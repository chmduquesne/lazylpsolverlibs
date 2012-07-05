/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs
 */
#include <glpk.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, const char *argv[]) {
    printf("Trying to solve a simple problem\n");
    /*
        0  <= x <= 3
        0  <= y <= 1

        minimize obj = -4x + y
        such that:
        c1: x + y <= 2
    */
    glp_prob *lp;
    lp = glp_create_prob();
    glp_set_prob_name(lp, "prob");
    glp_set_obj_dir(lp, GLP_MIN);
    glp_add_rows(lp, 1);
    glp_set_row_name(lp, 1, "C1");
    glp_set_row_bnds(lp, 1, GLP_UP, 0.0, 2.0); /* C1 <= 2 */
    glp_add_cols(lp, 2);
    glp_set_col_name(lp, 1, "x");
    glp_set_col_bnds(lp, 1, GLP_DB, 0.0, 3.0); /* 0 <= x <= 3 */
    glp_set_obj_coef(lp, 1, -4.0);             /* coef(x) = -4 */
    glp_set_col_name(lp, 2, "y");
    glp_set_col_bnds(lp, 2, GLP_DB, 0.0, 1.0); /* 0 <= y <= 1 */
    glp_set_obj_coef(lp, 2, 1.0);              /* coef(y) = 1 */
    int ind[2+1] = {0, 1, 2};
    double val[2+1] = {0, 1.0, 1.0};
    glp_set_mat_row(lp, 1, 2, ind, val); /* C1 = x + y */
    glp_smcp params;
    {
        params.msg_lev = GLP_MSG_OFF;
        params.meth = GLP_PRIMAL;
        params.pricing = GLP_PT_STD;
        params.r_test = GLP_RT_STD;
        params.tol_bnd = 1e-7;
        params.tol_dj = 1e-7;
        params.tol_piv = 1e-10;
        params.obj_ll = -DBL_MAX;
        params.obj_ul = +DBL_MAX;
        params.it_lim = INT_MAX;
        params.tm_lim = INT_MAX;
        params.out_frq = 500;
        params.out_dly = 0;
        params.presolve = GLP_OFF;
    }
    if (glp_simplex(lp, &params) == 0) {
        printf("Problem solved successfully!\n");
    }
    glp_delete_prob(lp);
    return 0;
}
