#!/bin/sh

# extract the function name from a function declaration
func_name(){
    echo $@ | sed 's/ *(.*) *;/();/g' \
            | sed 's/ /\n/g' \
            | grep '(' \
            | sed 's/();//g' \
            | sed 's/\*//g'
}

# extract the arguments names from a function declaration
func_args(){
    echo $@ | sed 's/[^(]*(\(.*\)) *;/\1)/g' \
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
                \"lazylpsolverlibs: could not find the proper library\");
            }
        }
        if (!g_module_symbol(module, \"$name\", (gpointer *) &$symbol)) {
                fprintf(stderr,
                \"lazylpsolverlibs: could not find $name\");
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
    echo "$*"  | sed "s/\<$name\>/(*$symbol)/g" \
                | sed 's/;/ = NULL;/g'
}

# declare the necessary headers
make_include_headers(){
    echo "#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include \"$header\""
}

# create the loading interface
make_loading_interface(){
    libnames=$@
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
            *p = '\\0';
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
for name in $libnames; do
    echo "    if (!module) module = g_module_open_all(\"$name\", G_MODULE_BIND_LOCAL);"
done
echo "    return (module != NULL);
}"
}

header_to_cfile(){
    func_decl=$(mktemp)
    cat $1  | grep -v "#include" \
            | cpp \
            | tr '\n' ' ' \
            | sed 's/{[^}]*}/{}/g' \
            | sed 's/;/;\n/g' \
            | grep '(' \
            | sed 's/\s\+/ /g' \
            | sed 's/^ *//g' \
            | grep -v '^#' \
            | grep -v 'typedef' \
            > $func_decl
    make_include_headers $header
    make_loading_interface $libnames
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
    echo "
NAME
    stublib - create a stub library from an header file

SYNOPSIS
    stublib [-l libnames] header
"
}

[ -z "$1" ] && usage && exit
[ $1 == "-l" ] && libnames=$2 && header=$3
[ $1 != "-l" ] && header=$1

header_to_cfile $header
