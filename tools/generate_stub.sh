#!/bin/sh

usage()
{
    echo "Usage: sh $0 <solver_name> <std_include_path> <symbol_file> <header_prefix> <cfile_prefix>"
    echo "    solver_name: cplex, gurobi, xprs, glpk"
    echo "    std_include_path: ilcplex/cplex.h, gurobi_c.h, xprs.h, glpk.h"
    echo "    symbol_file: list of symbols to fake"
    echo "    header_prefix: where to generate the header"
    echo "    cfile_prefix: where to generate the c file"
}

exit_error()
{
    echo "$@"
    usage
    exit 1
}

[ -z "$1" ] && exit_error "missing solver name"   || solver_name=$1
[ -z "$2" ] && exit_error "missing include path"  || std_include_path=$2
[ -z "$3" ] && exit_error "missing symbol file"   || symbols=$(cat $3)
[ -z "$4" ] && exit_error "missing header prefix" || header_prefix=$4
[ -z "$5" ] && exit_error "missing cfile prefix"  || cfile_prefix=$5

lazy_header=lazy_${solver_name}.h
lazy_cfile=lazy_${solver_name}.c

generate_header() {
    capitalized_name=$(echo ${solver_name} | sed 's/\S/\U&\L/g')

    echo "
    #ifndef LAZY_${capitalized_name}_H
    #define LAZY_${capitalized_name}_H

    #include <ltdl.h>
    #include \"lazy_loading_status.h\"

    #ifdef __cplusplus
    extern \"C\" {
    #endif

    #ifdef _WIN32
    #ifdef BUILDING_LAZYLPSOLVERLIBS
    #define LLSL_DECL __declspec(dllexport)
    #else
    #define LLSL_DECL __declspec(dllimport)
    #endif
    #else
    #define LLSL_DECL
    #endif

    /* handle to the library */
    LLSL_DECL lt_dlhandle __${solver_name}_handle;
    /* loads the symbols */
    LLSL_DECL int load_${solver_name}_symbols();
    /* unloads the symbols (if called as many times as loadSymbols) */
    LLSL_DECL int unload_${solver_name}_symbols();
    /* prints what symbols ar missing */
    LLSL_DECL void print_${solver_name}_missing_symbols();
    " >> $header_prefix/$lazy_header


    for i in $symbols; do
        echo "#define $i LLSL_DECL (*__symbolic_$i)" >> $header_prefix/$lazy_header
    done

    echo "
    #ifdef __cplusplus
    }
    #endif

    #include <${std_include_path}>

    /* Now we need to redefine LLSL_DECL as nothing (this issues a warning) */
    #ifdef _WIN32
    #undef LLSL_DECL
    #define LLSL_DECL
    #endif

    #endif /* LAZY_${capitalized_name}_H */
    " >> $header_prefix/$lazy_header
    sed -i "s/^    \(.*\)/\1/g" $header_prefix/$lazy_header
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
    " >> $cfile_prefix/$lazy_cfile
    for i in $symbols; do
        echo "        if (!(__symbolic_$i = lt_dlsym(__${solver_name}_handle, \"$i\"))) res = SYMBOL_MISSING;" >> $cfile_prefix/$lazy_cfile
    done
    echo "
        return res;
    }

    void print_${solver_name}_missing_symbols() {
    " >> $cfile_prefix/${lazy_cfile}
    for i in $symbols; do
        echo "        if (!__symbolic_$i) printf(\"$i\\n\");" >> $cfile_prefix/$lazy_cfile
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
    " >> $cfile_prefix/$lazy_cfile
    sed -i "s/^    \(.*\)/\1/g" $cfile_prefix/$lazy_cfile
}

rm -f $header_prefix/$lazy_header $cfile_prefix/$lazy_cfile
generate_header
generate_c_file
