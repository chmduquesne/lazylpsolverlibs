
#include <stdio.h>
#include "lazy_gurobi_c.h"

/* C does not support bool, let's do it with macros */
#define bool int
#define true 1
#define false 0

int load_gurobi_c_symbols() {
    int res;
    bool try_another;
    try_another = true;

    if (lt_dlinit () != 0) return SYMBOL_LOAD_FAIL;

    try_another = !(__gurobi_c_handle = lt_dlopenext("libgurobi_c"));
    if (try_another) try_another = !(__gurobi_c_handle = lt_dlopenext("gurobi_c"));
    if (try_another) return SYMBOL_LOAD_FAIL;

    res = SYMBOL_LOAD_SUCCESS;

    if (!(__symbolic_GRBaddconstr = lt_dlsym(__gurobi_c_handle, "GRBaddconstr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddconstrs = lt_dlsym(__gurobi_c_handle, "GRBaddconstrs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddrangeconstr = lt_dlsym(__gurobi_c_handle, "GRBaddrangeconstr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddrangeconstrs = lt_dlsym(__gurobi_c_handle, "GRBaddrangeconstrs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddsos = lt_dlsym(__gurobi_c_handle, "GRBaddsos"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddvar = lt_dlsym(__gurobi_c_handle, "GRBaddvar"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBaddvars = lt_dlsym(__gurobi_c_handle, "GRBaddvars"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcbcut = lt_dlsym(__gurobi_c_handle, "GRBcbcut"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcbget = lt_dlsym(__gurobi_c_handle, "GRBcbget"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcbsolution = lt_dlsym(__gurobi_c_handle, "GRBcbsolution"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcheckmodel = lt_dlsym(__gurobi_c_handle, "GRBcheckmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBchgcoeffs = lt_dlsym(__gurobi_c_handle, "GRBchgcoeffs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcomputeIIS = lt_dlsym(__gurobi_c_handle, "GRBcomputeIIS"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBconverttofixed = lt_dlsym(__gurobi_c_handle, "GRBconverttofixed"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBcopymodel = lt_dlsym(__gurobi_c_handle, "GRBcopymodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBdelconstrs = lt_dlsym(__gurobi_c_handle, "GRBdelconstrs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBdelsos = lt_dlsym(__gurobi_c_handle, "GRBdelsos"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBdelvars = lt_dlsym(__gurobi_c_handle, "GRBdelvars"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBfeasibility = lt_dlsym(__gurobi_c_handle, "GRBfeasibility"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBfixedmodel = lt_dlsym(__gurobi_c_handle, "GRBfixedmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBfreeenv = lt_dlsym(__gurobi_c_handle, "GRBfreeenv"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBfreemodel = lt_dlsym(__gurobi_c_handle, "GRBfreemodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetattrinfo = lt_dlsym(__gurobi_c_handle, "GRBgetattrinfo"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcallbackfunc = lt_dlsym(__gurobi_c_handle, "GRBgetcallbackfunc"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcbwhatinfo = lt_dlsym(__gurobi_c_handle, "GRBgetcbwhatinfo"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcharattrarray = lt_dlsym(__gurobi_c_handle, "GRBgetcharattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcharattrelement = lt_dlsym(__gurobi_c_handle, "GRBgetcharattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcharattrlist = lt_dlsym(__gurobi_c_handle, "GRBgetcharattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetcoeff = lt_dlsym(__gurobi_c_handle, "GRBgetcoeff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetconstrs = lt_dlsym(__gurobi_c_handle, "GRBgetconstrs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblattr = lt_dlsym(__gurobi_c_handle, "GRBgetdblattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblattrarray = lt_dlsym(__gurobi_c_handle, "GRBgetdblattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblattrelement = lt_dlsym(__gurobi_c_handle, "GRBgetdblattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblattrlist = lt_dlsym(__gurobi_c_handle, "GRBgetdblattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblparam = lt_dlsym(__gurobi_c_handle, "GRBgetdblparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetdblparaminfo = lt_dlsym(__gurobi_c_handle, "GRBgetdblparaminfo"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetenv = lt_dlsym(__gurobi_c_handle, "GRBgetenv"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgeterrormsg = lt_dlsym(__gurobi_c_handle, "GRBgeterrormsg"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintattr = lt_dlsym(__gurobi_c_handle, "GRBgetintattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintattrarray = lt_dlsym(__gurobi_c_handle, "GRBgetintattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintattrelement = lt_dlsym(__gurobi_c_handle, "GRBgetintattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintattrlist = lt_dlsym(__gurobi_c_handle, "GRBgetintattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintparam = lt_dlsym(__gurobi_c_handle, "GRBgetintparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetintparaminfo = lt_dlsym(__gurobi_c_handle, "GRBgetintparaminfo"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetlogfile = lt_dlsym(__gurobi_c_handle, "GRBgetlogfile"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetmerrormsg = lt_dlsym(__gurobi_c_handle, "GRBgetmerrormsg"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetnumparams = lt_dlsym(__gurobi_c_handle, "GRBgetnumparams"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetparamname = lt_dlsym(__gurobi_c_handle, "GRBgetparamname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetparamtype = lt_dlsym(__gurobi_c_handle, "GRBgetparamtype"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetsos = lt_dlsym(__gurobi_c_handle, "GRBgetsos"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrattr = lt_dlsym(__gurobi_c_handle, "GRBgetstrattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrattrarray = lt_dlsym(__gurobi_c_handle, "GRBgetstrattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrattrelement = lt_dlsym(__gurobi_c_handle, "GRBgetstrattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrattrlist = lt_dlsym(__gurobi_c_handle, "GRBgetstrattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrparam = lt_dlsym(__gurobi_c_handle, "GRBgetstrparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetstrparaminfo = lt_dlsym(__gurobi_c_handle, "GRBgetstrparaminfo"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBgetvars = lt_dlsym(__gurobi_c_handle, "GRBgetvars"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBiismodel = lt_dlsym(__gurobi_c_handle, "GRBiismodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBloadenv = lt_dlsym(__gurobi_c_handle, "GRBloadenv"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBloadmodel = lt_dlsym(__gurobi_c_handle, "GRBloadmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBmsg = lt_dlsym(__gurobi_c_handle, "GRBmsg"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBnewmodel = lt_dlsym(__gurobi_c_handle, "GRBnewmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBoptimize = lt_dlsym(__gurobi_c_handle, "GRBoptimize"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBplatform = lt_dlsym(__gurobi_c_handle, "GRBplatform"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBpresolvemodel = lt_dlsym(__gurobi_c_handle, "GRBpresolvemodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBread = lt_dlsym(__gurobi_c_handle, "GRBread"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBreadmodel = lt_dlsym(__gurobi_c_handle, "GRBreadmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBreadparams = lt_dlsym(__gurobi_c_handle, "GRBreadparams"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBrelaxmodel = lt_dlsym(__gurobi_c_handle, "GRBrelaxmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBresetmodel = lt_dlsym(__gurobi_c_handle, "GRBresetmodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBresetparams = lt_dlsym(__gurobi_c_handle, "GRBresetparams"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetcallbackfunc = lt_dlsym(__gurobi_c_handle, "GRBsetcallbackfunc"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetcharattrarray = lt_dlsym(__gurobi_c_handle, "GRBsetcharattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetcharattrelement = lt_dlsym(__gurobi_c_handle, "GRBsetcharattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetcharattrlist = lt_dlsym(__gurobi_c_handle, "GRBsetcharattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetdblattr = lt_dlsym(__gurobi_c_handle, "GRBsetdblattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetdblattrarray = lt_dlsym(__gurobi_c_handle, "GRBsetdblattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetdblattrelement = lt_dlsym(__gurobi_c_handle, "GRBsetdblattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetdblattrlist = lt_dlsym(__gurobi_c_handle, "GRBsetdblattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetdblparam = lt_dlsym(__gurobi_c_handle, "GRBsetdblparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetintattr = lt_dlsym(__gurobi_c_handle, "GRBsetintattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetintattrarray = lt_dlsym(__gurobi_c_handle, "GRBsetintattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetintattrelement = lt_dlsym(__gurobi_c_handle, "GRBsetintattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetintattrlist = lt_dlsym(__gurobi_c_handle, "GRBsetintattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetintparam = lt_dlsym(__gurobi_c_handle, "GRBsetintparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetlogfile = lt_dlsym(__gurobi_c_handle, "GRBsetlogfile"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetsignal = lt_dlsym(__gurobi_c_handle, "GRBsetsignal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetstrattr = lt_dlsym(__gurobi_c_handle, "GRBsetstrattr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetstrattrarray = lt_dlsym(__gurobi_c_handle, "GRBsetstrattrarray"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetstrattrelement = lt_dlsym(__gurobi_c_handle, "GRBsetstrattrelement"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetstrattrlist = lt_dlsym(__gurobi_c_handle, "GRBsetstrattrlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBsetstrparam = lt_dlsym(__gurobi_c_handle, "GRBsetstrparam"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBstrongbranch = lt_dlsym(__gurobi_c_handle, "GRBstrongbranch"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBterminate = lt_dlsym(__gurobi_c_handle, "GRBterminate"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBupdatemodel = lt_dlsym(__gurobi_c_handle, "GRBupdatemodel"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBversion = lt_dlsym(__gurobi_c_handle, "GRBversion"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBwrite = lt_dlsym(__gurobi_c_handle, "GRBwrite"))) res = SYMBOL_MISSING;
    if (!(__symbolic_GRBwriteparams = lt_dlsym(__gurobi_c_handle, "GRBwriteparams"))) res = SYMBOL_MISSING;

    return res;
}

void print_gurobi_c_missing_symbols() {

    if (!__symbolic_GRBaddconstr) printf("GRBaddconstr\n");
    if (!__symbolic_GRBaddconstrs) printf("GRBaddconstrs\n");
    if (!__symbolic_GRBaddrangeconstr) printf("GRBaddrangeconstr\n");
    if (!__symbolic_GRBaddrangeconstrs) printf("GRBaddrangeconstrs\n");
    if (!__symbolic_GRBaddsos) printf("GRBaddsos\n");
    if (!__symbolic_GRBaddvar) printf("GRBaddvar\n");
    if (!__symbolic_GRBaddvars) printf("GRBaddvars\n");
    if (!__symbolic_GRBcbcut) printf("GRBcbcut\n");
    if (!__symbolic_GRBcbget) printf("GRBcbget\n");
    if (!__symbolic_GRBcbsolution) printf("GRBcbsolution\n");
    if (!__symbolic_GRBcheckmodel) printf("GRBcheckmodel\n");
    if (!__symbolic_GRBchgcoeffs) printf("GRBchgcoeffs\n");
    if (!__symbolic_GRBcomputeIIS) printf("GRBcomputeIIS\n");
    if (!__symbolic_GRBconverttofixed) printf("GRBconverttofixed\n");
    if (!__symbolic_GRBcopymodel) printf("GRBcopymodel\n");
    if (!__symbolic_GRBdelconstrs) printf("GRBdelconstrs\n");
    if (!__symbolic_GRBdelsos) printf("GRBdelsos\n");
    if (!__symbolic_GRBdelvars) printf("GRBdelvars\n");
    if (!__symbolic_GRBfeasibility) printf("GRBfeasibility\n");
    if (!__symbolic_GRBfixedmodel) printf("GRBfixedmodel\n");
    if (!__symbolic_GRBfreeenv) printf("GRBfreeenv\n");
    if (!__symbolic_GRBfreemodel) printf("GRBfreemodel\n");
    if (!__symbolic_GRBgetattrinfo) printf("GRBgetattrinfo\n");
    if (!__symbolic_GRBgetcallbackfunc) printf("GRBgetcallbackfunc\n");
    if (!__symbolic_GRBgetcbwhatinfo) printf("GRBgetcbwhatinfo\n");
    if (!__symbolic_GRBgetcharattrarray) printf("GRBgetcharattrarray\n");
    if (!__symbolic_GRBgetcharattrelement) printf("GRBgetcharattrelement\n");
    if (!__symbolic_GRBgetcharattrlist) printf("GRBgetcharattrlist\n");
    if (!__symbolic_GRBgetcoeff) printf("GRBgetcoeff\n");
    if (!__symbolic_GRBgetconstrs) printf("GRBgetconstrs\n");
    if (!__symbolic_GRBgetdblattr) printf("GRBgetdblattr\n");
    if (!__symbolic_GRBgetdblattrarray) printf("GRBgetdblattrarray\n");
    if (!__symbolic_GRBgetdblattrelement) printf("GRBgetdblattrelement\n");
    if (!__symbolic_GRBgetdblattrlist) printf("GRBgetdblattrlist\n");
    if (!__symbolic_GRBgetdblparam) printf("GRBgetdblparam\n");
    if (!__symbolic_GRBgetdblparaminfo) printf("GRBgetdblparaminfo\n");
    if (!__symbolic_GRBgetenv) printf("GRBgetenv\n");
    if (!__symbolic_GRBgeterrormsg) printf("GRBgeterrormsg\n");
    if (!__symbolic_GRBgetintattr) printf("GRBgetintattr\n");
    if (!__symbolic_GRBgetintattrarray) printf("GRBgetintattrarray\n");
    if (!__symbolic_GRBgetintattrelement) printf("GRBgetintattrelement\n");
    if (!__symbolic_GRBgetintattrlist) printf("GRBgetintattrlist\n");
    if (!__symbolic_GRBgetintparam) printf("GRBgetintparam\n");
    if (!__symbolic_GRBgetintparaminfo) printf("GRBgetintparaminfo\n");
    if (!__symbolic_GRBgetlogfile) printf("GRBgetlogfile\n");
    if (!__symbolic_GRBgetmerrormsg) printf("GRBgetmerrormsg\n");
    if (!__symbolic_GRBgetnumparams) printf("GRBgetnumparams\n");
    if (!__symbolic_GRBgetparamname) printf("GRBgetparamname\n");
    if (!__symbolic_GRBgetparamtype) printf("GRBgetparamtype\n");
    if (!__symbolic_GRBgetsos) printf("GRBgetsos\n");
    if (!__symbolic_GRBgetstrattr) printf("GRBgetstrattr\n");
    if (!__symbolic_GRBgetstrattrarray) printf("GRBgetstrattrarray\n");
    if (!__symbolic_GRBgetstrattrelement) printf("GRBgetstrattrelement\n");
    if (!__symbolic_GRBgetstrattrlist) printf("GRBgetstrattrlist\n");
    if (!__symbolic_GRBgetstrparam) printf("GRBgetstrparam\n");
    if (!__symbolic_GRBgetstrparaminfo) printf("GRBgetstrparaminfo\n");
    if (!__symbolic_GRBgetvars) printf("GRBgetvars\n");
    if (!__symbolic_GRBiismodel) printf("GRBiismodel\n");
    if (!__symbolic_GRBloadenv) printf("GRBloadenv\n");
    if (!__symbolic_GRBloadmodel) printf("GRBloadmodel\n");
    if (!__symbolic_GRBmsg) printf("GRBmsg\n");
    if (!__symbolic_GRBnewmodel) printf("GRBnewmodel\n");
    if (!__symbolic_GRBoptimize) printf("GRBoptimize\n");
    if (!__symbolic_GRBplatform) printf("GRBplatform\n");
    if (!__symbolic_GRBpresolvemodel) printf("GRBpresolvemodel\n");
    if (!__symbolic_GRBread) printf("GRBread\n");
    if (!__symbolic_GRBreadmodel) printf("GRBreadmodel\n");
    if (!__symbolic_GRBreadparams) printf("GRBreadparams\n");
    if (!__symbolic_GRBrelaxmodel) printf("GRBrelaxmodel\n");
    if (!__symbolic_GRBresetmodel) printf("GRBresetmodel\n");
    if (!__symbolic_GRBresetparams) printf("GRBresetparams\n");
    if (!__symbolic_GRBsetcallbackfunc) printf("GRBsetcallbackfunc\n");
    if (!__symbolic_GRBsetcharattrarray) printf("GRBsetcharattrarray\n");
    if (!__symbolic_GRBsetcharattrelement) printf("GRBsetcharattrelement\n");
    if (!__symbolic_GRBsetcharattrlist) printf("GRBsetcharattrlist\n");
    if (!__symbolic_GRBsetdblattr) printf("GRBsetdblattr\n");
    if (!__symbolic_GRBsetdblattrarray) printf("GRBsetdblattrarray\n");
    if (!__symbolic_GRBsetdblattrelement) printf("GRBsetdblattrelement\n");
    if (!__symbolic_GRBsetdblattrlist) printf("GRBsetdblattrlist\n");
    if (!__symbolic_GRBsetdblparam) printf("GRBsetdblparam\n");
    if (!__symbolic_GRBsetintattr) printf("GRBsetintattr\n");
    if (!__symbolic_GRBsetintattrarray) printf("GRBsetintattrarray\n");
    if (!__symbolic_GRBsetintattrelement) printf("GRBsetintattrelement\n");
    if (!__symbolic_GRBsetintattrlist) printf("GRBsetintattrlist\n");
    if (!__symbolic_GRBsetintparam) printf("GRBsetintparam\n");
    if (!__symbolic_GRBsetlogfile) printf("GRBsetlogfile\n");
    if (!__symbolic_GRBsetsignal) printf("GRBsetsignal\n");
    if (!__symbolic_GRBsetstrattr) printf("GRBsetstrattr\n");
    if (!__symbolic_GRBsetstrattrarray) printf("GRBsetstrattrarray\n");
    if (!__symbolic_GRBsetstrattrelement) printf("GRBsetstrattrelement\n");
    if (!__symbolic_GRBsetstrattrlist) printf("GRBsetstrattrlist\n");
    if (!__symbolic_GRBsetstrparam) printf("GRBsetstrparam\n");
    if (!__symbolic_GRBstrongbranch) printf("GRBstrongbranch\n");
    if (!__symbolic_GRBterminate) printf("GRBterminate\n");
    if (!__symbolic_GRBupdatemodel) printf("GRBupdatemodel\n");
    if (!__symbolic_GRBversion) printf("GRBversion\n");
    if (!__symbolic_GRBwrite) printf("GRBwrite\n");
    if (!__symbolic_GRBwriteparams) printf("GRBwriteparams\n");

}

int unload_gurobi_c_symbols() {
    /* unload library */
    if (lt_dlclose (__gurobi_c_handle) != 0) return SYMBOL_UNLOAD_FAIL;

    /* exit */
    if (lt_dlexit() != 0) return SYMBOL_UNLOAD_FAIL;

    return SYMBOL_UNLOAD_SUCCESS;
}

