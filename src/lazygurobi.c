#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gurobi_c.h>

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
    char *LAZYLPSOLVERLIBS_GUROBI_LIB;
    LAZYLPSOLVERLIBS_GUROBI_LIB = getenv("LAZYLPSOLVERLIBS_GUROBI_LIB");
    if (!module) {
        DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", "/usr/lib/libgurobi.so");
        module = g_module_open("/usr/lib/libgurobi.so", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
    }
    if (LAZYLPSOLVERLIBS_GUROBI_LIB != NULL) {
        if (!module) {
            DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", LAZYLPSOLVERLIBS_GUROBI_LIB);
            module = g_module_open(LAZYLPSOLVERLIBS_GUROBI_LIB, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        }
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "gurobi50.dll");
#else
        path = g_module_build_path(NULL, "gurobi50");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "gurobi461.dll");
#else
        path = g_module_build_path(NULL, "gurobi461");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "gurobi452.dll");
#else
        path = g_module_build_path(NULL, "gurobi452");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "gurobi402.dll");
#else
        path = g_module_build_path(NULL, "gurobi402");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "gurobi303.dll");
#else
        path = g_module_build_path(NULL, "gurobi303");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    return (module != NULL);
}

/* imported functions */

int (*__symbolic_GRBgetattrinfo) (GRBmodel * model, const char *attrname, int *datatypeP, int *sizeP, int *settableP) = NULL;
int (*__symbolic_GRBgetintattr) (GRBmodel * model, const char *attrname, int *valueP) = NULL;
int (*__symbolic_GRBsetintattr) (GRBmodel * model, const char *attrname, int newvalue) = NULL;
int (*__symbolic_GRBgetintattrelement) (GRBmodel * model, const char *attrname, int element, int *valueP) = NULL;
int (*__symbolic_GRBsetintattrelement) (GRBmodel * model, const char *attrname, int element, int newvalue) = NULL;
int (*__symbolic_GRBgetintattrarray) (GRBmodel * model, const char *attrname, int first, int len, int *values) = NULL;
int (*__symbolic_GRBsetintattrarray) (GRBmodel * model, const char *attrname, int first, int len, int *newvalues) = NULL;
int (*__symbolic_GRBgetintattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, int *values) = NULL;
int (*__symbolic_GRBsetintattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, int *newvalues) = NULL;
int (*__symbolic_GRBgetcharattrelement) (GRBmodel * model, const char *attrname, int element, char *valueP) = NULL;
int (*__symbolic_GRBsetcharattrelement) (GRBmodel * model, const char *attrname, int element, char newvalue) = NULL;
int (*__symbolic_GRBgetcharattrarray) (GRBmodel * model, const char *attrname, int first, int len, char *values) = NULL;
int (*__symbolic_GRBsetcharattrarray) (GRBmodel * model, const char *attrname, int first, int len, char *newvalues) = NULL;
int (*__symbolic_GRBgetcharattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, char *values) = NULL;
int (*__symbolic_GRBsetcharattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, char *newvalues) = NULL;
int (*__symbolic_GRBgetdblattr) (GRBmodel * model, const char *attrname, double *valueP) = NULL;
int (*__symbolic_GRBsetdblattr) (GRBmodel * model, const char *attrname, double newvalue) = NULL;
int (*__symbolic_GRBgetdblattrelement) (GRBmodel * model, const char *attrname, int element, double *valueP) = NULL;
int (*__symbolic_GRBsetdblattrelement) (GRBmodel * model, const char *attrname, int element, double newvalue) = NULL;
int (*__symbolic_GRBgetdblattrarray) (GRBmodel * model, const char *attrname, int first, int len, double *values) = NULL;
int (*__symbolic_GRBsetdblattrarray) (GRBmodel * model, const char *attrname, int first, int len, double *newvalues) = NULL;
int (*__symbolic_GRBgetdblattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, double *values) = NULL;
int (*__symbolic_GRBsetdblattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, double *newvalues) = NULL;
int (*__symbolic_GRBgetstrattr) (GRBmodel * model, const char *attrname, char **valueP) = NULL;
int (*__symbolic_GRBsetstrattr) (GRBmodel * model, const char *attrname, char *newvalue) = NULL;
int (*__symbolic_GRBgetstrattrelement) (GRBmodel * model, const char *attrname, int element, char **valueP) = NULL;
int (*__symbolic_GRBsetstrattrelement) (GRBmodel * model, const char *attrname, int element, char *newvalue) = NULL;
int (*__symbolic_GRBgetstrattrarray) (GRBmodel * model, const char *attrname, int first, int len, char **values) = NULL;
int (*__symbolic_GRBsetstrattrarray) (GRBmodel * model, const char *attrname, int first, int len, char **newvalues) = NULL;
int (*__symbolic_GRBgetstrattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, char **values) = NULL;
int (*__symbolic_GRBsetstrattrlist) (GRBmodel * model, const char *attrname, int len, int *ind, char **newvalues) = NULL;
int (*__symbolic_GRBsetcallbackfunc) (GRBmodel * model, int ( * cb) (GRBmodel *model, void *cbdata, int where, void *usrdata), void *usrdata) = NULL;
int (*__symbolic_GRBgetcallbackfunc) (GRBmodel * model, int ( ** cbP) (GRBmodel *model, void *cbdata, int where, void *usrdata)) = NULL;
int (*__symbolic_GRBcbget) (void *cbdata, int where, int what, void *resultP) = NULL;
int (*__symbolic_GRBcbsolution) (void *cbdata, const double *solution) = NULL;
int (*__symbolic_GRBcbcut) (void *cbdata, int cutlen, const int *cutind, const double *cutval, char cutsense, double cutrhs) = NULL;
int (*__symbolic_GRBgetcoeff) (GRBmodel * model, int constr, int var, double *valP) = NULL;
int (*__symbolic_GRBgetconstrs) (GRBmodel * model, int *numnzP, int *cbeg, int *cind, double *cval, int start, int len) = NULL;
int (*__symbolic_GRBgetvars) (GRBmodel * model, int *numnzP, int *vbeg, int *vind, double *vval, int start, int len) = NULL;
int (*__symbolic_GRBgetsos) (GRBmodel * model, int *nummembersP, int *sostype, int *beg, int *ind, double *weight, int start, int len) = NULL;
int (*__symbolic_GRBoptimize) (GRBmodel * model) = NULL;
GRBmodel * (*__symbolic_GRBcopymodel) (GRBmodel * model) = NULL;
GRBmodel * (*__symbolic_GRBfixedmodel) (GRBmodel * model) = NULL;
int (*__symbolic_GRBgetcbwhatinfo) (void *cbdata, int what, int *typeP, int *sizeP) = NULL;
GRBmodel * (*__symbolic_GRBrelaxmodel) (GRBmodel * model) = NULL;
int (*__symbolic_GRBconverttofixed) (GRBmodel * lp) = NULL;
GRBmodel * (*__symbolic_GRBpresolvemodel) (GRBmodel * model) = NULL;
GRBmodel * (*__symbolic_GRBiismodel) (GRBmodel * model) = NULL;
GRBmodel * (*__symbolic_GRBfeasibility) (GRBmodel * model) = NULL;
int (*__symbolic_GRBreadmodel) (GRBenv * env, const char *filename, GRBmodel ** modelP) = NULL;
int (*__symbolic_GRBread) (GRBmodel * model, const char *filename) = NULL;
int (*__symbolic_GRBwrite) (GRBmodel * model, const char *filename) = NULL;
int (*__symbolic_GRBnewmodel) (GRBenv * env, GRBmodel ** modelP, const char *Pname, int numvars, double *obj, double *lb, double *ub, char *vtype, char **varnames) = NULL;
int (*__symbolic_GRBloadmodel) (GRBenv * env, GRBmodel ** modelP, const char *Pname, int numvars, int numconstrs, int objsense, double objcon, double *obj, char *sense, double *rhs, int *vbeg, int *vlen, int *vind, double *vval, double *lb, double *ub, char *vtype, char **varnames, char **constrnames) = NULL;
int (*__symbolic_GRBaddvar) (GRBmodel * model, int numnz, int *vind, double *vval, double obj, double lb, double ub, char vtype, char *varname) = NULL;
int (*__symbolic_GRBaddvars) (GRBmodel * model, int numvars, int numnz, int *vbeg, int *vind, double *vval, double *obj, double *lb, double *ub, char *vtype, char **varnames) = NULL;
int (*__symbolic_GRBaddconstr) (GRBmodel * model, int numnz, int *cind, double *cval, char sense, double rhs, char *constrnames) = NULL;
int (*__symbolic_GRBaddconstrs) (GRBmodel * model, int numconstrs, int numnz, int *cbeg, int *cind, double *cval, char *sense, double *rhs, char **constrnames) = NULL;
int (*__symbolic_GRBaddrangeconstr) (GRBmodel * model, int numnz, int *cind, double *cval, double lower, double upper, char *constrnames) = NULL;
int (*__symbolic_GRBaddrangeconstrs) (GRBmodel * model, int numconstrs, int numnz, int *cbeg, int *cind, double *cval, double *lower, double *upper, char **constrnames) = NULL;
int (*__symbolic_GRBaddsos) (GRBmodel * model, int numsos, int nummembers, int *types, int *beg, int *ind, double *weight) = NULL;
int (*__symbolic_GRBdelvars) (GRBmodel * model, int len, int *ind) = NULL;
int (*__symbolic_GRBdelconstrs) (GRBmodel * model, int len, int *ind) = NULL;
int (*__symbolic_GRBdelsos) (GRBmodel * model, int len, int *ind) = NULL;
int (*__symbolic_GRBchgcoeffs) (GRBmodel * model, int cnt, int *cind, int *vind, double *val) = NULL;
int (*__symbolic_GRBupdatemodel) (GRBmodel * model) = NULL;
int (*__symbolic_GRBresetmodel) (GRBmodel * model) = NULL;
int (*__symbolic_GRBfreemodel) (GRBmodel * model) = NULL;
int (*__symbolic_GRBcomputeIIS) (GRBmodel * lp) = NULL;
int (*__symbolic_GRBstrongbranch) (GRBmodel * model, int num, int *cand, double *downobjbd, double *upobjbd, int *statusP) = NULL;
int (*__symbolic_GRBcheckmodel) (GRBmodel * model) = NULL;
void (*__symbolic_GRBsetsignal) (GRBmodel * model) = NULL;
void (*__symbolic_GRBterminate) (GRBmodel * model) = NULL;
void (*__symbolic_GRBmsg) (GRBenv * env, const char *message) = NULL;
int (*__symbolic_GRBgetlogfile) (GRBenv * env, FILE ** logfileP) = NULL;
int (*__symbolic_GRBsetlogfile) (GRBenv * env, FILE * logfile) = NULL;
int (*__symbolic_GRBgetintparam) (GRBenv * env, const char *paramname, int *valueP) = NULL;
int (*__symbolic_GRBgetdblparam) (GRBenv * env, const char *paramname, double *valueP) = NULL;
int (*__symbolic_GRBgetstrparam) (GRBenv * env, const char *paramname, char *valueP) = NULL;
int (*__symbolic_GRBgetintparaminfo) (GRBenv * env, const char *paramname, int *valueP, int *minP, int *maxP, int *defP) = NULL;
int (*__symbolic_GRBgetdblparaminfo) (GRBenv * env, const char *paramname, double *valueP, double *minP, double *maxP, double *defP) = NULL;
int (*__symbolic_GRBgetstrparaminfo) (GRBenv * env, const char *paramname, char *valueP, char *defP) = NULL;
int (*__symbolic_GRBsetintparam) (GRBenv * env, const char *paramname, int value) = NULL;
int (*__symbolic_GRBsetdblparam) (GRBenv * env, const char *paramname, double value) = NULL;
int (*__symbolic_GRBsetstrparam) (GRBenv * env, const char *paramname, const char *value) = NULL;
int (*__symbolic_GRBgetparamtype) (GRBenv * env, const char *paramname) = NULL;
int (*__symbolic_GRBresetparams) (GRBenv * env) = NULL;
int (*__symbolic_GRBwriteparams) (GRBenv * env, const char *filename) = NULL;
int (*__symbolic_GRBreadparams) (GRBenv * env, const char *filename) = NULL;
int (*__symbolic_GRBgetnumparams) (GRBenv * env) = NULL;
int (*__symbolic_GRBgetparamname) (GRBenv * env, int i, char **paramnameP) = NULL;
int (*__symbolic_GRBloadenv) (GRBenv ** envP, const char *logfilename) = NULL;
GRBenv * (*__symbolic_GRBgetenv) (GRBmodel * model) = NULL;
void (*__symbolic_GRBfreeenv) (GRBenv * env) = NULL;
const char * (*__symbolic_GRBgeterrormsg) (GRBenv * env) = NULL;
const char * (*__symbolic_GRBgetmerrormsg) (GRBmodel * model) = NULL;
void (*__symbolic_GRBversion) (int *majorP, int *minorP, int *technicalP) = NULL;
char * (*__symbolic_GRBplatform) (void) = NULL;

