#!/bin/sh

usage()
{
    echo "Usage: sh $0 <solver_name> <std_include_path> <symbol_file> <prefix>"
    echo "    solver_name: cplex, gurobi, xprs, glpk"
    echo "    std_include_path: ilcplex/cplex.h, gurobi_c.h, xprs.h, glpk.h"
    echo "    symbol_file: list of symbols to fake"
    echo "    prefix: where to generate the files"
}

exit_error()
{
    echo "$@"
    usage
    exit 1
}

[ -z "$1" ] && exit_error "missing solver name"  || solver_name=$1
[ -z "$2" ] && exit_error "missing include path" || std_include_path=$2
[ -z "$3" ] && exit_error "missing symbol file"  || symbols=$(cat $3)
[ -z "$4" ] && exit_error "missing symbol file"  || prefix=$4

lazy_header=lazy_${solver_name}.h
lazy_cfile=lazy_${solver_name}.c

generate_header() {
    capitalized_name=$(echo ${solver_name} | sed 's/\S/\U&\L/g')

    echo "
    #ifndef LAZY_${capitalized_name}_H
    #define LAZY_${capitalized_name}_H

    #include <ltdl.h>
    #include \"lazy_loading_status.h\"

    /* handle to the library */
    lt_dlhandle __${solver_name}_handle;
    /* loads the symbols */
    int load_${solver_name}_symbols();
    /* unloads the symbols (if called as many times as loadSymbols) */
    int unload_${solver_name}_symbols();
    /* prints what symbols ar missing */
    void print_${solver_name}_missing_symbols();
    " >> $prefix/$lazy_header


    for i in $symbols; do
        echo "#define $i (*__symbolic_$i)" >> $prefix/$lazy_header
    done

    echo "
    #include <${std_include_path}>

    #endif /* LAZY_${capitalized_name}_H */
    " >> $prefix/$lazy_header
    sed -i "s/^    \(.*\)/\1/g" $prefix/$lazy_header
}

generate_c_file() {
    echo "
    #include <stdio.h>
    #include <stdbool.h>
    #include \"$lazy_header\"

    int load_${solver_name}_symbols() {
        int res;
        bool try_another;
        try_another = true;

        if (lt_dlinit () != 0) return SYMBOL_LOAD_FAIL;

        try_another = !(__${solver_name}_handle = lt_dlopenext(\"lib${solver_name}\"));
        if (try_another) try_another = !(__${solver_name}_handle = lt_dlopenext(\"${solver_name}\"));
        if (try_another) return SYMBOL_LOAD_FAIL;

        res = SYMBOL_LOAD_SUCCESS;
    " >> $prefix/$lazy_cfile
    for i in $symbols; do
        echo "        if (!(__symbolic_$i = lt_dlsym(__${solver_name}_handle, \"$i\"))) res = SYMBOL_MISSING;" >> $prefix/$lazy_cfile
    done
    echo "
        return res;
    }

    void print_${solver_name}_missing_symbols() {
    " >> $prefix/${lazy_cfile}
    for i in $symbols; do
        echo "        if (!__symbolic_$i) printf(\"$i\\\n\");" >> $prefix/$lazy_cfile
    done
    echo "
    }

    int unload_${solver_name}_symbols() {
        /* unload library */
        if (lt_dlclose (__${solver_name}_handle) != 0) return SYMBOL_UNLOAD_FAIL;

        /* exit */
        if (lt_dlexit() != 0) return SYMBOL_UNLOAD_FAIL;

        return SYMBOL_UNLOAD_SUCCESS;
    }
    " >> $prefix/$lazy_cfile
    sed -i "s/^    \(.*\)/\1/g" $prefix/$lazy_cfile
}

rm -f $prefix/$lazy_header $prefix/$lazy_cfile
generate_header
generate_c_file
