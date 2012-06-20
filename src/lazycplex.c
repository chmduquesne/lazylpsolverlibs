#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ilcplex/cplex.h>

/* A debugging macro */
#define DEBUG_PRINT(...) if (debug_enabled()) { fprintf( stderr, __VA_ARGS__ ); }

/*
 * returns true if the environment variable LAZYLPSOLVERLIBS_DEBUG is set
 * to "on", 0 otherwise
 */
int debug_enabled() {
    const char * LAZYLPSOLVERLIBS_DEBUG;
    LAZYLPSOLVERLIBS_DEBUG = getenv("LAZYLPSOLVERLIBS_DEBUG");
    if (LAZYLPSOLVERLIBS_DEBUG != NULL && strlen(LAZYLPSOLVERLIBS_DEBUG) > 0)
        return 1;
    return 0;
}

/* handle to the library */
GModule *module = NULL;

/* searches and loads the actual library */
int load_module(){
    char *path;
    /* environment variable */
    char *LAZYLPSOLVERLIBS_CPLEX_LIB;
    LAZYLPSOLVERLIBS_CPLEX_LIB = getenv("LAZYLPSOLVERLIBS_CPLEX_LIB");
    if (!module) {
        DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", "/usr/lib/libcplex.so");
        module = g_module_open("/usr/lib/libcplex.so", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
    }
    if (LAZYLPSOLVERLIBS_CPLEX_LIB != NULL) {
        if (!module) {
            DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", LAZYLPSOLVERLIBS_CPLEX_LIB);
            module = g_module_open(LAZYLPSOLVERLIBS_CPLEX_LIB, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        }
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex123.dll");
#else
        path = g_module_build_path(NULL, "cplex123");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex121.dll");
#else
        path = g_module_build_path(NULL, "cplex121");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex120.dll");
#else
        path = g_module_build_path(NULL, "cplex120");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex112.dll");
#else
        path = g_module_build_path(NULL, "cplex112");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex111.dll");
#else
        path = g_module_build_path(NULL, "cplex111");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex110.dll");
#else
        path = g_module_build_path(NULL, "cplex110");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex102.dll");
#else
        path = g_module_build_path(NULL, "cplex102");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex101.dll");
#else
        path = g_module_build_path(NULL, "cplex101");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex100.dll");
#else
        path = g_module_build_path(NULL, "cplex100");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex91.dll");
#else
        path = g_module_build_path(NULL, "cplex91");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex90.dll");
#else
        path = g_module_build_path(NULL, "cplex90");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex81.dll");
#else
        path = g_module_build_path(NULL, "cplex81");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex80.dll");
#else
        path = g_module_build_path(NULL, "cplex80");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex75.dll");
#else
        path = g_module_build_path(NULL, "cplex75");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex71.dll");
#else
        path = g_module_build_path(NULL, "cplex71");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex70.dll");
#else
        path = g_module_build_path(NULL, "cplex70");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex66.dll");
#else
        path = g_module_build_path(NULL, "cplex66");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex65.dll");
#else
        path = g_module_build_path(NULL, "cplex65");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex60.dll");
#else
        path = g_module_build_path(NULL, "cplex60");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex50.dll");
#else
        path = g_module_build_path(NULL, "cplex50");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex40.dll");
#else
        path = g_module_build_path(NULL, "cplex40");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex30.dll");
#else
        path = g_module_build_path(NULL, "cplex30");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex21.dll");
#else
        path = g_module_build_path(NULL, "cplex21");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "cplex20.dll");
#else
        path = g_module_build_path(NULL, "cplex20");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    return (module != NULL);
}

/* imported functions */

CPXLPptr (*__symbolic_CPXcreateprob) (CPXCENVptr env, int *status_p, const char *probname_str) = NULL;
CPXLPptr (*__symbolic_CPXcloneprob) (CPXCENVptr env, CPXCLPptr lp, int *status_p) = NULL;
int (*__symbolic_CPXcopylpwnames) (CPXCENVptr env, CPXLPptr lp, int numcols, int numrows, int objsense, const double *objective, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval, char **colname, char **rowname) = NULL;
int (*__symbolic_CPXcopylp) (CPXCENVptr env, CPXLPptr lp, int numcols, int numrows, int objsense, const double *objective, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval) = NULL;
int (*__symbolic_CPXcopyobjname) (CPXCENVptr env, CPXLPptr lp, const char *objname_str) = NULL;
int (*__symbolic_CPXcopybase) (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat) = NULL;
int (*__symbolic_CPXcleanup) (CPXCENVptr env, CPXLPptr lp, double eps) = NULL;
int (*__symbolic_CPXcopystart) (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat, const double *cprim, const double *rprim, const double *cdual, const double *rdual) = NULL;
int (*__symbolic_CPXfreeprob) (CPXCENVptr env, CPXLPptr * lp_p) = NULL;
int (*__symbolic_CPXcopynettolp) (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETextract) (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp, int *colmap, int *rowmap) = NULL;
int (*__symbolic_CPXlpopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXconcurrentlpopt) (CPXCENVptr env, CPXCENVptr * childenv, CPXLPptr lp, int P) = NULL;
int (*__symbolic_CPXconcurrentmipopt) (CPXCENVptr env, CPXCENVptr * childenv, CPXLPptr lp, int P) = NULL;
int (*__symbolic_CPXprimopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXdualopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXhybnetopt) (CPXCENVptr env, CPXLPptr lp, int method) = NULL;
int (*__symbolic_CPXsiftopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXpratio) (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio, int *downleave, int *upleave, int *downleavestatus, int *upleavestatus, int *downstatus, int *upstatus) = NULL;
int (*__symbolic_CPXdratio) (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio, int *downenter, int *upenter, int *downstatus, int *upstatus) = NULL;
int (*__symbolic_CPXpivot) (CPXCENVptr env, CPXLPptr lp, int jenter, int jleave, int leavestat) = NULL;
int (*__symbolic_CPXsetphase2) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXcheckpfeas) (CPXCENVptr env, CPXLPptr lp, int *infeas_p) = NULL;
int (*__symbolic_CPXcheckdfeas) (CPXCENVptr env, CPXLPptr lp, int *infeas_p) = NULL;
int (*__symbolic_CPXchecksoln) (CPXCENVptr env, CPXLPptr lp, int *lpstatus_p) = NULL;
int (*__symbolic_CPXsolution) (CPXCENVptr env, CPXCLPptr lp, int *lpstat_p, double *objval_p, double *x, double *pi, double *slack, double *dj) = NULL;
int (*__symbolic_CPXsolninfo) (CPXCENVptr env, CPXCLPptr lp, int *solnmethod_p, int *solntype_p, int *pfeasind_p, int *dfeasind_p) = NULL;
int (*__symbolic_CPXgetstat) (CPXCENVptr env, CPXCLPptr lp) = NULL;
CPXCHARptr (*__symbolic_CPXgetstatstring) (CPXCENVptr env, int statind, char *buffer_str) = NULL;
int (*__symbolic_CPXgetmethod) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetobjval) (CPXCENVptr env, CPXCLPptr lp, double *objval_p) = NULL;
int (*__symbolic_CPXgetx) (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXgetax) (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXgetpi) (CPXCENVptr env, CPXCLPptr lp, double *pi, int begin, int end) = NULL;
int (*__symbolic_CPXgetslack) (CPXCENVptr env, CPXCLPptr lp, double *slack, int begin, int end) = NULL;
int (*__symbolic_CPXgetrowinfeas) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end) = NULL;
int (*__symbolic_CPXgetcolinfeas) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end) = NULL;
int (*__symbolic_CPXgetdj) (CPXCENVptr env, CPXCLPptr lp, double *dj, int begin, int end) = NULL;
int (*__symbolic_CPXgetgrad) (CPXCENVptr env, CPXCLPptr lp, int j, int *head, double *y) = NULL;
int (*__symbolic_CPXgetijdiv) (CPXCENVptr env, CPXCLPptr lp, int *idiv_p, int *jdiv_p) = NULL;
int (*__symbolic_CPXgetbase) (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat) = NULL;
int (*__symbolic_CPXgetitcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetphase1cnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsiftitcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsiftphase1cnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetbaritcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetcrossppushcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetcrosspexchcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetcrossdpushcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetcrossdexchcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetpsbcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetdsbcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetdblquality) (CPXCENVptr env, CPXCLPptr lp, double *quality_p, int what) = NULL;
int (*__symbolic_CPXgetsolnpooldblquality) (CPXCENVptr env, CPXCLPptr lp, int soln, double *quality_p, int what) = NULL;
int (*__symbolic_CPXgetintquality) (CPXCENVptr env, CPXCLPptr lp, int *quality_p, int what) = NULL;
int (*__symbolic_CPXgetsolnpoolintquality) (CPXCENVptr env, CPXCLPptr lp, int soln, int *quality_p, int what) = NULL;
int (*__symbolic_CPXrhssa) (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lower, double *upper) = NULL;
int (*__symbolic_CPXboundsa) (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lblower, double *lbupper, double *ublower, double *ubupper) = NULL;
int (*__symbolic_CPXobjsa) (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lower, double *upper) = NULL;
int (*__symbolic_CPXErangesa) (CPXENVptr env, CPXLPptr lp, int begin, int end, double *lblower, double *lbupper, double *ublower, double *ubupper) = NULL;
int (*__symbolic_CPXrefineconflict) (CPXCENVptr env, CPXLPptr lp, int *confnumrows_p, int *confnumcols_p) = NULL;
int (*__symbolic_CPXgetconflict) (CPXCENVptr env, CPXCLPptr lp, int *confstat_p, int *rowind, int *rowbdstat, int *confnumrows_p, int *colind, int *colbdstat, int *confnumcols_p) = NULL;
int (*__symbolic_CPXrefineconflictext) (CPXCENVptr env, CPXLPptr lp, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype) = NULL;
int (*__symbolic_CPXgetconflictext) (CPXCENVptr env, CPXCLPptr lp, int *grpstat, int beg, int end) = NULL;
int (*__symbolic_CPXclpwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXrobustopt) (CPXCENVptr env, CPXLPptr lp, CPXLPptr lblp, CPXLPptr ublp, double objchg, const double *maxchg) = NULL;
int (*__symbolic_CPXfeasopt) (CPXCENVptr env, CPXLPptr lp, const double *rhs, const double *rng, const double *lb, const double *ub) = NULL;
int (*__symbolic_CPXEfeasopt) (CPXCENVptr env, CPXLPptr lp, const double *rhs, const double *rng, const double *lb, const double *ub, const double *qrhs) = NULL;
int (*__symbolic_CPXfeasoptext) (CPXCENVptr env, CPXLPptr lp, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype) = NULL;
int (*__symbolic_CPXnewrows) (CPXCENVptr env, CPXLPptr lp, int rcnt, const double *rhs, const char *sense, const double *rngval, char **rowname) = NULL;
int (*__symbolic_CPXaddrows) (CPXCENVptr env, CPXLPptr lp, int ccnt, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **colname, char **rowname) = NULL;
int (*__symbolic_CPXnewcols) (CPXCENVptr env, CPXLPptr lp, int ccnt, const double *obj, const double *lb, const double *ub, const char *xctype, char **colname) = NULL;
int (*__symbolic_CPXaddcols) (CPXCENVptr env, CPXLPptr lp, int ccnt, int nzcnt, const double *obj, const int *cmatbeg, const int *cmatind, const double *cmatval, const double *lb, const double *ub, char **colname) = NULL;
int (*__symbolic_CPXdelrows) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXdelsetrows) (CPXCENVptr env, CPXLPptr lp, int *delstat) = NULL;
int (*__symbolic_CPXdelcols) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXdelsetcols) (CPXCENVptr env, CPXLPptr lp, int *delstat) = NULL;
int (*__symbolic_CPXchgname) (CPXCENVptr env, CPXLPptr lp, int key, int ij, const char *newname_str) = NULL;
int (*__symbolic_CPXchgrowname) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname) = NULL;
int (*__symbolic_CPXchgcolname) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname) = NULL;
int (*__symbolic_CPXdelnames) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXchgprobname) (CPXCENVptr env, CPXLPptr lp, const char *probname_str) = NULL;
int (*__symbolic_CPXchgcoef) (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue) = NULL;
int (*__symbolic_CPXchgcoeflist) (CPXCENVptr env, CPXLPptr lp, int numcoefs, const int *rowlist, const int *collist, const double *vallist) = NULL;
int (*__symbolic_CPXchgbds) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *lu, const double *bd) = NULL;
int (*__symbolic_CPXchgobj) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXchgrhs) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXchgrngval) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXchgsense) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *sense) = NULL;
void (*__symbolic_CPXchgobjsen) (CPXCENVptr env, CPXLPptr lp, int maxormin) = NULL;
int (*__symbolic_CPXchgprobtype) (CPXCENVptr env, CPXLPptr lp, int type) = NULL;
int (*__symbolic_CPXchgprobtypesolnpool) (CPXCENVptr env, CPXLPptr lp, int type, int soln) = NULL;
int (*__symbolic_CPXcompletelp) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXpreaddrows) (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname) = NULL;
int (*__symbolic_CPXprechgobj) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXgetnumcols) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumrows) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumnz) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetobjsen) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetobj) (CPXCENVptr env, CPXCLPptr lp, double *obj, int begin, int end) = NULL;
int (*__symbolic_CPXgetrhs) (CPXCENVptr env, CPXCLPptr lp, double *rhs, int begin, int end) = NULL;
int (*__symbolic_CPXgetsense) (CPXCENVptr env, CPXCLPptr lp, char *sense, int begin, int end) = NULL;
int (*__symbolic_CPXgetcols) (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *cmatbeg, int *cmatind, double *cmatval, int cmatspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetrows) (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *rmatbeg, int *rmatind, double *rmatval, int rmatspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetlb) (CPXCENVptr env, CPXCLPptr lp, double *lb, int begin, int end) = NULL;
int (*__symbolic_CPXgetub) (CPXCENVptr env, CPXCLPptr lp, double *ub, int begin, int end) = NULL;
int (*__symbolic_CPXgetrngval) (CPXCENVptr env, CPXCLPptr lp, double *rngval, int begin, int end) = NULL;
int (*__symbolic_CPXgetprobname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p) = NULL;
int (*__symbolic_CPXgetobjname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p) = NULL;
int (*__symbolic_CPXgetcolname) (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetrowname) (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetcoef) (CPXCENVptr env, CPXCLPptr lp, int i, int j, double *coef_p) = NULL;
int (*__symbolic_CPXgetrowindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetcolindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetprobtype) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXreadcopyprob) (CPXCENVptr env, CPXLPptr lp, const char *filename_str, const char *filetype_str) = NULL;
int (*__symbolic_CPXreadcopybase) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXreadcopysol) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXwriteprob) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, const char *filetype_str) = NULL;
int (*__symbolic_CPXmbasewrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXsolwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXsolwritesolnpool) (CPXCENVptr env, CPXCLPptr lp, int soln, const char *filename_str) = NULL;
int (*__symbolic_CPXsolwritesolnpoolall) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXembwrite) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXdperwrite) (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double epsilon) = NULL;
int (*__symbolic_CPXpperwrite) (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double epsilon) = NULL;
int (*__symbolic_CPXpreslvwrite) (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double *objoff_p) = NULL;
int (*__symbolic_CPXdualwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, double *objshift_p) = NULL;
int (*__symbolic_CPXsetdefaults) (CPXENVptr env) = NULL;
int (*__symbolic_CPXsetintparam) (CPXENVptr env, int whichparam, int newvalue) = NULL;
int (*__symbolic_CPXsetdblparam) (CPXENVptr env, int whichparam, double newvalue) = NULL;
int (*__symbolic_CPXsetstrparam) (CPXENVptr env, int whichparam, const char *newvalue_str) = NULL;
int (*__symbolic_CPXgetintparam) (CPXCENVptr env, int whichparam, int *value_p) = NULL;
int (*__symbolic_CPXgetdblparam) (CPXCENVptr env, int whichparam, double *value_p) = NULL;
int (*__symbolic_CPXgetstrparam) (CPXCENVptr env, int whichparam, char *value_str) = NULL;
int (*__symbolic_CPXinfointparam) (CPXCENVptr env, int whichparam, int *defvalue_p, int *minvalue_p, int *maxvalue_p) = NULL;
int (*__symbolic_CPXinfodblparam) (CPXCENVptr env, int whichparam, double *defvalue_p, double *minvalue_p, double *maxvalue_p) = NULL;
int (*__symbolic_CPXinfostrparam) (CPXCENVptr env, int whichparam, char *defvalue_str) = NULL;
int (*__symbolic_CPXgetparamname) (CPXCENVptr env, int whichparam, char *name_str) = NULL;
int (*__symbolic_CPXgetparamnum) (CPXCENVptr env, const char *name_str, int *whichparam_p) = NULL;
int (*__symbolic_CPXgetparamtype) (CPXCENVptr env, int whichparam, int *paramtype) = NULL;
int (*__symbolic_CPXreadcopyparam) (CPXENVptr env, const char *filename_str) = NULL;
int (*__symbolic_CPXwriteparam) (CPXCENVptr env, const char *filename_str) = NULL;
int (*__symbolic_CPXgetchgparam) (CPXCENVptr env, int *cnt_p, int *paramnum, int pspace, int *surplus_p) = NULL;
int (*__symbolic_CPXtuneparam) (CPXENVptr env, CPXLPptr lp, int intcnt, const int *intnum, const int *intval, int dblcnt, const int *dblnum, const double *dblval, int strcnt, const int *strnum, char **strval, int *tunestat_p) = NULL;
int (*__symbolic_CPXtuneparamprobset) (CPXENVptr env, int filecnt, char **filename, char **filetype, int intcnt, const int *intind, const int *intval, int dblcnt, const int *dblind, const double *dblval, int strcnt, const int *strind, char **strval, int *tunestat_p) = NULL;
CPXCCHARptr (*__symbolic_CPXversion) (CPXCENVptr env) = NULL;
CPXENVptr (*__symbolic_CPXopenCPLEX) (int *status_p) = NULL;
CPXENVptr (*__symbolic_CPXopenCPLEXruntime) (int *status_p, int serialnum, const char *licenvstring_str) = NULL;
int (*__symbolic_CPXcloseCPLEX) (CPXENVptr * env_p) = NULL;
int (*__symbolic_CPXsetstaringsol) (const char *ilm_license_str, int ilm_license_signature) = NULL;
CPXENVptr (*__symbolic_CPXparenv) (CPXENVptr env, int *status_p) = NULL;
int (*__symbolic_CPXfreeparenv) (CPXENVptr env, CPXENVptr * child_p) = NULL;
int (*__symbolic_CPXcheckcopylp) (CPXCENVptr env, CPXCLPptr lp, int numcols, int numrows, int objsen, const double *obj, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval) = NULL;
int (*__symbolic_CPXcheckcopylpwnames) (CPXCENVptr env, CPXCLPptr lp, int numcols, int numrows, int objsen, const double *obj, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval, char **colname, char **rowname) = NULL;
int (*__symbolic_CPXcheckaddcols) (CPXCENVptr env, CPXCLPptr lp, int ccnt, int nzcnt, const double *obj, const int *cmatbeg, const int *cmatind, const double *cmatval, const double *lb, const double *ub, char **colname) = NULL;
int (*__symbolic_CPXcheckaddrows) (CPXCENVptr env, CPXCLPptr lp, int ccnt, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **colname, char **rowname) = NULL;
int (*__symbolic_CPXcheckchgcoeflist) (CPXCENVptr env, CPXCLPptr lp, int numcoefs, const int *rowlist, const int *collist, const double *vallist) = NULL;
int (*__symbolic_CPXcheckvals) (CPXCENVptr env, CPXCLPptr lp, int cnt, const int *rowind, const int *colind, const double *values) = NULL;
int (*__symbolic_CPXgetchannels) (CPXCENVptr env, CPXCHANNELptr * cpxresults_p, CPXCHANNELptr * cpxwarning_p, CPXCHANNELptr * cpxerror_p, CPXCHANNELptr * cpxlog_p) = NULL;
int (*__symbolic_CPXsetlogfile) (CPXENVptr env, CPXFILEptr lfile) = NULL;
int (*__symbolic_CPXgetlogfile) (CPXCENVptr env, CPXFILEptr * logfile_p) = NULL;
int (*__symbolic_CPXmsg) (CPXCHANNELptr channel, const char *format, ...) = NULL;
int (*__symbolic_CPXmsgstr) (CPXCHANNELptr channel, const char *msg_str) = NULL;
void (*__symbolic_CPXflushchannel) (CPXCENVptr env, CPXCHANNELptr channel) = NULL;
int (*__symbolic_CPXflushstdchannels) (CPXCENVptr env) = NULL;
CPXCHANNELptr (*__symbolic_CPXaddchannel) (CPXENVptr env) = NULL;
int (*__symbolic_CPXaddfpdest) (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr) = NULL;
int (*__symbolic_CPXdelfpdest) (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr) = NULL;
int (*__symbolic_CPXaddfuncdest) (CPXCENVptr env, CPXCHANNELptr channel, void *handle, void ( * msgfunction) (void *, const char *)) = NULL;
int (*__symbolic_CPXdelfuncdest) (CPXCENVptr env, CPXCHANNELptr channel, void *handle, void ( * msgfunction) (void *, const char *)) = NULL;
void (*__symbolic_CPXdelchannel) (CPXENVptr env, CPXCHANNELptr * channel_p) = NULL;
void (*__symbolic_CPXdisconnectchannel) (CPXCENVptr env, CPXCHANNELptr channel) = NULL;
CPXCCHARptr (*__symbolic_CPXgeterrorstring) (CPXCENVptr env, int errcode, char *buffer_str) = NULL;
int (*__symbolic_CPXsetlpcallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle) = NULL;
int (*__symbolic_CPXsetnetcallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle) = NULL;
int (*__symbolic_CPXsettuningcallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle) = NULL;
int (*__symbolic_CPXgetcallbackinfo) (CPXCENVptr env, void *cbdata, int wherefrom, int whichinfo, void *result_p) = NULL;
int (*__symbolic_CPXgetlpcallbackfunc) (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p) = NULL;
int (*__symbolic_CPXgetnetcallbackfunc) (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p) = NULL;
int (*__symbolic_CPXgettuningcallbackfunc) (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p) = NULL;
int (*__symbolic_CPXsetprofcallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, int, void *), void *cbhandle) = NULL;
CPXFILEptr (*__symbolic_CPXfopen) (const char *filename_str, const char *type_str) = NULL;
int (*__symbolic_CPXfclose) (CPXFILEptr stream) = NULL;
int (*__symbolic_CPXfputs) (const char *s_str, CPXFILEptr stream) = NULL;
CPXVOIDptr (*__symbolic_CPXmalloc) (size_t size) = NULL;
CPXVOIDptr (*__symbolic_CPXrealloc) (void *ptr, size_t size) = NULL;
CPXVOIDptr (*__symbolic_CPXmemcpy) (void *s1, void *s2, size_t n) = NULL;
void (*__symbolic_CPXfree) (void *ptr) = NULL;
int (*__symbolic_CPXstrlen) (const char *s_str) = NULL;
CPXCHARptr (*__symbolic_CPXstrcpy) (char *dest_str, const char *src_str) = NULL;
int (*__symbolic_CPXputenv) (const char *envsetting_str) = NULL;
void (*__symbolic_CPXEisort) (int n, int *a, int *perm) = NULL;
void (*__symbolic_CPXEinsort) (int n, int *a) = NULL;
int (*__symbolic_CPXEgetThreadNumber) (CPXCENVptr env) = NULL;
int (*__symbolic_CPXEgetmaxthreads) (CPXCENVptr env) = NULL;
int (*__symbolic_CPXEsetJNI) (CPXENVptr env, CPXVOIDptr jni) = NULL;
CPXVOIDptr (*__symbolic_CPXEgetJNI) (CPXCENVptr env) = NULL;
int (*__symbolic_CPXEsetnamefunctions) (CPXENVptr env, void *userdata, const char *( * getcname) (void *, int, char *), const char *( * getrname) (void *, int, char *), const char *( * getqname) (void *, int, char *), const char *( * getiname) (void *, int, char *), const char *( * getsname) (void *, int, char *)) = NULL;
int (*__symbolic_CPXEsetnamedef) (CPXENVptr env, const char *def_str, int deftype) = NULL;
int (*__symbolic_CPXEdelnames) (CPXCENVptr env, CPXLPptr lp) = NULL;
CPXVOIDptr (*__symbolic_CPXEgetCache) (CPXLPptr lp) = NULL;
int (*__symbolic_CPXEcacheNewCols) (CPXCENVptr env, CPXLPptr lp, int ccnt, const double *zobj, const double *zlb, const double *zub, const char *zctype, const char *const *zcname) = NULL;
int (*__symbolic_CPXEcacheNewRows) (CPXCENVptr env, CPXLPptr lp, int rcnt, const double *zrhs, const char *zsense, const double *rngval, const char *const *zrname) = NULL;
int (*__symbolic_CPXEcacheNewNZsByNZ) (CPXCENVptr env, CPXLPptr lp, int nzcnt, const int *rowlist, const int *collist, const double *vallist) = NULL;
int (*__symbolic_CPXEgetorigcolind) (CPXCENVptr env, CPXCLPptr lp, int j) = NULL;
int (*__symbolic_CPXEgetorigrowind) (CPXCENVptr env, CPXCLPptr lp, int i) = NULL;
double (*__symbolic_CPXEgetbigreal) (CPXCENVptr env) = NULL;
int (*__symbolic_CPXEispromotion) (CPXCENVptr env, int rspace, int cspace, int ispace) = NULL;
int (*__symbolic_CPXEgetnumrownz) (CPXCENVptr env, CPXCLPptr lp, int *mark) = NULL;
int (*__symbolic_CPXEcangetbase) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXEwriteparam) (CPXCENVptr env, const char *filename_str) = NULL;
int (*__symbolic_CPXsetterminate) (CPXENVptr env, volatile int *terminate_p) = NULL;
void (*__symbolic_CPXEsetterminatefunc) (CPXENVptr env, int ( * terminatefunc) (CPXCENVptr)) = NULL;
int (*__symbolic_CPXEnsAddNames) (struct cpxnameset *nset, int n, const char *const *name) = NULL;
int (*__symbolic_CPXgetbhead) (CPXCENVptr env, CPXCLPptr lp, int *head, double *x) = NULL;
int (*__symbolic_CPXbinvcol) (CPXCENVptr env, CPXCLPptr lp, int j, double *x) = NULL;
int (*__symbolic_CPXbinvrow) (CPXCENVptr env, CPXCLPptr lp, int i, double *y) = NULL;
int (*__symbolic_CPXbinvacol) (CPXCENVptr env, CPXCLPptr lp, int j, double *x) = NULL;
int (*__symbolic_CPXbinvarow) (CPXCENVptr env, CPXCLPptr lp, int i, double *z) = NULL;
int (*__symbolic_CPXftran) (CPXCENVptr env, CPXCLPptr lp, double *x) = NULL;
int (*__symbolic_CPXbtran) (CPXCENVptr env, CPXCLPptr lp, double *y) = NULL;
int (*__symbolic_CPXgetijrow) (CPXCENVptr env, CPXCLPptr lp, int i, int j, int *row_p) = NULL;
int (*__symbolic_CPXgetray) (CPXCENVptr env, CPXCLPptr lp, double *z) = NULL;
int (*__symbolic_CPXgetweight) (CPXCENVptr env, CPXCLPptr lp, int rcnt, const int *rmatbeg, const int *rmatind, const double *rmatval, double *weight, int dpriind) = NULL;
int (*__symbolic_CPXmdleave) (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio) = NULL;
int (*__symbolic_CPXstrongbranch) (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downobj, double *upobj, int itlim) = NULL;
int (*__symbolic_CPXdualfarkas) (CPXCENVptr env, CPXCLPptr lp, double *y, double *proof_p) = NULL;
int (*__symbolic_CPXgetobjoffset) (CPXCENVptr env, CPXCLPptr lp, double *objoffset_p) = NULL;
int (*__symbolic_CPXcopypartialbase) (CPXCENVptr env, CPXLPptr lp, int ccnt, const int *cindices, const int *cstat, int rcnt, const int *rindices, const int *rstat) = NULL;
int (*__symbolic_CPXgetbasednorms) (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat, double *dnorm) = NULL;
int (*__symbolic_CPXcopybasednorms) (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat, const double *dnorm) = NULL;
int (*__symbolic_CPXgetdnorms) (CPXCENVptr env, CPXCLPptr lp, double *norm, int *head, int *len_p) = NULL;
int (*__symbolic_CPXcopydnorms) (CPXCENVptr env, CPXLPptr lp, const double *norm, const int *head, int len) = NULL;
void (*__symbolic_CPXkilldnorms) (CPXLPptr lp) = NULL;
int (*__symbolic_CPXgetpnorms) (CPXCENVptr env, CPXCLPptr lp, double *cnorm, double *rnorm, int *len_p) = NULL;
int (*__symbolic_CPXcopypnorms) (CPXCENVptr env, CPXLPptr lp, const double *cnorm, const double *rnorm, int len) = NULL;
void (*__symbolic_CPXkillpnorms) (CPXLPptr lp) = NULL;
int (*__symbolic_CPXpivotin) (CPXCENVptr env, CPXLPptr lp, const int *rlist, int rlen) = NULL;
int (*__symbolic_CPXpivotout) (CPXCENVptr env, CPXLPptr lp, const int *clist, int clen) = NULL;
int (*__symbolic_CPXunscaleprob) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXtightenbds) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *lu, const double *bd) = NULL;
int (*__symbolic_CPXpresolve) (CPXCENVptr env, CPXLPptr lp, int method) = NULL;
int (*__symbolic_CPXbasicpresolve) (CPXCENVptr env, CPXLPptr lp, double *redlb, double *redub, int *rstat) = NULL;
int (*__symbolic_CPXslackfromx) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *slack) = NULL;
int (*__symbolic_CPXdjfrompi) (CPXCENVptr env, CPXCLPptr lp, const double *pi, double *dj) = NULL;
int (*__symbolic_CPXqpdjfrompi) (CPXCENVptr env, CPXCLPptr lp, const double *pi, const double *x, double *dj) = NULL;
int (*__symbolic_CPXfreepresolve) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXgetredlp) (CPXCENVptr env, CPXCLPptr lp, CPXCLPptr * redlp_p) = NULL;
int (*__symbolic_CPXcrushx) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *prex) = NULL;
int (*__symbolic_CPXuncrushx) (CPXCENVptr env, CPXCLPptr lp, double *x, const double *prex) = NULL;
int (*__symbolic_CPXcrushpi) (CPXCENVptr env, CPXCLPptr lp, const double *pi, double *prepi) = NULL;
int (*__symbolic_CPXuncrushpi) (CPXCENVptr env, CPXCLPptr lp, double *pi, const double *prepi) = NULL;
int (*__symbolic_CPXqpuncrushpi) (CPXCENVptr env, CPXCLPptr lp, double *pi, const double *prepi, const double *x) = NULL;
int (*__symbolic_CPXcrushform) (CPXCENVptr env, CPXCLPptr lp, int len, const int *ind, const double *val, int *plen_p, double *poffset_p, int *pind, double *pval) = NULL;
int (*__symbolic_CPXuncrushform) (CPXCENVptr env, CPXCLPptr lp, int plen, const int *pind, const double *pval, int *len_p, double *offset_p, int *ind, double *val) = NULL;
int (*__symbolic_CPXgetprestat) (CPXCENVptr env, CPXCLPptr lp, int *prestat_p, int *pcstat, int *prstat, int *ocstat, int *orstat) = NULL;
int (*__symbolic_CPXcopyprotected) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices) = NULL;
int (*__symbolic_CPXgetprotected) (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, int pspace, int *surplus_p) = NULL;
int (*__symbolic_CPXEaggregatevars) (CPXCENVptr env, CPXLPptr lp, int start, int end, const char *protectrow) = NULL;
int (*__symbolic_CPXgettime) (CPXCENVptr env, double *timestamp) = NULL;
int (*__symbolic_CPXlpwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXlprewrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXmpswrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXmpsrewrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXsavwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXreadcopyvec) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXvecwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXbinsolwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXtxtsolwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXwritesol) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, const char *filetype_str) = NULL;
int (*__symbolic_CPXgetiis) (CPXCENVptr env, CPXCLPptr lp, int *iisstat_p, int *rowind, int *rowbdstat, int *iisnumrows_p, int *colind, int *colbdstat, int *iisnumcols_p) = NULL;
int (*__symbolic_CPXfindiis) (CPXCENVptr env, CPXLPptr lp, int *iisnumrows_p, int *iisnumcols_p) = NULL;
int (*__symbolic_CPXdisplayiis) (CPXCENVptr env, CPXCLPptr lp, CPXCHANNELptr channel, int display) = NULL;
int (*__symbolic_CPXiiswrite) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXhybbaropt) (CPXCENVptr env, CPXLPptr lp, int method) = NULL;
int (*__symbolic_CPXbaropt) (CPXCENVptr env, CPXLPptr lp) = NULL;
void (*__symbolic_CPXEgeneric_lock) (volatile int *lock) = NULL;
void (*__symbolic_CPXEgeneric_unlock) (volatile int *lock) = NULL;
int (*__symbolic_CPXsetorderhookfunc) (CPXENVptr env, int ( * orderhook) (CPXCENVptr, int, int *, int **, int *)) = NULL;
void (*__symbolic_CPXgetorderhookfunc) (CPXCENVptr env, int ( ** orderhook_p) (CPXCENVptr, int, int *, int **, int *)) = NULL;
int (*__symbolic_CPXcopyctype) (CPXCENVptr env, CPXLPptr lp, const char *xctype) = NULL;
int (*__symbolic_CPXcopyorder) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const int *priority, const int *direction) = NULL;
int (*__symbolic_CPXcopysos) (CPXCENVptr env, CPXLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname) = NULL;
int (*__symbolic_CPXcopymipstart) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXchgmipstart) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values) = NULL;
int (*__symbolic_CPXchgmipstarts) (CPXCENVptr env, CPXLPptr lp, int mcnt, const int *mipstartindices, int nzcnt, const int *beg, const int *varindices, const double *values, const int *effortlevel) = NULL;
int (*__symbolic_CPXaddmipstarts) (CPXCENVptr env, CPXLPptr lp, int mcnt, int nzcnt, const int *beg, const int *varindices, const double *values, const int *effortlevel, char **mipstartname) = NULL;
int (*__symbolic_CPXdelmipstarts) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXdelsetmipstarts) (CPXCENVptr env, CPXLPptr lp, int *delstat) = NULL;
int (*__symbolic_CPXrefinemipstartconflict) (CPXCENVptr env, CPXLPptr lp, int mipstartindex, int *confnumrows_p, int *confnumcols_p) = NULL;
int (*__symbolic_CPXrefinemipstartconflictext) (CPXCENVptr env, CPXLPptr lp, int mipstartindex, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype) = NULL;
int (*__symbolic_CPXmipopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXgetmipitcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetbestobjval) (CPXCENVptr env, CPXCLPptr lp, double *objval_p) = NULL;
int (*__symbolic_CPXgetmiprelgap) (CPXCENVptr env, CPXCLPptr lp, double *gap_p) = NULL;
int (*__symbolic_CPXgetcutoff) (CPXCENVptr env, CPXCLPptr lp, double *cutoff_p) = NULL;
int (*__symbolic_CPXgetnodecnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnodeleftcnt) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnodeint) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumcuts) (CPXCENVptr env, CPXCLPptr lp, int cuttype, int *num_p) = NULL;
int (*__symbolic_CPXgetnummipstarts) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetmipstart) (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, double *value, int mipstartspace, int *surplus_p) = NULL;
int (*__symbolic_CPXgetmipstarts) (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *beg, int *varindices, double *values, int *effortlevel, int startspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetmipstartname) (CPXCENVptr env, CPXCLPptr lp, char **name, char *store, int storesz, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetmipstartindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetsolnpoolmipstart) (CPXCENVptr env, CPXCLPptr lp, int soln, int *cnt_p, int *indices, double *value, int mipstartspace, int *surplus_p) = NULL;
int (*__symbolic_CPXgetsolnpoolnummipstarts) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsubstat) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsubmethod) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXchgctype) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *xctype) = NULL;
int (*__symbolic_CPXaddsos) (CPXCENVptr env, CPXLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname) = NULL;
int (*__symbolic_CPXdelsetsos) (CPXCENVptr env, CPXLPptr lp, int *delset) = NULL;
int (*__symbolic_CPXgetctype) (CPXCENVptr env, CPXCLPptr lp, char *xctype, int begin, int end) = NULL;
int (*__symbolic_CPXgetnumsos) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsos) (CPXCENVptr env, CPXCLPptr lp, int *numsosnz_p, char *sostype, int *sosbeg, int *sosind, double *soswt, int sosspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetsosname) (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXgetsosindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetsosinfeas) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end) = NULL;
int (*__symbolic_CPXgetnumindconstrs) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetindconstr) (CPXCENVptr env, CPXCLPptr lp, int *indvar_p, int *complemented_p, int *nzcnt_p, double *rhs_p, char *sense_p, int *linind, double *linval, int space, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXEgetindicator) (CPXCENVptr env, CPXCLPptr lp, int *indvar_p, int *complemented_p, int *nzcnt_p, double *rhs_p, char *sense_p, int *ind, double *val, int space, int *surplus_p, int *type_p, int which) = NULL;
int (*__symbolic_CPXgetindconstrindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetindconstrname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetindconstrslack) (CPXCENVptr env, CPXCLPptr lp, double *indslack, int begin, int end) = NULL;
int (*__symbolic_CPXindconstrslackfromx) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *indslack) = NULL;
int (*__symbolic_CPXgetindconstrinfeas) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end) = NULL;
int (*__symbolic_CPXdelindconstrs) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXgetnumint) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumbin) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumsemicont) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumsemiint) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetorder) (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, int *priority, int *direction, int ordspace, int *surplus_p) = NULL;
int (*__symbolic_CPXpopulate) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXgetsolnpoolnumfilters) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXaddsolnpooldivfilter) (CPXCENVptr env, CPXLPptr lp, double lower_bound, double upper_bound, int nzcnt, const int *ind, const double *weight, const double *refval, const char *lname_str) = NULL;
int (*__symbolic_CPXaddsolnpoolrngfilter) (CPXCENVptr env, CPXLPptr lp, double lb, double ub, int nzcnt, const int *ind, const double *val, const char *lname_str) = NULL;
int (*__symbolic_CPXgetsolnpoolfiltertype) (CPXCENVptr env, CPXCLPptr lp, int *ftype_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpooldivfilter) (CPXCENVptr env, CPXCLPptr lp, double *lowercutoff_p, double *upper_cutoff_p, int *nzcnt_p, int *ind, double *val, double *refval, int space, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpoolfilter) (CPXCENVptr env, CPXCLPptr lp, int *ftype_p, double *lowercutoff_p, double *upper_cutoff_p, int *nzcnt_p, int *ind, double *val, double *refval, int space, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpoolrngfilter) (CPXCENVptr env, CPXCLPptr lp, double *lb_p, double *ub_p, int *nzcnt_p, int *ind, double *val, int space, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpoolfiltername) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpoolfilterindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXdelsolnpoolfilters) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXdelsetsolnpoolfilters) (CPXCENVptr env, CPXLPptr lp, int *delstat) = NULL;
int (*__symbolic_CPXgetsolnpoolnumsolns) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsolnpoolnumreplaced) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetsolnpoolmeanobjval) (CPXCENVptr env, CPXCLPptr lp, double *meanobjval_p) = NULL;
int (*__symbolic_CPXgetsolnpoolobjval) (CPXCENVptr env, CPXCLPptr lp, int soln, double *objval_p) = NULL;
int (*__symbolic_CPXgetsolnpoolx) (CPXCENVptr env, CPXCLPptr lp, int soln, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXgetsolnpoolslack) (CPXCENVptr env, CPXCLPptr lp, int soln, double *slack, int begin, int end) = NULL;
int (*__symbolic_CPXgetsolnpoolqconstrslack) (CPXCENVptr env, CPXCLPptr lp, int soln, double *qcslack, int begin, int end) = NULL;
int (*__symbolic_CPXgetsolnpoolsolnname) (CPXCENVptr env, CPXCLPptr lp, char *store, int storesz, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetsolnpoolsolnindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXdelsolnpoolsolns) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXdelsetsolnpoolsolns) (CPXCENVptr env, CPXLPptr lp, int *delstat) = NULL;
int (*__symbolic_CPXreadcopyorder) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXreadcopysolnpoolfilters) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXreadcopymipstart) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXreadcopymipstarts) (CPXCENVptr env, CPXLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXordwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXmstwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXwritemipstarts) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, int begin, int end) = NULL;
int (*__symbolic_CPXmstwritesolnpool) (CPXCENVptr env, CPXCLPptr lp, int soln, const char *filename_str) = NULL;
int (*__symbolic_CPXmstwritesolnpoolall) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXfltwrite) (CPXCENVptr env, CPXCLPptr lp, const char *filename_str) = NULL;
int (*__symbolic_CPXcheckcopyctype) (CPXCENVptr env, CPXCLPptr lp, const char *xctype) = NULL;
int (*__symbolic_CPXcheckcopysos) (CPXCENVptr env, CPXCLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname) = NULL;
int (*__symbolic_CPXEchgsosname) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname) = NULL;
int (*__symbolic_CPXsetinfocallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle) = NULL;
int (*__symbolic_CPXgetinfocallbackfunc) (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p) = NULL;
int (*__symbolic_CPXsetmipcallbackfunc) (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle) = NULL;
int (*__symbolic_CPXgetmipcallbackfunc) (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p) = NULL;
int (*__symbolic_CPXsetbranchcallbackfunc) (CPXENVptr env, int ( * branchcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void *cbhandle) = NULL;
int (*__symbolic_CPXsetbranchnosolncallbackfunc) (CPXENVptr env, int ( * branchnosolncallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void *cbhandle) = NULL;
int (*__symbolic_CPXsetcutcallbackfunc) (CPXENVptr env, int ( * cutcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction_p), void *cbhandle) = NULL;
int (*__symbolic_CPXsetnodecallbackfunc) (CPXENVptr env, int ( * nodecallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *nodeindex, int *useraction), void *cbhandle) = NULL;
int (*__symbolic_CPXsetheuristiccallbackfunc) (CPXENVptr env, int ( * heuristiccallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double *objval_p, double *x, int *checkfeas_p, int *useraction_p), void *cbhandle) = NULL;
int (*__symbolic_CPXsetincumbentcallbackfunc) (CPXENVptr env, int ( * incumbentcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double objval, double *x, int *isfeas_p, int *useraction_p), void *cbhandle) = NULL;
int (*__symbolic_CPXsetsolvecallbackfunc) (CPXENVptr env, int ( * solvecallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction), void *cbhandle) = NULL;
int (*__symbolic_CPXsetdeletenodecallbackfunc) (CPXENVptr env, void ( * deletecallback) (CPXCENVptr xenv, int wherefrom, void *cbhandle, int seqnum, void *handle), void *cbhandle) = NULL;
void (*__symbolic_CPXgetbranchcallbackfunc) (CPXCENVptr env, int ( ** branchcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetbranchnosolncallbackfunc) (CPXCENVptr env, int ( ** branchnosolncallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetcutcallbackfunc) (CPXCENVptr env, int ( ** cutcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction_p), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetnodecallbackfunc) (CPXCENVptr env, int ( ** nodecallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *nodeindex, int *useraction), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetheuristiccallbackfunc) (CPXCENVptr env, int ( ** heuristiccallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double *objval_p, double *x, int *checkfeas_p, int *useraction_p), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetincumbentcallbackfunc) (CPXCENVptr env, int ( ** incumbentcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double objval, double *x, int *isfeas_p, int *useraction_p), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetsolvecallbackfunc) (CPXCENVptr env, int ( ** solvecallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction), void **cbhandle_p) = NULL;
void (*__symbolic_CPXgetdeletenodecallbackfunc) (CPXCENVptr env, void ( ** deletecallback_p) (CPXCENVptr xenv, int wherefrom, void *cbhandle, int seqnum, void *handle), void **cbhandle_p) = NULL;
int (*__symbolic_CPXgetcallbacknodelp) (CPXCENVptr env, void *cbdata, int wherefrom, CPXLPptr * nodelp_p) = NULL;
int (*__symbolic_CPXgetcallbacknodeinfo) (CPXCENVptr env, void *cbdata, int wherefrom, int nodeindex, int whichinfo, void *result_p) = NULL;
int (*__symbolic_CPXgetcallbackseqinfo) (CPXCENVptr env, void *cbdata, int wherefrom, int seqid, int whichinfo, void *result_p) = NULL;
int (*__symbolic_CPXgetcallbacksosinfo) (CPXCENVptr env, void *cbdata, int wherefrom, int sosindex, int member, int whichinfo, void *result_p) = NULL;
int (*__symbolic_CPXgetcallbackindicatorinfo) (CPXCENVptr env, void *cbdata, int wherefrom, int iindex, int whichinfo, void *result_p) = NULL;
int (*__symbolic_CPXcutcallbackadd) (CPXCENVptr env, void *cbdata, int wherefrom, int nzcnt, double rhs, int sense, const int *cutind, const double *cutval, int purgeable) = NULL;
int (*__symbolic_CPXcutcallbackaddlocal) (CPXCENVptr env, void *cbdata, int wherefrom, int nzcnt, double rhs, int sense, const int *cutind, const double *cutval) = NULL;
int (*__symbolic_CPXbranchcallbackbranchbds) (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int cnt, const int *indices, const char *lu, const int *bd, void *userhandle, int *seqnum_p) = NULL;
int (*__symbolic_CPXbranchcallbackbranchgeneral) (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int varcnt, const int *varind, const char *varlu, const int *varbd, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, void *userhandle, int *seqnum_p) = NULL;
int (*__symbolic_CPXbranchcallbackbranchconstraints) (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, void *userhandle, int *seqnum_p) = NULL;
int (*__symbolic_CPXgetcallbacknodex) (CPXCENVptr env, void *cbdata, int wherefrom, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbacknodeobjval) (CPXCENVptr env, void *cbdata, int wherefrom, double *objval_p) = NULL;
int (*__symbolic_CPXgetcallbackctype) (CPXCENVptr env, void *cbdata, int wherefrom, char *xctype, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbackorder) (CPXCENVptr env, void *cbdata, int wherefrom, int *priority, int *direction, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbackpseudocosts) (CPXCENVptr env, void *cbdata, int wherefrom, double *uppc, double *downpc, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbackincumbent) (CPXCENVptr env, void *cbdata, int wherefrom, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbacknodeintfeas) (CPXCENVptr env, void *cbdata, int wherefrom, int *feas, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbackgloballb) (CPXCENVptr env, void *cbdata, int wherefrom, double *lb, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbackglobalub) (CPXCENVptr env, void *cbdata, int wherefrom, double *ub, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbacknodelb) (CPXCENVptr env, void *cbdata, int wherefrom, double *lb, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbacknodeub) (CPXCENVptr env, void *cbdata, int wherefrom, double *ub, int begin, int end) = NULL;
int (*__symbolic_CPXgetcallbacklp) (CPXCENVptr env, void *cbdata, int wherefrom, CPXCLPptr * lp_p) = NULL;
int (*__symbolic_CPXgetcallbacknodestat) (CPXCENVptr env, void *cbdata, int wherefrom, int *nodestat_p) = NULL;
int (*__symbolic_CPXgetcallbackbranchconstraints) (CPXCENVptr env, void *cbdata, int wherefrom, int which, int *cuts_p, int *nzcnt_p, double *rhs, char *sense, int *rmatbeg, int *rmatind, double *rmatval, int rmatsz, int *surplus_p) = NULL;
int (*__symbolic_CPXaddusercuts) (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname) = NULL;
int (*__symbolic_CPXaddlazyconstraints) (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname) = NULL;
int (*__symbolic_CPXfreeusercuts) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXfreelazyconstraints) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXEgetusercuts) (CPXCENVptr env, CPXCLPptr lp, int *rcnt_p, int *nzcnt_p, double **zrhs_p, char **zsense_p, int **rmatbeg_p, int **rmatind_p, double **rmatval_p) = NULL;
int (*__symbolic_CPXEgetusercutname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXEgetlazyconstraints) (CPXCENVptr env, CPXCLPptr lp, int *rcnt_p, int *nzcnt_p, double **zrhs_p, char **zsense_p, int **rmatbeg_p, int **rmatind_p, double **rmatval_p) = NULL;
int (*__symbolic_CPXEgetlazyconstraintname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXordread) (CPXCENVptr env, const char *filename_str, int numcols, char **colname, int *cnt_p, int *indices, int *priority, int *direction) = NULL;
int (*__symbolic_CPXaddindconstr) (CPXCENVptr env, CPXLPptr lp, int indvar, int complemented, int nzcnt, double rhs, int sense, const int *linind, const double *linval, const char *indname_str) = NULL;
int (*__symbolic_CPXEgetnumgconstrs) (CPXCENVptr env, CPXCLPptr lp, int contype) = NULL;
int (*__symbolic_CPXEdelgconstrs) (CPXCENVptr env, CPXLPptr lp, int contype, int beg, int end) = NULL;
int (*__symbolic_CPXEaddindconstr) (CPXCENVptr env, CPXLPptr lp, int indicator, int complemented, int linnzcnt, double rhs, int sense, const int *linind, const double *linval, int type, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddminexpr) (CPXCENVptr env, CPXLPptr lp, int y, double constant, int nexpr, int nnz, const int *matbeg, const int *matind, const double *matval, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddmaxexpr) (CPXCENVptr env, CPXLPptr lp, int y, double constant, int nexpr, int nnz, const int *matbeg, const int *matind, const double *matval, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddpwl) (CPXCENVptr env, CPXLPptr lp, int y, int npoints, double *point, int nslopes, double *slope, double a, double b, int x, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddabs) (CPXCENVptr env, CPXLPptr lp, int y, int x, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvar) (CPXCENVptr env, CPXLPptr lp, const int npvalues, const double *pvalues, const int nrvalues, const double *rvalues, const char *lname_str) = NULL;
int (*__symbolic_CPXEchgsetvar) (CPXCENVptr env, CPXLPptr lp, const int setvarid, const int npvalues, const double *pvalues, const int nrvalues, const double *rvalues) = NULL;
int (*__symbolic_CPXEgetsetvarvalues) (CPXCENVptr env, CPXLPptr lp, const int setvarid, const int nvalues, const int *values, int *soln) = NULL;
int (*__symbolic_CPXEaddsetvarmember) (CPXCENVptr env, CPXLPptr lp, const int indvarid, const int setvarid, const double value, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarcard) (CPXCENVptr env, CPXLPptr lp, const int cardvarid, const int setvarid, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarsum) (CPXCENVptr env, CPXLPptr lp, const int sumvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarmin) (CPXCENVptr env, CPXLPptr lp, const int minvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarmax) (CPXCENVptr env, CPXLPptr lp, const int maxvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarsubset) (CPXCENVptr env, CPXLPptr lp, const int setvar1, const int setvar2, const int strict, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvardomain) (CPXCENVptr env, CPXLPptr lp, const int setvar, const int nvalues, const double *values, const int possible, const int required, const int forbidden, const int strict, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarunion) (CPXCENVptr env, CPXLPptr lp, const int unionsetvar, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarintersection) (CPXCENVptr env, CPXLPptr lp, const int unionsetvar, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarnullintersect) (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarintersect) (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvareq) (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarneq) (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str) = NULL;
int (*__symbolic_CPXEaddsetvarneqcst) (CPXCENVptr env, CPXLPptr lp, const int servar1, const int nvalues, const double *values, const char *lname_str) = NULL;
CPXNETptr (*__symbolic_CPXNETcreateprob) (CPXENVptr env, int *status_p, const char *name_str) = NULL;
int (*__symbolic_CPXNETfreeprob) (CPXENVptr env, CPXNETptr * net_p) = NULL;
int (*__symbolic_CPXNETcopynet) (CPXCENVptr env, CPXNETptr net, int objsen, int nnodes, const double *supply, char **nnames, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **anames) = NULL;
int (*__symbolic_CPXNETcopybase) (CPXCENVptr env, CPXNETptr net, const int *astat, const int *nstat) = NULL;
int (*__symbolic_CPXNETaddnodes) (CPXCENVptr env, CPXNETptr net, int nnodes, const double *supply, char **name) = NULL;
int (*__symbolic_CPXNETaddarcs) (CPXCENVptr env, CPXNETptr net, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **anames) = NULL;
int (*__symbolic_CPXNETdelnodes) (CPXCENVptr env, CPXNETptr net, int begin, int end) = NULL;
int (*__symbolic_CPXNETdelarcs) (CPXCENVptr env, CPXNETptr net, int begin, int end) = NULL;
int (*__symbolic_CPXNETdelset) (CPXCENVptr env, CPXNETptr net, int *whichnodes, int *whicharcs) = NULL;
int (*__symbolic_CPXNETprimopt) (CPXCENVptr env, CPXNETptr net) = NULL;
int (*__symbolic_CPXNETgetstat) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetobjval) (CPXCENVptr env, CPXCNETptr net, double *objval_p) = NULL;
int (*__symbolic_CPXNETgetx) (CPXCENVptr env, CPXCNETptr net, double *x, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetpi) (CPXCENVptr env, CPXCNETptr net, double *pi, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetslack) (CPXCENVptr env, CPXCNETptr net, double *slack, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetdj) (CPXCENVptr env, CPXCNETptr net, double *dj, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetitcnt) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetphase1cnt) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetbase) (CPXCENVptr env, CPXCNETptr net, int *astat, int *nstat) = NULL;
int (*__symbolic_CPXNETsolution) (CPXCENVptr env, CPXCNETptr net, int *netstat_p, double *objval_p, double *x, double *pi, double *slack, double *dj) = NULL;
int (*__symbolic_CPXNETsolninfo) (CPXCENVptr env, CPXCNETptr net, int *pfeasind_p, int *dfeasind_p) = NULL;
int (*__symbolic_CPXNETchgname) (CPXCENVptr env, CPXNETptr net, int key, int vindex, const char *name_str) = NULL;
int (*__symbolic_CPXNETchgarcname) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, char **newname) = NULL;
int (*__symbolic_CPXNETchgnodename) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, char **newname) = NULL;
int (*__symbolic_CPXNETchgobjsen) (CPXCENVptr env, CPXNETptr net, int maxormin) = NULL;
int (*__symbolic_CPXNETchgbds) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const char *lu, const double *bd) = NULL;
int (*__symbolic_CPXNETchgarcnodes) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const int *fromnode, const int *tonode) = NULL;
int (*__symbolic_CPXNETchgobj) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const double *obj) = NULL;
int (*__symbolic_CPXNETchgsupply) (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const double *supply) = NULL;
int (*__symbolic_CPXNETgetobjsen) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetsupply) (CPXCENVptr env, CPXCNETptr net, double *supply, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetprobname) (CPXCENVptr env, CPXCNETptr net, char *buf_str, int bufspace, int *surplus_p) = NULL;
int (*__symbolic_CPXNETgetnodename) (CPXCENVptr env, CPXCNETptr net, char **nnames, char *namestore, int namespc, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetarcname) (CPXCENVptr env, CPXCNETptr net, char **nnames, char *namestore, int namespc, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetlb) (CPXCENVptr env, CPXCNETptr net, double *low, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetub) (CPXCENVptr env, CPXCNETptr net, double *up, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetobj) (CPXCENVptr env, CPXCNETptr net, double *obj, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetarcnodes) (CPXCENVptr env, CPXCNETptr net, int *fromnode, int *tonode, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetnodearcs) (CPXCENVptr env, CPXCNETptr net, int *arccnt_p, int *arcbeg, int *arc, int arcspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXNETgetnumnodes) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetnumarcs) (CPXCENVptr env, CPXCNETptr net) = NULL;
int (*__symbolic_CPXNETgetnodeindex) (CPXCENVptr env, CPXCNETptr net, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXNETgetarcindex) (CPXCENVptr env, CPXCNETptr net, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXNETreadcopyprob) (CPXCENVptr env, CPXNETptr net, const char *filename_str) = NULL;
int (*__symbolic_CPXNETreadcopybase) (CPXCENVptr env, CPXNETptr net, const char *filename_str) = NULL;
int (*__symbolic_CPXNETwriteprob) (CPXCENVptr env, CPXCNETptr net, const char *filename_str, const char *format_str) = NULL;
int (*__symbolic_CPXNETbasewrite) (CPXCENVptr env, CPXCNETptr net, const char *filename_str) = NULL;
int (*__symbolic_CPXNETcheckcopynet) (CPXCENVptr env, CPXNETptr net, int objsen, int nnodes, const double *supply, char **nnames, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **aname) = NULL;
int (*__symbolic_CPXcopyquad) (CPXCENVptr env, CPXLPptr lp, const int *qmatbeg, const int *qmatcnt, const int *qmatind, const double *qmatval) = NULL;
int (*__symbolic_CPXcopyqpsep) (CPXCENVptr env, CPXLPptr lp, const double *qsepvec) = NULL;
int (*__symbolic_CPXchgqpcoef) (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue) = NULL;
int (*__symbolic_CPXgetnumqpnz) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetnumquad) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetqpcoef) (CPXCENVptr env, CPXCLPptr lp, int rownum, int colnum, double *coef_p) = NULL;
int (*__symbolic_CPXgetquad) (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *qmatbeg, int *qmatind, double *qmatval, int qmatspace, int *surplus_p, int begin, int end) = NULL;
int (*__symbolic_CPXqpindefcertificate) (CPXCENVptr env, CPXCLPptr lp, double *x) = NULL;
int (*__symbolic_CPXcheckcopyqpsep) (CPXCENVptr env, CPXCLPptr lp, const double *qsepvec) = NULL;
int (*__symbolic_CPXcheckcopyquad) (CPXCENVptr env, CPXCLPptr lp, const int *qmatbeg, const int *qmatcnt, const int *qmatind, const double *qmatval) = NULL;
int (*__symbolic_CPXqpopt) (CPXCENVptr env, CPXLPptr lp) = NULL;
int (*__symbolic_CPXaddqconstr) (CPXCENVptr env, CPXLPptr lp, int linnzcnt, int quadnzcnt, double rhs, int sense, const int *linind, const double *linval, const int *quadrow, const int *quadcol, const double *quadval, const char *lname_str) = NULL;
int (*__symbolic_CPXdelqconstrs) (CPXCENVptr env, CPXLPptr lp, int begin, int end) = NULL;
int (*__symbolic_CPXgetnumqconstrs) (CPXCENVptr env, CPXCLPptr lp) = NULL;
int (*__symbolic_CPXgetqconstrindex) (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p) = NULL;
int (*__symbolic_CPXgetqconstr) (CPXCENVptr env, CPXCLPptr lp, int *linnzcnt_p, int *quadnzcnt_p, double *rhs_p, char *sense_p, int *linind, double *linval, int linspace, int *linsurplus_p, int *quadrow, int *quadcol, double *quadval, int quadspace, int *quadsurplus_p, int which) = NULL;
int (*__symbolic_CPXgetqconstrname) (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which) = NULL;
int (*__symbolic_CPXgetqconstrslack) (CPXCENVptr env, CPXCLPptr lp, double *qcslack, int begin, int end) = NULL;
int (*__symbolic_CPXqconstrslackfromx) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *qcslack) = NULL;
int (*__symbolic_CPXgetqconstrinfeas) (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end) = NULL;
int (*__symbolic_CPXgetxqxax) (CPXCENVptr env, CPXCLPptr lp, double *xqxax, int begin, int end) = NULL;
int (*__symbolic_CPXEchgqcname) (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname) = NULL;

