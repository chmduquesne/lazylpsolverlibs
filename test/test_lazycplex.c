#include <ilcplex/cplex.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/* Bring in the declarations for the string functions */

#include <string.h>

/* Include declaration for functions at end of program */

static int populatebyrow (CPXENVptr env, CPXLPptr lp);
static void free_and_null (char **ptr);

int main (int argc, char **argv) {
    int      solstat;
    double   objval;
    double   *x = NULL;
    double   *pi = NULL;
    double   *slack = NULL;
    double   *dj = NULL;
    CPXENVptr     env = NULL;
    CPXLPptr      lp = NULL;
    int           status = 0;
    int           cur_numrows, cur_numcols;

    env = CPXopenCPLEX (&status);
    if ( env == NULL ) {
        char  errmsg[1024];
        fprintf (stderr, "Could not open CPLEX environment.\n");
        CPXgeterrorstring (env, status, errmsg);
        fprintf (stderr, "%s", errmsg);
        goto TERMINATE;
    }
    lp = CPXcreateprob (env, &status, "lpex1");
    if ( lp == NULL ) {
        fprintf (stderr, "Failed to create LP.\n");
        goto TERMINATE;
    }
    status = populatebyrow (env, lp);
    if ( status ) {
        fprintf (stderr, "Failed to populate problem.\n");
        goto TERMINATE;
    }
    status = CPXlpopt (env, lp);
    if ( status ) {
        fprintf (stderr, "Failed to optimize LP.\n");
        goto TERMINATE;
    }

    cur_numrows = CPXgetnumrows (env, lp);
    cur_numcols = CPXgetnumcols (env, lp);
    x = (double *) malloc (cur_numcols * sizeof(double));
    slack = (double *) malloc (cur_numrows * sizeof(double));
    dj = (double *) malloc (cur_numcols * sizeof(double));
    pi = (double *) malloc (cur_numrows * sizeof(double));
    if ( x     == NULL ||
            slack == NULL ||
            dj    == NULL ||
            pi    == NULL   ) {
        status = CPXERR_NO_MEMORY;
        fprintf (stderr, "Could not allocate memory for solution.\n");
        goto TERMINATE;
    }
    status = CPXsolution (env, lp, &solstat, &objval, x, pi, slack, dj);
    if ( status ) {
        fprintf (stderr, "Failed to obtain solution.\n");
        goto TERMINATE;
    }

TERMINATE:
    free_and_null ((char **) &x);
    free_and_null ((char **) &slack);
    free_and_null ((char **) &dj);
    free_and_null ((char **) &pi);
    if ( lp != NULL ) {
        status = CPXfreeprob (env, &lp);
        if ( status ) {
            fprintf (stderr, "CPXfreeprob failed, error code %d.\n", status);
        }
    }
    if ( env != NULL ) {
        status = CPXcloseCPLEX (&env);
        if ( status ) {
            char  errmsg[1024];
            fprintf (stderr, "Could not close CPLEX environment.\n");
            CPXgeterrorstring (env, status, errmsg);
            fprintf (stderr, "%s", errmsg);
        }
    }

    return (status);

}  /* END main */

static void
free_and_null (char **ptr)
{
    if ( *ptr != NULL ) {
        free (*ptr);
        *ptr = NULL;
    }
} /* END free_and_null */

#define NUMROWS    2
#define NUMCOLS    3
#define NUMNZ      6

    static int
populatebyrow (CPXENVptr env, CPXLPptr lp)
{
    int      status    = 0;
    double   obj[NUMCOLS];
    double   lb[NUMCOLS];
    double   ub[NUMCOLS];
    char     *colname[NUMCOLS];
    int      rmatbeg[NUMROWS];
    int      rmatind[NUMNZ];
    double   rmatval[NUMNZ];
    double   rhs[NUMROWS];
    char     sense[NUMROWS];
    char     *rowname[NUMROWS];

    CPXchgobjsen (env, lp, CPX_MAX);  /* Problem is maximization */
    obj[0]     = 1.0;  obj[1]     = 2.0;          obj[2]     = 3.0;
    lb[0]      = 0.0;  lb[1]      = 0.0;          lb[2]      = 0.0;
    ub[0]      = 40.0; ub[1]      = CPX_INFBOUND; ub[2]      = CPX_INFBOUND;
    colname[0] = "x1"; colname[1] = "x2";         colname[2] = "x3";
    status = CPXnewcols (env, lp, NUMCOLS, obj, lb, ub, NULL, colname);
    if ( status )  goto TERMINATE;

    rmatbeg[0] = 0;     rowname[0] = "c1";
    rmatind[0] = 0;     rmatind[1] = 1;    rmatind[2] = 2;     sense[0] = 'L';
    rmatval[0] = -1.0;  rmatval[1] = 1.0;  rmatval[2] = 1.0;   rhs[0]   = 20.0;
    rmatbeg[1] = 3;     rowname[1] = "c2";
    rmatind[3] = 0;     rmatind[4] = 1;    rmatind[5] = 2;     sense[1] = 'L';
    rmatval[3] = 1.0;   rmatval[4] = -3.0; rmatval[5] = 1.0;   rhs[1]   = 30.0;
    status = CPXaddrows (env, lp, 0, NUMROWS, NUMNZ, rhs, sense, rmatbeg,
            rmatind, rmatval, NULL, rowname);
    if ( status )  goto TERMINATE;

TERMINATE:
    printf("cplex: solved a problem sucessfully.\n");

    return (status);

}  /* END populatebyrow */