/* hijacked functions */

int GRBgetattrinfo (GRBmodel * model, const char *attrname, int *datatypeP, int *sizeP, int *settableP){
    if (!__symbolic_GRBgetattrinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetattrinfo", (gpointer *) &__symbolic_GRBgetattrinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetattrinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetattrinfo.\n");
        }
    }
    return __symbolic_GRBgetattrinfo(model, attrname, datatypeP, sizeP, settableP);
}
int GRBgetintattr (GRBmodel * model, const char *attrname, int *valueP){
    if (!__symbolic_GRBgetintattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintattr", (gpointer *) &__symbolic_GRBgetintattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintattr.\n");
        }
    }
    return __symbolic_GRBgetintattr(model, attrname, valueP);
}
int GRBsetintattr (GRBmodel * model, const char *attrname, int newvalue){
    if (!__symbolic_GRBsetintattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetintattr", (gpointer *) &__symbolic_GRBsetintattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetintattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetintattr.\n");
        }
    }
    return __symbolic_GRBsetintattr(model, attrname, newvalue);
}
int GRBgetintattrelement (GRBmodel * model, const char *attrname, int element, int *valueP){
    if (!__symbolic_GRBgetintattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintattrelement", (gpointer *) &__symbolic_GRBgetintattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintattrelement.\n");
        }
    }
    return __symbolic_GRBgetintattrelement(model, attrname, element, valueP);
}
int GRBsetintattrelement (GRBmodel * model, const char *attrname, int element, int newvalue){
    if (!__symbolic_GRBsetintattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetintattrelement", (gpointer *) &__symbolic_GRBsetintattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetintattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetintattrelement.\n");
        }
    }
    return __symbolic_GRBsetintattrelement(model, attrname, element, newvalue);
}
int GRBgetintattrarray (GRBmodel * model, const char *attrname, int first, int len, int *values){
    if (!__symbolic_GRBgetintattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintattrarray", (gpointer *) &__symbolic_GRBgetintattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintattrarray.\n");
        }
    }
    return __symbolic_GRBgetintattrarray(model, attrname, first, len, values);
}
int GRBsetintattrarray (GRBmodel * model, const char *attrname, int first, int len, int *newvalues){
    if (!__symbolic_GRBsetintattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetintattrarray", (gpointer *) &__symbolic_GRBsetintattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetintattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetintattrarray.\n");
        }
    }
    return __symbolic_GRBsetintattrarray(model, attrname, first, len, newvalues);
}
int GRBgetintattrlist (GRBmodel * model, const char *attrname, int len, int *ind, int *values){
    if (!__symbolic_GRBgetintattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintattrlist", (gpointer *) &__symbolic_GRBgetintattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintattrlist.\n");
        }
    }
    return __symbolic_GRBgetintattrlist(model, attrname, len, ind, values);
}
int GRBsetintattrlist (GRBmodel * model, const char *attrname, int len, int *ind, int *newvalues){
    if (!__symbolic_GRBsetintattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetintattrlist", (gpointer *) &__symbolic_GRBsetintattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetintattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetintattrlist.\n");
        }
    }
    return __symbolic_GRBsetintattrlist(model, attrname, len, ind, newvalues);
}
int GRBgetcharattrelement (GRBmodel * model, const char *attrname, int element, char *valueP){
    if (!__symbolic_GRBgetcharattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcharattrelement", (gpointer *) &__symbolic_GRBgetcharattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcharattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcharattrelement.\n");
        }
    }
    return __symbolic_GRBgetcharattrelement(model, attrname, element, valueP);
}
int GRBsetcharattrelement (GRBmodel * model, const char *attrname, int element, char newvalue){
    if (!__symbolic_GRBsetcharattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetcharattrelement", (gpointer *) &__symbolic_GRBsetcharattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetcharattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetcharattrelement.\n");
        }
    }
    return __symbolic_GRBsetcharattrelement(model, attrname, element, newvalue);
}
int GRBgetcharattrarray (GRBmodel * model, const char *attrname, int first, int len, char *values){
    if (!__symbolic_GRBgetcharattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcharattrarray", (gpointer *) &__symbolic_GRBgetcharattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcharattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcharattrarray.\n");
        }
    }
    return __symbolic_GRBgetcharattrarray(model, attrname, first, len, values);
}
int GRBsetcharattrarray (GRBmodel * model, const char *attrname, int first, int len, char *newvalues){
    if (!__symbolic_GRBsetcharattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetcharattrarray", (gpointer *) &__symbolic_GRBsetcharattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetcharattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetcharattrarray.\n");
        }
    }
    return __symbolic_GRBsetcharattrarray(model, attrname, first, len, newvalues);
}
int GRBgetcharattrlist (GRBmodel * model, const char *attrname, int len, int *ind, char *values){
    if (!__symbolic_GRBgetcharattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcharattrlist", (gpointer *) &__symbolic_GRBgetcharattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcharattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcharattrlist.\n");
        }
    }
    return __symbolic_GRBgetcharattrlist(model, attrname, len, ind, values);
}
int GRBsetcharattrlist (GRBmodel * model, const char *attrname, int len, int *ind, char *newvalues){
    if (!__symbolic_GRBsetcharattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetcharattrlist", (gpointer *) &__symbolic_GRBsetcharattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetcharattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetcharattrlist.\n");
        }
    }
    return __symbolic_GRBsetcharattrlist(model, attrname, len, ind, newvalues);
}
int GRBgetdblattr (GRBmodel * model, const char *attrname, double *valueP){
    if (!__symbolic_GRBgetdblattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblattr", (gpointer *) &__symbolic_GRBgetdblattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblattr.\n");
        }
    }
    return __symbolic_GRBgetdblattr(model, attrname, valueP);
}
int GRBsetdblattr (GRBmodel * model, const char *attrname, double newvalue){
    if (!__symbolic_GRBsetdblattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetdblattr", (gpointer *) &__symbolic_GRBsetdblattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetdblattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetdblattr.\n");
        }
    }
    return __symbolic_GRBsetdblattr(model, attrname, newvalue);
}
int GRBgetdblattrelement (GRBmodel * model, const char *attrname, int element, double *valueP){
    if (!__symbolic_GRBgetdblattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblattrelement", (gpointer *) &__symbolic_GRBgetdblattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblattrelement.\n");
        }
    }
    return __symbolic_GRBgetdblattrelement(model, attrname, element, valueP);
}
int GRBsetdblattrelement (GRBmodel * model, const char *attrname, int element, double newvalue){
    if (!__symbolic_GRBsetdblattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetdblattrelement", (gpointer *) &__symbolic_GRBsetdblattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetdblattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetdblattrelement.\n");
        }
    }
    return __symbolic_GRBsetdblattrelement(model, attrname, element, newvalue);
}
int GRBgetdblattrarray (GRBmodel * model, const char *attrname, int first, int len, double *values){
    if (!__symbolic_GRBgetdblattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblattrarray", (gpointer *) &__symbolic_GRBgetdblattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblattrarray.\n");
        }
    }
    return __symbolic_GRBgetdblattrarray(model, attrname, first, len, values);
}
int GRBsetdblattrarray (GRBmodel * model, const char *attrname, int first, int len, double *newvalues){
    if (!__symbolic_GRBsetdblattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetdblattrarray", (gpointer *) &__symbolic_GRBsetdblattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetdblattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetdblattrarray.\n");
        }
    }
    return __symbolic_GRBsetdblattrarray(model, attrname, first, len, newvalues);
}
int GRBgetdblattrlist (GRBmodel * model, const char *attrname, int len, int *ind, double *values){
    if (!__symbolic_GRBgetdblattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblattrlist", (gpointer *) &__symbolic_GRBgetdblattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblattrlist.\n");
        }
    }
    return __symbolic_GRBgetdblattrlist(model, attrname, len, ind, values);
}
int GRBsetdblattrlist (GRBmodel * model, const char *attrname, int len, int *ind, double *newvalues){
    if (!__symbolic_GRBsetdblattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetdblattrlist", (gpointer *) &__symbolic_GRBsetdblattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetdblattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetdblattrlist.\n");
        }
    }
    return __symbolic_GRBsetdblattrlist(model, attrname, len, ind, newvalues);
}
int GRBgetstrattr (GRBmodel * model, const char *attrname, char **valueP){
    if (!__symbolic_GRBgetstrattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrattr", (gpointer *) &__symbolic_GRBgetstrattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrattr.\n");
        }
    }
    return __symbolic_GRBgetstrattr(model, attrname, valueP);
}
int GRBsetstrattr (GRBmodel * model, const char *attrname, char *newvalue){
    if (!__symbolic_GRBsetstrattr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetstrattr", (gpointer *) &__symbolic_GRBsetstrattr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetstrattr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetstrattr.\n");
        }
    }
    return __symbolic_GRBsetstrattr(model, attrname, newvalue);
}
int GRBgetstrattrelement (GRBmodel * model, const char *attrname, int element, char **valueP){
    if (!__symbolic_GRBgetstrattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrattrelement", (gpointer *) &__symbolic_GRBgetstrattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrattrelement.\n");
        }
    }
    return __symbolic_GRBgetstrattrelement(model, attrname, element, valueP);
}
int GRBsetstrattrelement (GRBmodel * model, const char *attrname, int element, char *newvalue){
    if (!__symbolic_GRBsetstrattrelement) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetstrattrelement", (gpointer *) &__symbolic_GRBsetstrattrelement)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetstrattrelement could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetstrattrelement.\n");
        }
    }
    return __symbolic_GRBsetstrattrelement(model, attrname, element, newvalue);
}
int GRBgetstrattrarray (GRBmodel * model, const char *attrname, int first, int len, char **values){
    if (!__symbolic_GRBgetstrattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrattrarray", (gpointer *) &__symbolic_GRBgetstrattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrattrarray.\n");
        }
    }
    return __symbolic_GRBgetstrattrarray(model, attrname, first, len, values);
}
int GRBsetstrattrarray (GRBmodel * model, const char *attrname, int first, int len, char **newvalues){
    if (!__symbolic_GRBsetstrattrarray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetstrattrarray", (gpointer *) &__symbolic_GRBsetstrattrarray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetstrattrarray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetstrattrarray.\n");
        }
    }
    return __symbolic_GRBsetstrattrarray(model, attrname, first, len, newvalues);
}
int GRBgetstrattrlist (GRBmodel * model, const char *attrname, int len, int *ind, char **values){
    if (!__symbolic_GRBgetstrattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrattrlist", (gpointer *) &__symbolic_GRBgetstrattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrattrlist.\n");
        }
    }
    return __symbolic_GRBgetstrattrlist(model, attrname, len, ind, values);
}
int GRBsetstrattrlist (GRBmodel * model, const char *attrname, int len, int *ind, char **newvalues){
    if (!__symbolic_GRBsetstrattrlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetstrattrlist", (gpointer *) &__symbolic_GRBsetstrattrlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetstrattrlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetstrattrlist.\n");
        }
    }
    return __symbolic_GRBsetstrattrlist(model, attrname, len, ind, newvalues);
}
int GRBsetcallbackfunc (GRBmodel * model, int ( * cb) (GRBmodel *model, void *cbdata, int where, void *usrdata), void *usrdata){
    if (!__symbolic_GRBsetcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetcallbackfunc", (gpointer *) &__symbolic_GRBsetcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetcallbackfunc.\n");
        }
    }
    return __symbolic_GRBsetcallbackfunc(model, cb, usrdata);
}
int GRBgetcallbackfunc (GRBmodel * model, int ( ** cbP) (GRBmodel *model, void *cbdata, int where, void *usrdata)){
    if (!__symbolic_GRBgetcallbackfunc) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcallbackfunc", (gpointer *) &__symbolic_GRBgetcallbackfunc)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcallbackfunc could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcallbackfunc.\n");
        }
    }
    return __symbolic_GRBgetcallbackfunc(model, cbP);
}
int GRBcbget (void *cbdata, int where, int what, void *resultP){
    if (!__symbolic_GRBcbget) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcbget", (gpointer *) &__symbolic_GRBcbget)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcbget could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcbget.\n");
        }
    }
    return __symbolic_GRBcbget(cbdata, where, what, resultP);
}
int GRBcbsolution (void *cbdata, const double *solution){
    if (!__symbolic_GRBcbsolution) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcbsolution", (gpointer *) &__symbolic_GRBcbsolution)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcbsolution could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcbsolution.\n");
        }
    }
    return __symbolic_GRBcbsolution(cbdata, solution);
}
int GRBcbcut (void *cbdata, int cutlen, const int *cutind, const double *cutval, char cutsense, double cutrhs){
    if (!__symbolic_GRBcbcut) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcbcut", (gpointer *) &__symbolic_GRBcbcut)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcbcut could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcbcut.\n");
        }
    }
    return __symbolic_GRBcbcut(cbdata, cutlen, cutind, cutval, cutsense, cutrhs);
}
int GRBgetcoeff (GRBmodel * model, int constr, int var, double *valP){
    if (!__symbolic_GRBgetcoeff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcoeff", (gpointer *) &__symbolic_GRBgetcoeff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcoeff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcoeff.\n");
        }
    }
    return __symbolic_GRBgetcoeff(model, constr, var, valP);
}
int GRBgetconstrs (GRBmodel * model, int *numnzP, int *cbeg, int *cind, double *cval, int start, int len){
    if (!__symbolic_GRBgetconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetconstrs", (gpointer *) &__symbolic_GRBgetconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetconstrs.\n");
        }
    }
    return __symbolic_GRBgetconstrs(model, numnzP, cbeg, cind, cval, start, len);
}
int GRBgetvars (GRBmodel * model, int *numnzP, int *vbeg, int *vind, double *vval, int start, int len){
    if (!__symbolic_GRBgetvars) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetvars", (gpointer *) &__symbolic_GRBgetvars)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetvars could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetvars.\n");
        }
    }
    return __symbolic_GRBgetvars(model, numnzP, vbeg, vind, vval, start, len);
}
int GRBgetsos (GRBmodel * model, int *nummembersP, int *sostype, int *beg, int *ind, double *weight, int start, int len){
    if (!__symbolic_GRBgetsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetsos", (gpointer *) &__symbolic_GRBgetsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetsos.\n");
        }
    }
    return __symbolic_GRBgetsos(model, nummembersP, sostype, beg, ind, weight, start, len);
}
int GRBoptimize (GRBmodel * model){
    if (!__symbolic_GRBoptimize) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBoptimize", (gpointer *) &__symbolic_GRBoptimize)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBoptimize could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBoptimize.\n");
        }
    }
    return __symbolic_GRBoptimize(model);
}
GRBmodel * GRBcopymodel (GRBmodel * model){
    if (!__symbolic_GRBcopymodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcopymodel", (gpointer *) &__symbolic_GRBcopymodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcopymodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcopymodel.\n");
        }
    }
    return __symbolic_GRBcopymodel(model);
}
GRBmodel * GRBfixedmodel (GRBmodel * model){
    if (!__symbolic_GRBfixedmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBfixedmodel", (gpointer *) &__symbolic_GRBfixedmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBfixedmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBfixedmodel.\n");
        }
    }
    return __symbolic_GRBfixedmodel(model);
}
int GRBgetcbwhatinfo (void *cbdata, int what, int *typeP, int *sizeP){
    if (!__symbolic_GRBgetcbwhatinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetcbwhatinfo", (gpointer *) &__symbolic_GRBgetcbwhatinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetcbwhatinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetcbwhatinfo.\n");
        }
    }
    return __symbolic_GRBgetcbwhatinfo(cbdata, what, typeP, sizeP);
}
GRBmodel * GRBrelaxmodel (GRBmodel * model){
    if (!__symbolic_GRBrelaxmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBrelaxmodel", (gpointer *) &__symbolic_GRBrelaxmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBrelaxmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBrelaxmodel.\n");
        }
    }
    return __symbolic_GRBrelaxmodel(model);
}
int GRBconverttofixed (GRBmodel * lp){
    if (!__symbolic_GRBconverttofixed) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBconverttofixed", (gpointer *) &__symbolic_GRBconverttofixed)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBconverttofixed could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBconverttofixed.\n");
        }
    }
    return __symbolic_GRBconverttofixed(lp);
}
GRBmodel * GRBpresolvemodel (GRBmodel * model){
    if (!__symbolic_GRBpresolvemodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBpresolvemodel", (gpointer *) &__symbolic_GRBpresolvemodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBpresolvemodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBpresolvemodel.\n");
        }
    }
    return __symbolic_GRBpresolvemodel(model);
}
GRBmodel * GRBiismodel (GRBmodel * model){
    if (!__symbolic_GRBiismodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBiismodel", (gpointer *) &__symbolic_GRBiismodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBiismodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBiismodel.\n");
        }
    }
    return __symbolic_GRBiismodel(model);
}
GRBmodel * GRBfeasibility (GRBmodel * model){
    if (!__symbolic_GRBfeasibility) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBfeasibility", (gpointer *) &__symbolic_GRBfeasibility)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBfeasibility could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBfeasibility.\n");
        }
    }
    return __symbolic_GRBfeasibility(model);
}
int GRBreadmodel (GRBenv * env, const char *filename, GRBmodel ** modelP){
    if (!__symbolic_GRBreadmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBreadmodel", (gpointer *) &__symbolic_GRBreadmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBreadmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBreadmodel.\n");
        }
    }
    return __symbolic_GRBreadmodel(env, filename, modelP);
}
int GRBread (GRBmodel * model, const char *filename){
    if (!__symbolic_GRBread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBread", (gpointer *) &__symbolic_GRBread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBread.\n");
        }
    }
    return __symbolic_GRBread(model, filename);
}
int GRBwrite (GRBmodel * model, const char *filename){
    if (!__symbolic_GRBwrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBwrite", (gpointer *) &__symbolic_GRBwrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBwrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBwrite.\n");
        }
    }
    return __symbolic_GRBwrite(model, filename);
}
int GRBnewmodel (GRBenv * env, GRBmodel ** modelP, const char *Pname, int numvars, double *obj, double *lb, double *ub, char *vtype, char **varnames){
    if (!__symbolic_GRBnewmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBnewmodel", (gpointer *) &__symbolic_GRBnewmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBnewmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBnewmodel.\n");
        }
    }
    return __symbolic_GRBnewmodel(env, modelP, Pname, numvars, obj, lb, ub, vtype, varnames);
}
int GRBloadmodel (GRBenv * env, GRBmodel ** modelP, const char *Pname, int numvars, int numconstrs, int objsense, double objcon, double *obj, char *sense, double *rhs, int *vbeg, int *vlen, int *vind, double *vval, double *lb, double *ub, char *vtype, char **varnames, char **constrnames){
    if (!__symbolic_GRBloadmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBloadmodel", (gpointer *) &__symbolic_GRBloadmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBloadmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBloadmodel.\n");
        }
    }
    return __symbolic_GRBloadmodel(env, modelP, Pname, numvars, numconstrs, objsense, objcon, obj, sense, rhs, vbeg, vlen, vind, vval, lb, ub, vtype, varnames, constrnames);
}
int GRBaddvar (GRBmodel * model, int numnz, int *vind, double *vval, double obj, double lb, double ub, char vtype, char *varname){
    if (!__symbolic_GRBaddvar) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddvar", (gpointer *) &__symbolic_GRBaddvar)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddvar could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddvar.\n");
        }
    }
    return __symbolic_GRBaddvar(model, numnz, vind, vval, obj, lb, ub, vtype, varname);
}
int GRBaddvars (GRBmodel * model, int numvars, int numnz, int *vbeg, int *vind, double *vval, double *obj, double *lb, double *ub, char *vtype, char **varnames){
    if (!__symbolic_GRBaddvars) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddvars", (gpointer *) &__symbolic_GRBaddvars)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddvars could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddvars.\n");
        }
    }
    return __symbolic_GRBaddvars(model, numvars, numnz, vbeg, vind, vval, obj, lb, ub, vtype, varnames);
}
int GRBaddconstr (GRBmodel * model, int numnz, int *cind, double *cval, char sense, double rhs, char *constrnames){
    if (!__symbolic_GRBaddconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddconstr", (gpointer *) &__symbolic_GRBaddconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddconstr.\n");
        }
    }
    return __symbolic_GRBaddconstr(model, numnz, cind, cval, sense, rhs, constrnames);
}
int GRBaddconstrs (GRBmodel * model, int numconstrs, int numnz, int *cbeg, int *cind, double *cval, char *sense, double *rhs, char **constrnames){
    if (!__symbolic_GRBaddconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddconstrs", (gpointer *) &__symbolic_GRBaddconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddconstrs.\n");
        }
    }
    return __symbolic_GRBaddconstrs(model, numconstrs, numnz, cbeg, cind, cval, sense, rhs, constrnames);
}
int GRBaddrangeconstr (GRBmodel * model, int numnz, int *cind, double *cval, double lower, double upper, char *constrnames){
    if (!__symbolic_GRBaddrangeconstr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddrangeconstr", (gpointer *) &__symbolic_GRBaddrangeconstr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddrangeconstr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddrangeconstr.\n");
        }
    }
    return __symbolic_GRBaddrangeconstr(model, numnz, cind, cval, lower, upper, constrnames);
}
int GRBaddrangeconstrs (GRBmodel * model, int numconstrs, int numnz, int *cbeg, int *cind, double *cval, double *lower, double *upper, char **constrnames){
    if (!__symbolic_GRBaddrangeconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddrangeconstrs", (gpointer *) &__symbolic_GRBaddrangeconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddrangeconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddrangeconstrs.\n");
        }
    }
    return __symbolic_GRBaddrangeconstrs(model, numconstrs, numnz, cbeg, cind, cval, lower, upper, constrnames);
}
int GRBaddsos (GRBmodel * model, int numsos, int nummembers, int *types, int *beg, int *ind, double *weight){
    if (!__symbolic_GRBaddsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBaddsos", (gpointer *) &__symbolic_GRBaddsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBaddsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBaddsos.\n");
        }
    }
    return __symbolic_GRBaddsos(model, numsos, nummembers, types, beg, ind, weight);
}
int GRBdelvars (GRBmodel * model, int len, int *ind){
    if (!__symbolic_GRBdelvars) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBdelvars", (gpointer *) &__symbolic_GRBdelvars)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBdelvars could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBdelvars.\n");
        }
    }
    return __symbolic_GRBdelvars(model, len, ind);
}
int GRBdelconstrs (GRBmodel * model, int len, int *ind){
    if (!__symbolic_GRBdelconstrs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBdelconstrs", (gpointer *) &__symbolic_GRBdelconstrs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBdelconstrs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBdelconstrs.\n");
        }
    }
    return __symbolic_GRBdelconstrs(model, len, ind);
}
int GRBdelsos (GRBmodel * model, int len, int *ind){
    if (!__symbolic_GRBdelsos) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBdelsos", (gpointer *) &__symbolic_GRBdelsos)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBdelsos could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBdelsos.\n");
        }
    }
    return __symbolic_GRBdelsos(model, len, ind);
}
int GRBchgcoeffs (GRBmodel * model, int cnt, int *cind, int *vind, double *val){
    if (!__symbolic_GRBchgcoeffs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBchgcoeffs", (gpointer *) &__symbolic_GRBchgcoeffs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBchgcoeffs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBchgcoeffs.\n");
        }
    }
    return __symbolic_GRBchgcoeffs(model, cnt, cind, vind, val);
}
int GRBupdatemodel (GRBmodel * model){
    if (!__symbolic_GRBupdatemodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBupdatemodel", (gpointer *) &__symbolic_GRBupdatemodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBupdatemodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBupdatemodel.\n");
        }
    }
    return __symbolic_GRBupdatemodel(model);
}
int GRBresetmodel (GRBmodel * model){
    if (!__symbolic_GRBresetmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBresetmodel", (gpointer *) &__symbolic_GRBresetmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBresetmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBresetmodel.\n");
        }
    }
    return __symbolic_GRBresetmodel(model);
}
int GRBfreemodel (GRBmodel * model){
    if (!__symbolic_GRBfreemodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBfreemodel", (gpointer *) &__symbolic_GRBfreemodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBfreemodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBfreemodel.\n");
        }
    }
    return __symbolic_GRBfreemodel(model);
}
int GRBcomputeIIS (GRBmodel * lp){
    if (!__symbolic_GRBcomputeIIS) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcomputeIIS", (gpointer *) &__symbolic_GRBcomputeIIS)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcomputeIIS could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcomputeIIS.\n");
        }
    }
    return __symbolic_GRBcomputeIIS(lp);
}
int GRBstrongbranch (GRBmodel * model, int num, int *cand, double *downobjbd, double *upobjbd, int *statusP){
    if (!__symbolic_GRBstrongbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBstrongbranch", (gpointer *) &__symbolic_GRBstrongbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBstrongbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBstrongbranch.\n");
        }
    }
    return __symbolic_GRBstrongbranch(model, num, cand, downobjbd, upobjbd, statusP);
}
int GRBcheckmodel (GRBmodel * model){
    if (!__symbolic_GRBcheckmodel) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBcheckmodel", (gpointer *) &__symbolic_GRBcheckmodel)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBcheckmodel could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBcheckmodel.\n");
        }
    }
    return __symbolic_GRBcheckmodel(model);
}
void GRBsetsignal (GRBmodel * model){
    if (!__symbolic_GRBsetsignal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetsignal", (gpointer *) &__symbolic_GRBsetsignal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetsignal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetsignal.\n");
        }
    }
    return __symbolic_GRBsetsignal(model);
}
void GRBterminate (GRBmodel * model){
    if (!__symbolic_GRBterminate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBterminate", (gpointer *) &__symbolic_GRBterminate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBterminate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBterminate.\n");
        }
    }
    return __symbolic_GRBterminate(model);
}
void GRBmsg (GRBenv * env, const char *message){
    if (!__symbolic_GRBmsg) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBmsg", (gpointer *) &__symbolic_GRBmsg)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBmsg could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBmsg.\n");
        }
    }
    return __symbolic_GRBmsg(env, message);
}
int GRBgetlogfile (GRBenv * env, FILE ** logfileP){
    if (!__symbolic_GRBgetlogfile) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetlogfile", (gpointer *) &__symbolic_GRBgetlogfile)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetlogfile could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetlogfile.\n");
        }
    }
    return __symbolic_GRBgetlogfile(env, logfileP);
}
int GRBsetlogfile (GRBenv * env, FILE * logfile){
    if (!__symbolic_GRBsetlogfile) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetlogfile", (gpointer *) &__symbolic_GRBsetlogfile)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetlogfile could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetlogfile.\n");
        }
    }
    return __symbolic_GRBsetlogfile(env, logfile);
}
int GRBgetintparam (GRBenv * env, const char *paramname, int *valueP){
    if (!__symbolic_GRBgetintparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintparam", (gpointer *) &__symbolic_GRBgetintparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintparam.\n");
        }
    }
    return __symbolic_GRBgetintparam(env, paramname, valueP);
}
int GRBgetdblparam (GRBenv * env, const char *paramname, double *valueP){
    if (!__symbolic_GRBgetdblparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblparam", (gpointer *) &__symbolic_GRBgetdblparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblparam.\n");
        }
    }
    return __symbolic_GRBgetdblparam(env, paramname, valueP);
}
int GRBgetstrparam (GRBenv * env, const char *paramname, char *valueP){
    if (!__symbolic_GRBgetstrparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrparam", (gpointer *) &__symbolic_GRBgetstrparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrparam.\n");
        }
    }
    return __symbolic_GRBgetstrparam(env, paramname, valueP);
}
int GRBgetintparaminfo (GRBenv * env, const char *paramname, int *valueP, int *minP, int *maxP, int *defP){
    if (!__symbolic_GRBgetintparaminfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetintparaminfo", (gpointer *) &__symbolic_GRBgetintparaminfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetintparaminfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetintparaminfo.\n");
        }
    }
    return __symbolic_GRBgetintparaminfo(env, paramname, valueP, minP, maxP, defP);
}
int GRBgetdblparaminfo (GRBenv * env, const char *paramname, double *valueP, double *minP, double *maxP, double *defP){
    if (!__symbolic_GRBgetdblparaminfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetdblparaminfo", (gpointer *) &__symbolic_GRBgetdblparaminfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetdblparaminfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetdblparaminfo.\n");
        }
    }
    return __symbolic_GRBgetdblparaminfo(env, paramname, valueP, minP, maxP, defP);
}
int GRBgetstrparaminfo (GRBenv * env, const char *paramname, char *valueP, char *defP){
    if (!__symbolic_GRBgetstrparaminfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetstrparaminfo", (gpointer *) &__symbolic_GRBgetstrparaminfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetstrparaminfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetstrparaminfo.\n");
        }
    }
    return __symbolic_GRBgetstrparaminfo(env, paramname, valueP, defP);
}
int GRBsetintparam (GRBenv * env, const char *paramname, int value){
    if (!__symbolic_GRBsetintparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetintparam", (gpointer *) &__symbolic_GRBsetintparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetintparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetintparam.\n");
        }
    }
    return __symbolic_GRBsetintparam(env, paramname, value);
}
int GRBsetdblparam (GRBenv * env, const char *paramname, double value){
    if (!__symbolic_GRBsetdblparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetdblparam", (gpointer *) &__symbolic_GRBsetdblparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetdblparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetdblparam.\n");
        }
    }
    return __symbolic_GRBsetdblparam(env, paramname, value);
}
int GRBsetstrparam (GRBenv * env, const char *paramname, const char *value){
    if (!__symbolic_GRBsetstrparam) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBsetstrparam", (gpointer *) &__symbolic_GRBsetstrparam)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBsetstrparam could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBsetstrparam.\n");
        }
    }
    return __symbolic_GRBsetstrparam(env, paramname, value);
}
int GRBgetparamtype (GRBenv * env, const char *paramname){
    if (!__symbolic_GRBgetparamtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetparamtype", (gpointer *) &__symbolic_GRBgetparamtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetparamtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetparamtype.\n");
        }
    }
    return __symbolic_GRBgetparamtype(env, paramname);
}
int GRBresetparams (GRBenv * env){
    if (!__symbolic_GRBresetparams) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBresetparams", (gpointer *) &__symbolic_GRBresetparams)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBresetparams could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBresetparams.\n");
        }
    }
    return __symbolic_GRBresetparams(env);
}
int GRBwriteparams (GRBenv * env, const char *filename){
    if (!__symbolic_GRBwriteparams) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBwriteparams", (gpointer *) &__symbolic_GRBwriteparams)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBwriteparams could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBwriteparams.\n");
        }
    }
    return __symbolic_GRBwriteparams(env, filename);
}
int GRBreadparams (GRBenv * env, const char *filename){
    if (!__symbolic_GRBreadparams) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBreadparams", (gpointer *) &__symbolic_GRBreadparams)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBreadparams could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBreadparams.\n");
        }
    }
    return __symbolic_GRBreadparams(env, filename);
}
int GRBgetnumparams (GRBenv * env){
    if (!__symbolic_GRBgetnumparams) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetnumparams", (gpointer *) &__symbolic_GRBgetnumparams)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetnumparams could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetnumparams.\n");
        }
    }
    return __symbolic_GRBgetnumparams(env);
}
int GRBgetparamname (GRBenv * env, int i, char **paramnameP){
    if (!__symbolic_GRBgetparamname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetparamname", (gpointer *) &__symbolic_GRBgetparamname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetparamname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetparamname.\n");
        }
    }
    return __symbolic_GRBgetparamname(env, i, paramnameP);
}
int GRBloadenv (GRBenv ** envP, const char *logfilename){
    if (!__symbolic_GRBloadenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBloadenv", (gpointer *) &__symbolic_GRBloadenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBloadenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBloadenv.\n");
        }
    }
    return __symbolic_GRBloadenv(envP, logfilename);
}
GRBenv * GRBgetenv (GRBmodel * model){
    if (!__symbolic_GRBgetenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetenv", (gpointer *) &__symbolic_GRBgetenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetenv.\n");
        }
    }
    return __symbolic_GRBgetenv(model);
}
void GRBfreeenv (GRBenv * env){
    if (!__symbolic_GRBfreeenv) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBfreeenv", (gpointer *) &__symbolic_GRBfreeenv)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBfreeenv could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBfreeenv.\n");
        }
    }
    return __symbolic_GRBfreeenv(env);
}
const char * GRBgeterrormsg (GRBenv * env){
    if (!__symbolic_GRBgeterrormsg) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgeterrormsg", (gpointer *) &__symbolic_GRBgeterrormsg)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgeterrormsg could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgeterrormsg.\n");
        }
    }
    return __symbolic_GRBgeterrormsg(env);
}
const char * GRBgetmerrormsg (GRBmodel * model){
    if (!__symbolic_GRBgetmerrormsg) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBgetmerrormsg", (gpointer *) &__symbolic_GRBgetmerrormsg)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBgetmerrormsg could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBgetmerrormsg.\n");
        }
    }
    return __symbolic_GRBgetmerrormsg(model);
}
void GRBversion (int *majorP, int *minorP, int *technicalP){
    if (!__symbolic_GRBversion) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBversion", (gpointer *) &__symbolic_GRBversion)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBversion could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBversion.\n");
        }
    }
    return __symbolic_GRBversion(majorP, minorP, technicalP);
}
char * GRBplatform (void){
    if (!__symbolic_GRBplatform) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_GUROBI_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libgurobi.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "GRBplatform", (gpointer *) &__symbolic_GRBplatform)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol GRBplatform could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol GRBplatform.\n");
        }
    }
    return __symbolic_GRBplatform();
}