/* hijacked functions */

CPXLPptr CPXcreateprob (CPXCENVptr env, int *status_p, const char *probname_str){
    if (!__symbolic_CPXcreateprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcreateprob", (gpointer *) &__symbolic_CPXcreateprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcreateprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcreateprob.\n");
        }
    }
    return __symbolic_CPXcreateprob(env, status_p, probname_str);
}
CPXLPptr CPXcloneprob (CPXCENVptr env, CPXCLPptr lp, int *status_p){
    if (!__symbolic_CPXcloneprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcloneprob", (gpointer *) &__symbolic_CPXcloneprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcloneprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcloneprob.\n");
        }
    }
    return __symbolic_CPXcloneprob(env, lp, status_p);
}
int CPXcopylpwnames (CPXCENVptr env, CPXLPptr lp, int numcols, int numrows, int objsense, const double *objective, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval, char **colname, char **rowname){
    if (!__symbolic_CPXcopylpwnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopylpwnames", (gpointer *) &__symbolic_CPXcopylpwnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopylpwnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopylpwnames.\n");
        }
    }
    return __symbolic_CPXcopylpwnames(env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval, colname, rowname);
}
int CPXcopylp (CPXCENVptr env, CPXLPptr lp, int numcols, int numrows, int objsense, const double *objective, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval){
    if (!__symbolic_CPXcopylp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopylp", (gpointer *) &__symbolic_CPXcopylp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopylp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopylp.\n");
        }
    }
    return __symbolic_CPXcopylp(env, lp, numcols, numrows, objsense, objective, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval);
}
int CPXcopyobjname (CPXCENVptr env, CPXLPptr lp, const char *objname_str){
    if (!__symbolic_CPXcopyobjname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyobjname", (gpointer *) &__symbolic_CPXcopyobjname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyobjname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyobjname.\n");
        }
    }
    return __symbolic_CPXcopyobjname(env, lp, objname_str);
}
int CPXcopybase (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat){
    if (!__symbolic_CPXcopybase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopybase", (gpointer *) &__symbolic_CPXcopybase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopybase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopybase.\n");
        }
    }
    return __symbolic_CPXcopybase(env, lp, cstat, rstat);
}
int CPXcleanup (CPXCENVptr env, CPXLPptr lp, double eps){
    if (!__symbolic_CPXcleanup) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcleanup", (gpointer *) &__symbolic_CPXcleanup)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcleanup could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcleanup.\n");
        }
    }
    return __symbolic_CPXcleanup(env, lp, eps);
}
int CPXcopystart (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat, const double *cprim, const double *rprim, const double *cdual, const double *rdual){
    if (!__symbolic_CPXcopystart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopystart", (gpointer *) &__symbolic_CPXcopystart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopystart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopystart.\n");
        }
    }
    return __symbolic_CPXcopystart(env, lp, cstat, rstat, cprim, rprim, cdual, rdual);
}
int CPXfreeprob (CPXCENVptr env, CPXLPptr * lp_p){
    if (!__symbolic_CPXfreeprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfreeprob", (gpointer *) &__symbolic_CPXfreeprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfreeprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfreeprob.\n");
        }
    }
    return __symbolic_CPXfreeprob(env, lp_p);
}
int CPXcopynettolp (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net){
    if (!__symbolic_CPXcopynettolp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopynettolp", (gpointer *) &__symbolic_CPXcopynettolp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopynettolp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopynettolp.\n");
        }
    }
    return __symbolic_CPXcopynettolp(env, lp, net);
}
int CPXNETextract (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp, int *colmap, int *rowmap){
    if (!__symbolic_CPXNETextract) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETextract", (gpointer *) &__symbolic_CPXNETextract)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETextract could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETextract.\n");
        }
    }
    return __symbolic_CPXNETextract(env, net, lp, colmap, rowmap);
}
int CPXlpopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXlpopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXlpopt", (gpointer *) &__symbolic_CPXlpopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXlpopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXlpopt.\n");
        }
    }
    return __symbolic_CPXlpopt(env, lp);
}
int CPXconcurrentlpopt (CPXCENVptr env, CPXCENVptr * childenv, CPXLPptr lp, int P){
    if (!__symbolic_CPXconcurrentlpopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXconcurrentlpopt", (gpointer *) &__symbolic_CPXconcurrentlpopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXconcurrentlpopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXconcurrentlpopt.\n");
        }
    }
    return __symbolic_CPXconcurrentlpopt(env, childenv, lp, P);
}
int CPXconcurrentmipopt (CPXCENVptr env, CPXCENVptr * childenv, CPXLPptr lp, int P){
    if (!__symbolic_CPXconcurrentmipopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXconcurrentmipopt", (gpointer *) &__symbolic_CPXconcurrentmipopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXconcurrentmipopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXconcurrentmipopt.\n");
        }
    }
    return __symbolic_CPXconcurrentmipopt(env, childenv, lp, P);
}
int CPXprimopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXprimopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXprimopt", (gpointer *) &__symbolic_CPXprimopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXprimopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXprimopt.\n");
        }
    }
    return __symbolic_CPXprimopt(env, lp);
}
int CPXdualopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXdualopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdualopt", (gpointer *) &__symbolic_CPXdualopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdualopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdualopt.\n");
        }
    }
    return __symbolic_CPXdualopt(env, lp);
}
int CPXhybnetopt (CPXCENVptr env, CPXLPptr lp, int method){
    if (!__symbolic_CPXhybnetopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXhybnetopt", (gpointer *) &__symbolic_CPXhybnetopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXhybnetopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXhybnetopt.\n");
        }
    }
    return __symbolic_CPXhybnetopt(env, lp, method);
}
int CPXsiftopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXsiftopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsiftopt", (gpointer *) &__symbolic_CPXsiftopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsiftopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsiftopt.\n");
        }
    }
    return __symbolic_CPXsiftopt(env, lp);
}
int CPXpratio (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio, int *downleave, int *upleave, int *downleavestatus, int *upleavestatus, int *downstatus, int *upstatus){
    if (!__symbolic_CPXpratio) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpratio", (gpointer *) &__symbolic_CPXpratio)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpratio could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpratio.\n");
        }
    }
    return __symbolic_CPXpratio(env, lp, indices, cnt, downratio, upratio, downleave, upleave, downleavestatus, upleavestatus, downstatus, upstatus);
}
int CPXdratio (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio, int *downenter, int *upenter, int *downstatus, int *upstatus){
    if (!__symbolic_CPXdratio) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdratio", (gpointer *) &__symbolic_CPXdratio)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdratio could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdratio.\n");
        }
    }
    return __symbolic_CPXdratio(env, lp, indices, cnt, downratio, upratio, downenter, upenter, downstatus, upstatus);
}
int CPXpivot (CPXCENVptr env, CPXLPptr lp, int jenter, int jleave, int leavestat){
    if (!__symbolic_CPXpivot) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpivot", (gpointer *) &__symbolic_CPXpivot)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpivot could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpivot.\n");
        }
    }
    return __symbolic_CPXpivot(env, lp, jenter, jleave, leavestat);
}
int CPXsetphase2 (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXsetphase2) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetphase2", (gpointer *) &__symbolic_CPXsetphase2)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetphase2 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetphase2.\n");
        }
    }
    return __symbolic_CPXsetphase2(env, lp);
}
int CPXcheckpfeas (CPXCENVptr env, CPXLPptr lp, int *infeas_p){
    if (!__symbolic_CPXcheckpfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckpfeas", (gpointer *) &__symbolic_CPXcheckpfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckpfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckpfeas.\n");
        }
    }
    return __symbolic_CPXcheckpfeas(env, lp, infeas_p);
}
int CPXcheckdfeas (CPXCENVptr env, CPXLPptr lp, int *infeas_p){
    if (!__symbolic_CPXcheckdfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckdfeas", (gpointer *) &__symbolic_CPXcheckdfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckdfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckdfeas.\n");
        }
    }
    return __symbolic_CPXcheckdfeas(env, lp, infeas_p);
}
int CPXchecksoln (CPXCENVptr env, CPXLPptr lp, int *lpstatus_p){
    if (!__symbolic_CPXchecksoln) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchecksoln", (gpointer *) &__symbolic_CPXchecksoln)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchecksoln could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchecksoln.\n");
        }
    }
    return __symbolic_CPXchecksoln(env, lp, lpstatus_p);
}
int CPXsolution (CPXCENVptr env, CPXCLPptr lp, int *lpstat_p, double *objval_p, double *x, double *pi, double *slack, double *dj){
    if (!__symbolic_CPXsolution) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsolution", (gpointer *) &__symbolic_CPXsolution)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsolution could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsolution.\n");
        }
    }
    return __symbolic_CPXsolution(env, lp, lpstat_p, objval_p, x, pi, slack, dj);
}
int CPXsolninfo (CPXCENVptr env, CPXCLPptr lp, int *solnmethod_p, int *solntype_p, int *pfeasind_p, int *dfeasind_p){
    if (!__symbolic_CPXsolninfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsolninfo", (gpointer *) &__symbolic_CPXsolninfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsolninfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsolninfo.\n");
        }
    }
    return __symbolic_CPXsolninfo(env, lp, solnmethod_p, solntype_p, pfeasind_p, dfeasind_p);
}
int CPXgetstat (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetstat) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetstat", (gpointer *) &__symbolic_CPXgetstat)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetstat could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetstat.\n");
        }
    }
    return __symbolic_CPXgetstat(env, lp);
}
CPXCHARptr CPXgetstatstring (CPXCENVptr env, int statind, char *buffer_str){
    if (!__symbolic_CPXgetstatstring) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetstatstring", (gpointer *) &__symbolic_CPXgetstatstring)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetstatstring could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetstatstring.\n");
        }
    }
    return __symbolic_CPXgetstatstring(env, statind, buffer_str);
}
int CPXgetmethod (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetmethod) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmethod", (gpointer *) &__symbolic_CPXgetmethod)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmethod could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmethod.\n");
        }
    }
    return __symbolic_CPXgetmethod(env, lp);
}
int CPXgetobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p){
    if (!__symbolic_CPXgetobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetobjval", (gpointer *) &__symbolic_CPXgetobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetobjval.\n");
        }
    }
    return __symbolic_CPXgetobjval(env, lp, objval_p);
}
int CPXgetx (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end){
    if (!__symbolic_CPXgetx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetx", (gpointer *) &__symbolic_CPXgetx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetx.\n");
        }
    }
    return __symbolic_CPXgetx(env, lp, x, begin, end);
}
int CPXgetax (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end){
    if (!__symbolic_CPXgetax) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetax", (gpointer *) &__symbolic_CPXgetax)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetax could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetax.\n");
        }
    }
    return __symbolic_CPXgetax(env, lp, x, begin, end);
}
int CPXgetpi (CPXCENVptr env, CPXCLPptr lp, double *pi, int begin, int end){
    if (!__symbolic_CPXgetpi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetpi", (gpointer *) &__symbolic_CPXgetpi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetpi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetpi.\n");
        }
    }
    return __symbolic_CPXgetpi(env, lp, pi, begin, end);
}
int CPXgetslack (CPXCENVptr env, CPXCLPptr lp, double *slack, int begin, int end){
    if (!__symbolic_CPXgetslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetslack", (gpointer *) &__symbolic_CPXgetslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetslack.\n");
        }
    }
    return __symbolic_CPXgetslack(env, lp, slack, begin, end);
}
int CPXgetrowinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end){
    if (!__symbolic_CPXgetrowinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrowinfeas", (gpointer *) &__symbolic_CPXgetrowinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrowinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrowinfeas.\n");
        }
    }
    return __symbolic_CPXgetrowinfeas(env, lp, x, infeasout, begin, end);
}
int CPXgetcolinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end){
    if (!__symbolic_CPXgetcolinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcolinfeas", (gpointer *) &__symbolic_CPXgetcolinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcolinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcolinfeas.\n");
        }
    }
    return __symbolic_CPXgetcolinfeas(env, lp, x, infeasout, begin, end);
}
int CPXgetdj (CPXCENVptr env, CPXCLPptr lp, double *dj, int begin, int end){
    if (!__symbolic_CPXgetdj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdj", (gpointer *) &__symbolic_CPXgetdj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdj.\n");
        }
    }
    return __symbolic_CPXgetdj(env, lp, dj, begin, end);
}
int CPXgetgrad (CPXCENVptr env, CPXCLPptr lp, int j, int *head, double *y){
    if (!__symbolic_CPXgetgrad) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetgrad", (gpointer *) &__symbolic_CPXgetgrad)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetgrad could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetgrad.\n");
        }
    }
    return __symbolic_CPXgetgrad(env, lp, j, head, y);
}
int CPXgetijdiv (CPXCENVptr env, CPXCLPptr lp, int *idiv_p, int *jdiv_p){
    if (!__symbolic_CPXgetijdiv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetijdiv", (gpointer *) &__symbolic_CPXgetijdiv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetijdiv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetijdiv.\n");
        }
    }
    return __symbolic_CPXgetijdiv(env, lp, idiv_p, jdiv_p);
}
int CPXgetbase (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat){
    if (!__symbolic_CPXgetbase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbase", (gpointer *) &__symbolic_CPXgetbase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbase.\n");
        }
    }
    return __symbolic_CPXgetbase(env, lp, cstat, rstat);
}
int CPXgetitcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetitcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetitcnt", (gpointer *) &__symbolic_CPXgetitcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetitcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetitcnt.\n");
        }
    }
    return __symbolic_CPXgetitcnt(env, lp);
}
int CPXgetphase1cnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetphase1cnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetphase1cnt", (gpointer *) &__symbolic_CPXgetphase1cnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetphase1cnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetphase1cnt.\n");
        }
    }
    return __symbolic_CPXgetphase1cnt(env, lp);
}
int CPXgetsiftitcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsiftitcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsiftitcnt", (gpointer *) &__symbolic_CPXgetsiftitcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsiftitcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsiftitcnt.\n");
        }
    }
    return __symbolic_CPXgetsiftitcnt(env, lp);
}
int CPXgetsiftphase1cnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsiftphase1cnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsiftphase1cnt", (gpointer *) &__symbolic_CPXgetsiftphase1cnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsiftphase1cnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsiftphase1cnt.\n");
        }
    }
    return __symbolic_CPXgetsiftphase1cnt(env, lp);
}
int CPXgetbaritcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetbaritcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbaritcnt", (gpointer *) &__symbolic_CPXgetbaritcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbaritcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbaritcnt.\n");
        }
    }
    return __symbolic_CPXgetbaritcnt(env, lp);
}
int CPXgetcrossppushcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetcrossppushcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcrossppushcnt", (gpointer *) &__symbolic_CPXgetcrossppushcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcrossppushcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcrossppushcnt.\n");
        }
    }
    return __symbolic_CPXgetcrossppushcnt(env, lp);
}
int CPXgetcrosspexchcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetcrosspexchcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcrosspexchcnt", (gpointer *) &__symbolic_CPXgetcrosspexchcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcrosspexchcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcrosspexchcnt.\n");
        }
    }
    return __symbolic_CPXgetcrosspexchcnt(env, lp);
}
int CPXgetcrossdpushcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetcrossdpushcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcrossdpushcnt", (gpointer *) &__symbolic_CPXgetcrossdpushcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcrossdpushcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcrossdpushcnt.\n");
        }
    }
    return __symbolic_CPXgetcrossdpushcnt(env, lp);
}
int CPXgetcrossdexchcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetcrossdexchcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcrossdexchcnt", (gpointer *) &__symbolic_CPXgetcrossdexchcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcrossdexchcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcrossdexchcnt.\n");
        }
    }
    return __symbolic_CPXgetcrossdexchcnt(env, lp);
}
int CPXgetpsbcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetpsbcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetpsbcnt", (gpointer *) &__symbolic_CPXgetpsbcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetpsbcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetpsbcnt.\n");
        }
    }
    return __symbolic_CPXgetpsbcnt(env, lp);
}
int CPXgetdsbcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetdsbcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdsbcnt", (gpointer *) &__symbolic_CPXgetdsbcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdsbcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdsbcnt.\n");
        }
    }
    return __symbolic_CPXgetdsbcnt(env, lp);
}
int CPXgetdblquality (CPXCENVptr env, CPXCLPptr lp, double *quality_p, int what){
    if (!__symbolic_CPXgetdblquality) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdblquality", (gpointer *) &__symbolic_CPXgetdblquality)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdblquality could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdblquality.\n");
        }
    }
    return __symbolic_CPXgetdblquality(env, lp, quality_p, what);
}
int CPXgetsolnpooldblquality (CPXCENVptr env, CPXCLPptr lp, int soln, double *quality_p, int what){
    if (!__symbolic_CPXgetsolnpooldblquality) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpooldblquality", (gpointer *) &__symbolic_CPXgetsolnpooldblquality)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpooldblquality could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpooldblquality.\n");
        }
    }
    return __symbolic_CPXgetsolnpooldblquality(env, lp, soln, quality_p, what);
}
int CPXgetintquality (CPXCENVptr env, CPXCLPptr lp, int *quality_p, int what){
    if (!__symbolic_CPXgetintquality) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetintquality", (gpointer *) &__symbolic_CPXgetintquality)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetintquality could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetintquality.\n");
        }
    }
    return __symbolic_CPXgetintquality(env, lp, quality_p, what);
}
int CPXgetsolnpoolintquality (CPXCENVptr env, CPXCLPptr lp, int soln, int *quality_p, int what){
    if (!__symbolic_CPXgetsolnpoolintquality) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolintquality", (gpointer *) &__symbolic_CPXgetsolnpoolintquality)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolintquality could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolintquality.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolintquality(env, lp, soln, quality_p, what);
}
int CPXrhssa (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lower, double *upper){
    if (!__symbolic_CPXrhssa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrhssa", (gpointer *) &__symbolic_CPXrhssa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrhssa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrhssa.\n");
        }
    }
    return __symbolic_CPXrhssa(env, lp, begin, end, lower, upper);
}
int CPXboundsa (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lblower, double *lbupper, double *ublower, double *ubupper){
    if (!__symbolic_CPXboundsa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXboundsa", (gpointer *) &__symbolic_CPXboundsa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXboundsa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXboundsa.\n");
        }
    }
    return __symbolic_CPXboundsa(env, lp, begin, end, lblower, lbupper, ublower, ubupper);
}
int CPXobjsa (CPXCENVptr env, CPXCLPptr lp, int begin, int end, double *lower, double *upper){
    if (!__symbolic_CPXobjsa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXobjsa", (gpointer *) &__symbolic_CPXobjsa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXobjsa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXobjsa.\n");
        }
    }
    return __symbolic_CPXobjsa(env, lp, begin, end, lower, upper);
}
int CPXErangesa (CPXENVptr env, CPXLPptr lp, int begin, int end, double *lblower, double *lbupper, double *ublower, double *ubupper){
    if (!__symbolic_CPXErangesa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXErangesa", (gpointer *) &__symbolic_CPXErangesa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXErangesa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXErangesa.\n");
        }
    }
    return __symbolic_CPXErangesa(env, lp, begin, end, lblower, lbupper, ublower, ubupper);
}
int CPXrefineconflict (CPXCENVptr env, CPXLPptr lp, int *confnumrows_p, int *confnumcols_p){
    if (!__symbolic_CPXrefineconflict) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrefineconflict", (gpointer *) &__symbolic_CPXrefineconflict)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrefineconflict could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrefineconflict.\n");
        }
    }
    return __symbolic_CPXrefineconflict(env, lp, confnumrows_p, confnumcols_p);
}
int CPXgetconflict (CPXCENVptr env, CPXCLPptr lp, int *confstat_p, int *rowind, int *rowbdstat, int *confnumrows_p, int *colind, int *colbdstat, int *confnumcols_p){
    if (!__symbolic_CPXgetconflict) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetconflict", (gpointer *) &__symbolic_CPXgetconflict)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetconflict could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetconflict.\n");
        }
    }
    return __symbolic_CPXgetconflict(env, lp, confstat_p, rowind, rowbdstat, confnumrows_p, colind, colbdstat, confnumcols_p);
}
int CPXrefineconflictext (CPXCENVptr env, CPXLPptr lp, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype){
    if (!__symbolic_CPXrefineconflictext) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrefineconflictext", (gpointer *) &__symbolic_CPXrefineconflictext)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrefineconflictext could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrefineconflictext.\n");
        }
    }
    return __symbolic_CPXrefineconflictext(env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}
