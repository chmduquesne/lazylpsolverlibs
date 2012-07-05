/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs
 */
#include <ilcplex/cplex.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char *argv[]) {
    printf("Trying to solve a simple problem\n");
    /*
        0  <= x <= 3
        0  <= y <= 1

        minimize obj = -4x + y
        such that:
        c1: x + y <= 2
    */
    CPXENVptr env;
    CPXLPptr lp;
    int status;
    /* columns */
    char* colname[] = { "x", "y" };   /* columns x, y */
    double obj[] = { -4.0, 1.0 };     /* coefs -4, 0 */
    double lb[] = { 0.0, 0.0 };       /* lowerbounds 0, 0 */
    double ub[] = { 3.0, 1.0 };       /* upperbounds 3, 1 */
    /* rows */
    int      rmatbeg[] = { 0 };       /* rows 0 start at index O */
    int      rmatind[] = { 2 };       /* 2 non null coefs in row 0*/
    double   rmatval[] = { 1.0, 1.0 };/* coefs 1, 1 */
    double   rhs[] = { 2.0 };         /* rhs 2 */
    char     sense[] = { 'L' };       /* sense <= */
    char     *rowname[] = { "C1" };
    /* prepare environment */
    if ((env = CPXopenCPLEX (&status)) == NULL) {
        char  err[1024];
        fprintf (stderr, "Could not open cplex environment.\n");
        CPXgeterrorstring (env, status, err);
        fprintf (stderr, "%s", err);
        exit(1);
    }
    lp = CPXcreateprob (env, NULL, "prob");
    CPXnewcols (env, lp, 2, obj, lb, ub, NULL, colname);
    CPXaddrows (env, lp, 0, 1, 2, rhs, sense, rmatbeg,
            rmatind, rmatval, NULL, rowname);
    if (CPXlpopt (env, lp) == 0) {
        printf("Problem solved successfully!\n");
    }
    CPXfreeprob (env, &lp);
    CPXcloseCPLEX (&env);
    return 0;
}
