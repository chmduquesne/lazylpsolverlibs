#ifndef LAZY_XPRS_H
#define LAZY_XPRS_H

#include <ltdl.h>
#include "lazy_loading_status.h"

/* handle to the library */
lt_dlhandle __xprs_handle;
/* loads the symbols */
int load_xprs_symbols();
/* unloads the symbols (if called as many times as loadSymbols) */
int unload_xprs_symbols();
/* prints what symbols ar missing */
void print_xprs_missing_symbols();

#define XPRSaddcols (*__symbolic_XPRSaddcols)
#define XPRSaddcuts (*__symbolic_XPRSaddcuts)
#define XPRSaddnames (*__symbolic_XPRSaddnames)
#define XPRSaddqmatrix (*__symbolic_XPRSaddqmatrix)
#define XPRSaddrows (*__symbolic_XPRSaddrows)
#define XPRSaddsetnames (*__symbolic_XPRSaddsetnames)
#define XPRSaddsets (*__symbolic_XPRSaddsets)
#define XPRSalter (*__symbolic_XPRSalter)
#define XPRSbasiscondition (*__symbolic_XPRSbasiscondition)
#define XPRSbeginlicensing (*__symbolic_XPRSbeginlicensing)
#define XPRS_bo_addbounds (*__symbolic_XPRS_bo_addbounds)
#define XPRS_bo_addbranches (*__symbolic_XPRS_bo_addbranches)
#define XPRS_bo_addcuts (*__symbolic_XPRS_bo_addcuts)
#define XPRS_bo_addrows (*__symbolic_XPRS_bo_addrows)
#define XPRS_bo_create (*__symbolic_XPRS_bo_create)
#define XPRS_bo_destroy (*__symbolic_XPRS_bo_destroy)
#define XPRS_bo_getbounds (*__symbolic_XPRS_bo_getbounds)
#define XPRS_bo_getbranches (*__symbolic_XPRS_bo_getbranches)
#define XPRS_bo_getid (*__symbolic_XPRS_bo_getid)
#define XPRS_bo_getlasterror (*__symbolic_XPRS_bo_getlasterror)
#define XPRS_bo_getrows (*__symbolic_XPRS_bo_getrows)
#define XPRS_bo_setcbmsghandler (*__symbolic_XPRS_bo_setcbmsghandler)
#define XPRS_bo_setpreferredbranch (*__symbolic_XPRS_bo_setpreferredbranch)
#define XPRS_bo_setpriority (*__symbolic_XPRS_bo_setpriority)
#define XPRS_bo_store (*__symbolic_XPRS_bo_store)
#define XPRSbtran (*__symbolic_XPRSbtran)
#define XPRSchgbounds (*__symbolic_XPRSchgbounds)
#define XPRSchgcoef (*__symbolic_XPRSchgcoef)
#define XPRSchgcoltype (*__symbolic_XPRSchgcoltype)
#define XPRSchgmcoef (*__symbolic_XPRSchgmcoef)
#define XPRSchgmqobj (*__symbolic_XPRSchgmqobj)
#define XPRSchgobj (*__symbolic_XPRSchgobj)
#define XPRSchgobjsense (*__symbolic_XPRSchgobjsense)
#define XPRSchgqobj (*__symbolic_XPRSchgqobj)
#define XPRSchgqrowcoeff (*__symbolic_XPRSchgqrowcoeff)
#define XPRSchgrhs (*__symbolic_XPRSchgrhs)
#define XPRSchgrhsrange (*__symbolic_XPRSchgrhsrange)
#define XPRSchgrowtype (*__symbolic_XPRSchgrowtype)
#define XPRScopycallbacks (*__symbolic_XPRScopycallbacks)
#define XPRScopycontrols (*__symbolic_XPRScopycontrols)
#define XPRScopyprob (*__symbolic_XPRScopyprob)
#define XPRScreateprob (*__symbolic_XPRScreateprob)
#define XPRSdelcols (*__symbolic_XPRSdelcols)
#define XPRSdelcpcuts (*__symbolic_XPRSdelcpcuts)
#define XPRSdelcuts (*__symbolic_XPRSdelcuts)
#define XPRSdelindicators (*__symbolic_XPRSdelindicators)
#define XPRSdelnode (*__symbolic_XPRSdelnode)
#define XPRSdelqmatrix (*__symbolic_XPRSdelqmatrix)
#define XPRSdelrows (*__symbolic_XPRSdelrows)
#define XPRSdelsets (*__symbolic_XPRSdelsets)
#define XPRSdestroyprob (*__symbolic_XPRSdestroyprob)
#define XPRSendlicensing (*__symbolic_XPRSendlicensing)
#define XPRSfixglobal (*__symbolic_XPRSfixglobal)
#define XPRSfixglobals (*__symbolic_XPRSfixglobals)
#define XPRSfree (*__symbolic_XPRSfree)
#define XPRSftran (*__symbolic_XPRSftran)
#define XPRS_ge_getlasterror (*__symbolic_XPRS_ge_getlasterror)
#define XPRS_ge_setcbmsghandler (*__symbolic_XPRS_ge_setcbmsghandler)
#define XPRSgetbanner (*__symbolic_XPRSgetbanner)
#define XPRSgetbasis (*__symbolic_XPRSgetbasis)
#define XPRSgetcbbariteration (*__symbolic_XPRSgetcbbariteration)
#define XPRSgetcbbarlog (*__symbolic_XPRSgetcbbarlog)
#define XPRSgetcbchgbranch (*__symbolic_XPRSgetcbchgbranch)
#define XPRSgetcbchgbranchobject (*__symbolic_XPRSgetcbchgbranchobject)
#define XPRSgetcbchgnode (*__symbolic_XPRSgetcbchgnode)
#define XPRSgetcbcutlog (*__symbolic_XPRSgetcbcutlog)
#define XPRSgetcbcutmgr (*__symbolic_XPRSgetcbcutmgr)
#define XPRSgetcbdestroymt (*__symbolic_XPRSgetcbdestroymt)
#define XPRSgetcbestimate (*__symbolic_XPRSgetcbestimate)
#define XPRSgetcbgloballog (*__symbolic_XPRSgetcbgloballog)
#define XPRSgetcbinfnode (*__symbolic_XPRSgetcbinfnode)
#define XPRSgetcbintsol (*__symbolic_XPRSgetcbintsol)
#define XPRSgetcblplog (*__symbolic_XPRSgetcblplog)
#define XPRSgetcbmessage (*__symbolic_XPRSgetcbmessage)
#define XPRSgetcbmipthread (*__symbolic_XPRSgetcbmipthread)
#define XPRSgetcbnewnode (*__symbolic_XPRSgetcbnewnode)
#define XPRSgetcbnlpevaluate (*__symbolic_XPRSgetcbnlpevaluate)
#define XPRSgetcbnlpgradient (*__symbolic_XPRSgetcbnlpgradient)
#define XPRSgetcbnlphessian (*__symbolic_XPRSgetcbnlphessian)
#define XPRSgetcbnodecutoff (*__symbolic_XPRSgetcbnodecutoff)
#define XPRSgetcboptnode (*__symbolic_XPRSgetcboptnode)
#define XPRSgetcbpreintsol (*__symbolic_XPRSgetcbpreintsol)
#define XPRSgetcbprenode (*__symbolic_XPRSgetcbprenode)
#define XPRSgetcbsepnode (*__symbolic_XPRSgetcbsepnode)
#define XPRSgetcoef (*__symbolic_XPRSgetcoef)
#define XPRSgetcolrange (*__symbolic_XPRSgetcolrange)
#define XPRSgetcols (*__symbolic_XPRSgetcols)
#define XPRSgetcoltype (*__symbolic_XPRSgetcoltype)
#define XPRSgetcpcutlist (*__symbolic_XPRSgetcpcutlist)
#define XPRSgetcpcuts (*__symbolic_XPRSgetcpcuts)
#define XPRSgetcutlist (*__symbolic_XPRSgetcutlist)
#define XPRSgetcutmap (*__symbolic_XPRSgetcutmap)
#define XPRSgetcutslack (*__symbolic_XPRSgetcutslack)
#define XPRSgetdaysleft (*__symbolic_XPRSgetdaysleft)
#define XPRSgetdblattrib (*__symbolic_XPRSgetdblattrib)
#define XPRSgetdblcontrol (*__symbolic_XPRSgetdblcontrol)
#define XPRSgetdirs (*__symbolic_XPRSgetdirs)
#define XPRSgetglobal (*__symbolic_XPRSgetglobal)
#define XPRSgetiis (*__symbolic_XPRSgetiis)
#define XPRSgetiisdata (*__symbolic_XPRSgetiisdata)
#define XPRSgetindex (*__symbolic_XPRSgetindex)
#define XPRSgetindicators (*__symbolic_XPRSgetindicators)
#define XPRSgetinfeas (*__symbolic_XPRSgetinfeas)
#define XPRSgetintattrib (*__symbolic_XPRSgetintattrib)
#define XPRSgetintcontrol (*__symbolic_XPRSgetintcontrol)
#define XPRSgetlasterror (*__symbolic_XPRSgetlasterror)
#define XPRSgetlb (*__symbolic_XPRSgetlb)
#define XPRSgetlicerrmsg (*__symbolic_XPRSgetlicerrmsg)
#define XPRSgetlpsol (*__symbolic_XPRSgetlpsol)
#define XPRSgetmessagestatus (*__symbolic_XPRSgetmessagestatus)
#define XPRSgetmipsol (*__symbolic_XPRSgetmipsol)
#define XPRSgetmqobj (*__symbolic_XPRSgetmqobj)
#define XPRSgetnamelist (*__symbolic_XPRSgetnamelist)
#define XPRSgetnamelistobject (*__symbolic_XPRSgetnamelistobject)
#define XPRSgetnames (*__symbolic_XPRSgetnames)
#define XPRSgetobj (*__symbolic_XPRSgetobj)
#define XPRSgetobjecttypename (*__symbolic_XPRSgetobjecttypename)
#define XPRSgetpivotorder (*__symbolic_XPRSgetpivotorder)
#define XPRSgetpivots (*__symbolic_XPRSgetpivots)
#define XPRSgetpresolvebasis (*__symbolic_XPRSgetpresolvebasis)
#define XPRSgetpresolvemap (*__symbolic_XPRSgetpresolvemap)
#define XPRSgetpresolvesol (*__symbolic_XPRSgetpresolvesol)
#define XPRSgetprobname (*__symbolic_XPRSgetprobname)
#define XPRSgetqobj (*__symbolic_XPRSgetqobj)
#define XPRSgetqrowcoeff (*__symbolic_XPRSgetqrowcoeff)
#define XPRSgetqrowqmatrix (*__symbolic_XPRSgetqrowqmatrix)
#define XPRSgetqrowqmatrixtriplets (*__symbolic_XPRSgetqrowqmatrixtriplets)
#define XPRSgetqrows (*__symbolic_XPRSgetqrows)
#define XPRSgetrhs (*__symbolic_XPRSgetrhs)
#define XPRSgetrhsrange (*__symbolic_XPRSgetrhsrange)
#define XPRSgetrowrange (*__symbolic_XPRSgetrowrange)
#define XPRSgetrows (*__symbolic_XPRSgetrows)
#define XPRSgetrowtype (*__symbolic_XPRSgetrowtype)
#define XPRSgetscaledinfeas (*__symbolic_XPRSgetscaledinfeas)
#define XPRSgetsol (*__symbolic_XPRSgetsol)
#define XPRSgetstrattrib (*__symbolic_XPRSgetstrattrib)
#define XPRSgetstrcontrol (*__symbolic_XPRSgetstrcontrol)
#define XPRSgetub (*__symbolic_XPRSgetub)
#define XPRSgetunbvec (*__symbolic_XPRSgetunbvec)
#define XPRSgetversion (*__symbolic_XPRSgetversion)
#define XPRSglobal (*__symbolic_XPRSglobal)
#define XPRSgoal (*__symbolic_XPRSgoal)
#define XPRSiisall (*__symbolic_XPRSiisall)
#define XPRSiisclear (*__symbolic_XPRSiisclear)
#define XPRSiisfirst (*__symbolic_XPRSiisfirst)
#define XPRSiisisolations (*__symbolic_XPRSiisisolations)
#define XPRSiisnext (*__symbolic_XPRSiisnext)
#define XPRSiisstatus (*__symbolic_XPRSiisstatus)
#define XPRSiiswrite (*__symbolic_XPRSiiswrite)
#define XPRSinit (*__symbolic_XPRSinit)
#define XPRSinitglobal (*__symbolic_XPRSinitglobal)
#define XPRSinitializenlphessian (*__symbolic_XPRSinitializenlphessian)
#define XPRSinitializenlphessian_indexpairs (*__symbolic_XPRSinitializenlphessian_indexpairs)
#define XPRSinterrupt (*__symbolic_XPRSinterrupt)
#define XPRSlicense (*__symbolic_XPRSlicense)
#define XPRSloadbasis (*__symbolic_XPRSloadbasis)
#define XPRSloadbranchdirs (*__symbolic_XPRSloadbranchdirs)
#define XPRSloadcuts (*__symbolic_XPRSloadcuts)
#define XPRSloaddelayedrows (*__symbolic_XPRSloaddelayedrows)
#define XPRSloaddirs (*__symbolic_XPRSloaddirs)
#define XPRSloadglobal (*__symbolic_XPRSloadglobal)
#define XPRSloadlp (*__symbolic_XPRSloadlp)
#define XPRSloadmipsol (*__symbolic_XPRSloadmipsol)
#define XPRSloadmodelcuts (*__symbolic_XPRSloadmodelcuts)
#define XPRSloadpresolvebasis (*__symbolic_XPRSloadpresolvebasis)
#define XPRSloadpresolvedirs (*__symbolic_XPRSloadpresolvedirs)
#define XPRSloadqcqp (*__symbolic_XPRSloadqcqp)
#define XPRSloadqcqpglobal (*__symbolic_XPRSloadqcqpglobal)
#define XPRSloadqglobal (*__symbolic_XPRSloadqglobal)
#define XPRSloadqp (*__symbolic_XPRSloadqp)
#define XPRSloadsecurevecs (*__symbolic_XPRSloadsecurevecs)
#define XPRSlogfilehandler (*__symbolic_XPRSlogfilehandler)
#define XPRSlpoptimize (*__symbolic_XPRSlpoptimize)
#define XPRSmaxim (*__symbolic_XPRSmaxim)
#define XPRSminim (*__symbolic_XPRSminim)
#define XPRSmipoptimize (*__symbolic_XPRSmipoptimize)
#define XPRS_mse_create (*__symbolic_XPRS_mse_create)
#define XPRS_mse_destroy (*__symbolic_XPRS_mse_destroy)
#define XPRS_mse_getcbgetsolutiondiff (*__symbolic_XPRS_mse_getcbgetsolutiondiff)
#define XPRS_mse_getcullchoice (*__symbolic_XPRS_mse_getcullchoice)
#define XPRS_mse_getdblattrib (*__symbolic_XPRS_mse_getdblattrib)
#define XPRS_mse_getdblcontrol (*__symbolic_XPRS_mse_getdblcontrol)
#define XPRS_mse_getintattrib (*__symbolic_XPRS_mse_getintattrib)
#define XPRS_mse_getintcontrol (*__symbolic_XPRS_mse_getintcontrol)
#define XPRS_mse_getlasterror (*__symbolic_XPRS_mse_getlasterror)
#define XPRS_mse_getsolbasename (*__symbolic_XPRS_mse_getsolbasename)
#define XPRS_mse_getsollist (*__symbolic_XPRS_mse_getsollist)
#define XPRS_mse_getsolmetric (*__symbolic_XPRS_mse_getsolmetric)
#define XPRS_mse_maxim (*__symbolic_XPRS_mse_maxim)
#define XPRS_mse_minim (*__symbolic_XPRS_mse_minim)
#define XPRS_mse_opt (*__symbolic_XPRS_mse_opt)
#define XPRS_mse_setcbgetsolutiondiff (*__symbolic_XPRS_mse_setcbgetsolutiondiff)
#define XPRS_mse_setcbmsghandler (*__symbolic_XPRS_mse_setcbmsghandler)
#define XPRS_mse_setdblcontrol (*__symbolic_XPRS_mse_setdblcontrol)
#define XPRS_mse_setintcontrol (*__symbolic_XPRS_mse_setintcontrol)
#define XPRS_mse_setsolbasename (*__symbolic_XPRS_mse_setsolbasename)
#define XPRS_msp_create (*__symbolic_XPRS_msp_create)
#define XPRS_msp_delsol (*__symbolic_XPRS_msp_delsol)
#define XPRS_msp_destroy (*__symbolic_XPRS_msp_destroy)
#define XPRS_msp_findsolbyname (*__symbolic_XPRS_msp_findsolbyname)
#define XPRS_msp_getdblattrib (*__symbolic_XPRS_msp_getdblattrib)
#define XPRS_msp_getdblattribprob (*__symbolic_XPRS_msp_getdblattribprob)
#define XPRS_msp_getdblattribprobextreme (*__symbolic_XPRS_msp_getdblattribprobextreme)
#define XPRS_msp_getdblattribprobsol (*__symbolic_XPRS_msp_getdblattribprobsol)
#define XPRS_msp_getdblattribsol (*__symbolic_XPRS_msp_getdblattribsol)
#define XPRS_msp_getdblcontrol (*__symbolic_XPRS_msp_getdblcontrol)
#define XPRS_msp_getdblcontrolsol (*__symbolic_XPRS_msp_getdblcontrolsol)
#define XPRS_msp_getintattrib (*__symbolic_XPRS_msp_getintattrib)
#define XPRS_msp_getintattribprob (*__symbolic_XPRS_msp_getintattribprob)
#define XPRS_msp_getintattribprobextreme (*__symbolic_XPRS_msp_getintattribprobextreme)
#define XPRS_msp_getintattribprobsol (*__symbolic_XPRS_msp_getintattribprobsol)
#define XPRS_msp_getintattribsol (*__symbolic_XPRS_msp_getintattribsol)
#define XPRS_msp_getintcontrol (*__symbolic_XPRS_msp_getintcontrol)
#define XPRS_msp_getintcontrolsol (*__symbolic_XPRS_msp_getintcontrolsol)
#define XPRS_msp_getlasterror (*__symbolic_XPRS_msp_getlasterror)
#define XPRS_msp_getsol (*__symbolic_XPRS_msp_getsol)
#define XPRS_msp_getsollist (*__symbolic_XPRS_msp_getsollist)
#define XPRS_msp_getsollist2 (*__symbolic_XPRS_msp_getsollist2)
#define XPRS_msp_getsolname (*__symbolic_XPRS_msp_getsolname)
#define XPRS_msp_loadsol (*__symbolic_XPRS_msp_loadsol)
#define XPRS_msp_probattach (*__symbolic_XPRS_msp_probattach)
#define XPRS_msp_probdetach (*__symbolic_XPRS_msp_probdetach)
#define XPRS_msp_readslxsol (*__symbolic_XPRS_msp_readslxsol)
#define XPRS_msp_setcbmsghandler (*__symbolic_XPRS_msp_setcbmsghandler)
#define XPRS_msp_setdblcontrol (*__symbolic_XPRS_msp_setdblcontrol)
#define XPRS_msp_setdblcontrolsol (*__symbolic_XPRS_msp_setdblcontrolsol)
#define XPRS_msp_setintcontrol (*__symbolic_XPRS_msp_setintcontrol)
#define XPRS_msp_setintcontrolsol (*__symbolic_XPRS_msp_setintcontrolsol)
#define XPRS_msp_setsolname (*__symbolic_XPRS_msp_setsolname)
#define XPRS_msp_writeslxsol (*__symbolic_XPRS_msp_writeslxsol)
#define XPRS_nml_addnames (*__symbolic_XPRS_nml_addnames)
#define XPRS_nml_copynames (*__symbolic_XPRS_nml_copynames)
#define XPRS_nml_create (*__symbolic_XPRS_nml_create)
#define XPRS_nml_destroy (*__symbolic_XPRS_nml_destroy)
#define XPRS_nml_findname (*__symbolic_XPRS_nml_findname)
#define XPRS_nml_getlasterror (*__symbolic_XPRS_nml_getlasterror)
#define XPRS_nml_getmaxnamelen (*__symbolic_XPRS_nml_getmaxnamelen)
#define XPRS_nml_getnamecount (*__symbolic_XPRS_nml_getnamecount)
#define XPRS_nml_getnames (*__symbolic_XPRS_nml_getnames)
#define XPRS_nml_removenames (*__symbolic_XPRS_nml_removenames)
#define XPRS_nml_setcbmsghandler (*__symbolic_XPRS_nml_setcbmsghandler)
#define XPRSobjsa (*__symbolic_XPRSobjsa)
#define XPRSpivot (*__symbolic_XPRSpivot)
#define XPRSpostsolve (*__symbolic_XPRSpostsolve)
#define XPRSpresolverow (*__symbolic_XPRSpresolverow)
#define XPRSrange (*__symbolic_XPRSrange)
#define XPRSreadbasis (*__symbolic_XPRSreadbasis)
#define XPRSreadbinsol (*__symbolic_XPRSreadbinsol)
#define XPRSreaddirs (*__symbolic_XPRSreaddirs)
#define XPRSreadprob (*__symbolic_XPRSreadprob)
#define XPRSreadslxsol (*__symbolic_XPRSreadslxsol)
#define XPRSrepairinfeas (*__symbolic_XPRSrepairinfeas)
#define XPRSrepairweightedinfeas (*__symbolic_XPRSrepairweightedinfeas)
#define XPRSresetnlp (*__symbolic_XPRSresetnlp)
#define XPRSrestore (*__symbolic_XPRSrestore)
#define XPRSrhssa (*__symbolic_XPRSrhssa)
#define XPRSsave (*__symbolic_XPRSsave)
#define XPRSscale (*__symbolic_XPRSscale)
#define XPRSsetbranchbounds (*__symbolic_XPRSsetbranchbounds)
#define XPRSsetbranchcuts (*__symbolic_XPRSsetbranchcuts)
#define XPRSsetcbbariteration (*__symbolic_XPRSsetcbbariteration)
#define XPRSsetcbbarlog (*__symbolic_XPRSsetcbbarlog)
#define XPRSsetcbchgbranch (*__symbolic_XPRSsetcbchgbranch)
#define XPRSsetcbchgbranchobject (*__symbolic_XPRSsetcbchgbranchobject)
#define XPRSsetcbchgnode (*__symbolic_XPRSsetcbchgnode)
#define XPRSsetcbcutlog (*__symbolic_XPRSsetcbcutlog)
#define XPRSsetcbcutmgr (*__symbolic_XPRSsetcbcutmgr)
#define XPRSsetcbdestroymt (*__symbolic_XPRSsetcbdestroymt)
#define XPRSsetcbestimate (*__symbolic_XPRSsetcbestimate)
#define XPRSsetcbgloballog (*__symbolic_XPRSsetcbgloballog)
#define XPRSsetcbinfnode (*__symbolic_XPRSsetcbinfnode)
#define XPRSsetcbintsol (*__symbolic_XPRSsetcbintsol)
#define XPRSsetcblplog (*__symbolic_XPRSsetcblplog)
#define XPRSsetcbmessage (*__symbolic_XPRSsetcbmessage)
#define XPRSsetcbmipthread (*__symbolic_XPRSsetcbmipthread)
#define XPRSsetcbnewnode (*__symbolic_XPRSsetcbnewnode)
#define XPRSsetcbnlpevaluate (*__symbolic_XPRSsetcbnlpevaluate)
#define XPRSsetcbnlpgradient (*__symbolic_XPRSsetcbnlpgradient)
#define XPRSsetcbnlphessian (*__symbolic_XPRSsetcbnlphessian)
#define XPRSsetcbnodecutoff (*__symbolic_XPRSsetcbnodecutoff)
#define XPRSsetcboptnode (*__symbolic_XPRSsetcboptnode)
#define XPRSsetcbpreintsol (*__symbolic_XPRSsetcbpreintsol)
#define XPRSsetcbprenode (*__symbolic_XPRSsetcbprenode)
#define XPRSsetcbsepnode (*__symbolic_XPRSsetcbsepnode)
#define XPRSsetdblcontrol (*__symbolic_XPRSsetdblcontrol)
#define XPRSsetdefaultcontrol (*__symbolic_XPRSsetdefaultcontrol)
#define XPRSsetdefaults (*__symbolic_XPRSsetdefaults)
#define XPRSsetindicators (*__symbolic_XPRSsetindicators)
#define XPRSsetintcontrol (*__symbolic_XPRSsetintcontrol)
#define XPRSsetlogfile (*__symbolic_XPRSsetlogfile)
#define XPRSsetmessagestatus (*__symbolic_XPRSsetmessagestatus)
#define XPRSsetprobname (*__symbolic_XPRSsetprobname)
#define XPRSsetstrcontrol (*__symbolic_XPRSsetstrcontrol)
#define XPRSstorebounds (*__symbolic_XPRSstorebounds)
#define XPRSstorecuts (*__symbolic_XPRSstorecuts)
#define XPRSwritebasis (*__symbolic_XPRSwritebasis)
#define XPRSwritebinsol (*__symbolic_XPRSwritebinsol)
#define XPRSwritedirs (*__symbolic_XPRSwritedirs)
#define XPRSwriteprob (*__symbolic_XPRSwriteprob)
#define XPRSwriteprtrange (*__symbolic_XPRSwriteprtrange)
#define XPRSwriteprtsol (*__symbolic_XPRSwriteprtsol)
#define XPRSwriterange (*__symbolic_XPRSwriterange)
#define XPRSwriteslxsol (*__symbolic_XPRSwriteslxsol)
#define XPRSwritesol (*__symbolic_XPRSwritesol)


#include <xprs.h>

#endif /* LAZY_XPRS_H */

