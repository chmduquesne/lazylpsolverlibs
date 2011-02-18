#include "test_lazylibs.h"
#ifdef COMPILED_WITH_CPLEX_SUPPORT
#include "lazy_cplex.h"
#endif
#ifdef COMPILED_WITH_XPRESS_SUPPORT
#include "lazy_xprs.h"
#endif
#ifdef COMPILED_WITH_GUROBI_SUPPORT
#include "lazy_gurobi_c.h"
#endif
#ifdef COMPILED_WITH_GLPK_SUPPORT
#include "lazy_glpk.h"
#endif
#include "lazy_loading_status.h"
#include <stdio.h>

int test_lazysolver(int (*load)(), int(*solve)(), void (*print_missing)(), int (*unload)())
{
    int status;
    int ok;
    ok = 1;
    status = load();
    switch(status) {
        case SYMBOL_LOAD_SUCCESS:
            fprintf(stdout, "The library loaded fine.\n");
            break;
        case SYMBOL_MISSING:
            fprintf(stdout, "The library loaded, though some symbols are missing:\n");
            print_missing();
            break;
        case SYMBOL_LOAD_FAIL:
            fprintf(stdout, "The library did not load.\n");
            ok = 0;
            break;
    }

    if (!ok) return -1;

    if (solve() == 0)
        fprintf(stdout, "A problem was sucessfully solved\n");
    else
        fprintf(stdout, "The problem failed to solve\n");

    status = unload();
    switch(status) {
        case SYMBOL_UNLOAD_SUCCESS:
            fprintf(stdout, "The library unloaded fine.\n");
            break;
        case SYMBOL_UNLOAD_FAIL:
            fprintf(stdout, "The library did not unload fine\n");
            break;
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    char buffer[256];
    fprintf(stdout, "\nTesting cplex support...\n");
#ifdef COMPILED_WITH_CPLEX_SUPPORT
    test_lazysolver(&load_cplex_symbols,
            &solve_cplex_example,
            &print_cplex_missing_symbols,
            &unload_cplex_symbols);
#else
    fprintf(stdout, "lazylibs compiled without cplex support!\n");
#endif
    fprintf(stdout, "\nTesting xpress support...\n");
#ifdef COMPILED_WITH_XPRESS_SUPPORT
    test_lazysolver(&load_xprs_symbols,
            &solve_xprs_example,
            &print_xprs_missing_symbols,
            &unload_xprs_symbols);
#else
    fprintf(stdout, "lazylibs compiled without xpress support!\n");
#endif
    fprintf(stdout, "\nTesting gurobi support...\n");
#ifdef COMPILED_WITH_GUROBI_SUPPORT
    test_lazysolver(&load_gurobi_c_symbols,
            &solve_gurobi_example,
            &print_gurobi_c_missing_symbols,
            &unload_gurobi_c_symbols);
#else
    fprintf(stdout, "lazylibs compiled without gurobi support!\n");
#endif
    fprintf(stdout, "\nTesting glpk support...\n");
#ifdef COMPILED_WITH_GLPK_SUPPORT
    test_lazysolver(&load_glpk_symbols,
            &solve_glpk_example,
            &print_glpk_missing_symbols,
            &unload_glpk_symbols);
#else
    fprintf(stdout, "lazylibs compiled without glpk support!\n");
#endif
    fprintf(stdout, "\nPress a key to exit\n");
    fread(buffer, 1, 1, stdin);
    return 0;
}