int CPXgetconflictext (CPXCENVptr env, CPXCLPptr lp, int *grpstat, int beg, int end){
    if (!__symbolic_CPXgetconflictext) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetconflictext", (gpointer *) &__symbolic_CPXgetconflictext)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetconflictext could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetconflictext.\n");
        }
    }
    return __symbolic_CPXgetconflictext(env, lp, grpstat, beg, end);
}
int CPXclpwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXclpwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXclpwrite", (gpointer *) &__symbolic_CPXclpwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXclpwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXclpwrite.\n");
        }
    }
    return __symbolic_CPXclpwrite(env, lp, filename_str);
}
int CPXrobustopt (CPXCENVptr env, CPXLPptr lp, CPXLPptr lblp, CPXLPptr ublp, double objchg, const double *maxchg){
    if (!__symbolic_CPXrobustopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrobustopt", (gpointer *) &__symbolic_CPXrobustopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrobustopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrobustopt.\n");
        }
    }
    return __symbolic_CPXrobustopt(env, lp, lblp, ublp, objchg, maxchg);
}
int CPXfeasopt (CPXCENVptr env, CPXLPptr lp, const double *rhs, const double *rng, const double *lb, const double *ub){
    if (!__symbolic_CPXfeasopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfeasopt", (gpointer *) &__symbolic_CPXfeasopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfeasopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfeasopt.\n");
        }
    }
    return __symbolic_CPXfeasopt(env, lp, rhs, rng, lb, ub);
}
int CPXEfeasopt (CPXCENVptr env, CPXLPptr lp, const double *rhs, const double *rng, const double *lb, const double *ub, const double *qrhs){
    if (!__symbolic_CPXEfeasopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEfeasopt", (gpointer *) &__symbolic_CPXEfeasopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEfeasopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEfeasopt.\n");
        }
    }
    return __symbolic_CPXEfeasopt(env, lp, rhs, rng, lb, ub, qrhs);
}
int CPXfeasoptext (CPXCENVptr env, CPXLPptr lp, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype){
    if (!__symbolic_CPXfeasoptext) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfeasoptext", (gpointer *) &__symbolic_CPXfeasoptext)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfeasoptext could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfeasoptext.\n");
        }
    }
    return __symbolic_CPXfeasoptext(env, lp, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}
int CPXnewrows (CPXCENVptr env, CPXLPptr lp, int rcnt, const double *rhs, const char *sense, const double *rngval, char **rowname){
    if (!__symbolic_CPXnewrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXnewrows", (gpointer *) &__symbolic_CPXnewrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXnewrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXnewrows.\n");
        }
    }
    return __symbolic_CPXnewrows(env, lp, rcnt, rhs, sense, rngval, rowname);
}
int CPXaddrows (CPXCENVptr env, CPXLPptr lp, int ccnt, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **colname, char **rowname){
    if (!__symbolic_CPXaddrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddrows", (gpointer *) &__symbolic_CPXaddrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddrows.\n");
        }
    }
    return __symbolic_CPXaddrows(env, lp, ccnt, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, colname, rowname);
}
int CPXnewcols (CPXCENVptr env, CPXLPptr lp, int ccnt, const double *obj, const double *lb, const double *ub, const char *xctype, char **colname){
    if (!__symbolic_CPXnewcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXnewcols", (gpointer *) &__symbolic_CPXnewcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXnewcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXnewcols.\n");
        }
    }
    return __symbolic_CPXnewcols(env, lp, ccnt, obj, lb, ub, xctype, colname);
}
int CPXaddcols (CPXCENVptr env, CPXLPptr lp, int ccnt, int nzcnt, const double *obj, const int *cmatbeg, const int *cmatind, const double *cmatval, const double *lb, const double *ub, char **colname){
    if (!__symbolic_CPXaddcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddcols", (gpointer *) &__symbolic_CPXaddcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddcols.\n");
        }
    }
    return __symbolic_CPXaddcols(env, lp, ccnt, nzcnt, obj, cmatbeg, cmatind, cmatval, lb, ub, colname);
}
int CPXdelrows (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelrows", (gpointer *) &__symbolic_CPXdelrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelrows.\n");
        }
    }
    return __symbolic_CPXdelrows(env, lp, begin, end);
}
int CPXdelsetrows (CPXCENVptr env, CPXLPptr lp, int *delstat){
    if (!__symbolic_CPXdelsetrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetrows", (gpointer *) &__symbolic_CPXdelsetrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetrows.\n");
        }
    }
    return __symbolic_CPXdelsetrows(env, lp, delstat);
}
int CPXdelcols (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelcols", (gpointer *) &__symbolic_CPXdelcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelcols.\n");
        }
    }
    return __symbolic_CPXdelcols(env, lp, begin, end);
}
int CPXdelsetcols (CPXCENVptr env, CPXLPptr lp, int *delstat){
    if (!__symbolic_CPXdelsetcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetcols", (gpointer *) &__symbolic_CPXdelsetcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetcols.\n");
        }
    }
    return __symbolic_CPXdelsetcols(env, lp, delstat);
}
int CPXchgname (CPXCENVptr env, CPXLPptr lp, int key, int ij, const char *newname_str){
    if (!__symbolic_CPXchgname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgname", (gpointer *) &__symbolic_CPXchgname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgname.\n");
        }
    }
    return __symbolic_CPXchgname(env, lp, key, ij, newname_str);
}
int CPXchgrowname (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXchgrowname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgrowname", (gpointer *) &__symbolic_CPXchgrowname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgrowname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgrowname.\n");
        }
    }
    return __symbolic_CPXchgrowname(env, lp, cnt, indices, newname);
}
int CPXchgcolname (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXchgcolname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgcolname", (gpointer *) &__symbolic_CPXchgcolname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgcolname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgcolname.\n");
        }
    }
    return __symbolic_CPXchgcolname(env, lp, cnt, indices, newname);
}
int CPXdelnames (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXdelnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelnames", (gpointer *) &__symbolic_CPXdelnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelnames.\n");
        }
    }
    return __symbolic_CPXdelnames(env, lp);
}
int CPXchgprobname (CPXCENVptr env, CPXLPptr lp, const char *probname_str){
    if (!__symbolic_CPXchgprobname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgprobname", (gpointer *) &__symbolic_CPXchgprobname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgprobname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgprobname.\n");
        }
    }
    return __symbolic_CPXchgprobname(env, lp, probname_str);
}
int CPXchgcoef (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue){
    if (!__symbolic_CPXchgcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgcoef", (gpointer *) &__symbolic_CPXchgcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgcoef.\n");
        }
    }
    return __symbolic_CPXchgcoef(env, lp, i, j, newvalue);
}
int CPXchgcoeflist (CPXCENVptr env, CPXLPptr lp, int numcoefs, const int *rowlist, const int *collist, const double *vallist){
    if (!__symbolic_CPXchgcoeflist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgcoeflist", (gpointer *) &__symbolic_CPXchgcoeflist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgcoeflist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgcoeflist.\n");
        }
    }
    return __symbolic_CPXchgcoeflist(env, lp, numcoefs, rowlist, collist, vallist);
}
int CPXchgbds (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *lu, const double *bd){
    if (!__symbolic_CPXchgbds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgbds", (gpointer *) &__symbolic_CPXchgbds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgbds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgbds.\n");
        }
    }
    return __symbolic_CPXchgbds(env, lp, cnt, indices, lu, bd);
}
int CPXchgobj (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXchgobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgobj", (gpointer *) &__symbolic_CPXchgobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgobj.\n");
        }
    }
    return __symbolic_CPXchgobj(env, lp, cnt, indices, values);
}
int CPXchgrhs (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXchgrhs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgrhs", (gpointer *) &__symbolic_CPXchgrhs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgrhs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgrhs.\n");
        }
    }
    return __symbolic_CPXchgrhs(env, lp, cnt, indices, values);
}
int CPXchgrngval (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXchgrngval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgrngval", (gpointer *) &__symbolic_CPXchgrngval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgrngval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgrngval.\n");
        }
    }
    return __symbolic_CPXchgrngval(env, lp, cnt, indices, values);
}
int CPXchgsense (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *sense){
    if (!__symbolic_CPXchgsense) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgsense", (gpointer *) &__symbolic_CPXchgsense)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgsense could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgsense.\n");
        }
    }
    return __symbolic_CPXchgsense(env, lp, cnt, indices, sense);
}
void CPXchgobjsen (CPXCENVptr env, CPXLPptr lp, int maxormin){
    if (!__symbolic_CPXchgobjsen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgobjsen", (gpointer *) &__symbolic_CPXchgobjsen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgobjsen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgobjsen.\n");
        }
    }
    return __symbolic_CPXchgobjsen(env, lp, maxormin);
}
int CPXchgprobtype (CPXCENVptr env, CPXLPptr lp, int type){
    if (!__symbolic_CPXchgprobtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgprobtype", (gpointer *) &__symbolic_CPXchgprobtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgprobtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgprobtype.\n");
        }
    }
    return __symbolic_CPXchgprobtype(env, lp, type);
}
int CPXchgprobtypesolnpool (CPXCENVptr env, CPXLPptr lp, int type, int soln){
    if (!__symbolic_CPXchgprobtypesolnpool) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgprobtypesolnpool", (gpointer *) &__symbolic_CPXchgprobtypesolnpool)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgprobtypesolnpool could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgprobtypesolnpool.\n");
        }
    }
    return __symbolic_CPXchgprobtypesolnpool(env, lp, type, soln);
}
int CPXcompletelp (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXcompletelp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcompletelp", (gpointer *) &__symbolic_CPXcompletelp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcompletelp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcompletelp.\n");
        }
    }
    return __symbolic_CPXcompletelp(env, lp);
}
int CPXpreaddrows (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname){
    if (!__symbolic_CPXpreaddrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpreaddrows", (gpointer *) &__symbolic_CPXpreaddrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpreaddrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpreaddrows.\n");
        }
    }
    return __symbolic_CPXpreaddrows(env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}
