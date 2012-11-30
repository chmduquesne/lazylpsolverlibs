/*
 * Copyright 2012 Christophe-Marie Duquesne
 *
 * This file is part of lazylpsolverlibs.
 *
 * You can redistribute it and/or modify it under the terms of the GNU
 * General Public License version 3 or (at your option) any later version.
 *
 * You should have received a copy of the GNU General Public License along
 * with lazylpsolverlibs (file GPL). If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <ilcplex/cplex.h>
#include <glpk.h>
#include <xprs.h>
#include <gurobi_c.h>
#include <lazylpsolverlibs.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <setjmp.h>

/*
 * These function are valid solver code. They all try to solve
 * the same problem, using their respective solver API:
 *
 * 0  <= x <= 3
 * 0  <= y <= 1
 *
 * minimize obj = -4x + y
 * such that:
 * c1: x + y <= 2
 */
static int cplex_example(void);
static int glpk_example(void);
static int gurobi_example(void);
static int xpress_example(void);

/*
 * Callback for the lazylibs if symbols are missing.
 */
static void handle_solver_error(const char *err);

/* To store/restore the environment */
static jmp_buf buf;

/* cplex example */
int cplex_example(void) {
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
    CPXlpopt (env, lp);
    CPXfreeprob (env, &lp);
    CPXcloseCPLEX (&env);
    return 0;
}

/* glpk example */
int glpk_example() {
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
    glp_simplex(lp, &params);
    glp_delete_prob(lp);
    return 0;
}

/* gurobi example */
int gurobi_example(void) {
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
    GRBoptimize(model);
    GRBfreemodel(model);
    GRBfreeenv(env);
    return 0;
}

/* xpress example */
int xpress_example(void) {
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
    XPRSminim(prob, "");
    XPRSdestroyprob(prob);
    XPRSfree();
    return 0;
}


/*
 * callback for missing symbols
 *
 * In C++, we would throw some exception. Here, longjump seems the only
 * way to properly come back from a failed solver call and continue the
 * execution.
 */
void handle_solver_error(const char *err) {

    longjmp(buf, 1);
}

int main(int argc, const char *argv[])
{
    int (*example[])(void) = {
        cplex_example,
        glpk_example,
        gurobi_example,
        xpress_example,
        NULL
    };
    char *name[] = {
        "cplex",
        "glpk",
        "gurobi",
        "xpress",
        NULL
    };
    int i;

    /*
     * Set the call back for missing symbols
     */
    set_lazycplex_failure_callback(handle_solver_error);
    set_lazyglpk_failure_callback(handle_solver_error);
    set_lazygurobi_failure_callback(handle_solver_error);
    set_lazyxprs_failure_callback(handle_solver_error);

    /*
     * Call each solver sequentially
     *
     * In C++, we would use try/catch. Here, we sort of have to use
     * setjmp/longjmp.
     */
    for (i = 0; example[i] != NULL; i++) {
        if (!setjmp(buf)){
            example[i]();
            fprintf(stdout, "\t%s: yes\n", name[i]);
        } else {
            fprintf(stdout, "\t%s: no\n", name[i]);
        }
    }

    return 0;
}
