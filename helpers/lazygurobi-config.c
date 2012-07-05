/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs
 */
#include <gurobi_c.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, const char *argv[]) {
    printf("Trying to solve a simple problem\n");
    /*
        0  <= x <= 3
        0  <= y <= 1

        minimize obj = -4x + y
        such that:
        c1: x + y <= 2
    */
    GRBenv *env = NULL;
    GRBmodel *model = NULL;
    int error = 0;

    int numvars = 2;
    double obj[] = { -4.0, 1.0 };
    double lb[] = { 0.0, 0.0 };
    double ub[] = { 1.0, 1.0 };
    char *varnames[] = { "x", "y" };

    int numnz = 2;
    int ind[] = { 0, 1 };
    double val[] = { 1.0, 1.0 };

    /* prepare environment */
    error = GRBloadenv(&env, NULL);
    if (error || env == NULL) {
        fprintf(stderr, "Error: could not open gurobi environment\n");
        exit(1);
    }
    GRBnewmodel(env, &model, "prob", numvars, obj, lb, ub, NULL, varnames);
    GRBaddconstr(model, numnz, ind, val, GRB_LESS_EQUAL, 2.0, "C1");
    if (GRBoptimize(model) == 0) {
        printf("Problem solved successfully!\n");
    }
    GRBfreemodel(model);
    GRBfreeenv(env);
    return 0;
}