int CPXprechgobj (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXprechgobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXprechgobj", (gpointer *) &__symbolic_CPXprechgobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXprechgobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXprechgobj.\n");
        }
    }
    return __symbolic_CPXprechgobj(env, lp, cnt, indices, values);
}
int CPXgetnumcols (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumcols", (gpointer *) &__symbolic_CPXgetnumcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumcols.\n");
        }
    }
    return __symbolic_CPXgetnumcols(env, lp);
}
int CPXgetnumrows (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumrows", (gpointer *) &__symbolic_CPXgetnumrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumrows.\n");
        }
    }
    return __symbolic_CPXgetnumrows(env, lp);
}
int CPXgetnumnz (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumnz) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumnz", (gpointer *) &__symbolic_CPXgetnumnz)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumnz could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumnz.\n");
        }
    }
    return __symbolic_CPXgetnumnz(env, lp);
}
int CPXgetobjsen (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetobjsen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetobjsen", (gpointer *) &__symbolic_CPXgetobjsen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetobjsen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetobjsen.\n");
        }
    }
    return __symbolic_CPXgetobjsen(env, lp);
}
int CPXgetobj (CPXCENVptr env, CPXCLPptr lp, double *obj, int begin, int end){
    if (!__symbolic_CPXgetobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetobj", (gpointer *) &__symbolic_CPXgetobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetobj.\n");
        }
    }
    return __symbolic_CPXgetobj(env, lp, obj, begin, end);
}
int CPXgetrhs (CPXCENVptr env, CPXCLPptr lp, double *rhs, int begin, int end){
    if (!__symbolic_CPXgetrhs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrhs", (gpointer *) &__symbolic_CPXgetrhs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrhs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrhs.\n");
        }
    }
    return __symbolic_CPXgetrhs(env, lp, rhs, begin, end);
}
int CPXgetsense (CPXCENVptr env, CPXCLPptr lp, char *sense, int begin, int end){
    if (!__symbolic_CPXgetsense) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsense", (gpointer *) &__symbolic_CPXgetsense)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsense could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsense.\n");
        }
    }
    return __symbolic_CPXgetsense(env, lp, sense, begin, end);
}
int CPXgetcols (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *cmatbeg, int *cmatind, double *cmatval, int cmatspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcols", (gpointer *) &__symbolic_CPXgetcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcols.\n");
        }
    }
    return __symbolic_CPXgetcols(env, lp, nzcnt_p, cmatbeg, cmatind, cmatval, cmatspace, surplus_p, begin, end);
}
int CPXgetrows (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *rmatbeg, int *rmatind, double *rmatval, int rmatspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrows", (gpointer *) &__symbolic_CPXgetrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrows.\n");
        }
    }
    return __symbolic_CPXgetrows(env, lp, nzcnt_p, rmatbeg, rmatind, rmatval, rmatspace, surplus_p, begin, end);
}
int CPXgetlb (CPXCENVptr env, CPXCLPptr lp, double *lb, int begin, int end){
    if (!__symbolic_CPXgetlb) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetlb", (gpointer *) &__symbolic_CPXgetlb)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetlb could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetlb.\n");
        }
    }
    return __symbolic_CPXgetlb(env, lp, lb, begin, end);
}
int CPXgetub (CPXCENVptr env, CPXCLPptr lp, double *ub, int begin, int end){
    if (!__symbolic_CPXgetub) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetub", (gpointer *) &__symbolic_CPXgetub)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetub could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetub.\n");
        }
    }
    return __symbolic_CPXgetub(env, lp, ub, begin, end);
}
int CPXgetrngval (CPXCENVptr env, CPXCLPptr lp, double *rngval, int begin, int end){
    if (!__symbolic_CPXgetrngval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrngval", (gpointer *) &__symbolic_CPXgetrngval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrngval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrngval.\n");
        }
    }
    return __symbolic_CPXgetrngval(env, lp, rngval, begin, end);
}
int CPXgetprobname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p){
    if (!__symbolic_CPXgetprobname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetprobname", (gpointer *) &__symbolic_CPXgetprobname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetprobname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetprobname.\n");
        }
    }
    return __symbolic_CPXgetprobname(env, lp, buf_str, bufspace, surplus_p);
}
int CPXgetobjname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p){
    if (!__symbolic_CPXgetobjname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetobjname", (gpointer *) &__symbolic_CPXgetobjname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetobjname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetobjname.\n");
        }
    }
    return __symbolic_CPXgetobjname(env, lp, buf_str, bufspace, surplus_p);
}
int CPXgetcolname (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetcolname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcolname", (gpointer *) &__symbolic_CPXgetcolname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcolname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcolname.\n");
        }
    }
    return __symbolic_CPXgetcolname(env, lp, name, namestore, storespace, surplus_p, begin, end);
}
int CPXgetrowname (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetrowname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrowname", (gpointer *) &__symbolic_CPXgetrowname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrowname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrowname.\n");
        }
    }
    return __symbolic_CPXgetrowname(env, lp, name, namestore, storespace, surplus_p, begin, end);
}
int CPXgetcoef (CPXCENVptr env, CPXCLPptr lp, int i, int j, double *coef_p){
    if (!__symbolic_CPXgetcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcoef", (gpointer *) &__symbolic_CPXgetcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcoef.\n");
        }
    }
    return __symbolic_CPXgetcoef(env, lp, i, j, coef_p);
}
int CPXgetrowindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetrowindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetrowindex", (gpointer *) &__symbolic_CPXgetrowindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetrowindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetrowindex.\n");
        }
    }
    return __symbolic_CPXgetrowindex(env, lp, lname_str, index_p);
}
int CPXgetcolindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetcolindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcolindex", (gpointer *) &__symbolic_CPXgetcolindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcolindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcolindex.\n");
        }
    }
    return __symbolic_CPXgetcolindex(env, lp, lname_str, index_p);
}
int CPXgetprobtype (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetprobtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetprobtype", (gpointer *) &__symbolic_CPXgetprobtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetprobtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetprobtype.\n");
        }
    }
    return __symbolic_CPXgetprobtype(env, lp);
}
int CPXreadcopyprob (CPXCENVptr env, CPXLPptr lp, const char *filename_str, const char *filetype_str){
    if (!__symbolic_CPXreadcopyprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopyprob", (gpointer *) &__symbolic_CPXreadcopyprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopyprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopyprob.\n");
        }
    }
    return __symbolic_CPXreadcopyprob(env, lp, filename_str, filetype_str);
}
int CPXreadcopybase (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopybase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopybase", (gpointer *) &__symbolic_CPXreadcopybase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopybase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopybase.\n");
        }
    }
    return __symbolic_CPXreadcopybase(env, lp, filename_str);
}
int CPXreadcopysol (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopysol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopysol", (gpointer *) &__symbolic_CPXreadcopysol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopysol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopysol.\n");
        }
    }
    return __symbolic_CPXreadcopysol(env, lp, filename_str);
}
int CPXwriteprob (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, const char *filetype_str){
    if (!__symbolic_CPXwriteprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXwriteprob", (gpointer *) &__symbolic_CPXwriteprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXwriteprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXwriteprob.\n");
        }
    }
    return __symbolic_CPXwriteprob(env, lp, filename_str, filetype_str);
}
int CPXmbasewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXmbasewrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmbasewrite", (gpointer *) &__symbolic_CPXmbasewrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmbasewrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmbasewrite.\n");
        }
    }
    return __symbolic_CPXmbasewrite(env, lp, filename_str);
}
int CPXsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXsolwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsolwrite", (gpointer *) &__symbolic_CPXsolwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsolwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsolwrite.\n");
        }
    }
    return __symbolic_CPXsolwrite(env, lp, filename_str);
}
int CPXsolwritesolnpool (CPXCENVptr env, CPXCLPptr lp, int soln, const char *filename_str){
    if (!__symbolic_CPXsolwritesolnpool) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsolwritesolnpool", (gpointer *) &__symbolic_CPXsolwritesolnpool)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsolwritesolnpool could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsolwritesolnpool.\n");
        }
    }
    return __symbolic_CPXsolwritesolnpool(env, lp, soln, filename_str);
}
int CPXsolwritesolnpoolall (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXsolwritesolnpoolall) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsolwritesolnpoolall", (gpointer *) &__symbolic_CPXsolwritesolnpoolall)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsolwritesolnpoolall could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsolwritesolnpoolall.\n");
        }
    }
    return __symbolic_CPXsolwritesolnpoolall(env, lp, filename_str);
}
int CPXembwrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXembwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXembwrite", (gpointer *) &__symbolic_CPXembwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXembwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXembwrite.\n");
        }
    }
    return __symbolic_CPXembwrite(env, lp, filename_str);
}
int CPXdperwrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double epsilon){
    if (!__symbolic_CPXdperwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdperwrite", (gpointer *) &__symbolic_CPXdperwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdperwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdperwrite.\n");
        }
    }
    return __symbolic_CPXdperwrite(env, lp, filename_str, epsilon);
}
int CPXpperwrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double epsilon){
    if (!__symbolic_CPXpperwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpperwrite", (gpointer *) &__symbolic_CPXpperwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpperwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpperwrite.\n");
        }
    }
    return __symbolic_CPXpperwrite(env, lp, filename_str, epsilon);
}
int CPXpreslvwrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str, double *objoff_p){
    if (!__symbolic_CPXpreslvwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpreslvwrite", (gpointer *) &__symbolic_CPXpreslvwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpreslvwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpreslvwrite.\n");
        }
    }
    return __symbolic_CPXpreslvwrite(env, lp, filename_str, objoff_p);
}
int CPXdualwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, double *objshift_p){
    if (!__symbolic_CPXdualwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdualwrite", (gpointer *) &__symbolic_CPXdualwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdualwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdualwrite.\n");
        }
    }
    return __symbolic_CPXdualwrite(env, lp, filename_str, objshift_p);
}
int CPXsetdefaults (CPXENVptr env){
    if (!__symbolic_CPXsetdefaults) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetdefaults", (gpointer *) &__symbolic_CPXsetdefaults)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetdefaults could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetdefaults.\n");
        }
    }
    return __symbolic_CPXsetdefaults(env);
}
int CPXsetintparam (CPXENVptr env, int whichparam, int newvalue){
    if (!__symbolic_CPXsetintparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetintparam", (gpointer *) &__symbolic_CPXsetintparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetintparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetintparam.\n");
        }
    }
    return __symbolic_CPXsetintparam(env, whichparam, newvalue);
}
int CPXsetdblparam (CPXENVptr env, int whichparam, double newvalue){
    if (!__symbolic_CPXsetdblparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetdblparam", (gpointer *) &__symbolic_CPXsetdblparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetdblparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetdblparam.\n");
        }
    }
    return __symbolic_CPXsetdblparam(env, whichparam, newvalue);
}
int CPXsetstrparam (CPXENVptr env, int whichparam, const char *newvalue_str){
    if (!__symbolic_CPXsetstrparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetstrparam", (gpointer *) &__symbolic_CPXsetstrparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetstrparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetstrparam.\n");
        }
    }
    return __symbolic_CPXsetstrparam(env, whichparam, newvalue_str);
}
int CPXgetintparam (CPXCENVptr env, int whichparam, int *value_p){
    if (!__symbolic_CPXgetintparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetintparam", (gpointer *) &__symbolic_CPXgetintparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetintparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetintparam.\n");
        }
    }
    return __symbolic_CPXgetintparam(env, whichparam, value_p);
}
int CPXgetdblparam (CPXCENVptr env, int whichparam, double *value_p){
    if (!__symbolic_CPXgetdblparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdblparam", (gpointer *) &__symbolic_CPXgetdblparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdblparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdblparam.\n");
        }
    }
    return __symbolic_CPXgetdblparam(env, whichparam, value_p);
}
int CPXgetstrparam (CPXCENVptr env, int whichparam, char *value_str){
    if (!__symbolic_CPXgetstrparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetstrparam", (gpointer *) &__symbolic_CPXgetstrparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetstrparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetstrparam.\n");
        }
    }
    return __symbolic_CPXgetstrparam(env, whichparam, value_str);
}
int CPXinfointparam (CPXCENVptr env, int whichparam, int *defvalue_p, int *minvalue_p, int *maxvalue_p){
    if (!__symbolic_CPXinfointparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXinfointparam", (gpointer *) &__symbolic_CPXinfointparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXinfointparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXinfointparam.\n");
        }
    }
    return __symbolic_CPXinfointparam(env, whichparam, defvalue_p, minvalue_p, maxvalue_p);
}
int CPXinfodblparam (CPXCENVptr env, int whichparam, double *defvalue_p, double *minvalue_p, double *maxvalue_p){
    if (!__symbolic_CPXinfodblparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXinfodblparam", (gpointer *) &__symbolic_CPXinfodblparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXinfodblparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXinfodblparam.\n");
        }
    }
    return __symbolic_CPXinfodblparam(env, whichparam, defvalue_p, minvalue_p, maxvalue_p);
}
int CPXinfostrparam (CPXCENVptr env, int whichparam, char *defvalue_str){
    if (!__symbolic_CPXinfostrparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXinfostrparam", (gpointer *) &__symbolic_CPXinfostrparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXinfostrparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXinfostrparam.\n");
        }
    }
    return __symbolic_CPXinfostrparam(env, whichparam, defvalue_str);
}
int CPXgetparamname (CPXCENVptr env, int whichparam, char *name_str){
    if (!__symbolic_CPXgetparamname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetparamname", (gpointer *) &__symbolic_CPXgetparamname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetparamname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetparamname.\n");
        }
    }
    return __symbolic_CPXgetparamname(env, whichparam, name_str);
}
int CPXgetparamnum (CPXCENVptr env, const char *name_str, int *whichparam_p){
    if (!__symbolic_CPXgetparamnum) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetparamnum", (gpointer *) &__symbolic_CPXgetparamnum)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetparamnum could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetparamnum.\n");
        }
    }
    return __symbolic_CPXgetparamnum(env, name_str, whichparam_p);
}
int CPXgetparamtype (CPXCENVptr env, int whichparam, int *paramtype){
    if (!__symbolic_CPXgetparamtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetparamtype", (gpointer *) &__symbolic_CPXgetparamtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetparamtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetparamtype.\n");
        }
    }
    return __symbolic_CPXgetparamtype(env, whichparam, paramtype);
}
int CPXreadcopyparam (CPXENVptr env, const char *filename_str){
    if (!__symbolic_CPXreadcopyparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopyparam", (gpointer *) &__symbolic_CPXreadcopyparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopyparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopyparam.\n");
        }
    }
    return __symbolic_CPXreadcopyparam(env, filename_str);
}
int CPXwriteparam (CPXCENVptr env, const char *filename_str){
    if (!__symbolic_CPXwriteparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXwriteparam", (gpointer *) &__symbolic_CPXwriteparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXwriteparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXwriteparam.\n");
        }
    }
    return __symbolic_CPXwriteparam(env, filename_str);
}
int CPXgetchgparam (CPXCENVptr env, int *cnt_p, int *paramnum, int pspace, int *surplus_p){
    if (!__symbolic_CPXgetchgparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetchgparam", (gpointer *) &__symbolic_CPXgetchgparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetchgparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetchgparam.\n");
        }
    }
    return __symbolic_CPXgetchgparam(env, cnt_p, paramnum, pspace, surplus_p);
}
int CPXtuneparam (CPXENVptr env, CPXLPptr lp, int intcnt, const int *intnum, const int *intval, int dblcnt, const int *dblnum, const double *dblval, int strcnt, const int *strnum, char **strval, int *tunestat_p){
    if (!__symbolic_CPXtuneparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXtuneparam", (gpointer *) &__symbolic_CPXtuneparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXtuneparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXtuneparam.\n");
        }
    }
    return __symbolic_CPXtuneparam(env, lp, intcnt, intnum, intval, dblcnt, dblnum, dblval, strcnt, strnum, strval, tunestat_p);
}
int CPXtuneparamprobset (CPXENVptr env, int filecnt, char **filename, char **filetype, int intcnt, const int *intind, const int *intval, int dblcnt, const int *dblind, const double *dblval, int strcnt, const int *strind, char **strval, int *tunestat_p){
    if (!__symbolic_CPXtuneparamprobset) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXtuneparamprobset", (gpointer *) &__symbolic_CPXtuneparamprobset)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXtuneparamprobset could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXtuneparamprobset.\n");
        }
    }
    return __symbolic_CPXtuneparamprobset(env, filecnt, filename, filetype, intcnt, intind, intval, dblcnt, dblind, dblval, strcnt, strind, strval, tunestat_p);
}
CPXCCHARptr CPXversion (CPXCENVptr env){
    if (!__symbolic_CPXversion) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXversion", (gpointer *) &__symbolic_CPXversion)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXversion could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXversion.\n");
        }
    }
    return __symbolic_CPXversion(env);
}
CPXENVptr CPXopenCPLEX (int *status_p){
    if (!__symbolic_CPXopenCPLEX) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXopenCPLEX", (gpointer *) &__symbolic_CPXopenCPLEX)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXopenCPLEX could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXopenCPLEX.\n");
        }
    }
    return __symbolic_CPXopenCPLEX(status_p);
}
CPXENVptr CPXopenCPLEXruntime (int *status_p, int serialnum, const char *licenvstring_str){
    if (!__symbolic_CPXopenCPLEXruntime) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXopenCPLEXruntime", (gpointer *) &__symbolic_CPXopenCPLEXruntime)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXopenCPLEXruntime could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXopenCPLEXruntime.\n");
        }
    }
    return __symbolic_CPXopenCPLEXruntime(status_p, serialnum, licenvstring_str);
}
int CPXcloseCPLEX (CPXENVptr * env_p){
    if (!__symbolic_CPXcloseCPLEX) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcloseCPLEX", (gpointer *) &__symbolic_CPXcloseCPLEX)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcloseCPLEX could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcloseCPLEX.\n");
        }
    }
    return __symbolic_CPXcloseCPLEX(env_p);
}
int CPXsetstaringsol (const char *ilm_license_str, int ilm_license_signature){
    if (!__symbolic_CPXsetstaringsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetstaringsol", (gpointer *) &__symbolic_CPXsetstaringsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetstaringsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetstaringsol.\n");
        }
    }
    return __symbolic_CPXsetstaringsol(ilm_license_str, ilm_license_signature);
}
CPXENVptr CPXparenv (CPXENVptr env, int *status_p){
    if (!__symbolic_CPXparenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXparenv", (gpointer *) &__symbolic_CPXparenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXparenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXparenv.\n");
        }
    }
    return __symbolic_CPXparenv(env, status_p);
}
int CPXfreeparenv (CPXENVptr env, CPXENVptr * child_p){
    if (!__symbolic_CPXfreeparenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfreeparenv", (gpointer *) &__symbolic_CPXfreeparenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfreeparenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfreeparenv.\n");
        }
    }
    return __symbolic_CPXfreeparenv(env, child_p);
}
int CPXcheckcopylp (CPXCENVptr env, CPXCLPptr lp, int numcols, int numrows, int objsen, const double *obj, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval){
    if (!__symbolic_CPXcheckcopylp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopylp", (gpointer *) &__symbolic_CPXcheckcopylp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopylp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopylp.\n");
        }
    }
    return __symbolic_CPXcheckcopylp(env, lp, numcols, numrows, objsen, obj, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval);
}
int CPXcheckcopylpwnames (CPXCENVptr env, CPXCLPptr lp, int numcols, int numrows, int objsen, const double *obj, const double *rhs, const char *sense, const int *matbeg, const int *matcnt, const int *matind, const double *matval, const double *lb, const double *ub, const double *rngval, char **colname, char **rowname){
    if (!__symbolic_CPXcheckcopylpwnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopylpwnames", (gpointer *) &__symbolic_CPXcheckcopylpwnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopylpwnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopylpwnames.\n");
        }
    }
    return __symbolic_CPXcheckcopylpwnames(env, lp, numcols, numrows, objsen, obj, rhs, sense, matbeg, matcnt, matind, matval, lb, ub, rngval, colname, rowname);
}
int CPXcheckaddcols (CPXCENVptr env, CPXCLPptr lp, int ccnt, int nzcnt, const double *obj, const int *cmatbeg, const int *cmatind, const double *cmatval, const double *lb, const double *ub, char **colname){
    if (!__symbolic_CPXcheckaddcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckaddcols", (gpointer *) &__symbolic_CPXcheckaddcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckaddcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckaddcols.\n");
        }
    }
    return __symbolic_CPXcheckaddcols(env, lp, ccnt, nzcnt, obj, cmatbeg, cmatind, cmatval, lb, ub, colname);
}
int CPXcheckaddrows (CPXCENVptr env, CPXCLPptr lp, int ccnt, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **colname, char **rowname){
    if (!__symbolic_CPXcheckaddrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckaddrows", (gpointer *) &__symbolic_CPXcheckaddrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckaddrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckaddrows.\n");
        }
    }
    return __symbolic_CPXcheckaddrows(env, lp, ccnt, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, colname, rowname);
}
int CPXcheckchgcoeflist (CPXCENVptr env, CPXCLPptr lp, int numcoefs, const int *rowlist, const int *collist, const double *vallist){
    if (!__symbolic_CPXcheckchgcoeflist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckchgcoeflist", (gpointer *) &__symbolic_CPXcheckchgcoeflist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckchgcoeflist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckchgcoeflist.\n");
        }
    }
    return __symbolic_CPXcheckchgcoeflist(env, lp, numcoefs, rowlist, collist, vallist);
}
int CPXcheckvals (CPXCENVptr env, CPXCLPptr lp, int cnt, const int *rowind, const int *colind, const double *values){
    if (!__symbolic_CPXcheckvals) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckvals", (gpointer *) &__symbolic_CPXcheckvals)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckvals could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckvals.\n");
        }
    }
    return __symbolic_CPXcheckvals(env, lp, cnt, rowind, colind, values);
}
int CPXgetchannels (CPXCENVptr env, CPXCHANNELptr * cpxresults_p, CPXCHANNELptr * cpxwarning_p, CPXCHANNELptr * cpxerror_p, CPXCHANNELptr * cpxlog_p){
    if (!__symbolic_CPXgetchannels) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetchannels", (gpointer *) &__symbolic_CPXgetchannels)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetchannels could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetchannels.\n");
        }
    }
    return __symbolic_CPXgetchannels(env, cpxresults_p, cpxwarning_p, cpxerror_p, cpxlog_p);
}
int CPXsetlogfile (CPXENVptr env, CPXFILEptr lfile){
    if (!__symbolic_CPXsetlogfile) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetlogfile", (gpointer *) &__symbolic_CPXsetlogfile)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetlogfile could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetlogfile.\n");
        }
    }
    return __symbolic_CPXsetlogfile(env, lfile);
}
int CPXgetlogfile (CPXCENVptr env, CPXFILEptr * logfile_p){
    if (!__symbolic_CPXgetlogfile) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetlogfile", (gpointer *) &__symbolic_CPXgetlogfile)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetlogfile could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetlogfile.\n");
        }
    }
    return __symbolic_CPXgetlogfile(env, logfile_p);
}
int CPXmsg (CPXCHANNELptr channel, const char *format, ...){
    if (!__symbolic_CPXmsg) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmsg", (gpointer *) &__symbolic_CPXmsg)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmsg could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmsg.\n");
        }
    }
    return __symbolic_CPXmsg(channel, format);
}
int CPXmsgstr (CPXCHANNELptr channel, const char *msg_str){
    if (!__symbolic_CPXmsgstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmsgstr", (gpointer *) &__symbolic_CPXmsgstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmsgstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmsgstr.\n");
        }
    }
    return __symbolic_CPXmsgstr(channel, msg_str);
}
void CPXflushchannel (CPXCENVptr env, CPXCHANNELptr channel){
    if (!__symbolic_CPXflushchannel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXflushchannel", (gpointer *) &__symbolic_CPXflushchannel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXflushchannel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXflushchannel.\n");
        }
    }
    return __symbolic_CPXflushchannel(env, channel);
}
int CPXflushstdchannels (CPXCENVptr env){
    if (!__symbolic_CPXflushstdchannels) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXflushstdchannels", (gpointer *) &__symbolic_CPXflushstdchannels)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXflushstdchannels could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXflushstdchannels.\n");
        }
    }
    return __symbolic_CPXflushstdchannels(env);
}
CPXCHANNELptr CPXaddchannel (CPXENVptr env){
    if (!__symbolic_CPXaddchannel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddchannel", (gpointer *) &__symbolic_CPXaddchannel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddchannel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddchannel.\n");
        }
    }
    return __symbolic_CPXaddchannel(env);
}
int CPXaddfpdest (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr){
    if (!__symbolic_CPXaddfpdest) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddfpdest", (gpointer *) &__symbolic_CPXaddfpdest)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddfpdest could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddfpdest.\n");
        }
    }
    return __symbolic_CPXaddfpdest(env, channel, fileptr);
}
int CPXdelfpdest (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr){
    if (!__symbolic_CPXdelfpdest) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelfpdest", (gpointer *) &__symbolic_CPXdelfpdest)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelfpdest could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelfpdest.\n");
        }
    }
    return __symbolic_CPXdelfpdest(env, channel, fileptr);
}
int CPXaddfuncdest (CPXCENVptr env, CPXCHANNELptr channel, void *handle, void ( * msgfunction) (void *, const char *)){
    if (!__symbolic_CPXaddfuncdest) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddfuncdest", (gpointer *) &__symbolic_CPXaddfuncdest)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddfuncdest could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddfuncdest.\n");
        }
    }
    return __symbolic_CPXaddfuncdest(env, channel, handle, msgfunction);
}
int CPXdelfuncdest (CPXCENVptr env, CPXCHANNELptr channel, void *handle, void ( * msgfunction) (void *, const char *)){
    if (!__symbolic_CPXdelfuncdest) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelfuncdest", (gpointer *) &__symbolic_CPXdelfuncdest)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelfuncdest could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelfuncdest.\n");
        }
    }
    return __symbolic_CPXdelfuncdest(env, channel, handle, msgfunction);
}
void CPXdelchannel (CPXENVptr env, CPXCHANNELptr * channel_p){
    if (!__symbolic_CPXdelchannel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelchannel", (gpointer *) &__symbolic_CPXdelchannel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelchannel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelchannel.\n");
        }
    }
    return __symbolic_CPXdelchannel(env, channel_p);
}
void CPXdisconnectchannel (CPXCENVptr env, CPXCHANNELptr channel){
    if (!__symbolic_CPXdisconnectchannel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdisconnectchannel", (gpointer *) &__symbolic_CPXdisconnectchannel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdisconnectchannel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdisconnectchannel.\n");
        }
    }
    return __symbolic_CPXdisconnectchannel(env, channel);
}
CPXCCHARptr CPXgeterrorstring (CPXCENVptr env, int errcode, char *buffer_str){
    if (!__symbolic_CPXgeterrorstring) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgeterrorstring", (gpointer *) &__symbolic_CPXgeterrorstring)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgeterrorstring could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgeterrorstring.\n");
        }
    }
    return __symbolic_CPXgeterrorstring(env, errcode, buffer_str);
}
int CPXsetlpcallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle){
    if (!__symbolic_CPXsetlpcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetlpcallbackfunc", (gpointer *) &__symbolic_CPXsetlpcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetlpcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetlpcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetlpcallbackfunc(env, callback, cbhandle);
}
int CPXsetnetcallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle){
    if (!__symbolic_CPXsetnetcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetnetcallbackfunc", (gpointer *) &__symbolic_CPXsetnetcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetnetcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetnetcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetnetcallbackfunc(env, callback, cbhandle);
}
int CPXsettuningcallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle){
    if (!__symbolic_CPXsettuningcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsettuningcallbackfunc", (gpointer *) &__symbolic_CPXsettuningcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsettuningcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsettuningcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsettuningcallbackfunc(env, callback, cbhandle);
}
int CPXgetcallbackinfo (CPXCENVptr env, void *cbdata, int wherefrom, int whichinfo, void *result_p){
    if (!__symbolic_CPXgetcallbackinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackinfo", (gpointer *) &__symbolic_CPXgetcallbackinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackinfo.\n");
        }
    }
    return __symbolic_CPXgetcallbackinfo(env, cbdata, wherefrom, whichinfo, result_p);
}
int CPXgetlpcallbackfunc (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p){
    if (!__symbolic_CPXgetlpcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetlpcallbackfunc", (gpointer *) &__symbolic_CPXgetlpcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetlpcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetlpcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetlpcallbackfunc(env, callback_p, cbhandle_p);
}
int CPXgetnetcallbackfunc (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p){
    if (!__symbolic_CPXgetnetcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnetcallbackfunc", (gpointer *) &__symbolic_CPXgetnetcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnetcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnetcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetnetcallbackfunc(env, callback_p, cbhandle_p);
}
int CPXgettuningcallbackfunc (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p){
    if (!__symbolic_CPXgettuningcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgettuningcallbackfunc", (gpointer *) &__symbolic_CPXgettuningcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgettuningcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgettuningcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgettuningcallbackfunc(env, callback_p, cbhandle_p);
}
int CPXsetprofcallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, int, void *), void *cbhandle){
    if (!__symbolic_CPXsetprofcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetprofcallbackfunc", (gpointer *) &__symbolic_CPXsetprofcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetprofcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetprofcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetprofcallbackfunc(env, callback, cbhandle);
}
CPXFILEptr CPXfopen (const char *filename_str, const char *type_str){
    if (!__symbolic_CPXfopen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfopen", (gpointer *) &__symbolic_CPXfopen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfopen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfopen.\n");
        }
    }
    return __symbolic_CPXfopen(filename_str, type_str);
}
int CPXfclose (CPXFILEptr stream){
    if (!__symbolic_CPXfclose) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfclose", (gpointer *) &__symbolic_CPXfclose)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfclose could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfclose.\n");
        }
    }
    return __symbolic_CPXfclose(stream);
}
int CPXfputs (const char *s_str, CPXFILEptr stream){
    if (!__symbolic_CPXfputs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfputs", (gpointer *) &__symbolic_CPXfputs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfputs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfputs.\n");
        }
    }
    return __symbolic_CPXfputs(s_str, stream);
}
CPXVOIDptr CPXmalloc (size_t size){
    if (!__symbolic_CPXmalloc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmalloc", (gpointer *) &__symbolic_CPXmalloc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmalloc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmalloc.\n");
        }
    }
    return __symbolic_CPXmalloc(size);
}
CPXVOIDptr CPXrealloc (void *ptr, size_t size){
    if (!__symbolic_CPXrealloc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrealloc", (gpointer *) &__symbolic_CPXrealloc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrealloc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrealloc.\n");
        }
    }
    return __symbolic_CPXrealloc(ptr, size);
}
CPXVOIDptr CPXmemcpy (void *s1, void *s2, size_t n){
    if (!__symbolic_CPXmemcpy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmemcpy", (gpointer *) &__symbolic_CPXmemcpy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmemcpy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmemcpy.\n");
        }
    }
    return __symbolic_CPXmemcpy(s1, s2, n);
}
void CPXfree (void *ptr){
    if (!__symbolic_CPXfree) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfree", (gpointer *) &__symbolic_CPXfree)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfree could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfree.\n");
        }
    }
    return __symbolic_CPXfree(ptr);
}
int CPXstrlen (const char *s_str){
    if (!__symbolic_CPXstrlen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXstrlen", (gpointer *) &__symbolic_CPXstrlen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXstrlen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXstrlen.\n");
        }
    }
    return __symbolic_CPXstrlen(s_str);
}
CPXCHARptr CPXstrcpy (char *dest_str, const char *src_str){
    if (!__symbolic_CPXstrcpy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXstrcpy", (gpointer *) &__symbolic_CPXstrcpy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXstrcpy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXstrcpy.\n");
        }
    }
    return __symbolic_CPXstrcpy(dest_str, src_str);
}
int CPXputenv (const char *envsetting_str){
    if (!__symbolic_CPXputenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXputenv", (gpointer *) &__symbolic_CPXputenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXputenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXputenv.\n");
        }
    }
    return __symbolic_CPXputenv(envsetting_str);
}
void CPXEisort (int n, int *a, int *perm){
    if (!__symbolic_CPXEisort) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEisort", (gpointer *) &__symbolic_CPXEisort)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEisort could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEisort.\n");
        }
    }
    return __symbolic_CPXEisort(n, a, perm);
}
void CPXEinsort (int n, int *a){
    if (!__symbolic_CPXEinsort) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEinsort", (gpointer *) &__symbolic_CPXEinsort)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEinsort could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEinsort.\n");
        }
    }
    return __symbolic_CPXEinsort(n, a);
}
int CPXEgetThreadNumber (CPXCENVptr env){
    if (!__symbolic_CPXEgetThreadNumber) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetThreadNumber", (gpointer *) &__symbolic_CPXEgetThreadNumber)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetThreadNumber could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetThreadNumber.\n");
        }
    }
    return __symbolic_CPXEgetThreadNumber(env);
}
int CPXEgetmaxthreads (CPXCENVptr env){
    if (!__symbolic_CPXEgetmaxthreads) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetmaxthreads", (gpointer *) &__symbolic_CPXEgetmaxthreads)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetmaxthreads could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetmaxthreads.\n");
        }
    }
    return __symbolic_CPXEgetmaxthreads(env);
}
int CPXEsetJNI (CPXENVptr env, CPXVOIDptr jni){
    if (!__symbolic_CPXEsetJNI) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEsetJNI", (gpointer *) &__symbolic_CPXEsetJNI)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEsetJNI could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEsetJNI.\n");
        }
    }
    return __symbolic_CPXEsetJNI(env, jni);
}
CPXVOIDptr CPXEgetJNI (CPXCENVptr env){
    if (!__symbolic_CPXEgetJNI) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetJNI", (gpointer *) &__symbolic_CPXEgetJNI)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetJNI could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetJNI.\n");
        }
    }
    return __symbolic_CPXEgetJNI(env);
}
int CPXEsetnamefunctions (CPXENVptr env, void *userdata, const char *( * getcname) (void *, int, char *), const char *( * getrname) (void *, int, char *), const char *( * getqname) (void *, int, char *), const char *( * getiname) (void *, int, char *), const char *( * getsname) (void *, int, char *)){
    if (!__symbolic_CPXEsetnamefunctions) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEsetnamefunctions", (gpointer *) &__symbolic_CPXEsetnamefunctions)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEsetnamefunctions could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEsetnamefunctions.\n");
        }
    }
    return __symbolic_CPXEsetnamefunctions(env, userdata, getcname, getrname, getqname, getiname, getsname);
}
int CPXEsetnamedef (CPXENVptr env, const char *def_str, int deftype){
    if (!__symbolic_CPXEsetnamedef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEsetnamedef", (gpointer *) &__symbolic_CPXEsetnamedef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEsetnamedef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEsetnamedef.\n");
        }
    }
    return __symbolic_CPXEsetnamedef(env, def_str, deftype);
}
int CPXEdelnames (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXEdelnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEdelnames", (gpointer *) &__symbolic_CPXEdelnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEdelnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEdelnames.\n");
        }
    }
    return __symbolic_CPXEdelnames(env, lp);
}
CPXVOIDptr CPXEgetCache (CPXLPptr lp){
    if (!__symbolic_CPXEgetCache) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetCache", (gpointer *) &__symbolic_CPXEgetCache)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetCache could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetCache.\n");
        }
    }
    return __symbolic_CPXEgetCache(lp);
}
int CPXEcacheNewCols (CPXCENVptr env, CPXLPptr lp, int ccnt, const double *zobj, const double *zlb, const double *zub, const char *zctype, const char *const *zcname){
    if (!__symbolic_CPXEcacheNewCols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEcacheNewCols", (gpointer *) &__symbolic_CPXEcacheNewCols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEcacheNewCols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEcacheNewCols.\n");
        }
    }
    return __symbolic_CPXEcacheNewCols(env, lp, ccnt, zobj, zlb, zub, zctype, zcname);
}
int CPXEcacheNewRows (CPXCENVptr env, CPXLPptr lp, int rcnt, const double *zrhs, const char *zsense, const double *rngval, const char *const *zrname){
    if (!__symbolic_CPXEcacheNewRows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEcacheNewRows", (gpointer *) &__symbolic_CPXEcacheNewRows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEcacheNewRows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEcacheNewRows.\n");
        }
    }
    return __symbolic_CPXEcacheNewRows(env, lp, rcnt, zrhs, zsense, rngval, zrname);
}
int CPXEcacheNewNZsByNZ (CPXCENVptr env, CPXLPptr lp, int nzcnt, const int *rowlist, const int *collist, const double *vallist){
    if (!__symbolic_CPXEcacheNewNZsByNZ) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEcacheNewNZsByNZ", (gpointer *) &__symbolic_CPXEcacheNewNZsByNZ)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEcacheNewNZsByNZ could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEcacheNewNZsByNZ.\n");
        }
    }
    return __symbolic_CPXEcacheNewNZsByNZ(env, lp, nzcnt, rowlist, collist, vallist);
}
int CPXEgetorigcolind (CPXCENVptr env, CPXCLPptr lp, int j){
    if (!__symbolic_CPXEgetorigcolind) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetorigcolind", (gpointer *) &__symbolic_CPXEgetorigcolind)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetorigcolind could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetorigcolind.\n");
        }
    }
    return __symbolic_CPXEgetorigcolind(env, lp, j);
}
int CPXEgetorigrowind (CPXCENVptr env, CPXCLPptr lp, int i){
    if (!__symbolic_CPXEgetorigrowind) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetorigrowind", (gpointer *) &__symbolic_CPXEgetorigrowind)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetorigrowind could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetorigrowind.\n");
        }
    }
    return __symbolic_CPXEgetorigrowind(env, lp, i);
}
double CPXEgetbigreal (CPXCENVptr env){
    if (!__symbolic_CPXEgetbigreal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetbigreal", (gpointer *) &__symbolic_CPXEgetbigreal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetbigreal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetbigreal.\n");
        }
    }
    return __symbolic_CPXEgetbigreal(env);
}
int CPXEispromotion (CPXCENVptr env, int rspace, int cspace, int ispace){
    if (!__symbolic_CPXEispromotion) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEispromotion", (gpointer *) &__symbolic_CPXEispromotion)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEispromotion could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEispromotion.\n");
        }
    }
    return __symbolic_CPXEispromotion(env, rspace, cspace, ispace);
}
int CPXEgetnumrownz (CPXCENVptr env, CPXCLPptr lp, int *mark){
    if (!__symbolic_CPXEgetnumrownz) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetnumrownz", (gpointer *) &__symbolic_CPXEgetnumrownz)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetnumrownz could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetnumrownz.\n");
        }
    }
    return __symbolic_CPXEgetnumrownz(env, lp, mark);
}
int CPXEcangetbase (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXEcangetbase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEcangetbase", (gpointer *) &__symbolic_CPXEcangetbase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEcangetbase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEcangetbase.\n");
        }
    }
    return __symbolic_CPXEcangetbase(env, lp);
}
int CPXEwriteparam (CPXCENVptr env, const char *filename_str){
    if (!__symbolic_CPXEwriteparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEwriteparam", (gpointer *) &__symbolic_CPXEwriteparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEwriteparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEwriteparam.\n");
        }
    }
    return __symbolic_CPXEwriteparam(env, filename_str);
}
int CPXsetterminate (CPXENVptr env, volatile int *terminate_p){
    if (!__symbolic_CPXsetterminate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetterminate", (gpointer *) &__symbolic_CPXsetterminate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetterminate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetterminate.\n");
        }
    }
    return __symbolic_CPXsetterminate(env, terminate_p);
}
void CPXEsetterminatefunc (CPXENVptr env, int ( * terminatefunc) (CPXCENVptr)){
    if (!__symbolic_CPXEsetterminatefunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEsetterminatefunc", (gpointer *) &__symbolic_CPXEsetterminatefunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEsetterminatefunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEsetterminatefunc.\n");
        }
    }
    return __symbolic_CPXEsetterminatefunc(env, terminatefunc);
}
int CPXEnsAddNames (struct cpxnameset *nset, int n, const char *const *name){
    if (!__symbolic_CPXEnsAddNames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEnsAddNames", (gpointer *) &__symbolic_CPXEnsAddNames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEnsAddNames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEnsAddNames.\n");
        }
    }
    return __symbolic_CPXEnsAddNames(nset, n, name);
}
int CPXgetbhead (CPXCENVptr env, CPXCLPptr lp, int *head, double *x){
    if (!__symbolic_CPXgetbhead) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbhead", (gpointer *) &__symbolic_CPXgetbhead)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbhead could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbhead.\n");
        }
    }
    return __symbolic_CPXgetbhead(env, lp, head, x);
}
int CPXbinvcol (CPXCENVptr env, CPXCLPptr lp, int j, double *x){
    if (!__symbolic_CPXbinvcol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbinvcol", (gpointer *) &__symbolic_CPXbinvcol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbinvcol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbinvcol.\n");
        }
    }
    return __symbolic_CPXbinvcol(env, lp, j, x);
}
int CPXbinvrow (CPXCENVptr env, CPXCLPptr lp, int i, double *y){
    if (!__symbolic_CPXbinvrow) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbinvrow", (gpointer *) &__symbolic_CPXbinvrow)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbinvrow could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbinvrow.\n");
        }
    }
    return __symbolic_CPXbinvrow(env, lp, i, y);
}
int CPXbinvacol (CPXCENVptr env, CPXCLPptr lp, int j, double *x){
    if (!__symbolic_CPXbinvacol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbinvacol", (gpointer *) &__symbolic_CPXbinvacol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbinvacol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbinvacol.\n");
        }
    }
    return __symbolic_CPXbinvacol(env, lp, j, x);
}
int CPXbinvarow (CPXCENVptr env, CPXCLPptr lp, int i, double *z){
    if (!__symbolic_CPXbinvarow) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbinvarow", (gpointer *) &__symbolic_CPXbinvarow)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbinvarow could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbinvarow.\n");
        }
    }
    return __symbolic_CPXbinvarow(env, lp, i, z);
}
int CPXftran (CPXCENVptr env, CPXCLPptr lp, double *x){
    if (!__symbolic_CPXftran) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXftran", (gpointer *) &__symbolic_CPXftran)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXftran could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXftran.\n");
        }
    }
    return __symbolic_CPXftran(env, lp, x);
}
int CPXbtran (CPXCENVptr env, CPXCLPptr lp, double *y){
    if (!__symbolic_CPXbtran) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbtran", (gpointer *) &__symbolic_CPXbtran)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbtran could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbtran.\n");
        }
    }
    return __symbolic_CPXbtran(env, lp, y);
}
int CPXgetijrow (CPXCENVptr env, CPXCLPptr lp, int i, int j, int *row_p){
    if (!__symbolic_CPXgetijrow) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetijrow", (gpointer *) &__symbolic_CPXgetijrow)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetijrow could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetijrow.\n");
        }
    }
    return __symbolic_CPXgetijrow(env, lp, i, j, row_p);
}
int CPXgetray (CPXCENVptr env, CPXCLPptr lp, double *z){
    if (!__symbolic_CPXgetray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetray", (gpointer *) &__symbolic_CPXgetray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetray.\n");
        }
    }
    return __symbolic_CPXgetray(env, lp, z);
}
int CPXgetweight (CPXCENVptr env, CPXCLPptr lp, int rcnt, const int *rmatbeg, const int *rmatind, const double *rmatval, double *weight, int dpriind){
    if (!__symbolic_CPXgetweight) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetweight", (gpointer *) &__symbolic_CPXgetweight)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetweight could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetweight.\n");
        }
    }
    return __symbolic_CPXgetweight(env, lp, rcnt, rmatbeg, rmatind, rmatval, weight, dpriind);
}
int CPXmdleave (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downratio, double *upratio){
    if (!__symbolic_CPXmdleave) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmdleave", (gpointer *) &__symbolic_CPXmdleave)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmdleave could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmdleave.\n");
        }
    }
    return __symbolic_CPXmdleave(env, lp, indices, cnt, downratio, upratio);
}
int CPXstrongbranch (CPXCENVptr env, CPXLPptr lp, const int *indices, int cnt, double *downobj, double *upobj, int itlim){
    if (!__symbolic_CPXstrongbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXstrongbranch", (gpointer *) &__symbolic_CPXstrongbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXstrongbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXstrongbranch.\n");
        }
    }
    return __symbolic_CPXstrongbranch(env, lp, indices, cnt, downobj, upobj, itlim);
}
int CPXdualfarkas (CPXCENVptr env, CPXCLPptr lp, double *y, double *proof_p){
    if (!__symbolic_CPXdualfarkas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdualfarkas", (gpointer *) &__symbolic_CPXdualfarkas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdualfarkas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdualfarkas.\n");
        }
    }
    return __symbolic_CPXdualfarkas(env, lp, y, proof_p);
}
int CPXgetobjoffset (CPXCENVptr env, CPXCLPptr lp, double *objoffset_p){
    if (!__symbolic_CPXgetobjoffset) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetobjoffset", (gpointer *) &__symbolic_CPXgetobjoffset)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetobjoffset could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetobjoffset.\n");
        }
    }
    return __symbolic_CPXgetobjoffset(env, lp, objoffset_p);
}
int CPXcopypartialbase (CPXCENVptr env, CPXLPptr lp, int ccnt, const int *cindices, const int *cstat, int rcnt, const int *rindices, const int *rstat){
    if (!__symbolic_CPXcopypartialbase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopypartialbase", (gpointer *) &__symbolic_CPXcopypartialbase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopypartialbase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopypartialbase.\n");
        }
    }
    return __symbolic_CPXcopypartialbase(env, lp, ccnt, cindices, cstat, rcnt, rindices, rstat);
}
int CPXgetbasednorms (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat, double *dnorm){
    if (!__symbolic_CPXgetbasednorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbasednorms", (gpointer *) &__symbolic_CPXgetbasednorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbasednorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbasednorms.\n");
        }
    }
    return __symbolic_CPXgetbasednorms(env, lp, cstat, rstat, dnorm);
}
int CPXcopybasednorms (CPXCENVptr env, CPXLPptr lp, const int *cstat, const int *rstat, const double *dnorm){
    if (!__symbolic_CPXcopybasednorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopybasednorms", (gpointer *) &__symbolic_CPXcopybasednorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopybasednorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopybasednorms.\n");
        }
    }
    return __symbolic_CPXcopybasednorms(env, lp, cstat, rstat, dnorm);
}
int CPXgetdnorms (CPXCENVptr env, CPXCLPptr lp, double *norm, int *head, int *len_p){
    if (!__symbolic_CPXgetdnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdnorms", (gpointer *) &__symbolic_CPXgetdnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdnorms.\n");
        }
    }
    return __symbolic_CPXgetdnorms(env, lp, norm, head, len_p);
}
int CPXcopydnorms (CPXCENVptr env, CPXLPptr lp, const double *norm, const int *head, int len){
    if (!__symbolic_CPXcopydnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopydnorms", (gpointer *) &__symbolic_CPXcopydnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopydnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopydnorms.\n");
        }
    }
    return __symbolic_CPXcopydnorms(env, lp, norm, head, len);
}
void CPXkilldnorms (CPXLPptr lp){
    if (!__symbolic_CPXkilldnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXkilldnorms", (gpointer *) &__symbolic_CPXkilldnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXkilldnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXkilldnorms.\n");
        }
    }
    return __symbolic_CPXkilldnorms(lp);
}
int CPXgetpnorms (CPXCENVptr env, CPXCLPptr lp, double *cnorm, double *rnorm, int *len_p){
    if (!__symbolic_CPXgetpnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetpnorms", (gpointer *) &__symbolic_CPXgetpnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetpnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetpnorms.\n");
        }
    }
    return __symbolic_CPXgetpnorms(env, lp, cnorm, rnorm, len_p);
}
int CPXcopypnorms (CPXCENVptr env, CPXLPptr lp, const double *cnorm, const double *rnorm, int len){
    if (!__symbolic_CPXcopypnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopypnorms", (gpointer *) &__symbolic_CPXcopypnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopypnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopypnorms.\n");
        }
    }
    return __symbolic_CPXcopypnorms(env, lp, cnorm, rnorm, len);
}
void CPXkillpnorms (CPXLPptr lp){
    if (!__symbolic_CPXkillpnorms) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXkillpnorms", (gpointer *) &__symbolic_CPXkillpnorms)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXkillpnorms could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXkillpnorms.\n");
        }
    }
    return __symbolic_CPXkillpnorms(lp);
}
int CPXpivotin (CPXCENVptr env, CPXLPptr lp, const int *rlist, int rlen){
    if (!__symbolic_CPXpivotin) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpivotin", (gpointer *) &__symbolic_CPXpivotin)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpivotin could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpivotin.\n");
        }
    }
    return __symbolic_CPXpivotin(env, lp, rlist, rlen);
}
int CPXpivotout (CPXCENVptr env, CPXLPptr lp, const int *clist, int clen){
    if (!__symbolic_CPXpivotout) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpivotout", (gpointer *) &__symbolic_CPXpivotout)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpivotout could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpivotout.\n");
        }
    }
    return __symbolic_CPXpivotout(env, lp, clist, clen);
}
int CPXunscaleprob (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXunscaleprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXunscaleprob", (gpointer *) &__symbolic_CPXunscaleprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXunscaleprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXunscaleprob.\n");
        }
    }
    return __symbolic_CPXunscaleprob(env, lp);
}
int CPXtightenbds (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *lu, const double *bd){
    if (!__symbolic_CPXtightenbds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXtightenbds", (gpointer *) &__symbolic_CPXtightenbds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXtightenbds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXtightenbds.\n");
        }
    }
    return __symbolic_CPXtightenbds(env, lp, cnt, indices, lu, bd);
}
int CPXpresolve (CPXCENVptr env, CPXLPptr lp, int method){
    if (!__symbolic_CPXpresolve) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpresolve", (gpointer *) &__symbolic_CPXpresolve)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpresolve could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpresolve.\n");
        }
    }
    return __symbolic_CPXpresolve(env, lp, method);
}
int CPXbasicpresolve (CPXCENVptr env, CPXLPptr lp, double *redlb, double *redub, int *rstat){
    if (!__symbolic_CPXbasicpresolve) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbasicpresolve", (gpointer *) &__symbolic_CPXbasicpresolve)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbasicpresolve could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbasicpresolve.\n");
        }
    }
    return __symbolic_CPXbasicpresolve(env, lp, redlb, redub, rstat);
}
int CPXslackfromx (CPXCENVptr env, CPXCLPptr lp, const double *x, double *slack){
    if (!__symbolic_CPXslackfromx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXslackfromx", (gpointer *) &__symbolic_CPXslackfromx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXslackfromx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXslackfromx.\n");
        }
    }
    return __symbolic_CPXslackfromx(env, lp, x, slack);
}
int CPXdjfrompi (CPXCENVptr env, CPXCLPptr lp, const double *pi, double *dj){
    if (!__symbolic_CPXdjfrompi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdjfrompi", (gpointer *) &__symbolic_CPXdjfrompi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdjfrompi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdjfrompi.\n");
        }
    }
    return __symbolic_CPXdjfrompi(env, lp, pi, dj);
}
int CPXqpdjfrompi (CPXCENVptr env, CPXCLPptr lp, const double *pi, const double *x, double *dj){
    if (!__symbolic_CPXqpdjfrompi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXqpdjfrompi", (gpointer *) &__symbolic_CPXqpdjfrompi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXqpdjfrompi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXqpdjfrompi.\n");
        }
    }
    return __symbolic_CPXqpdjfrompi(env, lp, pi, x, dj);
}
int CPXfreepresolve (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXfreepresolve) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfreepresolve", (gpointer *) &__symbolic_CPXfreepresolve)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfreepresolve could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfreepresolve.\n");
        }
    }
    return __symbolic_CPXfreepresolve(env, lp);
}
int CPXgetredlp (CPXCENVptr env, CPXCLPptr lp, CPXCLPptr * redlp_p){
    if (!__symbolic_CPXgetredlp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetredlp", (gpointer *) &__symbolic_CPXgetredlp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetredlp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetredlp.\n");
        }
    }
    return __symbolic_CPXgetredlp(env, lp, redlp_p);
}
int CPXcrushx (CPXCENVptr env, CPXCLPptr lp, const double *x, double *prex){
    if (!__symbolic_CPXcrushx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcrushx", (gpointer *) &__symbolic_CPXcrushx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcrushx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcrushx.\n");
        }
    }
    return __symbolic_CPXcrushx(env, lp, x, prex);
}
int CPXuncrushx (CPXCENVptr env, CPXCLPptr lp, double *x, const double *prex){
    if (!__symbolic_CPXuncrushx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXuncrushx", (gpointer *) &__symbolic_CPXuncrushx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXuncrushx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXuncrushx.\n");
        }
    }
    return __symbolic_CPXuncrushx(env, lp, x, prex);
}
int CPXcrushpi (CPXCENVptr env, CPXCLPptr lp, const double *pi, double *prepi){
    if (!__symbolic_CPXcrushpi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcrushpi", (gpointer *) &__symbolic_CPXcrushpi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcrushpi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcrushpi.\n");
        }
    }
    return __symbolic_CPXcrushpi(env, lp, pi, prepi);
}
int CPXuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi, const double *prepi){
    if (!__symbolic_CPXuncrushpi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXuncrushpi", (gpointer *) &__symbolic_CPXuncrushpi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXuncrushpi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXuncrushpi.\n");
        }
    }
    return __symbolic_CPXuncrushpi(env, lp, pi, prepi);
}
int CPXqpuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi, const double *prepi, const double *x){
    if (!__symbolic_CPXqpuncrushpi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXqpuncrushpi", (gpointer *) &__symbolic_CPXqpuncrushpi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXqpuncrushpi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXqpuncrushpi.\n");
        }
    }
    return __symbolic_CPXqpuncrushpi(env, lp, pi, prepi, x);
}
int CPXcrushform (CPXCENVptr env, CPXCLPptr lp, int len, const int *ind, const double *val, int *plen_p, double *poffset_p, int *pind, double *pval){
    if (!__symbolic_CPXcrushform) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcrushform", (gpointer *) &__symbolic_CPXcrushform)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcrushform could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcrushform.\n");
        }
    }
    return __symbolic_CPXcrushform(env, lp, len, ind, val, plen_p, poffset_p, pind, pval);
}
int CPXuncrushform (CPXCENVptr env, CPXCLPptr lp, int plen, const int *pind, const double *pval, int *len_p, double *offset_p, int *ind, double *val){
    if (!__symbolic_CPXuncrushform) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXuncrushform", (gpointer *) &__symbolic_CPXuncrushform)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXuncrushform could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXuncrushform.\n");
        }
    }
    return __symbolic_CPXuncrushform(env, lp, plen, pind, pval, len_p, offset_p, ind, val);
}
int CPXgetprestat (CPXCENVptr env, CPXCLPptr lp, int *prestat_p, int *pcstat, int *prstat, int *ocstat, int *orstat){
    if (!__symbolic_CPXgetprestat) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetprestat", (gpointer *) &__symbolic_CPXgetprestat)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetprestat could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetprestat.\n");
        }
    }
    return __symbolic_CPXgetprestat(env, lp, prestat_p, pcstat, prstat, ocstat, orstat);
}
int CPXcopyprotected (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices){
    if (!__symbolic_CPXcopyprotected) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyprotected", (gpointer *) &__symbolic_CPXcopyprotected)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyprotected could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyprotected.\n");
        }
    }
    return __symbolic_CPXcopyprotected(env, lp, cnt, indices);
}
int CPXgetprotected (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, int pspace, int *surplus_p){
    if (!__symbolic_CPXgetprotected) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetprotected", (gpointer *) &__symbolic_CPXgetprotected)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetprotected could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetprotected.\n");
        }
    }
    return __symbolic_CPXgetprotected(env, lp, cnt_p, indices, pspace, surplus_p);
}
int CPXEaggregatevars (CPXCENVptr env, CPXLPptr lp, int start, int end, const char *protectrow){
    if (!__symbolic_CPXEaggregatevars) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaggregatevars", (gpointer *) &__symbolic_CPXEaggregatevars)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaggregatevars could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaggregatevars.\n");
        }
    }
    return __symbolic_CPXEaggregatevars(env, lp, start, end, protectrow);
}
int CPXgettime (CPXCENVptr env, double *timestamp){
    if (!__symbolic_CPXgettime) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgettime", (gpointer *) &__symbolic_CPXgettime)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgettime could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgettime.\n");
        }
    }
    return __symbolic_CPXgettime(env, timestamp);
}
int CPXlpwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXlpwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXlpwrite", (gpointer *) &__symbolic_CPXlpwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXlpwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXlpwrite.\n");
        }
    }
    return __symbolic_CPXlpwrite(env, lp, filename_str);
}
int CPXlprewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXlprewrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXlprewrite", (gpointer *) &__symbolic_CPXlprewrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXlprewrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXlprewrite.\n");
        }
    }
    return __symbolic_CPXlprewrite(env, lp, filename_str);
}
int CPXmpswrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXmpswrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmpswrite", (gpointer *) &__symbolic_CPXmpswrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmpswrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmpswrite.\n");
        }
    }
    return __symbolic_CPXmpswrite(env, lp, filename_str);
}
int CPXmpsrewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXmpsrewrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmpsrewrite", (gpointer *) &__symbolic_CPXmpsrewrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmpsrewrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmpsrewrite.\n");
        }
    }
    return __symbolic_CPXmpsrewrite(env, lp, filename_str);
}
int CPXsavwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXsavwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsavwrite", (gpointer *) &__symbolic_CPXsavwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsavwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsavwrite.\n");
        }
    }
    return __symbolic_CPXsavwrite(env, lp, filename_str);
}
int CPXreadcopyvec (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopyvec) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopyvec", (gpointer *) &__symbolic_CPXreadcopyvec)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopyvec could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopyvec.\n");
        }
    }
    return __symbolic_CPXreadcopyvec(env, lp, filename_str);
}
int CPXvecwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXvecwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXvecwrite", (gpointer *) &__symbolic_CPXvecwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXvecwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXvecwrite.\n");
        }
    }
    return __symbolic_CPXvecwrite(env, lp, filename_str);
}
int CPXbinsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXbinsolwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbinsolwrite", (gpointer *) &__symbolic_CPXbinsolwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbinsolwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbinsolwrite.\n");
        }
    }
    return __symbolic_CPXbinsolwrite(env, lp, filename_str);
}
int CPXtxtsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXtxtsolwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXtxtsolwrite", (gpointer *) &__symbolic_CPXtxtsolwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXtxtsolwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXtxtsolwrite.\n");
        }
    }
    return __symbolic_CPXtxtsolwrite(env, lp, filename_str);
}
int CPXwritesol (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, const char *filetype_str){
    if (!__symbolic_CPXwritesol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXwritesol", (gpointer *) &__symbolic_CPXwritesol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXwritesol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXwritesol.\n");
        }
    }
    return __symbolic_CPXwritesol(env, lp, filename_str, filetype_str);
}
int CPXgetiis (CPXCENVptr env, CPXCLPptr lp, int *iisstat_p, int *rowind, int *rowbdstat, int *iisnumrows_p, int *colind, int *colbdstat, int *iisnumcols_p){
    if (!__symbolic_CPXgetiis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetiis", (gpointer *) &__symbolic_CPXgetiis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetiis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetiis.\n");
        }
    }
    return __symbolic_CPXgetiis(env, lp, iisstat_p, rowind, rowbdstat, iisnumrows_p, colind, colbdstat, iisnumcols_p);
}
int CPXfindiis (CPXCENVptr env, CPXLPptr lp, int *iisnumrows_p, int *iisnumcols_p){
    if (!__symbolic_CPXfindiis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfindiis", (gpointer *) &__symbolic_CPXfindiis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfindiis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfindiis.\n");
        }
    }
    return __symbolic_CPXfindiis(env, lp, iisnumrows_p, iisnumcols_p);
}
int CPXdisplayiis (CPXCENVptr env, CPXCLPptr lp, CPXCHANNELptr channel, int display){
    if (!__symbolic_CPXdisplayiis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdisplayiis", (gpointer *) &__symbolic_CPXdisplayiis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdisplayiis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdisplayiis.\n");
        }
    }
    return __symbolic_CPXdisplayiis(env, lp, channel, display);
}
int CPXiiswrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXiiswrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXiiswrite", (gpointer *) &__symbolic_CPXiiswrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXiiswrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXiiswrite.\n");
        }
    }
    return __symbolic_CPXiiswrite(env, lp, filename_str);
}
int CPXhybbaropt (CPXCENVptr env, CPXLPptr lp, int method){
    if (!__symbolic_CPXhybbaropt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXhybbaropt", (gpointer *) &__symbolic_CPXhybbaropt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXhybbaropt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXhybbaropt.\n");
        }
    }
    return __symbolic_CPXhybbaropt(env, lp, method);
}
int CPXbaropt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXbaropt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbaropt", (gpointer *) &__symbolic_CPXbaropt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbaropt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbaropt.\n");
        }
    }
    return __symbolic_CPXbaropt(env, lp);
}
void CPXEgeneric_lock (volatile int *lock){
    if (!__symbolic_CPXEgeneric_lock) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgeneric_lock", (gpointer *) &__symbolic_CPXEgeneric_lock)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgeneric_lock could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgeneric_lock.\n");
        }
    }
    return __symbolic_CPXEgeneric_lock(lock);
}
void CPXEgeneric_unlock (volatile int *lock){
    if (!__symbolic_CPXEgeneric_unlock) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgeneric_unlock", (gpointer *) &__symbolic_CPXEgeneric_unlock)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgeneric_unlock could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgeneric_unlock.\n");
        }
    }
    return __symbolic_CPXEgeneric_unlock(lock);
}
int CPXsetorderhookfunc (CPXENVptr env, int ( * orderhook) (CPXCENVptr, int, int *, int **, int *)){
    if (!__symbolic_CPXsetorderhookfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetorderhookfunc", (gpointer *) &__symbolic_CPXsetorderhookfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetorderhookfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetorderhookfunc.\n");
        }
    }
    return __symbolic_CPXsetorderhookfunc(env, orderhook);
}
void CPXgetorderhookfunc (CPXCENVptr env, int ( ** orderhook_p) (CPXCENVptr, int, int *, int **, int *)){
    if (!__symbolic_CPXgetorderhookfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetorderhookfunc", (gpointer *) &__symbolic_CPXgetorderhookfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetorderhookfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetorderhookfunc.\n");
        }
    }
    return __symbolic_CPXgetorderhookfunc(env, orderhook_p);
}
int CPXcopyctype (CPXCENVptr env, CPXLPptr lp, const char *xctype){
    if (!__symbolic_CPXcopyctype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyctype", (gpointer *) &__symbolic_CPXcopyctype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyctype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyctype.\n");
        }
    }
    return __symbolic_CPXcopyctype(env, lp, xctype);
}
int CPXcopyorder (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const int *priority, const int *direction){
    if (!__symbolic_CPXcopyorder) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyorder", (gpointer *) &__symbolic_CPXcopyorder)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyorder could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyorder.\n");
        }
    }
    return __symbolic_CPXcopyorder(env, lp, cnt, indices, priority, direction);
}
int CPXcopysos (CPXCENVptr env, CPXLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname){
    if (!__symbolic_CPXcopysos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopysos", (gpointer *) &__symbolic_CPXcopysos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopysos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopysos.\n");
        }
    }
    return __symbolic_CPXcopysos(env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname);
}
int CPXcopymipstart (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXcopymipstart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopymipstart", (gpointer *) &__symbolic_CPXcopymipstart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopymipstart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopymipstart.\n");
        }
    }
    return __symbolic_CPXcopymipstart(env, lp, cnt, indices, values);
}
int CPXchgmipstart (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const double *values){
    if (!__symbolic_CPXchgmipstart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgmipstart", (gpointer *) &__symbolic_CPXchgmipstart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgmipstart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgmipstart.\n");
        }
    }
    return __symbolic_CPXchgmipstart(env, lp, cnt, indices, values);
}
int CPXchgmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt, const int *mipstartindices, int nzcnt, const int *beg, const int *varindices, const double *values, const int *effortlevel){
    if (!__symbolic_CPXchgmipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgmipstarts", (gpointer *) &__symbolic_CPXchgmipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgmipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgmipstarts.\n");
        }
    }
    return __symbolic_CPXchgmipstarts(env, lp, mcnt, mipstartindices, nzcnt, beg, varindices, values, effortlevel);
}
int CPXaddmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt, int nzcnt, const int *beg, const int *varindices, const double *values, const int *effortlevel, char **mipstartname){
    if (!__symbolic_CPXaddmipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddmipstarts", (gpointer *) &__symbolic_CPXaddmipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddmipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddmipstarts.\n");
        }
    }
    return __symbolic_CPXaddmipstarts(env, lp, mcnt, nzcnt, beg, varindices, values, effortlevel, mipstartname);
}
int CPXdelmipstarts (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelmipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelmipstarts", (gpointer *) &__symbolic_CPXdelmipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelmipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelmipstarts.\n");
        }
    }
    return __symbolic_CPXdelmipstarts(env, lp, begin, end);
}
int CPXdelsetmipstarts (CPXCENVptr env, CPXLPptr lp, int *delstat){
    if (!__symbolic_CPXdelsetmipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetmipstarts", (gpointer *) &__symbolic_CPXdelsetmipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetmipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetmipstarts.\n");
        }
    }
    return __symbolic_CPXdelsetmipstarts(env, lp, delstat);
}
int CPXrefinemipstartconflict (CPXCENVptr env, CPXLPptr lp, int mipstartindex, int *confnumrows_p, int *confnumcols_p){
    if (!__symbolic_CPXrefinemipstartconflict) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrefinemipstartconflict", (gpointer *) &__symbolic_CPXrefinemipstartconflict)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrefinemipstartconflict could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrefinemipstartconflict.\n");
        }
    }
    return __symbolic_CPXrefinemipstartconflict(env, lp, mipstartindex, confnumrows_p, confnumcols_p);
}
int CPXrefinemipstartconflictext (CPXCENVptr env, CPXLPptr lp, int mipstartindex, int grpcnt, int concnt, const double *grppref, const int *grpbeg, const int *grpind, const char *grptype){
    if (!__symbolic_CPXrefinemipstartconflictext) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXrefinemipstartconflictext", (gpointer *) &__symbolic_CPXrefinemipstartconflictext)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXrefinemipstartconflictext could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXrefinemipstartconflictext.\n");
        }
    }
    return __symbolic_CPXrefinemipstartconflictext(env, lp, mipstartindex, grpcnt, concnt, grppref, grpbeg, grpind, grptype);
}
int CPXmipopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXmipopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmipopt", (gpointer *) &__symbolic_CPXmipopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmipopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmipopt.\n");
        }
    }
    return __symbolic_CPXmipopt(env, lp);
}
int CPXgetmipitcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetmipitcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipitcnt", (gpointer *) &__symbolic_CPXgetmipitcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipitcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipitcnt.\n");
        }
    }
    return __symbolic_CPXgetmipitcnt(env, lp);
}
int CPXgetbestobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p){
    if (!__symbolic_CPXgetbestobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbestobjval", (gpointer *) &__symbolic_CPXgetbestobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbestobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbestobjval.\n");
        }
    }
    return __symbolic_CPXgetbestobjval(env, lp, objval_p);
}
int CPXgetmiprelgap (CPXCENVptr env, CPXCLPptr lp, double *gap_p){
    if (!__symbolic_CPXgetmiprelgap) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmiprelgap", (gpointer *) &__symbolic_CPXgetmiprelgap)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmiprelgap could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmiprelgap.\n");
        }
    }
    return __symbolic_CPXgetmiprelgap(env, lp, gap_p);
}
int CPXgetcutoff (CPXCENVptr env, CPXCLPptr lp, double *cutoff_p){
    if (!__symbolic_CPXgetcutoff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcutoff", (gpointer *) &__symbolic_CPXgetcutoff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcutoff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcutoff.\n");
        }
    }
    return __symbolic_CPXgetcutoff(env, lp, cutoff_p);
}
int CPXgetnodecnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnodecnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnodecnt", (gpointer *) &__symbolic_CPXgetnodecnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnodecnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnodecnt.\n");
        }
    }
    return __symbolic_CPXgetnodecnt(env, lp);
}
int CPXgetnodeleftcnt (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnodeleftcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnodeleftcnt", (gpointer *) &__symbolic_CPXgetnodeleftcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnodeleftcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnodeleftcnt.\n");
        }
    }
    return __symbolic_CPXgetnodeleftcnt(env, lp);
}
int CPXgetnodeint (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnodeint) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnodeint", (gpointer *) &__symbolic_CPXgetnodeint)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnodeint could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnodeint.\n");
        }
    }
    return __symbolic_CPXgetnodeint(env, lp);
}
int CPXgetnumcuts (CPXCENVptr env, CPXCLPptr lp, int cuttype, int *num_p){
    if (!__symbolic_CPXgetnumcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumcuts", (gpointer *) &__symbolic_CPXgetnumcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumcuts.\n");
        }
    }
    return __symbolic_CPXgetnumcuts(env, lp, cuttype, num_p);
}
int CPXgetnummipstarts (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnummipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnummipstarts", (gpointer *) &__symbolic_CPXgetnummipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnummipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnummipstarts.\n");
        }
    }
    return __symbolic_CPXgetnummipstarts(env, lp);
}
int CPXgetmipstart (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, double *value, int mipstartspace, int *surplus_p){
    if (!__symbolic_CPXgetmipstart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipstart", (gpointer *) &__symbolic_CPXgetmipstart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipstart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipstart.\n");
        }
    }
    return __symbolic_CPXgetmipstart(env, lp, cnt_p, indices, value, mipstartspace, surplus_p);
}
int CPXgetmipstarts (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *beg, int *varindices, double *values, int *effortlevel, int startspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetmipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipstarts", (gpointer *) &__symbolic_CPXgetmipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipstarts.\n");
        }
    }
    return __symbolic_CPXgetmipstarts(env, lp, nzcnt_p, beg, varindices, values, effortlevel, startspace, surplus_p, begin, end);
}
int CPXgetmipstartname (CPXCENVptr env, CPXCLPptr lp, char **name, char *store, int storesz, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetmipstartname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipstartname", (gpointer *) &__symbolic_CPXgetmipstartname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipstartname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipstartname.\n");
        }
    }
    return __symbolic_CPXgetmipstartname(env, lp, name, store, storesz, surplus_p, begin, end);
}
int CPXgetmipstartindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetmipstartindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipstartindex", (gpointer *) &__symbolic_CPXgetmipstartindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipstartindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipstartindex.\n");
        }
    }
    return __symbolic_CPXgetmipstartindex(env, lp, lname_str, index_p);
}
int CPXgetsolnpoolmipstart (CPXCENVptr env, CPXCLPptr lp, int soln, int *cnt_p, int *indices, double *value, int mipstartspace, int *surplus_p){
    if (!__symbolic_CPXgetsolnpoolmipstart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolmipstart", (gpointer *) &__symbolic_CPXgetsolnpoolmipstart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolmipstart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolmipstart.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolmipstart(env, lp, soln, cnt_p, indices, value, mipstartspace, surplus_p);
}
int CPXgetsolnpoolnummipstarts (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsolnpoolnummipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolnummipstarts", (gpointer *) &__symbolic_CPXgetsolnpoolnummipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolnummipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolnummipstarts.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolnummipstarts(env, lp);
}
int CPXgetsubstat (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsubstat) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsubstat", (gpointer *) &__symbolic_CPXgetsubstat)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsubstat could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsubstat.\n");
        }
    }
    return __symbolic_CPXgetsubstat(env, lp);
}
int CPXgetsubmethod (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsubmethod) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsubmethod", (gpointer *) &__symbolic_CPXgetsubmethod)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsubmethod could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsubmethod.\n");
        }
    }
    return __symbolic_CPXgetsubmethod(env, lp);
}
int CPXchgctype (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, const char *xctype){
    if (!__symbolic_CPXchgctype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgctype", (gpointer *) &__symbolic_CPXchgctype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgctype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgctype.\n");
        }
    }
    return __symbolic_CPXchgctype(env, lp, cnt, indices, xctype);
}
int CPXaddsos (CPXCENVptr env, CPXLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname){
    if (!__symbolic_CPXaddsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddsos", (gpointer *) &__symbolic_CPXaddsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddsos.\n");
        }
    }
    return __symbolic_CPXaddsos(env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname);
}
int CPXdelsetsos (CPXCENVptr env, CPXLPptr lp, int *delset){
    if (!__symbolic_CPXdelsetsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetsos", (gpointer *) &__symbolic_CPXdelsetsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetsos.\n");
        }
    }
    return __symbolic_CPXdelsetsos(env, lp, delset);
}
int CPXgetctype (CPXCENVptr env, CPXCLPptr lp, char *xctype, int begin, int end){
    if (!__symbolic_CPXgetctype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetctype", (gpointer *) &__symbolic_CPXgetctype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetctype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetctype.\n");
        }
    }
    return __symbolic_CPXgetctype(env, lp, xctype, begin, end);
}
int CPXgetnumsos (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumsos", (gpointer *) &__symbolic_CPXgetnumsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumsos.\n");
        }
    }
    return __symbolic_CPXgetnumsos(env, lp);
}
int CPXgetsos (CPXCENVptr env, CPXCLPptr lp, int *numsosnz_p, char *sostype, int *sosbeg, int *sosind, double *soswt, int sosspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsos", (gpointer *) &__symbolic_CPXgetsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsos.\n");
        }
    }
    return __symbolic_CPXgetsos(env, lp, numsosnz_p, sostype, sosbeg, sosind, soswt, sosspace, surplus_p, begin, end);
}
int CPXgetsosname (CPXCENVptr env, CPXCLPptr lp, char **name, char *namestore, int storespace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetsosname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsosname", (gpointer *) &__symbolic_CPXgetsosname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsosname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsosname.\n");
        }
    }
    return __symbolic_CPXgetsosname(env, lp, name, namestore, storespace, surplus_p, begin, end);
}
int CPXgetsosindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetsosindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsosindex", (gpointer *) &__symbolic_CPXgetsosindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsosindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsosindex.\n");
        }
    }
    return __symbolic_CPXgetsosindex(env, lp, lname_str, index_p);
}
int CPXgetsosinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end){
    if (!__symbolic_CPXgetsosinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsosinfeas", (gpointer *) &__symbolic_CPXgetsosinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsosinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsosinfeas.\n");
        }
    }
    return __symbolic_CPXgetsosinfeas(env, lp, x, infeasout, begin, end);
}
int CPXgetnumindconstrs (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumindconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumindconstrs", (gpointer *) &__symbolic_CPXgetnumindconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumindconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumindconstrs.\n");
        }
    }
    return __symbolic_CPXgetnumindconstrs(env, lp);
}
int CPXgetindconstr (CPXCENVptr env, CPXCLPptr lp, int *indvar_p, int *complemented_p, int *nzcnt_p, double *rhs_p, char *sense_p, int *linind, double *linval, int space, int *surplus_p, int which){
    if (!__symbolic_CPXgetindconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetindconstr", (gpointer *) &__symbolic_CPXgetindconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetindconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetindconstr.\n");
        }
    }
    return __symbolic_CPXgetindconstr(env, lp, indvar_p, complemented_p, nzcnt_p, rhs_p, sense_p, linind, linval, space, surplus_p, which);
}
int CPXEgetindicator (CPXCENVptr env, CPXCLPptr lp, int *indvar_p, int *complemented_p, int *nzcnt_p, double *rhs_p, char *sense_p, int *ind, double *val, int space, int *surplus_p, int *type_p, int which){
    if (!__symbolic_CPXEgetindicator) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetindicator", (gpointer *) &__symbolic_CPXEgetindicator)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetindicator could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetindicator.\n");
        }
    }
    return __symbolic_CPXEgetindicator(env, lp, indvar_p, complemented_p, nzcnt_p, rhs_p, sense_p, ind, val, space, surplus_p, type_p, which);
}
int CPXgetindconstrindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetindconstrindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetindconstrindex", (gpointer *) &__symbolic_CPXgetindconstrindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetindconstrindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetindconstrindex.\n");
        }
    }
    return __symbolic_CPXgetindconstrindex(env, lp, lname_str, index_p);
}
int CPXgetindconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which){
    if (!__symbolic_CPXgetindconstrname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetindconstrname", (gpointer *) &__symbolic_CPXgetindconstrname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetindconstrname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetindconstrname.\n");
        }
    }
    return __symbolic_CPXgetindconstrname(env, lp, buf_str, bufspace, surplus_p, which);
}
int CPXgetindconstrslack (CPXCENVptr env, CPXCLPptr lp, double *indslack, int begin, int end){
    if (!__symbolic_CPXgetindconstrslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetindconstrslack", (gpointer *) &__symbolic_CPXgetindconstrslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetindconstrslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetindconstrslack.\n");
        }
    }
    return __symbolic_CPXgetindconstrslack(env, lp, indslack, begin, end);
}
int CPXindconstrslackfromx (CPXCENVptr env, CPXCLPptr lp, const double *x, double *indslack){
    if (!__symbolic_CPXindconstrslackfromx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXindconstrslackfromx", (gpointer *) &__symbolic_CPXindconstrslackfromx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXindconstrslackfromx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXindconstrslackfromx.\n");
        }
    }
    return __symbolic_CPXindconstrslackfromx(env, lp, x, indslack);
}
int CPXgetindconstrinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end){
    if (!__symbolic_CPXgetindconstrinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetindconstrinfeas", (gpointer *) &__symbolic_CPXgetindconstrinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetindconstrinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetindconstrinfeas.\n");
        }
    }
    return __symbolic_CPXgetindconstrinfeas(env, lp, x, infeasout, begin, end);
}
int CPXdelindconstrs (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelindconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelindconstrs", (gpointer *) &__symbolic_CPXdelindconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelindconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelindconstrs.\n");
        }
    }
    return __symbolic_CPXdelindconstrs(env, lp, begin, end);
}
int CPXgetnumint (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumint) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumint", (gpointer *) &__symbolic_CPXgetnumint)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumint could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumint.\n");
        }
    }
    return __symbolic_CPXgetnumint(env, lp);
}
int CPXgetnumbin (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumbin) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumbin", (gpointer *) &__symbolic_CPXgetnumbin)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumbin could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumbin.\n");
        }
    }
    return __symbolic_CPXgetnumbin(env, lp);
}
int CPXgetnumsemicont (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumsemicont) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumsemicont", (gpointer *) &__symbolic_CPXgetnumsemicont)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumsemicont could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumsemicont.\n");
        }
    }
    return __symbolic_CPXgetnumsemicont(env, lp);
}
int CPXgetnumsemiint (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumsemiint) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumsemiint", (gpointer *) &__symbolic_CPXgetnumsemiint)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumsemiint could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumsemiint.\n");
        }
    }
    return __symbolic_CPXgetnumsemiint(env, lp);
}
int CPXgetorder (CPXCENVptr env, CPXCLPptr lp, int *cnt_p, int *indices, int *priority, int *direction, int ordspace, int *surplus_p){
    if (!__symbolic_CPXgetorder) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetorder", (gpointer *) &__symbolic_CPXgetorder)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetorder could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetorder.\n");
        }
    }
    return __symbolic_CPXgetorder(env, lp, cnt_p, indices, priority, direction, ordspace, surplus_p);
}
int CPXpopulate (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXpopulate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXpopulate", (gpointer *) &__symbolic_CPXpopulate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXpopulate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXpopulate.\n");
        }
    }
    return __symbolic_CPXpopulate(env, lp);
}
int CPXgetsolnpoolnumfilters (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsolnpoolnumfilters) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolnumfilters", (gpointer *) &__symbolic_CPXgetsolnpoolnumfilters)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolnumfilters could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolnumfilters.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolnumfilters(env, lp);
}
int CPXaddsolnpooldivfilter (CPXCENVptr env, CPXLPptr lp, double lower_bound, double upper_bound, int nzcnt, const int *ind, const double *weight, const double *refval, const char *lname_str){
    if (!__symbolic_CPXaddsolnpooldivfilter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddsolnpooldivfilter", (gpointer *) &__symbolic_CPXaddsolnpooldivfilter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddsolnpooldivfilter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddsolnpooldivfilter.\n");
        }
    }
    return __symbolic_CPXaddsolnpooldivfilter(env, lp, lower_bound, upper_bound, nzcnt, ind, weight, refval, lname_str);
}
int CPXaddsolnpoolrngfilter (CPXCENVptr env, CPXLPptr lp, double lb, double ub, int nzcnt, const int *ind, const double *val, const char *lname_str){
    if (!__symbolic_CPXaddsolnpoolrngfilter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddsolnpoolrngfilter", (gpointer *) &__symbolic_CPXaddsolnpoolrngfilter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddsolnpoolrngfilter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddsolnpoolrngfilter.\n");
        }
    }
    return __symbolic_CPXaddsolnpoolrngfilter(env, lp, lb, ub, nzcnt, ind, val, lname_str);
}
int CPXgetsolnpoolfiltertype (CPXCENVptr env, CPXCLPptr lp, int *ftype_p, int which){
    if (!__symbolic_CPXgetsolnpoolfiltertype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolfiltertype", (gpointer *) &__symbolic_CPXgetsolnpoolfiltertype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolfiltertype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolfiltertype.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolfiltertype(env, lp, ftype_p, which);
}
int CPXgetsolnpooldivfilter (CPXCENVptr env, CPXCLPptr lp, double *lowercutoff_p, double *upper_cutoff_p, int *nzcnt_p, int *ind, double *val, double *refval, int space, int *surplus_p, int which){
    if (!__symbolic_CPXgetsolnpooldivfilter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpooldivfilter", (gpointer *) &__symbolic_CPXgetsolnpooldivfilter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpooldivfilter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpooldivfilter.\n");
        }
    }
    return __symbolic_CPXgetsolnpooldivfilter(env, lp, lowercutoff_p, upper_cutoff_p, nzcnt_p, ind, val, refval, space, surplus_p, which);
}
int CPXgetsolnpoolfilter (CPXCENVptr env, CPXCLPptr lp, int *ftype_p, double *lowercutoff_p, double *upper_cutoff_p, int *nzcnt_p, int *ind, double *val, double *refval, int space, int *surplus_p, int which){
    if (!__symbolic_CPXgetsolnpoolfilter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolfilter", (gpointer *) &__symbolic_CPXgetsolnpoolfilter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolfilter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolfilter.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolfilter(env, lp, ftype_p, lowercutoff_p, upper_cutoff_p, nzcnt_p, ind, val, refval, space, surplus_p, which);
}
int CPXgetsolnpoolrngfilter (CPXCENVptr env, CPXCLPptr lp, double *lb_p, double *ub_p, int *nzcnt_p, int *ind, double *val, int space, int *surplus_p, int which){
    if (!__symbolic_CPXgetsolnpoolrngfilter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolrngfilter", (gpointer *) &__symbolic_CPXgetsolnpoolrngfilter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolrngfilter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolrngfilter.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolrngfilter(env, lp, lb_p, ub_p, nzcnt_p, ind, val, space, surplus_p, which);
}
int CPXgetsolnpoolfiltername (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which){
    if (!__symbolic_CPXgetsolnpoolfiltername) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolfiltername", (gpointer *) &__symbolic_CPXgetsolnpoolfiltername)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolfiltername could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolfiltername.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolfiltername(env, lp, buf_str, bufspace, surplus_p, which);
}
int CPXgetsolnpoolfilterindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetsolnpoolfilterindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolfilterindex", (gpointer *) &__symbolic_CPXgetsolnpoolfilterindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolfilterindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolfilterindex.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolfilterindex(env, lp, lname_str, index_p);
}
int CPXdelsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelsolnpoolfilters) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsolnpoolfilters", (gpointer *) &__symbolic_CPXdelsolnpoolfilters)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsolnpoolfilters could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsolnpoolfilters.\n");
        }
    }
    return __symbolic_CPXdelsolnpoolfilters(env, lp, begin, end);
}
int CPXdelsetsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int *delstat){
    if (!__symbolic_CPXdelsetsolnpoolfilters) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetsolnpoolfilters", (gpointer *) &__symbolic_CPXdelsetsolnpoolfilters)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetsolnpoolfilters could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetsolnpoolfilters.\n");
        }
    }
    return __symbolic_CPXdelsetsolnpoolfilters(env, lp, delstat);
}
int CPXgetsolnpoolnumsolns (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsolnpoolnumsolns) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolnumsolns", (gpointer *) &__symbolic_CPXgetsolnpoolnumsolns)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolnumsolns could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolnumsolns.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolnumsolns(env, lp);
}
int CPXgetsolnpoolnumreplaced (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetsolnpoolnumreplaced) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolnumreplaced", (gpointer *) &__symbolic_CPXgetsolnpoolnumreplaced)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolnumreplaced could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolnumreplaced.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolnumreplaced(env, lp);
}
int CPXgetsolnpoolmeanobjval (CPXCENVptr env, CPXCLPptr lp, double *meanobjval_p){
    if (!__symbolic_CPXgetsolnpoolmeanobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolmeanobjval", (gpointer *) &__symbolic_CPXgetsolnpoolmeanobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolmeanobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolmeanobjval.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolmeanobjval(env, lp, meanobjval_p);
}
int CPXgetsolnpoolobjval (CPXCENVptr env, CPXCLPptr lp, int soln, double *objval_p){
    if (!__symbolic_CPXgetsolnpoolobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolobjval", (gpointer *) &__symbolic_CPXgetsolnpoolobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolobjval.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolobjval(env, lp, soln, objval_p);
}
int CPXgetsolnpoolx (CPXCENVptr env, CPXCLPptr lp, int soln, double *x, int begin, int end){
    if (!__symbolic_CPXgetsolnpoolx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolx", (gpointer *) &__symbolic_CPXgetsolnpoolx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolx.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolx(env, lp, soln, x, begin, end);
}
int CPXgetsolnpoolslack (CPXCENVptr env, CPXCLPptr lp, int soln, double *slack, int begin, int end){
    if (!__symbolic_CPXgetsolnpoolslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolslack", (gpointer *) &__symbolic_CPXgetsolnpoolslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolslack.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolslack(env, lp, soln, slack, begin, end);
}
int CPXgetsolnpoolqconstrslack (CPXCENVptr env, CPXCLPptr lp, int soln, double *qcslack, int begin, int end){
    if (!__symbolic_CPXgetsolnpoolqconstrslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolqconstrslack", (gpointer *) &__symbolic_CPXgetsolnpoolqconstrslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolqconstrslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolqconstrslack.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolqconstrslack(env, lp, soln, qcslack, begin, end);
}
int CPXgetsolnpoolsolnname (CPXCENVptr env, CPXCLPptr lp, char *store, int storesz, int *surplus_p, int which){
    if (!__symbolic_CPXgetsolnpoolsolnname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolsolnname", (gpointer *) &__symbolic_CPXgetsolnpoolsolnname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolsolnname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolsolnname.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolsolnname(env, lp, store, storesz, surplus_p, which);
}
int CPXgetsolnpoolsolnindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetsolnpoolsolnindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolnpoolsolnindex", (gpointer *) &__symbolic_CPXgetsolnpoolsolnindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolnpoolsolnindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolnpoolsolnindex.\n");
        }
    }
    return __symbolic_CPXgetsolnpoolsolnindex(env, lp, lname_str, index_p);
}
int CPXdelsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelsolnpoolsolns) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsolnpoolsolns", (gpointer *) &__symbolic_CPXdelsolnpoolsolns)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsolnpoolsolns could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsolnpoolsolns.\n");
        }
    }
    return __symbolic_CPXdelsolnpoolsolns(env, lp, begin, end);
}
int CPXdelsetsolnpoolsolns (CPXCENVptr env, CPXLPptr lp, int *delstat){
    if (!__symbolic_CPXdelsetsolnpoolsolns) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelsetsolnpoolsolns", (gpointer *) &__symbolic_CPXdelsetsolnpoolsolns)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelsetsolnpoolsolns could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelsetsolnpoolsolns.\n");
        }
    }
    return __symbolic_CPXdelsetsolnpoolsolns(env, lp, delstat);
}
int CPXreadcopyorder (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopyorder) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopyorder", (gpointer *) &__symbolic_CPXreadcopyorder)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopyorder could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopyorder.\n");
        }
    }
    return __symbolic_CPXreadcopyorder(env, lp, filename_str);
}
int CPXreadcopysolnpoolfilters (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopysolnpoolfilters) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopysolnpoolfilters", (gpointer *) &__symbolic_CPXreadcopysolnpoolfilters)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopysolnpoolfilters could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopysolnpoolfilters.\n");
        }
    }
    return __symbolic_CPXreadcopysolnpoolfilters(env, lp, filename_str);
}
int CPXreadcopymipstart (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopymipstart) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopymipstart", (gpointer *) &__symbolic_CPXreadcopymipstart)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopymipstart could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopymipstart.\n");
        }
    }
    return __symbolic_CPXreadcopymipstart(env, lp, filename_str);
}
int CPXreadcopymipstarts (CPXCENVptr env, CPXLPptr lp, const char *filename_str){
    if (!__symbolic_CPXreadcopymipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXreadcopymipstarts", (gpointer *) &__symbolic_CPXreadcopymipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXreadcopymipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXreadcopymipstarts.\n");
        }
    }
    return __symbolic_CPXreadcopymipstarts(env, lp, filename_str);
}
int CPXordwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXordwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXordwrite", (gpointer *) &__symbolic_CPXordwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXordwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXordwrite.\n");
        }
    }
    return __symbolic_CPXordwrite(env, lp, filename_str);
}
int CPXmstwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXmstwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmstwrite", (gpointer *) &__symbolic_CPXmstwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmstwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmstwrite.\n");
        }
    }
    return __symbolic_CPXmstwrite(env, lp, filename_str);
}
int CPXwritemipstarts (CPXCENVptr env, CPXCLPptr lp, const char *filename_str, int begin, int end){
    if (!__symbolic_CPXwritemipstarts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXwritemipstarts", (gpointer *) &__symbolic_CPXwritemipstarts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXwritemipstarts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXwritemipstarts.\n");
        }
    }
    return __symbolic_CPXwritemipstarts(env, lp, filename_str, begin, end);
}
int CPXmstwritesolnpool (CPXCENVptr env, CPXCLPptr lp, int soln, const char *filename_str){
    if (!__symbolic_CPXmstwritesolnpool) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmstwritesolnpool", (gpointer *) &__symbolic_CPXmstwritesolnpool)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmstwritesolnpool could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmstwritesolnpool.\n");
        }
    }
    return __symbolic_CPXmstwritesolnpool(env, lp, soln, filename_str);
}
int CPXmstwritesolnpoolall (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXmstwritesolnpoolall) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXmstwritesolnpoolall", (gpointer *) &__symbolic_CPXmstwritesolnpoolall)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXmstwritesolnpoolall could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXmstwritesolnpoolall.\n");
        }
    }
    return __symbolic_CPXmstwritesolnpoolall(env, lp, filename_str);
}
int CPXfltwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str){
    if (!__symbolic_CPXfltwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfltwrite", (gpointer *) &__symbolic_CPXfltwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfltwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfltwrite.\n");
        }
    }
    return __symbolic_CPXfltwrite(env, lp, filename_str);
}
int CPXcheckcopyctype (CPXCENVptr env, CPXCLPptr lp, const char *xctype){
    if (!__symbolic_CPXcheckcopyctype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopyctype", (gpointer *) &__symbolic_CPXcheckcopyctype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopyctype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopyctype.\n");
        }
    }
    return __symbolic_CPXcheckcopyctype(env, lp, xctype);
}
int CPXcheckcopysos (CPXCENVptr env, CPXCLPptr lp, int numsos, int numsosnz, const char *sostype, const int *sosbeg, const int *sosind, const double *soswt, char **sosname){
    if (!__symbolic_CPXcheckcopysos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopysos", (gpointer *) &__symbolic_CPXcheckcopysos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopysos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopysos.\n");
        }
    }
    return __symbolic_CPXcheckcopysos(env, lp, numsos, numsosnz, sostype, sosbeg, sosind, soswt, sosname);
}
int CPXEchgsosname (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXEchgsosname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEchgsosname", (gpointer *) &__symbolic_CPXEchgsosname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEchgsosname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEchgsosname.\n");
        }
    }
    return __symbolic_CPXEchgsosname(env, lp, cnt, indices, newname);
}
int CPXsetinfocallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle){
    if (!__symbolic_CPXsetinfocallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetinfocallbackfunc", (gpointer *) &__symbolic_CPXsetinfocallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetinfocallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetinfocallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetinfocallbackfunc(env, callback, cbhandle);
}
int CPXgetinfocallbackfunc (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p){
    if (!__symbolic_CPXgetinfocallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetinfocallbackfunc", (gpointer *) &__symbolic_CPXgetinfocallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetinfocallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetinfocallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetinfocallbackfunc(env, callback_p, cbhandle_p);
}
int CPXsetmipcallbackfunc (CPXENVptr env, int ( * callback) (CPXCENVptr, void *, int, void *), void *cbhandle){
    if (!__symbolic_CPXsetmipcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetmipcallbackfunc", (gpointer *) &__symbolic_CPXsetmipcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetmipcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetmipcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetmipcallbackfunc(env, callback, cbhandle);
}
int CPXgetmipcallbackfunc (CPXCENVptr env, int ( ** callback_p) (CPXCENVptr, void *, int, void *), void **cbhandle_p){
    if (!__symbolic_CPXgetmipcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetmipcallbackfunc", (gpointer *) &__symbolic_CPXgetmipcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetmipcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetmipcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetmipcallbackfunc(env, callback_p, cbhandle_p);
}
int CPXsetbranchcallbackfunc (CPXENVptr env, int ( * branchcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void *cbhandle){
    if (!__symbolic_CPXsetbranchcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetbranchcallbackfunc", (gpointer *) &__symbolic_CPXsetbranchcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetbranchcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetbranchcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetbranchcallbackfunc(env, branchcallback, cbhandle);
}
int CPXsetbranchnosolncallbackfunc (CPXENVptr env, int ( * branchnosolncallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void *cbhandle){
    if (!__symbolic_CPXsetbranchnosolncallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetbranchnosolncallbackfunc", (gpointer *) &__symbolic_CPXsetbranchnosolncallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetbranchnosolncallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetbranchnosolncallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetbranchnosolncallbackfunc(env, branchnosolncallback, cbhandle);
}
int CPXsetcutcallbackfunc (CPXENVptr env, int ( * cutcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction_p), void *cbhandle){
    if (!__symbolic_CPXsetcutcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetcutcallbackfunc", (gpointer *) &__symbolic_CPXsetcutcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetcutcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetcutcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetcutcallbackfunc(env, cutcallback, cbhandle);
}
int CPXsetnodecallbackfunc (CPXENVptr env, int ( * nodecallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *nodeindex, int *useraction), void *cbhandle){
    if (!__symbolic_CPXsetnodecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetnodecallbackfunc", (gpointer *) &__symbolic_CPXsetnodecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetnodecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetnodecallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetnodecallbackfunc(env, nodecallback, cbhandle);
}
int CPXsetheuristiccallbackfunc (CPXENVptr env, int ( * heuristiccallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double *objval_p, double *x, int *checkfeas_p, int *useraction_p), void *cbhandle){
    if (!__symbolic_CPXsetheuristiccallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetheuristiccallbackfunc", (gpointer *) &__symbolic_CPXsetheuristiccallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetheuristiccallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetheuristiccallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetheuristiccallbackfunc(env, heuristiccallback, cbhandle);
}
int CPXsetincumbentcallbackfunc (CPXENVptr env, int ( * incumbentcallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double objval, double *x, int *isfeas_p, int *useraction_p), void *cbhandle){
    if (!__symbolic_CPXsetincumbentcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetincumbentcallbackfunc", (gpointer *) &__symbolic_CPXsetincumbentcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetincumbentcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetincumbentcallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetincumbentcallbackfunc(env, incumbentcallback, cbhandle);
}
int CPXsetsolvecallbackfunc (CPXENVptr env, int ( * solvecallback) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction), void *cbhandle){
    if (!__symbolic_CPXsetsolvecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetsolvecallbackfunc", (gpointer *) &__symbolic_CPXsetsolvecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetsolvecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetsolvecallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetsolvecallbackfunc(env, solvecallback, cbhandle);
}
int CPXsetdeletenodecallbackfunc (CPXENVptr env, void ( * deletecallback) (CPXCENVptr xenv, int wherefrom, void *cbhandle, int seqnum, void *handle), void *cbhandle){
    if (!__symbolic_CPXsetdeletenodecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXsetdeletenodecallbackfunc", (gpointer *) &__symbolic_CPXsetdeletenodecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXsetdeletenodecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXsetdeletenodecallbackfunc.\n");
        }
    }
    return __symbolic_CPXsetdeletenodecallbackfunc(env, deletecallback, cbhandle);
}
void CPXgetbranchcallbackfunc (CPXCENVptr env, int ( ** branchcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void **cbhandle_p){
    if (!__symbolic_CPXgetbranchcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbranchcallbackfunc", (gpointer *) &__symbolic_CPXgetbranchcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbranchcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbranchcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetbranchcallbackfunc(env, branchcallback_p, cbhandle_p);
}
void CPXgetbranchnosolncallbackfunc (CPXCENVptr env, int ( ** branchnosolncallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int brtype, int brset, int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg, const int *xindex, const char *lu, const int *bd, int *useraction_p), void **cbhandle_p){
    if (!__symbolic_CPXgetbranchnosolncallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetbranchnosolncallbackfunc", (gpointer *) &__symbolic_CPXgetbranchnosolncallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetbranchnosolncallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetbranchnosolncallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetbranchnosolncallbackfunc(env, branchnosolncallback_p, cbhandle_p);
}
void CPXgetcutcallbackfunc (CPXCENVptr env, int ( ** cutcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction_p), void **cbhandle_p){
    if (!__symbolic_CPXgetcutcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcutcallbackfunc", (gpointer *) &__symbolic_CPXgetcutcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcutcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcutcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetcutcallbackfunc(env, cutcallback_p, cbhandle_p);
}
void CPXgetnodecallbackfunc (CPXCENVptr env, int ( ** nodecallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *nodeindex, int *useraction), void **cbhandle_p){
    if (!__symbolic_CPXgetnodecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnodecallbackfunc", (gpointer *) &__symbolic_CPXgetnodecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnodecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnodecallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetnodecallbackfunc(env, nodecallback_p, cbhandle_p);
}
void CPXgetheuristiccallbackfunc (CPXCENVptr env, int ( ** heuristiccallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double *objval_p, double *x, int *checkfeas_p, int *useraction_p), void **cbhandle_p){
    if (!__symbolic_CPXgetheuristiccallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetheuristiccallbackfunc", (gpointer *) &__symbolic_CPXgetheuristiccallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetheuristiccallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetheuristiccallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetheuristiccallbackfunc(env, heuristiccallback_p, cbhandle_p);
}
void CPXgetincumbentcallbackfunc (CPXCENVptr env, int ( ** incumbentcallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, double objval, double *x, int *isfeas_p, int *useraction_p), void **cbhandle_p){
    if (!__symbolic_CPXgetincumbentcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetincumbentcallbackfunc", (gpointer *) &__symbolic_CPXgetincumbentcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetincumbentcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetincumbentcallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetincumbentcallbackfunc(env, incumbentcallback_p, cbhandle_p);
}
void CPXgetsolvecallbackfunc (CPXCENVptr env, int ( ** solvecallback_p) (CPXCENVptr xenv, void *cbdata, int wherefrom, void *cbhandle, int *useraction), void **cbhandle_p){
    if (!__symbolic_CPXgetsolvecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetsolvecallbackfunc", (gpointer *) &__symbolic_CPXgetsolvecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetsolvecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetsolvecallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetsolvecallbackfunc(env, solvecallback_p, cbhandle_p);
}
void CPXgetdeletenodecallbackfunc (CPXCENVptr env, void ( ** deletecallback_p) (CPXCENVptr xenv, int wherefrom, void *cbhandle, int seqnum, void *handle), void **cbhandle_p){
    if (!__symbolic_CPXgetdeletenodecallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetdeletenodecallbackfunc", (gpointer *) &__symbolic_CPXgetdeletenodecallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetdeletenodecallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetdeletenodecallbackfunc.\n");
        }
    }
    return __symbolic_CPXgetdeletenodecallbackfunc(env, deletecallback_p, cbhandle_p);
}
int CPXgetcallbacknodelp (CPXCENVptr env, void *cbdata, int wherefrom, CPXLPptr * nodelp_p){
    if (!__symbolic_CPXgetcallbacknodelp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodelp", (gpointer *) &__symbolic_CPXgetcallbacknodelp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodelp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodelp.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodelp(env, cbdata, wherefrom, nodelp_p);
}
int CPXgetcallbacknodeinfo (CPXCENVptr env, void *cbdata, int wherefrom, int nodeindex, int whichinfo, void *result_p){
    if (!__symbolic_CPXgetcallbacknodeinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodeinfo", (gpointer *) &__symbolic_CPXgetcallbacknodeinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodeinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodeinfo.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodeinfo(env, cbdata, wherefrom, nodeindex, whichinfo, result_p);
}
int CPXgetcallbackseqinfo (CPXCENVptr env, void *cbdata, int wherefrom, int seqid, int whichinfo, void *result_p){
    if (!__symbolic_CPXgetcallbackseqinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackseqinfo", (gpointer *) &__symbolic_CPXgetcallbackseqinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackseqinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackseqinfo.\n");
        }
    }
    return __symbolic_CPXgetcallbackseqinfo(env, cbdata, wherefrom, seqid, whichinfo, result_p);
}
int CPXgetcallbacksosinfo (CPXCENVptr env, void *cbdata, int wherefrom, int sosindex, int member, int whichinfo, void *result_p){
    if (!__symbolic_CPXgetcallbacksosinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacksosinfo", (gpointer *) &__symbolic_CPXgetcallbacksosinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacksosinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacksosinfo.\n");
        }
    }
    return __symbolic_CPXgetcallbacksosinfo(env, cbdata, wherefrom, sosindex, member, whichinfo, result_p);
}
int CPXgetcallbackindicatorinfo (CPXCENVptr env, void *cbdata, int wherefrom, int iindex, int whichinfo, void *result_p){
    if (!__symbolic_CPXgetcallbackindicatorinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackindicatorinfo", (gpointer *) &__symbolic_CPXgetcallbackindicatorinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackindicatorinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackindicatorinfo.\n");
        }
    }
    return __symbolic_CPXgetcallbackindicatorinfo(env, cbdata, wherefrom, iindex, whichinfo, result_p);
}
int CPXcutcallbackadd (CPXCENVptr env, void *cbdata, int wherefrom, int nzcnt, double rhs, int sense, const int *cutind, const double *cutval, int purgeable){
    if (!__symbolic_CPXcutcallbackadd) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcutcallbackadd", (gpointer *) &__symbolic_CPXcutcallbackadd)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcutcallbackadd could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcutcallbackadd.\n");
        }
    }
    return __symbolic_CPXcutcallbackadd(env, cbdata, wherefrom, nzcnt, rhs, sense, cutind, cutval, purgeable);
}
int CPXcutcallbackaddlocal (CPXCENVptr env, void *cbdata, int wherefrom, int nzcnt, double rhs, int sense, const int *cutind, const double *cutval){
    if (!__symbolic_CPXcutcallbackaddlocal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcutcallbackaddlocal", (gpointer *) &__symbolic_CPXcutcallbackaddlocal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcutcallbackaddlocal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcutcallbackaddlocal.\n");
        }
    }
    return __symbolic_CPXcutcallbackaddlocal(env, cbdata, wherefrom, nzcnt, rhs, sense, cutind, cutval);
}
int CPXbranchcallbackbranchbds (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int cnt, const int *indices, const char *lu, const int *bd, void *userhandle, int *seqnum_p){
    if (!__symbolic_CPXbranchcallbackbranchbds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbranchcallbackbranchbds", (gpointer *) &__symbolic_CPXbranchcallbackbranchbds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbranchcallbackbranchbds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbranchcallbackbranchbds.\n");
        }
    }
    return __symbolic_CPXbranchcallbackbranchbds(env, cbdata, wherefrom, nodeest, cnt, indices, lu, bd, userhandle, seqnum_p);
}
int CPXbranchcallbackbranchgeneral (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int varcnt, const int *varind, const char *varlu, const int *varbd, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, void *userhandle, int *seqnum_p){
    if (!__symbolic_CPXbranchcallbackbranchgeneral) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbranchcallbackbranchgeneral", (gpointer *) &__symbolic_CPXbranchcallbackbranchgeneral)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbranchcallbackbranchgeneral could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbranchcallbackbranchgeneral.\n");
        }
    }
    return __symbolic_CPXbranchcallbackbranchgeneral(env, cbdata, wherefrom, nodeest, varcnt, varind, varlu, varbd, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, userhandle, seqnum_p);
}
int CPXbranchcallbackbranchconstraints (CPXCENVptr env, void *cbdata, int wherefrom, double nodeest, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, void *userhandle, int *seqnum_p){
    if (!__symbolic_CPXbranchcallbackbranchconstraints) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXbranchcallbackbranchconstraints", (gpointer *) &__symbolic_CPXbranchcallbackbranchconstraints)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXbranchcallbackbranchconstraints could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXbranchcallbackbranchconstraints.\n");
        }
    }
    return __symbolic_CPXbranchcallbackbranchconstraints(env, cbdata, wherefrom, nodeest, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, userhandle, seqnum_p);
}
int CPXgetcallbacknodex (CPXCENVptr env, void *cbdata, int wherefrom, double *x, int begin, int end){
    if (!__symbolic_CPXgetcallbacknodex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodex", (gpointer *) &__symbolic_CPXgetcallbacknodex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodex.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodex(env, cbdata, wherefrom, x, begin, end);
}
int CPXgetcallbacknodeobjval (CPXCENVptr env, void *cbdata, int wherefrom, double *objval_p){
    if (!__symbolic_CPXgetcallbacknodeobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodeobjval", (gpointer *) &__symbolic_CPXgetcallbacknodeobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodeobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodeobjval.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodeobjval(env, cbdata, wherefrom, objval_p);
}
int CPXgetcallbackctype (CPXCENVptr env, void *cbdata, int wherefrom, char *xctype, int begin, int end){
    if (!__symbolic_CPXgetcallbackctype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackctype", (gpointer *) &__symbolic_CPXgetcallbackctype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackctype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackctype.\n");
        }
    }
    return __symbolic_CPXgetcallbackctype(env, cbdata, wherefrom, xctype, begin, end);
}
int CPXgetcallbackorder (CPXCENVptr env, void *cbdata, int wherefrom, int *priority, int *direction, int begin, int end){
    if (!__symbolic_CPXgetcallbackorder) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackorder", (gpointer *) &__symbolic_CPXgetcallbackorder)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackorder could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackorder.\n");
        }
    }
    return __symbolic_CPXgetcallbackorder(env, cbdata, wherefrom, priority, direction, begin, end);
}
int CPXgetcallbackpseudocosts (CPXCENVptr env, void *cbdata, int wherefrom, double *uppc, double *downpc, int begin, int end){
    if (!__symbolic_CPXgetcallbackpseudocosts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackpseudocosts", (gpointer *) &__symbolic_CPXgetcallbackpseudocosts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackpseudocosts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackpseudocosts.\n");
        }
    }
    return __symbolic_CPXgetcallbackpseudocosts(env, cbdata, wherefrom, uppc, downpc, begin, end);
}
int CPXgetcallbackincumbent (CPXCENVptr env, void *cbdata, int wherefrom, double *x, int begin, int end){
    if (!__symbolic_CPXgetcallbackincumbent) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackincumbent", (gpointer *) &__symbolic_CPXgetcallbackincumbent)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackincumbent could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackincumbent.\n");
        }
    }
    return __symbolic_CPXgetcallbackincumbent(env, cbdata, wherefrom, x, begin, end);
}
int CPXgetcallbacknodeintfeas (CPXCENVptr env, void *cbdata, int wherefrom, int *feas, int begin, int end){
    if (!__symbolic_CPXgetcallbacknodeintfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodeintfeas", (gpointer *) &__symbolic_CPXgetcallbacknodeintfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodeintfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodeintfeas.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodeintfeas(env, cbdata, wherefrom, feas, begin, end);
}
int CPXgetcallbackgloballb (CPXCENVptr env, void *cbdata, int wherefrom, double *lb, int begin, int end){
    if (!__symbolic_CPXgetcallbackgloballb) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackgloballb", (gpointer *) &__symbolic_CPXgetcallbackgloballb)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackgloballb could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackgloballb.\n");
        }
    }
    return __symbolic_CPXgetcallbackgloballb(env, cbdata, wherefrom, lb, begin, end);
}
int CPXgetcallbackglobalub (CPXCENVptr env, void *cbdata, int wherefrom, double *ub, int begin, int end){
    if (!__symbolic_CPXgetcallbackglobalub) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackglobalub", (gpointer *) &__symbolic_CPXgetcallbackglobalub)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackglobalub could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackglobalub.\n");
        }
    }
    return __symbolic_CPXgetcallbackglobalub(env, cbdata, wherefrom, ub, begin, end);
}
int CPXgetcallbacknodelb (CPXCENVptr env, void *cbdata, int wherefrom, double *lb, int begin, int end){
    if (!__symbolic_CPXgetcallbacknodelb) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodelb", (gpointer *) &__symbolic_CPXgetcallbacknodelb)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodelb could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodelb.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodelb(env, cbdata, wherefrom, lb, begin, end);
}
int CPXgetcallbacknodeub (CPXCENVptr env, void *cbdata, int wherefrom, double *ub, int begin, int end){
    if (!__symbolic_CPXgetcallbacknodeub) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodeub", (gpointer *) &__symbolic_CPXgetcallbacknodeub)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodeub could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodeub.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodeub(env, cbdata, wherefrom, ub, begin, end);
}
int CPXgetcallbacklp (CPXCENVptr env, void *cbdata, int wherefrom, CPXCLPptr * lp_p){
    if (!__symbolic_CPXgetcallbacklp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacklp", (gpointer *) &__symbolic_CPXgetcallbacklp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacklp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacklp.\n");
        }
    }
    return __symbolic_CPXgetcallbacklp(env, cbdata, wherefrom, lp_p);
}
int CPXgetcallbacknodestat (CPXCENVptr env, void *cbdata, int wherefrom, int *nodestat_p){
    if (!__symbolic_CPXgetcallbacknodestat) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbacknodestat", (gpointer *) &__symbolic_CPXgetcallbacknodestat)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbacknodestat could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbacknodestat.\n");
        }
    }
    return __symbolic_CPXgetcallbacknodestat(env, cbdata, wherefrom, nodestat_p);
}
int CPXgetcallbackbranchconstraints (CPXCENVptr env, void *cbdata, int wherefrom, int which, int *cuts_p, int *nzcnt_p, double *rhs, char *sense, int *rmatbeg, int *rmatind, double *rmatval, int rmatsz, int *surplus_p){
    if (!__symbolic_CPXgetcallbackbranchconstraints) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetcallbackbranchconstraints", (gpointer *) &__symbolic_CPXgetcallbackbranchconstraints)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetcallbackbranchconstraints could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetcallbackbranchconstraints.\n");
        }
    }
    return __symbolic_CPXgetcallbackbranchconstraints(env, cbdata, wherefrom, which, cuts_p, nzcnt_p, rhs, sense, rmatbeg, rmatind, rmatval, rmatsz, surplus_p);
}
int CPXaddusercuts (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname){
    if (!__symbolic_CPXaddusercuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddusercuts", (gpointer *) &__symbolic_CPXaddusercuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddusercuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddusercuts.\n");
        }
    }
    return __symbolic_CPXaddusercuts(env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}
