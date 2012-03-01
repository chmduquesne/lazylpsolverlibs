#include "test_lazylibs.h"
#ifndef SKIP_CPLEX_SUPPORT
#include "lazycplex.h"
#endif
#ifndef SKIP_XPRESS_SUPPORT
#include "lazyxprs.h"
#endif
#ifndef SKIP_GUROBI_SUPPORT
#include "lazygurobi.h"
#endif
#ifndef SKIP_GLPK_SUPPORT
#include "lazyglpk.h"
#endif
#include "lazy_loading_status.h"
#include <stdio.h>
#include <stdlib.h>

int test_lazysolver(int (*load)(), int(*solve)(), void (*print_missing)(), int (*unload)())
{
    int status;
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
            return -1;
            break;
    }

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
    char *LAZYLPSOLVERLIBS_CPLEX_LIB_PATH;
    char *LAZYLPSOLVERLIBS_XPRESS_LIB_PATH;
    char *LAZYLPSOLVERLIBS_GUROBI_LIB_PATH;
    char *LAZYLPSOLVERLIBS_GLPK_LIB_PATH;

    LAZYLPSOLVERLIBS_CPLEX_LIB_PATH = NULL;
    LAZYLPSOLVERLIBS_XPRESS_LIB_PATH = NULL;
    LAZYLPSOLVERLIBS_GUROBI_LIB_PATH = NULL;
    LAZYLPSOLVERLIBS_GLPK_LIB_PATH = NULL;

    printf("This program will now test wether it can reach different solvers.\n");

    printf("\nTesting cplex support...\n");
#ifndef SKIP_CPLEX_SUPPORT
    LAZYLPSOLVERLIBS_CPLEX_LIB_PATH = getenv("LAZYLPSOLVERLIBS_CPLEX_LIB_PATH");
    if (LAZYLPSOLVERLIBS_CPLEX_LIB_PATH != NULL) {
        fprintf(stdout, "Trying to load LAZYLPSOLVERLIBS_CPLEX_LIB_PATH=%s\n", LAZYLPSOLVERLIBS_CPLEX_LIB_PATH);
    }
    test_lazysolver(&load_cplex_symbols,
            &solve_cplex_example,
            &print_cplex_missing_symbols,
            &unload_cplex_symbols);
#else
    printf("lazylibs compiled without cplex support!\n");
#endif
    printf("\nTesting xpress support...\n");
#ifndef SKIP_XPRESS_SUPPORT
    LAZYLPSOLVERLIBS_XPRESS_LIB_PATH = getenv("LAZYLPSOLVERLIBS_XPRESS_LIB_PATH");
    if (LAZYLPSOLVERLIBS_XPRESS_LIB_PATH != NULL) {
        fprintf(stdout, "Trying to load LAZYLPSOLVERLIBS_XPRESS_LIB_PATH=%s\n", LAZYLPSOLVERLIBS_XPRESS_LIB_PATH);
    }
    test_lazysolver(&load_xprs_symbols,
            &solve_xprs_example,
            &print_xprs_missing_symbols,
            &unload_xprs_symbols);
#else
    printf("lazylibs compiled without xpress support!\n");
#endif
    printf("\nTesting gurobi support...\n");
#ifndef SKIP_GUROBI_SUPPORT
    LAZYLPSOLVERLIBS_GUROBI_LIB_PATH = getenv("LAZYLPSOLVERLIBS_GUROBI_LIB_PATH");
    if (LAZYLPSOLVERLIBS_GUROBI_LIB_PATH != NULL) {
        fprintf(stdout, "Trying to load LAZYLPSOLVERLIBS_GUROBI_LIB_PATH=%s\n", LAZYLPSOLVERLIBS_GUROBI_LIB_PATH);
    }
    test_lazysolver(&load_gurobi_symbols,
            &solve_gurobi_example,
            &print_gurobi_missing_symbols,
            &unload_gurobi_symbols);
#else
    printf("lazylibs compiled without gurobi support!\n");
#endif
    printf("\nTesting glpk support...\n");
#ifndef SKIP_GLPK_SUPPORT
    LAZYLPSOLVERLIBS_GLPK_LIB_PATH = getenv("LAZYLPSOLVERLIBS_GLPK_LIB_PATH");
    if (LAZYLPSOLVERLIBS_GLPK_LIB_PATH != NULL) {
        fprintf(stdout, "Trying to load LAZYLPSOLVERLIBS_GLPK_LIB_PATH=%s\n", LAZYLPSOLVERLIBS_GLPK_LIB_PATH);
    }
    test_lazysolver(&load_glpk_symbols,
            &solve_glpk_example,
            &print_glpk_missing_symbols,
            &unload_glpk_symbols);
#else
    printf("lazylibs compiled without glpk support!\n");
#endif

#ifdef _WIN32
#endif

    printf("\nPress a key to exit\n");
    fread(buffer, 1, 1, stdin);
    return 0;
}
