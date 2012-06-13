#ifndef _XPRS_H
#define _XPRS_H

/*
 * This header was partly generated from a solver header of the same name,
 * to make lazylpsolverlibs callable. It contains only constants,
 * structures, and macros generated from the original header, and thus,
 * contains no copyrightable information.
 *
 * Additionnal hand editing was also probably performed.
 */

#ifdef _WIN32
#define XPRS_CC __stdcall
#else
#define XPRS_CC
#endif
typedef struct XPRSobject_s *XPRSobject;
typedef struct xo_prob_struct *XPRSprob;
typedef struct XPRSglobalenv_s *XPRSglobalenv;
typedef struct XPRSmipsolpool_s *XPRSmipsolpool;
typedef struct XPRSmessagingadmin_s *XPRSmessagingadmin;
typedef struct xo_NameList *XPRSnamelist;
typedef struct XPRSmipsolenum_s *XPRSmipsolenum;
typedef struct XPRSprobperturber_s *XPRSprobperturber;
typedef struct xo_user_branch_entity_s *XPRSbranchobject;
typedef struct PoolCut *XPRScut;
#define XPRS_PLUSINFINITY 1.0e+20
#define XPRS_MINUSINFINITY -1.0e+20
#define XPRS_MAXINT 2147483647
#define XPRS_OBJ_MINIMIZE 1
#define XPRS_OBJ_MAXIMIZE -1
#define XPVERSION 20
#define XPRS_MPSRHSNAME 6001
#define XPRS_MPSOBJNAME 6002
#define XPRS_MPSRANGENAME 6003
#define XPRS_MPSBOUNDNAME 6004
#define XPRS_OUTPUTMASK 6005
#define XPRS_MATRIXTOL 7001
#define XPRS_PIVOTTOL 7002
#define XPRS_FEASTOL 7003
#define XPRS_OUTPUTTOL 7004
#define XPRS_SOSREFTOL 7005
#define XPRS_OPTIMALITYTOL 7006
#define XPRS_ETATOL 7007
#define XPRS_RELPIVOTTOL 7008
#define XPRS_MIPTOL 7009
#define XPRS_DEGRADEFACTOR 7010
#define XPRS_MIPTARGET 7011
#define XPRS_MIPADDCUTOFF 7012
#define XPRS_MIPABSCUTOFF 7013
#define XPRS_MIPRELCUTOFF 7014
#define XPRS_PSEUDOCOST 7015
#define XPRS_PENALTY 7016
#define XPRS_BIGM 7018
#define XPRS_MIPABSSTOP 7019
#define XPRS_MIPRELSTOP 7020
#define XPRS_CHOLESKYTOL 7032
#define XPRS_BARGAPSTOP 7033
#define XPRS_BARDUALSTOP 7034
#define XPRS_BARPRIMALSTOP 7035
#define XPRS_BARSTEPSTOP 7036
#define XPRS_ELIMTOL 7042
#define XPRS_PERTURB 7044
#define XPRS_MARKOWITZTOL 7047
#define XPRS_PPFACTOR 7069
#define XPRS_SBEFFORT 7086
#define XPRS_HEURDIVERANDOMIZE 7089
#define XPRS_HEURSEARCHEFFORT 7090
#define XPRS_CUTFACTOR 7091
#define XPRS_EIGENVALUETOL 7097
#define XPRS_INDLINBIGM 7099
#define XPRS_TREEMEMORYSAVINGTARGET 7100
#define XPRS_GLOBALFILEBIAS 7101
#define XPRS_EXTRAROWS 8004
#define XPRS_EXTRACOLS 8005
#define XPRS_EXTRAELEMS 8006
#define XPRS_LPITERLIMIT 8007
#define XPRS_LPLOG 8009
#define XPRS_SCALING 8010
#define XPRS_PRESOLVE 8011
#define XPRS_CRASH 8012
#define XPRS_PRICINGALG 8013
#define XPRS_INVERTFREQ 8014
#define XPRS_INVERTMIN 8015
#define XPRS_MAXNODE 8018
#define XPRS_MAXTIME 8020
#define XPRS_MAXMIPSOL 8021
#define XPRS_KEEPMIPSOL 8022
#define XPRS_DEFAULTALG 8023
#define XPRS_VARSELECTION 8025
#define XPRS_NODESELECTION 8026
#define XPRS_BACKTRACK 8027
#define XPRS_MIPLOG 8028
#define XPRS_KEEPNROWS 8030
#define XPRS_MPSECHO 8032
#define XPRS_MAXPAGELINES 8034
#define XPRS_OUTPUTLOG 8035
#define XPRS_EXTRAPRESOLVE 8037
#define XPRS_CACHESIZE 8043
#define XPRS_CROSSOVER 8044
#define XPRS_BARITERLIMIT 8045
#define XPRS_CHOLESKYALG 8046
#define XPRS_BAROUTPUT 8047
#define XPRS_CSTYLE 8050
#define XPRS_EXTRAMIPENTS 8051
#define XPRS_REFACTOR 8052
#define XPRS_BARTHREADS 8053
#define XPRS_KEEPBASIS 8054
#define XPRS_VERSION 8061
#define XPRS_BIGMMETHOD 8068
#define XPRS_MPSNAMELENGTH 8071
#define XPRS_SOLUTIONFILE 8072
#define XPRS_PRESOLVEOPS 8077
#define XPRS_MIPPRESOLVE 8078
#define XPRS_MIPTHREADS 8079
#define XPRS_BARORDER 8080
#define XPRS_BREADTHFIRST 8082
#define XPRS_AUTOPERTURB 8084
#define XPRS_DENSECOLLIMIT 8086
#define XPRS_CUTFREQ 8116
#define XPRS_TRACE 8130
#define XPRS_MAXIIS 8131
#define XPRS_CPUTIME 8133
#define XPRS_COVERCUTS 8134
#define XPRS_GOMCUTS 8135
#define XPRS_MPSFORMAT 8137
#define XPRS_CUTSTRATEGY 8138
#define XPRS_CUTDEPTH 8139
#define XPRS_TREECOVERCUTS 8140
#define XPRS_TREEGOMCUTS 8141
#define XPRS_CUTSELECT 8142
#define XPRS_TREECUTSELECT 8143
#define XPRS_DUALIZE 8144
#define XPRS_DUALGRADIENT 8145
#define XPRS_SBITERLIMIT 8146
#define XPRS_SBBEST 8147
#define XPRS_MAXCUTTIME 8149
#define XPRS_ACTIVESET 8152
#define XPRS_BARINDEFLIMIT 8153
#define XPRS_HEURSTRATEGY 8154
#define XPRS_HEURFREQ 8155
#define XPRS_HEURDEPTH 8156
#define XPRS_HEURMAXSOL 8157
#define XPRS_HEURNODES 8158
#define XPRS_LNPBEST 8160
#define XPRS_LNPITERLIMIT 8161
#define XPRS_BRANCHCHOICE 8162
#define XPRS_SBSELECT 8164
#define XPRS_LOCALCHOICE 8170
#define XPRS_LOCALBACKTRACK 8171
#define XPRS_DUALSTRATEGY 8174
#define XPRS_L1CACHE 8175
#define XPRS_HEURDIVESTRATEGY 8177
#define XPRS_HEURSELECT 8178
#define XPRS_BARSTART 8180
#define XPRS_EXTRASETS 8190
#define XPRS_EXTRASETELEMS 8191
#define XPRS_FEASIBILITYPUMP 8193
#define XPRS_PRECOEFELIM 8194
#define XPRS_PREDOMCOL 8195
#define XPRS_HEURSEARCHFREQ 8196
#define XPRS_HEURDIVESPEEDUP 8197
#define XPRS_SBESTIMATE 8198
#define XPRS_HISTORYCOSTS 8206
#define XPRS_ALGAFTERCROSSOVER 8208
#define XPRS_LINELENGTH 8209
#define XPRS_MUTEXCALLBACKS 8210
#define XPRS_BARCRASH 8211
#define XPRS_HEURSEARCHROOTSELECT 8216
#define XPRS_HEURSEARCHTREESELECT 8217
#define XPRS_MPS18COMPATIBLE 8223
#define XPRS_ROOTPRESOLVE 8224
#define XPRS_CROSSOVERDRP 8227
#define XPRS_FORCEOUTPUT 8229
#define XPRS_DETERMINISTIC 8232
#define XPRS_PREPROBING 8238
#define XPRS_EXTRAQCELEMENTS 8240
#define XPRS_EXTRAQCROWS 8241
#define XPRS_TREEMEMORYLIMIT 8242
#define XPRS_TREECOMPRESSION 8243
#define XPRS_TREEDIAGNOSTICS 8244
#define XPRS_MAXGLOBALFILESIZE 8245
#define XPRS_TEMPBOUNDS 8250
#define XPRS_IFCHECKCONVEXITY 8251
#define XPRS_PRIMALUNSHIFT 8252
#define XPRS_REPAIRINDEFINITEQ 8254
#define XPRS_MAXLOCALBACKTRACK 8257
#define XPRS_BACKTRACKTIE 8266
#define XPRS_BRANCHDISJ 8267
#define XPRS_LPTHREADS 8274
#define XPRS_MAXSCALEFACTOR 8275
#define XPRS_HEURTHREADS 8276
#define XPRS_THREADS 8278
#define XPRS_PREDOMROW 8281
#define XPRS_BRANCHSTRUCTURAL 8282
#define XPRS_QUADRATICUNSHIFT 8284
#define XPRS_BARPRESOLVEOPS 8286
#define XPRS_MATRIXNAME 3001
#define XPRS_BOUNDNAME 3002
#define XPRS_OBJNAME 3003
#define XPRS_RHSNAME 3004
#define XPRS_RANGENAME 3005
#define XPRS_LPOBJVAL 2001
#define XPRS_SUMPRIMALINF 2002
#define XPRS_MIPOBJVAL 2003
#define XPRS_BESTBOUND 2004
#define XPRS_OBJRHS 2005
#define XPRS_OBJSENSE 2008
#define XPRS_BRANCHVALUE 2009
#define XPRS_PENALTYVALUE 2061
#define XPRS_CURRMIPCUTOFF 2062
#define XPRS_BARPRIMALOBJ 4001
#define XPRS_BARDUALOBJ 4002
#define XPRS_BARPRIMALINF 4003
#define XPRS_BARDUALINF 4004
#define XPRS_BARCGAP 4005
#define XPRS_ROWS 1001
#define XPRS_SETS 1004
#define XPRS_SETMEMBERS 1005
#define XPRS_ELEMS 1006
#define XPRS_PRIMALINFEAS 1007
#define XPRS_DUALINFEAS 1008
#define XPRS_SIMPLEXITER 1009
#define XPRS_LPSTATUS 1010
#define XPRS_MIPSTATUS 1011
#define XPRS_CUTS 1012
#define XPRS_NODES 1013
#define XPRS_NODEDEPTH 1014
#define XPRS_ACTIVENODES 1015
#define XPRS_MIPSOLNODE 1016
#define XPRS_MIPSOLS 1017
#define XPRS_COLS 1018
#define XPRS_SPAREROWS 1019
#define XPRS_SPARECOLS 1020
#define XPRS_SPAREELEMS 1021
#define XPRS_SPAREMIPENTS 1022
#define XPRS_ERRORCODE 1023
#define XPRS_MIPINFEAS 1024
#define XPRS_PRESOLVESTATE 1026
#define XPRS_PARENTNODE 1027
#define XPRS_NAMELENGTH 1028
#define XPRS_QELEMS 1030
#define XPRS_NUMIIS 1031
#define XPRS_MIPENTS 1032
#define XPRS_BRANCHVAR 1036
#define XPRS_MIPTHREADID 1037
#define XPRS_ORIGINALROWS 1124
#define XPRS_STOPSTATUS 1179
#define XPRS_SPARESETS 1203
#define XPRS_SPARESETELEMS 1204
#define XPRS_ORIGINALCOLS 1214
#define XPRS_QCELEMS 1232
#define XPRS_QCONSTRAINTS 1234
#define XPRS_NLPHESSIANELEMS 1243
#define XPRS_CURRENTNODE 1248
#define XPRS_TREEMEMORYUSAGE 1251
#define XPRS_GLOBALFILESIZE 1252
#define XPRS_GLOBALFILEUSAGE 1253
#define XPRS_INDICATORS 1254
#define XPRS_CORESDETECTED 1260
#define XPRS_BARITER 5001
#define XPRS_BARAASIZE 5002
#define XPRS_BARLSIZE 5003
#define XPRS_BARDENSECOL 5004
#define XPRS_BARCROSSOVER 5005
#define XPRS_IIS 1031
#define XPRS_MSP_DEFAULTUSERSOLFEASTOL 6209
#define XPRS_MSP_DEFAULTUSERSOLMIPTOL 6210
#define XPRS_MSP_SOL_FEASTOL 6402
#define XPRS_MSP_SOL_MIPTOL 6403
#define XPRS_MSP_DUPLICATESOLUTIONSPOLICY 6203
#define XPRS_MSP_INCLUDEPROBNAMEINLOGGING 6211
#define XPRS_MSP_WRITESLXSOLLOGGING 6212
#define XPRS_MSP_SOL_BITFIELDSUSR 6406
#define XPRS_MSP_SOLPRB_OBJ 6500
#define XPRS_MSP_SOLPRB_INFSUM_PRIMAL 6502
#define XPRS_MSP_SOLPRB_INFSUM_MIP 6504
#define XPRS_MSP_SOLPRB_INFSUM_SLACK 6506
#define XPRS_MSP_SOLPRB_INFMAX_SLACK 6508
#define XPRS_MSP_SOLPRB_INFSUM_COLUMN 6510
#define XPRS_MSP_SOLPRB_INFMAX_COLUMN 6512
#define XPRS_MSP_SOLPRB_INFSUM_DELAYEDROW 6514
#define XPRS_MSP_SOLPRB_INFMAX_DELAYEDROW 6516
#define XPRS_MSP_SOLPRB_INFSUM_INT 6518
#define XPRS_MSP_SOLPRB_INFMAX_INT 6520
#define XPRS_MSP_SOLPRB_INFSUM_BIN 6522
#define XPRS_MSP_SOLPRB_INFMAX_BIN 6524
#define XPRS_MSP_SOLPRB_INFSUM_SC 6526
#define XPRS_MSP_SOLPRB_INFMAX_SC 6528
#define XPRS_MSP_SOLPRB_INFSUM_SI 6530
#define XPRS_MSP_SOLPRB_INFMAX_SI 6532
#define XPRS_MSP_SOLPRB_INFSUM_PI 6534
#define XPRS_MSP_SOLPRB_INFMAX_PI 6536
#define XPRS_MSP_SOLPRB_INFSUM_SET1 6538
#define XPRS_MSP_SOLPRB_INFMAX_SET1 6540
#define XPRS_MSP_SOLPRB_INFSUM_SET2 6542
#define XPRS_MSP_SOLPRB_INFMAX_SET2 6544
#define XPRS_MSP_SOLUTIONS 6208
#define XPRS_MSP_PRB_VALIDSOLS 6300
#define XPRS_MSP_PRB_FEASIBLESOLS 6301
#define XPRS_MSP_SOL_COLS 6400
#define XPRS_MSP_SOL_NONZEROS 6401
#define XPRS_MSP_SOL_ISUSERSOLUTION 6404
#define XPRS_MSP_SOL_ISREPROCESSEDUSERSOLUTION 6405
#define XPRS_MSP_SOL_BITFIELDSSYS 6407
#define XPRS_MSP_SOLPRB_INFEASCOUNT 6501
#define XPRS_MSP_SOLPRB_INFCNT_PRIMAL 6503
#define XPRS_MSP_SOLPRB_INFCNT_MIP 6505
#define XPRS_MSP_SOLPRB_INFCNT_SLACK 6507
#define XPRS_MSP_SOLPRB_INFMXI_SLACK 6509
#define XPRS_MSP_SOLPRB_INFCNT_COLUMN 6511
#define XPRS_MSP_SOLPRB_INFMXI_COLUMN 6513
#define XPRS_MSP_SOLPRB_INFCNT_DELAYEDROW 6515
#define XPRS_MSP_SOLPRB_INFMXI_DELAYEDROW 6517
#define XPRS_MSP_SOLPRB_INFCNT_INT 6519
#define XPRS_MSP_SOLPRB_INFMXI_INT 6521
#define XPRS_MSP_SOLPRB_INFCNT_BIN 6523
#define XPRS_MSP_SOLPRB_INFMXI_BIN 6525
#define XPRS_MSP_SOLPRB_INFCNT_SC 6527
#define XPRS_MSP_SOLPRB_INFMXI_SC 6529
#define XPRS_MSP_SOLPRB_INFCNT_SI 6531
#define XPRS_MSP_SOLPRB_INFMXI_SI 6533
#define XPRS_MSP_SOLPRB_INFCNT_PI 6535
#define XPRS_MSP_SOLPRB_INFMXI_PI 6537
#define XPRS_MSP_SOLPRB_INFCNT_SET1 6539
#define XPRS_MSP_SOLPRB_INFMXI_SET1 6541
#define XPRS_MSP_SOLPRB_INFCNT_SET2 6543
#define XPRS_MSP_SOLPRB_INFMXI_SET2 6545
#define XPRS_MSE_OUTPUTTOL 6609
#define XPRS_MSE_CALLBACKCULLSOLS_MIPOBJECT 6601
#define XPRS_MSE_CALLBACKCULLSOLS_DIVERSITY 6602
#define XPRS_MSE_CALLBACKCULLSOLS_MODOBJECT 6603
#define XPRS_MSE_OPTIMIZEDIVERSITY 6607
#define XPRS_MSE_DIVERSITYSUM 6608
#define XPRS_MSE_SOLUTIONS 6600
#define XPRS_MSE_METRIC_MIPOBJECT 6604
#define XPRS_MSE_METRIC_DIVERSITY 6605
#define XPRS_MSE_METRIC_MODOBJECT 6606
#define XPRS_PTB_PERMUTE_INTENSITY_ROW 6702
#define XPRS_PTB_PERMUTE_INTENSITY_COL 6703
#define XPRS_PTB_SHIFTSCALE_COLS_INTENSITY 6722
#define XPRS_PTB_PERMUTE_ACTIVE 6700
#define XPRS_PTB_PERMUTE_SEEDLAST 6701
#define XPRS_PTB_PERTURB_COST2_ACTIVE 6710
#define XPRS_PTB_PERTURB_COST2_SEEDLAST 6711
#define XPRS_PTB_SHIFTSCALE_COLS_ACTIVE 6720
#define XPRS_PTB_SHIFTSCALE_COLS_SEEDLAST 6721
#define XPRS_PTB_PERTURB_COST2_TOTALABSCOSTCHANGE 6713
#define XPRS_PTB_SHIFTSCALE_COLS_FIXEDOBJDELTA 6724
#define XPRS_PTB_PERMUTE_PERMCOUNT_ROW 6704
#define XPRS_PTB_PERMUTE_PERMCOUNT_COL 6705
#define XPRS_PTB_PERTURB_COST2_CHANGEDCOLCOUNT 6712
#define XPRS_PTB_SHIFTSCALE_COLS_CHANGEDCOLCOUNT 6723
#define XPRS_LP_UNSTARTED 0
#define XPRS_LP_OPTIMAL 1
#define XPRS_LP_INFEAS 2
#define XPRS_LP_CUTOFF 3
#define XPRS_LP_UNFINISHED 4
#define XPRS_LP_UNBOUNDED 5
#define XPRS_LP_CUTOFF_IN_DUAL 6
#define XPRS_LP_UNSOLVED 7
#define XPRS_LP_NONCONVEX 8
#define XPRS_MIP_NOT_LOADED 0
#define XPRS_MIP_LP_NOT_OPTIMAL 1
#define XPRS_MIP_LP_OPTIMAL 2
#define XPRS_MIP_NO_SOL_FOUND 3
#define XPRS_MIP_SOLUTION 4
#define XPRS_MIP_INFEAS 5
#define XPRS_MIP_OPTIMAL 6
#define XPRS_BAR_DEFAULT 0
#define XPRS_BAR_MIN_DEGREE 1
#define XPRS_BAR_MIN_LOCAL_FILL 2
#define XPRS_BAR_NESTED_DISSECTION 3
#define XPRS_ALG_DEFAULT 1
#define XPRS_ALG_DUAL 2
#define XPRS_ALG_PRIMAL 3
#define XPRS_ALG_BARRIER 4
#define XPRS_STOP_TIMELIMIT 1
#define XPRS_STOP_CTRLC 2
#define XPRS_STOP_NODELIMIT 3
#define XPRS_STOP_ITERLIMIT 4
#define XPRS_STOP_MIPGAP 5
#define XPRS_STOP_SOLLIMIT 6
#define XPRS_STOP_USER 9
#define XPRS_ISUSERSOLUTION 0x1
#define XPRS_ISREPROCESSEDUSERSOLUTION 0x2
#ifdef __cplusplus
extern "C"
{
#endif
  int XPRS_CC XPRScopycallbacks (XPRSprob dest, XPRSprob src);
  int XPRS_CC XPRScopycontrols (XPRSprob dest, XPRSprob src);
  int XPRS_CC XPRScopyprob (XPRSprob dest, XPRSprob src,
                            const char *probname);
  int XPRS_CC XPRScreateprob (XPRSprob * _probholder);
  int XPRS_CC XPRSdestroyprob (XPRSprob _prob);
  int XPRS_CC XPRSinit (const char *path);
  int XPRS_CC XPRSfree (void);
  int XPRS_CC XPRSgetbanner (char *banner);
  int XPRS_CC XPRSgetversion (char *version);
  int XPRS_CC XPRSgetdaysleft (int *daysleft);
  int XPRS_CC XPRSlicense (int *_i1, char *_c1);
  int XPRS_CC XPRSbeginlicensing (int *r_dontAlreadyHaveLicense);
  int XPRS_CC XPRSendlicensing (void);
  int XPRS_CC XPRSgetlicerrmsg (char *msg, int len);
  int XPRS_CC XPRSsetlogfile (XPRSprob prob, const char *logname);
  int XPRS_CC XPRSsetintcontrol (XPRSprob prob, int _index, int _ivalue);
  int XPRS_CC XPRSsetdblcontrol (XPRSprob prob, int _index, double _dvalue);
  int XPRS_CC XPRSinterrupt (XPRSprob prob, int reason);
  int XPRS_CC XPRSgetprobname (XPRSprob prob, char *_svalue);
  int XPRS_CC XPRSgetqobj (XPRSprob prob, int _icol, int _jcol,
                           double *_dval);
  int XPRS_CC XPRSsetprobname (XPRSprob prob, const char *_svalue);
  int XPRS_CC XPRSsetstrcontrol (XPRSprob prob, int _index,
                                 const char *_svalue);
  int XPRS_CC XPRSgetintcontrol (XPRSprob prob, int _index, int *_ivalue);
  int XPRS_CC XPRSgetdblcontrol (XPRSprob prob, int _index, double *_dvalue);
  int XPRS_CC XPRSgetstrcontrol (XPRSprob prob, int _index, char *_svalue);
  int XPRS_CC XPRSgetintattrib (XPRSprob prob, int _index, int *_ivalue);
  int XPRS_CC XPRSgetstrattrib (XPRSprob prob, int _index, char *_cvalue);
  int XPRS_CC XPRSgetdblattrib (XPRSprob prob, int _index, double *_dvalue);
  int XPRS_CC XPRSsetdefaultcontrol (XPRSprob prob, int _index);
  int XPRS_CC XPRSsetdefaults (XPRSprob prob);
  int XPRS_CC XPRSgoal (XPRSprob prob, const char *_filename,
                        const char *_sflags);
  int XPRS_CC XPRSreadprob (XPRSprob prob, const char *_sprobname,
                            const char *_sflags);
  int XPRS_CC XPRSloadlp (XPRSprob prob, const char *_sprobname, int ncols,
                          int nrows, const char _srowtypes[],
                          const double _drhs[], const double _drange[],
                          const double _dobj[], const int _mstart[],
                          const int _mnel[], const int _mrwind[],
                          const double _dmatval[], const double _dlb[],
                          const double _dub[]);
  int XPRS_CC XPRSloadqp (XPRSprob prob, const char *_sprobname, int ncols,
                          int nrows, const char _srowtypes[],
                          const double _drhs[], const double _drange[],
                          const double _dobj[], const int _mstart[],
                          const int _mnel[], const int _mrwind[],
                          const double _dmatval[], const double _dlb[],
                          const double _dub[], int nquads,
                          const int _mqcol1[], const int _mqcol2[],
                          const double _dqval[]);
  int XPRS_CC XPRSloadqglobal (XPRSprob prob, const char *probname, int ncols,
                               int nrows, const char qsenx[],
                               const double rhsx[], const double range[],
                               const double objx[], const int matbeg[],
                               const int matcnt[], const int matind[],
                               const double dmtval[], const double bndl[],
                               const double bndu[], const int nquads,
                               const int mqcol1[], const int mqcol2[],
                               const double dqval[], const int ngents,
                               const int nsets, const char qgtype[],
                               const int mgcols[], const double dlim[],
                               const char qstype[], const int msstart[],
                               const int mscols[], const double dref[]);
  int XPRS_CC XPRSfixglobal (XPRSprob prob);
  int XPRS_CC XPRSfixglobals (XPRSprob prob, int ifround);
  int XPRS_CC XPRSloadmodelcuts (XPRSprob prob, int nmodcuts,
                                 const int _mrows[]);
  int XPRS_CC XPRSloaddelayedrows (XPRSprob prob, int nrows,
                                   const int _mrows[]);
  int XPRS_CC XPRSloaddirs (XPRSprob prob, int ndirs, const int _mcols[],
                            const int _mpri[], const char _sbr[],
                            const double dupc[], const double ddpc[]);
  int XPRS_CC XPRSloadbranchdirs (XPRSprob prob, int ndirs,
                                  const int _mcols[], const int _mbranch[]);
  int XPRS_CC XPRSloadpresolvedirs (XPRSprob prob, int ndirs,
                                    const int _mcols[], const int _mpri[],
                                    const char _sbr[], const double dupc[],
                                    const double ddpc[]);
  int XPRS_CC XPRSgetdirs (XPRSprob prob, int *ndirs, int _mcols[],
                           int _mpri[], char _sbr[], double dupc[],
                           double ddpc[]);
  int XPRS_CC XPRSloadglobal (XPRSprob prob, const char *_sprobname,
                              int ncols, int nrows, const char _srowtypes[],
                              const double _drhs[], const double _drange[],
                              const double _dobj[], const int _mstart[],
                              const int _mnel[], const int _mrwind[],
                              const double _dmatval[], const double _dlb[],
                              const double _dub[], int ngents, int nsets,
                              const char _qgtype[], const int _mgcols[],
                              const double _dlim[], const char _stype[],
                              const int _msstart[], const int _mscols[],
                              const double _dref[]);
  int XPRS_CC XPRSaddnames (XPRSprob prob, int _itype, const char _sname[],
                            int first, int last);
  int XPRS_CC XPRSaddsetnames (XPRSprob prob, const char _sname[], int first,
                               int last);
  int XPRS_CC XPRSscale (XPRSprob prob, const int mrscal[],
                         const int mcscal[]);
  int XPRS_CC XPRSreaddirs (XPRSprob prob, const char *_sfilename);
  int XPRS_CC XPRSwritedirs (XPRSprob prob, const char *_sfilename);
  int XPRS_CC XPRSsetindicators (XPRSprob prob, int nrows, const int _mrows[],
                                 const int _inds[], const int _comps[]);
  int XPRS_CC XPRSgetindicators (XPRSprob prob, int _inds[], int _comps[],
                                 int first, int last);
  int XPRS_CC XPRSdelindicators (XPRSprob prob, int first, int last);
  int XPRS_CC XPRSminim (XPRSprob prob, const char *_sflags);
  int XPRS_CC XPRSmaxim (XPRSprob prob, const char *_sflags);
  int XPRS_CC XPRSlpoptimize (XPRSprob prob, const char *_sflags);
  int XPRS_CC XPRSmipoptimize (XPRSprob prob, const char *_sflags);
  int XPRS_CC XPRSrange (XPRSprob prob);
  int XPRS_CC XPRSgetrowrange (XPRSprob prob, double _upact[],
                               double _loact[], double _uup[], double _udn[]);
  int XPRS_CC XPRSgetcolrange (XPRSprob prob, double _upact[],
                               double _loact[], double _uup[], double _udn[],
                               double _ucost[], double _lcost[]);
  int XPRS_CC XPRSgetpivotorder (XPRSprob prob, int mpiv[]);
  int XPRS_CC XPRSgetpresolvemap (XPRSprob prob, int rowmap[], int colmap[]);
  int XPRS_CC XPRSreadbasis (XPRSprob prob, const char *_sfilename,
                             const char *_sflags);
  int XPRS_CC XPRSwritebasis (XPRSprob prob, const char *_sfilename,
                              const char *_sflags);
  int XPRS_CC XPRSglobal (XPRSprob prob);
  int XPRS_CC XPRSinitglobal (XPRSprob prob);
  int XPRS_CC XPRSwriteprtsol (XPRSprob prob, const char *_sfilename,
                               const char *_sflags);
  int XPRS_CC XPRSalter (XPRSprob prob, const char *_sfilename);
  int XPRS_CC XPRSwritesol (XPRSprob prob, const char *_sfilename,
                            const char *_sflags);
  int XPRS_CC XPRSwritebinsol (XPRSprob prob, const char *_sfilename,
                               const char *_sflags);
  int XPRS_CC XPRSreadbinsol (XPRSprob prob, const char *_sfilename,
                              const char *_sflags);
  int XPRS_CC XPRSwriteslxsol (XPRSprob prob, const char *_sfilename,
                               const char *_sflags);
  int XPRS_CC XPRSreadslxsol (XPRSprob prob, const char *_sfilename,
                              const char *_sflags);
  int XPRS_CC XPRSwriteprtrange (XPRSprob prob);
  int XPRS_CC XPRSwriterange (XPRSprob prob, const char *_sfilename,
                              const char *_sflags);
  int XPRS_CC XPRSgetsol (XPRSprob prob, double _dx[], double _dslack[],
                          double _dual[], double _dj[]);
  int XPRS_CC XPRSgetpresolvesol (XPRSprob prob, double _dx[],
                                  double _dslack[], double _dual[],
                                  double _dj[]);
  int XPRS_CC XPRSgetinfeas (XPRSprob prob, int *npv, int *nps, int *nds,
                             int *ndv, int mx[], int mslack[], int mdual[],
                             int mdj[]);
  int XPRS_CC XPRSgetscaledinfeas (XPRSprob prob, int *npv, int *nps,
                                   int *nds, int *ndv, int mx[], int mslack[],
                                   int mdual[], int mdj[]);
  int XPRS_CC XPRSgetunbvec (XPRSprob prob, int *icol);
  int XPRS_CC XPRSbtran (XPRSprob prob, double dwork[]);
  int XPRS_CC XPRSftran (XPRSprob prob, double dwork[]);
  int XPRS_CC XPRSgetobj (XPRSprob prob, double _dobj[], int first, int last);
  int XPRS_CC XPRSgetrhs (XPRSprob prob, double _drhs[], int first, int last);
  int XPRS_CC XPRSgetrhsrange (XPRSprob prob, double _drng[], int first,
                               int last);
  int XPRS_CC XPRSgetlb (XPRSprob prob, double _dbdl[], int first, int last);
  int XPRS_CC XPRSgetub (XPRSprob prob, double _dbdu[], int first, int last);
  int XPRS_CC XPRSgetcols (XPRSprob prob, int _mstart[], int _mrwind[],
                           double _dmatval[], int maxcoeffs, int *ncoeffs,
                           int first, int last);
  int XPRS_CC XPRSgetrows (XPRSprob prob, int _mstart[], int _mclind[],
                           double _dmatval[], int maxcoeffs, int *ncoeffs,
                           int first, int last);
  int XPRS_CC XPRSgetcoef (XPRSprob prob, int _irow, int _icol,
                           double *_dval);
  int XPRS_CC XPRSgetmqobj (XPRSprob prob, int _mstart[], int _mclind[],
                            double _dobjval[], int maxcoeffs, int *ncoeffs,
                            int first, int last);
  int XPRS_CC XPRSiisclear (XPRSprob prob);
  int XPRS_CC XPRSiisfirst (XPRSprob prob, int ifiis, int *status_code);
  int XPRS_CC XPRSiisnext (XPRSprob prob, int *status_code);
  int XPRS_CC XPRSiisstatus (XPRSprob prob, int *iiscount, int rowsizes[],
                             int colsizes[], double suminfeas[],
                             int numinfeas[]);
  int XPRS_CC XPRSiisall (XPRSprob prob);
  int XPRS_CC XPRSiiswrite (XPRSprob prob, int number, const char *fn,
                            int filetype, const char *typeflags);
  int XPRS_CC XPRSiisisolations (XPRSprob prob, int number);
  int XPRS_CC XPRSgetiisdata (XPRSprob prob, int number, int *rownumber,
                              int *colnumber, int miisrow[], int miiscol[],
                              char constrainttype[], char colbndtype[],
                              double duals[], double rdcs[],
                              char isolationrows[], char isolationcols[]);
  int XPRS_CC XPRSgetiis (XPRSprob prob, int *ncols, int *nrows,
                          int _miiscol[], int _miisrow[]);
  int XPRS_CC XPRSgetpresolvebasis (XPRSprob prob, int _mrowstatus[],
                                    int _mcolstatus[]);
  int XPRS_CC XPRSloadpresolvebasis (XPRSprob prob, const int _mrowstatus[],
                                     const int _mcolstatus[]);
  int XPRS_CC XPRSgetglobal (XPRSprob prob, int *ngents, int *nsets,
                             char _sgtype[], int _mgcols[], double _dlim[],
                             char _sstype[], int _msstart[], int _mscols[],
                             double _dref[]);
  int XPRS_CC XPRSwriteprob (XPRSprob prob, const char *_sfilename,
                             const char *_sflags);
  int XPRS_CC XPRSgetnames (XPRSprob prob, int _itype, char _sbuff[],
                            int first, int last);
  int XPRS_CC XPRSgetrowtype (XPRSprob prob, char _srowtype[], int first,
                              int last);
  int XPRS_CC XPRSloadsecurevecs (XPRSprob prob, int nrows, int ncols,
                                  const int mrow[], const int mcol[]);
  int XPRS_CC XPRSgetcoltype (XPRSprob prob, char _coltype[], int first,
                              int last);
  int XPRS_CC XPRSgetbasis (XPRSprob prob, int _mrowstatus[],
                            int _mcolstatus[]);
  int XPRS_CC XPRSloadbasis (XPRSprob prob, const int _mrowstatus[],
                             const int _mcolstatus[]);
  int XPRS_CC XPRSgetindex (XPRSprob prob, int _itype, const char *_sname,
                            int *_iseq);
  int XPRS_CC XPRSaddrows (XPRSprob prob, int nrows, int ncoeffs,
                           const char _srowtype[], const double _drhs[],
                           const double _drng[], const int _mstart[],
                           const int _mclind[], const double _dmatval[]);
  int XPRS_CC XPRSdelrows (XPRSprob prob, int nrows, const int _mindex[]);
  int XPRS_CC XPRSdelnode (XPRSprob prob, int _inode, int ifboth);
  int XPRS_CC XPRSaddcols (XPRSprob prob, int ncols, int ncoeffs,
                           const double _dobj[], const int _mstart[],
                           const int _mrwind[], const double _dmatval[],
                           const double _dbdl[], const double _dbdu[]);
  int XPRS_CC XPRSdelcols (XPRSprob prob, int ncols, const int _mindex[]);
  int XPRS_CC XPRSchgcoltype (XPRSprob prob, int ncols, const int _mindex[],
                              const char _coltype[]);
  int XPRS_CC XPRSchgrowtype (XPRSprob prob, int nrows, const int _mindex[],
                              const char _srowtype[]);
  int XPRS_CC XPRSchgbounds (XPRSprob prob, int nbnds, const int _mindex[],
                             const char _sboundtype[], const double _dbnd[]);
  int XPRS_CC XPRSchgobj (XPRSprob prob, int ncols, const int _mindex[],
                          const double _dobj[]);
  int XPRS_CC XPRSchgcoef (XPRSprob prob, int _irow, int _icol, double _dval);
  int XPRS_CC XPRSchgmcoef (XPRSprob prob, int ncoeffs, const int _mrow[],
                            const int _mcol[], const double _dval[]);
  int XPRS_CC XPRSchgmqobj (XPRSprob prob, int ncols, const int _mcol1[],
                            const int _mcol2[], const double _dval[]);
  int XPRS_CC XPRSchgqobj (XPRSprob prob, int _icol, int _jcol, double _dval);
  int XPRS_CC XPRSchgrhs (XPRSprob prob, int nrows, const int _mindex[],
                          const double _drhs[]);
  int XPRS_CC XPRSchgrhsrange (XPRSprob prob, int nrows, const int _mindex[],
                               const double _drng[]);
  int XPRS_CC XPRSchgobjsense (XPRSprob prob, int objsense);
  int XPRS_CC XPRSsave (XPRSprob prob);
  int XPRS_CC XPRSrestore (XPRSprob prob, const char *_sprobname,
                           const char *_force);
  int XPRS_CC XPRSpivot (XPRSprob prob, int _in, int _out);
  int XPRS_CC XPRSgetpivots (XPRSprob prob, int _in, int _mout[],
                             double _dout[], double *_dobjo, int *npiv,
                             int maxpiv);
  int XPRS_CC XPRSsetcblplog (XPRSprob prob,
                              int (XPRS_CC * f_lplog) (XPRSprob prob,
                                                       void *vContext),
                              void *p);
  int XPRS_CC XPRSsetcbgloballog (XPRSprob prob,
                                  int (XPRS_CC * f_globallog) (XPRSprob prob,
                                                               void
                                                               *vContext),
                                  void *p);
  int XPRS_CC XPRSsetcbcutlog (XPRSprob prob,
                               int (XPRS_CC * f_cutlog) (XPRSprob prob,
                                                         void *vContext),
                               void *p);
  int XPRS_CC XPRSsetcbbarlog (XPRSprob prob,
                               int (XPRS_CC * f_barlog) (XPRSprob prob,
                                                         void *vContext),
                               void *p);
  int XPRS_CC XPRSsetcbcutmgr (XPRSprob prob,
                               int (XPRS_CC * f_cutmgr) (XPRSprob prob,
                                                         void *vContext),
                               void *p);
  int XPRS_CC XPRSsetcbchgnode (XPRSprob prob,
                                void (XPRS_CC * f_chgnode) (XPRSprob prob,
                                                            void *vContext,
                                                            int *nodnum),
                                void *p);
  int XPRS_CC XPRSsetcboptnode (XPRSprob prob,
                                void (XPRS_CC * f_optnode) (XPRSprob prob,
                                                            void *vContext,
                                                            int *feas),
                                void *p);
  int XPRS_CC XPRSsetcbprenode (XPRSprob prob,
                                void (XPRS_CC * f_prenode) (XPRSprob prob,
                                                            void *vContext,
                                                            int *nodinfeas),
                                void *p);
  int XPRS_CC XPRSsetcbinfnode (XPRSprob prob,
                                void (XPRS_CC * f_infnode) (XPRSprob prob,
                                                            void *vContext),
                                void *p);
  int XPRS_CC XPRSsetcbnewnode (XPRSprob prob,
                                void (XPRS_CC * f_newnode) (XPRSprob prob,
                                                            void *vContext,
                                                            int parentnode,
                                                            int newnode,
                                                            int branch),
                                void *p);
  int XPRS_CC XPRSsetcbnodecutoff (XPRSprob prob,
                                   void (XPRS_CC *
                                         f_nodecutoff) (XPRSprob prob,
                                                        void *vContext,
                                                        int nodnum), void *p);
  int XPRS_CC XPRSsetcbpreintsol (XPRSprob prob,
                                  void (XPRS_CC * f_preintsol) (XPRSprob prob,
                                                                void
                                                                *vContext,
                                                                int
                                                                isheuristic,
                                                                int *ifreject,
                                                                double
                                                                *cutoff),
                                  void *p);
  int XPRS_CC XPRSsetcbintsol (XPRSprob prob,
                               void (XPRS_CC * f_intsol) (XPRSprob prob,
                                                          void *vContext),
                               void *p);
  int XPRS_CC XPRSsetcbchgbranch (XPRSprob prob,
                                  void (XPRS_CC * f_chgbranch) (XPRSprob prob,
                                                                void
                                                                *vContext,
                                                                int *entity,
                                                                int *up,
                                                                double
                                                                *estdeg),
                                  void *p);
  int XPRS_CC XPRSsetcbchgbranchobject (XPRSprob prob,
                                        void (XPRS_CC *
                                              f_chgbranchobject) (XPRSprob
                                                                  prob,
                                                                  void
                                                                  *vContext,
                                                                  XPRSbranchobject
                                                                  obranch,
                                                                  XPRSbranchobject
                                                                  *
                                                                  p_newobject),
                                        void *p);
  int XPRS_CC XPRSsetcbestimate (XPRSprob prob,
                                 int (XPRS_CC * f_estimate) (XPRSprob prob,
                                                             void *vContext,
                                                             int *iglsel,
                                                             int *iprio,
                                                             double *degbest,
                                                             double *degworst,
                                                             double *curval,
                                                             int *ifupx,
                                                             int *nglinf,
                                                             double *degsum,
                                                             int *nbr),
                                 void *p);
  int XPRS_CC XPRSsetcbsepnode (XPRSprob prob,
                                int (XPRS_CC * f_sepnode) (XPRSprob prob,
                                                           void *vContext,
                                                           int ibr,
                                                           int iglsel,
                                                           int ifup,
                                                           double curval),
                                void *p);
  int XPRS_CC XPRSsetcbmessage (XPRSprob prob,
                                void (XPRS_CC * f_message) (XPRSprob prob,
                                                            void *vContext,
                                                            const char *msg,
                                                            int len,
                                                            int msgtype),
                                void *p);
  int XPRS_CC XPRSsetcbmipthread (XPRSprob prob,
                                  void (XPRS_CC *
                                        f_mipthread) (XPRSprob master_prob,
                                                      void *vContext,
                                                      XPRSprob prob),
                                  void *p);
  int XPRS_CC XPRSsetcbdestroymt (XPRSprob prob,
                                  void (XPRS_CC * f_destroymt) (XPRSprob prob,
                                                                void
                                                                *vContext),
                                  void *p);
  int XPRS_CC XPRSgetcblplog (XPRSprob prob,
                              int (XPRS_CC ** f_lplog) (XPRSprob prob,
                                                        void *vContext),
                              void **p);
  int XPRS_CC XPRSgetcbgloballog (XPRSprob prob,
                                  int (XPRS_CC ** f_globallog) (XPRSprob prob,
                                                                void
                                                                *vContext),
                                  void **p);
  int XPRS_CC XPRSgetcbcutlog (XPRSprob prob,
                               int (XPRS_CC ** f_cutlog) (XPRSprob prob,
                                                          void *vContext),
                               void **p);
  int XPRS_CC XPRSgetcbbarlog (XPRSprob prob,
                               int (XPRS_CC ** f_barlog) (XPRSprob prob,
                                                          void *vContext),
                               void **p);
  int XPRS_CC XPRSgetcbcutmgr (XPRSprob prob,
                               int (XPRS_CC ** f_cutmgr) (XPRSprob prob,
                                                          void *vContext),
                               void **p);
  int XPRS_CC XPRSgetcbchgnode (XPRSprob prob,
                                void (XPRS_CC ** f_chgnode) (XPRSprob prob,
                                                             void *vContext,
                                                             int *nodnum),
                                void **p);
  int XPRS_CC XPRSgetcboptnode (XPRSprob prob,
                                void (XPRS_CC ** f_optnode) (XPRSprob prob,
                                                             void *vContext,
                                                             int *feas),
                                void **p);
  int XPRS_CC XPRSgetcbprenode (XPRSprob prob,
                                void (XPRS_CC ** f_prenode) (XPRSprob prob,
                                                             void *vContext,
                                                             int *nodinfeas),
                                void **p);
  int XPRS_CC XPRSgetcbinfnode (XPRSprob prob,
                                void (XPRS_CC ** f_infnode) (XPRSprob prob,
                                                             void *vContext),
                                void **p);
  int XPRS_CC XPRSgetcbnewnode (XPRSprob prob,
                                void (XPRS_CC ** f_newnode) (XPRSprob prob,
                                                             void *vContext,
                                                             int parentnode,
                                                             int newnode,
                                                             int branch),
                                void **p);
  int XPRS_CC XPRSgetcbnodecutoff (XPRSprob prob,
                                   void (XPRS_CC **
                                         f_nodecutoff) (XPRSprob prob,
                                                        void *vContext,
                                                        int nodnum),
                                   void **p);
  int XPRS_CC XPRSgetcbpreintsol (XPRSprob prob,
                                  void (XPRS_CC **
                                        f_preintsol) (XPRSprob prob,
                                                      void *vContext,
                                                      int isheuristic,
                                                      int *ifreject,
                                                      double *cutoff),
                                  void **p);
  int XPRS_CC XPRSgetcbintsol (XPRSprob prob,
                               void (XPRS_CC ** f_intsol) (XPRSprob prob,
                                                           void *vContext),
                               void **p);
  int XPRS_CC XPRSgetcbchgbranch (XPRSprob prob,
                                  void (XPRS_CC **
                                        f_chgbranch) (XPRSprob prob,
                                                      void *vContext,
                                                      int *entity, int *up,
                                                      double *estdeg),
                                  void **p);
  int XPRS_CC XPRSgetcbchgbranchobject (XPRSprob prob,
                                        void (XPRS_CC **
                                              f_chgbranchobject) (XPRSprob
                                                                  prob,
                                                                  void
                                                                  *vContext,
                                                                  XPRSbranchobject
                                                                  obranch,
                                                                  XPRSbranchobject
                                                                  *
                                                                  p_newobject),
                                        void **p);
  int XPRS_CC XPRSgetcbestimate (XPRSprob prob,
                                 int (XPRS_CC ** f_estimate) (XPRSprob prob,
                                                              void *vContext,
                                                              int *iglsel,
                                                              int *iprio,
                                                              double *degbest,
                                                              double
                                                              *degworst,
                                                              double *curval,
                                                              int *ifupx,
                                                              int *nglinf,
                                                              double *degsum,
                                                              int *nbr),
                                 void **p);
  int XPRS_CC XPRSgetcbsepnode (XPRSprob prob,
                                int (XPRS_CC ** f_sepnode) (XPRSprob prob,
                                                            void *vContext,
                                                            int ibr,
                                                            int iglsel,
                                                            int ifup,
                                                            double curval),
                                void **p);
  int XPRS_CC XPRSgetcbmessage (XPRSprob prob,
                                void (XPRS_CC ** f_message) (XPRSprob prob,
                                                             void *vContext,
                                                             const char *msg,
                                                             int len,
                                                             int msgtype),
                                void **p);
  int XPRS_CC XPRSgetcbmipthread (XPRSprob prob,
                                  void (XPRS_CC **
                                        f_mipthread) (XPRSprob master_prob,
                                                      void *vContext,
                                                      XPRSprob prob),
                                  void **p);
  int XPRS_CC XPRSgetcbdestroymt (XPRSprob prob,
                                  void (XPRS_CC **
                                        f_destroymt) (XPRSprob prob,
                                                      void *vContext),
                                  void **p);
  int XPRS_CC XPRSaddcuts (XPRSprob prob, int ncuts, const int mtype[],
                           const char qrtype[], const double drhs[],
                           const int mstart[], const int mcols[],
                           const double dmatval[]);
  int XPRS_CC XPRSdelcuts (XPRSprob prob, int ibasis, int itype, int interp,
                           double delta, int ncuts, const XPRScut mcutind[]);
  int XPRS_CC XPRSdelcpcuts (XPRSprob prob, int itype, int interp, int ncuts,
                             const XPRScut mcutind[]);
  int XPRS_CC XPRSgetcutlist (XPRSprob prob, int itype, int interp,
                              int *ncuts, int maxcuts, XPRScut mcutind[]);
  int XPRS_CC XPRSgetcpcutlist (XPRSprob prob, int itype, int interp,
                                double delta, int *ncuts, int maxcuts,
                                XPRScut mcutind[], double dviol[]);
  int XPRS_CC XPRSgetcpcuts (XPRSprob prob, const XPRScut mindex[], int ncuts,
                             int size, int mtype[], char qrtype[],
                             int mstart[], int mcols[], double dmatval[],
                             double drhs[]);
  int XPRS_CC XPRSloadcuts (XPRSprob prob, int itype, int interp, int ncuts,
                            const XPRScut mcutind[]);
  int XPRS_CC XPRSstorecuts (XPRSprob prob, int ncuts, int nodupl,
                             const int mtype[], const char qrtype[],
                             const double drhs[], const int mstart[],
                             XPRScut mindex[], const int mcols[],
                             const double dmatval[]);
  int XPRS_CC XPRSpresolverow (XPRSprob prob, char qrtype, int nzo,
                               const int mcolso[], const double dvalo[],
                               double drhso, int maxcoeffs, int *nzp,
                               int mcolsp[], double dvalp[], double *drhsp,
                               int *status);
  int XPRS_CC XPRSloadmipsol (XPRSprob prob, const double dsol[],
                              int *status);
  int XPRS_CC XPRSstorebounds (XPRSprob prob, int nbnds, const int mcols[],
                               const char qbtype[], const double dbnd[],
                               void **mindex);
  int XPRS_CC XPRSsetbranchcuts (XPRSprob prob, int nbcuts,
                                 const XPRScut mindex[]);
  int XPRS_CC XPRSsetbranchbounds (XPRSprob prob, void *mindex);
  int XPRS_CC XPRSgetlasterror (XPRSprob prob, char *errmsg);
  int XPRS_CC XPRSbasiscondition (XPRSprob prob, double *condnum,
                                  double *scondnum);
  int XPRS_CC XPRSgetmipsol (XPRSprob prob, double _dx[], double _dslack[]);
  int XPRS_CC XPRSgetlpsol (XPRSprob prob, double _dx[], double _dslack[],
                            double _dual[], double _dj[]);
  int XPRS_CC XPRSpostsolve (XPRSprob prob);
  int XPRS_CC XPRSdelsets (XPRSprob prob, int nsets, const int msindex[]);
  int XPRS_CC XPRSaddsets (XPRSprob prob, int newsets, int newnz,
                           const char qstype[], const int msstart[],
                           const int mscols[], const double dref[]);
  int XPRS_CC XPRSsetmessagestatus (XPRSprob prob, int errcode,
                                    int bEnabledStatus);
  int XPRS_CC XPRSgetmessagestatus (XPRSprob prob, int errcode,
                                    int *bEnabledStatus);
  int XPRS_CC XPRSrepairweightedinfeas (XPRSprob prob, int *scode,
                                        const double lrp_array[],
                                        const double grp_array[],
                                        const double lbp_array[],
                                        const double ubp_array[],
                                        char second_phase, double delta,
                                        const char *optflags);
  int XPRS_CC XPRSrepairinfeas (XPRSprob prob, int *scode, char ptype,
                                char phase2, char globalflags, double lrp,
                                double grp, double lbp, double ubp,
                                double delta);
  int XPRS_CC XPRSgetcutslack (XPRSprob prob, XPRScut cut, double *dslack);
  int XPRS_CC XPRSgetcutmap (XPRSprob prob, int ncuts, const XPRScut cuts[],
                             int cutmap[]);
  int XPRS_CC XPRSgetnamelist (XPRSprob prob, int _itype, char _sbuff[],
                               int names_len, int *names_len_reqd, int first,
                               int last);
  int XPRS_CC XPRSgetnamelistobject (XPRSprob prob, int _itype,
                                     XPRSnamelist * r_nl);
  int XPRS_CC XPRSlogfilehandler (XPRSobject obj, void *vUserContext,
                                  void *vSystemThreadId, const char *sMsg,
                                  int iMsgType, int iMsgCode);
  int XPRS_CC XPRSgetobjecttypename (XPRSobject obj,
                                     const char **sObjectName);
  int XPRS_CC XPRSobjsa (XPRSprob prob, int ncols, const int mindex[],
                         double lower[], double upper[]);
  int XPRS_CC XPRSrhssa (XPRSprob prob, int nrows, const int mindex[],
                         double lower[], double upper[]);
  int XPRS_CC
    XPRS_ge_setcbmsghandler (int (XPRS_CC * f_msghandler)
                             (XPRSobject vXPRSObject, void *vUserContext,
                              void *vSystemThreadId, const char *sMsg,
                              int iMsgType, int iMsgCode), void *p);
  int XPRS_CC XPRS_ge_getlasterror (int *iMsgCode, char *_msg,
                                    int _iStringBufferBytes,
                                    int *_iBytesInInternalString);
  int XPRS_CC XPRS_msp_create (XPRSmipsolpool * msp);
  int XPRS_CC XPRS_msp_destroy (XPRSmipsolpool msp);
  int XPRS_CC XPRS_msp_probattach (XPRSmipsolpool msp, XPRSprob prob);
  int XPRS_CC XPRS_msp_probdetach (XPRSmipsolpool msp, XPRSprob prob);
  int XPRS_CC XPRS_msp_setcbmsghandler (XPRSmipsolpool msp,
                                        int (XPRS_CC *
                                             f_msghandler) (XPRSobject
                                                            vXPRSObject,
                                                            void
                                                            *vUserContext,
                                                            void
                                                            *vSystemThreadId,
                                                            const char *sMsg,
                                                            int iMsgType,
                                                            int iMsgCode),
                                        void *p);
  int XPRS_CC XPRS_msp_getsollist (XPRSmipsolpool msp,
                                   XPRSprob prob_to_rank_against,
                                   int iRankAttrib, int bRankAscending,
                                   int iRankFirstIndex_Ob,
                                   int iRankLastIndex_Ob,
                                   int iSolutionIds_Zb[],
                                   int *nReturnedSolIds, int *nSols);
  int XPRS_CC XPRS_msp_getsollist2 (XPRSmipsolpool msp,
                                    XPRSprob prob_to_rank_against,
                                    int iRankAttrib, int bRankAscending,
                                    int iRankFirstIndex_Ob,
                                    int iRankLastIndex_Ob,
                                    int bUseUserBitFilter, int iUserBitMask,
                                    int iUserBitPattern,
                                    int bUseInternalBitFilter,
                                    int iInternalBitMask,
                                    int iInternalBitPattern,
                                    int iSolutionIds_Zb[],
                                    int *nReturnedSolIds, int *nSols);
  int XPRS_CC XPRS_msp_getsol (XPRSmipsolpool msp, int iSolutionId,
                               int *iSolutionIdStatus_, double x[],
                               int iColFirst, int iColLast,
                               int *nValuesReturned);
  int XPRS_CC XPRS_msp_loadsol (XPRSmipsolpool msp, int *iSolutionId,
                                const double x[], int nCols,
                                const char *sSolutionName,
                                int *bNameModifiedForUniqueness,
                                int
                                *iSolutionIdOfExistingDuplicatePreventedLoad);
  int XPRS_CC XPRS_msp_delsol (XPRSmipsolpool msp, int iSolutionId,
                               int *iSolutionIdStatus_);
  int XPRS_CC XPRS_msp_getintattribprobsol (XPRSmipsolpool msp,
                                            XPRSprob prob_to_rank_against,
                                            int iSolutionId,
                                            int *iSolutionIdStatus_,
                                            int iAttribId, int *Dst);
  int XPRS_CC XPRS_msp_getdblattribprobsol (XPRSmipsolpool msp,
                                            XPRSprob prob_to_rank_against,
                                            int iSolutionId,
                                            int *iSolutionIdStatus_,
                                            int iAttribId, double *Dst);
  int XPRS_CC XPRS_msp_getintattribprob (XPRSmipsolpool msp, XPRSprob prob,
                                         int iAttribId, int *Dst);
  int XPRS_CC XPRS_msp_getdblattribprob (XPRSmipsolpool msp, XPRSprob prob,
                                         int iAttribId, double *Dst);
  int XPRS_CC XPRS_msp_getintattribsol (XPRSmipsolpool msp, int iSolutionId,
                                        int *iSolutionIdStatus_,
                                        int iAttribId, int *Dst);
  int XPRS_CC XPRS_msp_getdblattribsol (XPRSmipsolpool msp, int iSolutionId,
                                        int *iSolutionIdStatus_,
                                        int iAttribId, double *Dst);
  int XPRS_CC XPRS_msp_getintcontrolsol (XPRSmipsolpool msp, int iSolutionId,
                                         int *iSolutionIdStatus_,
                                         int iControlId, int *Val);
  int XPRS_CC XPRS_msp_getdblcontrolsol (XPRSmipsolpool msp, int iSolutionId,
                                         int *iSolutionIdStatus_,
                                         int iControlId, double *Val);
  int XPRS_CC XPRS_msp_setintcontrolsol (XPRSmipsolpool msp, int iSolutionId,
                                         int *iSolutionIdStatus_,
                                         int iControlId, int Val);
  int XPRS_CC XPRS_msp_setdblcontrolsol (XPRSmipsolpool msp, int iSolutionId,
                                         int *iSolutionIdStatus_,
                                         int iControlId, double Val);
  int XPRS_CC XPRS_msp_getintattribprobextreme (XPRSmipsolpool msp,
                                                XPRSprob prob_to_rank_against,
                                                int bGet_Max_Otherwise_Min,
                                                int *iSolutionId,
                                                int iAttribId,
                                                int *ExtremeVal);
  int XPRS_CC XPRS_msp_getdblattribprobextreme (XPRSmipsolpool msp,
                                                XPRSprob prob_to_rank_against,
                                                int bGet_Max_Otherwise_Min,
                                                int *iSolutionId,
                                                int iAttribId,
                                                double *ExtremeVal);
  int XPRS_CC XPRS_msp_getintattrib (XPRSmipsolpool msp, int iAttribId,
                                     int *Val);
  int XPRS_CC XPRS_msp_getdblattrib (XPRSmipsolpool msp, int iAttribId,
                                     double *Val);
  int XPRS_CC XPRS_msp_getintcontrol (XPRSmipsolpool msp, int iControlId,
                                      int *Val);
  int XPRS_CC XPRS_msp_getdblcontrol (XPRSmipsolpool msp, int iControlId,
                                      double *Val);
  int XPRS_CC XPRS_msp_setintcontrol (XPRSmipsolpool msp, int iControlId,
                                      int Val);
  int XPRS_CC XPRS_msp_setdblcontrol (XPRSmipsolpool msp, int iControlId,
                                      double Val);
  int XPRS_CC XPRS_msp_setsolname (XPRSmipsolpool msp, int iSolutionId,
                                   const char *sNewSolutionBaseName,
                                   int *bNameModifiedForUniqueness,
                                   int *iSolutionIdStatus_);
  int XPRS_CC XPRS_msp_getsolname (XPRSmipsolpool msp, int iSolutionId,
                                   char *_sname, int _iStringBufferBytes,
                                   int *_iBytesInInternalString,
                                   int *iSolutionIdStatus_);
  int XPRS_CC XPRS_msp_findsolbyname (XPRSmipsolpool msp,
                                      const char *sSolutionName,
                                      int *iSolutionId);
  int XPRS_CC XPRS_msp_writeslxsol (XPRSmipsolpool msp, XPRSprob prob_context,
                                    int iSolutionId, int *iSolutionIdStatus_,
                                    const char *sFileName,
                                    const char *sFlags);
  int XPRS_CC XPRS_msp_readslxsol (XPRSmipsolpool msp,
                                   XPRSnamelist col_name_list,
                                   const char *sFileName, const char *sFlags,
                                   int *iSolutionId_Beg,
                                   int *iSolutionId_End);
  int XPRS_CC XPRS_msp_getlasterror (XPRSmipsolpool msp, int *iMsgCode,
                                     char *_msg, int _iStringBufferBytes,
                                     int *_iBytesInInternalString);
  int XPRS_CC XPRS_nml_create (XPRSnamelist * r_nl);
  int XPRS_CC XPRS_nml_destroy (XPRSnamelist nml);
  int XPRS_CC XPRS_nml_getnamecount (XPRSnamelist nml, int *count);
  int XPRS_CC XPRS_nml_getmaxnamelen (XPRSnamelist nml, int *namlen);
  int XPRS_CC XPRS_nml_getnames (XPRSnamelist nml, int padlen, char buf[],
                                 int buflen, int *r_buflen_reqd,
                                 int firstIndex, int lastIndex);
  int XPRS_CC XPRS_nml_addnames (XPRSnamelist nml, const char buf[],
                                 int firstIndex, int lastIndex);
  int XPRS_CC XPRS_nml_removenames (XPRSnamelist nml, int firstIndex,
                                    int lastIndex);
  int XPRS_CC XPRS_nml_findname (XPRSnamelist nml, const char *name,
                                 int *r_index);
  int XPRS_CC XPRS_nml_copynames (XPRSnamelist dst, XPRSnamelist src);
  int XPRS_CC XPRS_nml_getlasterror (XPRSnamelist nml, int *iMsgCode,
                                     char *_msg, int _iStringBufferBytes,
                                     int *_iBytesInInternalString);
  int XPRS_CC XPRS_nml_setcbmsghandler (XPRSnamelist nml,
                                        int (XPRS_CC *
                                             f_msghandler) (XPRSobject
                                                            vXPRSObject,
                                                            void
                                                            *vUserContext,
                                                            void
                                                            *vSystemThreadId,
                                                            const char *sMsg,
                                                            int iMsgType,
                                                            int iMsgCode),
                                        void *p);
  int XPRS_CC XPRSgetqrowcoeff (XPRSprob prob, int irow, int icol, int jcol,
                                double *dval);
  int XPRS_CC XPRSgetqrowqmatrix (XPRSprob prob, int irow, int mstart[],
                                  int mclind[], double dobjval[],
                                  int maxcoeffs, int *ncoeffs, int first,
                                  int last);
  int XPRS_CC XPRSgetqrowqmatrixtriplets (XPRSprob prob, int irow,
                                          int *nqelem, int mqcol1[],
                                          int mqcol2[], double dqe[]);
  int XPRS_CC XPRSchgqrowcoeff (XPRSprob prob, int irow, int icol, int jcol,
                                double dval);
  int XPRS_CC XPRSgetqrows (XPRSprob prob, int *qmn, int qcrows[]);
  int XPRS_CC XPRSaddqmatrix (XPRSprob prob, int irow, int nqtr,
                              const int mqc1[], const int mqc2[],
                              const double dqew[]);
  int XPRS_CC XPRSdelqmatrix (XPRSprob prob, int irow);
  int XPRS_CC XPRSloadqcqp (XPRSprob prob, const char *_sprobname, int ncols,
                            int nrows, const char _srowtypes[],
                            const double _drhs[], const double _drange[],
                            const double _dobj[], const int _mstart[],
                            const int _mnel[], const int _mrwind[],
                            const double _dmatval[], const double _dlb[],
                            const double _dub[], int nquads,
                            const int _mqcol1[], const int _mqcol2[],
                            const double _dqval[], int qmn,
                            const int qcrows[], const int qcnquads[],
                            const int qcmqcol1[], const int qcmqcol2[],
                            const double qcdqval[]);
  int XPRS_CC XPRSloadqcqpglobal (XPRSprob prob, const char *_sprobname,
                                  int ncols, int nrows,
                                  const char _srowtypes[],
                                  const double _drhs[],
                                  const double _drange[],
                                  const double _dobj[], const int _matbeg[],
                                  const int _matcnt[], const int _matrow[],
                                  const double _dmatval[],
                                  const double _dlb[], const double _dub[],
                                  int nquads, const int _mqcol1[],
                                  const int _mqcol2[], const double _dqval[],
                                  int qmn, const int qcrows[],
                                  const int qcnquads[], const int qcmqcol1[],
                                  const int qcmqcol2[],
                                  const double qcdqval[], const int ngents,
                                  const int nsets, const char qgtype[],
                                  const int mgcols[], const double dlim[],
                                  const char qstype[], const int msstart[],
                                  const int mscols[], const double dref[]);
  int XPRS_CC XPRS_mse_create (XPRSmipsolenum * mse);
  int XPRS_CC XPRS_mse_destroy (XPRSmipsolenum mse);
  int XPRS_CC XPRS_mse_getsollist (XPRSmipsolenum mse, int iMetricId,
                                   int iRankFirstIndex_Ob,
                                   int iRankLastIndex_Ob, int iSolutionIds[],
                                   int *nReturnedSolIds, int *nSols);
  int XPRS_CC XPRS_mse_getsolmetric (XPRSmipsolenum mse, int iSolutionId,
                                     int *iSolutionIdStatus, int iMetricId,
                                     double *dMetric);
  int XPRS_CC XPRS_mse_getcullchoice (XPRSmipsolenum mse, int iMetricId,
                                      int cull_sol_id_list[],
                                      int nMaxSolsToCull, int *nSolsToCull,
                                      double dNewSolMetric, const double x[],
                                      int nCols, int *bRejectSoln);
  int XPRS_CC XPRS_mse_minim (XPRSmipsolenum mse, XPRSprob prob,
                              XPRSmipsolpool msp,
                              int (XPRS_CC *
                                   f_mse_handler) (XPRSmipsolenum mse,
                                                   XPRSprob prob,
                                                   XPRSmipsolpool msp,
                                                   void *vContext,
                                                   int *nMaxSols,
                                                   const double x_Zb[],
                                                   const int nCols,
                                                   const double dMipObject,
                                                   double *dModifiedObject,
                                                   int *bRejectSoln,
                                                   int
                                                   *bUpdateMipAbsCutOffOnCurrentSet),
                              void *p, int *nMaxSols);
  int XPRS_CC XPRS_mse_maxim (XPRSmipsolenum mse, XPRSprob prob,
                              XPRSmipsolpool msp,
                              int (XPRS_CC *
                                   f_mse_handler) (XPRSmipsolenum mse,
                                                   XPRSprob prob,
                                                   XPRSmipsolpool msp,
                                                   void *vContext,
                                                   int *nMaxSols,
                                                   const double x_Zb[],
                                                   const int nCols,
                                                   const double dMipObject,
                                                   double *dModifiedObject,
                                                   int *bRejectSoln,
                                                   int
                                                   *bUpdateMipAbsCutOffOnCurrentSet),
                              void *p, int *nMaxSols);
  int XPRS_CC XPRS_mse_opt (XPRSmipsolenum mse, XPRSprob prob,
                            XPRSmipsolpool msp,
                            int (XPRS_CC * f_mse_handler) (XPRSmipsolenum mse,
                                                           XPRSprob prob,
                                                           XPRSmipsolpool msp,
                                                           void *vContext,
                                                           int *nMaxSols,
                                                           const double
                                                           x_Zb[],
                                                           const int nCols,
                                                           const double
                                                           dMipObject,
                                                           double
                                                           *dModifiedObject,
                                                           int *bRejectSoln,
                                                           int
                                                           *bUpdateMipAbsCutOffOnCurrentSet),
                            void *p, int *nMaxSols);
  int XPRS_CC XPRS_mse_getintattrib (XPRSmipsolenum mse, int iAttribId,
                                     int *Val);
  int XPRS_CC XPRS_mse_getdblattrib (XPRSmipsolenum mse, int iAttribId,
                                     double *Val);
  int XPRS_CC XPRS_mse_getintcontrol (XPRSmipsolenum mse, int iAttribId,
                                      int *Val);
  int XPRS_CC XPRS_mse_getdblcontrol (XPRSmipsolenum mse, int iAttribId,
                                      double *Val);
  int XPRS_CC XPRS_mse_setintcontrol (XPRSmipsolenum mse, int iAttribId,
                                      int Val);
  int XPRS_CC XPRS_mse_setdblcontrol (XPRSmipsolenum mse, int iAttribId,
                                      double Val);
  int XPRS_CC XPRS_mse_getlasterror (XPRSmipsolenum mse, int *iMsgCode,
                                     char *_msg, int _iStringBufferBytes,
                                     int *_iBytesInInternalString);
  int XPRS_CC XPRS_mse_setcbmsghandler (XPRSmipsolenum mse,
                                        int (XPRS_CC *
                                             f_msghandler) (XPRSobject
                                                            vXPRSObject,
                                                            void
                                                            *vUserContext,
                                                            void
                                                            *vSystemThreadId,
                                                            const char *sMsg,
                                                            int iMsgType,
                                                            int iMsgCode),
                                        void *p);
  int XPRS_CC XPRS_mse_setsolbasename (XPRSmipsolenum mse,
                                       const char *sSolutionBaseName);
  int XPRS_CC XPRS_mse_getsolbasename (XPRSmipsolenum mse, char *_sname,
                                       int _iStringBufferBytes,
                                       int *_iBytesInInternalString);
  int XPRS_CC XPRS_mse_setcbgetsolutiondiff (XPRSmipsolenum mse,
                                             int (XPRS_CC *
                                                  f_mse_getsolutiondiff)
                                             (XPRSmipsolenum mse,
                                              void *vContext, int nCols,
                                              int iSolutionId_1,
                                              int iElemCount_1,
                                              double dMipObj_1,
                                              const double Vals_1[],
                                              const int iSparseIndices_1[],
                                              int iSolutionId_2,
                                              int iElemCount_2,
                                              double dMipObj_2,
                                              const double Vals_2[],
                                              const int iSparseIndices_2[],
                                              double *dDiffMetric), void *p);
  int XPRS_CC XPRS_mse_getcbgetsolutiondiff (XPRSmipsolenum mse,
                                             int (XPRS_CC **
                                                  f_mse_getsolutiondiff)
                                             (XPRSmipsolenum mse,
                                              void *vContext, int nCols,
                                              int iSolutionId_1,
                                              int iElemCount_1,
                                              double dMipObj_1,
                                              const double Vals_1[],
                                              const int iSparseIndices_1[],
                                              int iSolutionId_2,
                                              int iElemCount_2,
                                              double dMipObj_2,
                                              const double Vals_2[],
                                              const int iSparseIndices_2[],
                                              double *dDiffMetric), void **p);
  int XPRS_CC XPRSinitializenlphessian (XPRSprob prob, const int mstart[],
                                        const int mcol[]);
  int XPRS_CC XPRSinitializenlphessian_indexpairs (XPRSprob prob, int nqcelem,
                                                   const int mcol1[],
                                                   const int mcol2[]);
  int XPRS_CC XPRSsetcbnlpevaluate (XPRSprob prob,
                                    void (XPRS_CC *
                                          f_evaluate) (XPRSprob prob,
                                                       void *vContext,
                                                       const double x[],
                                                       double *v), void *p);
  int XPRS_CC XPRSsetcbnlpgradient (XPRSprob prob,
                                    void (XPRS_CC *
                                          f_gradient) (XPRSprob prob,
                                                       void *vContext,
                                                       const double x[],
                                                       double g[]), void *p);
  int XPRS_CC XPRSsetcbnlphessian (XPRSprob prob,
                                   void (XPRS_CC * f_hessian) (XPRSprob prob,
                                                               void *vContext,
                                                               const double
                                                               x[],
                                                               const int
                                                               mstart[],
                                                               const int
                                                               mqcol[],
                                                               double dqe[]),
                                   void *p);
  int XPRS_CC XPRSgetcbnlpevaluate (XPRSprob prob,
                                    void (XPRS_CC **
                                          f_evaluate) (XPRSprob prob,
                                                       void *vContext,
                                                       const double x[],
                                                       double *v), void **p);
  int XPRS_CC XPRSgetcbnlpgradient (XPRSprob prob,
                                    void (XPRS_CC **
                                          f_gradient) (XPRSprob prob,
                                                       void *vContext,
                                                       const double x[],
                                                       double g[]), void **p);
  int XPRS_CC XPRSgetcbnlphessian (XPRSprob prob,
                                   void (XPRS_CC ** f_hessian) (XPRSprob prob,
                                                                void
                                                                *vContext,
                                                                const double
                                                                x[],
                                                                const int
                                                                mstart[],
                                                                const int
                                                                mqcol[],
                                                                double dqe[]),
                                   void **p);
  int XPRS_CC XPRSresetnlp (XPRSprob prob);
  int XPRS_CC XPRSsetcbbariteration (XPRSprob prob,
                                     void (XPRS_CC *
                                           f_evaluate) (XPRSprob prob,
                                                        void *vContext,
                                                        int *barrier_action),
                                     void *p);
  int XPRS_CC XPRSgetcbbariteration (XPRSprob prob,
                                     void (XPRS_CC **
                                           f_evaluate) (XPRSprob prob,
                                                        void *vContext,
                                                        int *barrier_action),
                                     void **p);
  int XPRS_CC XPRS_bo_create (XPRSbranchobject * p_object, XPRSprob prob,
                              int isoriginal);
  int XPRS_CC XPRS_bo_destroy (XPRSbranchobject obranch);
  int XPRS_CC XPRS_bo_store (XPRSbranchobject obranch, int *p_status);
  int XPRS_CC XPRS_bo_addbranches (XPRSbranchobject obranch, int nbranches);
  int XPRS_CC XPRS_bo_getbranches (XPRSbranchobject obranch,
                                   int *p_nbranches);
  int XPRS_CC XPRS_bo_setpriority (XPRSbranchobject obranch, int ipriority);
  int XPRS_CC XPRS_bo_setpreferredbranch (XPRSbranchobject obranch,
                                          int ibranch);
  int XPRS_CC XPRS_bo_addbounds (XPRSbranchobject obranch, int ibranch,
                                 int nbounds, const char cbndtype[],
                                 const int mbndcol[], const double dbndval[]);
  int XPRS_CC XPRS_bo_getbounds (XPRSbranchobject obranch, int ibranch,
                                 int *p_nbounds, int nbounds_size,
                                 char cbndtype[], int mbndcol[],
                                 double dbndval[]);
  int XPRS_CC XPRS_bo_addrows (XPRSbranchobject obranch, int ibranch,
                               int nrows, int nelems, const char crtype[],
                               const double drrhs[], const int mrbeg[],
                               const int mcol[], const double dval[]);
  int XPRS_CC XPRS_bo_getrows (XPRSbranchobject obranch, int ibranch,
                               int *p_nrows, int nrows_size, int *p_nelems,
                               int nelems_size, char crtype[], double drrhs[],
                               int mrbeg[], int mcol[], double dval[]);
  int XPRS_CC XPRS_bo_addcuts (XPRSbranchobject obranch, int ibranch,
                               int ncuts, const XPRScut mcutind[]);
  int XPRS_CC XPRS_bo_getid (XPRSbranchobject obranch, int *p_id);
  int XPRS_CC XPRS_bo_setcbmsghandler (XPRSbranchobject obranch,
                                       int (XPRS_CC *
                                            f_msghandler) (XPRSobject
                                                           vXPRSObject,
                                                           void *vUserContext,
                                                           void
                                                           *vSystemThreadId,
                                                           const char *sMsg,
                                                           int iMsgType,
                                                           int iMsgCode),
                                       void *p);
  int XPRS_CC XPRS_bo_getlasterror (XPRSbranchobject obranch, int *iMsgCode,
                                    char *_msg, int _iStringBufferBytes,
                                    int *_iBytesInInternalString);
#ifdef __cplusplus
}
#endif

#endif                          /* _XPRS_H */
