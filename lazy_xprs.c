
#include "lazy_xprs.h"

int load_xprs_symbols() {
    int res;

    if (lt_dlinit () != 0) return SYMBOL_LOAD_FAIL;
    if (!(__xprs_handle = lt_dlopenext("libxprs"))) return SYMBOL_LOAD_FAIL;

    res = SYMBOL_LOAD_SUCCESS;

    if (!(__symbolic_XPRSaddcols = lt_dlsym(__xprs_handle, "XPRSaddcols"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddcuts = lt_dlsym(__xprs_handle, "XPRSaddcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddnames = lt_dlsym(__xprs_handle, "XPRSaddnames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddqmatrix = lt_dlsym(__xprs_handle, "XPRSaddqmatrix"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddrows = lt_dlsym(__xprs_handle, "XPRSaddrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddsetnames = lt_dlsym(__xprs_handle, "XPRSaddsetnames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSaddsets = lt_dlsym(__xprs_handle, "XPRSaddsets"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSalter = lt_dlsym(__xprs_handle, "XPRSalter"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSbasiscondition = lt_dlsym(__xprs_handle, "XPRSbasiscondition"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSbeginlicensing = lt_dlsym(__xprs_handle, "XPRSbeginlicensing"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_addbounds = lt_dlsym(__xprs_handle, "XPRS_bo_addbounds"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_addbranches = lt_dlsym(__xprs_handle, "XPRS_bo_addbranches"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_addcuts = lt_dlsym(__xprs_handle, "XPRS_bo_addcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_addrows = lt_dlsym(__xprs_handle, "XPRS_bo_addrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_create = lt_dlsym(__xprs_handle, "XPRS_bo_create"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_destroy = lt_dlsym(__xprs_handle, "XPRS_bo_destroy"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_getbounds = lt_dlsym(__xprs_handle, "XPRS_bo_getbounds"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_getbranches = lt_dlsym(__xprs_handle, "XPRS_bo_getbranches"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_getid = lt_dlsym(__xprs_handle, "XPRS_bo_getid"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_getlasterror = lt_dlsym(__xprs_handle, "XPRS_bo_getlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_getrows = lt_dlsym(__xprs_handle, "XPRS_bo_getrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_setcbmsghandler = lt_dlsym(__xprs_handle, "XPRS_bo_setcbmsghandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_setpreferredbranch = lt_dlsym(__xprs_handle, "XPRS_bo_setpreferredbranch"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_setpriority = lt_dlsym(__xprs_handle, "XPRS_bo_setpriority"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_bo_store = lt_dlsym(__xprs_handle, "XPRS_bo_store"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSbtran = lt_dlsym(__xprs_handle, "XPRSbtran"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgbounds = lt_dlsym(__xprs_handle, "XPRSchgbounds"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgcoef = lt_dlsym(__xprs_handle, "XPRSchgcoef"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgcoltype = lt_dlsym(__xprs_handle, "XPRSchgcoltype"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgmcoef = lt_dlsym(__xprs_handle, "XPRSchgmcoef"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgmqobj = lt_dlsym(__xprs_handle, "XPRSchgmqobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgobj = lt_dlsym(__xprs_handle, "XPRSchgobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgobjsense = lt_dlsym(__xprs_handle, "XPRSchgobjsense"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgqobj = lt_dlsym(__xprs_handle, "XPRSchgqobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgqrowcoeff = lt_dlsym(__xprs_handle, "XPRSchgqrowcoeff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgrhs = lt_dlsym(__xprs_handle, "XPRSchgrhs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgrhsrange = lt_dlsym(__xprs_handle, "XPRSchgrhsrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSchgrowtype = lt_dlsym(__xprs_handle, "XPRSchgrowtype"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRScopycallbacks = lt_dlsym(__xprs_handle, "XPRScopycallbacks"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRScopycontrols = lt_dlsym(__xprs_handle, "XPRScopycontrols"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRScopyprob = lt_dlsym(__xprs_handle, "XPRScopyprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRScreateprob = lt_dlsym(__xprs_handle, "XPRScreateprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelcols = lt_dlsym(__xprs_handle, "XPRSdelcols"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelcpcuts = lt_dlsym(__xprs_handle, "XPRSdelcpcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelcuts = lt_dlsym(__xprs_handle, "XPRSdelcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelindicators = lt_dlsym(__xprs_handle, "XPRSdelindicators"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelnode = lt_dlsym(__xprs_handle, "XPRSdelnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelqmatrix = lt_dlsym(__xprs_handle, "XPRSdelqmatrix"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelrows = lt_dlsym(__xprs_handle, "XPRSdelrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdelsets = lt_dlsym(__xprs_handle, "XPRSdelsets"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSdestroyprob = lt_dlsym(__xprs_handle, "XPRSdestroyprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSendlicensing = lt_dlsym(__xprs_handle, "XPRSendlicensing"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSfixglobal = lt_dlsym(__xprs_handle, "XPRSfixglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSfixglobals = lt_dlsym(__xprs_handle, "XPRSfixglobals"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSfree = lt_dlsym(__xprs_handle, "XPRSfree"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSftran = lt_dlsym(__xprs_handle, "XPRSftran"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_ge_getlasterror = lt_dlsym(__xprs_handle, "XPRS_ge_getlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_ge_setcbmsghandler = lt_dlsym(__xprs_handle, "XPRS_ge_setcbmsghandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetbanner = lt_dlsym(__xprs_handle, "XPRSgetbanner"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetbasis = lt_dlsym(__xprs_handle, "XPRSgetbasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbbariteration = lt_dlsym(__xprs_handle, "XPRSgetcbbariteration"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbbarlog = lt_dlsym(__xprs_handle, "XPRSgetcbbarlog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbchgbranch = lt_dlsym(__xprs_handle, "XPRSgetcbchgbranch"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbchgbranchobject = lt_dlsym(__xprs_handle, "XPRSgetcbchgbranchobject"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbchgnode = lt_dlsym(__xprs_handle, "XPRSgetcbchgnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbcutlog = lt_dlsym(__xprs_handle, "XPRSgetcbcutlog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbcutmgr = lt_dlsym(__xprs_handle, "XPRSgetcbcutmgr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbdestroymt = lt_dlsym(__xprs_handle, "XPRSgetcbdestroymt"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbestimate = lt_dlsym(__xprs_handle, "XPRSgetcbestimate"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbgloballog = lt_dlsym(__xprs_handle, "XPRSgetcbgloballog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbinfnode = lt_dlsym(__xprs_handle, "XPRSgetcbinfnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbintsol = lt_dlsym(__xprs_handle, "XPRSgetcbintsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcblplog = lt_dlsym(__xprs_handle, "XPRSgetcblplog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbmessage = lt_dlsym(__xprs_handle, "XPRSgetcbmessage"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbmipthread = lt_dlsym(__xprs_handle, "XPRSgetcbmipthread"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbnewnode = lt_dlsym(__xprs_handle, "XPRSgetcbnewnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbnlpevaluate = lt_dlsym(__xprs_handle, "XPRSgetcbnlpevaluate"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbnlpgradient = lt_dlsym(__xprs_handle, "XPRSgetcbnlpgradient"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbnlphessian = lt_dlsym(__xprs_handle, "XPRSgetcbnlphessian"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbnodecutoff = lt_dlsym(__xprs_handle, "XPRSgetcbnodecutoff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcboptnode = lt_dlsym(__xprs_handle, "XPRSgetcboptnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbpreintsol = lt_dlsym(__xprs_handle, "XPRSgetcbpreintsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbprenode = lt_dlsym(__xprs_handle, "XPRSgetcbprenode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcbsepnode = lt_dlsym(__xprs_handle, "XPRSgetcbsepnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcoef = lt_dlsym(__xprs_handle, "XPRSgetcoef"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcolrange = lt_dlsym(__xprs_handle, "XPRSgetcolrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcols = lt_dlsym(__xprs_handle, "XPRSgetcols"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcoltype = lt_dlsym(__xprs_handle, "XPRSgetcoltype"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcpcutlist = lt_dlsym(__xprs_handle, "XPRSgetcpcutlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcpcuts = lt_dlsym(__xprs_handle, "XPRSgetcpcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcutlist = lt_dlsym(__xprs_handle, "XPRSgetcutlist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcutmap = lt_dlsym(__xprs_handle, "XPRSgetcutmap"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetcutslack = lt_dlsym(__xprs_handle, "XPRSgetcutslack"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetdaysleft = lt_dlsym(__xprs_handle, "XPRSgetdaysleft"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetdblattrib = lt_dlsym(__xprs_handle, "XPRSgetdblattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetdblcontrol = lt_dlsym(__xprs_handle, "XPRSgetdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetdirs = lt_dlsym(__xprs_handle, "XPRSgetdirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetglobal = lt_dlsym(__xprs_handle, "XPRSgetglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetiis = lt_dlsym(__xprs_handle, "XPRSgetiis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetiisdata = lt_dlsym(__xprs_handle, "XPRSgetiisdata"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetindex = lt_dlsym(__xprs_handle, "XPRSgetindex"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetindicators = lt_dlsym(__xprs_handle, "XPRSgetindicators"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetinfeas = lt_dlsym(__xprs_handle, "XPRSgetinfeas"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetintattrib = lt_dlsym(__xprs_handle, "XPRSgetintattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetintcontrol = lt_dlsym(__xprs_handle, "XPRSgetintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetlasterror = lt_dlsym(__xprs_handle, "XPRSgetlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetlb = lt_dlsym(__xprs_handle, "XPRSgetlb"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetlicerrmsg = lt_dlsym(__xprs_handle, "XPRSgetlicerrmsg"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetlpsol = lt_dlsym(__xprs_handle, "XPRSgetlpsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetmessagestatus = lt_dlsym(__xprs_handle, "XPRSgetmessagestatus"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetmipsol = lt_dlsym(__xprs_handle, "XPRSgetmipsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetmqobj = lt_dlsym(__xprs_handle, "XPRSgetmqobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetnamelist = lt_dlsym(__xprs_handle, "XPRSgetnamelist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetnamelistobject = lt_dlsym(__xprs_handle, "XPRSgetnamelistobject"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetnames = lt_dlsym(__xprs_handle, "XPRSgetnames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetobj = lt_dlsym(__xprs_handle, "XPRSgetobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetobjecttypename = lt_dlsym(__xprs_handle, "XPRSgetobjecttypename"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetpivotorder = lt_dlsym(__xprs_handle, "XPRSgetpivotorder"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetpivots = lt_dlsym(__xprs_handle, "XPRSgetpivots"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetpresolvebasis = lt_dlsym(__xprs_handle, "XPRSgetpresolvebasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetpresolvemap = lt_dlsym(__xprs_handle, "XPRSgetpresolvemap"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetpresolvesol = lt_dlsym(__xprs_handle, "XPRSgetpresolvesol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetprobname = lt_dlsym(__xprs_handle, "XPRSgetprobname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetqobj = lt_dlsym(__xprs_handle, "XPRSgetqobj"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetqrowcoeff = lt_dlsym(__xprs_handle, "XPRSgetqrowcoeff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetqrowqmatrix = lt_dlsym(__xprs_handle, "XPRSgetqrowqmatrix"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetqrowqmatrixtriplets = lt_dlsym(__xprs_handle, "XPRSgetqrowqmatrixtriplets"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetqrows = lt_dlsym(__xprs_handle, "XPRSgetqrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetrhs = lt_dlsym(__xprs_handle, "XPRSgetrhs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetrhsrange = lt_dlsym(__xprs_handle, "XPRSgetrhsrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetrowrange = lt_dlsym(__xprs_handle, "XPRSgetrowrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetrows = lt_dlsym(__xprs_handle, "XPRSgetrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetrowtype = lt_dlsym(__xprs_handle, "XPRSgetrowtype"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetscaledinfeas = lt_dlsym(__xprs_handle, "XPRSgetscaledinfeas"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetsol = lt_dlsym(__xprs_handle, "XPRSgetsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetstrattrib = lt_dlsym(__xprs_handle, "XPRSgetstrattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetstrcontrol = lt_dlsym(__xprs_handle, "XPRSgetstrcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetub = lt_dlsym(__xprs_handle, "XPRSgetub"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetunbvec = lt_dlsym(__xprs_handle, "XPRSgetunbvec"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgetversion = lt_dlsym(__xprs_handle, "XPRSgetversion"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSglobal = lt_dlsym(__xprs_handle, "XPRSglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSgoal = lt_dlsym(__xprs_handle, "XPRSgoal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisall = lt_dlsym(__xprs_handle, "XPRSiisall"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisclear = lt_dlsym(__xprs_handle, "XPRSiisclear"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisfirst = lt_dlsym(__xprs_handle, "XPRSiisfirst"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisisolations = lt_dlsym(__xprs_handle, "XPRSiisisolations"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisnext = lt_dlsym(__xprs_handle, "XPRSiisnext"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiisstatus = lt_dlsym(__xprs_handle, "XPRSiisstatus"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSiiswrite = lt_dlsym(__xprs_handle, "XPRSiiswrite"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSinit = lt_dlsym(__xprs_handle, "XPRSinit"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSinitglobal = lt_dlsym(__xprs_handle, "XPRSinitglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSinitializenlphessian = lt_dlsym(__xprs_handle, "XPRSinitializenlphessian"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSinitializenlphessian_indexpairs = lt_dlsym(__xprs_handle, "XPRSinitializenlphessian_indexpairs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSinterrupt = lt_dlsym(__xprs_handle, "XPRSinterrupt"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSlicense = lt_dlsym(__xprs_handle, "XPRSlicense"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadbasis = lt_dlsym(__xprs_handle, "XPRSloadbasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadbranchdirs = lt_dlsym(__xprs_handle, "XPRSloadbranchdirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadcuts = lt_dlsym(__xprs_handle, "XPRSloadcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloaddelayedrows = lt_dlsym(__xprs_handle, "XPRSloaddelayedrows"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloaddirs = lt_dlsym(__xprs_handle, "XPRSloaddirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadglobal = lt_dlsym(__xprs_handle, "XPRSloadglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadlp = lt_dlsym(__xprs_handle, "XPRSloadlp"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadmipsol = lt_dlsym(__xprs_handle, "XPRSloadmipsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadmodelcuts = lt_dlsym(__xprs_handle, "XPRSloadmodelcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadpresolvebasis = lt_dlsym(__xprs_handle, "XPRSloadpresolvebasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadpresolvedirs = lt_dlsym(__xprs_handle, "XPRSloadpresolvedirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadqcqp = lt_dlsym(__xprs_handle, "XPRSloadqcqp"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadqcqpglobal = lt_dlsym(__xprs_handle, "XPRSloadqcqpglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadqglobal = lt_dlsym(__xprs_handle, "XPRSloadqglobal"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadqp = lt_dlsym(__xprs_handle, "XPRSloadqp"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSloadsecurevecs = lt_dlsym(__xprs_handle, "XPRSloadsecurevecs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSlogfilehandler = lt_dlsym(__xprs_handle, "XPRSlogfilehandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSlpoptimize = lt_dlsym(__xprs_handle, "XPRSlpoptimize"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSmaxim = lt_dlsym(__xprs_handle, "XPRSmaxim"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSminim = lt_dlsym(__xprs_handle, "XPRSminim"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSmipoptimize = lt_dlsym(__xprs_handle, "XPRSmipoptimize"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_create = lt_dlsym(__xprs_handle, "XPRS_mse_create"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_destroy = lt_dlsym(__xprs_handle, "XPRS_mse_destroy"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getcbgetsolutiondiff = lt_dlsym(__xprs_handle, "XPRS_mse_getcbgetsolutiondiff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getcullchoice = lt_dlsym(__xprs_handle, "XPRS_mse_getcullchoice"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getdblattrib = lt_dlsym(__xprs_handle, "XPRS_mse_getdblattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getdblcontrol = lt_dlsym(__xprs_handle, "XPRS_mse_getdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getintattrib = lt_dlsym(__xprs_handle, "XPRS_mse_getintattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getintcontrol = lt_dlsym(__xprs_handle, "XPRS_mse_getintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getlasterror = lt_dlsym(__xprs_handle, "XPRS_mse_getlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getsolbasename = lt_dlsym(__xprs_handle, "XPRS_mse_getsolbasename"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getsollist = lt_dlsym(__xprs_handle, "XPRS_mse_getsollist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_getsolmetric = lt_dlsym(__xprs_handle, "XPRS_mse_getsolmetric"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_maxim = lt_dlsym(__xprs_handle, "XPRS_mse_maxim"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_minim = lt_dlsym(__xprs_handle, "XPRS_mse_minim"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_opt = lt_dlsym(__xprs_handle, "XPRS_mse_opt"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_setcbgetsolutiondiff = lt_dlsym(__xprs_handle, "XPRS_mse_setcbgetsolutiondiff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_setcbmsghandler = lt_dlsym(__xprs_handle, "XPRS_mse_setcbmsghandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_setdblcontrol = lt_dlsym(__xprs_handle, "XPRS_mse_setdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_setintcontrol = lt_dlsym(__xprs_handle, "XPRS_mse_setintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_mse_setsolbasename = lt_dlsym(__xprs_handle, "XPRS_mse_setsolbasename"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_create = lt_dlsym(__xprs_handle, "XPRS_msp_create"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_delsol = lt_dlsym(__xprs_handle, "XPRS_msp_delsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_destroy = lt_dlsym(__xprs_handle, "XPRS_msp_destroy"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_findsolbyname = lt_dlsym(__xprs_handle, "XPRS_msp_findsolbyname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblattrib = lt_dlsym(__xprs_handle, "XPRS_msp_getdblattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblattribprob = lt_dlsym(__xprs_handle, "XPRS_msp_getdblattribprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblattribprobextreme = lt_dlsym(__xprs_handle, "XPRS_msp_getdblattribprobextreme"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblattribprobsol = lt_dlsym(__xprs_handle, "XPRS_msp_getdblattribprobsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblattribsol = lt_dlsym(__xprs_handle, "XPRS_msp_getdblattribsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblcontrol = lt_dlsym(__xprs_handle, "XPRS_msp_getdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getdblcontrolsol = lt_dlsym(__xprs_handle, "XPRS_msp_getdblcontrolsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintattrib = lt_dlsym(__xprs_handle, "XPRS_msp_getintattrib"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintattribprob = lt_dlsym(__xprs_handle, "XPRS_msp_getintattribprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintattribprobextreme = lt_dlsym(__xprs_handle, "XPRS_msp_getintattribprobextreme"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintattribprobsol = lt_dlsym(__xprs_handle, "XPRS_msp_getintattribprobsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintattribsol = lt_dlsym(__xprs_handle, "XPRS_msp_getintattribsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintcontrol = lt_dlsym(__xprs_handle, "XPRS_msp_getintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getintcontrolsol = lt_dlsym(__xprs_handle, "XPRS_msp_getintcontrolsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getlasterror = lt_dlsym(__xprs_handle, "XPRS_msp_getlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getsol = lt_dlsym(__xprs_handle, "XPRS_msp_getsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getsollist = lt_dlsym(__xprs_handle, "XPRS_msp_getsollist"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getsollist2 = lt_dlsym(__xprs_handle, "XPRS_msp_getsollist2"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_getsolname = lt_dlsym(__xprs_handle, "XPRS_msp_getsolname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_loadsol = lt_dlsym(__xprs_handle, "XPRS_msp_loadsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_probattach = lt_dlsym(__xprs_handle, "XPRS_msp_probattach"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_probdetach = lt_dlsym(__xprs_handle, "XPRS_msp_probdetach"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_readslxsol = lt_dlsym(__xprs_handle, "XPRS_msp_readslxsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setcbmsghandler = lt_dlsym(__xprs_handle, "XPRS_msp_setcbmsghandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setdblcontrol = lt_dlsym(__xprs_handle, "XPRS_msp_setdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setdblcontrolsol = lt_dlsym(__xprs_handle, "XPRS_msp_setdblcontrolsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setintcontrol = lt_dlsym(__xprs_handle, "XPRS_msp_setintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setintcontrolsol = lt_dlsym(__xprs_handle, "XPRS_msp_setintcontrolsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_setsolname = lt_dlsym(__xprs_handle, "XPRS_msp_setsolname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_msp_writeslxsol = lt_dlsym(__xprs_handle, "XPRS_msp_writeslxsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_addnames = lt_dlsym(__xprs_handle, "XPRS_nml_addnames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_copynames = lt_dlsym(__xprs_handle, "XPRS_nml_copynames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_create = lt_dlsym(__xprs_handle, "XPRS_nml_create"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_destroy = lt_dlsym(__xprs_handle, "XPRS_nml_destroy"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_findname = lt_dlsym(__xprs_handle, "XPRS_nml_findname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_getlasterror = lt_dlsym(__xprs_handle, "XPRS_nml_getlasterror"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_getmaxnamelen = lt_dlsym(__xprs_handle, "XPRS_nml_getmaxnamelen"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_getnamecount = lt_dlsym(__xprs_handle, "XPRS_nml_getnamecount"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_getnames = lt_dlsym(__xprs_handle, "XPRS_nml_getnames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_removenames = lt_dlsym(__xprs_handle, "XPRS_nml_removenames"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRS_nml_setcbmsghandler = lt_dlsym(__xprs_handle, "XPRS_nml_setcbmsghandler"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSobjsa = lt_dlsym(__xprs_handle, "XPRSobjsa"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSpivot = lt_dlsym(__xprs_handle, "XPRSpivot"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSpostsolve = lt_dlsym(__xprs_handle, "XPRSpostsolve"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSpresolverow = lt_dlsym(__xprs_handle, "XPRSpresolverow"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSrange = lt_dlsym(__xprs_handle, "XPRSrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSreadbasis = lt_dlsym(__xprs_handle, "XPRSreadbasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSreadbinsol = lt_dlsym(__xprs_handle, "XPRSreadbinsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSreaddirs = lt_dlsym(__xprs_handle, "XPRSreaddirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSreadprob = lt_dlsym(__xprs_handle, "XPRSreadprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSreadslxsol = lt_dlsym(__xprs_handle, "XPRSreadslxsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSrepairinfeas = lt_dlsym(__xprs_handle, "XPRSrepairinfeas"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSrepairweightedinfeas = lt_dlsym(__xprs_handle, "XPRSrepairweightedinfeas"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSresetnlp = lt_dlsym(__xprs_handle, "XPRSresetnlp"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSrestore = lt_dlsym(__xprs_handle, "XPRSrestore"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSrhssa = lt_dlsym(__xprs_handle, "XPRSrhssa"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsave = lt_dlsym(__xprs_handle, "XPRSsave"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSscale = lt_dlsym(__xprs_handle, "XPRSscale"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetbranchbounds = lt_dlsym(__xprs_handle, "XPRSsetbranchbounds"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetbranchcuts = lt_dlsym(__xprs_handle, "XPRSsetbranchcuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbbariteration = lt_dlsym(__xprs_handle, "XPRSsetcbbariteration"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbbarlog = lt_dlsym(__xprs_handle, "XPRSsetcbbarlog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbchgbranch = lt_dlsym(__xprs_handle, "XPRSsetcbchgbranch"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbchgbranchobject = lt_dlsym(__xprs_handle, "XPRSsetcbchgbranchobject"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbchgnode = lt_dlsym(__xprs_handle, "XPRSsetcbchgnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbcutlog = lt_dlsym(__xprs_handle, "XPRSsetcbcutlog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbcutmgr = lt_dlsym(__xprs_handle, "XPRSsetcbcutmgr"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbdestroymt = lt_dlsym(__xprs_handle, "XPRSsetcbdestroymt"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbestimate = lt_dlsym(__xprs_handle, "XPRSsetcbestimate"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbgloballog = lt_dlsym(__xprs_handle, "XPRSsetcbgloballog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbinfnode = lt_dlsym(__xprs_handle, "XPRSsetcbinfnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbintsol = lt_dlsym(__xprs_handle, "XPRSsetcbintsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcblplog = lt_dlsym(__xprs_handle, "XPRSsetcblplog"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbmessage = lt_dlsym(__xprs_handle, "XPRSsetcbmessage"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbmipthread = lt_dlsym(__xprs_handle, "XPRSsetcbmipthread"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbnewnode = lt_dlsym(__xprs_handle, "XPRSsetcbnewnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbnlpevaluate = lt_dlsym(__xprs_handle, "XPRSsetcbnlpevaluate"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbnlpgradient = lt_dlsym(__xprs_handle, "XPRSsetcbnlpgradient"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbnlphessian = lt_dlsym(__xprs_handle, "XPRSsetcbnlphessian"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbnodecutoff = lt_dlsym(__xprs_handle, "XPRSsetcbnodecutoff"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcboptnode = lt_dlsym(__xprs_handle, "XPRSsetcboptnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbpreintsol = lt_dlsym(__xprs_handle, "XPRSsetcbpreintsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbprenode = lt_dlsym(__xprs_handle, "XPRSsetcbprenode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetcbsepnode = lt_dlsym(__xprs_handle, "XPRSsetcbsepnode"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetdblcontrol = lt_dlsym(__xprs_handle, "XPRSsetdblcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetdefaultcontrol = lt_dlsym(__xprs_handle, "XPRSsetdefaultcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetdefaults = lt_dlsym(__xprs_handle, "XPRSsetdefaults"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetindicators = lt_dlsym(__xprs_handle, "XPRSsetindicators"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetintcontrol = lt_dlsym(__xprs_handle, "XPRSsetintcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetlogfile = lt_dlsym(__xprs_handle, "XPRSsetlogfile"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetmessagestatus = lt_dlsym(__xprs_handle, "XPRSsetmessagestatus"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetprobname = lt_dlsym(__xprs_handle, "XPRSsetprobname"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSsetstrcontrol = lt_dlsym(__xprs_handle, "XPRSsetstrcontrol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSstorebounds = lt_dlsym(__xprs_handle, "XPRSstorebounds"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSstorecuts = lt_dlsym(__xprs_handle, "XPRSstorecuts"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwritebasis = lt_dlsym(__xprs_handle, "XPRSwritebasis"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwritebinsol = lt_dlsym(__xprs_handle, "XPRSwritebinsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwritedirs = lt_dlsym(__xprs_handle, "XPRSwritedirs"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwriteprob = lt_dlsym(__xprs_handle, "XPRSwriteprob"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwriteprtrange = lt_dlsym(__xprs_handle, "XPRSwriteprtrange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwriteprtsol = lt_dlsym(__xprs_handle, "XPRSwriteprtsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwriterange = lt_dlsym(__xprs_handle, "XPRSwriterange"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwriteslxsol = lt_dlsym(__xprs_handle, "XPRSwriteslxsol"))) res = SYMBOL_MISSING;
    if (!(__symbolic_XPRSwritesol = lt_dlsym(__xprs_handle, "XPRSwritesol"))) res = SYMBOL_MISSING;

    return res;
}
int unload_xprs_symbols() {
    /* unload library */
    if (lt_dlclose (__xprs_handle) != 0) return SYMBOL_UNLOAD_FAIL;

    /* exit */
    if (lt_dlexit() != 0) return SYMBOL_UNLOAD_FAIL;

    return SYMBOL_UNLOAD_SUCCESS;
}