int CPXaddlazyconstraints (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt, const double *rhs, const char *sense, const int *rmatbeg, const int *rmatind, const double *rmatval, char **rowname){
    if (!__symbolic_CPXaddlazyconstraints) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddlazyconstraints", (gpointer *) &__symbolic_CPXaddlazyconstraints)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddlazyconstraints could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddlazyconstraints.\n");
        }
    }
    return __symbolic_CPXaddlazyconstraints(env, lp, rcnt, nzcnt, rhs, sense, rmatbeg, rmatind, rmatval, rowname);
}
int CPXfreeusercuts (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXfreeusercuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfreeusercuts", (gpointer *) &__symbolic_CPXfreeusercuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfreeusercuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfreeusercuts.\n");
        }
    }
    return __symbolic_CPXfreeusercuts(env, lp);
}
int CPXfreelazyconstraints (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXfreelazyconstraints) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXfreelazyconstraints", (gpointer *) &__symbolic_CPXfreelazyconstraints)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXfreelazyconstraints could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXfreelazyconstraints.\n");
        }
    }
    return __symbolic_CPXfreelazyconstraints(env, lp);
}
int CPXEgetusercuts (CPXCENVptr env, CPXCLPptr lp, int *rcnt_p, int *nzcnt_p, double **zrhs_p, char **zsense_p, int **rmatbeg_p, int **rmatind_p, double **rmatval_p){
    if (!__symbolic_CPXEgetusercuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetusercuts", (gpointer *) &__symbolic_CPXEgetusercuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetusercuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetusercuts.\n");
        }
    }
    return __symbolic_CPXEgetusercuts(env, lp, rcnt_p, nzcnt_p, zrhs_p, zsense_p, rmatbeg_p, rmatind_p, rmatval_p);
}
int CPXEgetusercutname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which){
    if (!__symbolic_CPXEgetusercutname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetusercutname", (gpointer *) &__symbolic_CPXEgetusercutname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetusercutname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetusercutname.\n");
        }
    }
    return __symbolic_CPXEgetusercutname(env, lp, buf_str, bufspace, surplus_p, which);
}
int CPXEgetlazyconstraints (CPXCENVptr env, CPXCLPptr lp, int *rcnt_p, int *nzcnt_p, double **zrhs_p, char **zsense_p, int **rmatbeg_p, int **rmatind_p, double **rmatval_p){
    if (!__symbolic_CPXEgetlazyconstraints) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetlazyconstraints", (gpointer *) &__symbolic_CPXEgetlazyconstraints)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetlazyconstraints could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetlazyconstraints.\n");
        }
    }
    return __symbolic_CPXEgetlazyconstraints(env, lp, rcnt_p, nzcnt_p, zrhs_p, zsense_p, rmatbeg_p, rmatind_p, rmatval_p);
}
int CPXEgetlazyconstraintname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which){
    if (!__symbolic_CPXEgetlazyconstraintname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetlazyconstraintname", (gpointer *) &__symbolic_CPXEgetlazyconstraintname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetlazyconstraintname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetlazyconstraintname.\n");
        }
    }
    return __symbolic_CPXEgetlazyconstraintname(env, lp, buf_str, bufspace, surplus_p, which);
}
int CPXordread (CPXCENVptr env, const char *filename_str, int numcols, char **colname, int *cnt_p, int *indices, int *priority, int *direction){
    if (!__symbolic_CPXordread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXordread", (gpointer *) &__symbolic_CPXordread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXordread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXordread.\n");
        }
    }
    return __symbolic_CPXordread(env, filename_str, numcols, colname, cnt_p, indices, priority, direction);
}
int CPXaddindconstr (CPXCENVptr env, CPXLPptr lp, int indvar, int complemented, int nzcnt, double rhs, int sense, const int *linind, const double *linval, const char *indname_str){
    if (!__symbolic_CPXaddindconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddindconstr", (gpointer *) &__symbolic_CPXaddindconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddindconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddindconstr.\n");
        }
    }
    return __symbolic_CPXaddindconstr(env, lp, indvar, complemented, nzcnt, rhs, sense, linind, linval, indname_str);
}
int CPXEgetnumgconstrs (CPXCENVptr env, CPXCLPptr lp, int contype){
    if (!__symbolic_CPXEgetnumgconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetnumgconstrs", (gpointer *) &__symbolic_CPXEgetnumgconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetnumgconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetnumgconstrs.\n");
        }
    }
    return __symbolic_CPXEgetnumgconstrs(env, lp, contype);
}
int CPXEdelgconstrs (CPXCENVptr env, CPXLPptr lp, int contype, int beg, int end){
    if (!__symbolic_CPXEdelgconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEdelgconstrs", (gpointer *) &__symbolic_CPXEdelgconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEdelgconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEdelgconstrs.\n");
        }
    }
    return __symbolic_CPXEdelgconstrs(env, lp, contype, beg, end);
}
int CPXEaddindconstr (CPXCENVptr env, CPXLPptr lp, int indicator, int complemented, int linnzcnt, double rhs, int sense, const int *linind, const double *linval, int type, const char *lname_str){
    if (!__symbolic_CPXEaddindconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddindconstr", (gpointer *) &__symbolic_CPXEaddindconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddindconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddindconstr.\n");
        }
    }
    return __symbolic_CPXEaddindconstr(env, lp, indicator, complemented, linnzcnt, rhs, sense, linind, linval, type, lname_str);
}
int CPXEaddminexpr (CPXCENVptr env, CPXLPptr lp, int y, double constant, int nexpr, int nnz, const int *matbeg, const int *matind, const double *matval, const char *lname_str){
    if (!__symbolic_CPXEaddminexpr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddminexpr", (gpointer *) &__symbolic_CPXEaddminexpr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddminexpr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddminexpr.\n");
        }
    }
    return __symbolic_CPXEaddminexpr(env, lp, y, constant, nexpr, nnz, matbeg, matind, matval, lname_str);
}
int CPXEaddmaxexpr (CPXCENVptr env, CPXLPptr lp, int y, double constant, int nexpr, int nnz, const int *matbeg, const int *matind, const double *matval, const char *lname_str){
    if (!__symbolic_CPXEaddmaxexpr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddmaxexpr", (gpointer *) &__symbolic_CPXEaddmaxexpr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddmaxexpr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddmaxexpr.\n");
        }
    }
    return __symbolic_CPXEaddmaxexpr(env, lp, y, constant, nexpr, nnz, matbeg, matind, matval, lname_str);
}
int CPXEaddpwl (CPXCENVptr env, CPXLPptr lp, int y, int npoints, double *point, int nslopes, double *slope, double a, double b, int x, const char *lname_str){
    if (!__symbolic_CPXEaddpwl) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddpwl", (gpointer *) &__symbolic_CPXEaddpwl)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddpwl could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddpwl.\n");
        }
    }
    return __symbolic_CPXEaddpwl(env, lp, y, npoints, point, nslopes, slope, a, b, x, lname_str);
}
int CPXEaddabs (CPXCENVptr env, CPXLPptr lp, int y, int x, const char *lname_str){
    if (!__symbolic_CPXEaddabs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddabs", (gpointer *) &__symbolic_CPXEaddabs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddabs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddabs.\n");
        }
    }
    return __symbolic_CPXEaddabs(env, lp, y, x, lname_str);
}
int CPXEaddsetvar (CPXCENVptr env, CPXLPptr lp, const int npvalues, const double *pvalues, const int nrvalues, const double *rvalues, const char *lname_str){
    if (!__symbolic_CPXEaddsetvar) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvar", (gpointer *) &__symbolic_CPXEaddsetvar)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvar could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvar.\n");
        }
    }
    return __symbolic_CPXEaddsetvar(env, lp, npvalues, pvalues, nrvalues, rvalues, lname_str);
}
int CPXEchgsetvar (CPXCENVptr env, CPXLPptr lp, const int setvarid, const int npvalues, const double *pvalues, const int nrvalues, const double *rvalues){
    if (!__symbolic_CPXEchgsetvar) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEchgsetvar", (gpointer *) &__symbolic_CPXEchgsetvar)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEchgsetvar could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEchgsetvar.\n");
        }
    }
    return __symbolic_CPXEchgsetvar(env, lp, setvarid, npvalues, pvalues, nrvalues, rvalues);
}
int CPXEgetsetvarvalues (CPXCENVptr env, CPXLPptr lp, const int setvarid, const int nvalues, const int *values, int *soln){
    if (!__symbolic_CPXEgetsetvarvalues) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEgetsetvarvalues", (gpointer *) &__symbolic_CPXEgetsetvarvalues)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEgetsetvarvalues could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEgetsetvarvalues.\n");
        }
    }
    return __symbolic_CPXEgetsetvarvalues(env, lp, setvarid, nvalues, values, soln);
}
int CPXEaddsetvarmember (CPXCENVptr env, CPXLPptr lp, const int indvarid, const int setvarid, const double value, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarmember) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarmember", (gpointer *) &__symbolic_CPXEaddsetvarmember)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarmember could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarmember.\n");
        }
    }
    return __symbolic_CPXEaddsetvarmember(env, lp, indvarid, setvarid, value, lname_str);
}
int CPXEaddsetvarcard (CPXCENVptr env, CPXLPptr lp, const int cardvarid, const int setvarid, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarcard) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarcard", (gpointer *) &__symbolic_CPXEaddsetvarcard)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarcard could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarcard.\n");
        }
    }
    return __symbolic_CPXEaddsetvarcard(env, lp, cardvarid, setvarid, lname_str);
}
int CPXEaddsetvarsum (CPXCENVptr env, CPXLPptr lp, const int sumvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarsum) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarsum", (gpointer *) &__symbolic_CPXEaddsetvarsum)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarsum could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarsum.\n");
        }
    }
    return __symbolic_CPXEaddsetvarsum(env, lp, sumvarid, setvarid, nvalues, vals, lname_str);
}
int CPXEaddsetvarmin (CPXCENVptr env, CPXLPptr lp, const int minvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarmin) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarmin", (gpointer *) &__symbolic_CPXEaddsetvarmin)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarmin could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarmin.\n");
        }
    }
    return __symbolic_CPXEaddsetvarmin(env, lp, minvarid, setvarid, nvalues, vals, lname_str);
}
int CPXEaddsetvarmax (CPXCENVptr env, CPXLPptr lp, const int maxvarid, const int setvarid, const int nvalues, const double *vals, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarmax) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarmax", (gpointer *) &__symbolic_CPXEaddsetvarmax)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarmax could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarmax.\n");
        }
    }
    return __symbolic_CPXEaddsetvarmax(env, lp, maxvarid, setvarid, nvalues, vals, lname_str);
}
int CPXEaddsetvarsubset (CPXCENVptr env, CPXLPptr lp, const int setvar1, const int setvar2, const int strict, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarsubset) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarsubset", (gpointer *) &__symbolic_CPXEaddsetvarsubset)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarsubset could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarsubset.\n");
        }
    }
    return __symbolic_CPXEaddsetvarsubset(env, lp, setvar1, setvar2, strict, lname_str);
}
int CPXEaddsetvardomain (CPXCENVptr env, CPXLPptr lp, const int setvar, const int nvalues, const double *values, const int possible, const int required, const int forbidden, const int strict, const char *lname_str){
    if (!__symbolic_CPXEaddsetvardomain) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvardomain", (gpointer *) &__symbolic_CPXEaddsetvardomain)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvardomain could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvardomain.\n");
        }
    }
    return __symbolic_CPXEaddsetvardomain(env, lp, setvar, nvalues, values, possible, required, forbidden, strict, lname_str);
}
int CPXEaddsetvarunion (CPXCENVptr env, CPXLPptr lp, const int unionsetvar, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarunion) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarunion", (gpointer *) &__symbolic_CPXEaddsetvarunion)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarunion could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarunion.\n");
        }
    }
    return __symbolic_CPXEaddsetvarunion(env, lp, unionsetvar, servar1, setvar2, lname_str);
}
int CPXEaddsetvarintersection (CPXCENVptr env, CPXLPptr lp, const int unionsetvar, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarintersection) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarintersection", (gpointer *) &__symbolic_CPXEaddsetvarintersection)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarintersection could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarintersection.\n");
        }
    }
    return __symbolic_CPXEaddsetvarintersection(env, lp, unionsetvar, servar1, setvar2, lname_str);
}
int CPXEaddsetvarnullintersect (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarnullintersect) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarnullintersect", (gpointer *) &__symbolic_CPXEaddsetvarnullintersect)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarnullintersect could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarnullintersect.\n");
        }
    }
    return __symbolic_CPXEaddsetvarnullintersect(env, lp, servar1, setvar2, lname_str);
}
int CPXEaddsetvarintersect (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarintersect) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarintersect", (gpointer *) &__symbolic_CPXEaddsetvarintersect)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarintersect could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarintersect.\n");
        }
    }
    return __symbolic_CPXEaddsetvarintersect(env, lp, servar1, setvar2, lname_str);
}
int CPXEaddsetvareq (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvareq) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvareq", (gpointer *) &__symbolic_CPXEaddsetvareq)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvareq could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvareq.\n");
        }
    }
    return __symbolic_CPXEaddsetvareq(env, lp, servar1, setvar2, lname_str);
}
int CPXEaddsetvarneq (CPXCENVptr env, CPXLPptr lp, const int servar1, const int setvar2, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarneq) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarneq", (gpointer *) &__symbolic_CPXEaddsetvarneq)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarneq could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarneq.\n");
        }
    }
    return __symbolic_CPXEaddsetvarneq(env, lp, servar1, setvar2, lname_str);
}
int CPXEaddsetvarneqcst (CPXCENVptr env, CPXLPptr lp, const int servar1, const int nvalues, const double *values, const char *lname_str){
    if (!__symbolic_CPXEaddsetvarneqcst) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEaddsetvarneqcst", (gpointer *) &__symbolic_CPXEaddsetvarneqcst)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEaddsetvarneqcst could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEaddsetvarneqcst.\n");
        }
    }
    return __symbolic_CPXEaddsetvarneqcst(env, lp, servar1, nvalues, values, lname_str);
}
CPXNETptr CPXNETcreateprob (CPXENVptr env, int *status_p, const char *name_str){
    if (!__symbolic_CPXNETcreateprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETcreateprob", (gpointer *) &__symbolic_CPXNETcreateprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETcreateprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETcreateprob.\n");
        }
    }
    return __symbolic_CPXNETcreateprob(env, status_p, name_str);
}
int CPXNETfreeprob (CPXENVptr env, CPXNETptr * net_p){
    if (!__symbolic_CPXNETfreeprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETfreeprob", (gpointer *) &__symbolic_CPXNETfreeprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETfreeprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETfreeprob.\n");
        }
    }
    return __symbolic_CPXNETfreeprob(env, net_p);
}
int CPXNETcopynet (CPXCENVptr env, CPXNETptr net, int objsen, int nnodes, const double *supply, char **nnames, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **anames){
    if (!__symbolic_CPXNETcopynet) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETcopynet", (gpointer *) &__symbolic_CPXNETcopynet)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETcopynet could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETcopynet.\n");
        }
    }
    return __symbolic_CPXNETcopynet(env, net, objsen, nnodes, supply, nnames, narcs, fromnode, tonode, low, up, obj, anames);
}
int CPXNETcopybase (CPXCENVptr env, CPXNETptr net, const int *astat, const int *nstat){
    if (!__symbolic_CPXNETcopybase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETcopybase", (gpointer *) &__symbolic_CPXNETcopybase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETcopybase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETcopybase.\n");
        }
    }
    return __symbolic_CPXNETcopybase(env, net, astat, nstat);
}
int CPXNETaddnodes (CPXCENVptr env, CPXNETptr net, int nnodes, const double *supply, char **name){
    if (!__symbolic_CPXNETaddnodes) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETaddnodes", (gpointer *) &__symbolic_CPXNETaddnodes)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETaddnodes could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETaddnodes.\n");
        }
    }
    return __symbolic_CPXNETaddnodes(env, net, nnodes, supply, name);
}
int CPXNETaddarcs (CPXCENVptr env, CPXNETptr net, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **anames){
    if (!__symbolic_CPXNETaddarcs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETaddarcs", (gpointer *) &__symbolic_CPXNETaddarcs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETaddarcs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETaddarcs.\n");
        }
    }
    return __symbolic_CPXNETaddarcs(env, net, narcs, fromnode, tonode, low, up, obj, anames);
}
int CPXNETdelnodes (CPXCENVptr env, CPXNETptr net, int begin, int end){
    if (!__symbolic_CPXNETdelnodes) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETdelnodes", (gpointer *) &__symbolic_CPXNETdelnodes)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETdelnodes could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETdelnodes.\n");
        }
    }
    return __symbolic_CPXNETdelnodes(env, net, begin, end);
}
int CPXNETdelarcs (CPXCENVptr env, CPXNETptr net, int begin, int end){
    if (!__symbolic_CPXNETdelarcs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETdelarcs", (gpointer *) &__symbolic_CPXNETdelarcs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETdelarcs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETdelarcs.\n");
        }
    }
    return __symbolic_CPXNETdelarcs(env, net, begin, end);
}
int CPXNETdelset (CPXCENVptr env, CPXNETptr net, int *whichnodes, int *whicharcs){
    if (!__symbolic_CPXNETdelset) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETdelset", (gpointer *) &__symbolic_CPXNETdelset)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETdelset could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETdelset.\n");
        }
    }
    return __symbolic_CPXNETdelset(env, net, whichnodes, whicharcs);
}
int CPXNETprimopt (CPXCENVptr env, CPXNETptr net){
    if (!__symbolic_CPXNETprimopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETprimopt", (gpointer *) &__symbolic_CPXNETprimopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETprimopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETprimopt.\n");
        }
    }
    return __symbolic_CPXNETprimopt(env, net);
}
int CPXNETgetstat (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetstat) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetstat", (gpointer *) &__symbolic_CPXNETgetstat)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetstat could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetstat.\n");
        }
    }
    return __symbolic_CPXNETgetstat(env, net);
}
int CPXNETgetobjval (CPXCENVptr env, CPXCNETptr net, double *objval_p){
    if (!__symbolic_CPXNETgetobjval) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetobjval", (gpointer *) &__symbolic_CPXNETgetobjval)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetobjval could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetobjval.\n");
        }
    }
    return __symbolic_CPXNETgetobjval(env, net, objval_p);
}
int CPXNETgetx (CPXCENVptr env, CPXCNETptr net, double *x, int begin, int end){
    if (!__symbolic_CPXNETgetx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetx", (gpointer *) &__symbolic_CPXNETgetx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetx.\n");
        }
    }
    return __symbolic_CPXNETgetx(env, net, x, begin, end);
}
int CPXNETgetpi (CPXCENVptr env, CPXCNETptr net, double *pi, int begin, int end){
    if (!__symbolic_CPXNETgetpi) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetpi", (gpointer *) &__symbolic_CPXNETgetpi)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetpi could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetpi.\n");
        }
    }
    return __symbolic_CPXNETgetpi(env, net, pi, begin, end);
}
int CPXNETgetslack (CPXCENVptr env, CPXCNETptr net, double *slack, int begin, int end){
    if (!__symbolic_CPXNETgetslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetslack", (gpointer *) &__symbolic_CPXNETgetslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetslack.\n");
        }
    }
    return __symbolic_CPXNETgetslack(env, net, slack, begin, end);
}
int CPXNETgetdj (CPXCENVptr env, CPXCNETptr net, double *dj, int begin, int end){
    if (!__symbolic_CPXNETgetdj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetdj", (gpointer *) &__symbolic_CPXNETgetdj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetdj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetdj.\n");
        }
    }
    return __symbolic_CPXNETgetdj(env, net, dj, begin, end);
}
int CPXNETgetitcnt (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetitcnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetitcnt", (gpointer *) &__symbolic_CPXNETgetitcnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetitcnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetitcnt.\n");
        }
    }
    return __symbolic_CPXNETgetitcnt(env, net);
}
int CPXNETgetphase1cnt (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetphase1cnt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetphase1cnt", (gpointer *) &__symbolic_CPXNETgetphase1cnt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetphase1cnt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetphase1cnt.\n");
        }
    }
    return __symbolic_CPXNETgetphase1cnt(env, net);
}
int CPXNETgetbase (CPXCENVptr env, CPXCNETptr net, int *astat, int *nstat){
    if (!__symbolic_CPXNETgetbase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetbase", (gpointer *) &__symbolic_CPXNETgetbase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetbase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetbase.\n");
        }
    }
    return __symbolic_CPXNETgetbase(env, net, astat, nstat);
}
int CPXNETsolution (CPXCENVptr env, CPXCNETptr net, int *netstat_p, double *objval_p, double *x, double *pi, double *slack, double *dj){
    if (!__symbolic_CPXNETsolution) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETsolution", (gpointer *) &__symbolic_CPXNETsolution)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETsolution could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETsolution.\n");
        }
    }
    return __symbolic_CPXNETsolution(env, net, netstat_p, objval_p, x, pi, slack, dj);
}
int CPXNETsolninfo (CPXCENVptr env, CPXCNETptr net, int *pfeasind_p, int *dfeasind_p){
    if (!__symbolic_CPXNETsolninfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETsolninfo", (gpointer *) &__symbolic_CPXNETsolninfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETsolninfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETsolninfo.\n");
        }
    }
    return __symbolic_CPXNETsolninfo(env, net, pfeasind_p, dfeasind_p);
}
int CPXNETchgname (CPXCENVptr env, CPXNETptr net, int key, int vindex, const char *name_str){
    if (!__symbolic_CPXNETchgname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgname", (gpointer *) &__symbolic_CPXNETchgname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgname.\n");
        }
    }
    return __symbolic_CPXNETchgname(env, net, key, vindex, name_str);
}
int CPXNETchgarcname (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXNETchgarcname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgarcname", (gpointer *) &__symbolic_CPXNETchgarcname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgarcname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgarcname.\n");
        }
    }
    return __symbolic_CPXNETchgarcname(env, net, cnt, indices, newname);
}
int CPXNETchgnodename (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXNETchgnodename) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgnodename", (gpointer *) &__symbolic_CPXNETchgnodename)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgnodename could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgnodename.\n");
        }
    }
    return __symbolic_CPXNETchgnodename(env, net, cnt, indices, newname);
}
int CPXNETchgobjsen (CPXCENVptr env, CPXNETptr net, int maxormin){
    if (!__symbolic_CPXNETchgobjsen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgobjsen", (gpointer *) &__symbolic_CPXNETchgobjsen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgobjsen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgobjsen.\n");
        }
    }
    return __symbolic_CPXNETchgobjsen(env, net, maxormin);
}
int CPXNETchgbds (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const char *lu, const double *bd){
    if (!__symbolic_CPXNETchgbds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgbds", (gpointer *) &__symbolic_CPXNETchgbds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgbds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgbds.\n");
        }
    }
    return __symbolic_CPXNETchgbds(env, net, cnt, indices, lu, bd);
}
int CPXNETchgarcnodes (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const int *fromnode, const int *tonode){
    if (!__symbolic_CPXNETchgarcnodes) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgarcnodes", (gpointer *) &__symbolic_CPXNETchgarcnodes)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgarcnodes could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgarcnodes.\n");
        }
    }
    return __symbolic_CPXNETchgarcnodes(env, net, cnt, indices, fromnode, tonode);
}
int CPXNETchgobj (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const double *obj){
    if (!__symbolic_CPXNETchgobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgobj", (gpointer *) &__symbolic_CPXNETchgobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgobj.\n");
        }
    }
    return __symbolic_CPXNETchgobj(env, net, cnt, indices, obj);
}
int CPXNETchgsupply (CPXCENVptr env, CPXNETptr net, int cnt, const int *indices, const double *supply){
    if (!__symbolic_CPXNETchgsupply) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETchgsupply", (gpointer *) &__symbolic_CPXNETchgsupply)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETchgsupply could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETchgsupply.\n");
        }
    }
    return __symbolic_CPXNETchgsupply(env, net, cnt, indices, supply);
}
int CPXNETgetobjsen (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetobjsen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetobjsen", (gpointer *) &__symbolic_CPXNETgetobjsen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetobjsen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetobjsen.\n");
        }
    }
    return __symbolic_CPXNETgetobjsen(env, net);
}
int CPXNETgetsupply (CPXCENVptr env, CPXCNETptr net, double *supply, int begin, int end){
    if (!__symbolic_CPXNETgetsupply) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetsupply", (gpointer *) &__symbolic_CPXNETgetsupply)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetsupply could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetsupply.\n");
        }
    }
    return __symbolic_CPXNETgetsupply(env, net, supply, begin, end);
}
int CPXNETgetprobname (CPXCENVptr env, CPXCNETptr net, char *buf_str, int bufspace, int *surplus_p){
    if (!__symbolic_CPXNETgetprobname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetprobname", (gpointer *) &__symbolic_CPXNETgetprobname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetprobname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetprobname.\n");
        }
    }
    return __symbolic_CPXNETgetprobname(env, net, buf_str, bufspace, surplus_p);
}
int CPXNETgetnodename (CPXCENVptr env, CPXCNETptr net, char **nnames, char *namestore, int namespc, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXNETgetnodename) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetnodename", (gpointer *) &__symbolic_CPXNETgetnodename)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetnodename could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetnodename.\n");
        }
    }
    return __symbolic_CPXNETgetnodename(env, net, nnames, namestore, namespc, surplus_p, begin, end);
}
int CPXNETgetarcname (CPXCENVptr env, CPXCNETptr net, char **nnames, char *namestore, int namespc, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXNETgetarcname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetarcname", (gpointer *) &__symbolic_CPXNETgetarcname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetarcname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetarcname.\n");
        }
    }
    return __symbolic_CPXNETgetarcname(env, net, nnames, namestore, namespc, surplus_p, begin, end);
}
int CPXNETgetlb (CPXCENVptr env, CPXCNETptr net, double *low, int begin, int end){
    if (!__symbolic_CPXNETgetlb) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetlb", (gpointer *) &__symbolic_CPXNETgetlb)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetlb could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetlb.\n");
        }
    }
    return __symbolic_CPXNETgetlb(env, net, low, begin, end);
}
int CPXNETgetub (CPXCENVptr env, CPXCNETptr net, double *up, int begin, int end){
    if (!__symbolic_CPXNETgetub) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetub", (gpointer *) &__symbolic_CPXNETgetub)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetub could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetub.\n");
        }
    }
    return __symbolic_CPXNETgetub(env, net, up, begin, end);
}
int CPXNETgetobj (CPXCENVptr env, CPXCNETptr net, double *obj, int begin, int end){
    if (!__symbolic_CPXNETgetobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetobj", (gpointer *) &__symbolic_CPXNETgetobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetobj.\n");
        }
    }
    return __symbolic_CPXNETgetobj(env, net, obj, begin, end);
}
int CPXNETgetarcnodes (CPXCENVptr env, CPXCNETptr net, int *fromnode, int *tonode, int begin, int end){
    if (!__symbolic_CPXNETgetarcnodes) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetarcnodes", (gpointer *) &__symbolic_CPXNETgetarcnodes)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetarcnodes could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetarcnodes.\n");
        }
    }
    return __symbolic_CPXNETgetarcnodes(env, net, fromnode, tonode, begin, end);
}
int CPXNETgetnodearcs (CPXCENVptr env, CPXCNETptr net, int *arccnt_p, int *arcbeg, int *arc, int arcspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXNETgetnodearcs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetnodearcs", (gpointer *) &__symbolic_CPXNETgetnodearcs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetnodearcs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetnodearcs.\n");
        }
    }
    return __symbolic_CPXNETgetnodearcs(env, net, arccnt_p, arcbeg, arc, arcspace, surplus_p, begin, end);
}
int CPXNETgetnumnodes (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetnumnodes) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetnumnodes", (gpointer *) &__symbolic_CPXNETgetnumnodes)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetnumnodes could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetnumnodes.\n");
        }
    }
    return __symbolic_CPXNETgetnumnodes(env, net);
}
int CPXNETgetnumarcs (CPXCENVptr env, CPXCNETptr net){
    if (!__symbolic_CPXNETgetnumarcs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetnumarcs", (gpointer *) &__symbolic_CPXNETgetnumarcs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetnumarcs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetnumarcs.\n");
        }
    }
    return __symbolic_CPXNETgetnumarcs(env, net);
}
int CPXNETgetnodeindex (CPXCENVptr env, CPXCNETptr net, const char *lname_str, int *index_p){
    if (!__symbolic_CPXNETgetnodeindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetnodeindex", (gpointer *) &__symbolic_CPXNETgetnodeindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetnodeindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetnodeindex.\n");
        }
    }
    return __symbolic_CPXNETgetnodeindex(env, net, lname_str, index_p);
}
int CPXNETgetarcindex (CPXCENVptr env, CPXCNETptr net, const char *lname_str, int *index_p){
    if (!__symbolic_CPXNETgetarcindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETgetarcindex", (gpointer *) &__symbolic_CPXNETgetarcindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETgetarcindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETgetarcindex.\n");
        }
    }
    return __symbolic_CPXNETgetarcindex(env, net, lname_str, index_p);
}
int CPXNETreadcopyprob (CPXCENVptr env, CPXNETptr net, const char *filename_str){
    if (!__symbolic_CPXNETreadcopyprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETreadcopyprob", (gpointer *) &__symbolic_CPXNETreadcopyprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETreadcopyprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETreadcopyprob.\n");
        }
    }
    return __symbolic_CPXNETreadcopyprob(env, net, filename_str);
}
int CPXNETreadcopybase (CPXCENVptr env, CPXNETptr net, const char *filename_str){
    if (!__symbolic_CPXNETreadcopybase) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETreadcopybase", (gpointer *) &__symbolic_CPXNETreadcopybase)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETreadcopybase could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETreadcopybase.\n");
        }
    }
    return __symbolic_CPXNETreadcopybase(env, net, filename_str);
}
int CPXNETwriteprob (CPXCENVptr env, CPXCNETptr net, const char *filename_str, const char *format_str){
    if (!__symbolic_CPXNETwriteprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETwriteprob", (gpointer *) &__symbolic_CPXNETwriteprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETwriteprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETwriteprob.\n");
        }
    }
    return __symbolic_CPXNETwriteprob(env, net, filename_str, format_str);
}
int CPXNETbasewrite (CPXCENVptr env, CPXCNETptr net, const char *filename_str){
    if (!__symbolic_CPXNETbasewrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETbasewrite", (gpointer *) &__symbolic_CPXNETbasewrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETbasewrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETbasewrite.\n");
        }
    }
    return __symbolic_CPXNETbasewrite(env, net, filename_str);
}
int CPXNETcheckcopynet (CPXCENVptr env, CPXNETptr net, int objsen, int nnodes, const double *supply, char **nnames, int narcs, const int *fromnode, const int *tonode, const double *low, const double *up, const double *obj, char **aname){
    if (!__symbolic_CPXNETcheckcopynet) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXNETcheckcopynet", (gpointer *) &__symbolic_CPXNETcheckcopynet)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXNETcheckcopynet could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXNETcheckcopynet.\n");
        }
    }
    return __symbolic_CPXNETcheckcopynet(env, net, objsen, nnodes, supply, nnames, narcs, fromnode, tonode, low, up, obj, aname);
}
int CPXcopyquad (CPXCENVptr env, CPXLPptr lp, const int *qmatbeg, const int *qmatcnt, const int *qmatind, const double *qmatval){
    if (!__symbolic_CPXcopyquad) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyquad", (gpointer *) &__symbolic_CPXcopyquad)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyquad could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyquad.\n");
        }
    }
    return __symbolic_CPXcopyquad(env, lp, qmatbeg, qmatcnt, qmatind, qmatval);
}
int CPXcopyqpsep (CPXCENVptr env, CPXLPptr lp, const double *qsepvec){
    if (!__symbolic_CPXcopyqpsep) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcopyqpsep", (gpointer *) &__symbolic_CPXcopyqpsep)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcopyqpsep could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcopyqpsep.\n");
        }
    }
    return __symbolic_CPXcopyqpsep(env, lp, qsepvec);
}
int CPXchgqpcoef (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue){
    if (!__symbolic_CPXchgqpcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXchgqpcoef", (gpointer *) &__symbolic_CPXchgqpcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXchgqpcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXchgqpcoef.\n");
        }
    }
    return __symbolic_CPXchgqpcoef(env, lp, i, j, newvalue);
}
int CPXgetnumqpnz (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumqpnz) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumqpnz", (gpointer *) &__symbolic_CPXgetnumqpnz)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumqpnz could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumqpnz.\n");
        }
    }
    return __symbolic_CPXgetnumqpnz(env, lp);
}
int CPXgetnumquad (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumquad) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumquad", (gpointer *) &__symbolic_CPXgetnumquad)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumquad could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumquad.\n");
        }
    }
    return __symbolic_CPXgetnumquad(env, lp);
}
int CPXgetqpcoef (CPXCENVptr env, CPXCLPptr lp, int rownum, int colnum, double *coef_p){
    if (!__symbolic_CPXgetqpcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqpcoef", (gpointer *) &__symbolic_CPXgetqpcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqpcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqpcoef.\n");
        }
    }
    return __symbolic_CPXgetqpcoef(env, lp, rownum, colnum, coef_p);
}
int CPXgetquad (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p, int *qmatbeg, int *qmatind, double *qmatval, int qmatspace, int *surplus_p, int begin, int end){
    if (!__symbolic_CPXgetquad) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetquad", (gpointer *) &__symbolic_CPXgetquad)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetquad could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetquad.\n");
        }
    }
    return __symbolic_CPXgetquad(env, lp, nzcnt_p, qmatbeg, qmatind, qmatval, qmatspace, surplus_p, begin, end);
}
int CPXqpindefcertificate (CPXCENVptr env, CPXCLPptr lp, double *x){
    if (!__symbolic_CPXqpindefcertificate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXqpindefcertificate", (gpointer *) &__symbolic_CPXqpindefcertificate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXqpindefcertificate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXqpindefcertificate.\n");
        }
    }
    return __symbolic_CPXqpindefcertificate(env, lp, x);
}
int CPXcheckcopyqpsep (CPXCENVptr env, CPXCLPptr lp, const double *qsepvec){
    if (!__symbolic_CPXcheckcopyqpsep) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopyqpsep", (gpointer *) &__symbolic_CPXcheckcopyqpsep)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopyqpsep could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopyqpsep.\n");
        }
    }
    return __symbolic_CPXcheckcopyqpsep(env, lp, qsepvec);
}
int CPXcheckcopyquad (CPXCENVptr env, CPXCLPptr lp, const int *qmatbeg, const int *qmatcnt, const int *qmatind, const double *qmatval){
    if (!__symbolic_CPXcheckcopyquad) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXcheckcopyquad", (gpointer *) &__symbolic_CPXcheckcopyquad)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXcheckcopyquad could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXcheckcopyquad.\n");
        }
    }
    return __symbolic_CPXcheckcopyquad(env, lp, qmatbeg, qmatcnt, qmatind, qmatval);
}
int CPXqpopt (CPXCENVptr env, CPXLPptr lp){
    if (!__symbolic_CPXqpopt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXqpopt", (gpointer *) &__symbolic_CPXqpopt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXqpopt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXqpopt.\n");
        }
    }
    return __symbolic_CPXqpopt(env, lp);
}
int CPXaddqconstr (CPXCENVptr env, CPXLPptr lp, int linnzcnt, int quadnzcnt, double rhs, int sense, const int *linind, const double *linval, const int *quadrow, const int *quadcol, const double *quadval, const char *lname_str){
    if (!__symbolic_CPXaddqconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXaddqconstr", (gpointer *) &__symbolic_CPXaddqconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXaddqconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXaddqconstr.\n");
        }
    }
    return __symbolic_CPXaddqconstr(env, lp, linnzcnt, quadnzcnt, rhs, sense, linind, linval, quadrow, quadcol, quadval, lname_str);
}
int CPXdelqconstrs (CPXCENVptr env, CPXLPptr lp, int begin, int end){
    if (!__symbolic_CPXdelqconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXdelqconstrs", (gpointer *) &__symbolic_CPXdelqconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXdelqconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXdelqconstrs.\n");
        }
    }
    return __symbolic_CPXdelqconstrs(env, lp, begin, end);
}
int CPXgetnumqconstrs (CPXCENVptr env, CPXCLPptr lp){
    if (!__symbolic_CPXgetnumqconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetnumqconstrs", (gpointer *) &__symbolic_CPXgetnumqconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetnumqconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetnumqconstrs.\n");
        }
    }
    return __symbolic_CPXgetnumqconstrs(env, lp);
}
int CPXgetqconstrindex (CPXCENVptr env, CPXCLPptr lp, const char *lname_str, int *index_p){
    if (!__symbolic_CPXgetqconstrindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqconstrindex", (gpointer *) &__symbolic_CPXgetqconstrindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqconstrindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqconstrindex.\n");
        }
    }
    return __symbolic_CPXgetqconstrindex(env, lp, lname_str, index_p);
}
int CPXgetqconstr (CPXCENVptr env, CPXCLPptr lp, int *linnzcnt_p, int *quadnzcnt_p, double *rhs_p, char *sense_p, int *linind, double *linval, int linspace, int *linsurplus_p, int *quadrow, int *quadcol, double *quadval, int quadspace, int *quadsurplus_p, int which){
    if (!__symbolic_CPXgetqconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqconstr", (gpointer *) &__symbolic_CPXgetqconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqconstr.\n");
        }
    }
    return __symbolic_CPXgetqconstr(env, lp, linnzcnt_p, quadnzcnt_p, rhs_p, sense_p, linind, linval, linspace, linsurplus_p, quadrow, quadcol, quadval, quadspace, quadsurplus_p, which);
}
int CPXgetqconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str, int bufspace, int *surplus_p, int which){
    if (!__symbolic_CPXgetqconstrname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqconstrname", (gpointer *) &__symbolic_CPXgetqconstrname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqconstrname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqconstrname.\n");
        }
    }
    return __symbolic_CPXgetqconstrname(env, lp, buf_str, bufspace, surplus_p, which);
}
int CPXgetqconstrslack (CPXCENVptr env, CPXCLPptr lp, double *qcslack, int begin, int end){
    if (!__symbolic_CPXgetqconstrslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqconstrslack", (gpointer *) &__symbolic_CPXgetqconstrslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqconstrslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqconstrslack.\n");
        }
    }
    return __symbolic_CPXgetqconstrslack(env, lp, qcslack, begin, end);
}
int CPXqconstrslackfromx (CPXCENVptr env, CPXCLPptr lp, const double *x, double *qcslack){
    if (!__symbolic_CPXqconstrslackfromx) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXqconstrslackfromx", (gpointer *) &__symbolic_CPXqconstrslackfromx)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXqconstrslackfromx could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXqconstrslackfromx.\n");
        }
    }
    return __symbolic_CPXqconstrslackfromx(env, lp, x, qcslack);
}
int CPXgetqconstrinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x, double *infeasout, int begin, int end){
    if (!__symbolic_CPXgetqconstrinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetqconstrinfeas", (gpointer *) &__symbolic_CPXgetqconstrinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetqconstrinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetqconstrinfeas.\n");
        }
    }
    return __symbolic_CPXgetqconstrinfeas(env, lp, x, infeasout, begin, end);
}
int CPXgetxqxax (CPXCENVptr env, CPXCLPptr lp, double *xqxax, int begin, int end){
    if (!__symbolic_CPXgetxqxax) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXgetxqxax", (gpointer *) &__symbolic_CPXgetxqxax)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXgetxqxax could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXgetxqxax.\n");
        }
    }
    return __symbolic_CPXgetxqxax(env, lp, xqxax, begin, end);
}
int CPXEchgqcname (CPXCENVptr env, CPXLPptr lp, int cnt, const int *indices, char **newname){
    if (!__symbolic_CPXEchgqcname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_CPLEX_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libcplex.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "CPXEchgqcname", (gpointer *) &__symbolic_CPXEchgqcname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol CPXEchgqcname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol CPXEchgqcname.\n");
        }
    }
    return __symbolic_CPXEchgqcname(env, lp, cnt, indices, newname);
}
