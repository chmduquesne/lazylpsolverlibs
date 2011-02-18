#ifndef TEST_LAZYLIBS_H
#define TEST_LAZYLIBS_H

#include "config.h"

#ifdef COMPILED_WITH_CPLEX_SUPPORT
int solve_cplex_example();
#endif
#ifdef COMPILED_WITH_XPRESS_SUPPORT
int solve_xprs_example();
#endif
#ifdef COMPILED_WITH_GUROBI_SUPPORT
int solve_gurobi_example();
#endif
#ifdef COMPILED_WITH_GLPK_SUPPORT
int solve_glpk_example();
#endif

int test_lazysolver(int (*load)(), int(*solve)(), int (*unload)());

#endif /* TEST_LAZYLIBS_H */
