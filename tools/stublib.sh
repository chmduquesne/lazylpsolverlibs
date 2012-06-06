#!/bin/sh

# extract the function name from a function declaration
func_name(){
    echo $@ | sed 's/__attribute__((__stdcall__))//g' \
            | sed 's/__attribute__((__cdecl__))//g' \
            | sed 's/__attribute__//g' \
            | sed 's/__cdecl__//g' \
            | sed 's/__stdcall__//g' \
            | sed 's/__stdcall//g' \
            | sed 's/__cdecl//g' \
            | sed 's/ *(.*) *;/();/g' \
            | sed 's/ /\n/g' \
            | grep '(' \
            | sed 's/();//g' \
            | sed 's/\*//g'
}

# extract the arguments names from a function declaration
func_args(){
    echo $@ | sed 's/__attribute__((__stdcall__))//g' \
            | sed 's/__attribute__((__cdecl__))//g' \
            | sed 's/__attribute__//g' \
            | sed 's/__cdecl__//g' \
            | sed 's/__stdcall__//g' \
            | sed 's/__stdcall//g' \
            | sed 's/__cdecl//g' \
            | sed 's/[^(]*(\(.*\)) *;/\1)/g' \
            | sed 's/(\([^)]*\)) *([^)]*)/\1/g' \
            | sed 's/, *\.\.\.//g' \
            | sed 's/ *, */, /g' \
            | sed 's/ *)/)/g' \
            | sed 's/ /\n/g' \
            | sed 's/\[.*\]//g' \
            | grep ',\|)' \
            | grep -v '\<void\>' \
            | tr '\n' ' ' \
            | sed 's/)//g' \
            | sed 's/\*//g' \
            | sed 's/ *$//g'
}

# create a function from a function declaration. This function actually
# imports the original symbol and passes its arguments to this symbol.
make_func(){
    name=$(func_name "$*")
    symbol="__symbolic_$name"
    args=$(func_args "$*")
    echo "$*" | sed 's/;/{/g'
    echo "    if (!$symbol) {
        if (!module) {
            if (!load_module()) {
                fprintf(stderr,
                \"lazylpsolverlibs: could not find the proper library\\\n\");
            }
        }
        if (!g_module_symbol(module, \"$name\", (gpointer *) &$symbol)) {
                fprintf(stderr,
                \"lazylpsolverlibs: could not find $name\\\n\");
        }
    }
    return $symbol($args);"
    echo "}"
}

# declare a symbol to import a function that matches the input function
# declaration to
make_symbol_decl(){
    name=$(func_name "$*")
    symbol="__symbolic_$name"
    echo "$*"   | sed "s/\<$name\>/(*$symbol)/g" \
                | sed 's/;/ = NULL;/g'
}

# declare the necessary headers
make_include_headers(){
    echo "#include <gmodule.h>"
    echo "#include <stdio.h>"
    echo "#include <stdlib.h>"
    echo "#include <string.h>"
    if [ x"$declared_header" != x ]; then
        echo "#include $declared_header"
    else
        echo "#include $header"
    fi
}

# create the loading interface
make_loading_interface(){
    echo "
/* searches and loads a library from standard paths */
GModule *g_module_open_all(const gchar *name, GModuleFlags flags) {
    char *LIB_PATH, *LIB_PATH_COPY, *p, *dir;
    GModule *res;

    p = NULL;
    dir = NULL;
    res = NULL;

#ifdef _WIN32
    LIB_PATH = getenv(\"PATH\");
#define PATH_SEP ';'
#else
    LIB_PATH = getenv(\"LD_LIBRARY_PATH\");
#define PATH_SEP ':'
#endif

    res = g_module_open(g_module_build_path(NULL, name), flags);
    if (res) {
        return res;
    }
    if (LIB_PATH) {
        LIB_PATH_COPY = malloc(strlen(LIB_PATH));
        strncpy(LIB_PATH_COPY, LIB_PATH, strlen(LIB_PATH));
        p = LIB_PATH_COPY;
        dir = p;
        while ((p = strchr(p, PATH_SEP))) {
            *p = '\\\0';
            p++;
            res = g_module_open(g_module_build_path(dir, name), flags);
            if (res) {
                free(LIB_PATH_COPY);
                return res;
            }
            dir = p;
        }
        res = g_module_open(g_module_build_path(dir, name), flags);
        free(LIB_PATH_COPY);
    }
    return res;
}

/* handle to the library */
GModule *module = NULL;

/* searches and loads the actual library */
int load_module(){"
if [ x"$environment_var" != x ]; then
    echo "    /* environment variable */"
    echo "    char *$environment_var;"
    echo "    $environment_var = getenv(\"$environment_var\");"
fi
if [ x"$try_first" != x ]; then
    echo "    if (!module) module = g_module_open(\"$try_first\", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
fi
if [ x"$environment_var" != x ]; then
    echo "    if ($environment_var != NULL) {"
    echo "        if (!module) module = g_module_open($environment_var, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
    echo "    }"
fi
for name in $libnames; do
    echo "    if (!module) module = g_module_open_all(\"$name\", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
done
echo "    return (module != NULL);
}"
}

header_to_cfile(){
    func_decl=$(mktemp)
    cat $header | grep -v "#include" \
                | $cpp \
                | grep -v '^#' \
                | tr '\n' ' ' \
                | sed 's/{[^}]*}/{}/g' \
                | sed 's/;/;\n/g' \
                | grep '(' \
                | sed 's/\s\+/ /g' \
                | sed 's/^ *//g' \
                | grep -v 'typedef' \
                > $func_decl
    make_include_headers
    make_loading_interface
    echo ""
    echo "/* imported functions */"
    echo ""
    while read line; do
        make_symbol_decl "$line"
    done < $func_decl
    echo ""
    echo "/* hijacked functions */"
    echo ""
    while read line; do
        make_func "$line"
    done < $func_decl
    rm $func_decl
}

usage(){
    echo "Usage: stublib.sh -i header -l libnames [-e environment_var] [-f try_first] [-d declared_header] [-c c_preprocessor]"
    echo ""
    echo " - libnames has to be a coma-separated list, without the prefix lib nor the extension name .so"
    echo " - try_first has to be a full path that will be tried first"
    echo " - environment_var will be tried just after (interpreted as a full path as well)"
    echo " - libnames will be tried in the order specified, in every directory of LD_LIBRARY_PATH (linux) or PATH (windows)"
    echo " - declared_header will be used instead of header if specified"
    echo " - c_preprocessor will be used instead of cpp if specified"
}

cpp=cpp
while getopts "hi:l:e:f:d:c:" opt; do
    case $opt in
        h)
            usage
            ;;
        i)
            header=$OPTARG
            test -f $header || (echo "$header: No such file or directory" >&2 && exit 1)
            ;;
        l)
            libnames=$(echo $OPTARG | sed "s/,/ /g")
            ;;
        e)
            environment_var=$OPTARG
            ;;
        f)
            try_first=$OPTARG
            ;;
        d)
            declared_header=$OPTARG
            ;;
        c)
            cpp=$OPTARG
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
    esac
done

test -z $header && echo "You must provide an argument to -i" && usage && exit
header_to_cfile
