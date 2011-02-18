#!/bin/sh

if test x$1 = x || test x$2 = x ; then
    echo "Usage: sh $0 solver_header symbol_file [additional include with/]"
    exit
else
    stubbed_header=$1
    symbols_file=$2
    include=$3
fi

clean_name=$(echo ${stubbed_header} | sed "s/.h//")
capitalized_name=$(echo ${clean_name} | sed 's/\S/\U&\L/g')

lazy_header=lazy_${clean_name}.h
lazy_cfile=lazy_${clean_name}.c
rm -f ${lazy_header} ${lazy_cfile}

echo "Generating header"
echo "Getting symbols to fake"
# file generated with nm lib + grep header + manual editing
symbols=$(cat ${symbols_file})

echo "#ifndef LAZY_${capitalized_name}_H
#define LAZY_${capitalized_name}_H

#include <ltdl.h>
#include <lazy_loading_status.h>

/* handle to the library */
lt_dlhandle __${clean_name}_handle;
/* loads the symbols */
int load_${clean_name}_symbols();
/* unloads the symbols (if called as many times as loadSymbols) */
int unload_${clean_name}_symbols();
/* prints what symbols ar missing */
void print_${clean_name}_missing_symbols();
" >> $lazy_header

for i in $symbols; do
    echo "#define $i (*__symbolic_$i)" >> $lazy_header
done
echo "

#include <${include}${stubbed_header}>

#endif /* LAZY_${capitalized_name}_H */
" >> $lazy_header

echo "Generating C file"
echo "
#include <stdio.h>
#include \"$lazy_header\"

/* C does not support bool, let's do it with macros */
#define bool int
#define true 1
#define false 0

int load_${clean_name}_symbols() {
    int res;
    bool try_another;
    try_another = true;

    if (lt_dlinit () != 0) return SYMBOL_LOAD_FAIL;

    try_another = !(__${clean_name}_handle = lt_dlopenext(\"lib${clean_name}\"));
    if (try_another) try_another = !(__${clean_name}_handle = lt_dlopenext(\"${clean_name}\"));
    if (try_another) return SYMBOL_LOAD_FAIL;

    res = SYMBOL_LOAD_SUCCESS;
" >> $lazy_cfile
for i in $symbols; do
    echo "    if (!(__symbolic_$i = lt_dlsym(__${clean_name}_handle, \"$i\"))) res = SYMBOL_MISSING;" >> $lazy_cfile
done
echo "
    return res;
}

void print_${clean_name}_missing_symbols() {
" >> ${lazy_cfile}
for i in $symbols; do
    echo "    if (!__symbolic_$i) printf(\"$i\\\n\");" >> $lazy_cfile
done
echo "
}

int unload_${clean_name}_symbols() {
    /* unload library */
    if (lt_dlclose (__${clean_name}_handle) != 0) return SYMBOL_UNLOAD_FAIL;

    /* exit */
    if (lt_dlexit() != 0) return SYMBOL_UNLOAD_FAIL;

    return SYMBOL_UNLOAD_SUCCESS;
}
" >> $lazy_cfile
