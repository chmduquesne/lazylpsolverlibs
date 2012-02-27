
#ifndef LAZY_XPRS_H
#define LAZY_XPRS_H

#include <ltdl.h>
#include "lazy_loading_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#ifdef BUILDING_LAZYLPSOLVERLIBS
#define LLSL_DECL __declspec(dllexport)
#else
#define LLSL_DECL __declspec(dllimport)
#endif
#else
#define LLSL_DECL
#endif

/* handle to the library */
LLSL_DECL lt_dlhandle __xprs_handle;
/* loads the symbols */
LLSL_DECL int load_xprs_symbols();
/* unloads the symbols (if called as many times as loadSymbols) */
LLSL_DECL int unload_xprs_symbols();
/* prints what symbols ar missing */
LLSL_DECL void print_xprs_missing_symbols();

#define XPRSaddcols LLSL_DECL (*__symbolic_XPRSaddcols)
#define XPRSaddcuts LLSL_DECL (*__symbolic_XPRSaddcuts)
#define XPRSaddnames LLSL_DECL (*__symbolic_XPRSaddnames)
#define XPRSaddqmatrix LLSL_DECL (*__symbolic_XPRSaddqmatrix)
#define XPRSaddrows LLSL_DECL (*__symbolic_XPRSaddrows)
#define XPRSaddsetnames LLSL_DECL (*__symbolic_XPRSaddsetnames)
#define XPRSaddsets LLSL_DECL (*__symbolic_XPRSaddsets)
#define XPRSalter LLSL_DECL (*__symbolic_XPRSalter)
#define XPRSbasiscondition LLSL_DECL (*__symbolic_XPRSbasiscondition)
#define XPRSbeginlicensing LLSL_DECL (*__symbolic_XPRSbeginlicensing)
#define XPRS_bo_addbounds LLSL_DECL (*__symbolic_XPRS_bo_addbounds)
#define XPRS_bo_addbranches LLSL_DECL (*__symbolic_XPRS_bo_addbranches)
#define XPRS_bo_addcuts LLSL_DECL (*__symbolic_XPRS_bo_addcuts)
#define XPRS_bo_addrows LLSL_DECL (*__symbolic_XPRS_bo_addrows)
#define XPRS_bo_create LLSL_DECL (*__symbolic_XPRS_bo_create)
#define XPRS_bo_destroy LLSL_DECL (*__symbolic_XPRS_bo_destroy)
#define XPRS_bo_getbounds LLSL_DECL (*__symbolic_XPRS_bo_getbounds)
#define XPRS_bo_getbranches LLSL_DECL (*__symbolic_XPRS_bo_getbranches)
#define XPRS_bo_getid LLSL_DECL (*__symbolic_XPRS_bo_getid)
#define XPRS_bo_getlasterror LLSL_DECL (*__symbolic_XPRS_bo_getlasterror)
#define XPRS_bo_getrows LLSL_DECL (*__symbolic_XPRS_bo_getrows)
#define XPRS_bo_setcbmsghandler LLSL_DECL (*__symbolic_XPRS_bo_setcbmsghandler)
#define XPRS_bo_setpreferredbranch LLSL_DECL (*__symbolic_XPRS_bo_setpreferredbranch)
#define XPRS_bo_setpriority LLSL_DECL (*__symbolic_XPRS_bo_setpriority)
#define XPRS_bo_store LLSL_DECL (*__symbolic_XPRS_bo_store)
#define XPRSbtran LLSL_DECL (*__symbolic_XPRSbtran)
#define XPRSchgbounds LLSL_DECL (*__symbolic_XPRSchgbounds)
#define XPRSchgcoef LLSL_DECL (*__symbolic_XPRSchgcoef)
#define XPRSchgcoltype LLSL_DECL (*__symbolic_XPRSchgcoltype)
#define XPRSchgmcoef LLSL_DECL (*__symbolic_XPRSchgmcoef)
#define XPRSchgmqobj LLSL_DECL (*__symbolic_XPRSchgmqobj)
#define XPRSchgobj LLSL_DECL (*__symbolic_XPRSchgobj)
#define XPRSchgobjsense LLSL_DECL (*__symbolic_XPRSchgobjsense)
#define XPRSchgqobj LLSL_DECL (*__symbolic_XPRSchgqobj)
#define XPRSchgqrowcoeff LLSL_DECL (*__symbolic_XPRSchgqrowcoeff)
#define XPRSchgrhs LLSL_DECL (*__symbolic_XPRSchgrhs)
#define XPRSchgrhsrange LLSL_DECL (*__symbolic_XPRSchgrhsrange)
#define XPRSchgrowtype LLSL_DECL (*__symbolic_XPRSchgrowtype)
#define XPRScopycallbacks LLSL_DECL (*__symbolic_XPRScopycallbacks)
#define XPRScopycontrols LLSL_DECL (*__symbolic_XPRScopycontrols)
#define XPRScopyprob LLSL_DECL (*__symbolic_XPRScopyprob)
#define XPRScreateprob LLSL_DECL (*__symbolic_XPRScreateprob)
#define XPRSdelcols LLSL_DECL (*__symbolic_XPRSdelcols)
#define XPRSdelcpcuts LLSL_DECL (*__symbolic_XPRSdelcpcuts)
#define XPRSdelcuts LLSL_DECL (*__symbolic_XPRSdelcuts)
#define XPRSdelindicators LLSL_DECL (*__symbolic_XPRSdelindicators)
#define XPRSdelnode LLSL_DECL (*__symbolic_XPRSdelnode)
#define XPRSdelqmatrix LLSL_DECL (*__symbolic_XPRSdelqmatrix)
#define XPRSdelrows LLSL_DECL (*__symbolic_XPRSdelrows)
#define XPRSdelsets LLSL_DECL (*__symbolic_XPRSdelsets)
#define XPRSdestroyprob LLSL_DECL (*__symbolic_XPRSdestroyprob)
#define XPRSendlicensing LLSL_DECL (*__symbolic_XPRSendlicensing)
#define XPRSfixglobal LLSL_DECL (*__symbolic_XPRSfixglobal)
#define XPRSfixglobals LLSL_DECL (*__symbolic_XPRSfixglobals)
#define XPRSfree LLSL_DECL (*__symbolic_XPRSfree)
#define XPRSftran LLSL_DECL (*__symbolic_XPRSftran)
#define XPRS_ge_getlasterror LLSL_DECL (*__symbolic_XPRS_ge_getlasterror)
#define XPRS_ge_setcbmsghandler LLSL_DECL (*__symbolic_XPRS_ge_setcbmsghandler)
#define XPRSgetbanner LLSL_DECL (*__symbolic_XPRSgetbanner)
#define XPRSgetbasis LLSL_DECL (*__symbolic_XPRSgetbasis)
#define XPRSgetcbbariteration LLSL_DECL (*__symbolic_XPRSgetcbbariteration)
#define XPRSgetcbbarlog LLSL_DECL (*__symbolic_XPRSgetcbbarlog)
#define XPRSgetcbchgbranch LLSL_DECL (*__symbolic_XPRSgetcbchgbranch)
#define XPRSgetcbchgbranchobject LLSL_DECL (*__symbolic_XPRSgetcbchgbranchobject)
#define XPRSgetcbchgnode LLSL_DECL (*__symbolic_XPRSgetcbchgnode)
#define XPRSgetcbcutlog LLSL_DECL (*__symbolic_XPRSgetcbcutlog)
#define XPRSgetcbcutmgr LLSL_DECL (*__symbolic_XPRSgetcbcutmgr)
#define XPRSgetcbdestroymt LLSL_DECL (*__symbolic_XPRSgetcbdestroymt)
#define XPRSgetcbestimate LLSL_DECL (*__symbolic_XPRSgetcbestimate)
#define XPRSgetcbgloballog LLSL_DECL (*__symbolic_XPRSgetcbgloballog)
#define XPRSgetcbinfnode LLSL_DECL (*__symbolic_XPRSgetcbinfnode)
#define XPRSgetcbintsol LLSL_DECL (*__symbolic_XPRSgetcbintsol)
#define XPRSgetcblplog LLSL_DECL (*__symbolic_XPRSgetcblplog)
#define XPRSgetcbmessage LLSL_DECL (*__symbolic_XPRSgetcbmessage)
#define XPRSgetcbmipthread LLSL_DECL (*__symbolic_XPRSgetcbmipthread)
#define XPRSgetcbnewnode LLSL_DECL (*__symbolic_XPRSgetcbnewnode)
#define XPRSgetcbnlpevaluate LLSL_DECL (*__symbolic_XPRSgetcbnlpevaluate)
#define XPRSgetcbnlpgradient LLSL_DECL (*__symbolic_XPRSgetcbnlpgradient)
#define XPRSgetcbnlphessian LLSL_DECL (*__symbolic_XPRSgetcbnlphessian)
#define XPRSgetcbnodecutoff LLSL_DECL (*__symbolic_XPRSgetcbnodecutoff)
#define XPRSgetcboptnode LLSL_DECL (*__symbolic_XPRSgetcboptnode)
#define XPRSgetcbpreintsol LLSL_DECL (*__symbolic_XPRSgetcbpreintsol)
#define XPRSgetcbprenode LLSL_DECL (*__symbolic_XPRSgetcbprenode)
#define XPRSgetcbsepnode LLSL_DECL (*__symbolic_XPRSgetcbsepnode)
#define XPRSgetcoef LLSL_DECL (*__symbolic_XPRSgetcoef)
#define XPRSgetcolrange LLSL_DECL (*__symbolic_XPRSgetcolrange)
#define XPRSgetcols LLSL_DECL (*__symbolic_XPRSgetcols)
#define XPRSgetcoltype LLSL_DECL (*__symbolic_XPRSgetcoltype)
#define XPRSgetcpcutlist LLSL_DECL (*__symbolic_XPRSgetcpcutlist)
#define XPRSgetcpcuts LLSL_DECL (*__symbolic_XPRSgetcpcuts)
#define XPRSgetcutlist LLSL_DECL (*__symbolic_XPRSgetcutlist)
#define XPRSgetcutmap LLSL_DECL (*__symbolic_XPRSgetcutmap)
#define XPRSgetcutslack LLSL_DECL (*__symbolic_XPRSgetcutslack)
#define XPRSgetdaysleft LLSL_DECL (*__symbolic_XPRSgetdaysleft)
#define XPRSgetdblattrib LLSL_DECL (*__symbolic_XPRSgetdblattrib)
#define XPRSgetdblcontrol LLSL_DECL (*__symbolic_XPRSgetdblcontrol)
#define XPRSgetdirs LLSL_DECL (*__symbolic_XPRSgetdirs)
#define XPRSgetglobal LLSL_DECL (*__symbolic_XPRSgetglobal)
#define XPRSgetiis LLSL_DECL (*__symbolic_XPRSgetiis)
#define XPRSgetiisdata LLSL_DECL (*__symbolic_XPRSgetiisdata)
#define XPRSgetindex LLSL_DECL (*__symbolic_XPRSgetindex)
#define XPRSgetindicators LLSL_DECL (*__symbolic_XPRSgetindicators)
#define XPRSgetinfeas LLSL_DECL (*__symbolic_XPRSgetinfeas)
#define XPRSgetintattrib LLSL_DECL (*__symbolic_XPRSgetintattrib)
#define XPRSgetintcontrol LLSL_DECL (*__symbolic_XPRSgetintcontrol)
#define XPRSgetlasterror LLSL_DECL (*__symbolic_XPRSgetlasterror)
#define XPRSgetlb LLSL_DECL (*__symbolic_XPRSgetlb)
#define XPRSgetlicerrmsg LLSL_DECL (*__symbolic_XPRSgetlicerrmsg)
#define XPRSgetlpsol LLSL_DECL (*__symbolic_XPRSgetlpsol)
#define XPRSgetmessagestatus LLSL_DECL (*__symbolic_XPRSgetmessagestatus)
#define XPRSgetmipsol LLSL_DECL (*__symbolic_XPRSgetmipsol)
#define XPRSgetmqobj LLSL_DECL (*__symbolic_XPRSgetmqobj)
#define XPRSgetnamelist LLSL_DECL (*__symbolic_XPRSgetnamelist)
#define XPRSgetnamelistobject LLSL_DECL (*__symbolic_XPRSgetnamelistobject)
#define XPRSgetnames LLSL_DECL (*__symbolic_XPRSgetnames)
#define XPRSgetobj LLSL_DECL (*__symbolic_XPRSgetobj)
#define XPRSgetobjecttypename LLSL_DECL (*__symbolic_XPRSgetobjecttypename)
#define XPRSgetpivotorder LLSL_DECL (*__symbolic_XPRSgetpivotorder)
#define XPRSgetpivots LLSL_DECL (*__symbolic_XPRSgetpivots)
#define XPRSgetpresolvebasis LLSL_DECL (*__symbolic_XPRSgetpresolvebasis)
#define XPRSgetpresolvemap LLSL_DECL (*__symbolic_XPRSgetpresolvemap)
#define XPRSgetpresolvesol LLSL_DECL (*__symbolic_XPRSgetpresolvesol)
#define XPRSgetprobname LLSL_DECL (*__symbolic_XPRSgetprobname)
#define XPRSgetqobj LLSL_DECL (*__symbolic_XPRSgetqobj)
#define XPRSgetqrowcoeff LLSL_DECL (*__symbolic_XPRSgetqrowcoeff)
#define XPRSgetqrowqmatrix LLSL_DECL (*__symbolic_XPRSgetqrowqmatrix)
#define XPRSgetqrowqmatrixtriplets LLSL_DECL (*__symbolic_XPRSgetqrowqmatrixtriplets)
#define XPRSgetqrows LLSL_DECL (*__symbolic_XPRSgetqrows)
#define XPRSgetrhs LLSL_DECL (*__symbolic_XPRSgetrhs)
#define XPRSgetrhsrange LLSL_DECL (*__symbolic_XPRSgetrhsrange)
#define XPRSgetrowrange LLSL_DECL (*__symbolic_XPRSgetrowrange)
#define XPRSgetrows LLSL_DECL (*__symbolic_XPRSgetrows)
#define XPRSgetrowtype LLSL_DECL (*__symbolic_XPRSgetrowtype)
#define XPRSgetscaledinfeas LLSL_DECL (*__symbolic_XPRSgetscaledinfeas)
#define XPRSgetsol LLSL_DECL (*__symbolic_XPRSgetsol)
#define XPRSgetstrattrib LLSL_DECL (*__symbolic_XPRSgetstrattrib)
#define XPRSgetstrcontrol LLSL_DECL (*__symbolic_XPRSgetstrcontrol)
#define XPRSgetub LLSL_DECL (*__symbolic_XPRSgetub)
#define XPRSgetunbvec LLSL_DECL (*__symbolic_XPRSgetunbvec)
#define XPRSgetversion LLSL_DECL (*__symbolic_XPRSgetversion)
#define XPRSglobal LLSL_DECL (*__symbolic_XPRSglobal)
#define XPRSgoal LLSL_DECL (*__symbolic_XPRSgoal)
#define XPRSiisall LLSL_DECL (*__symbolic_XPRSiisall)
#define XPRSiisclear LLSL_DECL (*__symbolic_XPRSiisclear)
#define XPRSiisfirst LLSL_DECL (*__symbolic_XPRSiisfirst)
#define XPRSiisisolations LLSL_DECL (*__symbolic_XPRSiisisolations)
#define XPRSiisnext LLSL_DECL (*__symbolic_XPRSiisnext)
#define XPRSiisstatus LLSL_DECL (*__symbolic_XPRSiisstatus)
#define XPRSiiswrite LLSL_DECL (*__symbolic_XPRSiiswrite)
#define XPRSinit LLSL_DECL (*__symbolic_XPRSinit)
#define XPRSinitglobal LLSL_DECL (*__symbolic_XPRSinitglobal)
#define XPRSinitializenlphessian LLSL_DECL (*__symbolic_XPRSinitializenlphessian)
#define XPRSinitializenlphessian_indexpairs LLSL_DECL (*__symbolic_XPRSinitializenlphessian_indexpairs)
#define XPRSinterrupt LLSL_DECL (*__symbolic_XPRSinterrupt)
#define XPRSlicense LLSL_DECL (*__symbolic_XPRSlicense)
#define XPRSloadbasis LLSL_DECL (*__symbolic_XPRSloadbasis)
#define XPRSloadbranchdirs LLSL_DECL (*__symbolic_XPRSloadbranchdirs)
#define XPRSloadcuts LLSL_DECL (*__symbolic_XPRSloadcuts)
#define XPRSloaddelayedrows LLSL_DECL (*__symbolic_XPRSloaddelayedrows)
#define XPRSloaddirs LLSL_DECL (*__symbolic_XPRSloaddirs)
#define XPRSloadglobal LLSL_DECL (*__symbolic_XPRSloadglobal)
#define XPRSloadlp LLSL_DECL (*__symbolic_XPRSloadlp)
#define XPRSloadmipsol LLSL_DECL (*__symbolic_XPRSloadmipsol)
#define XPRSloadmodelcuts LLSL_DECL (*__symbolic_XPRSloadmodelcuts)
#define XPRSloadpresolvebasis LLSL_DECL (*__symbolic_XPRSloadpresolvebasis)
#define XPRSloadpresolvedirs LLSL_DECL (*__symbolic_XPRSloadpresolvedirs)
#define XPRSloadqcqp LLSL_DECL (*__symbolic_XPRSloadqcqp)
#define XPRSloadqcqpglobal LLSL_DECL (*__symbolic_XPRSloadqcqpglobal)
#define XPRSloadqglobal LLSL_DECL (*__symbolic_XPRSloadqglobal)
#define XPRSloadqp LLSL_DECL (*__symbolic_XPRSloadqp)
#define XPRSloadsecurevecs LLSL_DECL (*__symbolic_XPRSloadsecurevecs)
#define XPRSlogfilehandler LLSL_DECL (*__symbolic_XPRSlogfilehandler)
#define XPRSlpoptimize LLSL_DECL (*__symbolic_XPRSlpoptimize)
#define XPRSmaxim LLSL_DECL (*__symbolic_XPRSmaxim)
#define XPRSminim LLSL_DECL (*__symbolic_XPRSminim)
#define XPRSmipoptimize LLSL_DECL (*__symbolic_XPRSmipoptimize)
#define XPRS_mse_create LLSL_DECL (*__symbolic_XPRS_mse_create)
#define XPRS_mse_destroy LLSL_DECL (*__symbolic_XPRS_mse_destroy)
#define XPRS_mse_getcbgetsolutiondiff LLSL_DECL (*__symbolic_XPRS_mse_getcbgetsolutiondiff)
#define XPRS_mse_getcullchoice LLSL_DECL (*__symbolic_XPRS_mse_getcullchoice)
#define XPRS_mse_getdblattrib LLSL_DECL (*__symbolic_XPRS_mse_getdblattrib)
#define XPRS_mse_getdblcontrol LLSL_DECL (*__symbolic_XPRS_mse_getdblcontrol)
#define XPRS_mse_getintattrib LLSL_DECL (*__symbolic_XPRS_mse_getintattrib)
#define XPRS_mse_getintcontrol LLSL_DECL (*__symbolic_XPRS_mse_getintcontrol)
#define XPRS_mse_getlasterror LLSL_DECL (*__symbolic_XPRS_mse_getlasterror)
#define XPRS_mse_getsolbasename LLSL_DECL (*__symbolic_XPRS_mse_getsolbasename)
#define XPRS_mse_getsollist LLSL_DECL (*__symbolic_XPRS_mse_getsollist)
#define XPRS_mse_getsolmetric LLSL_DECL (*__symbolic_XPRS_mse_getsolmetric)
#define XPRS_mse_maxim LLSL_DECL (*__symbolic_XPRS_mse_maxim)
#define XPRS_mse_minim LLSL_DECL (*__symbolic_XPRS_mse_minim)
#define XPRS_mse_opt LLSL_DECL (*__symbolic_XPRS_mse_opt)
#define XPRS_mse_setcbgetsolutiondiff LLSL_DECL (*__symbolic_XPRS_mse_setcbgetsolutiondiff)
#define XPRS_mse_setcbmsghandler LLSL_DECL (*__symbolic_XPRS_mse_setcbmsghandler)
#define XPRS_mse_setdblcontrol LLSL_DECL (*__symbolic_XPRS_mse_setdblcontrol)
#define XPRS_mse_setintcontrol LLSL_DECL (*__symbolic_XPRS_mse_setintcontrol)
#define XPRS_mse_setsolbasename LLSL_DECL (*__symbolic_XPRS_mse_setsolbasename)
#define XPRS_msp_create LLSL_DECL (*__symbolic_XPRS_msp_create)
#define XPRS_msp_delsol LLSL_DECL (*__symbolic_XPRS_msp_delsol)
#define XPRS_msp_destroy LLSL_DECL (*__symbolic_XPRS_msp_destroy)
#define XPRS_msp_findsolbyname LLSL_DECL (*__symbolic_XPRS_msp_findsolbyname)
#define XPRS_msp_getdblattrib LLSL_DECL (*__symbolic_XPRS_msp_getdblattrib)
#define XPRS_msp_getdblattribprob LLSL_DECL (*__symbolic_XPRS_msp_getdblattribprob)
#define XPRS_msp_getdblattribprobextreme LLSL_DECL (*__symbolic_XPRS_msp_getdblattribprobextreme)
#define XPRS_msp_getdblattribprobsol LLSL_DECL (*__symbolic_XPRS_msp_getdblattribprobsol)
#define XPRS_msp_getdblattribsol LLSL_DECL (*__symbolic_XPRS_msp_getdblattribsol)
#define XPRS_msp_getdblcontrol LLSL_DECL (*__symbolic_XPRS_msp_getdblcontrol)
#define XPRS_msp_getdblcontrolsol LLSL_DECL (*__symbolic_XPRS_msp_getdblcontrolsol)
#define XPRS_msp_getintattrib LLSL_DECL (*__symbolic_XPRS_msp_getintattrib)
#define XPRS_msp_getintattribprob LLSL_DECL (*__symbolic_XPRS_msp_getintattribprob)
#define XPRS_msp_getintattribprobextreme LLSL_DECL (*__symbolic_XPRS_msp_getintattribprobextreme)
#define XPRS_msp_getintattribprobsol LLSL_DECL (*__symbolic_XPRS_msp_getintattribprobsol)
#define XPRS_msp_getintattribsol LLSL_DECL (*__symbolic_XPRS_msp_getintattribsol)
#define XPRS_msp_getintcontrol LLSL_DECL (*__symbolic_XPRS_msp_getintcontrol)
#define XPRS_msp_getintcontrolsol LLSL_DECL (*__symbolic_XPRS_msp_getintcontrolsol)
#define XPRS_msp_getlasterror LLSL_DECL (*__symbolic_XPRS_msp_getlasterror)
#define XPRS_msp_getsol LLSL_DECL (*__symbolic_XPRS_msp_getsol)
#define XPRS_msp_getsollist LLSL_DECL (*__symbolic_XPRS_msp_getsollist)
#define XPRS_msp_getsollist2 LLSL_DECL (*__symbolic_XPRS_msp_getsollist2)
#define XPRS_msp_getsolname LLSL_DECL (*__symbolic_XPRS_msp_getsolname)
#define XPRS_msp_loadsol LLSL_DECL (*__symbolic_XPRS_msp_loadsol)
#define XPRS_msp_probattach LLSL_DECL (*__symbolic_XPRS_msp_probattach)
#define XPRS_msp_probdetach LLSL_DECL (*__symbolic_XPRS_msp_probdetach)
#define XPRS_msp_readslxsol LLSL_DECL (*__symbolic_XPRS_msp_readslxsol)
#define XPRS_msp_setcbmsghandler LLSL_DECL (*__symbolic_XPRS_msp_setcbmsghandler)
#define XPRS_msp_setdblcontrol LLSL_DECL (*__symbolic_XPRS_msp_setdblcontrol)
#define XPRS_msp_setdblcontrolsol LLSL_DECL (*__symbolic_XPRS_msp_setdblcontrolsol)
#define XPRS_msp_setintcontrol LLSL_DECL (*__symbolic_XPRS_msp_setintcontrol)
#define XPRS_msp_setintcontrolsol LLSL_DECL (*__symbolic_XPRS_msp_setintcontrolsol)
#define XPRS_msp_setsolname LLSL_DECL (*__symbolic_XPRS_msp_setsolname)
#define XPRS_msp_writeslxsol LLSL_DECL (*__symbolic_XPRS_msp_writeslxsol)
#define XPRS_nml_addnames LLSL_DECL (*__symbolic_XPRS_nml_addnames)
#define XPRS_nml_copynames LLSL_DECL (*__symbolic_XPRS_nml_copynames)
#define XPRS_nml_create LLSL_DECL (*__symbolic_XPRS_nml_create)
#define XPRS_nml_destroy LLSL_DECL (*__symbolic_XPRS_nml_destroy)
#define XPRS_nml_findname LLSL_DECL (*__symbolic_XPRS_nml_findname)
#define XPRS_nml_getlasterror LLSL_DECL (*__symbolic_XPRS_nml_getlasterror)
#define XPRS_nml_getmaxnamelen LLSL_DECL (*__symbolic_XPRS_nml_getmaxnamelen)
#define XPRS_nml_getnamecount LLSL_DECL (*__symbolic_XPRS_nml_getnamecount)
#define XPRS_nml_getnames LLSL_DECL (*__symbolic_XPRS_nml_getnames)
#define XPRS_nml_removenames LLSL_DECL (*__symbolic_XPRS_nml_removenames)
#define XPRS_nml_setcbmsghandler LLSL_DECL (*__symbolic_XPRS_nml_setcbmsghandler)
#define XPRSobjsa LLSL_DECL (*__symbolic_XPRSobjsa)
#define XPRSpivot LLSL_DECL (*__symbolic_XPRSpivot)
#define XPRSpostsolve LLSL_DECL (*__symbolic_XPRSpostsolve)
#define XPRSpresolverow LLSL_DECL (*__symbolic_XPRSpresolverow)
#define XPRSrange LLSL_DECL (*__symbolic_XPRSrange)
#define XPRSreadbasis LLSL_DECL (*__symbolic_XPRSreadbasis)
#define XPRSreadbinsol LLSL_DECL (*__symbolic_XPRSreadbinsol)
#define XPRSreaddirs LLSL_DECL (*__symbolic_XPRSreaddirs)
#define XPRSreadprob LLSL_DECL (*__symbolic_XPRSreadprob)
#define XPRSreadslxsol LLSL_DECL (*__symbolic_XPRSreadslxsol)
#define XPRSrepairinfeas LLSL_DECL (*__symbolic_XPRSrepairinfeas)
#define XPRSrepairweightedinfeas LLSL_DECL (*__symbolic_XPRSrepairweightedinfeas)
#define XPRSresetnlp LLSL_DECL (*__symbolic_XPRSresetnlp)
#define XPRSrestore LLSL_DECL (*__symbolic_XPRSrestore)
#define XPRSrhssa LLSL_DECL (*__symbolic_XPRSrhssa)
#define XPRSsave LLSL_DECL (*__symbolic_XPRSsave)
#define XPRSscale LLSL_DECL (*__symbolic_XPRSscale)
#define XPRSsetbranchbounds LLSL_DECL (*__symbolic_XPRSsetbranchbounds)
#define XPRSsetbranchcuts LLSL_DECL (*__symbolic_XPRSsetbranchcuts)
#define XPRSsetcbbariteration LLSL_DECL (*__symbolic_XPRSsetcbbariteration)
#define XPRSsetcbbarlog LLSL_DECL (*__symbolic_XPRSsetcbbarlog)
#define XPRSsetcbchgbranch LLSL_DECL (*__symbolic_XPRSsetcbchgbranch)
#define XPRSsetcbchgbranchobject LLSL_DECL (*__symbolic_XPRSsetcbchgbranchobject)
#define XPRSsetcbchgnode LLSL_DECL (*__symbolic_XPRSsetcbchgnode)
#define XPRSsetcbcutlog LLSL_DECL (*__symbolic_XPRSsetcbcutlog)
#define XPRSsetcbcutmgr LLSL_DECL (*__symbolic_XPRSsetcbcutmgr)
#define XPRSsetcbdestroymt LLSL_DECL (*__symbolic_XPRSsetcbdestroymt)
#define XPRSsetcbestimate LLSL_DECL (*__symbolic_XPRSsetcbestimate)
#define XPRSsetcbgloballog LLSL_DECL (*__symbolic_XPRSsetcbgloballog)
#define XPRSsetcbinfnode LLSL_DECL (*__symbolic_XPRSsetcbinfnode)
#define XPRSsetcbintsol LLSL_DECL (*__symbolic_XPRSsetcbintsol)
#define XPRSsetcblplog LLSL_DECL (*__symbolic_XPRSsetcblplog)
#define XPRSsetcbmessage LLSL_DECL (*__symbolic_XPRSsetcbmessage)
#define XPRSsetcbmipthread LLSL_DECL (*__symbolic_XPRSsetcbmipthread)
#define XPRSsetcbnewnode LLSL_DECL (*__symbolic_XPRSsetcbnewnode)
#define XPRSsetcbnlpevaluate LLSL_DECL (*__symbolic_XPRSsetcbnlpevaluate)
#define XPRSsetcbnlpgradient LLSL_DECL (*__symbolic_XPRSsetcbnlpgradient)
#define XPRSsetcbnlphessian LLSL_DECL (*__symbolic_XPRSsetcbnlphessian)
#define XPRSsetcbnodecutoff LLSL_DECL (*__symbolic_XPRSsetcbnodecutoff)
#define XPRSsetcboptnode LLSL_DECL (*__symbolic_XPRSsetcboptnode)
#define XPRSsetcbpreintsol LLSL_DECL (*__symbolic_XPRSsetcbpreintsol)
#define XPRSsetcbprenode LLSL_DECL (*__symbolic_XPRSsetcbprenode)
#define XPRSsetcbsepnode LLSL_DECL (*__symbolic_XPRSsetcbsepnode)
#define XPRSsetdblcontrol LLSL_DECL (*__symbolic_XPRSsetdblcontrol)
#define XPRSsetdefaultcontrol LLSL_DECL (*__symbolic_XPRSsetdefaultcontrol)
#define XPRSsetdefaults LLSL_DECL (*__symbolic_XPRSsetdefaults)
#define XPRSsetindicators LLSL_DECL (*__symbolic_XPRSsetindicators)
#define XPRSsetintcontrol LLSL_DECL (*__symbolic_XPRSsetintcontrol)
#define XPRSsetlogfile LLSL_DECL (*__symbolic_XPRSsetlogfile)
#define XPRSsetmessagestatus LLSL_DECL (*__symbolic_XPRSsetmessagestatus)
#define XPRSsetprobname LLSL_DECL (*__symbolic_XPRSsetprobname)
#define XPRSsetstrcontrol LLSL_DECL (*__symbolic_XPRSsetstrcontrol)
#define XPRSstorebounds LLSL_DECL (*__symbolic_XPRSstorebounds)
#define XPRSstorecuts LLSL_DECL (*__symbolic_XPRSstorecuts)
#define XPRSwritebasis LLSL_DECL (*__symbolic_XPRSwritebasis)
#define XPRSwritebinsol LLSL_DECL (*__symbolic_XPRSwritebinsol)
#define XPRSwritedirs LLSL_DECL (*__symbolic_XPRSwritedirs)
#define XPRSwriteprob LLSL_DECL (*__symbolic_XPRSwriteprob)
#define XPRSwriteprtrange LLSL_DECL (*__symbolic_XPRSwriteprtrange)
#define XPRSwriteprtsol LLSL_DECL (*__symbolic_XPRSwriteprtsol)
#define XPRSwriterange LLSL_DECL (*__symbolic_XPRSwriterange)
#define XPRSwriteslxsol LLSL_DECL (*__symbolic_XPRSwriteslxsol)
#define XPRSwritesol LLSL_DECL (*__symbolic_XPRSwritesol)

#ifdef __cplusplus
}
#endif

#include <xprs.h>

#ifdef _WIN32
/*
 * Windows corner case:
 *
 * Beyond this point, LLSL_DECL, which normally expands as
 * __declspec(dllimport) in order to allow the user to import our dll,
 * must be redefined as nothing: we don't want this macro to propagate
 * in the C files.
 *
 * Obviously this issues a warning, but this should be harmless.
 */
#undef LLSL_DECL
#define LLSL_DECL
#endif

#endif /* LAZY_XPRS_H */

