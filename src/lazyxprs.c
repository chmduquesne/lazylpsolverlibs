#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xprs.h>

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
    char *LAZYLPSOLVERLIBS_XPRS_LIB;
    LAZYLPSOLVERLIBS_XPRS_LIB = getenv("LAZYLPSOLVERLIBS_XPRS_LIB");
    if (!module) {
        DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", "/usr/lib/libxprs.so");
        module = g_module_open("/usr/lib/libxprs.so", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
    }
    if (LAZYLPSOLVERLIBS_XPRS_LIB != NULL) {
        if (!module) {
            DEBUG_PRINT ("lazylpsolverlibs: attempting to load library from %s\n", LAZYLPSOLVERLIBS_XPRS_LIB);
            module = g_module_open(LAZYLPSOLVERLIBS_XPRS_LIB, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        }
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "xprs.dll");
#else
        path = g_module_build_path(NULL, "xprs");
#endif
        DEBUG_PRINT("lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    return (module != NULL);
}

/* imported functions */

int (*__symbolic_XPRScopycallbacks) (XPRSprob dest, XPRSprob src) = NULL;
int (*__symbolic_XPRScopycontrols) (XPRSprob dest, XPRSprob src) = NULL;
int (*__symbolic_XPRScopyprob) (XPRSprob dest, XPRSprob src, const char *probname) = NULL;
int (*__symbolic_XPRScreateprob) (XPRSprob * _probholder) = NULL;
int (*__symbolic_XPRSdestroyprob) (XPRSprob _prob) = NULL;
int (*__symbolic_XPRSinit) (const char *path) = NULL;
int (*__symbolic_XPRSfree) (void) = NULL;
int (*__symbolic_XPRSgetbanner) (char *banner) = NULL;
int (*__symbolic_XPRSgetversion) (char *version) = NULL;
int (*__symbolic_XPRSgetdaysleft) (int *daysleft) = NULL;
int (*__symbolic_XPRSsetcheckedmode) (int checked_mode) = NULL;
int (*__symbolic_XPRSgetcheckedmode) (int *r_checked_mode) = NULL;
int (*__symbolic_XPRSlicense) (int *_i1, char *_c1) = NULL;
int (*__symbolic_XPRSbeginlicensing) (int *r_dontAlreadyHaveLicense) = NULL;
int (*__symbolic_XPRSendlicensing) (void) = NULL;
int (*__symbolic_XPRSgetlicerrmsg) (char *msg, int len) = NULL;
int (*__symbolic_XPRSsetlogfile) (XPRSprob prob, const char *logname) = NULL;
int (*__symbolic_XPRSsetintcontrol) (XPRSprob prob, int _index, int _ivalue) = NULL;
int (*__symbolic_XPRSsetintcontrol64) (XPRSprob prob, int _index, long _ivalue) = NULL;
int (*__symbolic_XPRSsetdblcontrol) (XPRSprob prob, int _index, double _dvalue) = NULL;
int (*__symbolic_XPRSinterrupt) (XPRSprob prob, int reason) = NULL;
int (*__symbolic_XPRSgetprobname) (XPRSprob prob, char *_svalue) = NULL;
int (*__symbolic_XPRSgetqobj) (XPRSprob prob, int _icol, int _jcol, double *_dval) = NULL;
int (*__symbolic_XPRSsetprobname) (XPRSprob prob, const char *_svalue) = NULL;
int (*__symbolic_XPRSsetstrcontrol) (XPRSprob prob, int _index, const char *_svalue) = NULL;
int (*__symbolic_XPRSgetintcontrol) (XPRSprob prob, int _index, int *_ivalue) = NULL;
int (*__symbolic_XPRSgetintcontrol64) (XPRSprob prob, int _index, long * _ivalue) = NULL;
int (*__symbolic_XPRSgetdblcontrol) (XPRSprob prob, int _index, double *_dvalue) = NULL;
int (*__symbolic_XPRSgetstrcontrol) (XPRSprob prob, int _index, char *_svalue) = NULL;
int (*__symbolic_XPRSgetintattrib) (XPRSprob prob, int _index, int *_ivalue) = NULL;
int (*__symbolic_XPRSgetintattrib64) (XPRSprob prob, int _index, long * _ivalue) = NULL;
int (*__symbolic_XPRSgetstrattrib) (XPRSprob prob, int _index, char *_cvalue) = NULL;
int (*__symbolic_XPRSgetdblattrib) (XPRSprob prob, int _index, double *_dvalue) = NULL;
int (*__symbolic_XPRSsetdefaultcontrol) (XPRSprob prob, int _index) = NULL;
int (*__symbolic_XPRSsetdefaults) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSgetcontrolinfo) (XPRSprob prob, const char *sCaName, int *iHeaderId, int *iTypeinfo) = NULL;
int (*__symbolic_XPRSgetattribinfo) (XPRSprob prob, const char *sCaName, int *iHeaderId, int *iTypeinfo) = NULL;
int (*__symbolic_XPRSgoal) (XPRSprob prob, const char *_filename, const char *_sflags) = NULL;
int (*__symbolic_XPRSreadprob) (XPRSprob prob, const char *_sprobname, const char *_sflags) = NULL;
int (*__symbolic_XPRSloadlp) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[]) = NULL;
int (*__symbolic_XPRSloadlp64) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[]) = NULL;
int (*__symbolic_XPRSloadqp) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[]) = NULL;
int (*__symbolic_XPRSloadqp64) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[]) = NULL;
int (*__symbolic_XPRSloadqglobal) (XPRSprob prob, const char *probname, int ncols, int nrows, const char qsenx[], const double rhsx[], const double range[], const double objx[], const int matbeg[], const int matcnt[], const int matind[], const double dmtval[], const double bndl[], const double bndu[], int nquads, const int mqcol1[], const int mqcol2[], const double dqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const int msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRSloadqglobal64) (XPRSprob prob, const char *probname, int ncols, int nrows, const char qsenx[], const double rhsx[], const double range[], const double objx[], const long matbeg[], const int matcnt[], const int matind[], const double dmtval[], const double bndl[], const double bndu[], long nquads, const int mqcol1[], const int mqcol2[], const double dqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const long msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRSfixglobal) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSfixglobals) (XPRSprob prob, int ifround) = NULL;
int (*__symbolic_XPRSloadmodelcuts) (XPRSprob prob, int nmodcuts, const int _mrows[]) = NULL;
int (*__symbolic_XPRSloaddelayedrows) (XPRSprob prob, int nrows, const int _mrows[]) = NULL;
int (*__symbolic_XPRSloaddirs) (XPRSprob prob, int ndirs, const int _mcols[], const int _mpri[], const char _sbr[], const double dupc[], const double ddpc[]) = NULL;
int (*__symbolic_XPRSloadbranchdirs) (XPRSprob prob, int ndirs, const int _mcols[], const int _mbranch[]) = NULL;
int (*__symbolic_XPRSloadpresolvedirs) (XPRSprob prob, int ndirs, const int _mcols[], const int _mpri[], const char _sbr[], const double dupc[], const double ddpc[]) = NULL;
int (*__symbolic_XPRSgetdirs) (XPRSprob prob, int *ndirs, int _mcols[], int _mpri[], char _sbr[], double dupc[], double ddpc[]) = NULL;
int (*__symbolic_XPRSloadglobal) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int ngents, int nsets, const char _qgtype[], const int _mgcols[], const double _dlim[], const char _stype[], const int _msstart[], const int _mscols[], const double _dref[]) = NULL;
int (*__symbolic_XPRSloadglobal64) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int ngents, int nsets, const char _qgtype[], const int _mgcols[], const double _dlim[], const char _stype[], const long _msstart[], const int _mscols[], const double _dref[]) = NULL;
int (*__symbolic_XPRSaddnames) (XPRSprob prob, int _itype, const char _sname[], int first, int last) = NULL;
int (*__symbolic_XPRSaddsetnames) (XPRSprob prob, const char _sname[], int first, int last) = NULL;
int (*__symbolic_XPRSscale) (XPRSprob prob, const int mrscal[], const int mcscal[]) = NULL;
int (*__symbolic_XPRSreaddirs) (XPRSprob prob, const char *_sfilename) = NULL;
int (*__symbolic_XPRSwritedirs) (XPRSprob prob, const char *_sfilename) = NULL;
int (*__symbolic_XPRSsetindicators) (XPRSprob prob, int nrows, const int _mrows[], const int _inds[], const int _comps[]) = NULL;
int (*__symbolic_XPRSgetindicators) (XPRSprob prob, int _inds[], int _comps[], int first, int last) = NULL;
int (*__symbolic_XPRSdelindicators) (XPRSprob prob, int first, int last) = NULL;
int (*__symbolic_XPRSminim) (XPRSprob prob, const char *_sflags) = NULL;
int (*__symbolic_XPRSmaxim) (XPRSprob prob, const char *_sflags) = NULL;
int (*__symbolic_XPRSlpoptimize) (XPRSprob prob, const char *_sflags) = NULL;
int (*__symbolic_XPRSmipoptimize) (XPRSprob prob, const char *_sflags) = NULL;
int (*__symbolic_XPRSrange) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSgetrowrange) (XPRSprob prob, double _upact[], double _loact[], double _uup[], double _udn[]) = NULL;
int (*__symbolic_XPRSgetcolrange) (XPRSprob prob, double _upact[], double _loact[], double _uup[], double _udn[], double _ucost[], double _lcost[]) = NULL;
int (*__symbolic_XPRSgetpivotorder) (XPRSprob prob, int mpiv[]) = NULL;
int (*__symbolic_XPRSgetpresolvemap) (XPRSprob prob, int rowmap[], int colmap[]) = NULL;
int (*__symbolic_XPRSreadbasis) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSwritebasis) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSglobal) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSinitglobal) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSwriteprtsol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSalter) (XPRSprob prob, const char *_sfilename) = NULL;
int (*__symbolic_XPRSwritesol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSwritebinsol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSreadbinsol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSwriteslxsol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSreadslxsol) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSwriteprtrange) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSwriterange) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSgetsol) (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]) = NULL;
int (*__symbolic_XPRSgetpresolvesol) (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]) = NULL;
int (*__symbolic_XPRSgetinfeas) (XPRSprob prob, int *npv, int *nps, int *nds, int *ndv, int mx[], int mslack[], int mdual[], int mdj[]) = NULL;
int (*__symbolic_XPRSgetscaledinfeas) (XPRSprob prob, int *npv, int *nps, int *nds, int *ndv, int mx[], int mslack[], int mdual[], int mdj[]) = NULL;
int (*__symbolic_XPRSgetunbvec) (XPRSprob prob, int *icol) = NULL;
int (*__symbolic_XPRSbtran) (XPRSprob prob, double dwork[]) = NULL;
int (*__symbolic_XPRSftran) (XPRSprob prob, double dwork[]) = NULL;
int (*__symbolic_XPRSgetobj) (XPRSprob prob, double _dobj[], int first, int last) = NULL;
int (*__symbolic_XPRSgetrhs) (XPRSprob prob, double _drhs[], int first, int last) = NULL;
int (*__symbolic_XPRSgetrhsrange) (XPRSprob prob, double _drng[], int first, int last) = NULL;
int (*__symbolic_XPRSgetlb) (XPRSprob prob, double _dbdl[], int first, int last) = NULL;
int (*__symbolic_XPRSgetub) (XPRSprob prob, double _dbdu[], int first, int last) = NULL;
int (*__symbolic_XPRSgetcols) (XPRSprob prob, int _mstart[], int _mrwind[], double _dmatval[], int maxcoeffs, int *ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetcols64) (XPRSprob prob, long _mstart[], int _mrwind[], double _dmatval[], long maxcoeffs, long * ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetrows) (XPRSprob prob, int _mstart[], int _mclind[], double _dmatval[], int maxcoeffs, int *ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetrows64) (XPRSprob prob, long _mstart[], int _mclind[], double _dmatval[], long maxcoeffs, long * ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetcoef) (XPRSprob prob, int _irow, int _icol, double *_dval) = NULL;
int (*__symbolic_XPRSgetmqobj) (XPRSprob prob, int _mstart[], int _mclind[], double _dobjval[], int maxcoeffs, int *ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetmqobj64) (XPRSprob prob, long _mstart[], int _mclind[], double _dobjval[], long maxcoeffs, long * ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSiisclear) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSiisfirst) (XPRSprob prob, int ifiis, int *status_code) = NULL;
int (*__symbolic_XPRSiisnext) (XPRSprob prob, int *status_code) = NULL;
int (*__symbolic_XPRSiisstatus) (XPRSprob prob, int *iiscount, int rowsizes[], int colsizes[], double suminfeas[], int numinfeas[]) = NULL;
int (*__symbolic_XPRSiisall) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSiiswrite) (XPRSprob prob, int number, const char *fn, int filetype, const char *typeflags) = NULL;
int (*__symbolic_XPRSiisisolations) (XPRSprob prob, int number) = NULL;
int (*__symbolic_XPRSgetiisdata) (XPRSprob prob, int number, int *rownumber, int *colnumber, int miisrow[], int miiscol[], char constrainttype[], char colbndtype[], double duals[], double rdcs[], char isolationrows[], char isolationcols[]) = NULL;
int (*__symbolic_XPRSgetiis) (XPRSprob prob, int *ncols, int *nrows, int _miiscol[], int _miisrow[]) = NULL;
int (*__symbolic_XPRSgetpresolvebasis) (XPRSprob prob, int _mrowstatus[], int _mcolstatus[]) = NULL;
int (*__symbolic_XPRSloadpresolvebasis) (XPRSprob prob, const int _mrowstatus[], const int _mcolstatus[]) = NULL;
int (*__symbolic_XPRSgetglobal) (XPRSprob prob, int *ngents, int *nsets, char _sgtype[], int _mgcols[], double _dlim[], char _sstype[], int _msstart[], int _mscols[], double _dref[]) = NULL;
int (*__symbolic_XPRSgetglobal64) (XPRSprob prob, int *ngents, int *nsets, char _sgtype[], int _mgcols[], double _dlim[], char _sstype[], long _msstart[], int _mscols[], double _dref[]) = NULL;
int (*__symbolic_XPRSwriteprob) (XPRSprob prob, const char *_sfilename, const char *_sflags) = NULL;
int (*__symbolic_XPRSgetnames) (XPRSprob prob, int _itype, char _sbuff[], int first, int last) = NULL;
int (*__symbolic_XPRSgetrowtype) (XPRSprob prob, char _srowtype[], int first, int last) = NULL;
int (*__symbolic_XPRSloadsecurevecs) (XPRSprob prob, int nrows, int ncols, const int mrow[], const int mcol[]) = NULL;
int (*__symbolic_XPRSgetcoltype) (XPRSprob prob, char _coltype[], int first, int last) = NULL;
int (*__symbolic_XPRSgetbasis) (XPRSprob prob, int _mrowstatus[], int _mcolstatus[]) = NULL;
int (*__symbolic_XPRSloadbasis) (XPRSprob prob, const int _mrowstatus[], const int _mcolstatus[]) = NULL;
int (*__symbolic_XPRSgetindex) (XPRSprob prob, int _itype, const char *_sname, int *_iseq) = NULL;
int (*__symbolic_XPRSaddrows) (XPRSprob prob, int nrows, int ncoeffs, const char _srowtype[], const double _drhs[], const double _drng[], const int _mstart[], const int _mclind[], const double _dmatval[]) = NULL;
int (*__symbolic_XPRSaddrows64) (XPRSprob prob, int nrows, long ncoeffs, const char _srowtype[], const double _drhs[], const double _drng[], const long _mstart[], const int _mclind[], const double _dmatval[]) = NULL;
int (*__symbolic_XPRSdelrows) (XPRSprob prob, int nrows, const int _mindex[]) = NULL;
int (*__symbolic_XPRSaddcols) (XPRSprob prob, int ncols, int ncoeffs, const double _dobj[], const int _mstart[], const int _mrwind[], const double _dmatval[], const double _dbdl[], const double _dbdu[]) = NULL;
int (*__symbolic_XPRSaddcols64) (XPRSprob prob, int ncols, long ncoeffs, const double _dobj[], const long _mstart[], const int _mrwind[], const double _dmatval[], const double _dbdl[], const double _dbdu[]) = NULL;
int (*__symbolic_XPRSdelcols) (XPRSprob prob, int ncols, const int _mindex[]) = NULL;
int (*__symbolic_XPRSchgcoltype) (XPRSprob prob, int ncols, const int _mindex[], const char _coltype[]) = NULL;
int (*__symbolic_XPRSchgrowtype) (XPRSprob prob, int nrows, const int _mindex[], const char _srowtype[]) = NULL;
int (*__symbolic_XPRSchgbounds) (XPRSprob prob, int nbnds, const int _mindex[], const char _sboundtype[], const double _dbnd[]) = NULL;
int (*__symbolic_XPRSchgobj) (XPRSprob prob, int ncols, const int _mindex[], const double _dobj[]) = NULL;
int (*__symbolic_XPRSchgcoef) (XPRSprob prob, int _irow, int _icol, double _dval) = NULL;
int (*__symbolic_XPRSchgmcoef) (XPRSprob prob, int ncoeffs, const int _mrow[], const int _mcol[], const double _dval[]) = NULL;
int (*__symbolic_XPRSchgmcoef64) (XPRSprob prob, long ncoeffs, const int _mrow[], const int _mcol[], const double _dval[]) = NULL;
int (*__symbolic_XPRSchgmqobj) (XPRSprob prob, int ncols, const int _mcol1[], const int _mcol2[], const double _dval[]) = NULL;
int (*__symbolic_XPRSchgmqobj64) (XPRSprob prob, long ncols, const int _mcol1[], const int _mcol2[], const double _dval[]) = NULL;
int (*__symbolic_XPRSchgqobj) (XPRSprob prob, int _icol, int _jcol, double _dval) = NULL;
int (*__symbolic_XPRSchgrhs) (XPRSprob prob, int nrows, const int _mindex[], const double _drhs[]) = NULL;
int (*__symbolic_XPRSchgrhsrange) (XPRSprob prob, int nrows, const int _mindex[], const double _drng[]) = NULL;
int (*__symbolic_XPRSchgobjsense) (XPRSprob prob, int objsense) = NULL;
int (*__symbolic_XPRSchgglblimit) (XPRSprob prob, int ncols, const int _mindex[], const double _dlimit[]) = NULL;
int (*__symbolic_XPRSsave) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSrestore) (XPRSprob prob, const char *_sprobname, const char *_force) = NULL;
int (*__symbolic_XPRSpivot) (XPRSprob prob, int _in, int _out) = NULL;
int (*__symbolic_XPRSgetpivots) (XPRSprob prob, int _in, int _mout[], double _dout[], double *_dobjo, int *npiv, int maxpiv) = NULL;
int (*__symbolic_XPRSaddcuts) (XPRSprob prob, int ncuts, const int mtype[], const char qrtype[], const double drhs[], const int mstart[], const int mcols[], const double dmatval[]) = NULL;
int (*__symbolic_XPRSaddcuts64) (XPRSprob prob, int ncuts, const int mtype[], const char qrtype[], const double drhs[], const long mstart[], const int mcols[], const double dmatval[]) = NULL;
int (*__symbolic_XPRSdelcuts) (XPRSprob prob, int ibasis, int itype, int interp, double delta, int ncuts, const XPRScut mcutind[]) = NULL;
int (*__symbolic_XPRSdelcpcuts) (XPRSprob prob, int itype, int interp, int ncuts, const XPRScut mcutind[]) = NULL;
int (*__symbolic_XPRSgetcutlist) (XPRSprob prob, int itype, int interp, int *ncuts, int maxcuts, XPRScut mcutind[]) = NULL;
int (*__symbolic_XPRSgetcpcutlist) (XPRSprob prob, int itype, int interp, double delta, int *ncuts, int maxcuts, XPRScut mcutind[], double dviol[]) = NULL;
int (*__symbolic_XPRSgetcpcuts) (XPRSprob prob, const XPRScut mindex[], int ncuts, int size, int mtype[], char qrtype[], int mstart[], int mcols[], double dmatval[], double drhs[]) = NULL;
int (*__symbolic_XPRSgetcpcuts64) (XPRSprob prob, const XPRScut mindex[], int ncuts, long size, int mtype[], char qrtype[], long mstart[], int mcols[], double dmatval[], double drhs[]) = NULL;
int (*__symbolic_XPRSloadcuts) (XPRSprob prob, int itype, int interp, int ncuts, const XPRScut mcutind[]) = NULL;
int (*__symbolic_XPRSstorecuts) (XPRSprob prob, int ncuts, int nodupl, const int mtype[], const char qrtype[], const double drhs[], const int mstart[], XPRScut mindex[], const int mcols[], const double dmatval[]) = NULL;
int (*__symbolic_XPRSstorecuts64) (XPRSprob prob, int ncuts, int nodupl, const int mtype[], const char qrtype[], const double drhs[], const long mstart[], XPRScut mindex[], const int mcols[], const double dmatval[]) = NULL;
int (*__symbolic_XPRSpresolverow) (XPRSprob prob, char qrtype, int nzo, const int mcolso[], const double dvalo[], double drhso, int maxcoeffs, int *nzp, int mcolsp[], double dvalp[], double *drhsp, int *status) = NULL;
int (*__symbolic_XPRSloadmipsol) (XPRSprob prob, const double dsol[], int *status) = NULL;
int (*__symbolic_XPRSaddmipsol) (XPRSprob prob, int ilength, const double mipsolval[], const int mipsolcol[], int *p_id) = NULL;
int (*__symbolic_XPRSstorebounds) (XPRSprob prob, int nbnds, const int mcols[], const char qbtype[], const double dbnd[], void **mindex) = NULL;
int (*__symbolic_XPRSsetbranchcuts) (XPRSprob prob, int nbcuts, const XPRScut mindex[]) = NULL;
int (*__symbolic_XPRSsetbranchbounds) (XPRSprob prob, void *mindex) = NULL;
int (*__symbolic_XPRSgetlasterror) (XPRSprob prob, char *errmsg) = NULL;
int (*__symbolic_XPRSbasiscondition) (XPRSprob prob, double *condnum, double *scondnum) = NULL;
int (*__symbolic_XPRSgetmipsol) (XPRSprob prob, double _dx[], double _dslack[]) = NULL;
int (*__symbolic_XPRSgetlpsol) (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]) = NULL;
int (*__symbolic_XPRSpostsolve) (XPRSprob prob) = NULL;
int (*__symbolic_XPRSdelsets) (XPRSprob prob, int nsets, const int msindex[]) = NULL;
int (*__symbolic_XPRSaddsets) (XPRSprob prob, int newsets, int newnz, const char qstype[], const int msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRSaddsets64) (XPRSprob prob, int newsets, long newnz, const char qstype[], const long msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRSstrongbranch) (XPRSprob prob, const int nbnds, const int _mindex[], const char _sboundtype[], const double _dbnd[], const int itrlimit, double _dsbobjval[], int _msbstatus[]) = NULL;
int (*__symbolic_XPRSgetprimalray) (XPRSprob prob, double _dpray[], int *_hasray) = NULL;
int (*__symbolic_XPRSgetdualray) (XPRSprob prob, double _ddray[], int *_hasray) = NULL;
int (*__symbolic_XPRSsetmessagestatus) (XPRSprob prob, int errcode, int bEnabledStatus) = NULL;
int (*__symbolic_XPRSgetmessagestatus) (XPRSprob prob, int errcode, int *bEnabledStatus) = NULL;
int (*__symbolic_XPRSrepairweightedinfeas) (XPRSprob prob, int *scode, const double lrp_array[], const double grp_array[], const double lbp_array[], const double ubp_array[], char second_phase, double delta, const char *optflags) = NULL;
int (*__symbolic_XPRSrepairinfeas) (XPRSprob prob, int *scode, char ptype, char phase2, char globalflags, double lrp, double grp, double lbp, double ubp, double delta) = NULL;
int (*__symbolic_XPRSgetcutslack) (XPRSprob prob, XPRScut cut, double *dslack) = NULL;
int (*__symbolic_XPRSgetcutmap) (XPRSprob prob, int ncuts, const XPRScut cuts[], int cutmap[]) = NULL;
int (*__symbolic_XPRSbasisstability) (XPRSprob prob, int typecode, int norm, int ifscaled, double *dval) = NULL;
int (*__symbolic_XPRSgetnamelist) (XPRSprob prob, int _itype, char _sbuff[], int names_len, int *names_len_reqd, int first, int last) = NULL;
int (*__symbolic_XPRSgetnamelistobject) (XPRSprob prob, int _itype, XPRSnamelist * r_nl) = NULL;
int (*__symbolic_XPRSlogfilehandler) (XPRSobject obj, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode) = NULL;
int (*__symbolic_XPRSgetobjecttypename) (XPRSobject obj, const char **sObjectName) = NULL;
int (*__symbolic_XPRSsetcblplog) (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcblplog) (XPRSprob prob, int ( ** f_lplog) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcblplog) (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecblplog) (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbgloballog) (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbgloballog) (XPRSprob prob, int ( ** f_globallog) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbgloballog) (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbgloballog) (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbcutlog) (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbcutlog) (XPRSprob prob, int ( ** f_cutlog) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbcutlog) (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbcutlog) (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbbarlog) (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbbarlog) (XPRSprob prob, int ( ** f_barlog) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbbarlog) (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbbarlog) (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbcutmgr) (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbcutmgr) (XPRSprob prob, int ( ** f_cutmgr) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbcutmgr) (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbcutmgr) (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbchgnode) (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p) = NULL;
int (*__symbolic_XPRSgetcbchgnode) (XPRSprob prob, void ( ** f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void **p) = NULL;
int (*__symbolic_XPRSaddcbchgnode) (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbchgnode) (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p) = NULL;
int (*__symbolic_XPRSsetcboptnode) (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p) = NULL;
int (*__symbolic_XPRSgetcboptnode) (XPRSprob prob, void ( ** f_optnode) (XPRSprob prob, void *vContext, int *feas), void **p) = NULL;
int (*__symbolic_XPRSaddcboptnode) (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecboptnode) (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p) = NULL;
int (*__symbolic_XPRSsetcbprenode) (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p) = NULL;
int (*__symbolic_XPRSgetcbprenode) (XPRSprob prob, void ( ** f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void **p) = NULL;
int (*__symbolic_XPRSaddcbprenode) (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbprenode) (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p) = NULL;
int (*__symbolic_XPRSsetcbinfnode) (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbinfnode) (XPRSprob prob, void ( ** f_infnode) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbinfnode) (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbinfnode) (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbnodecutoff) (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p) = NULL;
int (*__symbolic_XPRSgetcbnodecutoff) (XPRSprob prob, void ( ** f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void **p) = NULL;
int (*__symbolic_XPRSaddcbnodecutoff) (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbnodecutoff) (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p) = NULL;
int (*__symbolic_XPRSsetcbintsol) (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbintsol) (XPRSprob prob, void ( ** f_intsol) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbintsol) (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbintsol) (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbpreintsol) (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p) = NULL;
int (*__symbolic_XPRSgetcbpreintsol) (XPRSprob prob, void ( ** f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void **p) = NULL;
int (*__symbolic_XPRSaddcbpreintsol) (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbpreintsol) (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p) = NULL;
int (*__symbolic_XPRSsetcbchgbranch) (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p) = NULL;
int (*__symbolic_XPRSgetcbchgbranch) (XPRSprob prob, void ( ** f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void **p) = NULL;
int (*__symbolic_XPRSaddcbchgbranch) (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbchgbranch) (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p) = NULL;
int (*__symbolic_XPRSsetcbestimate) (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p) = NULL;
int (*__symbolic_XPRSgetcbestimate) (XPRSprob prob, int ( ** f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void **p) = NULL;
int (*__symbolic_XPRSaddcbestimate) (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbestimate) (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p) = NULL;
int (*__symbolic_XPRSsetcbsepnode) (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p) = NULL;
int (*__symbolic_XPRSgetcbsepnode) (XPRSprob prob, int ( ** f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void **p) = NULL;
int (*__symbolic_XPRSaddcbsepnode) (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbsepnode) (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p) = NULL;
int (*__symbolic_XPRSsetcbmessage) (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p) = NULL;
int (*__symbolic_XPRSgetcbmessage) (XPRSprob prob, void ( ** f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void **p) = NULL;
int (*__symbolic_XPRSaddcbmessage) (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbmessage) (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p) = NULL;
int (*__symbolic_XPRSsetcbmipthread) (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p) = NULL;
int (*__symbolic_XPRSgetcbmipthread) (XPRSprob prob, void ( ** f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void **p) = NULL;
int (*__symbolic_XPRSaddcbmipthread) (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbmipthread) (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p) = NULL;
int (*__symbolic_XPRSsetcbdestroymt) (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSgetcbdestroymt) (XPRSprob prob, void ( ** f_destroymt) (XPRSprob prob, void *vContext), void **p) = NULL;
int (*__symbolic_XPRSaddcbdestroymt) (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbdestroymt) (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p) = NULL;
int (*__symbolic_XPRSsetcbnewnode) (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p) = NULL;
int (*__symbolic_XPRSgetcbnewnode) (XPRSprob prob, void ( ** f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void **p) = NULL;
int (*__symbolic_XPRSaddcbnewnode) (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbnewnode) (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p) = NULL;
int (*__symbolic_XPRSsetcbbariteration) (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p) = NULL;
int (*__symbolic_XPRSgetcbbariteration) (XPRSprob prob, void ( ** f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void **p) = NULL;
int (*__symbolic_XPRSaddcbbariteration) (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbbariteration) (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p) = NULL;
int (*__symbolic_XPRSsetcbchgbranchobject) (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p) = NULL;
int (*__symbolic_XPRSgetcbchgbranchobject) (XPRSprob prob, void ( ** f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void **p) = NULL;
int (*__symbolic_XPRSaddcbchgbranchobject) (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbchgbranchobject) (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p) = NULL;
int (*__symbolic_XPRSsetcbgapnotify) (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p) = NULL;
int (*__symbolic_XPRSgetcbgapnotify) (XPRSprob prob, void ( ** f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void **p) = NULL;
int (*__symbolic_XPRSaddcbgapnotify) (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbgapnotify) (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p) = NULL;
int (*__symbolic_XPRSsetcbusersolnotify) (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p) = NULL;
int (*__symbolic_XPRSgetcbusersolnotify) (XPRSprob prob, void ( ** f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void **p) = NULL;
int (*__symbolic_XPRSaddcbusersolnotify) (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p, int priority) = NULL;
int (*__symbolic_XPRSremovecbusersolnotify) (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p) = NULL;
int (*__symbolic_XPRSobjsa) (XPRSprob prob, int ncols, const int mindex[], double lower[], double upper[]) = NULL;
int (*__symbolic_XPRSrhssa) (XPRSprob prob, int nrows, const int mindex[], double lower[], double upper[]) = NULL;
int (*__symbolic_XPRS_ge_setcbmsghandler) (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_ge_getcbmsghandler) (int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p) = NULL;
int (*__symbolic_XPRS_ge_addcbmsghandler) (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority) = NULL;
int (*__symbolic_XPRS_ge_removecbmsghandler) (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_ge_getlasterror) (int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;
int (*__symbolic_XPRS_msp_create) (XPRSmipsolpool * msp) = NULL;
int (*__symbolic_XPRS_msp_destroy) (XPRSmipsolpool msp) = NULL;
int (*__symbolic_XPRS_msp_probattach) (XPRSmipsolpool msp, XPRSprob prob) = NULL;
int (*__symbolic_XPRS_msp_probdetach) (XPRSmipsolpool msp, XPRSprob prob) = NULL;
int (*__symbolic_XPRS_msp_getsollist) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iRankAttrib, int bRankAscending, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int iSolutionIds_Zb[], int *nReturnedSolIds, int *nSols) = NULL;
int (*__symbolic_XPRS_msp_getsollist2) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iRankAttrib, int bRankAscending, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int bUseUserBitFilter, int iUserBitMask, int iUserBitPattern, int bUseInternalBitFilter, int iInternalBitMask, int iInternalBitPattern, int iSolutionIds_Zb[], int *nReturnedSolIds, int *nSols) = NULL;
int (*__symbolic_XPRS_msp_getsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, double x[], int iColFirst, int iColLast, int *nValuesReturned) = NULL;
int (*__symbolic_XPRS_msp_getslack) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, double slack[], int iRowFirst, int iRowLast, int *nValuesReturned) = NULL;
int (*__symbolic_XPRS_msp_loadsol) (XPRSmipsolpool msp, int *iSolutionId, const double x[], int nCols, const char *sSolutionName, int *bNameModifiedForUniqueness, int *iSolutionIdOfExistingDuplicatePreventedLoad) = NULL;
int (*__symbolic_XPRS_msp_delsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_) = NULL;
int (*__symbolic_XPRS_msp_getintattribprobsol) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, int *Dst) = NULL;
int (*__symbolic_XPRS_msp_getdblattribprobsol) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, double *Dst) = NULL;
int (*__symbolic_XPRS_msp_getintattribprob) (XPRSmipsolpool msp, XPRSprob prob, int iAttribId, int *Dst) = NULL;
int (*__symbolic_XPRS_msp_getdblattribprob) (XPRSmipsolpool msp, XPRSprob prob, int iAttribId, double *Dst) = NULL;
int (*__symbolic_XPRS_msp_getintattribsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, int *Dst) = NULL;
int (*__symbolic_XPRS_msp_getdblattribsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, double *Dst) = NULL;
int (*__symbolic_XPRS_msp_getintcontrolsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, int *Val) = NULL;
int (*__symbolic_XPRS_msp_getdblcontrolsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, double *Val) = NULL;
int (*__symbolic_XPRS_msp_setintcontrolsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, int Val) = NULL;
int (*__symbolic_XPRS_msp_setdblcontrolsol) (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, double Val) = NULL;
int (*__symbolic_XPRS_msp_getintattribprobextreme) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int bGet_Max_Otherwise_Min, int *iSolutionId, int iAttribId, int *ExtremeVal) = NULL;
int (*__symbolic_XPRS_msp_getdblattribprobextreme) (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int bGet_Max_Otherwise_Min, int *iSolutionId, int iAttribId, double *ExtremeVal) = NULL;
int (*__symbolic_XPRS_msp_getintattrib) (XPRSmipsolpool msp, int iAttribId, int *Val) = NULL;
int (*__symbolic_XPRS_msp_getdblattrib) (XPRSmipsolpool msp, int iAttribId, double *Val) = NULL;
int (*__symbolic_XPRS_msp_getintcontrol) (XPRSmipsolpool msp, int iControlId, int *Val) = NULL;
int (*__symbolic_XPRS_msp_getdblcontrol) (XPRSmipsolpool msp, int iControlId, double *Val) = NULL;
int (*__symbolic_XPRS_msp_setintcontrol) (XPRSmipsolpool msp, int iControlId, int Val) = NULL;
int (*__symbolic_XPRS_msp_setdblcontrol) (XPRSmipsolpool msp, int iControlId, double Val) = NULL;
int (*__symbolic_XPRS_msp_setsolname) (XPRSmipsolpool msp, int iSolutionId, const char *sNewSolutionBaseName, int *bNameModifiedForUniqueness, int *iSolutionIdStatus_) = NULL;
int (*__symbolic_XPRS_msp_getsolname) (XPRSmipsolpool msp, int iSolutionId, char *_sname, int _iStringBufferBytes, int *_iBytesInInternalString, int *iSolutionIdStatus_) = NULL;
int (*__symbolic_XPRS_msp_findsolbyname) (XPRSmipsolpool msp, const char *sSolutionName, int *iSolutionId) = NULL;
int (*__symbolic_XPRS_msp_writeslxsol) (XPRSmipsolpool msp, XPRSprob prob_context, int iSolutionId, int *iSolutionIdStatus_, const char *sFileName, const char *sFlags) = NULL;
int (*__symbolic_XPRS_msp_readslxsol) (XPRSmipsolpool msp, XPRSnamelist col_name_list, const char *sFileName, const char *sFlags, int *iSolutionId_Beg, int *iSolutionId_End) = NULL;
int (*__symbolic_XPRS_msp_getlasterror) (XPRSmipsolpool msp, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;
int (*__symbolic_XPRS_msp_setcbmsghandler) (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_msp_getcbmsghandler) (XPRSmipsolpool msp, int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p) = NULL;
int (*__symbolic_XPRS_msp_addcbmsghandler) (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority) = NULL;
int (*__symbolic_XPRS_msp_removecbmsghandler) (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_nml_create) (XPRSnamelist * r_nl) = NULL;
int (*__symbolic_XPRS_nml_destroy) (XPRSnamelist nml) = NULL;
int (*__symbolic_XPRS_nml_getnamecount) (XPRSnamelist nml, int *count) = NULL;
int (*__symbolic_XPRS_nml_getmaxnamelen) (XPRSnamelist nml, int *namlen) = NULL;
int (*__symbolic_XPRS_nml_getnames) (XPRSnamelist nml, int padlen, char buf[], int buflen, int *r_buflen_reqd, int firstIndex, int lastIndex) = NULL;
int (*__symbolic_XPRS_nml_addnames) (XPRSnamelist nml, const char buf[], int firstIndex, int lastIndex) = NULL;
int (*__symbolic_XPRS_nml_removenames) (XPRSnamelist nml, int firstIndex, int lastIndex) = NULL;
int (*__symbolic_XPRS_nml_findname) (XPRSnamelist nml, const char *name, int *r_index) = NULL;
int (*__symbolic_XPRS_nml_copynames) (XPRSnamelist dst, XPRSnamelist src) = NULL;
int (*__symbolic_XPRS_nml_getlasterror) (XPRSnamelist nml, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;
int (*__symbolic_XPRSgetqrowcoeff) (XPRSprob prob, int irow, int icol, int jcol, double *dval) = NULL;
int (*__symbolic_XPRSgetqrowqmatrix) (XPRSprob prob, int irow, int mstart[], int mclind[], double dobjval[], int maxcoeffs, int *ncoeffs, int first, int last) = NULL;
int (*__symbolic_XPRSgetqrowqmatrixtriplets) (XPRSprob prob, int irow, int *nqelem, int mqcol1[], int mqcol2[], double dqe[]) = NULL;
int (*__symbolic_XPRSchgqrowcoeff) (XPRSprob prob, int irow, int icol, int jcol, double dval) = NULL;
int (*__symbolic_XPRSgetqrows) (XPRSprob prob, int *qmn, int qcrows[]) = NULL;
int (*__symbolic_XPRSaddqmatrix) (XPRSprob prob, int irow, int nqtr, const int mqc1[], const int mqc2[], const double dqew[]) = NULL;
int (*__symbolic_XPRSaddqmatrix64) (XPRSprob prob, int irow, long nqtr, const int mqc1[], const int mqc2[], const double dqew[]) = NULL;
int (*__symbolic_XPRSdelqmatrix) (XPRSprob prob, int irow) = NULL;
int (*__symbolic_XPRSloadqcqp) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const int qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[]) = NULL;
int (*__symbolic_XPRSloadqcqp64) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const long qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[]) = NULL;
int (*__symbolic_XPRSloadqcqpglobal) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _matbeg[], const int _matcnt[], const int _matrow[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const int qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const int msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRSloadqcqpglobal64) (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _matbeg[], const int _matcnt[], const int _matrow[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const long qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const long msstart[], const int mscols[], const double dref[]) = NULL;
int (*__symbolic_XPRS_mse_create) (XPRSmipsolenum * mse) = NULL;
int (*__symbolic_XPRS_mse_destroy) (XPRSmipsolenum mse) = NULL;
int (*__symbolic_XPRS_mse_getsollist) (XPRSmipsolenum mse, int iMetricId, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int iSolutionIds[], int *nReturnedSolIds, int *nSols) = NULL;
int (*__symbolic_XPRS_mse_getsolmetric) (XPRSmipsolenum mse, int iSolutionId, int *iSolutionIdStatus, int iMetricId, double *dMetric) = NULL;
int (*__symbolic_XPRS_mse_getcullchoice) (XPRSmipsolenum mse, int iMetricId, int cull_sol_id_list[], int nMaxSolsToCull, int *nSolsToCull, double dNewSolMetric, const double x[], int nCols, int *bRejectSoln) = NULL;
int (*__symbolic_XPRS_mse_minim) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols) = NULL;
int (*__symbolic_XPRS_mse_maxim) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols) = NULL;
int (*__symbolic_XPRS_mse_opt) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols) = NULL;
int (*__symbolic_XPRS_mse_getintattrib) (XPRSmipsolenum mse, int iAttribId, int *Val) = NULL;
int (*__symbolic_XPRS_mse_getdblattrib) (XPRSmipsolenum mse, int iAttribId, double *Val) = NULL;
int (*__symbolic_XPRS_mse_getintcontrol) (XPRSmipsolenum mse, int iAttribId, int *Val) = NULL;
int (*__symbolic_XPRS_mse_getdblcontrol) (XPRSmipsolenum mse, int iAttribId, double *Val) = NULL;
int (*__symbolic_XPRS_mse_setintcontrol) (XPRSmipsolenum mse, int iAttribId, int Val) = NULL;
int (*__symbolic_XPRS_mse_setdblcontrol) (XPRSmipsolenum mse, int iAttribId, double Val) = NULL;
int (*__symbolic_XPRS_mse_getlasterror) (XPRSmipsolenum mse, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;
int (*__symbolic_XPRS_mse_setsolbasename) (XPRSmipsolenum mse, const char *sSolutionBaseName) = NULL;
int (*__symbolic_XPRS_mse_getsolbasename) (XPRSmipsolenum mse, char *_sname, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;
int (*__symbolic_XPRS_mse_setcbgetsolutiondiff) (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p) = NULL;
int (*__symbolic_XPRS_mse_getcbgetsolutiondiff) (XPRSmipsolenum mse, int ( ** f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void **p) = NULL;
int (*__symbolic_XPRS_mse_addcbgetsolutiondiff) (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p, int priority) = NULL;
int (*__symbolic_XPRS_mse_removecbgetsolutiondiff) (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p) = NULL;
int (*__symbolic_XPRS_mse_setcbmsghandler) (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_mse_getcbmsghandler) (XPRSmipsolenum mse, int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p) = NULL;
int (*__symbolic_XPRS_mse_addcbmsghandler) (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority) = NULL;
int (*__symbolic_XPRS_mse_removecbmsghandler) (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p) = NULL;
int (*__symbolic_XPRS_bo_create) (XPRSbranchobject * p_object, XPRSprob prob, int isoriginal) = NULL;
int (*__symbolic_XPRS_bo_destroy) (XPRSbranchobject obranch) = NULL;
int (*__symbolic_XPRS_bo_store) (XPRSbranchobject obranch, int *p_status) = NULL;
int (*__symbolic_XPRS_bo_addbranches) (XPRSbranchobject obranch, int nbranches) = NULL;
int (*__symbolic_XPRS_bo_getbranches) (XPRSbranchobject obranch, int *p_nbranches) = NULL;
int (*__symbolic_XPRS_bo_setpriority) (XPRSbranchobject obranch, int ipriority) = NULL;
int (*__symbolic_XPRS_bo_setpreferredbranch) (XPRSbranchobject obranch, int ibranch) = NULL;
int (*__symbolic_XPRS_bo_addbounds) (XPRSbranchobject obranch, int ibranch, int nbounds, const char cbndtype[], const int mbndcol[], const double dbndval[]) = NULL;
int (*__symbolic_XPRS_bo_getbounds) (XPRSbranchobject obranch, int ibranch, int *p_nbounds, int nbounds_size, char cbndtype[], int mbndcol[], double dbndval[]) = NULL;
int (*__symbolic_XPRS_bo_addrows) (XPRSbranchobject obranch, int ibranch, int nrows, int nelems, const char crtype[], const double drrhs[], const int mrbeg[], const int mcol[], const double dval[]) = NULL;
int (*__symbolic_XPRS_bo_getrows) (XPRSbranchobject obranch, int ibranch, int *p_nrows, int nrows_size, int *p_nelems, int nelems_size, char crtype[], double drrhs[], int mrbeg[], int mcol[], double dval[]) = NULL;
int (*__symbolic_XPRS_bo_addcuts) (XPRSbranchobject obranch, int ibranch, int ncuts, const XPRScut mcutind[]) = NULL;
int (*__symbolic_XPRS_bo_getid) (XPRSbranchobject obranch, int *p_id) = NULL;
int (*__symbolic_XPRS_bo_getlasterror) (XPRSbranchobject obranch, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString) = NULL;

/* hijacked functions */

int XPRScopycallbacks (XPRSprob dest, XPRSprob src){
    if (!__symbolic_XPRScopycallbacks) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRScopycallbacks", (gpointer *) &__symbolic_XPRScopycallbacks)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRScopycallbacks could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRScopycallbacks.\n");
        }
    }
    return __symbolic_XPRScopycallbacks(dest, src);
}
int XPRScopycontrols (XPRSprob dest, XPRSprob src){
    if (!__symbolic_XPRScopycontrols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRScopycontrols", (gpointer *) &__symbolic_XPRScopycontrols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRScopycontrols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRScopycontrols.\n");
        }
    }
    return __symbolic_XPRScopycontrols(dest, src);
}
int XPRScopyprob (XPRSprob dest, XPRSprob src, const char *probname){
    if (!__symbolic_XPRScopyprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRScopyprob", (gpointer *) &__symbolic_XPRScopyprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRScopyprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRScopyprob.\n");
        }
    }
    return __symbolic_XPRScopyprob(dest, src, probname);
}
int XPRScreateprob (XPRSprob * _probholder){
    if (!__symbolic_XPRScreateprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRScreateprob", (gpointer *) &__symbolic_XPRScreateprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRScreateprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRScreateprob.\n");
        }
    }
    return __symbolic_XPRScreateprob(_probholder);
}
int XPRSdestroyprob (XPRSprob _prob){
    if (!__symbolic_XPRSdestroyprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdestroyprob", (gpointer *) &__symbolic_XPRSdestroyprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdestroyprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdestroyprob.\n");
        }
    }
    return __symbolic_XPRSdestroyprob(_prob);
}
int XPRSinit (const char *path){
    if (!__symbolic_XPRSinit) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSinit", (gpointer *) &__symbolic_XPRSinit)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSinit could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSinit.\n");
        }
    }
    return __symbolic_XPRSinit(path);
}
int XPRSfree (void){
    if (!__symbolic_XPRSfree) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSfree", (gpointer *) &__symbolic_XPRSfree)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSfree could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSfree.\n");
        }
    }
    return __symbolic_XPRSfree();
}
int XPRSgetbanner (char *banner){
    if (!__symbolic_XPRSgetbanner) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetbanner", (gpointer *) &__symbolic_XPRSgetbanner)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetbanner could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetbanner.\n");
        }
    }
    return __symbolic_XPRSgetbanner(banner);
}
int XPRSgetversion (char *version){
    if (!__symbolic_XPRSgetversion) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetversion", (gpointer *) &__symbolic_XPRSgetversion)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetversion could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetversion.\n");
        }
    }
    return __symbolic_XPRSgetversion(version);
}
int XPRSgetdaysleft (int *daysleft){
    if (!__symbolic_XPRSgetdaysleft) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetdaysleft", (gpointer *) &__symbolic_XPRSgetdaysleft)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetdaysleft could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetdaysleft.\n");
        }
    }
    return __symbolic_XPRSgetdaysleft(daysleft);
}
int XPRSsetcheckedmode (int checked_mode){
    if (!__symbolic_XPRSsetcheckedmode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcheckedmode", (gpointer *) &__symbolic_XPRSsetcheckedmode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcheckedmode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcheckedmode.\n");
        }
    }
    return __symbolic_XPRSsetcheckedmode(checked_mode);
}
int XPRSgetcheckedmode (int *r_checked_mode){
    if (!__symbolic_XPRSgetcheckedmode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcheckedmode", (gpointer *) &__symbolic_XPRSgetcheckedmode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcheckedmode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcheckedmode.\n");
        }
    }
    return __symbolic_XPRSgetcheckedmode(r_checked_mode);
}
int XPRSlicense (int *_i1, char *_c1){
    if (!__symbolic_XPRSlicense) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSlicense", (gpointer *) &__symbolic_XPRSlicense)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSlicense could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSlicense.\n");
        }
    }
    return __symbolic_XPRSlicense(_i1, _c1);
}
int XPRSbeginlicensing (int *r_dontAlreadyHaveLicense){
    if (!__symbolic_XPRSbeginlicensing) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSbeginlicensing", (gpointer *) &__symbolic_XPRSbeginlicensing)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSbeginlicensing could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSbeginlicensing.\n");
        }
    }
    return __symbolic_XPRSbeginlicensing(r_dontAlreadyHaveLicense);
}
int XPRSendlicensing (void){
    if (!__symbolic_XPRSendlicensing) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSendlicensing", (gpointer *) &__symbolic_XPRSendlicensing)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSendlicensing could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSendlicensing.\n");
        }
    }
    return __symbolic_XPRSendlicensing();
}
int XPRSgetlicerrmsg (char *msg, int len){
    if (!__symbolic_XPRSgetlicerrmsg) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetlicerrmsg", (gpointer *) &__symbolic_XPRSgetlicerrmsg)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetlicerrmsg could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetlicerrmsg.\n");
        }
    }
    return __symbolic_XPRSgetlicerrmsg(msg, len);
}
int XPRSsetlogfile (XPRSprob prob, const char *logname){
    if (!__symbolic_XPRSsetlogfile) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetlogfile", (gpointer *) &__symbolic_XPRSsetlogfile)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetlogfile could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetlogfile.\n");
        }
    }
    return __symbolic_XPRSsetlogfile(prob, logname);
}
int XPRSsetintcontrol (XPRSprob prob, int _index, int _ivalue){
    if (!__symbolic_XPRSsetintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetintcontrol", (gpointer *) &__symbolic_XPRSsetintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetintcontrol.\n");
        }
    }
    return __symbolic_XPRSsetintcontrol(prob, _index, _ivalue);
}
int XPRSsetintcontrol64 (XPRSprob prob, int _index, long _ivalue){
    if (!__symbolic_XPRSsetintcontrol64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetintcontrol64", (gpointer *) &__symbolic_XPRSsetintcontrol64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetintcontrol64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetintcontrol64.\n");
        }
    }
    return __symbolic_XPRSsetintcontrol64(prob, _index, _ivalue);
}
int XPRSsetdblcontrol (XPRSprob prob, int _index, double _dvalue){
    if (!__symbolic_XPRSsetdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetdblcontrol", (gpointer *) &__symbolic_XPRSsetdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetdblcontrol.\n");
        }
    }
    return __symbolic_XPRSsetdblcontrol(prob, _index, _dvalue);
}
int XPRSinterrupt (XPRSprob prob, int reason){
    if (!__symbolic_XPRSinterrupt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSinterrupt", (gpointer *) &__symbolic_XPRSinterrupt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSinterrupt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSinterrupt.\n");
        }
    }
    return __symbolic_XPRSinterrupt(prob, reason);
}
int XPRSgetprobname (XPRSprob prob, char *_svalue){
    if (!__symbolic_XPRSgetprobname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetprobname", (gpointer *) &__symbolic_XPRSgetprobname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetprobname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetprobname.\n");
        }
    }
    return __symbolic_XPRSgetprobname(prob, _svalue);
}
int XPRSgetqobj (XPRSprob prob, int _icol, int _jcol, double *_dval){
    if (!__symbolic_XPRSgetqobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetqobj", (gpointer *) &__symbolic_XPRSgetqobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetqobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetqobj.\n");
        }
    }
    return __symbolic_XPRSgetqobj(prob, _icol, _jcol, _dval);
}
int XPRSsetprobname (XPRSprob prob, const char *_svalue){
    if (!__symbolic_XPRSsetprobname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetprobname", (gpointer *) &__symbolic_XPRSsetprobname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetprobname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetprobname.\n");
        }
    }
    return __symbolic_XPRSsetprobname(prob, _svalue);
}
int XPRSsetstrcontrol (XPRSprob prob, int _index, const char *_svalue){
    if (!__symbolic_XPRSsetstrcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetstrcontrol", (gpointer *) &__symbolic_XPRSsetstrcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetstrcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetstrcontrol.\n");
        }
    }
    return __symbolic_XPRSsetstrcontrol(prob, _index, _svalue);
}
int XPRSgetintcontrol (XPRSprob prob, int _index, int *_ivalue){
    if (!__symbolic_XPRSgetintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetintcontrol", (gpointer *) &__symbolic_XPRSgetintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetintcontrol.\n");
        }
    }
    return __symbolic_XPRSgetintcontrol(prob, _index, _ivalue);
}
int XPRSgetintcontrol64 (XPRSprob prob, int _index, long * _ivalue){
    if (!__symbolic_XPRSgetintcontrol64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetintcontrol64", (gpointer *) &__symbolic_XPRSgetintcontrol64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetintcontrol64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetintcontrol64.\n");
        }
    }
    return __symbolic_XPRSgetintcontrol64(prob, _index, _ivalue);
}
int XPRSgetdblcontrol (XPRSprob prob, int _index, double *_dvalue){
    if (!__symbolic_XPRSgetdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetdblcontrol", (gpointer *) &__symbolic_XPRSgetdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetdblcontrol.\n");
        }
    }
    return __symbolic_XPRSgetdblcontrol(prob, _index, _dvalue);
}
int XPRSgetstrcontrol (XPRSprob prob, int _index, char *_svalue){
    if (!__symbolic_XPRSgetstrcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetstrcontrol", (gpointer *) &__symbolic_XPRSgetstrcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetstrcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetstrcontrol.\n");
        }
    }
    return __symbolic_XPRSgetstrcontrol(prob, _index, _svalue);
}
int XPRSgetintattrib (XPRSprob prob, int _index, int *_ivalue){
    if (!__symbolic_XPRSgetintattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetintattrib", (gpointer *) &__symbolic_XPRSgetintattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetintattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetintattrib.\n");
        }
    }
    return __symbolic_XPRSgetintattrib(prob, _index, _ivalue);
}
int XPRSgetintattrib64 (XPRSprob prob, int _index, long * _ivalue){
    if (!__symbolic_XPRSgetintattrib64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetintattrib64", (gpointer *) &__symbolic_XPRSgetintattrib64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetintattrib64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetintattrib64.\n");
        }
    }
    return __symbolic_XPRSgetintattrib64(prob, _index, _ivalue);
}
int XPRSgetstrattrib (XPRSprob prob, int _index, char *_cvalue){
    if (!__symbolic_XPRSgetstrattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetstrattrib", (gpointer *) &__symbolic_XPRSgetstrattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetstrattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetstrattrib.\n");
        }
    }
    return __symbolic_XPRSgetstrattrib(prob, _index, _cvalue);
}
int XPRSgetdblattrib (XPRSprob prob, int _index, double *_dvalue){
    if (!__symbolic_XPRSgetdblattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetdblattrib", (gpointer *) &__symbolic_XPRSgetdblattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetdblattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetdblattrib.\n");
        }
    }
    return __symbolic_XPRSgetdblattrib(prob, _index, _dvalue);
}
int XPRSsetdefaultcontrol (XPRSprob prob, int _index){
    if (!__symbolic_XPRSsetdefaultcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetdefaultcontrol", (gpointer *) &__symbolic_XPRSsetdefaultcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetdefaultcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetdefaultcontrol.\n");
        }
    }
    return __symbolic_XPRSsetdefaultcontrol(prob, _index);
}
int XPRSsetdefaults (XPRSprob prob){
    if (!__symbolic_XPRSsetdefaults) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetdefaults", (gpointer *) &__symbolic_XPRSsetdefaults)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetdefaults could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetdefaults.\n");
        }
    }
    return __symbolic_XPRSsetdefaults(prob);
}
int XPRSgetcontrolinfo (XPRSprob prob, const char *sCaName, int *iHeaderId, int *iTypeinfo){
    if (!__symbolic_XPRSgetcontrolinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcontrolinfo", (gpointer *) &__symbolic_XPRSgetcontrolinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcontrolinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcontrolinfo.\n");
        }
    }
    return __symbolic_XPRSgetcontrolinfo(prob, sCaName, iHeaderId, iTypeinfo);
}
int XPRSgetattribinfo (XPRSprob prob, const char *sCaName, int *iHeaderId, int *iTypeinfo){
    if (!__symbolic_XPRSgetattribinfo) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetattribinfo", (gpointer *) &__symbolic_XPRSgetattribinfo)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetattribinfo could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetattribinfo.\n");
        }
    }
    return __symbolic_XPRSgetattribinfo(prob, sCaName, iHeaderId, iTypeinfo);
}
int XPRSgoal (XPRSprob prob, const char *_filename, const char *_sflags){
    if (!__symbolic_XPRSgoal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgoal", (gpointer *) &__symbolic_XPRSgoal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgoal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgoal.\n");
        }
    }
    return __symbolic_XPRSgoal(prob, _filename, _sflags);
}
int XPRSreadprob (XPRSprob prob, const char *_sprobname, const char *_sflags){
    if (!__symbolic_XPRSreadprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSreadprob", (gpointer *) &__symbolic_XPRSreadprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSreadprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSreadprob.\n");
        }
    }
    return __symbolic_XPRSreadprob(prob, _sprobname, _sflags);
}
int XPRSloadlp (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[]){
    if (!__symbolic_XPRSloadlp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadlp", (gpointer *) &__symbolic_XPRSloadlp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadlp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadlp.\n");
        }
    }
    return __symbolic_XPRSloadlp(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub);
}
int XPRSloadlp64 (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[]){
    if (!__symbolic_XPRSloadlp64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadlp64", (gpointer *) &__symbolic_XPRSloadlp64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadlp64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadlp64.\n");
        }
    }
    return __symbolic_XPRSloadlp64(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub);
}
int XPRSloadqp (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[]){
    if (!__symbolic_XPRSloadqp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqp", (gpointer *) &__symbolic_XPRSloadqp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqp.\n");
        }
    }
    return __symbolic_XPRSloadqp(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval);
}
int XPRSloadqp64 (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[]){
    if (!__symbolic_XPRSloadqp64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqp64", (gpointer *) &__symbolic_XPRSloadqp64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqp64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqp64.\n");
        }
    }
    return __symbolic_XPRSloadqp64(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval);
}
int XPRSloadqglobal (XPRSprob prob, const char *probname, int ncols, int nrows, const char qsenx[], const double rhsx[], const double range[], const double objx[], const int matbeg[], const int matcnt[], const int matind[], const double dmtval[], const double bndl[], const double bndu[], int nquads, const int mqcol1[], const int mqcol2[], const double dqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const int msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSloadqglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqglobal", (gpointer *) &__symbolic_XPRSloadqglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqglobal.\n");
        }
    }
    return __symbolic_XPRSloadqglobal(prob, probname, ncols, nrows, qsenx, rhsx, range, objx, matbeg, matcnt, matind, dmtval, bndl, bndu, nquads, mqcol1, mqcol2, dqval, ngents, nsets, qgtype, mgcols, dlim, qstype, msstart, mscols, dref);
}
int XPRSloadqglobal64 (XPRSprob prob, const char *probname, int ncols, int nrows, const char qsenx[], const double rhsx[], const double range[], const double objx[], const long matbeg[], const int matcnt[], const int matind[], const double dmtval[], const double bndl[], const double bndu[], long nquads, const int mqcol1[], const int mqcol2[], const double dqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const long msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSloadqglobal64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqglobal64", (gpointer *) &__symbolic_XPRSloadqglobal64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqglobal64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqglobal64.\n");
        }
    }
    return __symbolic_XPRSloadqglobal64(prob, probname, ncols, nrows, qsenx, rhsx, range, objx, matbeg, matcnt, matind, dmtval, bndl, bndu, nquads, mqcol1, mqcol2, dqval, ngents, nsets, qgtype, mgcols, dlim, qstype, msstart, mscols, dref);
}
int XPRSfixglobal (XPRSprob prob){
    if (!__symbolic_XPRSfixglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSfixglobal", (gpointer *) &__symbolic_XPRSfixglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSfixglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSfixglobal.\n");
        }
    }
    return __symbolic_XPRSfixglobal(prob);
}
int XPRSfixglobals (XPRSprob prob, int ifround){
    if (!__symbolic_XPRSfixglobals) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSfixglobals", (gpointer *) &__symbolic_XPRSfixglobals)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSfixglobals could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSfixglobals.\n");
        }
    }
    return __symbolic_XPRSfixglobals(prob, ifround);
}
int XPRSloadmodelcuts (XPRSprob prob, int nmodcuts, const int _mrows[]){
    if (!__symbolic_XPRSloadmodelcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadmodelcuts", (gpointer *) &__symbolic_XPRSloadmodelcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadmodelcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadmodelcuts.\n");
        }
    }
    return __symbolic_XPRSloadmodelcuts(prob, nmodcuts, _mrows);
}
int XPRSloaddelayedrows (XPRSprob prob, int nrows, const int _mrows[]){
    if (!__symbolic_XPRSloaddelayedrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloaddelayedrows", (gpointer *) &__symbolic_XPRSloaddelayedrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloaddelayedrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloaddelayedrows.\n");
        }
    }
    return __symbolic_XPRSloaddelayedrows(prob, nrows, _mrows);
}
int XPRSloaddirs (XPRSprob prob, int ndirs, const int _mcols[], const int _mpri[], const char _sbr[], const double dupc[], const double ddpc[]){
    if (!__symbolic_XPRSloaddirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloaddirs", (gpointer *) &__symbolic_XPRSloaddirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloaddirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloaddirs.\n");
        }
    }
    return __symbolic_XPRSloaddirs(prob, ndirs, _mcols, _mpri, _sbr, dupc, ddpc);
}
int XPRSloadbranchdirs (XPRSprob prob, int ndirs, const int _mcols[], const int _mbranch[]){
    if (!__symbolic_XPRSloadbranchdirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadbranchdirs", (gpointer *) &__symbolic_XPRSloadbranchdirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadbranchdirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadbranchdirs.\n");
        }
    }
    return __symbolic_XPRSloadbranchdirs(prob, ndirs, _mcols, _mbranch);
}
int XPRSloadpresolvedirs (XPRSprob prob, int ndirs, const int _mcols[], const int _mpri[], const char _sbr[], const double dupc[], const double ddpc[]){
    if (!__symbolic_XPRSloadpresolvedirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadpresolvedirs", (gpointer *) &__symbolic_XPRSloadpresolvedirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadpresolvedirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadpresolvedirs.\n");
        }
    }
    return __symbolic_XPRSloadpresolvedirs(prob, ndirs, _mcols, _mpri, _sbr, dupc, ddpc);
}
int XPRSgetdirs (XPRSprob prob, int *ndirs, int _mcols[], int _mpri[], char _sbr[], double dupc[], double ddpc[]){
    if (!__symbolic_XPRSgetdirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetdirs", (gpointer *) &__symbolic_XPRSgetdirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetdirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetdirs.\n");
        }
    }
    return __symbolic_XPRSgetdirs(prob, ndirs, _mcols, _mpri, _sbr, dupc, ddpc);
}
int XPRSloadglobal (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int ngents, int nsets, const char _qgtype[], const int _mgcols[], const double _dlim[], const char _stype[], const int _msstart[], const int _mscols[], const double _dref[]){
    if (!__symbolic_XPRSloadglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadglobal", (gpointer *) &__symbolic_XPRSloadglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadglobal.\n");
        }
    }
    return __symbolic_XPRSloadglobal(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, ngents, nsets, _qgtype, _mgcols, _dlim, _stype, _msstart, _mscols, _dref);
}
int XPRSloadglobal64 (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int ngents, int nsets, const char _qgtype[], const int _mgcols[], const double _dlim[], const char _stype[], const long _msstart[], const int _mscols[], const double _dref[]){
    if (!__symbolic_XPRSloadglobal64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadglobal64", (gpointer *) &__symbolic_XPRSloadglobal64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadglobal64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadglobal64.\n");
        }
    }
    return __symbolic_XPRSloadglobal64(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, ngents, nsets, _qgtype, _mgcols, _dlim, _stype, _msstart, _mscols, _dref);
}
int XPRSaddnames (XPRSprob prob, int _itype, const char _sname[], int first, int last){
    if (!__symbolic_XPRSaddnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddnames", (gpointer *) &__symbolic_XPRSaddnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddnames.\n");
        }
    }
    return __symbolic_XPRSaddnames(prob, _itype, _sname, first, last);
}
int XPRSaddsetnames (XPRSprob prob, const char _sname[], int first, int last){
    if (!__symbolic_XPRSaddsetnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddsetnames", (gpointer *) &__symbolic_XPRSaddsetnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddsetnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddsetnames.\n");
        }
    }
    return __symbolic_XPRSaddsetnames(prob, _sname, first, last);
}
int XPRSscale (XPRSprob prob, const int mrscal[], const int mcscal[]){
    if (!__symbolic_XPRSscale) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSscale", (gpointer *) &__symbolic_XPRSscale)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSscale could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSscale.\n");
        }
    }
    return __symbolic_XPRSscale(prob, mrscal, mcscal);
}
int XPRSreaddirs (XPRSprob prob, const char *_sfilename){
    if (!__symbolic_XPRSreaddirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSreaddirs", (gpointer *) &__symbolic_XPRSreaddirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSreaddirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSreaddirs.\n");
        }
    }
    return __symbolic_XPRSreaddirs(prob, _sfilename);
}
int XPRSwritedirs (XPRSprob prob, const char *_sfilename){
    if (!__symbolic_XPRSwritedirs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwritedirs", (gpointer *) &__symbolic_XPRSwritedirs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwritedirs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwritedirs.\n");
        }
    }
    return __symbolic_XPRSwritedirs(prob, _sfilename);
}
int XPRSsetindicators (XPRSprob prob, int nrows, const int _mrows[], const int _inds[], const int _comps[]){
    if (!__symbolic_XPRSsetindicators) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetindicators", (gpointer *) &__symbolic_XPRSsetindicators)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetindicators could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetindicators.\n");
        }
    }
    return __symbolic_XPRSsetindicators(prob, nrows, _mrows, _inds, _comps);
}
int XPRSgetindicators (XPRSprob prob, int _inds[], int _comps[], int first, int last){
    if (!__symbolic_XPRSgetindicators) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetindicators", (gpointer *) &__symbolic_XPRSgetindicators)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetindicators could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetindicators.\n");
        }
    }
    return __symbolic_XPRSgetindicators(prob, _inds, _comps, first, last);
}
int XPRSdelindicators (XPRSprob prob, int first, int last){
    if (!__symbolic_XPRSdelindicators) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelindicators", (gpointer *) &__symbolic_XPRSdelindicators)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelindicators could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelindicators.\n");
        }
    }
    return __symbolic_XPRSdelindicators(prob, first, last);
}
int XPRSminim (XPRSprob prob, const char *_sflags){
    if (!__symbolic_XPRSminim) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSminim", (gpointer *) &__symbolic_XPRSminim)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSminim could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSminim.\n");
        }
    }
    return __symbolic_XPRSminim(prob, _sflags);
}
int XPRSmaxim (XPRSprob prob, const char *_sflags){
    if (!__symbolic_XPRSmaxim) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSmaxim", (gpointer *) &__symbolic_XPRSmaxim)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSmaxim could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSmaxim.\n");
        }
    }
    return __symbolic_XPRSmaxim(prob, _sflags);
}
int XPRSlpoptimize (XPRSprob prob, const char *_sflags){
    if (!__symbolic_XPRSlpoptimize) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSlpoptimize", (gpointer *) &__symbolic_XPRSlpoptimize)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSlpoptimize could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSlpoptimize.\n");
        }
    }
    return __symbolic_XPRSlpoptimize(prob, _sflags);
}
int XPRSmipoptimize (XPRSprob prob, const char *_sflags){
    if (!__symbolic_XPRSmipoptimize) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSmipoptimize", (gpointer *) &__symbolic_XPRSmipoptimize)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSmipoptimize could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSmipoptimize.\n");
        }
    }
    return __symbolic_XPRSmipoptimize(prob, _sflags);
}
int XPRSrange (XPRSprob prob){
    if (!__symbolic_XPRSrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSrange", (gpointer *) &__symbolic_XPRSrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSrange.\n");
        }
    }
    return __symbolic_XPRSrange(prob);
}
int XPRSgetrowrange (XPRSprob prob, double _upact[], double _loact[], double _uup[], double _udn[]){
    if (!__symbolic_XPRSgetrowrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrowrange", (gpointer *) &__symbolic_XPRSgetrowrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrowrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrowrange.\n");
        }
    }
    return __symbolic_XPRSgetrowrange(prob, _upact, _loact, _uup, _udn);
}
int XPRSgetcolrange (XPRSprob prob, double _upact[], double _loact[], double _uup[], double _udn[], double _ucost[], double _lcost[]){
    if (!__symbolic_XPRSgetcolrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcolrange", (gpointer *) &__symbolic_XPRSgetcolrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcolrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcolrange.\n");
        }
    }
    return __symbolic_XPRSgetcolrange(prob, _upact, _loact, _uup, _udn, _ucost, _lcost);
}
int XPRSgetpivotorder (XPRSprob prob, int mpiv[]){
    if (!__symbolic_XPRSgetpivotorder) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetpivotorder", (gpointer *) &__symbolic_XPRSgetpivotorder)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetpivotorder could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetpivotorder.\n");
        }
    }
    return __symbolic_XPRSgetpivotorder(prob, mpiv);
}
int XPRSgetpresolvemap (XPRSprob prob, int rowmap[], int colmap[]){
    if (!__symbolic_XPRSgetpresolvemap) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetpresolvemap", (gpointer *) &__symbolic_XPRSgetpresolvemap)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetpresolvemap could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetpresolvemap.\n");
        }
    }
    return __symbolic_XPRSgetpresolvemap(prob, rowmap, colmap);
}
int XPRSreadbasis (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSreadbasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSreadbasis", (gpointer *) &__symbolic_XPRSreadbasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSreadbasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSreadbasis.\n");
        }
    }
    return __symbolic_XPRSreadbasis(prob, _sfilename, _sflags);
}
int XPRSwritebasis (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwritebasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwritebasis", (gpointer *) &__symbolic_XPRSwritebasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwritebasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwritebasis.\n");
        }
    }
    return __symbolic_XPRSwritebasis(prob, _sfilename, _sflags);
}
int XPRSglobal (XPRSprob prob){
    if (!__symbolic_XPRSglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSglobal", (gpointer *) &__symbolic_XPRSglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSglobal.\n");
        }
    }
    return __symbolic_XPRSglobal(prob);
}
int XPRSinitglobal (XPRSprob prob){
    if (!__symbolic_XPRSinitglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSinitglobal", (gpointer *) &__symbolic_XPRSinitglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSinitglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSinitglobal.\n");
        }
    }
    return __symbolic_XPRSinitglobal(prob);
}
int XPRSwriteprtsol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwriteprtsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwriteprtsol", (gpointer *) &__symbolic_XPRSwriteprtsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwriteprtsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwriteprtsol.\n");
        }
    }
    return __symbolic_XPRSwriteprtsol(prob, _sfilename, _sflags);
}
int XPRSalter (XPRSprob prob, const char *_sfilename){
    if (!__symbolic_XPRSalter) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSalter", (gpointer *) &__symbolic_XPRSalter)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSalter could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSalter.\n");
        }
    }
    return __symbolic_XPRSalter(prob, _sfilename);
}
int XPRSwritesol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwritesol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwritesol", (gpointer *) &__symbolic_XPRSwritesol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwritesol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwritesol.\n");
        }
    }
    return __symbolic_XPRSwritesol(prob, _sfilename, _sflags);
}
int XPRSwritebinsol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwritebinsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwritebinsol", (gpointer *) &__symbolic_XPRSwritebinsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwritebinsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwritebinsol.\n");
        }
    }
    return __symbolic_XPRSwritebinsol(prob, _sfilename, _sflags);
}
int XPRSreadbinsol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSreadbinsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSreadbinsol", (gpointer *) &__symbolic_XPRSreadbinsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSreadbinsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSreadbinsol.\n");
        }
    }
    return __symbolic_XPRSreadbinsol(prob, _sfilename, _sflags);
}
int XPRSwriteslxsol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwriteslxsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwriteslxsol", (gpointer *) &__symbolic_XPRSwriteslxsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwriteslxsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwriteslxsol.\n");
        }
    }
    return __symbolic_XPRSwriteslxsol(prob, _sfilename, _sflags);
}
int XPRSreadslxsol (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSreadslxsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSreadslxsol", (gpointer *) &__symbolic_XPRSreadslxsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSreadslxsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSreadslxsol.\n");
        }
    }
    return __symbolic_XPRSreadslxsol(prob, _sfilename, _sflags);
}
int XPRSwriteprtrange (XPRSprob prob){
    if (!__symbolic_XPRSwriteprtrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwriteprtrange", (gpointer *) &__symbolic_XPRSwriteprtrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwriteprtrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwriteprtrange.\n");
        }
    }
    return __symbolic_XPRSwriteprtrange(prob);
}
int XPRSwriterange (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwriterange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwriterange", (gpointer *) &__symbolic_XPRSwriterange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwriterange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwriterange.\n");
        }
    }
    return __symbolic_XPRSwriterange(prob, _sfilename, _sflags);
}
int XPRSgetsol (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]){
    if (!__symbolic_XPRSgetsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetsol", (gpointer *) &__symbolic_XPRSgetsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetsol.\n");
        }
    }
    return __symbolic_XPRSgetsol(prob, _dx, _dslack, _dual, _dj);
}
int XPRSgetpresolvesol (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]){
    if (!__symbolic_XPRSgetpresolvesol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetpresolvesol", (gpointer *) &__symbolic_XPRSgetpresolvesol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetpresolvesol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetpresolvesol.\n");
        }
    }
    return __symbolic_XPRSgetpresolvesol(prob, _dx, _dslack, _dual, _dj);
}
int XPRSgetinfeas (XPRSprob prob, int *npv, int *nps, int *nds, int *ndv, int mx[], int mslack[], int mdual[], int mdj[]){
    if (!__symbolic_XPRSgetinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetinfeas", (gpointer *) &__symbolic_XPRSgetinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetinfeas.\n");
        }
    }
    return __symbolic_XPRSgetinfeas(prob, npv, nps, nds, ndv, mx, mslack, mdual, mdj);
}
int XPRSgetscaledinfeas (XPRSprob prob, int *npv, int *nps, int *nds, int *ndv, int mx[], int mslack[], int mdual[], int mdj[]){
    if (!__symbolic_XPRSgetscaledinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetscaledinfeas", (gpointer *) &__symbolic_XPRSgetscaledinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetscaledinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetscaledinfeas.\n");
        }
    }
    return __symbolic_XPRSgetscaledinfeas(prob, npv, nps, nds, ndv, mx, mslack, mdual, mdj);
}
int XPRSgetunbvec (XPRSprob prob, int *icol){
    if (!__symbolic_XPRSgetunbvec) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetunbvec", (gpointer *) &__symbolic_XPRSgetunbvec)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetunbvec could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetunbvec.\n");
        }
    }
    return __symbolic_XPRSgetunbvec(prob, icol);
}
int XPRSbtran (XPRSprob prob, double dwork[]){
    if (!__symbolic_XPRSbtran) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSbtran", (gpointer *) &__symbolic_XPRSbtran)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSbtran could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSbtran.\n");
        }
    }
    return __symbolic_XPRSbtran(prob, dwork);
}
int XPRSftran (XPRSprob prob, double dwork[]){
    if (!__symbolic_XPRSftran) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSftran", (gpointer *) &__symbolic_XPRSftran)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSftran could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSftran.\n");
        }
    }
    return __symbolic_XPRSftran(prob, dwork);
}
int XPRSgetobj (XPRSprob prob, double _dobj[], int first, int last){
    if (!__symbolic_XPRSgetobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetobj", (gpointer *) &__symbolic_XPRSgetobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetobj.\n");
        }
    }
    return __symbolic_XPRSgetobj(prob, _dobj, first, last);
}
int XPRSgetrhs (XPRSprob prob, double _drhs[], int first, int last){
    if (!__symbolic_XPRSgetrhs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrhs", (gpointer *) &__symbolic_XPRSgetrhs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrhs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrhs.\n");
        }
    }
    return __symbolic_XPRSgetrhs(prob, _drhs, first, last);
}
int XPRSgetrhsrange (XPRSprob prob, double _drng[], int first, int last){
    if (!__symbolic_XPRSgetrhsrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrhsrange", (gpointer *) &__symbolic_XPRSgetrhsrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrhsrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrhsrange.\n");
        }
    }
    return __symbolic_XPRSgetrhsrange(prob, _drng, first, last);
}
int XPRSgetlb (XPRSprob prob, double _dbdl[], int first, int last){
    if (!__symbolic_XPRSgetlb) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetlb", (gpointer *) &__symbolic_XPRSgetlb)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetlb could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetlb.\n");
        }
    }
    return __symbolic_XPRSgetlb(prob, _dbdl, first, last);
}
int XPRSgetub (XPRSprob prob, double _dbdu[], int first, int last){
    if (!__symbolic_XPRSgetub) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetub", (gpointer *) &__symbolic_XPRSgetub)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetub could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetub.\n");
        }
    }
    return __symbolic_XPRSgetub(prob, _dbdu, first, last);
}
int XPRSgetcols (XPRSprob prob, int _mstart[], int _mrwind[], double _dmatval[], int maxcoeffs, int *ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcols", (gpointer *) &__symbolic_XPRSgetcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcols.\n");
        }
    }
    return __symbolic_XPRSgetcols(prob, _mstart, _mrwind, _dmatval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetcols64 (XPRSprob prob, long _mstart[], int _mrwind[], double _dmatval[], long maxcoeffs, long * ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetcols64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcols64", (gpointer *) &__symbolic_XPRSgetcols64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcols64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcols64.\n");
        }
    }
    return __symbolic_XPRSgetcols64(prob, _mstart, _mrwind, _dmatval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetrows (XPRSprob prob, int _mstart[], int _mclind[], double _dmatval[], int maxcoeffs, int *ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrows", (gpointer *) &__symbolic_XPRSgetrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrows.\n");
        }
    }
    return __symbolic_XPRSgetrows(prob, _mstart, _mclind, _dmatval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetrows64 (XPRSprob prob, long _mstart[], int _mclind[], double _dmatval[], long maxcoeffs, long * ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetrows64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrows64", (gpointer *) &__symbolic_XPRSgetrows64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrows64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrows64.\n");
        }
    }
    return __symbolic_XPRSgetrows64(prob, _mstart, _mclind, _dmatval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetcoef (XPRSprob prob, int _irow, int _icol, double *_dval){
    if (!__symbolic_XPRSgetcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcoef", (gpointer *) &__symbolic_XPRSgetcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcoef.\n");
        }
    }
    return __symbolic_XPRSgetcoef(prob, _irow, _icol, _dval);
}
int XPRSgetmqobj (XPRSprob prob, int _mstart[], int _mclind[], double _dobjval[], int maxcoeffs, int *ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetmqobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetmqobj", (gpointer *) &__symbolic_XPRSgetmqobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetmqobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetmqobj.\n");
        }
    }
    return __symbolic_XPRSgetmqobj(prob, _mstart, _mclind, _dobjval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetmqobj64 (XPRSprob prob, long _mstart[], int _mclind[], double _dobjval[], long maxcoeffs, long * ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetmqobj64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetmqobj64", (gpointer *) &__symbolic_XPRSgetmqobj64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetmqobj64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetmqobj64.\n");
        }
    }
    return __symbolic_XPRSgetmqobj64(prob, _mstart, _mclind, _dobjval, maxcoeffs, ncoeffs, first, last);
}
int XPRSiisclear (XPRSprob prob){
    if (!__symbolic_XPRSiisclear) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisclear", (gpointer *) &__symbolic_XPRSiisclear)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisclear could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisclear.\n");
        }
    }
    return __symbolic_XPRSiisclear(prob);
}
int XPRSiisfirst (XPRSprob prob, int ifiis, int *status_code){
    if (!__symbolic_XPRSiisfirst) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisfirst", (gpointer *) &__symbolic_XPRSiisfirst)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisfirst could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisfirst.\n");
        }
    }
    return __symbolic_XPRSiisfirst(prob, ifiis, status_code);
}
int XPRSiisnext (XPRSprob prob, int *status_code){
    if (!__symbolic_XPRSiisnext) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisnext", (gpointer *) &__symbolic_XPRSiisnext)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisnext could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisnext.\n");
        }
    }
    return __symbolic_XPRSiisnext(prob, status_code);
}
int XPRSiisstatus (XPRSprob prob, int *iiscount, int rowsizes[], int colsizes[], double suminfeas[], int numinfeas[]){
    if (!__symbolic_XPRSiisstatus) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisstatus", (gpointer *) &__symbolic_XPRSiisstatus)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisstatus could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisstatus.\n");
        }
    }
    return __symbolic_XPRSiisstatus(prob, iiscount, rowsizes, colsizes, suminfeas, numinfeas);
}
int XPRSiisall (XPRSprob prob){
    if (!__symbolic_XPRSiisall) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisall", (gpointer *) &__symbolic_XPRSiisall)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisall could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisall.\n");
        }
    }
    return __symbolic_XPRSiisall(prob);
}
int XPRSiiswrite (XPRSprob prob, int number, const char *fn, int filetype, const char *typeflags){
    if (!__symbolic_XPRSiiswrite) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiiswrite", (gpointer *) &__symbolic_XPRSiiswrite)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiiswrite could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiiswrite.\n");
        }
    }
    return __symbolic_XPRSiiswrite(prob, number, fn, filetype, typeflags);
}
int XPRSiisisolations (XPRSprob prob, int number){
    if (!__symbolic_XPRSiisisolations) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSiisisolations", (gpointer *) &__symbolic_XPRSiisisolations)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSiisisolations could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSiisisolations.\n");
        }
    }
    return __symbolic_XPRSiisisolations(prob, number);
}
int XPRSgetiisdata (XPRSprob prob, int number, int *rownumber, int *colnumber, int miisrow[], int miiscol[], char constrainttype[], char colbndtype[], double duals[], double rdcs[], char isolationrows[], char isolationcols[]){
    if (!__symbolic_XPRSgetiisdata) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetiisdata", (gpointer *) &__symbolic_XPRSgetiisdata)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetiisdata could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetiisdata.\n");
        }
    }
    return __symbolic_XPRSgetiisdata(prob, number, rownumber, colnumber, miisrow, miiscol, constrainttype, colbndtype, duals, rdcs, isolationrows, isolationcols);
}
int XPRSgetiis (XPRSprob prob, int *ncols, int *nrows, int _miiscol[], int _miisrow[]){
    if (!__symbolic_XPRSgetiis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetiis", (gpointer *) &__symbolic_XPRSgetiis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetiis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetiis.\n");
        }
    }
    return __symbolic_XPRSgetiis(prob, ncols, nrows, _miiscol, _miisrow);
}
int XPRSgetpresolvebasis (XPRSprob prob, int _mrowstatus[], int _mcolstatus[]){
    if (!__symbolic_XPRSgetpresolvebasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetpresolvebasis", (gpointer *) &__symbolic_XPRSgetpresolvebasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetpresolvebasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetpresolvebasis.\n");
        }
    }
    return __symbolic_XPRSgetpresolvebasis(prob, _mrowstatus, _mcolstatus);
}
int XPRSloadpresolvebasis (XPRSprob prob, const int _mrowstatus[], const int _mcolstatus[]){
    if (!__symbolic_XPRSloadpresolvebasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadpresolvebasis", (gpointer *) &__symbolic_XPRSloadpresolvebasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadpresolvebasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadpresolvebasis.\n");
        }
    }
    return __symbolic_XPRSloadpresolvebasis(prob, _mrowstatus, _mcolstatus);
}
int XPRSgetglobal (XPRSprob prob, int *ngents, int *nsets, char _sgtype[], int _mgcols[], double _dlim[], char _sstype[], int _msstart[], int _mscols[], double _dref[]){
    if (!__symbolic_XPRSgetglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetglobal", (gpointer *) &__symbolic_XPRSgetglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetglobal.\n");
        }
    }
    return __symbolic_XPRSgetglobal(prob, ngents, nsets, _sgtype, _mgcols, _dlim, _sstype, _msstart, _mscols, _dref);
}
int XPRSgetglobal64 (XPRSprob prob, int *ngents, int *nsets, char _sgtype[], int _mgcols[], double _dlim[], char _sstype[], long _msstart[], int _mscols[], double _dref[]){
    if (!__symbolic_XPRSgetglobal64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetglobal64", (gpointer *) &__symbolic_XPRSgetglobal64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetglobal64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetglobal64.\n");
        }
    }
    return __symbolic_XPRSgetglobal64(prob, ngents, nsets, _sgtype, _mgcols, _dlim, _sstype, _msstart, _mscols, _dref);
}
int XPRSwriteprob (XPRSprob prob, const char *_sfilename, const char *_sflags){
    if (!__symbolic_XPRSwriteprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSwriteprob", (gpointer *) &__symbolic_XPRSwriteprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSwriteprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSwriteprob.\n");
        }
    }
    return __symbolic_XPRSwriteprob(prob, _sfilename, _sflags);
}
int XPRSgetnames (XPRSprob prob, int _itype, char _sbuff[], int first, int last){
    if (!__symbolic_XPRSgetnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetnames", (gpointer *) &__symbolic_XPRSgetnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetnames.\n");
        }
    }
    return __symbolic_XPRSgetnames(prob, _itype, _sbuff, first, last);
}
int XPRSgetrowtype (XPRSprob prob, char _srowtype[], int first, int last){
    if (!__symbolic_XPRSgetrowtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetrowtype", (gpointer *) &__symbolic_XPRSgetrowtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetrowtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetrowtype.\n");
        }
    }
    return __symbolic_XPRSgetrowtype(prob, _srowtype, first, last);
}
int XPRSloadsecurevecs (XPRSprob prob, int nrows, int ncols, const int mrow[], const int mcol[]){
    if (!__symbolic_XPRSloadsecurevecs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadsecurevecs", (gpointer *) &__symbolic_XPRSloadsecurevecs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadsecurevecs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadsecurevecs.\n");
        }
    }
    return __symbolic_XPRSloadsecurevecs(prob, nrows, ncols, mrow, mcol);
}
int XPRSgetcoltype (XPRSprob prob, char _coltype[], int first, int last){
    if (!__symbolic_XPRSgetcoltype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcoltype", (gpointer *) &__symbolic_XPRSgetcoltype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcoltype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcoltype.\n");
        }
    }
    return __symbolic_XPRSgetcoltype(prob, _coltype, first, last);
}
int XPRSgetbasis (XPRSprob prob, int _mrowstatus[], int _mcolstatus[]){
    if (!__symbolic_XPRSgetbasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetbasis", (gpointer *) &__symbolic_XPRSgetbasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetbasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetbasis.\n");
        }
    }
    return __symbolic_XPRSgetbasis(prob, _mrowstatus, _mcolstatus);
}
int XPRSloadbasis (XPRSprob prob, const int _mrowstatus[], const int _mcolstatus[]){
    if (!__symbolic_XPRSloadbasis) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadbasis", (gpointer *) &__symbolic_XPRSloadbasis)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadbasis could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadbasis.\n");
        }
    }
    return __symbolic_XPRSloadbasis(prob, _mrowstatus, _mcolstatus);
}
int XPRSgetindex (XPRSprob prob, int _itype, const char *_sname, int *_iseq){
    if (!__symbolic_XPRSgetindex) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetindex", (gpointer *) &__symbolic_XPRSgetindex)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetindex could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetindex.\n");
        }
    }
    return __symbolic_XPRSgetindex(prob, _itype, _sname, _iseq);
}
int XPRSaddrows (XPRSprob prob, int nrows, int ncoeffs, const char _srowtype[], const double _drhs[], const double _drng[], const int _mstart[], const int _mclind[], const double _dmatval[]){
    if (!__symbolic_XPRSaddrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddrows", (gpointer *) &__symbolic_XPRSaddrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddrows.\n");
        }
    }
    return __symbolic_XPRSaddrows(prob, nrows, ncoeffs, _srowtype, _drhs, _drng, _mstart, _mclind, _dmatval);
}
int XPRSaddrows64 (XPRSprob prob, int nrows, long ncoeffs, const char _srowtype[], const double _drhs[], const double _drng[], const long _mstart[], const int _mclind[], const double _dmatval[]){
    if (!__symbolic_XPRSaddrows64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddrows64", (gpointer *) &__symbolic_XPRSaddrows64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddrows64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddrows64.\n");
        }
    }
    return __symbolic_XPRSaddrows64(prob, nrows, ncoeffs, _srowtype, _drhs, _drng, _mstart, _mclind, _dmatval);
}
int XPRSdelrows (XPRSprob prob, int nrows, const int _mindex[]){
    if (!__symbolic_XPRSdelrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelrows", (gpointer *) &__symbolic_XPRSdelrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelrows.\n");
        }
    }
    return __symbolic_XPRSdelrows(prob, nrows, _mindex);
}
int XPRSaddcols (XPRSprob prob, int ncols, int ncoeffs, const double _dobj[], const int _mstart[], const int _mrwind[], const double _dmatval[], const double _dbdl[], const double _dbdu[]){
    if (!__symbolic_XPRSaddcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcols", (gpointer *) &__symbolic_XPRSaddcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcols.\n");
        }
    }
    return __symbolic_XPRSaddcols(prob, ncols, ncoeffs, _dobj, _mstart, _mrwind, _dmatval, _dbdl, _dbdu);
}
int XPRSaddcols64 (XPRSprob prob, int ncols, long ncoeffs, const double _dobj[], const long _mstart[], const int _mrwind[], const double _dmatval[], const double _dbdl[], const double _dbdu[]){
    if (!__symbolic_XPRSaddcols64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcols64", (gpointer *) &__symbolic_XPRSaddcols64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcols64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcols64.\n");
        }
    }
    return __symbolic_XPRSaddcols64(prob, ncols, ncoeffs, _dobj, _mstart, _mrwind, _dmatval, _dbdl, _dbdu);
}
int XPRSdelcols (XPRSprob prob, int ncols, const int _mindex[]){
    if (!__symbolic_XPRSdelcols) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelcols", (gpointer *) &__symbolic_XPRSdelcols)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelcols could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelcols.\n");
        }
    }
    return __symbolic_XPRSdelcols(prob, ncols, _mindex);
}
int XPRSchgcoltype (XPRSprob prob, int ncols, const int _mindex[], const char _coltype[]){
    if (!__symbolic_XPRSchgcoltype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgcoltype", (gpointer *) &__symbolic_XPRSchgcoltype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgcoltype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgcoltype.\n");
        }
    }
    return __symbolic_XPRSchgcoltype(prob, ncols, _mindex, _coltype);
}
int XPRSchgrowtype (XPRSprob prob, int nrows, const int _mindex[], const char _srowtype[]){
    if (!__symbolic_XPRSchgrowtype) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgrowtype", (gpointer *) &__symbolic_XPRSchgrowtype)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgrowtype could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgrowtype.\n");
        }
    }
    return __symbolic_XPRSchgrowtype(prob, nrows, _mindex, _srowtype);
}
int XPRSchgbounds (XPRSprob prob, int nbnds, const int _mindex[], const char _sboundtype[], const double _dbnd[]){
    if (!__symbolic_XPRSchgbounds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgbounds", (gpointer *) &__symbolic_XPRSchgbounds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgbounds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgbounds.\n");
        }
    }
    return __symbolic_XPRSchgbounds(prob, nbnds, _mindex, _sboundtype, _dbnd);
}
int XPRSchgobj (XPRSprob prob, int ncols, const int _mindex[], const double _dobj[]){
    if (!__symbolic_XPRSchgobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgobj", (gpointer *) &__symbolic_XPRSchgobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgobj.\n");
        }
    }
    return __symbolic_XPRSchgobj(prob, ncols, _mindex, _dobj);
}
int XPRSchgcoef (XPRSprob prob, int _irow, int _icol, double _dval){
    if (!__symbolic_XPRSchgcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgcoef", (gpointer *) &__symbolic_XPRSchgcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgcoef.\n");
        }
    }
    return __symbolic_XPRSchgcoef(prob, _irow, _icol, _dval);
}
int XPRSchgmcoef (XPRSprob prob, int ncoeffs, const int _mrow[], const int _mcol[], const double _dval[]){
    if (!__symbolic_XPRSchgmcoef) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgmcoef", (gpointer *) &__symbolic_XPRSchgmcoef)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgmcoef could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgmcoef.\n");
        }
    }
    return __symbolic_XPRSchgmcoef(prob, ncoeffs, _mrow, _mcol, _dval);
}
int XPRSchgmcoef64 (XPRSprob prob, long ncoeffs, const int _mrow[], const int _mcol[], const double _dval[]){
    if (!__symbolic_XPRSchgmcoef64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgmcoef64", (gpointer *) &__symbolic_XPRSchgmcoef64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgmcoef64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgmcoef64.\n");
        }
    }
    return __symbolic_XPRSchgmcoef64(prob, ncoeffs, _mrow, _mcol, _dval);
}
int XPRSchgmqobj (XPRSprob prob, int ncols, const int _mcol1[], const int _mcol2[], const double _dval[]){
    if (!__symbolic_XPRSchgmqobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgmqobj", (gpointer *) &__symbolic_XPRSchgmqobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgmqobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgmqobj.\n");
        }
    }
    return __symbolic_XPRSchgmqobj(prob, ncols, _mcol1, _mcol2, _dval);
}
int XPRSchgmqobj64 (XPRSprob prob, long ncols, const int _mcol1[], const int _mcol2[], const double _dval[]){
    if (!__symbolic_XPRSchgmqobj64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgmqobj64", (gpointer *) &__symbolic_XPRSchgmqobj64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgmqobj64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgmqobj64.\n");
        }
    }
    return __symbolic_XPRSchgmqobj64(prob, ncols, _mcol1, _mcol2, _dval);
}
int XPRSchgqobj (XPRSprob prob, int _icol, int _jcol, double _dval){
    if (!__symbolic_XPRSchgqobj) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgqobj", (gpointer *) &__symbolic_XPRSchgqobj)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgqobj could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgqobj.\n");
        }
    }
    return __symbolic_XPRSchgqobj(prob, _icol, _jcol, _dval);
}
int XPRSchgrhs (XPRSprob prob, int nrows, const int _mindex[], const double _drhs[]){
    if (!__symbolic_XPRSchgrhs) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgrhs", (gpointer *) &__symbolic_XPRSchgrhs)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgrhs could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgrhs.\n");
        }
    }
    return __symbolic_XPRSchgrhs(prob, nrows, _mindex, _drhs);
}
int XPRSchgrhsrange (XPRSprob prob, int nrows, const int _mindex[], const double _drng[]){
    if (!__symbolic_XPRSchgrhsrange) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgrhsrange", (gpointer *) &__symbolic_XPRSchgrhsrange)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgrhsrange could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgrhsrange.\n");
        }
    }
    return __symbolic_XPRSchgrhsrange(prob, nrows, _mindex, _drng);
}
int XPRSchgobjsense (XPRSprob prob, int objsense){
    if (!__symbolic_XPRSchgobjsense) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgobjsense", (gpointer *) &__symbolic_XPRSchgobjsense)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgobjsense could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgobjsense.\n");
        }
    }
    return __symbolic_XPRSchgobjsense(prob, objsense);
}
int XPRSchgglblimit (XPRSprob prob, int ncols, const int _mindex[], const double _dlimit[]){
    if (!__symbolic_XPRSchgglblimit) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgglblimit", (gpointer *) &__symbolic_XPRSchgglblimit)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgglblimit could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgglblimit.\n");
        }
    }
    return __symbolic_XPRSchgglblimit(prob, ncols, _mindex, _dlimit);
}
int XPRSsave (XPRSprob prob){
    if (!__symbolic_XPRSsave) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsave", (gpointer *) &__symbolic_XPRSsave)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsave could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsave.\n");
        }
    }
    return __symbolic_XPRSsave(prob);
}
int XPRSrestore (XPRSprob prob, const char *_sprobname, const char *_force){
    if (!__symbolic_XPRSrestore) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSrestore", (gpointer *) &__symbolic_XPRSrestore)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSrestore could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSrestore.\n");
        }
    }
    return __symbolic_XPRSrestore(prob, _sprobname, _force);
}
int XPRSpivot (XPRSprob prob, int _in, int _out){
    if (!__symbolic_XPRSpivot) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSpivot", (gpointer *) &__symbolic_XPRSpivot)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSpivot could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSpivot.\n");
        }
    }
    return __symbolic_XPRSpivot(prob, _in, _out);
}
int XPRSgetpivots (XPRSprob prob, int _in, int _mout[], double _dout[], double *_dobjo, int *npiv, int maxpiv){
    if (!__symbolic_XPRSgetpivots) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetpivots", (gpointer *) &__symbolic_XPRSgetpivots)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetpivots could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetpivots.\n");
        }
    }
    return __symbolic_XPRSgetpivots(prob, _in, _mout, _dout, _dobjo, npiv, maxpiv);
}
int XPRSaddcuts (XPRSprob prob, int ncuts, const int mtype[], const char qrtype[], const double drhs[], const int mstart[], const int mcols[], const double dmatval[]){
    if (!__symbolic_XPRSaddcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcuts", (gpointer *) &__symbolic_XPRSaddcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcuts.\n");
        }
    }
    return __symbolic_XPRSaddcuts(prob, ncuts, mtype, qrtype, drhs, mstart, mcols, dmatval);
}
int XPRSaddcuts64 (XPRSprob prob, int ncuts, const int mtype[], const char qrtype[], const double drhs[], const long mstart[], const int mcols[], const double dmatval[]){
    if (!__symbolic_XPRSaddcuts64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcuts64", (gpointer *) &__symbolic_XPRSaddcuts64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcuts64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcuts64.\n");
        }
    }
    return __symbolic_XPRSaddcuts64(prob, ncuts, mtype, qrtype, drhs, mstart, mcols, dmatval);
}
int XPRSdelcuts (XPRSprob prob, int ibasis, int itype, int interp, double delta, int ncuts, const XPRScut mcutind[]){
    if (!__symbolic_XPRSdelcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelcuts", (gpointer *) &__symbolic_XPRSdelcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelcuts.\n");
        }
    }
    return __symbolic_XPRSdelcuts(prob, ibasis, itype, interp, delta, ncuts, mcutind);
}
int XPRSdelcpcuts (XPRSprob prob, int itype, int interp, int ncuts, const XPRScut mcutind[]){
    if (!__symbolic_XPRSdelcpcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelcpcuts", (gpointer *) &__symbolic_XPRSdelcpcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelcpcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelcpcuts.\n");
        }
    }
    return __symbolic_XPRSdelcpcuts(prob, itype, interp, ncuts, mcutind);
}
int XPRSgetcutlist (XPRSprob prob, int itype, int interp, int *ncuts, int maxcuts, XPRScut mcutind[]){
    if (!__symbolic_XPRSgetcutlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcutlist", (gpointer *) &__symbolic_XPRSgetcutlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcutlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcutlist.\n");
        }
    }
    return __symbolic_XPRSgetcutlist(prob, itype, interp, ncuts, maxcuts, mcutind);
}
int XPRSgetcpcutlist (XPRSprob prob, int itype, int interp, double delta, int *ncuts, int maxcuts, XPRScut mcutind[], double dviol[]){
    if (!__symbolic_XPRSgetcpcutlist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcpcutlist", (gpointer *) &__symbolic_XPRSgetcpcutlist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcpcutlist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcpcutlist.\n");
        }
    }
    return __symbolic_XPRSgetcpcutlist(prob, itype, interp, delta, ncuts, maxcuts, mcutind, dviol);
}
int XPRSgetcpcuts (XPRSprob prob, const XPRScut mindex[], int ncuts, int size, int mtype[], char qrtype[], int mstart[], int mcols[], double dmatval[], double drhs[]){
    if (!__symbolic_XPRSgetcpcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcpcuts", (gpointer *) &__symbolic_XPRSgetcpcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcpcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcpcuts.\n");
        }
    }
    return __symbolic_XPRSgetcpcuts(prob, mindex, ncuts, size, mtype, qrtype, mstart, mcols, dmatval, drhs);
}
int XPRSgetcpcuts64 (XPRSprob prob, const XPRScut mindex[], int ncuts, long size, int mtype[], char qrtype[], long mstart[], int mcols[], double dmatval[], double drhs[]){
    if (!__symbolic_XPRSgetcpcuts64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcpcuts64", (gpointer *) &__symbolic_XPRSgetcpcuts64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcpcuts64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcpcuts64.\n");
        }
    }
    return __symbolic_XPRSgetcpcuts64(prob, mindex, ncuts, size, mtype, qrtype, mstart, mcols, dmatval, drhs);
}
int XPRSloadcuts (XPRSprob prob, int itype, int interp, int ncuts, const XPRScut mcutind[]){
    if (!__symbolic_XPRSloadcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadcuts", (gpointer *) &__symbolic_XPRSloadcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadcuts.\n");
        }
    }
    return __symbolic_XPRSloadcuts(prob, itype, interp, ncuts, mcutind);
}
int XPRSstorecuts (XPRSprob prob, int ncuts, int nodupl, const int mtype[], const char qrtype[], const double drhs[], const int mstart[], XPRScut mindex[], const int mcols[], const double dmatval[]){
    if (!__symbolic_XPRSstorecuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSstorecuts", (gpointer *) &__symbolic_XPRSstorecuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSstorecuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSstorecuts.\n");
        }
    }
    return __symbolic_XPRSstorecuts(prob, ncuts, nodupl, mtype, qrtype, drhs, mstart, mindex, mcols, dmatval);
}
int XPRSstorecuts64 (XPRSprob prob, int ncuts, int nodupl, const int mtype[], const char qrtype[], const double drhs[], const long mstart[], XPRScut mindex[], const int mcols[], const double dmatval[]){
    if (!__symbolic_XPRSstorecuts64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSstorecuts64", (gpointer *) &__symbolic_XPRSstorecuts64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSstorecuts64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSstorecuts64.\n");
        }
    }
    return __symbolic_XPRSstorecuts64(prob, ncuts, nodupl, mtype, qrtype, drhs, mstart, mindex, mcols, dmatval);
}
int XPRSpresolverow (XPRSprob prob, char qrtype, int nzo, const int mcolso[], const double dvalo[], double drhso, int maxcoeffs, int *nzp, int mcolsp[], double dvalp[], double *drhsp, int *status){
    if (!__symbolic_XPRSpresolverow) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSpresolverow", (gpointer *) &__symbolic_XPRSpresolverow)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSpresolverow could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSpresolverow.\n");
        }
    }
    return __symbolic_XPRSpresolverow(prob, qrtype, nzo, mcolso, dvalo, drhso, maxcoeffs, nzp, mcolsp, dvalp, drhsp, status);
}
int XPRSloadmipsol (XPRSprob prob, const double dsol[], int *status){
    if (!__symbolic_XPRSloadmipsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadmipsol", (gpointer *) &__symbolic_XPRSloadmipsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadmipsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadmipsol.\n");
        }
    }
    return __symbolic_XPRSloadmipsol(prob, dsol, status);
}
int XPRSaddmipsol (XPRSprob prob, int ilength, const double mipsolval[], const int mipsolcol[], int *p_id){
    if (!__symbolic_XPRSaddmipsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddmipsol", (gpointer *) &__symbolic_XPRSaddmipsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddmipsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddmipsol.\n");
        }
    }
    return __symbolic_XPRSaddmipsol(prob, ilength, mipsolval, mipsolcol, p_id);
}
int XPRSstorebounds (XPRSprob prob, int nbnds, const int mcols[], const char qbtype[], const double dbnd[], void **mindex){
    if (!__symbolic_XPRSstorebounds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSstorebounds", (gpointer *) &__symbolic_XPRSstorebounds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSstorebounds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSstorebounds.\n");
        }
    }
    return __symbolic_XPRSstorebounds(prob, nbnds, mcols, qbtype, dbnd, mindex);
}
int XPRSsetbranchcuts (XPRSprob prob, int nbcuts, const XPRScut mindex[]){
    if (!__symbolic_XPRSsetbranchcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetbranchcuts", (gpointer *) &__symbolic_XPRSsetbranchcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetbranchcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetbranchcuts.\n");
        }
    }
    return __symbolic_XPRSsetbranchcuts(prob, nbcuts, mindex);
}
int XPRSsetbranchbounds (XPRSprob prob, void *mindex){
    if (!__symbolic_XPRSsetbranchbounds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetbranchbounds", (gpointer *) &__symbolic_XPRSsetbranchbounds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetbranchbounds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetbranchbounds.\n");
        }
    }
    return __symbolic_XPRSsetbranchbounds(prob, mindex);
}
int XPRSgetlasterror (XPRSprob prob, char *errmsg){
    if (!__symbolic_XPRSgetlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetlasterror", (gpointer *) &__symbolic_XPRSgetlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetlasterror.\n");
        }
    }
    return __symbolic_XPRSgetlasterror(prob, errmsg);
}
int XPRSbasiscondition (XPRSprob prob, double *condnum, double *scondnum){
    if (!__symbolic_XPRSbasiscondition) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSbasiscondition", (gpointer *) &__symbolic_XPRSbasiscondition)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSbasiscondition could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSbasiscondition.\n");
        }
    }
    return __symbolic_XPRSbasiscondition(prob, condnum, scondnum);
}
int XPRSgetmipsol (XPRSprob prob, double _dx[], double _dslack[]){
    if (!__symbolic_XPRSgetmipsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetmipsol", (gpointer *) &__symbolic_XPRSgetmipsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetmipsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetmipsol.\n");
        }
    }
    return __symbolic_XPRSgetmipsol(prob, _dx, _dslack);
}
int XPRSgetlpsol (XPRSprob prob, double _dx[], double _dslack[], double _dual[], double _dj[]){
    if (!__symbolic_XPRSgetlpsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetlpsol", (gpointer *) &__symbolic_XPRSgetlpsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetlpsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetlpsol.\n");
        }
    }
    return __symbolic_XPRSgetlpsol(prob, _dx, _dslack, _dual, _dj);
}
int XPRSpostsolve (XPRSprob prob){
    if (!__symbolic_XPRSpostsolve) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSpostsolve", (gpointer *) &__symbolic_XPRSpostsolve)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSpostsolve could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSpostsolve.\n");
        }
    }
    return __symbolic_XPRSpostsolve(prob);
}
int XPRSdelsets (XPRSprob prob, int nsets, const int msindex[]){
    if (!__symbolic_XPRSdelsets) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelsets", (gpointer *) &__symbolic_XPRSdelsets)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelsets could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelsets.\n");
        }
    }
    return __symbolic_XPRSdelsets(prob, nsets, msindex);
}
int XPRSaddsets (XPRSprob prob, int newsets, int newnz, const char qstype[], const int msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSaddsets) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddsets", (gpointer *) &__symbolic_XPRSaddsets)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddsets could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddsets.\n");
        }
    }
    return __symbolic_XPRSaddsets(prob, newsets, newnz, qstype, msstart, mscols, dref);
}
int XPRSaddsets64 (XPRSprob prob, int newsets, long newnz, const char qstype[], const long msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSaddsets64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddsets64", (gpointer *) &__symbolic_XPRSaddsets64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddsets64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddsets64.\n");
        }
    }
    return __symbolic_XPRSaddsets64(prob, newsets, newnz, qstype, msstart, mscols, dref);
}
int XPRSstrongbranch (XPRSprob prob, const int nbnds, const int _mindex[], const char _sboundtype[], const double _dbnd[], const int itrlimit, double _dsbobjval[], int _msbstatus[]){
    if (!__symbolic_XPRSstrongbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSstrongbranch", (gpointer *) &__symbolic_XPRSstrongbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSstrongbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSstrongbranch.\n");
        }
    }
    return __symbolic_XPRSstrongbranch(prob, nbnds, _mindex, _sboundtype, _dbnd, itrlimit, _dsbobjval, _msbstatus);
}
int XPRSgetprimalray (XPRSprob prob, double _dpray[], int *_hasray){
    if (!__symbolic_XPRSgetprimalray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetprimalray", (gpointer *) &__symbolic_XPRSgetprimalray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetprimalray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetprimalray.\n");
        }
    }
    return __symbolic_XPRSgetprimalray(prob, _dpray, _hasray);
}
int XPRSgetdualray (XPRSprob prob, double _ddray[], int *_hasray){
    if (!__symbolic_XPRSgetdualray) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetdualray", (gpointer *) &__symbolic_XPRSgetdualray)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetdualray could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetdualray.\n");
        }
    }
    return __symbolic_XPRSgetdualray(prob, _ddray, _hasray);
}
int XPRSsetmessagestatus (XPRSprob prob, int errcode, int bEnabledStatus){
    if (!__symbolic_XPRSsetmessagestatus) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetmessagestatus", (gpointer *) &__symbolic_XPRSsetmessagestatus)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetmessagestatus could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetmessagestatus.\n");
        }
    }
    return __symbolic_XPRSsetmessagestatus(prob, errcode, bEnabledStatus);
}
int XPRSgetmessagestatus (XPRSprob prob, int errcode, int *bEnabledStatus){
    if (!__symbolic_XPRSgetmessagestatus) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetmessagestatus", (gpointer *) &__symbolic_XPRSgetmessagestatus)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetmessagestatus could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetmessagestatus.\n");
        }
    }
    return __symbolic_XPRSgetmessagestatus(prob, errcode, bEnabledStatus);
}
int XPRSrepairweightedinfeas (XPRSprob prob, int *scode, const double lrp_array[], const double grp_array[], const double lbp_array[], const double ubp_array[], char second_phase, double delta, const char *optflags){
    if (!__symbolic_XPRSrepairweightedinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSrepairweightedinfeas", (gpointer *) &__symbolic_XPRSrepairweightedinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSrepairweightedinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSrepairweightedinfeas.\n");
        }
    }
    return __symbolic_XPRSrepairweightedinfeas(prob, scode, lrp_array, grp_array, lbp_array, ubp_array, second_phase, delta, optflags);
}
int XPRSrepairinfeas (XPRSprob prob, int *scode, char ptype, char phase2, char globalflags, double lrp, double grp, double lbp, double ubp, double delta){
    if (!__symbolic_XPRSrepairinfeas) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSrepairinfeas", (gpointer *) &__symbolic_XPRSrepairinfeas)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSrepairinfeas could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSrepairinfeas.\n");
        }
    }
    return __symbolic_XPRSrepairinfeas(prob, scode, ptype, phase2, globalflags, lrp, grp, lbp, ubp, delta);
}
int XPRSgetcutslack (XPRSprob prob, XPRScut cut, double *dslack){
    if (!__symbolic_XPRSgetcutslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcutslack", (gpointer *) &__symbolic_XPRSgetcutslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcutslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcutslack.\n");
        }
    }
    return __symbolic_XPRSgetcutslack(prob, cut, dslack);
}
int XPRSgetcutmap (XPRSprob prob, int ncuts, const XPRScut cuts[], int cutmap[]){
    if (!__symbolic_XPRSgetcutmap) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcutmap", (gpointer *) &__symbolic_XPRSgetcutmap)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcutmap could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcutmap.\n");
        }
    }
    return __symbolic_XPRSgetcutmap(prob, ncuts, cuts, cutmap);
}
int XPRSbasisstability (XPRSprob prob, int typecode, int norm, int ifscaled, double *dval){
    if (!__symbolic_XPRSbasisstability) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSbasisstability", (gpointer *) &__symbolic_XPRSbasisstability)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSbasisstability could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSbasisstability.\n");
        }
    }
    return __symbolic_XPRSbasisstability(prob, typecode, norm, ifscaled, dval);
}
int XPRSgetnamelist (XPRSprob prob, int _itype, char _sbuff[], int names_len, int *names_len_reqd, int first, int last){
    if (!__symbolic_XPRSgetnamelist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetnamelist", (gpointer *) &__symbolic_XPRSgetnamelist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetnamelist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetnamelist.\n");
        }
    }
    return __symbolic_XPRSgetnamelist(prob, _itype, _sbuff, names_len, names_len_reqd, first, last);
}
int XPRSgetnamelistobject (XPRSprob prob, int _itype, XPRSnamelist * r_nl){
    if (!__symbolic_XPRSgetnamelistobject) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetnamelistobject", (gpointer *) &__symbolic_XPRSgetnamelistobject)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetnamelistobject could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetnamelistobject.\n");
        }
    }
    return __symbolic_XPRSgetnamelistobject(prob, _itype, r_nl);
}
int XPRSlogfilehandler (XPRSobject obj, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode){
    if (!__symbolic_XPRSlogfilehandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSlogfilehandler", (gpointer *) &__symbolic_XPRSlogfilehandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSlogfilehandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSlogfilehandler.\n");
        }
    }
    return __symbolic_XPRSlogfilehandler(obj, vUserContext, vSystemThreadId, sMsg, iMsgType, iMsgCode);
}
int XPRSgetobjecttypename (XPRSobject obj, const char **sObjectName){
    if (!__symbolic_XPRSgetobjecttypename) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetobjecttypename", (gpointer *) &__symbolic_XPRSgetobjecttypename)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetobjecttypename could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetobjecttypename.\n");
        }
    }
    return __symbolic_XPRSgetobjecttypename(obj, sObjectName);
}
int XPRSsetcblplog (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcblplog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcblplog", (gpointer *) &__symbolic_XPRSsetcblplog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcblplog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcblplog.\n");
        }
    }
    return __symbolic_XPRSsetcblplog(prob, f_lplog, p);
}
int XPRSgetcblplog (XPRSprob prob, int ( ** f_lplog) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcblplog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcblplog", (gpointer *) &__symbolic_XPRSgetcblplog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcblplog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcblplog.\n");
        }
    }
    return __symbolic_XPRSgetcblplog(prob, f_lplog, p);
}
int XPRSaddcblplog (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcblplog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcblplog", (gpointer *) &__symbolic_XPRSaddcblplog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcblplog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcblplog.\n");
        }
    }
    return __symbolic_XPRSaddcblplog(prob, f_lplog, p, priority);
}
int XPRSremovecblplog (XPRSprob prob, int ( * f_lplog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecblplog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecblplog", (gpointer *) &__symbolic_XPRSremovecblplog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecblplog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecblplog.\n");
        }
    }
    return __symbolic_XPRSremovecblplog(prob, f_lplog, p);
}
int XPRSsetcbgloballog (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbgloballog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbgloballog", (gpointer *) &__symbolic_XPRSsetcbgloballog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbgloballog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbgloballog.\n");
        }
    }
    return __symbolic_XPRSsetcbgloballog(prob, f_globallog, p);
}
int XPRSgetcbgloballog (XPRSprob prob, int ( ** f_globallog) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbgloballog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbgloballog", (gpointer *) &__symbolic_XPRSgetcbgloballog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbgloballog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbgloballog.\n");
        }
    }
    return __symbolic_XPRSgetcbgloballog(prob, f_globallog, p);
}
int XPRSaddcbgloballog (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbgloballog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbgloballog", (gpointer *) &__symbolic_XPRSaddcbgloballog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbgloballog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbgloballog.\n");
        }
    }
    return __symbolic_XPRSaddcbgloballog(prob, f_globallog, p, priority);
}
int XPRSremovecbgloballog (XPRSprob prob, int ( * f_globallog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbgloballog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbgloballog", (gpointer *) &__symbolic_XPRSremovecbgloballog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbgloballog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbgloballog.\n");
        }
    }
    return __symbolic_XPRSremovecbgloballog(prob, f_globallog, p);
}
int XPRSsetcbcutlog (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbcutlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbcutlog", (gpointer *) &__symbolic_XPRSsetcbcutlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbcutlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbcutlog.\n");
        }
    }
    return __symbolic_XPRSsetcbcutlog(prob, f_cutlog, p);
}
int XPRSgetcbcutlog (XPRSprob prob, int ( ** f_cutlog) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbcutlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbcutlog", (gpointer *) &__symbolic_XPRSgetcbcutlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbcutlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbcutlog.\n");
        }
    }
    return __symbolic_XPRSgetcbcutlog(prob, f_cutlog, p);
}
int XPRSaddcbcutlog (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbcutlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbcutlog", (gpointer *) &__symbolic_XPRSaddcbcutlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbcutlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbcutlog.\n");
        }
    }
    return __symbolic_XPRSaddcbcutlog(prob, f_cutlog, p, priority);
}
int XPRSremovecbcutlog (XPRSprob prob, int ( * f_cutlog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbcutlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbcutlog", (gpointer *) &__symbolic_XPRSremovecbcutlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbcutlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbcutlog.\n");
        }
    }
    return __symbolic_XPRSremovecbcutlog(prob, f_cutlog, p);
}
int XPRSsetcbbarlog (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbbarlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbbarlog", (gpointer *) &__symbolic_XPRSsetcbbarlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbbarlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbbarlog.\n");
        }
    }
    return __symbolic_XPRSsetcbbarlog(prob, f_barlog, p);
}
int XPRSgetcbbarlog (XPRSprob prob, int ( ** f_barlog) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbbarlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbbarlog", (gpointer *) &__symbolic_XPRSgetcbbarlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbbarlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbbarlog.\n");
        }
    }
    return __symbolic_XPRSgetcbbarlog(prob, f_barlog, p);
}
int XPRSaddcbbarlog (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbbarlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbbarlog", (gpointer *) &__symbolic_XPRSaddcbbarlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbbarlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbbarlog.\n");
        }
    }
    return __symbolic_XPRSaddcbbarlog(prob, f_barlog, p, priority);
}
int XPRSremovecbbarlog (XPRSprob prob, int ( * f_barlog) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbbarlog) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbbarlog", (gpointer *) &__symbolic_XPRSremovecbbarlog)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbbarlog could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbbarlog.\n");
        }
    }
    return __symbolic_XPRSremovecbbarlog(prob, f_barlog, p);
}
int XPRSsetcbcutmgr (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbcutmgr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbcutmgr", (gpointer *) &__symbolic_XPRSsetcbcutmgr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbcutmgr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbcutmgr.\n");
        }
    }
    return __symbolic_XPRSsetcbcutmgr(prob, f_cutmgr, p);
}
int XPRSgetcbcutmgr (XPRSprob prob, int ( ** f_cutmgr) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbcutmgr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbcutmgr", (gpointer *) &__symbolic_XPRSgetcbcutmgr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbcutmgr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbcutmgr.\n");
        }
    }
    return __symbolic_XPRSgetcbcutmgr(prob, f_cutmgr, p);
}
int XPRSaddcbcutmgr (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbcutmgr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbcutmgr", (gpointer *) &__symbolic_XPRSaddcbcutmgr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbcutmgr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbcutmgr.\n");
        }
    }
    return __symbolic_XPRSaddcbcutmgr(prob, f_cutmgr, p, priority);
}
int XPRSremovecbcutmgr (XPRSprob prob, int ( * f_cutmgr) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbcutmgr) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbcutmgr", (gpointer *) &__symbolic_XPRSremovecbcutmgr)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbcutmgr could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbcutmgr.\n");
        }
    }
    return __symbolic_XPRSremovecbcutmgr(prob, f_cutmgr, p);
}
int XPRSsetcbchgnode (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p){
    if (!__symbolic_XPRSsetcbchgnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbchgnode", (gpointer *) &__symbolic_XPRSsetcbchgnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbchgnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbchgnode.\n");
        }
    }
    return __symbolic_XPRSsetcbchgnode(prob, f_chgnode, p);
}
int XPRSgetcbchgnode (XPRSprob prob, void ( ** f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void **p){
    if (!__symbolic_XPRSgetcbchgnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbchgnode", (gpointer *) &__symbolic_XPRSgetcbchgnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbchgnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbchgnode.\n");
        }
    }
    return __symbolic_XPRSgetcbchgnode(prob, f_chgnode, p);
}
int XPRSaddcbchgnode (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p, int priority){
    if (!__symbolic_XPRSaddcbchgnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbchgnode", (gpointer *) &__symbolic_XPRSaddcbchgnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbchgnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbchgnode.\n");
        }
    }
    return __symbolic_XPRSaddcbchgnode(prob, f_chgnode, p, priority);
}
int XPRSremovecbchgnode (XPRSprob prob, void ( * f_chgnode) (XPRSprob prob, void *vContext, int *nodnum), void *p){
    if (!__symbolic_XPRSremovecbchgnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbchgnode", (gpointer *) &__symbolic_XPRSremovecbchgnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbchgnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbchgnode.\n");
        }
    }
    return __symbolic_XPRSremovecbchgnode(prob, f_chgnode, p);
}
int XPRSsetcboptnode (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p){
    if (!__symbolic_XPRSsetcboptnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcboptnode", (gpointer *) &__symbolic_XPRSsetcboptnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcboptnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcboptnode.\n");
        }
    }
    return __symbolic_XPRSsetcboptnode(prob, f_optnode, p);
}
int XPRSgetcboptnode (XPRSprob prob, void ( ** f_optnode) (XPRSprob prob, void *vContext, int *feas), void **p){
    if (!__symbolic_XPRSgetcboptnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcboptnode", (gpointer *) &__symbolic_XPRSgetcboptnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcboptnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcboptnode.\n");
        }
    }
    return __symbolic_XPRSgetcboptnode(prob, f_optnode, p);
}
int XPRSaddcboptnode (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p, int priority){
    if (!__symbolic_XPRSaddcboptnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcboptnode", (gpointer *) &__symbolic_XPRSaddcboptnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcboptnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcboptnode.\n");
        }
    }
    return __symbolic_XPRSaddcboptnode(prob, f_optnode, p, priority);
}
int XPRSremovecboptnode (XPRSprob prob, void ( * f_optnode) (XPRSprob prob, void *vContext, int *feas), void *p){
    if (!__symbolic_XPRSremovecboptnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecboptnode", (gpointer *) &__symbolic_XPRSremovecboptnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecboptnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecboptnode.\n");
        }
    }
    return __symbolic_XPRSremovecboptnode(prob, f_optnode, p);
}
int XPRSsetcbprenode (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p){
    if (!__symbolic_XPRSsetcbprenode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbprenode", (gpointer *) &__symbolic_XPRSsetcbprenode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbprenode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbprenode.\n");
        }
    }
    return __symbolic_XPRSsetcbprenode(prob, f_prenode, p);
}
int XPRSgetcbprenode (XPRSprob prob, void ( ** f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void **p){
    if (!__symbolic_XPRSgetcbprenode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbprenode", (gpointer *) &__symbolic_XPRSgetcbprenode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbprenode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbprenode.\n");
        }
    }
    return __symbolic_XPRSgetcbprenode(prob, f_prenode, p);
}
int XPRSaddcbprenode (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p, int priority){
    if (!__symbolic_XPRSaddcbprenode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbprenode", (gpointer *) &__symbolic_XPRSaddcbprenode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbprenode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbprenode.\n");
        }
    }
    return __symbolic_XPRSaddcbprenode(prob, f_prenode, p, priority);
}
int XPRSremovecbprenode (XPRSprob prob, void ( * f_prenode) (XPRSprob prob, void *vContext, int *nodinfeas), void *p){
    if (!__symbolic_XPRSremovecbprenode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbprenode", (gpointer *) &__symbolic_XPRSremovecbprenode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbprenode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbprenode.\n");
        }
    }
    return __symbolic_XPRSremovecbprenode(prob, f_prenode, p);
}
int XPRSsetcbinfnode (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbinfnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbinfnode", (gpointer *) &__symbolic_XPRSsetcbinfnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbinfnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbinfnode.\n");
        }
    }
    return __symbolic_XPRSsetcbinfnode(prob, f_infnode, p);
}
int XPRSgetcbinfnode (XPRSprob prob, void ( ** f_infnode) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbinfnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbinfnode", (gpointer *) &__symbolic_XPRSgetcbinfnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbinfnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbinfnode.\n");
        }
    }
    return __symbolic_XPRSgetcbinfnode(prob, f_infnode, p);
}
int XPRSaddcbinfnode (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbinfnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbinfnode", (gpointer *) &__symbolic_XPRSaddcbinfnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbinfnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbinfnode.\n");
        }
    }
    return __symbolic_XPRSaddcbinfnode(prob, f_infnode, p, priority);
}
int XPRSremovecbinfnode (XPRSprob prob, void ( * f_infnode) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbinfnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbinfnode", (gpointer *) &__symbolic_XPRSremovecbinfnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbinfnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbinfnode.\n");
        }
    }
    return __symbolic_XPRSremovecbinfnode(prob, f_infnode, p);
}
int XPRSsetcbnodecutoff (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p){
    if (!__symbolic_XPRSsetcbnodecutoff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbnodecutoff", (gpointer *) &__symbolic_XPRSsetcbnodecutoff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbnodecutoff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbnodecutoff.\n");
        }
    }
    return __symbolic_XPRSsetcbnodecutoff(prob, f_nodecutoff, p);
}
int XPRSgetcbnodecutoff (XPRSprob prob, void ( ** f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void **p){
    if (!__symbolic_XPRSgetcbnodecutoff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbnodecutoff", (gpointer *) &__symbolic_XPRSgetcbnodecutoff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbnodecutoff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbnodecutoff.\n");
        }
    }
    return __symbolic_XPRSgetcbnodecutoff(prob, f_nodecutoff, p);
}
int XPRSaddcbnodecutoff (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p, int priority){
    if (!__symbolic_XPRSaddcbnodecutoff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbnodecutoff", (gpointer *) &__symbolic_XPRSaddcbnodecutoff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbnodecutoff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbnodecutoff.\n");
        }
    }
    return __symbolic_XPRSaddcbnodecutoff(prob, f_nodecutoff, p, priority);
}
int XPRSremovecbnodecutoff (XPRSprob prob, void ( * f_nodecutoff) (XPRSprob prob, void *vContext, int nodnum), void *p){
    if (!__symbolic_XPRSremovecbnodecutoff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbnodecutoff", (gpointer *) &__symbolic_XPRSremovecbnodecutoff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbnodecutoff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbnodecutoff.\n");
        }
    }
    return __symbolic_XPRSremovecbnodecutoff(prob, f_nodecutoff, p);
}
int XPRSsetcbintsol (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbintsol", (gpointer *) &__symbolic_XPRSsetcbintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbintsol.\n");
        }
    }
    return __symbolic_XPRSsetcbintsol(prob, f_intsol, p);
}
int XPRSgetcbintsol (XPRSprob prob, void ( ** f_intsol) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbintsol", (gpointer *) &__symbolic_XPRSgetcbintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbintsol.\n");
        }
    }
    return __symbolic_XPRSgetcbintsol(prob, f_intsol, p);
}
int XPRSaddcbintsol (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbintsol", (gpointer *) &__symbolic_XPRSaddcbintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbintsol.\n");
        }
    }
    return __symbolic_XPRSaddcbintsol(prob, f_intsol, p, priority);
}
int XPRSremovecbintsol (XPRSprob prob, void ( * f_intsol) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbintsol", (gpointer *) &__symbolic_XPRSremovecbintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbintsol.\n");
        }
    }
    return __symbolic_XPRSremovecbintsol(prob, f_intsol, p);
}
int XPRSsetcbpreintsol (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p){
    if (!__symbolic_XPRSsetcbpreintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbpreintsol", (gpointer *) &__symbolic_XPRSsetcbpreintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbpreintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbpreintsol.\n");
        }
    }
    return __symbolic_XPRSsetcbpreintsol(prob, f_preintsol, p);
}
int XPRSgetcbpreintsol (XPRSprob prob, void ( ** f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void **p){
    if (!__symbolic_XPRSgetcbpreintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbpreintsol", (gpointer *) &__symbolic_XPRSgetcbpreintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbpreintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbpreintsol.\n");
        }
    }
    return __symbolic_XPRSgetcbpreintsol(prob, f_preintsol, p);
}
int XPRSaddcbpreintsol (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p, int priority){
    if (!__symbolic_XPRSaddcbpreintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbpreintsol", (gpointer *) &__symbolic_XPRSaddcbpreintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbpreintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbpreintsol.\n");
        }
    }
    return __symbolic_XPRSaddcbpreintsol(prob, f_preintsol, p, priority);
}
int XPRSremovecbpreintsol (XPRSprob prob, void ( * f_preintsol) (XPRSprob prob, void *vContext, int isheuristic, int *ifreject, double *cutoff), void *p){
    if (!__symbolic_XPRSremovecbpreintsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbpreintsol", (gpointer *) &__symbolic_XPRSremovecbpreintsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbpreintsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbpreintsol.\n");
        }
    }
    return __symbolic_XPRSremovecbpreintsol(prob, f_preintsol, p);
}
int XPRSsetcbchgbranch (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p){
    if (!__symbolic_XPRSsetcbchgbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbchgbranch", (gpointer *) &__symbolic_XPRSsetcbchgbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbchgbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbchgbranch.\n");
        }
    }
    return __symbolic_XPRSsetcbchgbranch(prob, f_chgbranch, p);
}
int XPRSgetcbchgbranch (XPRSprob prob, void ( ** f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void **p){
    if (!__symbolic_XPRSgetcbchgbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbchgbranch", (gpointer *) &__symbolic_XPRSgetcbchgbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbchgbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbchgbranch.\n");
        }
    }
    return __symbolic_XPRSgetcbchgbranch(prob, f_chgbranch, p);
}
int XPRSaddcbchgbranch (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p, int priority){
    if (!__symbolic_XPRSaddcbchgbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbchgbranch", (gpointer *) &__symbolic_XPRSaddcbchgbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbchgbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbchgbranch.\n");
        }
    }
    return __symbolic_XPRSaddcbchgbranch(prob, f_chgbranch, p, priority);
}
int XPRSremovecbchgbranch (XPRSprob prob, void ( * f_chgbranch) (XPRSprob prob, void *vContext, int *entity, int *up, double *estdeg), void *p){
    if (!__symbolic_XPRSremovecbchgbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbchgbranch", (gpointer *) &__symbolic_XPRSremovecbchgbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbchgbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbchgbranch.\n");
        }
    }
    return __symbolic_XPRSremovecbchgbranch(prob, f_chgbranch, p);
}
int XPRSsetcbestimate (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p){
    if (!__symbolic_XPRSsetcbestimate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbestimate", (gpointer *) &__symbolic_XPRSsetcbestimate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbestimate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbestimate.\n");
        }
    }
    return __symbolic_XPRSsetcbestimate(prob, f_estimate, p);
}
int XPRSgetcbestimate (XPRSprob prob, int ( ** f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void **p){
    if (!__symbolic_XPRSgetcbestimate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbestimate", (gpointer *) &__symbolic_XPRSgetcbestimate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbestimate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbestimate.\n");
        }
    }
    return __symbolic_XPRSgetcbestimate(prob, f_estimate, p);
}
int XPRSaddcbestimate (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p, int priority){
    if (!__symbolic_XPRSaddcbestimate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbestimate", (gpointer *) &__symbolic_XPRSaddcbestimate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbestimate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbestimate.\n");
        }
    }
    return __symbolic_XPRSaddcbestimate(prob, f_estimate, p, priority);
}
int XPRSremovecbestimate (XPRSprob prob, int ( * f_estimate) (XPRSprob prob, void *vContext, int *iglsel, int *iprio, double *degbest, double *degworst, double *curval, int *ifupx, int *nglinf, double *degsum, int *nbr), void *p){
    if (!__symbolic_XPRSremovecbestimate) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbestimate", (gpointer *) &__symbolic_XPRSremovecbestimate)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbestimate could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbestimate.\n");
        }
    }
    return __symbolic_XPRSremovecbestimate(prob, f_estimate, p);
}
int XPRSsetcbsepnode (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p){
    if (!__symbolic_XPRSsetcbsepnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbsepnode", (gpointer *) &__symbolic_XPRSsetcbsepnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbsepnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbsepnode.\n");
        }
    }
    return __symbolic_XPRSsetcbsepnode(prob, f_sepnode, p);
}
int XPRSgetcbsepnode (XPRSprob prob, int ( ** f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void **p){
    if (!__symbolic_XPRSgetcbsepnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbsepnode", (gpointer *) &__symbolic_XPRSgetcbsepnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbsepnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbsepnode.\n");
        }
    }
    return __symbolic_XPRSgetcbsepnode(prob, f_sepnode, p);
}
int XPRSaddcbsepnode (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p, int priority){
    if (!__symbolic_XPRSaddcbsepnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbsepnode", (gpointer *) &__symbolic_XPRSaddcbsepnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbsepnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbsepnode.\n");
        }
    }
    return __symbolic_XPRSaddcbsepnode(prob, f_sepnode, p, priority);
}
int XPRSremovecbsepnode (XPRSprob prob, int ( * f_sepnode) (XPRSprob prob, void *vContext, int ibr, int iglsel, int ifup, double curval), void *p){
    if (!__symbolic_XPRSremovecbsepnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbsepnode", (gpointer *) &__symbolic_XPRSremovecbsepnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbsepnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbsepnode.\n");
        }
    }
    return __symbolic_XPRSremovecbsepnode(prob, f_sepnode, p);
}
int XPRSsetcbmessage (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p){
    if (!__symbolic_XPRSsetcbmessage) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbmessage", (gpointer *) &__symbolic_XPRSsetcbmessage)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbmessage could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbmessage.\n");
        }
    }
    return __symbolic_XPRSsetcbmessage(prob, f_message, p);
}
int XPRSgetcbmessage (XPRSprob prob, void ( ** f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void **p){
    if (!__symbolic_XPRSgetcbmessage) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbmessage", (gpointer *) &__symbolic_XPRSgetcbmessage)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbmessage could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbmessage.\n");
        }
    }
    return __symbolic_XPRSgetcbmessage(prob, f_message, p);
}
int XPRSaddcbmessage (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p, int priority){
    if (!__symbolic_XPRSaddcbmessage) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbmessage", (gpointer *) &__symbolic_XPRSaddcbmessage)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbmessage could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbmessage.\n");
        }
    }
    return __symbolic_XPRSaddcbmessage(prob, f_message, p, priority);
}
int XPRSremovecbmessage (XPRSprob prob, void ( * f_message) (XPRSprob prob, void *vContext, const char *msg, int len, int msgtype), void *p){
    if (!__symbolic_XPRSremovecbmessage) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbmessage", (gpointer *) &__symbolic_XPRSremovecbmessage)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbmessage could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbmessage.\n");
        }
    }
    return __symbolic_XPRSremovecbmessage(prob, f_message, p);
}
int XPRSsetcbmipthread (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p){
    if (!__symbolic_XPRSsetcbmipthread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbmipthread", (gpointer *) &__symbolic_XPRSsetcbmipthread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbmipthread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbmipthread.\n");
        }
    }
    return __symbolic_XPRSsetcbmipthread(prob, f_mipthread, p);
}
int XPRSgetcbmipthread (XPRSprob prob, void ( ** f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void **p){
    if (!__symbolic_XPRSgetcbmipthread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbmipthread", (gpointer *) &__symbolic_XPRSgetcbmipthread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbmipthread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbmipthread.\n");
        }
    }
    return __symbolic_XPRSgetcbmipthread(prob, f_mipthread, p);
}
int XPRSaddcbmipthread (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p, int priority){
    if (!__symbolic_XPRSaddcbmipthread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbmipthread", (gpointer *) &__symbolic_XPRSaddcbmipthread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbmipthread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbmipthread.\n");
        }
    }
    return __symbolic_XPRSaddcbmipthread(prob, f_mipthread, p, priority);
}
int XPRSremovecbmipthread (XPRSprob prob, void ( * f_mipthread) (XPRSprob master_prob, void *vContext, XPRSprob prob), void *p){
    if (!__symbolic_XPRSremovecbmipthread) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbmipthread", (gpointer *) &__symbolic_XPRSremovecbmipthread)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbmipthread could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbmipthread.\n");
        }
    }
    return __symbolic_XPRSremovecbmipthread(prob, f_mipthread, p);
}
int XPRSsetcbdestroymt (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSsetcbdestroymt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbdestroymt", (gpointer *) &__symbolic_XPRSsetcbdestroymt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbdestroymt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbdestroymt.\n");
        }
    }
    return __symbolic_XPRSsetcbdestroymt(prob, f_destroymt, p);
}
int XPRSgetcbdestroymt (XPRSprob prob, void ( ** f_destroymt) (XPRSprob prob, void *vContext), void **p){
    if (!__symbolic_XPRSgetcbdestroymt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbdestroymt", (gpointer *) &__symbolic_XPRSgetcbdestroymt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbdestroymt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbdestroymt.\n");
        }
    }
    return __symbolic_XPRSgetcbdestroymt(prob, f_destroymt, p);
}
int XPRSaddcbdestroymt (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p, int priority){
    if (!__symbolic_XPRSaddcbdestroymt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbdestroymt", (gpointer *) &__symbolic_XPRSaddcbdestroymt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbdestroymt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbdestroymt.\n");
        }
    }
    return __symbolic_XPRSaddcbdestroymt(prob, f_destroymt, p, priority);
}
int XPRSremovecbdestroymt (XPRSprob prob, void ( * f_destroymt) (XPRSprob prob, void *vContext), void *p){
    if (!__symbolic_XPRSremovecbdestroymt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbdestroymt", (gpointer *) &__symbolic_XPRSremovecbdestroymt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbdestroymt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbdestroymt.\n");
        }
    }
    return __symbolic_XPRSremovecbdestroymt(prob, f_destroymt, p);
}
int XPRSsetcbnewnode (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p){
    if (!__symbolic_XPRSsetcbnewnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbnewnode", (gpointer *) &__symbolic_XPRSsetcbnewnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbnewnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbnewnode.\n");
        }
    }
    return __symbolic_XPRSsetcbnewnode(prob, f_newnode, p);
}
int XPRSgetcbnewnode (XPRSprob prob, void ( ** f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void **p){
    if (!__symbolic_XPRSgetcbnewnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbnewnode", (gpointer *) &__symbolic_XPRSgetcbnewnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbnewnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbnewnode.\n");
        }
    }
    return __symbolic_XPRSgetcbnewnode(prob, f_newnode, p);
}
int XPRSaddcbnewnode (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p, int priority){
    if (!__symbolic_XPRSaddcbnewnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbnewnode", (gpointer *) &__symbolic_XPRSaddcbnewnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbnewnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbnewnode.\n");
        }
    }
    return __symbolic_XPRSaddcbnewnode(prob, f_newnode, p, priority);
}
int XPRSremovecbnewnode (XPRSprob prob, void ( * f_newnode) (XPRSprob prob, void *vContext, int parentnode, int newnode, int branch), void *p){
    if (!__symbolic_XPRSremovecbnewnode) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbnewnode", (gpointer *) &__symbolic_XPRSremovecbnewnode)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbnewnode could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbnewnode.\n");
        }
    }
    return __symbolic_XPRSremovecbnewnode(prob, f_newnode, p);
}
int XPRSsetcbbariteration (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p){
    if (!__symbolic_XPRSsetcbbariteration) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbbariteration", (gpointer *) &__symbolic_XPRSsetcbbariteration)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbbariteration could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbbariteration.\n");
        }
    }
    return __symbolic_XPRSsetcbbariteration(prob, f_bariteration, p);
}
int XPRSgetcbbariteration (XPRSprob prob, void ( ** f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void **p){
    if (!__symbolic_XPRSgetcbbariteration) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbbariteration", (gpointer *) &__symbolic_XPRSgetcbbariteration)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbbariteration could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbbariteration.\n");
        }
    }
    return __symbolic_XPRSgetcbbariteration(prob, f_bariteration, p);
}
int XPRSaddcbbariteration (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p, int priority){
    if (!__symbolic_XPRSaddcbbariteration) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbbariteration", (gpointer *) &__symbolic_XPRSaddcbbariteration)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbbariteration could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbbariteration.\n");
        }
    }
    return __symbolic_XPRSaddcbbariteration(prob, f_bariteration, p, priority);
}
int XPRSremovecbbariteration (XPRSprob prob, void ( * f_bariteration) (XPRSprob prob, void *vContext, int *barrier_action), void *p){
    if (!__symbolic_XPRSremovecbbariteration) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbbariteration", (gpointer *) &__symbolic_XPRSremovecbbariteration)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbbariteration could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbbariteration.\n");
        }
    }
    return __symbolic_XPRSremovecbbariteration(prob, f_bariteration, p);
}
int XPRSsetcbchgbranchobject (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p){
    if (!__symbolic_XPRSsetcbchgbranchobject) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbchgbranchobject", (gpointer *) &__symbolic_XPRSsetcbchgbranchobject)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbchgbranchobject could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbchgbranchobject.\n");
        }
    }
    return __symbolic_XPRSsetcbchgbranchobject(prob, f_chgbranchobject, p);
}
int XPRSgetcbchgbranchobject (XPRSprob prob, void ( ** f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void **p){
    if (!__symbolic_XPRSgetcbchgbranchobject) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbchgbranchobject", (gpointer *) &__symbolic_XPRSgetcbchgbranchobject)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbchgbranchobject could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbchgbranchobject.\n");
        }
    }
    return __symbolic_XPRSgetcbchgbranchobject(prob, f_chgbranchobject, p);
}
int XPRSaddcbchgbranchobject (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p, int priority){
    if (!__symbolic_XPRSaddcbchgbranchobject) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbchgbranchobject", (gpointer *) &__symbolic_XPRSaddcbchgbranchobject)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbchgbranchobject could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbchgbranchobject.\n");
        }
    }
    return __symbolic_XPRSaddcbchgbranchobject(prob, f_chgbranchobject, p, priority);
}
int XPRSremovecbchgbranchobject (XPRSprob prob, void ( * f_chgbranchobject) (XPRSprob prob, void *vContext, XPRSbranchobject obranch, XPRSbranchobject * p_newobject), void *p){
    if (!__symbolic_XPRSremovecbchgbranchobject) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbchgbranchobject", (gpointer *) &__symbolic_XPRSremovecbchgbranchobject)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbchgbranchobject could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbchgbranchobject.\n");
        }
    }
    return __symbolic_XPRSremovecbchgbranchobject(prob, f_chgbranchobject, p);
}
int XPRSsetcbgapnotify (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p){
    if (!__symbolic_XPRSsetcbgapnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbgapnotify", (gpointer *) &__symbolic_XPRSsetcbgapnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbgapnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbgapnotify.\n");
        }
    }
    return __symbolic_XPRSsetcbgapnotify(prob, f_gapnotify, p);
}
int XPRSgetcbgapnotify (XPRSprob prob, void ( ** f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void **p){
    if (!__symbolic_XPRSgetcbgapnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbgapnotify", (gpointer *) &__symbolic_XPRSgetcbgapnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbgapnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbgapnotify.\n");
        }
    }
    return __symbolic_XPRSgetcbgapnotify(prob, f_gapnotify, p);
}
int XPRSaddcbgapnotify (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p, int priority){
    if (!__symbolic_XPRSaddcbgapnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbgapnotify", (gpointer *) &__symbolic_XPRSaddcbgapnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbgapnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbgapnotify.\n");
        }
    }
    return __symbolic_XPRSaddcbgapnotify(prob, f_gapnotify, p, priority);
}
int XPRSremovecbgapnotify (XPRSprob prob, void ( * f_gapnotify) (XPRSprob prob, void *vContext, double *newRelGapNotifyTarget, double *newAbsGapNotifyTarget, double *newAbsGapNotifyObjTarget, double *newAbsGapNotifyBoundTarget), void *p){
    if (!__symbolic_XPRSremovecbgapnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbgapnotify", (gpointer *) &__symbolic_XPRSremovecbgapnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbgapnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbgapnotify.\n");
        }
    }
    return __symbolic_XPRSremovecbgapnotify(prob, f_gapnotify, p);
}
int XPRSsetcbusersolnotify (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p){
    if (!__symbolic_XPRSsetcbusersolnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSsetcbusersolnotify", (gpointer *) &__symbolic_XPRSsetcbusersolnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSsetcbusersolnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSsetcbusersolnotify.\n");
        }
    }
    return __symbolic_XPRSsetcbusersolnotify(prob, f_usersolnotify, p);
}
int XPRSgetcbusersolnotify (XPRSprob prob, void ( ** f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void **p){
    if (!__symbolic_XPRSgetcbusersolnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetcbusersolnotify", (gpointer *) &__symbolic_XPRSgetcbusersolnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetcbusersolnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetcbusersolnotify.\n");
        }
    }
    return __symbolic_XPRSgetcbusersolnotify(prob, f_usersolnotify, p);
}
int XPRSaddcbusersolnotify (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p, int priority){
    if (!__symbolic_XPRSaddcbusersolnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddcbusersolnotify", (gpointer *) &__symbolic_XPRSaddcbusersolnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddcbusersolnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddcbusersolnotify.\n");
        }
    }
    return __symbolic_XPRSaddcbusersolnotify(prob, f_usersolnotify, p, priority);
}
int XPRSremovecbusersolnotify (XPRSprob prob, void ( * f_usersolnotify) (XPRSprob prob, void *vContext, int id, int status), void *p){
    if (!__symbolic_XPRSremovecbusersolnotify) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSremovecbusersolnotify", (gpointer *) &__symbolic_XPRSremovecbusersolnotify)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSremovecbusersolnotify could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSremovecbusersolnotify.\n");
        }
    }
    return __symbolic_XPRSremovecbusersolnotify(prob, f_usersolnotify, p);
}
int XPRSobjsa (XPRSprob prob, int ncols, const int mindex[], double lower[], double upper[]){
    if (!__symbolic_XPRSobjsa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSobjsa", (gpointer *) &__symbolic_XPRSobjsa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSobjsa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSobjsa.\n");
        }
    }
    return __symbolic_XPRSobjsa(prob, ncols, mindex, lower, upper);
}
int XPRSrhssa (XPRSprob prob, int nrows, const int mindex[], double lower[], double upper[]){
    if (!__symbolic_XPRSrhssa) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSrhssa", (gpointer *) &__symbolic_XPRSrhssa)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSrhssa could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSrhssa.\n");
        }
    }
    return __symbolic_XPRSrhssa(prob, nrows, mindex, lower, upper);
}
int XPRS_ge_setcbmsghandler (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_ge_setcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_ge_setcbmsghandler", (gpointer *) &__symbolic_XPRS_ge_setcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_ge_setcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_ge_setcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_ge_setcbmsghandler(f_msghandler, p);
}
int XPRS_ge_getcbmsghandler (int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p){
    if (!__symbolic_XPRS_ge_getcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_ge_getcbmsghandler", (gpointer *) &__symbolic_XPRS_ge_getcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_ge_getcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_ge_getcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_ge_getcbmsghandler(f_msghandler, p);
}
int XPRS_ge_addcbmsghandler (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority){
    if (!__symbolic_XPRS_ge_addcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_ge_addcbmsghandler", (gpointer *) &__symbolic_XPRS_ge_addcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_ge_addcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_ge_addcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_ge_addcbmsghandler(f_msghandler, p, priority);
}
int XPRS_ge_removecbmsghandler (int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_ge_removecbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_ge_removecbmsghandler", (gpointer *) &__symbolic_XPRS_ge_removecbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_ge_removecbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_ge_removecbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_ge_removecbmsghandler(f_msghandler, p);
}
int XPRS_ge_getlasterror (int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_ge_getlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_ge_getlasterror", (gpointer *) &__symbolic_XPRS_ge_getlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_ge_getlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_ge_getlasterror.\n");
        }
    }
    return __symbolic_XPRS_ge_getlasterror(iMsgCode, _msg, _iStringBufferBytes, _iBytesInInternalString);
}
int XPRS_msp_create (XPRSmipsolpool * msp){
    if (!__symbolic_XPRS_msp_create) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_create", (gpointer *) &__symbolic_XPRS_msp_create)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_create could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_create.\n");
        }
    }
    return __symbolic_XPRS_msp_create(msp);
}
int XPRS_msp_destroy (XPRSmipsolpool msp){
    if (!__symbolic_XPRS_msp_destroy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_destroy", (gpointer *) &__symbolic_XPRS_msp_destroy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_destroy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_destroy.\n");
        }
    }
    return __symbolic_XPRS_msp_destroy(msp);
}
int XPRS_msp_probattach (XPRSmipsolpool msp, XPRSprob prob){
    if (!__symbolic_XPRS_msp_probattach) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_probattach", (gpointer *) &__symbolic_XPRS_msp_probattach)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_probattach could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_probattach.\n");
        }
    }
    return __symbolic_XPRS_msp_probattach(msp, prob);
}
int XPRS_msp_probdetach (XPRSmipsolpool msp, XPRSprob prob){
    if (!__symbolic_XPRS_msp_probdetach) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_probdetach", (gpointer *) &__symbolic_XPRS_msp_probdetach)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_probdetach could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_probdetach.\n");
        }
    }
    return __symbolic_XPRS_msp_probdetach(msp, prob);
}
int XPRS_msp_getsollist (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iRankAttrib, int bRankAscending, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int iSolutionIds_Zb[], int *nReturnedSolIds, int *nSols){
    if (!__symbolic_XPRS_msp_getsollist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getsollist", (gpointer *) &__symbolic_XPRS_msp_getsollist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getsollist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getsollist.\n");
        }
    }
    return __symbolic_XPRS_msp_getsollist(msp, prob_to_rank_against, iRankAttrib, bRankAscending, iRankFirstIndex_Ob, iRankLastIndex_Ob, iSolutionIds_Zb, nReturnedSolIds, nSols);
}
int XPRS_msp_getsollist2 (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iRankAttrib, int bRankAscending, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int bUseUserBitFilter, int iUserBitMask, int iUserBitPattern, int bUseInternalBitFilter, int iInternalBitMask, int iInternalBitPattern, int iSolutionIds_Zb[], int *nReturnedSolIds, int *nSols){
    if (!__symbolic_XPRS_msp_getsollist2) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getsollist2", (gpointer *) &__symbolic_XPRS_msp_getsollist2)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getsollist2 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getsollist2.\n");
        }
    }
    return __symbolic_XPRS_msp_getsollist2(msp, prob_to_rank_against, iRankAttrib, bRankAscending, iRankFirstIndex_Ob, iRankLastIndex_Ob, bUseUserBitFilter, iUserBitMask, iUserBitPattern, bUseInternalBitFilter, iInternalBitMask, iInternalBitPattern, iSolutionIds_Zb, nReturnedSolIds, nSols);
}
int XPRS_msp_getsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, double x[], int iColFirst, int iColLast, int *nValuesReturned){
    if (!__symbolic_XPRS_msp_getsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getsol", (gpointer *) &__symbolic_XPRS_msp_getsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getsol(msp, iSolutionId, iSolutionIdStatus_, x, iColFirst, iColLast, nValuesReturned);
}
int XPRS_msp_getslack (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, double slack[], int iRowFirst, int iRowLast, int *nValuesReturned){
    if (!__symbolic_XPRS_msp_getslack) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getslack", (gpointer *) &__symbolic_XPRS_msp_getslack)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getslack could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getslack.\n");
        }
    }
    return __symbolic_XPRS_msp_getslack(msp, prob_to_rank_against, iSolutionId, iSolutionIdStatus_, slack, iRowFirst, iRowLast, nValuesReturned);
}
int XPRS_msp_loadsol (XPRSmipsolpool msp, int *iSolutionId, const double x[], int nCols, const char *sSolutionName, int *bNameModifiedForUniqueness, int *iSolutionIdOfExistingDuplicatePreventedLoad){
    if (!__symbolic_XPRS_msp_loadsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_loadsol", (gpointer *) &__symbolic_XPRS_msp_loadsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_loadsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_loadsol.\n");
        }
    }
    return __symbolic_XPRS_msp_loadsol(msp, iSolutionId, x, nCols, sSolutionName, bNameModifiedForUniqueness, iSolutionIdOfExistingDuplicatePreventedLoad);
}
int XPRS_msp_delsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_){
    if (!__symbolic_XPRS_msp_delsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_delsol", (gpointer *) &__symbolic_XPRS_msp_delsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_delsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_delsol.\n");
        }
    }
    return __symbolic_XPRS_msp_delsol(msp, iSolutionId, iSolutionIdStatus_);
}
int XPRS_msp_getintattribprobsol (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, int *Dst){
    if (!__symbolic_XPRS_msp_getintattribprobsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintattribprobsol", (gpointer *) &__symbolic_XPRS_msp_getintattribprobsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintattribprobsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintattribprobsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getintattribprobsol(msp, prob_to_rank_against, iSolutionId, iSolutionIdStatus_, iAttribId, Dst);
}
int XPRS_msp_getdblattribprobsol (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, double *Dst){
    if (!__symbolic_XPRS_msp_getdblattribprobsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblattribprobsol", (gpointer *) &__symbolic_XPRS_msp_getdblattribprobsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblattribprobsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblattribprobsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblattribprobsol(msp, prob_to_rank_against, iSolutionId, iSolutionIdStatus_, iAttribId, Dst);
}
int XPRS_msp_getintattribprob (XPRSmipsolpool msp, XPRSprob prob, int iAttribId, int *Dst){
    if (!__symbolic_XPRS_msp_getintattribprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintattribprob", (gpointer *) &__symbolic_XPRS_msp_getintattribprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintattribprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintattribprob.\n");
        }
    }
    return __symbolic_XPRS_msp_getintattribprob(msp, prob, iAttribId, Dst);
}
int XPRS_msp_getdblattribprob (XPRSmipsolpool msp, XPRSprob prob, int iAttribId, double *Dst){
    if (!__symbolic_XPRS_msp_getdblattribprob) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblattribprob", (gpointer *) &__symbolic_XPRS_msp_getdblattribprob)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblattribprob could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblattribprob.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblattribprob(msp, prob, iAttribId, Dst);
}
int XPRS_msp_getintattribsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, int *Dst){
    if (!__symbolic_XPRS_msp_getintattribsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintattribsol", (gpointer *) &__symbolic_XPRS_msp_getintattribsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintattribsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintattribsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getintattribsol(msp, iSolutionId, iSolutionIdStatus_, iAttribId, Dst);
}
int XPRS_msp_getdblattribsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iAttribId, double *Dst){
    if (!__symbolic_XPRS_msp_getdblattribsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblattribsol", (gpointer *) &__symbolic_XPRS_msp_getdblattribsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblattribsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblattribsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblattribsol(msp, iSolutionId, iSolutionIdStatus_, iAttribId, Dst);
}
int XPRS_msp_getintcontrolsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, int *Val){
    if (!__symbolic_XPRS_msp_getintcontrolsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintcontrolsol", (gpointer *) &__symbolic_XPRS_msp_getintcontrolsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintcontrolsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintcontrolsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getintcontrolsol(msp, iSolutionId, iSolutionIdStatus_, iControlId, Val);
}
int XPRS_msp_getdblcontrolsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, double *Val){
    if (!__symbolic_XPRS_msp_getdblcontrolsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblcontrolsol", (gpointer *) &__symbolic_XPRS_msp_getdblcontrolsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblcontrolsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblcontrolsol.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblcontrolsol(msp, iSolutionId, iSolutionIdStatus_, iControlId, Val);
}
int XPRS_msp_setintcontrolsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, int Val){
    if (!__symbolic_XPRS_msp_setintcontrolsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setintcontrolsol", (gpointer *) &__symbolic_XPRS_msp_setintcontrolsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setintcontrolsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setintcontrolsol.\n");
        }
    }
    return __symbolic_XPRS_msp_setintcontrolsol(msp, iSolutionId, iSolutionIdStatus_, iControlId, Val);
}
int XPRS_msp_setdblcontrolsol (XPRSmipsolpool msp, int iSolutionId, int *iSolutionIdStatus_, int iControlId, double Val){
    if (!__symbolic_XPRS_msp_setdblcontrolsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setdblcontrolsol", (gpointer *) &__symbolic_XPRS_msp_setdblcontrolsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setdblcontrolsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setdblcontrolsol.\n");
        }
    }
    return __symbolic_XPRS_msp_setdblcontrolsol(msp, iSolutionId, iSolutionIdStatus_, iControlId, Val);
}
int XPRS_msp_getintattribprobextreme (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int bGet_Max_Otherwise_Min, int *iSolutionId, int iAttribId, int *ExtremeVal){
    if (!__symbolic_XPRS_msp_getintattribprobextreme) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintattribprobextreme", (gpointer *) &__symbolic_XPRS_msp_getintattribprobextreme)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintattribprobextreme could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintattribprobextreme.\n");
        }
    }
    return __symbolic_XPRS_msp_getintattribprobextreme(msp, prob_to_rank_against, bGet_Max_Otherwise_Min, iSolutionId, iAttribId, ExtremeVal);
}
int XPRS_msp_getdblattribprobextreme (XPRSmipsolpool msp, XPRSprob prob_to_rank_against, int bGet_Max_Otherwise_Min, int *iSolutionId, int iAttribId, double *ExtremeVal){
    if (!__symbolic_XPRS_msp_getdblattribprobextreme) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblattribprobextreme", (gpointer *) &__symbolic_XPRS_msp_getdblattribprobextreme)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblattribprobextreme could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblattribprobextreme.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblattribprobextreme(msp, prob_to_rank_against, bGet_Max_Otherwise_Min, iSolutionId, iAttribId, ExtremeVal);
}
int XPRS_msp_getintattrib (XPRSmipsolpool msp, int iAttribId, int *Val){
    if (!__symbolic_XPRS_msp_getintattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintattrib", (gpointer *) &__symbolic_XPRS_msp_getintattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintattrib.\n");
        }
    }
    return __symbolic_XPRS_msp_getintattrib(msp, iAttribId, Val);
}
int XPRS_msp_getdblattrib (XPRSmipsolpool msp, int iAttribId, double *Val){
    if (!__symbolic_XPRS_msp_getdblattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblattrib", (gpointer *) &__symbolic_XPRS_msp_getdblattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblattrib.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblattrib(msp, iAttribId, Val);
}
int XPRS_msp_getintcontrol (XPRSmipsolpool msp, int iControlId, int *Val){
    if (!__symbolic_XPRS_msp_getintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getintcontrol", (gpointer *) &__symbolic_XPRS_msp_getintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getintcontrol.\n");
        }
    }
    return __symbolic_XPRS_msp_getintcontrol(msp, iControlId, Val);
}
int XPRS_msp_getdblcontrol (XPRSmipsolpool msp, int iControlId, double *Val){
    if (!__symbolic_XPRS_msp_getdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getdblcontrol", (gpointer *) &__symbolic_XPRS_msp_getdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getdblcontrol.\n");
        }
    }
    return __symbolic_XPRS_msp_getdblcontrol(msp, iControlId, Val);
}
int XPRS_msp_setintcontrol (XPRSmipsolpool msp, int iControlId, int Val){
    if (!__symbolic_XPRS_msp_setintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setintcontrol", (gpointer *) &__symbolic_XPRS_msp_setintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setintcontrol.\n");
        }
    }
    return __symbolic_XPRS_msp_setintcontrol(msp, iControlId, Val);
}
int XPRS_msp_setdblcontrol (XPRSmipsolpool msp, int iControlId, double Val){
    if (!__symbolic_XPRS_msp_setdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setdblcontrol", (gpointer *) &__symbolic_XPRS_msp_setdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setdblcontrol.\n");
        }
    }
    return __symbolic_XPRS_msp_setdblcontrol(msp, iControlId, Val);
}
int XPRS_msp_setsolname (XPRSmipsolpool msp, int iSolutionId, const char *sNewSolutionBaseName, int *bNameModifiedForUniqueness, int *iSolutionIdStatus_){
    if (!__symbolic_XPRS_msp_setsolname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setsolname", (gpointer *) &__symbolic_XPRS_msp_setsolname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setsolname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setsolname.\n");
        }
    }
    return __symbolic_XPRS_msp_setsolname(msp, iSolutionId, sNewSolutionBaseName, bNameModifiedForUniqueness, iSolutionIdStatus_);
}
int XPRS_msp_getsolname (XPRSmipsolpool msp, int iSolutionId, char *_sname, int _iStringBufferBytes, int *_iBytesInInternalString, int *iSolutionIdStatus_){
    if (!__symbolic_XPRS_msp_getsolname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getsolname", (gpointer *) &__symbolic_XPRS_msp_getsolname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getsolname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getsolname.\n");
        }
    }
    return __symbolic_XPRS_msp_getsolname(msp, iSolutionId, _sname, _iStringBufferBytes, _iBytesInInternalString, iSolutionIdStatus_);
}
int XPRS_msp_findsolbyname (XPRSmipsolpool msp, const char *sSolutionName, int *iSolutionId){
    if (!__symbolic_XPRS_msp_findsolbyname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_findsolbyname", (gpointer *) &__symbolic_XPRS_msp_findsolbyname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_findsolbyname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_findsolbyname.\n");
        }
    }
    return __symbolic_XPRS_msp_findsolbyname(msp, sSolutionName, iSolutionId);
}
int XPRS_msp_writeslxsol (XPRSmipsolpool msp, XPRSprob prob_context, int iSolutionId, int *iSolutionIdStatus_, const char *sFileName, const char *sFlags){
    if (!__symbolic_XPRS_msp_writeslxsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_writeslxsol", (gpointer *) &__symbolic_XPRS_msp_writeslxsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_writeslxsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_writeslxsol.\n");
        }
    }
    return __symbolic_XPRS_msp_writeslxsol(msp, prob_context, iSolutionId, iSolutionIdStatus_, sFileName, sFlags);
}
int XPRS_msp_readslxsol (XPRSmipsolpool msp, XPRSnamelist col_name_list, const char *sFileName, const char *sFlags, int *iSolutionId_Beg, int *iSolutionId_End){
    if (!__symbolic_XPRS_msp_readslxsol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_readslxsol", (gpointer *) &__symbolic_XPRS_msp_readslxsol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_readslxsol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_readslxsol.\n");
        }
    }
    return __symbolic_XPRS_msp_readslxsol(msp, col_name_list, sFileName, sFlags, iSolutionId_Beg, iSolutionId_End);
}
int XPRS_msp_getlasterror (XPRSmipsolpool msp, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_msp_getlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getlasterror", (gpointer *) &__symbolic_XPRS_msp_getlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getlasterror.\n");
        }
    }
    return __symbolic_XPRS_msp_getlasterror(msp, iMsgCode, _msg, _iStringBufferBytes, _iBytesInInternalString);
}
int XPRS_msp_setcbmsghandler (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_msp_setcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_setcbmsghandler", (gpointer *) &__symbolic_XPRS_msp_setcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_setcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_setcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_msp_setcbmsghandler(msp, f_msghandler, p);
}
int XPRS_msp_getcbmsghandler (XPRSmipsolpool msp, int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p){
    if (!__symbolic_XPRS_msp_getcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_getcbmsghandler", (gpointer *) &__symbolic_XPRS_msp_getcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_getcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_getcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_msp_getcbmsghandler(msp, f_msghandler, p);
}
int XPRS_msp_addcbmsghandler (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority){
    if (!__symbolic_XPRS_msp_addcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_addcbmsghandler", (gpointer *) &__symbolic_XPRS_msp_addcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_addcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_addcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_msp_addcbmsghandler(msp, f_msghandler, p, priority);
}
int XPRS_msp_removecbmsghandler (XPRSmipsolpool msp, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_msp_removecbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_msp_removecbmsghandler", (gpointer *) &__symbolic_XPRS_msp_removecbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_msp_removecbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_msp_removecbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_msp_removecbmsghandler(msp, f_msghandler, p);
}
int XPRS_nml_create (XPRSnamelist * r_nl){
    if (!__symbolic_XPRS_nml_create) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_create", (gpointer *) &__symbolic_XPRS_nml_create)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_create could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_create.\n");
        }
    }
    return __symbolic_XPRS_nml_create(r_nl);
}
int XPRS_nml_destroy (XPRSnamelist nml){
    if (!__symbolic_XPRS_nml_destroy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_destroy", (gpointer *) &__symbolic_XPRS_nml_destroy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_destroy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_destroy.\n");
        }
    }
    return __symbolic_XPRS_nml_destroy(nml);
}
int XPRS_nml_getnamecount (XPRSnamelist nml, int *count){
    if (!__symbolic_XPRS_nml_getnamecount) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_getnamecount", (gpointer *) &__symbolic_XPRS_nml_getnamecount)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_getnamecount could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_getnamecount.\n");
        }
    }
    return __symbolic_XPRS_nml_getnamecount(nml, count);
}
int XPRS_nml_getmaxnamelen (XPRSnamelist nml, int *namlen){
    if (!__symbolic_XPRS_nml_getmaxnamelen) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_getmaxnamelen", (gpointer *) &__symbolic_XPRS_nml_getmaxnamelen)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_getmaxnamelen could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_getmaxnamelen.\n");
        }
    }
    return __symbolic_XPRS_nml_getmaxnamelen(nml, namlen);
}
int XPRS_nml_getnames (XPRSnamelist nml, int padlen, char buf[], int buflen, int *r_buflen_reqd, int firstIndex, int lastIndex){
    if (!__symbolic_XPRS_nml_getnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_getnames", (gpointer *) &__symbolic_XPRS_nml_getnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_getnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_getnames.\n");
        }
    }
    return __symbolic_XPRS_nml_getnames(nml, padlen, buf, buflen, r_buflen_reqd, firstIndex, lastIndex);
}
int XPRS_nml_addnames (XPRSnamelist nml, const char buf[], int firstIndex, int lastIndex){
    if (!__symbolic_XPRS_nml_addnames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_addnames", (gpointer *) &__symbolic_XPRS_nml_addnames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_addnames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_addnames.\n");
        }
    }
    return __symbolic_XPRS_nml_addnames(nml, buf, firstIndex, lastIndex);
}
int XPRS_nml_removenames (XPRSnamelist nml, int firstIndex, int lastIndex){
    if (!__symbolic_XPRS_nml_removenames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_removenames", (gpointer *) &__symbolic_XPRS_nml_removenames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_removenames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_removenames.\n");
        }
    }
    return __symbolic_XPRS_nml_removenames(nml, firstIndex, lastIndex);
}
int XPRS_nml_findname (XPRSnamelist nml, const char *name, int *r_index){
    if (!__symbolic_XPRS_nml_findname) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_findname", (gpointer *) &__symbolic_XPRS_nml_findname)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_findname could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_findname.\n");
        }
    }
    return __symbolic_XPRS_nml_findname(nml, name, r_index);
}
int XPRS_nml_copynames (XPRSnamelist dst, XPRSnamelist src){
    if (!__symbolic_XPRS_nml_copynames) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_copynames", (gpointer *) &__symbolic_XPRS_nml_copynames)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_copynames could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_copynames.\n");
        }
    }
    return __symbolic_XPRS_nml_copynames(dst, src);
}
int XPRS_nml_getlasterror (XPRSnamelist nml, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_nml_getlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_nml_getlasterror", (gpointer *) &__symbolic_XPRS_nml_getlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_nml_getlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_nml_getlasterror.\n");
        }
    }
    return __symbolic_XPRS_nml_getlasterror(nml, iMsgCode, _msg, _iStringBufferBytes, _iBytesInInternalString);
}
int XPRSgetqrowcoeff (XPRSprob prob, int irow, int icol, int jcol, double *dval){
    if (!__symbolic_XPRSgetqrowcoeff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetqrowcoeff", (gpointer *) &__symbolic_XPRSgetqrowcoeff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetqrowcoeff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetqrowcoeff.\n");
        }
    }
    return __symbolic_XPRSgetqrowcoeff(prob, irow, icol, jcol, dval);
}
int XPRSgetqrowqmatrix (XPRSprob prob, int irow, int mstart[], int mclind[], double dobjval[], int maxcoeffs, int *ncoeffs, int first, int last){
    if (!__symbolic_XPRSgetqrowqmatrix) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetqrowqmatrix", (gpointer *) &__symbolic_XPRSgetqrowqmatrix)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetqrowqmatrix could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetqrowqmatrix.\n");
        }
    }
    return __symbolic_XPRSgetqrowqmatrix(prob, irow, mstart, mclind, dobjval, maxcoeffs, ncoeffs, first, last);
}
int XPRSgetqrowqmatrixtriplets (XPRSprob prob, int irow, int *nqelem, int mqcol1[], int mqcol2[], double dqe[]){
    if (!__symbolic_XPRSgetqrowqmatrixtriplets) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetqrowqmatrixtriplets", (gpointer *) &__symbolic_XPRSgetqrowqmatrixtriplets)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetqrowqmatrixtriplets could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetqrowqmatrixtriplets.\n");
        }
    }
    return __symbolic_XPRSgetqrowqmatrixtriplets(prob, irow, nqelem, mqcol1, mqcol2, dqe);
}
int XPRSchgqrowcoeff (XPRSprob prob, int irow, int icol, int jcol, double dval){
    if (!__symbolic_XPRSchgqrowcoeff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSchgqrowcoeff", (gpointer *) &__symbolic_XPRSchgqrowcoeff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSchgqrowcoeff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSchgqrowcoeff.\n");
        }
    }
    return __symbolic_XPRSchgqrowcoeff(prob, irow, icol, jcol, dval);
}
int XPRSgetqrows (XPRSprob prob, int *qmn, int qcrows[]){
    if (!__symbolic_XPRSgetqrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSgetqrows", (gpointer *) &__symbolic_XPRSgetqrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSgetqrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSgetqrows.\n");
        }
    }
    return __symbolic_XPRSgetqrows(prob, qmn, qcrows);
}
int XPRSaddqmatrix (XPRSprob prob, int irow, int nqtr, const int mqc1[], const int mqc2[], const double dqew[]){
    if (!__symbolic_XPRSaddqmatrix) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddqmatrix", (gpointer *) &__symbolic_XPRSaddqmatrix)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddqmatrix could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddqmatrix.\n");
        }
    }
    return __symbolic_XPRSaddqmatrix(prob, irow, nqtr, mqc1, mqc2, dqew);
}
int XPRSaddqmatrix64 (XPRSprob prob, int irow, long nqtr, const int mqc1[], const int mqc2[], const double dqew[]){
    if (!__symbolic_XPRSaddqmatrix64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSaddqmatrix64", (gpointer *) &__symbolic_XPRSaddqmatrix64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSaddqmatrix64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSaddqmatrix64.\n");
        }
    }
    return __symbolic_XPRSaddqmatrix64(prob, irow, nqtr, mqc1, mqc2, dqew);
}
int XPRSdelqmatrix (XPRSprob prob, int irow){
    if (!__symbolic_XPRSdelqmatrix) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSdelqmatrix", (gpointer *) &__symbolic_XPRSdelqmatrix)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSdelqmatrix could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSdelqmatrix.\n");
        }
    }
    return __symbolic_XPRSdelqmatrix(prob, irow);
}
int XPRSloadqcqp (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const int qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[]){
    if (!__symbolic_XPRSloadqcqp) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqcqp", (gpointer *) &__symbolic_XPRSloadqcqp)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqcqp could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqcqp.\n");
        }
    }
    return __symbolic_XPRSloadqcqp(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval, qmn, qcrows, qcnquads, qcmqcol1, qcmqcol2, qcdqval);
}
int XPRSloadqcqp64 (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _mstart[], const int _mnel[], const int _mrwind[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const long qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[]){
    if (!__symbolic_XPRSloadqcqp64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqcqp64", (gpointer *) &__symbolic_XPRSloadqcqp64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqcqp64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqcqp64.\n");
        }
    }
    return __symbolic_XPRSloadqcqp64(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _mstart, _mnel, _mrwind, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval, qmn, qcrows, qcnquads, qcmqcol1, qcmqcol2, qcdqval);
}
int XPRSloadqcqpglobal (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const int _matbeg[], const int _matcnt[], const int _matrow[], const double _dmatval[], const double _dlb[], const double _dub[], int nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const int qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const int msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSloadqcqpglobal) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqcqpglobal", (gpointer *) &__symbolic_XPRSloadqcqpglobal)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqcqpglobal could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqcqpglobal.\n");
        }
    }
    return __symbolic_XPRSloadqcqpglobal(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _matbeg, _matcnt, _matrow, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval, qmn, qcrows, qcnquads, qcmqcol1, qcmqcol2, qcdqval, ngents, nsets, qgtype, mgcols, dlim, qstype, msstart, mscols, dref);
}
int XPRSloadqcqpglobal64 (XPRSprob prob, const char *_sprobname, int ncols, int nrows, const char _srowtypes[], const double _drhs[], const double _drange[], const double _dobj[], const long _matbeg[], const int _matcnt[], const int _matrow[], const double _dmatval[], const double _dlb[], const double _dub[], long nquads, const int _mqcol1[], const int _mqcol2[], const double _dqval[], int qmn, const int qcrows[], const long qcnquads[], const int qcmqcol1[], const int qcmqcol2[], const double qcdqval[], const int ngents, const int nsets, const char qgtype[], const int mgcols[], const double dlim[], const char qstype[], const long msstart[], const int mscols[], const double dref[]){
    if (!__symbolic_XPRSloadqcqpglobal64) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRSloadqcqpglobal64", (gpointer *) &__symbolic_XPRSloadqcqpglobal64)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRSloadqcqpglobal64 could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRSloadqcqpglobal64.\n");
        }
    }
    return __symbolic_XPRSloadqcqpglobal64(prob, _sprobname, ncols, nrows, _srowtypes, _drhs, _drange, _dobj, _matbeg, _matcnt, _matrow, _dmatval, _dlb, _dub, nquads, _mqcol1, _mqcol2, _dqval, qmn, qcrows, qcnquads, qcmqcol1, qcmqcol2, qcdqval, ngents, nsets, qgtype, mgcols, dlim, qstype, msstart, mscols, dref);
}
int XPRS_mse_create (XPRSmipsolenum * mse){
    if (!__symbolic_XPRS_mse_create) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_create", (gpointer *) &__symbolic_XPRS_mse_create)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_create could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_create.\n");
        }
    }
    return __symbolic_XPRS_mse_create(mse);
}
int XPRS_mse_destroy (XPRSmipsolenum mse){
    if (!__symbolic_XPRS_mse_destroy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_destroy", (gpointer *) &__symbolic_XPRS_mse_destroy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_destroy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_destroy.\n");
        }
    }
    return __symbolic_XPRS_mse_destroy(mse);
}
int XPRS_mse_getsollist (XPRSmipsolenum mse, int iMetricId, int iRankFirstIndex_Ob, int iRankLastIndex_Ob, int iSolutionIds[], int *nReturnedSolIds, int *nSols){
    if (!__symbolic_XPRS_mse_getsollist) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getsollist", (gpointer *) &__symbolic_XPRS_mse_getsollist)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getsollist could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getsollist.\n");
        }
    }
    return __symbolic_XPRS_mse_getsollist(mse, iMetricId, iRankFirstIndex_Ob, iRankLastIndex_Ob, iSolutionIds, nReturnedSolIds, nSols);
}
int XPRS_mse_getsolmetric (XPRSmipsolenum mse, int iSolutionId, int *iSolutionIdStatus, int iMetricId, double *dMetric){
    if (!__symbolic_XPRS_mse_getsolmetric) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getsolmetric", (gpointer *) &__symbolic_XPRS_mse_getsolmetric)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getsolmetric could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getsolmetric.\n");
        }
    }
    return __symbolic_XPRS_mse_getsolmetric(mse, iSolutionId, iSolutionIdStatus, iMetricId, dMetric);
}
int XPRS_mse_getcullchoice (XPRSmipsolenum mse, int iMetricId, int cull_sol_id_list[], int nMaxSolsToCull, int *nSolsToCull, double dNewSolMetric, const double x[], int nCols, int *bRejectSoln){
    if (!__symbolic_XPRS_mse_getcullchoice) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getcullchoice", (gpointer *) &__symbolic_XPRS_mse_getcullchoice)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getcullchoice could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getcullchoice.\n");
        }
    }
    return __symbolic_XPRS_mse_getcullchoice(mse, iMetricId, cull_sol_id_list, nMaxSolsToCull, nSolsToCull, dNewSolMetric, x, nCols, bRejectSoln);
}
int XPRS_mse_minim (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols){
    if (!__symbolic_XPRS_mse_minim) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_minim", (gpointer *) &__symbolic_XPRS_mse_minim)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_minim could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_minim.\n");
        }
    }
    return __symbolic_XPRS_mse_minim(mse, prob, msp, f_mse_handler, p, nMaxSols);
}
int XPRS_mse_maxim (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols){
    if (!__symbolic_XPRS_mse_maxim) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_maxim", (gpointer *) &__symbolic_XPRS_mse_maxim)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_maxim could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_maxim.\n");
        }
    }
    return __symbolic_XPRS_mse_maxim(mse, prob, msp, f_mse_handler, p, nMaxSols);
}
int XPRS_mse_opt (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, int ( * f_mse_handler) (XPRSmipsolenum mse, XPRSprob prob, XPRSmipsolpool msp, void *vContext, int *nMaxSols, const double x_Zb[], const int nCols, const double dMipObject, double *dModifiedObject, int *bRejectSoln, int *bUpdateMipAbsCutOffOnCurrentSet), void *p, int *nMaxSols){
    if (!__symbolic_XPRS_mse_opt) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_opt", (gpointer *) &__symbolic_XPRS_mse_opt)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_opt could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_opt.\n");
        }
    }
    return __symbolic_XPRS_mse_opt(mse, prob, msp, f_mse_handler, p, nMaxSols);
}
int XPRS_mse_getintattrib (XPRSmipsolenum mse, int iAttribId, int *Val){
    if (!__symbolic_XPRS_mse_getintattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getintattrib", (gpointer *) &__symbolic_XPRS_mse_getintattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getintattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getintattrib.\n");
        }
    }
    return __symbolic_XPRS_mse_getintattrib(mse, iAttribId, Val);
}
int XPRS_mse_getdblattrib (XPRSmipsolenum mse, int iAttribId, double *Val){
    if (!__symbolic_XPRS_mse_getdblattrib) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getdblattrib", (gpointer *) &__symbolic_XPRS_mse_getdblattrib)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getdblattrib could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getdblattrib.\n");
        }
    }
    return __symbolic_XPRS_mse_getdblattrib(mse, iAttribId, Val);
}
int XPRS_mse_getintcontrol (XPRSmipsolenum mse, int iAttribId, int *Val){
    if (!__symbolic_XPRS_mse_getintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getintcontrol", (gpointer *) &__symbolic_XPRS_mse_getintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getintcontrol.\n");
        }
    }
    return __symbolic_XPRS_mse_getintcontrol(mse, iAttribId, Val);
}
int XPRS_mse_getdblcontrol (XPRSmipsolenum mse, int iAttribId, double *Val){
    if (!__symbolic_XPRS_mse_getdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getdblcontrol", (gpointer *) &__symbolic_XPRS_mse_getdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getdblcontrol.\n");
        }
    }
    return __symbolic_XPRS_mse_getdblcontrol(mse, iAttribId, Val);
}
int XPRS_mse_setintcontrol (XPRSmipsolenum mse, int iAttribId, int Val){
    if (!__symbolic_XPRS_mse_setintcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_setintcontrol", (gpointer *) &__symbolic_XPRS_mse_setintcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_setintcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_setintcontrol.\n");
        }
    }
    return __symbolic_XPRS_mse_setintcontrol(mse, iAttribId, Val);
}
int XPRS_mse_setdblcontrol (XPRSmipsolenum mse, int iAttribId, double Val){
    if (!__symbolic_XPRS_mse_setdblcontrol) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_setdblcontrol", (gpointer *) &__symbolic_XPRS_mse_setdblcontrol)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_setdblcontrol could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_setdblcontrol.\n");
        }
    }
    return __symbolic_XPRS_mse_setdblcontrol(mse, iAttribId, Val);
}
int XPRS_mse_getlasterror (XPRSmipsolenum mse, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_mse_getlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getlasterror", (gpointer *) &__symbolic_XPRS_mse_getlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getlasterror.\n");
        }
    }
    return __symbolic_XPRS_mse_getlasterror(mse, iMsgCode, _msg, _iStringBufferBytes, _iBytesInInternalString);
}
int XPRS_mse_setsolbasename (XPRSmipsolenum mse, const char *sSolutionBaseName){
    if (!__symbolic_XPRS_mse_setsolbasename) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_setsolbasename", (gpointer *) &__symbolic_XPRS_mse_setsolbasename)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_setsolbasename could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_setsolbasename.\n");
        }
    }
    return __symbolic_XPRS_mse_setsolbasename(mse, sSolutionBaseName);
}
int XPRS_mse_getsolbasename (XPRSmipsolenum mse, char *_sname, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_mse_getsolbasename) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getsolbasename", (gpointer *) &__symbolic_XPRS_mse_getsolbasename)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getsolbasename could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getsolbasename.\n");
        }
    }
    return __symbolic_XPRS_mse_getsolbasename(mse, _sname, _iStringBufferBytes, _iBytesInInternalString);
}
int XPRS_mse_setcbgetsolutiondiff (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p){
    if (!__symbolic_XPRS_mse_setcbgetsolutiondiff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_setcbgetsolutiondiff", (gpointer *) &__symbolic_XPRS_mse_setcbgetsolutiondiff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_setcbgetsolutiondiff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_setcbgetsolutiondiff.\n");
        }
    }
    return __symbolic_XPRS_mse_setcbgetsolutiondiff(mse, f_mse_getsolutiondiff, p);
}
int XPRS_mse_getcbgetsolutiondiff (XPRSmipsolenum mse, int ( ** f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void **p){
    if (!__symbolic_XPRS_mse_getcbgetsolutiondiff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getcbgetsolutiondiff", (gpointer *) &__symbolic_XPRS_mse_getcbgetsolutiondiff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getcbgetsolutiondiff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getcbgetsolutiondiff.\n");
        }
    }
    return __symbolic_XPRS_mse_getcbgetsolutiondiff(mse, f_mse_getsolutiondiff, p);
}
int XPRS_mse_addcbgetsolutiondiff (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p, int priority){
    if (!__symbolic_XPRS_mse_addcbgetsolutiondiff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_addcbgetsolutiondiff", (gpointer *) &__symbolic_XPRS_mse_addcbgetsolutiondiff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_addcbgetsolutiondiff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_addcbgetsolutiondiff.\n");
        }
    }
    return __symbolic_XPRS_mse_addcbgetsolutiondiff(mse, f_mse_getsolutiondiff, p, priority);
}
int XPRS_mse_removecbgetsolutiondiff (XPRSmipsolenum mse, int ( * f_mse_getsolutiondiff) (XPRSmipsolenum mse, void *vContext, int nCols, int iSolutionId_1, int iElemCount_1, double dMipObj_1, const double Vals_1[], const int iSparseIndices_1[], int iSolutionId_2, int iElemCount_2, double dMipObj_2, const double Vals_2[], const int iSparseIndices_2[], double *dDiffMetric), void *p){
    if (!__symbolic_XPRS_mse_removecbgetsolutiondiff) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_removecbgetsolutiondiff", (gpointer *) &__symbolic_XPRS_mse_removecbgetsolutiondiff)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_removecbgetsolutiondiff could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_removecbgetsolutiondiff.\n");
        }
    }
    return __symbolic_XPRS_mse_removecbgetsolutiondiff(mse, f_mse_getsolutiondiff, p);
}
int XPRS_mse_setcbmsghandler (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_mse_setcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_setcbmsghandler", (gpointer *) &__symbolic_XPRS_mse_setcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_setcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_setcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_mse_setcbmsghandler(mse, f_msghandler, p);
}
int XPRS_mse_getcbmsghandler (XPRSmipsolenum mse, int ( ** f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void **p){
    if (!__symbolic_XPRS_mse_getcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_getcbmsghandler", (gpointer *) &__symbolic_XPRS_mse_getcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_getcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_getcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_mse_getcbmsghandler(mse, f_msghandler, p);
}
int XPRS_mse_addcbmsghandler (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p, int priority){
    if (!__symbolic_XPRS_mse_addcbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_addcbmsghandler", (gpointer *) &__symbolic_XPRS_mse_addcbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_addcbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_addcbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_mse_addcbmsghandler(mse, f_msghandler, p, priority);
}
int XPRS_mse_removecbmsghandler (XPRSmipsolenum mse, int ( * f_msghandler) (XPRSobject vXPRSObject, void *vUserContext, void *vSystemThreadId, const char *sMsg, int iMsgType, int iMsgCode), void *p){
    if (!__symbolic_XPRS_mse_removecbmsghandler) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_mse_removecbmsghandler", (gpointer *) &__symbolic_XPRS_mse_removecbmsghandler)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_mse_removecbmsghandler could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_mse_removecbmsghandler.\n");
        }
    }
    return __symbolic_XPRS_mse_removecbmsghandler(mse, f_msghandler, p);
}
int XPRS_bo_create (XPRSbranchobject * p_object, XPRSprob prob, int isoriginal){
    if (!__symbolic_XPRS_bo_create) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_create", (gpointer *) &__symbolic_XPRS_bo_create)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_create could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_create.\n");
        }
    }
    return __symbolic_XPRS_bo_create(p_object, prob, isoriginal);
}
int XPRS_bo_destroy (XPRSbranchobject obranch){
    if (!__symbolic_XPRS_bo_destroy) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_destroy", (gpointer *) &__symbolic_XPRS_bo_destroy)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_destroy could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_destroy.\n");
        }
    }
    return __symbolic_XPRS_bo_destroy(obranch);
}
int XPRS_bo_store (XPRSbranchobject obranch, int *p_status){
    if (!__symbolic_XPRS_bo_store) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_store", (gpointer *) &__symbolic_XPRS_bo_store)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_store could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_store.\n");
        }
    }
    return __symbolic_XPRS_bo_store(obranch, p_status);
}
int XPRS_bo_addbranches (XPRSbranchobject obranch, int nbranches){
    if (!__symbolic_XPRS_bo_addbranches) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_addbranches", (gpointer *) &__symbolic_XPRS_bo_addbranches)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_addbranches could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_addbranches.\n");
        }
    }
    return __symbolic_XPRS_bo_addbranches(obranch, nbranches);
}
int XPRS_bo_getbranches (XPRSbranchobject obranch, int *p_nbranches){
    if (!__symbolic_XPRS_bo_getbranches) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_getbranches", (gpointer *) &__symbolic_XPRS_bo_getbranches)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_getbranches could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_getbranches.\n");
        }
    }
    return __symbolic_XPRS_bo_getbranches(obranch, p_nbranches);
}
int XPRS_bo_setpriority (XPRSbranchobject obranch, int ipriority){
    if (!__symbolic_XPRS_bo_setpriority) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_setpriority", (gpointer *) &__symbolic_XPRS_bo_setpriority)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_setpriority could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_setpriority.\n");
        }
    }
    return __symbolic_XPRS_bo_setpriority(obranch, ipriority);
}
int XPRS_bo_setpreferredbranch (XPRSbranchobject obranch, int ibranch){
    if (!__symbolic_XPRS_bo_setpreferredbranch) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_setpreferredbranch", (gpointer *) &__symbolic_XPRS_bo_setpreferredbranch)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_setpreferredbranch could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_setpreferredbranch.\n");
        }
    }
    return __symbolic_XPRS_bo_setpreferredbranch(obranch, ibranch);
}
int XPRS_bo_addbounds (XPRSbranchobject obranch, int ibranch, int nbounds, const char cbndtype[], const int mbndcol[], const double dbndval[]){
    if (!__symbolic_XPRS_bo_addbounds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_addbounds", (gpointer *) &__symbolic_XPRS_bo_addbounds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_addbounds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_addbounds.\n");
        }
    }
    return __symbolic_XPRS_bo_addbounds(obranch, ibranch, nbounds, cbndtype, mbndcol, dbndval);
}
int XPRS_bo_getbounds (XPRSbranchobject obranch, int ibranch, int *p_nbounds, int nbounds_size, char cbndtype[], int mbndcol[], double dbndval[]){
    if (!__symbolic_XPRS_bo_getbounds) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_getbounds", (gpointer *) &__symbolic_XPRS_bo_getbounds)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_getbounds could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_getbounds.\n");
        }
    }
    return __symbolic_XPRS_bo_getbounds(obranch, ibranch, p_nbounds, nbounds_size, cbndtype, mbndcol, dbndval);
}
int XPRS_bo_addrows (XPRSbranchobject obranch, int ibranch, int nrows, int nelems, const char crtype[], const double drrhs[], const int mrbeg[], const int mcol[], const double dval[]){
    if (!__symbolic_XPRS_bo_addrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_addrows", (gpointer *) &__symbolic_XPRS_bo_addrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_addrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_addrows.\n");
        }
    }
    return __symbolic_XPRS_bo_addrows(obranch, ibranch, nrows, nelems, crtype, drrhs, mrbeg, mcol, dval);
}
int XPRS_bo_getrows (XPRSbranchobject obranch, int ibranch, int *p_nrows, int nrows_size, int *p_nelems, int nelems_size, char crtype[], double drrhs[], int mrbeg[], int mcol[], double dval[]){
    if (!__symbolic_XPRS_bo_getrows) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_getrows", (gpointer *) &__symbolic_XPRS_bo_getrows)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_getrows could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_getrows.\n");
        }
    }
    return __symbolic_XPRS_bo_getrows(obranch, ibranch, p_nrows, nrows_size, p_nelems, nelems_size, crtype, drrhs, mrbeg, mcol, dval);
}
int XPRS_bo_addcuts (XPRSbranchobject obranch, int ibranch, int ncuts, const XPRScut mcutind[]){
    if (!__symbolic_XPRS_bo_addcuts) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_addcuts", (gpointer *) &__symbolic_XPRS_bo_addcuts)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_addcuts could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_addcuts.\n");
        }
    }
    return __symbolic_XPRS_bo_addcuts(obranch, ibranch, ncuts, mcutind);
}
int XPRS_bo_getid (XPRSbranchobject obranch, int *p_id){
    if (!__symbolic_XPRS_bo_getid) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_getid", (gpointer *) &__symbolic_XPRS_bo_getid)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_getid could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_getid.\n");
        }
    }
    return __symbolic_XPRS_bo_getid(obranch, p_id);
}
int XPRS_bo_getlasterror (XPRSbranchobject obranch, int *iMsgCode, char *_msg, int _iStringBufferBytes, int *_iBytesInInternalString){
    if (!__symbolic_XPRS_bo_getlasterror) {
        if (!module) {
            DEBUG_PRINT("lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                fprintf(stderr, "lazylpsolverlibs: Library lookup failed! Suggestions:\n"
                    " - point the LAZYLPSOLVERLIBS_XPRS_LIB environment variable to the full path of the library\n"
                    " - or more secure, symlink /usr/lib/libxprs.so to the full path of the library (you need root access).\n"
             );
            } else {
                DEBUG_PRINT("lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "XPRS_bo_getlasterror", (gpointer *) &__symbolic_XPRS_bo_getlasterror)) {
            fprintf(stderr, "lazylpsolverlibs: the symbol XPRS_bo_getlasterror could not be found! Exiting your program to avoid a segfault.\n");
            exit(1);
        } else {
            DEBUG_PRINT("lazylpsolverlibs: sucessfully imported the symbol XPRS_bo_getlasterror.\n");
        }
    }
    return __symbolic_XPRS_bo_getlasterror(obranch, iMsgCode, _msg, _iStringBufferBytes, _iBytesInInternalString);
}
