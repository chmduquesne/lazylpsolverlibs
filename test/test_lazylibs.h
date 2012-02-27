#ifndef TEST_LAZYLIBS_H
#define TEST_LAZYLIBS_H

#ifndef SKIP_CPLEX_SUPPORT
int solve_cplex_example();
#endif
#ifndef SKIP_XPRESS_SUPPORT
int solve_xprs_example();
#endif
#ifndef SKIP_GUROBI_SUPPORT
int solve_gurobi_example();
#endif
#ifndef SKIP_GLPK_SUPPORT
int solve_glpk_example();
#endif

int test_lazysolver(int (*load)(), int(*solve)(), void(*print_missing)(), int (*unload)());

#endif /* TEST_LAZYLIBS_H */
