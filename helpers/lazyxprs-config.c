/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs
 */
#include <xprs.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Trying to solve a simple problem\n");
    /*
        0  <= x <= 3
        0  <= y <= 1

        minimize obj = -4x + y
        such that:
        c1: x + y <= 2
    */
    XPRSprob prob;
    int status;

    int ncols = 2;
    char colnames[]   = { 'x', 'y' }; /* columns x, y */
    double obj[] = { -4.0, 1.0 };     /* coefs -4, 0 */
    double lb[] = { 0.0, 0.0 };       /* lowerbounds 0, 0 */
    double ub[] = { 3.0, 1.0 };       /* upperbounds 3, 1 */

    int nrows = 1;
    char rownames[] = "C1";           /* row C1 */
    char sense[] = {'L'};             /* sense <= */
    double rhs[] = { 2.0 };           /* rhs 2 */

    int colstart[] = { 0, 1 };        /* start indices at mat[0] and mat[1]*/
    int ncolelem[] = { 1, 1 };        /* col 0 has 1 elt, col 1 has 1 elt */
    int rowind[] = { 0, 0 };          /* first elt of col 0 is on row 0,
                                       * first elt of col 0 is on row 0 */
    double mat[] = { 1.0, 1.0 };      /* x + y*/

    int ROW = 1;
    int COL = 2;

    char banner[256];
    /* prepare environment */
    status=XPRSinit(NULL);
    if (status != 0 && status != 32) {
        XPRSgetlicerrmsg(banner, sizeof banner);
        puts(banner);
        return(1);
    }

    XPRScreateprob(&prob);
    XPRSloadlp(prob, "prob", ncols, nrows, sense, rhs, NULL, obj,
            colstart, ncolelem, rowind, mat, lb, ub);
    XPRSaddnames(prob, ROW, rownames, 0, nrows-1);
    XPRSaddnames(prob, COL, colnames, 0, ncols-1);
    if (XPRSminim(prob, "") == 0) {
        printf("Problem solved successfully!\n");
    }
    XPRSdestroyprob(prob);
    XPRSfree();
    return 0;
}
