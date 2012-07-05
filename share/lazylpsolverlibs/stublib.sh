#!/bin/bash

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
            | sed 's/ *+ */+/g' \
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
            DEBUG_PRINT(\"lazylpsolverlibs: looking for a suitable library in the standard system path\\\n\");
            if (!load_module()) {
                fprintf(stderr, \"lazylpsolverlibs: Library lookup failed! Suggestions:\\\n\""
    if [ x"$environment_var" != x ]; then
        echo "                    \" - point the $environment_var environment variable to the full path of the library\\\n\""
    fi
    if [ x"$try_first" != x ]; then
        echo "                    \" - or more secure, symlink $try_first to the full path of the library (you need root access).\\\n\""
    fi
    echo "             );
            } else {
                DEBUG_PRINT(\"lazylpsolverlibs: Success!\\\n\");
            }
        }
        if (!g_module_symbol(module, \"$name\", (gpointer *) &$symbol)) {
            fprintf(stderr, \"lazylpsolverlibs: the symbol $name could not be found! Exiting your program to avoid a segfault.\\\n\");
            exit(1);
        } else {
            DEBUG_PRINT(\"lazylpsolverlibs: successfully imported the symbol $name.\\\n\");
        }
    }
    return $symbol($args);
}"
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
/* A debugging macro */
#define DEBUG_PRINT(...) if (debug_enabled()) { fprintf( stderr, __VA_ARGS__ ); }

/*
 * returns true if the environment variable LAZYLPSOLVERLIBS_DEBUG is set
 * to \"on\", 0 otherwise
 */
int debug_enabled() {
    const char * LAZYLPSOLVERLIBS_DEBUG;
    LAZYLPSOLVERLIBS_DEBUG = getenv(\"LAZYLPSOLVERLIBS_DEBUG\");
    if (LAZYLPSOLVERLIBS_DEBUG != NULL && strlen(LAZYLPSOLVERLIBS_DEBUG) > 0)
        return 1;
    return 0;
}

/* handle to the library */
GModule *module = NULL;

/* searches and loads the actual library */
int load_module(){
    char *path;"
if [ x"$environment_var" != x ]; then
    echo "    /* environment variable */"
    echo "    char *$environment_var;"
    echo "    $environment_var = getenv(\"$environment_var\");"
fi
if [ x"$try_first" != x ]; then
    echo "    if (!module) {"
    echo "        DEBUG_PRINT (\"lazylpsolverlibs: attempting to load library from %s\\\n\", \"$try_first\");"
    echo "        module = g_module_open(\"$try_first\", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
    echo "    }"
fi
if [ x"$environment_var" != x ]; then
    echo "    if ($environment_var != NULL) {"
    echo "        if (!module) {"
    echo "            DEBUG_PRINT (\"lazylpsolverlibs: attempting to load library from %s\\\n\", $environment_var);"
    echo "            module = g_module_open($environment_var, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
    echo "        }"
    echo "    }"
fi
for name in $libnames; do
    echo "    if (!module) {"
    echo "#ifdef _WIN32"
    echo "        path = g_module_build_path(NULL, \"${name}.dll\");"
    echo "#else"
    echo "        path = g_module_build_path(NULL, \"$name\");"
    echo "#endif"
    echo "        DEBUG_PRINT(\"lazylpsolverlibs: attempting to load library from %s\\\n\", path);"
    echo "        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);"
    echo "        g_free(path);"
    echo "    }"
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
