#ifndef _CPLEX_H
#define _CPLEX_H

/*
 * This header was partly generated from a solver header of the same name,
 * to make lazylpsolverlibs callable. It contains only constants,
 * structures, and macros generated from the original header, and thus,
 * contains no copyrightable information.
 *
 * Additionnal hand editing was also probably performed.
 */

#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPX_VERSION 1210
#include <stdio.h>
#ifdef _WIN32
#define CPXPUBLIC __stdcall
#define CPXPUBVARARGS __cdecl
#define CPXCDECL __cdecl
  typedef void *CPXFILEptr;
#else
#define CPXPUBLIC
#define CPXPUBVARARGS
#define CPXCDECL
  typedef FILE *CPXFILEptr;
#endif
#ifdef BUILD_CPXLIB
#if defined(_WIN32) || defined(__HP_cc)
#define CPXLIBAPI __declspec(dllexport)
#elif defined(__GNUC__) && defined(__linux__)
#define CPXLIBAPI __attribute__ ((visibility("default")))
#elif defined(__SUNPRO_C)
#define CPXLIBAPI __global
#else
#define CPXLIBAPI
#endif
#else
#if defined(_WIN32) && !defined(BUILD_CPXSTATIC)
#define CPXLIBAPI __declspec(dllimport)
#else
#define CPXLIBAPI
#endif
#endif
#define CPX_INFBOUND 1.0E+20
#define CPX_STR_PARAM_MAX 512
#define CPX_PARAMTYPE_NONE 0
#define CPX_PARAMTYPE_INT 1
#define CPX_PARAMTYPE_DOUBLE 2
#define CPX_PARAMTYPE_STRING 3
#define CPX_STAT_OPTIMAL 1
#define CPX_STAT_UNBOUNDED 2
#define CPX_STAT_INFEASIBLE 3
#define CPX_STAT_INForUNBD 4
#define CPX_STAT_OPTIMAL_INFEAS 5
#define CPX_STAT_NUM_BEST 6
#define CPX_STAT_ABORT_IT_LIM 10
#define CPX_STAT_ABORT_TIME_LIM 11
#define CPX_STAT_ABORT_OBJ_LIM 12
#define CPX_STAT_ABORT_USER 13
#define CPX_STAT_FEASIBLE_RELAXED_SUM 14
#define CPX_STAT_OPTIMAL_RELAXED_SUM 15
#define CPX_STAT_FEASIBLE_RELAXED_INF 16
#define CPX_STAT_OPTIMAL_RELAXED_INF 17
#define CPX_STAT_FEASIBLE_RELAXED_QUAD 18
#define CPX_STAT_OPTIMAL_RELAXED_QUAD 19
#define CPX_STAT_FEASIBLE 23
#define CPX_NO_SOLN 0
#define CPX_BASIC_SOLN 1
#define CPX_NONBASIC_SOLN 2
#define CPX_PRIMAL_SOLN 3
#define CPX_PRECOL_LOW -1
#define CPX_PRECOL_UP -2
#define CPX_PRECOL_FIX -3
#define CPX_PRECOL_AGG -4
#define CPX_PRECOL_OTHER -5
#define CPX_PREROW_RED -1
#define CPX_PREROW_AGG -2
#define CPX_PREROW_OTHER -3
#define CPXERR_NO_MEMORY 1001
#define CPXERR_NO_ENVIRONMENT 1002
#define CPXERR_BAD_ARGUMENT 1003
#define CPXERR_NULL_POINTER 1004
#define CPXERR_CALLBACK 1006
#define CPXERR_NO_PROBLEM 1009
#define CPXERR_LIMITS_TOO_BIG 1012
#define CPXERR_BAD_PARAM_NUM 1013
#define CPXERR_PARAM_TOO_SMALL 1014
#define CPXERR_PARAM_TOO_BIG 1015
#define CPXERR_RESTRICTED_VERSION 1016
#define CPXERR_NOT_FOR_MIP 1017
#define CPXERR_NOT_FOR_QP 1018
#define CPXERR_CHILD_OF_CHILD 1019
#define CPXERR_TOO_MANY_THREADS 1020
#define CPXERR_CANT_CLOSE_CHILD 1021
#define CPXERR_BAD_PROB_TYPE 1022
#define CPXERR_NOT_ONE_PROBLEM 1023
#define CPXERR_NOT_MILPCLASS 1024
#define CPXERR_STR_PARAM_TOO_LONG 1026
#define CPXERR_DECOMPRESSION 1027
#define CPXERR_BAD_PARAM_NAME 1028
#define CPXERR_NOT_MIQPCLASS 1029
#define CPXERR_NOT_FOR_QCP 1031
#define CPXERR_MSG_NO_CHANNEL 1051
#define CPXERR_MSG_NO_FILEPTR 1052
#define CPXERR_MSG_NO_FUNCTION 1053
#define CPXERR_PRESLV_INForUNBD 1101
#define CPXERR_PRESLV_NO_PROB 1103
#define CPXERR_PRESLV_ABORT 1106
#define CPXERR_PRESLV_BASIS_MEM 1107
#define CPXERR_PRESLV_COPYSOS 1108
#define CPXERR_PRESLV_COPYORDER 1109
#define CPXERR_PRESLV_SOLN_MIP 1110
#define CPXERR_PRESLV_SOLN_QP 1111
#define CPXERR_PRESLV_START_LP 1112
#define CPXERR_PRESLV_FAIL_BASIS 1114
#define CPXERR_PRESLV_NO_BASIS 1115
#define CPXERR_PRESLV_INF 1117
#define CPXERR_PRESLV_UNBD 1118
#define CPXERR_PRESLV_DUAL 1119
#define CPXERR_PRESLV_UNCRUSHFORM 1120
#define CPXERR_PRESLV_CRUSHFORM 1121
#define CPXERR_PRESLV_BAD_PARAM 1122
#define CPXERR_PRESLV_TIME_LIM 1123
#define CPXERR_INDEX_RANGE 1200
#define CPXERR_COL_INDEX_RANGE 1201
#define CPXERR_ROW_INDEX_RANGE 1203
#define CPXERR_INDEX_RANGE_LOW 1205
#define CPXERR_INDEX_RANGE_HIGH 1206
#define CPXERR_NEGATIVE_SURPLUS 1207
#define CPXERR_ARRAY_TOO_LONG 1208
#define CPXERR_NAME_CREATION 1209
#define CPXERR_NAME_NOT_FOUND 1210
#define CPXERR_NO_RHS_IN_OBJ 1211
#define CPXERR_BAD_SENSE 1215
#define CPXERR_NO_RNGVAL 1216
#define CPXERR_NO_SOLN 1217
#define CPXERR_NO_NAMES 1219
#define CPXERR_NOT_FIXED 1221
#define CPXERR_DUP_ENTRY 1222
#define CPXERR_NO_BARRIER_SOLN 1223
#define CPXERR_NULL_NAME 1224
#define CPXERR_NAN 1225
#define CPXERR_ARRAY_NOT_ASCENDING 1226
#define CPXERR_COUNT_RANGE 1227
#define CPXERR_COUNT_OVERLAP 1228
#define CPXERR_BAD_LUB 1229
#define CPXERR_NODE_INDEX_RANGE 1230
#define CPXERR_ARC_INDEX_RANGE 1231
#define CPXERR_NO_DUAL_SOLN 1232
#define CPXERR_DBL_MAX 1233
#define CPXERR_THREAD_FAILED 1234
#define CPXERR_INDEX_NOT_BASIC 1251
#define CPXERR_NEED_OPT_SOLN 1252
#define CPXERR_BAD_STATUS 1253
#define CPXERR_NOT_UNBOUNDED 1254
#define CPXERR_SBASE_INCOMPAT 1255
#define CPXERR_SINGULAR 1256
#define CPXERR_PRIIND 1257
#define CPXERR_NO_LU_FACTOR 1258
#define CPXERR_NO_SENSIT 1260
#define CPXERR_NO_BASIC_SOLN 1261
#define CPXERR_NO_BASIS 1262
#define CPXERR_ABORT_STRONGBRANCH 1263
#define CPXERR_NO_NORMS 1264
#define CPXERR_NOT_DUAL_UNBOUNDED 1265
#define CPXERR_TILIM_STRONGBRANCH 1266
#define CPXERR_BAD_PIVOT 1267
#define CPXERR_TILIM_CONDITION_NO 1268
#define CPXERR_BAD_METHOD 1292
#define CPXERR_NO_FILENAME 1421
#define CPXERR_FAIL_OPEN_WRITE 1422
#define CPXERR_FAIL_OPEN_READ 1423
#define CPXERR_BAD_FILETYPE 1424
#define CPXERR_XMLPARSE 1425
#define CPXERR_TOO_MANY_ROWS 1431
#define CPXERR_TOO_MANY_COLS 1432
#define CPXERR_TOO_MANY_COEFFS 1433
#define CPXERR_BAD_NUMBER 1434
#define CPXERR_BAD_EXPO_RANGE 1435
#define CPXERR_NO_OBJ_SENSE 1436
#define CPXERR_QCP_SENSE_FILE 1437
#define CPXERR_BAD_LAZY_UCUT 1438
#define CPXERR_BAD_INDCONSTR 1439
#define CPXERR_NO_NAME_SECTION 1441
#define CPXERR_BAD_SOS_TYPE 1442
#define CPXERR_COL_ROW_REPEATS 1443
#define CPXERR_RIM_ROW_REPEATS 1444
#define CPXERR_ROW_REPEATS 1445
#define CPXERR_COL_REPEATS 1446
#define CPXERR_RIM_REPEATS 1447
#define CPXERR_ROW_UNKNOWN 1448
#define CPXERR_COL_UNKNOWN 1449
#define CPXERR_NO_ROW_SENSE 1453
#define CPXERR_EXTRA_FX_BOUND 1454
#define CPXERR_EXTRA_FR_BOUND 1455
#define CPXERR_EXTRA_BV_BOUND 1456
#define CPXERR_BAD_BOUND_TYPE 1457
#define CPXERR_UP_BOUND_REPEATS 1458
#define CPXERR_LO_BOUND_REPEATS 1459
#define CPXERR_NO_BOUND_TYPE 1460
#define CPXERR_NO_QMATRIX_SECTION 1461
#define CPXERR_BAD_SECTION_ENDATA 1462
#define CPXERR_INT_TOO_BIG_INPUT 1463
#define CPXERR_NAME_TOO_LONG 1464
#define CPXERR_LINE_TOO_LONG 1465
#define CPXERR_NO_ROWS_SECTION 1471
#define CPXERR_NO_COLUMNS_SECTION 1472
#define CPXERR_BAD_SECTION_BOUNDS 1473
#define CPXERR_RANGE_SECTION_ORDER 1474
#define CPXERR_BAD_SECTION_QMATRIX 1475
#define CPXERR_NO_OBJECTIVE 1476
#define CPXERR_ROW_REPEAT_PRINT 1477
#define CPXERR_COL_REPEAT_PRINT 1478
#define CPXERR_RIMNZ_REPEATS 1479
#define CPXERR_EXTRA_INTORG 1480
#define CPXERR_EXTRA_INTEND 1481
#define CPXERR_EXTRA_SOSORG 1482
#define CPXERR_EXTRA_SOSEND 1483
#define CPXERR_TOO_MANY_RIMS 1484
#define CPXERR_TOO_MANY_RIMNZ 1485
#define CPXERR_NO_ROW_NAME 1486
#define CPXERR_BAD_OBJ_SENSE 1487
#define CPXERR_BAS_FILE_SHORT 1550
#define CPXERR_BAD_INDICATOR 1551
#define CPXERR_NO_ENDATA 1552
#define CPXERR_FILE_ENTRIES 1553
#define CPXERR_SBASE_ILLEGAL 1554
#define CPXERR_BAS_FILE_SIZE 1555
#define CPXERR_NO_VECTOR_SOLN 1556
#define CPXERR_NOT_SAV_FILE 1560
#define CPXERR_SAV_FILE_DATA 1561
#define CPXERR_SAV_FILE_WRITE 1562
#define CPXERR_FILE_FORMAT 1563
#define CPXERR_ADJ_SIGNS 1602
#define CPXERR_RHS_IN_OBJ 1603
#define CPXERR_ADJ_SIGN_SENSE 1604
#define CPXERR_QUAD_IN_ROW 1605
#define CPXERR_ADJ_SIGN_QUAD 1606
#define CPXERR_NO_OPERATOR 1607
#define CPXERR_NO_OP_OR_SENSE 1608
#define CPXERR_NO_ID_FIRST 1609
#define CPXERR_NO_RHS_COEFF 1610
#define CPXERR_NO_NUMBER_FIRST 1611
#define CPXERR_NO_QUAD_EXP 1612
#define CPXERR_QUAD_EXP_NOT_2 1613
#define CPXERR_NO_QP_OPERATOR 1614
#define CPXERR_NO_NUMBER 1615
#define CPXERR_NO_ID 1616
#define CPXERR_BAD_ID 1617
#define CPXERR_BAD_EXPONENT 1618
#define CPXERR_Q_DIVISOR 1619
#define CPXERR_NO_BOUND_SENSE 1621
#define CPXERR_BAD_BOUND_SENSE 1622
#define CPXERR_NO_NUMBER_BOUND 1623
#define CPXERR_NO_SOS_SEPARATOR 1627
#define CPXERR_INVALID_NUMBER 1650
#define CPXERR_PRM_DATA 1660
#define CPXERR_PRM_HEADER 1661
#define CPXERR_NO_CONFLICT 1719
#define CPXERR_CONFLICT_UNSTABLE 1720
#define CPXERR_WORK_FILE_OPEN 1801
#define CPXERR_WORK_FILE_READ 1802
#define CPXERR_WORK_FILE_WRITE 1803
#define CPXERR_IN_INFOCALLBACK 1804
#define CPXERR_MIPSEARCH_WITH_CALLBACKS 1805
#define CPXERR_LP_NOT_IN_ENVIRONMENT 1806
#define CPXERR_PARAM_INCOMPATIBLE 1807
#define CPXERR_LICENSE_MIN 32000
#define CPXERR_ILOG_LICENSE 32201
#define CPXERR_NO_MIP_LIC 32301
#define CPXERR_NO_BARRIER_LIC 32302
#define CPXERR_NO_MIQP_LIC 32305
#define CPXERR_BADLDWID 32018
#define CPXERR_BADPRODUCT 32023
#define CPXERR_ALGNOTLICENSED 32024
#define CPXERR_LICENSE_MAX 32999
#define CPX_ON 1
#define CPX_OFF 0
#define CPX_MAX -1
#define CPX_MIN 1
#define CPX_PPRIIND_PARTIAL -1
#define CPX_PPRIIND_AUTO 0
#define CPX_PPRIIND_DEVEX 1
#define CPX_PPRIIND_STEEP 2
#define CPX_PPRIIND_STEEPQSTART 3
#define CPX_PPRIIND_FULL 4
#define CPX_DPRIIND_AUTO 0
#define CPX_DPRIIND_FULL 1
#define CPX_DPRIIND_STEEP 2
#define CPX_DPRIIND_FULLSTEEP 3
#define CPX_DPRIIND_STEEPQSTART 4
#define CPX_DPRIIND_DEVEX 5
#define CPX_PARALLEL_DETERMINISTIC 1
#define CPX_PARALLEL_AUTO 0
#define CPX_PARALLEL_OPPORTUNISTIC -1
#define CPX_WRITELEVEL_AUTO 0
#define CPX_WRITELEVEL_ALLVARS 1
#define CPX_WRITELEVEL_DISCRETEVARS 2
#define CPX_WRITELEVEL_NONZEROVARS 3
#define CPX_WRITELEVEL_NONZERODISCRETEVARS 4
#define CPX_ALG_NONE -1
#define CPX_ALG_AUTOMATIC 0
#define CPX_ALG_PRIMAL 1
#define CPX_ALG_DUAL 2
#define CPX_ALG_NET 3
#define CPX_ALG_BARRIER 4
#define CPX_ALG_SIFTING 5
#define CPX_ALG_CONCURRENT 6
#define CPX_ALG_BAROPT 7
#define CPX_ALG_PIVOTIN 8
#define CPX_ALG_PIVOTOUT 9
#define CPX_ALG_PIVOT 10
#define CPX_ALG_FEASOPT 11
#define CPX_ALG_MIP 12
#define CPX_ALG_ROBUST 13
#define CPX_AT_LOWER 0
#define CPX_BASIC 1
#define CPX_AT_UPPER 2
#define CPX_FREE_SUPER 3
#define CPX_NO_VARIABLE 2100000000
#define CPX_CONTINUOUS 'C'
#define CPX_BINARY 'B'
#define CPX_INTEGER 'I'
#define CPX_SEMICONT 'S'
#define CPX_SEMIINT 'N'
#define CPX_PREREDUCE_PRIMALANDDUAL 3
#define CPX_PREREDUCE_DUALONLY 2
#define CPX_PREREDUCE_PRIMALONLY 1
#define CPX_PREREDUCE_NOPRIMALORDUAL 0
#define CPX_STAT_CONFLICT_FEASIBLE 30
#define CPX_STAT_CONFLICT_MINIMAL 31
#define CPX_STAT_CONFLICT_ABORT_CONTRADICTION 32
#define CPX_STAT_CONFLICT_ABORT_TIME_LIM 33
#define CPX_STAT_CONFLICT_ABORT_IT_LIM 34
#define CPX_STAT_CONFLICT_ABORT_NODE_LIM 35
#define CPX_STAT_CONFLICT_ABORT_OBJ_LIM 36
#define CPX_STAT_CONFLICT_ABORT_MEM_LIM 37
#define CPX_STAT_CONFLICT_ABORT_USER 38
#define CPX_CONFLICT_EXCLUDED -1
#define CPX_CONFLICT_POSSIBLE_MEMBER 0
#define CPX_CONFLICT_POSSIBLE_LB 1
#define CPX_CONFLICT_POSSIBLE_UB 2
#define CPX_CONFLICT_MEMBER 3
#define CPX_CONFLICT_LB 4
#define CPX_CONFLICT_UB 5
#define CPXPROB_LP 0
#define CPXPROB_MILP 1
#define CPXPROB_FIXEDMILP 3
#define CPXPROB_NODELP 4
#define CPXPROB_QP 5
#define CPXPROB_MIQP 7
#define CPXPROB_FIXEDMIQP 8
#define CPXPROB_NODEQP 9
#define CPXPROB_QCP 10
#define CPXPROB_MIQCP 11
#define CPXPROB_NODEQCP 12
#define CPX_PARAM_ADVIND 1001
#define CPX_PARAM_AGGFILL 1002
#define CPX_PARAM_AGGIND 1003
#define CPX_PARAM_BASINTERVAL 1004
#define CPX_PARAM_CFILEMUL 1005
#define CPX_PARAM_CLOCKTYPE 1006
#define CPX_PARAM_CRAIND 1007
#define CPX_PARAM_DEPIND 1008
#define CPX_PARAM_DPRIIND 1009
#define CPX_PARAM_PRICELIM 1010
#define CPX_PARAM_EPMRK 1013
#define CPX_PARAM_EPOPT 1014
#define CPX_PARAM_EPPER 1015
#define CPX_PARAM_EPRHS 1016
#define CPX_PARAM_FASTMIP 1017
#define CPX_PARAM_SIMDISPLAY 1019
#define CPX_PARAM_ITLIM 1020
#define CPX_PARAM_ROWREADLIM 1021
#define CPX_PARAM_NETFIND 1022
#define CPX_PARAM_COLREADLIM 1023
#define CPX_PARAM_NZREADLIM 1024
#define CPX_PARAM_OBJLLIM 1025
#define CPX_PARAM_OBJULIM 1026
#define CPX_PARAM_PERIND 1027
#define CPX_PARAM_PERLIM 1028
#define CPX_PARAM_PPRIIND 1029
#define CPX_PARAM_PREIND 1030
#define CPX_PARAM_REINV 1031
#define CPX_PARAM_REVERSEIND 1032
#define CPX_PARAM_RFILEMUL 1033
#define CPX_PARAM_SCAIND 1034
#define CPX_PARAM_SCRIND 1035
#define CPX_PARAM_SINGLIM 1037
#define CPX_PARAM_SINGTOL 1038
#define CPX_PARAM_TILIM 1039
#define CPX_PARAM_XXXIND 1041
#define CPX_PARAM_PREDUAL 1044
#define CPX_PARAM_EPOPT_H 1049
#define CPX_PARAM_EPRHS_H 1050
#define CPX_PARAM_PREPASS 1052
#define CPX_PARAM_DATACHECK 1056
#define CPX_PARAM_REDUCE 1057
#define CPX_PARAM_PRELINEAR 1058
#define CPX_PARAM_LPMETHOD 1062
#define CPX_PARAM_QPMETHOD 1063
#define CPX_PARAM_WORKDIR 1064
#define CPX_PARAM_WORKMEM 1065
#define CPX_PARAM_THREADS 1067
#define CPX_PARAM_CONFLICTDISPLAY 1074
#define CPX_PARAM_SIFTDISPLAY 1076
#define CPX_PARAM_SIFTALG 1077
#define CPX_PARAM_SIFTITLIM 1078
#define CPX_PARAM_MPSLONGNUM 1081
#define CPX_PARAM_MEMORYEMPHASIS 1082
#define CPX_PARAM_NUMERICALEMPHASIS 1083
#define CPX_PARAM_FEASOPTMODE 1084
#define CPX_PARAM_PARALLELMODE 1109
#define CPX_PARAM_TUNINGMEASURE 1110
#define CPX_PARAM_TUNINGREPEAT 1111
#define CPX_PARAM_TUNINGTILIM 1112
#define CPX_PARAM_TUNINGDISPLAY 1113
#define CPX_PARAM_WRITELEVEL 1114
#define CPX_PARAM_ALL_MIN 1000
#define CPX_PARAM_ALL_MAX 6000
#define CPX_CALLBACK_PRIMAL 1
#define CPX_CALLBACK_DUAL 2
#define CPX_CALLBACK_NETWORK 3
#define CPX_CALLBACK_PRIMAL_CROSSOVER 4
#define CPX_CALLBACK_DUAL_CROSSOVER 5
#define CPX_CALLBACK_BARRIER 6
#define CPX_CALLBACK_PRESOLVE 7
#define CPX_CALLBACK_QPBARRIER 8
#define CPX_CALLBACK_QPSIMPLEX 9
#define CPX_CALLBACK_TUNING 10
#define CPX_CALLBACK_INFO_PRIMAL_OBJ 1
#define CPX_CALLBACK_INFO_DUAL_OBJ 2
#define CPX_CALLBACK_INFO_PRIMAL_INFMEAS 3
#define CPX_CALLBACK_INFO_DUAL_INFMEAS 4
#define CPX_CALLBACK_INFO_PRIMAL_FEAS 5
#define CPX_CALLBACK_INFO_DUAL_FEAS 6
#define CPX_CALLBACK_INFO_ITCOUNT 7
#define CPX_CALLBACK_INFO_CROSSOVER_PPUSH 8
#define CPX_CALLBACK_INFO_CROSSOVER_PEXCH 9
#define CPX_CALLBACK_INFO_CROSSOVER_DPUSH 10
#define CPX_CALLBACK_INFO_CROSSOVER_DEXCH 11
#define CPX_CALLBACK_INFO_CROSSOVER_SBCNT 12
#define CPX_CALLBACK_INFO_PRESOLVE_ROWSGONE 13
#define CPX_CALLBACK_INFO_PRESOLVE_COLSGONE 14
#define CPX_CALLBACK_INFO_PRESOLVE_AGGSUBST 15
#define CPX_CALLBACK_INFO_PRESOLVE_COEFFS 16
#define CPX_CALLBACK_INFO_USER_PROBLEM 17
#define CPX_CALLBACK_INFO_TUNING_PROGRESS 18
#define CPX_CALLBACK_INFO_ENDTIME 19
#define CPX_TUNE_AVERAGE 1
#define CPX_TUNE_MINMAX 2
#define CPX_TUNE_ABORT 1
#define CPX_TUNE_TILIM 2
#define CPX_MAX_PRIMAL_INFEAS 1
#define CPX_MAX_SCALED_PRIMAL_INFEAS 2
#define CPX_SUM_PRIMAL_INFEAS 3
#define CPX_SUM_SCALED_PRIMAL_INFEAS 4
#define CPX_MAX_DUAL_INFEAS 5
#define CPX_MAX_SCALED_DUAL_INFEAS 6
#define CPX_SUM_DUAL_INFEAS 7
#define CPX_SUM_SCALED_DUAL_INFEAS 8
#define CPX_MAX_INT_INFEAS 9
#define CPX_SUM_INT_INFEAS 10
#define CPX_MAX_PRIMAL_RESIDUAL 11
#define CPX_MAX_SCALED_PRIMAL_RESIDUAL 12
#define CPX_SUM_PRIMAL_RESIDUAL 13
#define CPX_SUM_SCALED_PRIMAL_RESIDUAL 14
#define CPX_MAX_DUAL_RESIDUAL 15
#define CPX_MAX_SCALED_DUAL_RESIDUAL 16
#define CPX_SUM_DUAL_RESIDUAL 17
#define CPX_SUM_SCALED_DUAL_RESIDUAL 18
#define CPX_MAX_COMP_SLACK 19
#define CPX_SUM_COMP_SLACK 21
#define CPX_MAX_X 23
#define CPX_MAX_SCALED_X 24
#define CPX_MAX_PI 25
#define CPX_MAX_SCALED_PI 26
#define CPX_MAX_SLACK 27
#define CPX_MAX_SCALED_SLACK 28
#define CPX_MAX_RED_COST 29
#define CPX_MAX_SCALED_RED_COST 30
#define CPX_SUM_X 31
#define CPX_SUM_SCALED_X 32
#define CPX_SUM_PI 33
#define CPX_SUM_SCALED_PI 34
#define CPX_SUM_SLACK 35
#define CPX_SUM_SCALED_SLACK 36
#define CPX_SUM_RED_COST 37
#define CPX_SUM_SCALED_RED_COST 38
#define CPX_KAPPA 39
#define CPX_OBJ_GAP 40
#define CPX_DUAL_OBJ 41
#define CPX_PRIMAL_OBJ 42
#define CPX_MAX_QCPRIMAL_RESIDUAL 43
#define CPX_SUM_QCPRIMAL_RESIDUAL 44
#define CPX_MAX_QCSLACK_INFEAS 45
#define CPX_SUM_QCSLACK_INFEAS 46
#define CPX_MAX_QCSLACK 47
#define CPX_SUM_QCSLACK 48
#define CPX_MAX_INDSLACK_INFEAS 49
#define CPX_SUM_INDSLACK_INFEAS 50
#define CPX_EXACT_KAPPA 51
  struct cpxenv;
  typedef struct cpxenv *CPXENVptr;
  typedef const struct cpxenv *CPXCENVptr;
  struct cpxchannel;
  typedef struct cpxchannel *CPXCHANNELptr;
  struct cpxlp;
  typedef struct cpxlp *CPXLPptr;
  typedef const struct cpxlp *CPXCLPptr;
  struct cpxnet;
  typedef struct cpxnet *CPXNETptr;
  typedef const struct cpxnet *CPXCNETptr;
  typedef char *CPXCHARptr;
  typedef const char *CPXCCHARptr;
  typedef void *CPXVOIDptr;
#ifndef CPX_MODERN
#define CPXoptimize CPXlpopt
#define CPXgetsbcnt CPXgetpsbcnt
#endif
    CPXLIBAPI
    CPXLPptr CPXPUBLIC
    CPXcreateprob (CPXCENVptr env, int *status_p, const char *probname_str);
    CPXLIBAPI
    CPXLPptr CPXPUBLIC
    CPXcloneprob (CPXCENVptr env, CPXCLPptr lp, int *status_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopylpwnames (CPXCENVptr env, CPXLPptr lp, int numcols,
                     int numrows, int objsense, const double *objective,
                     const double *rhs, const char *sense,
                     const int *matbeg, const int *matcnt,
                     const int *matind, const double *matval,
                     const double *lb, const double *ub,
                     const double *rngval, char **colname, char **rowname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopylp (CPXCENVptr env, CPXLPptr lp, int numcols,
               int numrows, int objsense, const double *objective,
               const double *rhs, const char *sense,
               const int *matbeg, const int *matcnt,
               const int *matind, const double *matval,
               const double *lb, const double *ub, const double *rngval);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopyobjname (CPXCENVptr env, CPXLPptr lp, const char *objname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopybase (CPXCENVptr env, CPXLPptr lp, const int *cstat,
                 const int *rstat);
    CPXLIBAPI
    int CPXPUBLIC CPXcleanup (CPXCENVptr env, CPXLPptr lp, double eps);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopystart (CPXCENVptr env, CPXLPptr lp, const int *cstat,
                  const int *rstat, const double *cprim,
                  const double *rprim, const double *cdual,
                  const double *rdual);
    CPXLIBAPI int CPXPUBLIC CPXfreeprob (CPXCENVptr env, CPXLPptr * lp_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopynettolp (CPXCENVptr env, CPXLPptr lp, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETextract (CPXCENVptr env, CPXNETptr net, CPXCLPptr lp,
                   int *colmap, int *rowmap);
    CPXLIBAPI int CPXPUBLIC CPXlpopt (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXconcurrentlpopt (CPXCENVptr env, CPXCENVptr * childenv,
                        CPXLPptr lp, int P);
    CPXLIBAPI
    int CPXPUBLIC
    CPXconcurrentmipopt (CPXCENVptr env, CPXCENVptr * childenv,
                         CPXLPptr lp, int P);
    CPXLIBAPI int CPXPUBLIC CPXprimopt (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXdualopt (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXhybnetopt (CPXCENVptr env, CPXLPptr lp, int method);
    CPXLIBAPI int CPXPUBLIC CPXsiftopt (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpratio (CPXCENVptr env, CPXLPptr lp, const int *indices,
               int cnt, double *downratio, double *upratio,
               int *downleave, int *upleave,
               int *downleavestatus, int *upleavestatus,
               int *downstatus, int *upstatus);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdratio (CPXCENVptr env, CPXLPptr lp, const int *indices,
               int cnt, double *downratio, double *upratio,
               int *downenter, int *upenter, int *downstatus, int *upstatus);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpivot (CPXCENVptr env, CPXLPptr lp, int jenter,
              int jleave, int leavestat);
    CPXLIBAPI int CPXPUBLIC CPXsetphase2 (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXcheckpfeas (CPXCENVptr env, CPXLPptr lp, int *infeas_p);
    CPXLIBAPI
    int CPXPUBLIC CPXcheckdfeas (CPXCENVptr env, CPXLPptr lp, int *infeas_p);
    CPXLIBAPI
    int CPXPUBLIC CPXchecksoln (CPXCENVptr env, CPXLPptr lp, int *lpstatus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsolution (CPXCENVptr env, CPXCLPptr lp, int *lpstat_p,
                 double *objval_p, double *x, double *pi,
                 double *slack, double *dj);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsolninfo (CPXCENVptr env, CPXCLPptr lp,
                 int *solnmethod_p, int *solntype_p,
                 int *pfeasind_p, int *dfeasind_p);
    CPXLIBAPI int CPXPUBLIC CPXgetstat (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    CPXCHARptr CPXPUBLIC
    CPXgetstatstring (CPXCENVptr env, int statind, char *buffer_str);
    CPXLIBAPI int CPXPUBLIC CPXgetmethod (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetx (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetax (CPXCENVptr env, CPXCLPptr lp, double *x, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetpi (CPXCENVptr env, CPXCLPptr lp, double *pi, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetslack (CPXCENVptr env, CPXCLPptr lp, double *slack,
                 int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrowinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x,
                     double *infeasout, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcolinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x,
                     double *infeasout, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetdj (CPXCENVptr env, CPXCLPptr lp, double *dj, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetgrad (CPXCENVptr env, CPXCLPptr lp, int j, int *head, double *y);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetijdiv (CPXCENVptr env, CPXCLPptr lp, int *idiv_p, int *jdiv_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetbase (CPXCENVptr env, CPXCLPptr lp, int *cstat, int *rstat);
    CPXLIBAPI int CPXPUBLIC CPXgetitcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetphase1cnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetsiftitcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetsiftphase1cnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetbaritcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetcrossppushcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetcrosspexchcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetcrossdpushcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetcrossdexchcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetpsbcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetdsbcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetdblquality (CPXCENVptr env, CPXCLPptr lp,
                      double *quality_p, int what);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpooldblquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              double *quality_p, int what);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetintquality (CPXCENVptr env, CPXCLPptr lp, int *quality_p, int what);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolintquality (CPXCENVptr env, CPXCLPptr lp, int soln,
                              int *quality_p, int what);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrhssa (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
              double *lower, double *upper);
    CPXLIBAPI
    int CPXPUBLIC
    CPXboundsa (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
                double *lblower, double *lbupper, double *ublower,
                double *ubupper);
    CPXLIBAPI
    int CPXPUBLIC
    CPXobjsa (CPXCENVptr env, CPXCLPptr lp, int begin, int end,
              double *lower, double *upper);
    CPXLIBAPI
    int CPXPUBLIC
    CPXErangesa (CPXENVptr env, CPXLPptr lp, int begin, int end,
                 double *lblower, double *lbupper, double *ublower,
                 double *ubupper);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrefineconflict (CPXCENVptr env, CPXLPptr lp,
                       int *confnumrows_p, int *confnumcols_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetconflict (CPXCENVptr env, CPXCLPptr lp, int *confstat_p,
                    int *rowind, int *rowbdstat, int *confnumrows_p,
                    int *colind, int *colbdstat, int *confnumcols_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrefineconflictext (CPXCENVptr env, CPXLPptr lp, int grpcnt,
                          int concnt, const double *grppref,
                          const int *grpbeg, const int *grpind,
                          const char *grptype);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetconflictext (CPXCENVptr env, CPXCLPptr lp,
                       int *grpstat, int beg, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXclpwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrobustopt (CPXCENVptr env, CPXLPptr lp, CPXLPptr lblp, CPXLPptr ublp,
                  double objchg, const double *maxchg);
#define CPX_FEASOPT_MIN_SUM 0
#define CPX_FEASOPT_OPT_SUM 1
#define CPX_FEASOPT_MIN_INF 2
#define CPX_FEASOPT_OPT_INF 3
#define CPX_FEASOPT_MIN_QUAD 4
#define CPX_FEASOPT_OPT_QUAD 5
    CPXLIBAPI
    int CPXPUBLIC
    CPXfeasopt (CPXCENVptr env, CPXLPptr lp, const double *rhs,
                const double *rng, const double *lb, const double *ub);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEfeasopt (CPXCENVptr env, CPXLPptr lp, const double *rhs,
                 const double *rng, const double *lb, const double *ub,
                 const double *qrhs);
    CPXLIBAPI
    int CPXPUBLIC
    CPXfeasoptext (CPXCENVptr env, CPXLPptr lp, int grpcnt, int concnt,
                   const double *grppref, const int *grpbeg,
                   const int *grpind, const char *grptype);
    CPXLIBAPI int CPXPUBLIC CPXnewrows (CPXCENVptr env, CPXLPptr lp, int rcnt,
                                        const double *rhs, const char *sense,
                                        const double *rngval, char **rowname);
    CPXLIBAPI int CPXPUBLIC CPXaddrows (CPXCENVptr env, CPXLPptr lp, int ccnt,
                                        int rcnt, int nzcnt,
                                        const double *rhs, const char *sense,
                                        const int *rmatbeg,
                                        const int *rmatind,
                                        const double *rmatval, char **colname,
                                        char **rowname);
    CPXLIBAPI int CPXPUBLIC CPXnewcols (CPXCENVptr env, CPXLPptr lp, int ccnt,
                                        const double *obj, const double *lb,
                                        const double *ub, const char *xctype,
                                        char **colname);
    CPXLIBAPI int CPXPUBLIC CPXaddcols (CPXCENVptr env, CPXLPptr lp, int ccnt,
                                        int nzcnt, const double *obj,
                                        const int *cmatbeg,
                                        const int *cmatind,
                                        const double *cmatval,
                                        const double *lb, const double *ub,
                                        char **colname);
    CPXLIBAPI int CPXPUBLIC CPXdelrows (CPXCENVptr env, CPXLPptr lp,
                                        int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXdelsetrows (CPXCENVptr env, CPXLPptr lp,
                                           int *delstat);
    CPXLIBAPI int CPXPUBLIC CPXdelcols (CPXCENVptr env, CPXLPptr lp,
                                        int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXdelsetcols (CPXCENVptr env, CPXLPptr lp,
                                           int *delstat);
    CPXLIBAPI int CPXPUBLIC CPXchgname (CPXCENVptr env, CPXLPptr lp, int key,
                                        int ij, const char *newname_str);
    CPXLIBAPI int CPXPUBLIC CPXchgrowname (CPXCENVptr env, CPXLPptr lp,
                                           int cnt, const int *indices,
                                           char **newname);
    CPXLIBAPI int CPXPUBLIC CPXchgcolname (CPXCENVptr env, CPXLPptr lp,
                                           int cnt, const int *indices,
                                           char **newname);
    CPXLIBAPI int CPXPUBLIC CPXdelnames (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgprobname (CPXCENVptr env, CPXLPptr lp, const char *probname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgcoef (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgcoeflist (CPXCENVptr env, CPXLPptr lp, int numcoefs,
                    const int *rowlist, const int *collist,
                    const double *vallist);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgbds (CPXCENVptr env, CPXLPptr lp, int cnt,
               const int *indices, const char *lu, const double *bd);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgobj (CPXCENVptr env, CPXLPptr lp, int cnt,
               const int *indices, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgrhs (CPXCENVptr env, CPXLPptr lp, int cnt,
               const int *indices, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgrngval (CPXCENVptr env, CPXLPptr lp, int cnt,
                  const int *indices, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgsense (CPXCENVptr env, CPXLPptr lp, int cnt,
                 const int *indices, const char *sense);
    CPXLIBAPI
    void CPXPUBLIC CPXchgobjsen (CPXCENVptr env, CPXLPptr lp, int maxormin);
    CPXLIBAPI
    int CPXPUBLIC CPXchgprobtype (CPXCENVptr env, CPXLPptr lp, int type);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgprobtypesolnpool (CPXCENVptr env, CPXLPptr lp, int type, int soln);
    CPXLIBAPI int CPXPUBLIC CPXcompletelp (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpreaddrows (CPXCENVptr env, CPXLPptr lp, int rcnt, int nzcnt,
                   const double *rhs, const char *sense,
                   const int *rmatbeg, const int *rmatind,
                   const double *rmatval, char **rowname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXprechgobj (CPXCENVptr env, CPXLPptr lp, int cnt,
                  const int *indices, const double *values);
    CPXLIBAPI int CPXPUBLIC CPXgetnumcols (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumrows (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumnz (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetobjsen (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetobj (CPXCENVptr env, CPXCLPptr lp, double *obj, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrhs (CPXCENVptr env, CPXCLPptr lp, double *rhs, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsense (CPXCENVptr env, CPXCLPptr lp, char *sense,
                 int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcols (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p,
                int *cmatbeg, int *cmatind, double *cmatval,
                int cmatspace, int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrows (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p,
                int *rmatbeg, int *rmatind, double *rmatval,
                int rmatspace, int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetlb (CPXCENVptr env, CPXCLPptr lp, double *lb, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetub (CPXCENVptr env, CPXCLPptr lp, double *ub, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrngval (CPXCENVptr env, CPXCLPptr lp, double *rngval,
                  int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetprobname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                    int bufspace, int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetobjname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                   int bufspace, int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcolname (CPXCENVptr env, CPXCLPptr lp, char **name,
                   char *namestore, int storespace,
                   int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrowname (CPXCENVptr env, CPXCLPptr lp, char **name,
                   char *namestore, int storespace,
                   int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcoef (CPXCENVptr env, CPXCLPptr lp, int i, int j, double *coef_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetrowindex (CPXCENVptr env, CPXCLPptr lp,
                    const char *lname_str, int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcolindex (CPXCENVptr env, CPXCLPptr lp,
                    const char *lname_str, int *index_p);
    CPXLIBAPI int CPXPUBLIC CPXgetprobtype (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXreadcopyprob (CPXCENVptr env, CPXLPptr lp,
                     const char *filename_str, const char *filetype_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXreadcopybase (CPXCENVptr env, CPXLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXreadcopysol (CPXCENVptr env, CPXLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXwriteprob (CPXCENVptr env, CPXCLPptr lp,
                  const char *filename_str, const char *filetype_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXmbasewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsolwritesolnpool (CPXCENVptr env, CPXCLPptr lp, int soln,
                         const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsolwritesolnpoolall (CPXCENVptr env, CPXCLPptr lp,
                            const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXembwrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdperwrite (CPXCENVptr env, CPXLPptr lp,
                  const char *filename_str, double epsilon);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpperwrite (CPXCENVptr env, CPXLPptr lp,
                  const char *filename_str, double epsilon);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpreslvwrite (CPXCENVptr env, CPXLPptr lp,
                    const char *filename_str, double *objoff_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdualwrite (CPXCENVptr env, CPXCLPptr lp,
                  const char *filename_str, double *objshift_p);
    CPXLIBAPI int CPXPUBLIC CPXsetdefaults (CPXENVptr env);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetintparam (CPXENVptr env, int whichparam, int newvalue);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetdblparam (CPXENVptr env, int whichparam, double newvalue);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetstrparam (CPXENVptr env, int whichparam, const char *newvalue_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetintparam (CPXCENVptr env, int whichparam, int *value_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetdblparam (CPXCENVptr env, int whichparam, double *value_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetstrparam (CPXCENVptr env, int whichparam, char *value_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXinfointparam (CPXCENVptr env, int whichparam, int *defvalue_p,
                     int *minvalue_p, int *maxvalue_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXinfodblparam (CPXCENVptr env, int whichparam,
                     double *defvalue_p, double *minvalue_p,
                     double *maxvalue_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXinfostrparam (CPXCENVptr env, int whichparam, char *defvalue_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetparamname (CPXCENVptr env, int whichparam, char *name_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetparamnum (CPXCENVptr env, const char *name_str, int *whichparam_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetparamtype (CPXCENVptr env, int whichparam, int *paramtype);
    CPXLIBAPI
    int CPXPUBLIC CPXreadcopyparam (CPXENVptr env, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC CPXwriteparam (CPXCENVptr env, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetchgparam (CPXCENVptr env, int *cnt_p, int *paramnum,
                    int pspace, int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXtuneparam (CPXENVptr env, CPXLPptr lp,
                  int intcnt, const int *intnum, const int *intval,
                  int dblcnt, const int *dblnum, const double *dblval,
                  int strcnt, const int *strnum, char **strval,
                  int *tunestat_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXtuneparamprobset (CPXENVptr env, int filecnt, char **filename,
                         char **filetype,
                         int intcnt, const int *intind, const int *intval,
                         int dblcnt, const int *dblind, const double *dblval,
                         int strcnt, const int *strind, char **strval,
                         int *tunestat_p);
    CPXLIBAPI CPXCCHARptr CPXPUBLIC CPXversion (CPXCENVptr env);
    CPXLIBAPI CPXENVptr CPXPUBLIC CPXopenCPLEX (int *status_p);
    CPXLIBAPI
    CPXENVptr CPXPUBLIC
    CPXopenCPLEXruntime (int *status_p, int serialnum,
                         const char *licenvstring_str);
    CPXLIBAPI int CPXPUBLIC CPXcloseCPLEX (CPXENVptr * env_p);
#define CPXRegisterLicense CPXsetstaringsol
    CPXLIBAPI
    int CPXPUBLIC
    CPXRegisterLicense (const char *ilm_license_str,
                        int ilm_license_signature);
    CPXLIBAPI CPXENVptr CPXPUBLIC CPXparenv (CPXENVptr env, int *status_p);
    CPXLIBAPI
    int CPXPUBLIC CPXfreeparenv (CPXENVptr env, CPXENVptr * child_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckcopylp (CPXCENVptr env, CPXCLPptr lp, int numcols,
                    int numrows, int objsen, const double *obj,
                    const double *rhs, const char *sense,
                    const int *matbeg, const int *matcnt,
                    const int *matind, const double *matval,
                    const double *lb, const double *ub, const double *rngval);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckcopylpwnames (CPXCENVptr env, CPXCLPptr lp, int numcols,
                          int numrows, int objsen, const double *obj,
                          const double *rhs, const char *sense,
                          const int *matbeg, const int *matcnt,
                          const int *matind, const double *matval,
                          const double *lb, const double *ub,
                          const double *rngval,
                          char **colname, char **rowname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckaddcols (CPXCENVptr env, CPXCLPptr lp, int ccnt,
                     int nzcnt, const double *obj,
                     const int *cmatbeg, const int *cmatind,
                     const double *cmatval, const double *lb,
                     const double *ub, char **colname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckaddrows (CPXCENVptr env, CPXCLPptr lp, int ccnt,
                     int rcnt, int nzcnt, const double *rhs,
                     const char *sense, const int *rmatbeg,
                     const int *rmatind, const double *rmatval,
                     char **colname, char **rowname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckchgcoeflist (CPXCENVptr env, CPXCLPptr lp, int numcoefs,
                         const int *rowlist, const int *collist,
                         const double *vallist);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckvals (CPXCENVptr env, CPXCLPptr lp, int cnt,
                  const int *rowind, const int *colind, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetchannels (CPXCENVptr env, CPXCHANNELptr * cpxresults_p,
                    CPXCHANNELptr * cpxwarning_p,
                    CPXCHANNELptr * cpxerror_p, CPXCHANNELptr * cpxlog_p);
    CPXLIBAPI int CPXPUBLIC CPXsetlogfile (CPXENVptr env, CPXFILEptr lfile);
    CPXLIBAPI
    int CPXPUBLIC CPXgetlogfile (CPXCENVptr env, CPXFILEptr * logfile_p);
    CPXLIBAPI
    int CPXPUBVARARGS CPXmsg (CPXCHANNELptr channel, const char *format, ...);
    CPXLIBAPI
    int CPXPUBLIC CPXmsgstr (CPXCHANNELptr channel, const char *msg_str);
    CPXLIBAPI
    void CPXPUBLIC CPXflushchannel (CPXCENVptr env, CPXCHANNELptr channel);
    CPXLIBAPI int CPXPUBLIC CPXflushstdchannels (CPXCENVptr env);
    CPXLIBAPI CPXCHANNELptr CPXPUBLIC CPXaddchannel (CPXENVptr env);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddfpdest (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelfpdest (CPXCENVptr env, CPXCHANNELptr channel, CPXFILEptr fileptr);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC * msgfunction) (void *, const char *));
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelfuncdest (CPXCENVptr env, CPXCHANNELptr channel,
                    void *handle,
                    void (CPXPUBLIC * msgfunction) (void *, const char *));
    CPXLIBAPI
    void CPXPUBLIC CPXdelchannel (CPXENVptr env, CPXCHANNELptr * channel_p);
    CPXLIBAPI
    void CPXPUBLIC
    CPXdisconnectchannel (CPXCENVptr env, CPXCHANNELptr channel);
    CPXLIBAPI
    CPXCCHARptr CPXPUBLIC
    CPXgeterrorstring (CPXCENVptr env, int errcode, char *buffer_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetlpcallbackfunc (CPXENVptr env,
                          int (CPXPUBLIC * callback) (CPXCENVptr,
                                                      void *, int, void *),
                          void *cbhandle);
    CPXLIBAPI int CPXPUBLIC CPXsetnetcallbackfunc (CPXENVptr env,
                                                   int (CPXPUBLIC *
                                                        callback) (CPXCENVptr,
                                                                   void *,
                                                                   int,
                                                                   void *),
                                                   void *cbhandle);
    CPXLIBAPI int CPXPUBLIC CPXsettuningcallbackfunc (CPXENVptr env,
                                                      int (CPXPUBLIC *
                                                           callback)
                                                      (CPXCENVptr, void *,
                                                       int, void *),
                                                      void *cbhandle);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackinfo (CPXCENVptr env, void *cbdata,
                                                int wherefrom, int whichinfo,
                                                void *result_p);
    CPXLIBAPI int CPXPUBLIC CPXgetlpcallbackfunc (CPXCENVptr env,
                                                  int (CPXPUBLIC **
                                                       callback_p)
                                                  (CPXCENVptr, void *, int,
                                                   void *),
                                                  void **cbhandle_p);
    CPXLIBAPI int CPXPUBLIC CPXgetnetcallbackfunc (CPXCENVptr env,
                                                   int (CPXPUBLIC **
                                                        callback_p)
                                                   (CPXCENVptr, void *, int,
                                                    void *),
                                                   void **cbhandle_p);
    CPXLIBAPI int CPXPUBLIC CPXgettuningcallbackfunc (CPXCENVptr env,
                                                      int (CPXPUBLIC **
                                                           callback_p)
                                                      (CPXCENVptr, void *,
                                                       int, void *),
                                                      void **cbhandle_p);
    CPXLIBAPI int CPXPUBLIC CPXsetprofcallbackfunc (CPXENVptr env,
                                                    int (CPXPUBLIC *
                                                         callback)
                                                    (CPXCENVptr, int, void *),
                                                    void *cbhandle);
    CPXLIBAPI CPXFILEptr CPXPUBLIC CPXfopen (const char *filename_str,
                                             const char *type_str);
    CPXLIBAPI int CPXPUBLIC CPXfclose (CPXFILEptr stream);
    CPXLIBAPI int CPXPUBLIC CPXfputs (const char *s_str, CPXFILEptr stream);
    CPXLIBAPI CPXVOIDptr CPXPUBLIC CPXmalloc (size_t size);
    CPXLIBAPI CPXVOIDptr CPXPUBLIC CPXrealloc (void *ptr, size_t size);
    CPXLIBAPI CPXVOIDptr CPXPUBLIC CPXmemcpy (void *s1, void *s2, size_t n);
    CPXLIBAPI void CPXPUBLIC CPXfree (void *ptr);
    CPXLIBAPI int CPXPUBLIC CPXstrlen (const char *s_str);
    CPXLIBAPI
    CPXCHARptr CPXPUBLIC CPXstrcpy (char *dest_str, const char *src_str);
    CPXLIBAPI int CPXPUBLIC CPXputenv (const char *envsetting_str);
    CPXLIBAPI void CPXPUBLIC CPXEisort (int n, int *a, int *perm);
    CPXLIBAPI void CPXPUBLIC CPXEinsort (int n, int *a);
    CPXLIBAPI int CPXPUBLIC CPXEgetThreadNumber (CPXCENVptr env);
    CPXLIBAPI int CPXPUBLIC CPXEgetmaxthreads (CPXCENVptr env);
    CPXLIBAPI int CPXPUBLIC CPXEsetJNI (CPXENVptr env, CPXVOIDptr jni);
    CPXLIBAPI CPXVOIDptr CPXPUBLIC CPXEgetJNI (CPXCENVptr env);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEsetnamefunctions (CPXENVptr env, void *userdata,
                          const char *(CPXPUBLIC * getcname) (void *, int,
                                                              char *),
                          const char *(CPXPUBLIC * getrname) (void *, int,
                                                              char *),
                          const char *(CPXPUBLIC * getqname) (void *, int,
                                                              char *),
                          const char *(CPXPUBLIC * getiname) (void *, int,
                                                              char *),
                          const char *(CPXPUBLIC * getsname) (void *, int,
                                                              char *));
    CPXLIBAPI int CPXPUBLIC CPXEsetnamedef (CPXENVptr env,
                                            const char *def_str, int deftype);
    CPXLIBAPI int CPXPUBLIC CPXEdelnames (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI CPXVOIDptr CPXPUBLIC CPXEgetCache (CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEcacheNewCols (CPXCENVptr env, CPXLPptr lp,
                      int ccnt, const double *zobj,
                      const double *zlb, const double *zub,
                      const char *zctype, const char *const *zcname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEcacheNewRows (CPXCENVptr env, CPXLPptr lp,
                      int rcnt, const double *zrhs,
                      const char *zsense, const double *rngval,
                      const char *const *zrname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEcacheNewNZsByNZ (CPXCENVptr env, CPXLPptr lp,
                         int nzcnt, const int *rowlist,
                         const int *collist, const double *vallist);
    CPXLIBAPI
    int CPXPUBLIC CPXEgetorigcolind (CPXCENVptr env, CPXCLPptr lp, int j);
    CPXLIBAPI
    int CPXPUBLIC CPXEgetorigrowind (CPXCENVptr env, CPXCLPptr lp, int i);
    CPXLIBAPI double CPXPUBLIC CPXEgetbigreal (CPXCENVptr env);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEispromotion (CPXCENVptr env, int rspace, int cspace, int ispace);
    CPXLIBAPI
    int CPXPUBLIC CPXEgetnumrownz (CPXCENVptr env, CPXCLPptr lp, int *mark);
    CPXLIBAPI int CPXPUBLIC CPXEcangetbase (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXEwriteparam (CPXCENVptr env, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC CPXsetterminate (CPXENVptr env, volatile int *terminate_p);
    CPXLIBAPI
    void CPXPUBLIC
    CPXEsetterminatefunc (CPXENVptr env,
                          int (CPXPUBLIC * terminatefunc) (CPXCENVptr));
  struct cpxnameset;
    CPXLIBAPI
    int CPXPUBLIC
    CPXEnsAddNames (struct cpxnameset *nset, int n, const char *const *name);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetbhead (CPXCENVptr env, CPXCLPptr lp, int *head, double *x);
    CPXLIBAPI
    int CPXPUBLIC CPXbinvcol (CPXCENVptr env, CPXCLPptr lp, int j, double *x);
    CPXLIBAPI
    int CPXPUBLIC CPXbinvrow (CPXCENVptr env, CPXCLPptr lp, int i, double *y);
    CPXLIBAPI
    int CPXPUBLIC
    CPXbinvacol (CPXCENVptr env, CPXCLPptr lp, int j, double *x);
    CPXLIBAPI
    int CPXPUBLIC
    CPXbinvarow (CPXCENVptr env, CPXCLPptr lp, int i, double *z);
    CPXLIBAPI
    int CPXPUBLIC CPXftran (CPXCENVptr env, CPXCLPptr lp, double *x);
    CPXLIBAPI
    int CPXPUBLIC CPXbtran (CPXCENVptr env, CPXCLPptr lp, double *y);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetijrow (CPXCENVptr env, CPXCLPptr lp, int i, int j, int *row_p);
    CPXLIBAPI
    int CPXPUBLIC CPXgetray (CPXCENVptr env, CPXCLPptr lp, double *z);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetweight (CPXCENVptr env, CPXCLPptr lp, int rcnt,
                  const int *rmatbeg, const int *rmatind,
                  const double *rmatval, double *weight, int dpriind);
    CPXLIBAPI
    int CPXPUBLIC
    CPXmdleave (CPXCENVptr env, CPXLPptr lp,
                const int *indices, int cnt,
                double *downratio, double *upratio);
    CPXLIBAPI
    int CPXPUBLIC
    CPXstrongbranch (CPXCENVptr env, CPXLPptr lp,
                     const int *indices, int cnt,
                     double *downobj, double *upobj, int itlim);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdualfarkas (CPXCENVptr env, CPXCLPptr lp, double *y, double *proof_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetobjoffset (CPXCENVptr env, CPXCLPptr lp, double *objoffset_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopypartialbase (CPXCENVptr env, CPXLPptr lp,
                        int ccnt, const int *cindices,
                        const int *cstat, int rcnt,
                        const int *rindices, const int *rstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetbasednorms (CPXCENVptr env, CPXCLPptr lp, int *cstat,
                      int *rstat, double *dnorm);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopybasednorms (CPXCENVptr env, CPXLPptr lp, const int *cstat,
                       const int *rstat, const double *dnorm);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetdnorms (CPXCENVptr env, CPXCLPptr lp, double *norm,
                  int *head, int *len_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopydnorms (CPXCENVptr env, CPXLPptr lp,
                   const double *norm, const int *head, int len);
    CPXLIBAPI void CPXPUBLIC CPXkilldnorms (CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetpnorms (CPXCENVptr env, CPXCLPptr lp, double *cnorm,
                  double *rnorm, int *len_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopypnorms (CPXCENVptr env, CPXLPptr lp,
                   const double *cnorm, const double *rnorm, int len);
    CPXLIBAPI void CPXPUBLIC CPXkillpnorms (CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpivotin (CPXCENVptr env, CPXLPptr lp, const int *rlist, int rlen);
    CPXLIBAPI
    int CPXPUBLIC
    CPXpivotout (CPXCENVptr env, CPXLPptr lp, const int *clist, int clen);
    CPXLIBAPI int CPXPUBLIC CPXunscaleprob (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXtightenbds (CPXCENVptr env, CPXLPptr lp, int cnt,
                   const int *indices, const char *lu, const double *bd);
    CPXLIBAPI
    int CPXPUBLIC CPXpresolve (CPXCENVptr env, CPXLPptr lp, int method);
    CPXLIBAPI
    int CPXPUBLIC
    CPXbasicpresolve (CPXCENVptr env, CPXLPptr lp, double *redlb,
                      double *redub, int *rstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXslackfromx (CPXCENVptr env, CPXCLPptr lp, const double *x,
                   double *slack);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdjfrompi (CPXCENVptr env, CPXCLPptr lp, const double *pi, double *dj);
    CPXLIBAPI
    int CPXPUBLIC
    CPXqpdjfrompi (CPXCENVptr env, CPXCLPptr lp, const double *pi,
                   const double *x, double *dj);
    CPXLIBAPI int CPXPUBLIC CPXfreepresolve (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetredlp (CPXCENVptr env, CPXCLPptr lp, CPXCLPptr * redlp_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcrushx (CPXCENVptr env, CPXCLPptr lp, const double *x, double *prex);
    CPXLIBAPI
    int CPXPUBLIC
    CPXuncrushx (CPXCENVptr env, CPXCLPptr lp, double *x, const double *prex);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcrushpi (CPXCENVptr env, CPXCLPptr lp, const double *pi,
                double *prepi);
    CPXLIBAPI
    int CPXPUBLIC
    CPXuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                  const double *prepi);
    CPXLIBAPI
    int CPXPUBLIC
    CPXqpuncrushpi (CPXCENVptr env, CPXCLPptr lp, double *pi,
                    const double *prepi, const double *x);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcrushform (CPXCENVptr env, CPXCLPptr lp, int len,
                  const int *ind, const double *val,
                  int *plen_p, double *poffset_p, int *pind, double *pval);
    CPXLIBAPI
    int CPXPUBLIC
    CPXuncrushform (CPXCENVptr env, CPXCLPptr lp, int plen,
                    const int *pind, const double *pval, int *len_p,
                    double *offset_p, int *ind, double *val);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetprestat (CPXCENVptr env, CPXCLPptr lp, int *prestat_p,
                   int *pcstat, int *prstat, int *ocstat, int *orstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopyprotected (CPXCENVptr env, CPXLPptr lp, int cnt,
                      const int *indices);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetprotected (CPXCENVptr env, CPXCLPptr lp, int *cnt_p,
                     int *indices, int pspace, int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaggregatevars (CPXCENVptr env, CPXLPptr lp,
                       int start, int end, const char *protectrow);
    CPXLIBAPI int CPXPUBLIC CPXgettime (CPXCENVptr env, double *timestamp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXlpwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXlprewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXmpswrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXmpsrewrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsavwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXreadcopyvec (CPXCENVptr env, CPXLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXvecwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXbinsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXtxtsolwrite (CPXCENVptr env, CPXCLPptr lp, const char *filename_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXwritesol (CPXCENVptr env, CPXCLPptr lp,
                 const char *filename_str, const char *filetype_str);
#define CPXERR_IIS_NO_INFO 1701
#define CPXERR_IIS_NO_SOLN 1702
#define CPXERR_IIS_FEAS 1703
#define CPXERR_IIS_NOT_INFEAS 1704
#define CPXERR_IIS_OPT_INFEAS 1705
#define CPXERR_IIS_DEFAULT 1706
#define CPXERR_IIS_NO_BASIC 1707
#define CPXERR_IIS_NO_LOAD 1709
#define CPXERR_IIS_SUB_OBJ_LIM 1710
#define CPXERR_IIS_SUB_IT_LIM 1711
#define CPXERR_IIS_SUB_TIME_LIM 1712
#define CPXERR_IIS_NUM_BEST 1713
#define CPXERR_IIS_SUB_ABORT 1714
#define CPXIIS_COMPLETE 1
#define CPXIIS_PARTIAL 2
#define CPXIIS_TERSE 1
#define CPXIIS_VERBOSE 2
#define CPXIIS_AT_LOWER 0
#define CPXIIS_FIXED 1
#define CPXIIS_AT_UPPER 2
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetiis (CPXCENVptr env, CPXCLPptr lp, int *iisstat_p,
               int *rowind, int *rowbdstat, int *iisnumrows_p,
               int *colind, int *colbdstat, int *iisnumcols_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXfindiis (CPXCENVptr env, CPXLPptr lp, int *iisnumrows_p,
                int *iisnumcols_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdisplayiis (CPXCENVptr env, CPXCLPptr lp,
                   CPXCHANNELptr channel, int display);
    CPXLIBAPI
    int CPXPUBLIC
    CPXiiswrite (CPXCENVptr env, CPXLPptr lp, const char *filename_str);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __BARDEFS_H
#define __BARDEFS_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPX_STAT_OPTIMAL_FACE_UNBOUNDED 20
#define CPX_STAT_ABORT_PRIM_OBJ_LIM 21
#define CPX_STAT_ABORT_DUAL_OBJ_LIM 22
#define CPX_PARAM_BARDSTART 3001
#define CPX_PARAM_BAREPCOMP 3002
#define CPX_PARAM_BARGROWTH 3003
#define CPX_PARAM_BAROBJRNG 3004
#define CPX_PARAM_BARPSTART 3005
#define CPX_PARAM_BARALG 3007
#define CPX_PARAM_BARCOLNZ 3009
#define CPX_PARAM_BARDISPLAY 3010
#define CPX_PARAM_BARITLIM 3012
#define CPX_PARAM_BARMAXCOR 3013
#define CPX_PARAM_BARORDER 3014
#define CPX_PARAM_BARSTARTALG 3017
#define CPX_PARAM_BARCROSSALG 3018
#define CPX_PARAM_BARQCPEPCOMP 3020
#define CPX_BARORDER_AUTO 0
#define CPX_BARORDER_AMD 1
#define CPX_BARORDER_AMF 2
#define CPX_BARORDER_ND 3
  CPXLIBAPI
    int CPXPUBLIC CPXhybbaropt (CPXCENVptr env, CPXLPptr lp, int method);
    CPXLIBAPI int CPXPUBLIC CPXbaropt (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI void CPXPUBLIC CPXEgeneric_lock (volatile int *lock);
    CPXLIBAPI void CPXPUBLIC CPXEgeneric_unlock (volatile int *lock);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetorderhookfunc (CPXENVptr env,
                         int (CPXPUBLIC * orderhook) (CPXCENVptr,
                                                      int, int *, int **,
                                                      int *));
    CPXLIBAPI void CPXPUBLIC CPXgetorderhookfunc (CPXCENVptr env,
                                                  int (CPXPUBLIC **
                                                       orderhook_p)
                                                  (CPXCENVptr, int, int *,
                                                   int **, int *));
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __MIPDEFS_H
#define __MIPDEFS_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPXERR_NOT_MIP 3003
#define CPXERR_BAD_PRIORITY 3006
#define CPXERR_ORDER_BAD_DIRECTION 3007
#define CPXERR_ARRAY_BAD_SOS_TYPE 3009
#define CPXERR_UNIQUE_WEIGHTS 3010
#define CPXERR_BAD_DIRECTION 3012
#define CPXERR_NO_SOS 3015
#define CPXERR_NO_ORDER 3016
#define CPXERR_INT_TOO_BIG 3018
#define CPXERR_SUBPROB_SOLVE 3019
#define CPXERR_NO_MIPSTART 3020
#define CPXERR_BAD_CTYPE 3021
#define CPXERR_NO_INT_X 3023
#define CPXERR_NO_SOLNPOOL 3024
#define CPXERR_MISS_SOS_TYPE 3301
#define CPXERR_NO_TREE 3412
#define CPXERR_TREE_MEMORY_LIMIT 3413
#define CPXERR_FILTER_VARIABLE_TYPE 3414
#define CPXERR_NODE_ON_DISK 3504
#define CPXERR_PTHREAD_MUTEX_INIT 3601
#define CPXERR_PTHREAD_CREATE 3603
#define CPX_MIPEMPHASIS_BALANCED 0
#define CPX_MIPEMPHASIS_FEASIBILITY 1
#define CPX_MIPEMPHASIS_OPTIMALITY 2
#define CPX_MIPEMPHASIS_BESTBOUND 3
#define CPX_MIPEMPHASIS_HIDDENFEAS 4
#define CPX_TYPE_VAR '0'
#define CPX_TYPE_SOS1 '1'
#define CPX_TYPE_SOS2 '2'
#define CPX_TYPE_USER 'X'
#define CPX_TYPE_ANY 'A'
#define CPX_VARSEL_MININFEAS -1
#define CPX_VARSEL_DEFAULT 0
#define CPX_VARSEL_MAXINFEAS 1
#define CPX_VARSEL_PSEUDO 2
#define CPX_VARSEL_STRONG 3
#define CPX_VARSEL_PSEUDOREDUCED 4
#define CPX_NODESEL_DFS 0
#define CPX_NODESEL_BESTBOUND 1
#define CPX_NODESEL_BESTEST 2
#define CPX_NODESEL_BESTEST_ALT 3
#define CPX_MIPORDER_COST 1
#define CPX_MIPORDER_BOUNDS 2
#define CPX_MIPORDER_SCALEDCOST 3
#define CPX_BRANCH_GLOBAL 0
#define CPX_BRANCH_DOWN -1
#define CPX_BRANCH_UP 1
#define CPX_BRDIR_DOWN -1
#define CPX_BRDIR_AUTO 0
#define CPX_BRDIR_UP 1
#define CPX_CUT_COVER 0
#define CPX_CUT_GUBCOVER 1
#define CPX_CUT_FLOWCOVER 2
#define CPX_CUT_CLIQUE 3
#define CPX_CUT_FRAC 4
#define CPX_CUT_MIR 5
#define CPX_CUT_FLOWPATH 6
#define CPX_CUT_DISJ 7
#define CPX_CUT_IMPLBD 8
#define CPX_CUT_ZEROHALF 9
#define CPX_CUT_MCF 10
#define CPX_CUT_LOCALCOVER 11
#define CPX_CUT_TIGHTEN 12
#define CPX_CUT_OBJDISJ 13
#define CPX_CUT_USER 14
#define CPX_CUT_TABLE 15
#define CPX_CUT_SOLNPOOL 16
#define CPX_CUT_NUM_TYPES 17
#define CPX_MIPSEARCH_AUTO 0
#define CPX_MIPSEARCH_TRADITIONAL 1
#define CPX_MIPSEARCH_DYNAMIC 2
#define CPX_MIPSTART_AUTO 0
#define CPX_MIPSTART_CHECKFEAS 1
#define CPX_MIPSTART_SOLVEFIXED 2
#define CPX_MIPSTART_SOLVEMIP 3
#define CPX_MIPSTART_REPAIR 4
#define CPXMIP_OPTIMAL 101
#define CPXMIP_OPTIMAL_TOL 102
#define CPXMIP_INFEASIBLE 103
#define CPXMIP_SOL_LIM 104
#define CPXMIP_NODE_LIM_FEAS 105
#define CPXMIP_NODE_LIM_INFEAS 106
#define CPXMIP_TIME_LIM_FEAS 107
#define CPXMIP_TIME_LIM_INFEAS 108
#define CPXMIP_FAIL_FEAS 109
#define CPXMIP_FAIL_INFEAS 110
#define CPXMIP_MEM_LIM_FEAS 111
#define CPXMIP_MEM_LIM_INFEAS 112
#define CPXMIP_ABORT_FEAS 113
#define CPXMIP_ABORT_INFEAS 114
#define CPXMIP_OPTIMAL_INFEAS 115
#define CPXMIP_FAIL_FEAS_NO_TREE 116
#define CPXMIP_FAIL_INFEAS_NO_TREE 117
#define CPXMIP_UNBOUNDED 118
#define CPXMIP_INForUNBD 119
#define CPXMIP_FEASIBLE_RELAXED_SUM 120
#define CPXMIP_OPTIMAL_RELAXED_SUM 121
#define CPXMIP_FEASIBLE_RELAXED_INF 122
#define CPXMIP_OPTIMAL_RELAXED_INF 123
#define CPXMIP_FEASIBLE_RELAXED_QUAD 124
#define CPXMIP_OPTIMAL_RELAXED_QUAD 125
#define CPXMIP_ABORT_RELAXED 126
#define CPXMIP_FEASIBLE 127
#define CPXMIP_POPULATESOL_LIM 128
#define CPXMIP_OPTIMAL_POPULATED 129
#define CPXMIP_OPTIMAL_POPULATED_TOL 130
#define CPX_CALLBACK_MIP 101
#define CPX_CALLBACK_MIP_BRANCH 102
#define CPX_CALLBACK_MIP_NODE 103
#define CPX_CALLBACK_MIP_HEURISTIC 104
#define CPX_CALLBACK_MIP_SOLVE 105
#define CPX_CALLBACK_MIP_CUT 106
#define CPX_CALLBACK_MIP_PROBE 107
#define CPX_CALLBACK_MIP_FRACCUT 108
#define CPX_CALLBACK_MIP_DISJCUT 109
#define CPX_CALLBACK_MIP_FLOWMIR 110
#define CPX_CALLBACK_MIP_INCUMBENT 111
#define CPX_CALLBACK_MIP_DELETENODE 112
#define CPX_CALLBACK_MIP_BRANCH_NOSOLN 113
#define CPX_CALLBACK_INFO_BEST_INTEGER 101
#define CPX_CALLBACK_INFO_BEST_REMAINING 102
#define CPX_CALLBACK_INFO_NODE_COUNT 103
#define CPX_CALLBACK_INFO_NODES_LEFT 104
#define CPX_CALLBACK_INFO_MIP_ITERATIONS 105
#define CPX_CALLBACK_INFO_CUTOFF 106
#define CPX_CALLBACK_INFO_CLIQUE_COUNT 107
#define CPX_CALLBACK_INFO_COVER_COUNT 108
#define CPX_CALLBACK_INFO_MIP_FEAS 109
#define CPX_CALLBACK_INFO_FLOWCOVER_COUNT 110
#define CPX_CALLBACK_INFO_GUBCOVER_COUNT 111
#define CPX_CALLBACK_INFO_IMPLBD_COUNT 112
#define CPX_CALLBACK_INFO_PROBE_PHASE 113
#define CPX_CALLBACK_INFO_PROBE_PROGRESS 114
#define CPX_CALLBACK_INFO_FRACCUT_COUNT 115
#define CPX_CALLBACK_INFO_FRACCUT_PROGRESS 116
#define CPX_CALLBACK_INFO_DISJCUT_COUNT 117
#define CPX_CALLBACK_INFO_DISJCUT_PROGRESS 118
#define CPX_CALLBACK_INFO_FLOWPATH_COUNT 119
#define CPX_CALLBACK_INFO_MIRCUT_COUNT 120
#define CPX_CALLBACK_INFO_FLOWMIR_PROGRESS 121
#define CPX_CALLBACK_INFO_ZEROHALFCUT_COUNT 122
#define CPX_CALLBACK_INFO_MY_THREAD_NUM 123
#define CPX_CALLBACK_INFO_USER_THREADS 124
#define CPX_CALLBACK_INFO_MIP_REL_GAP 125
#define CPX_CALLBACK_INFO_MCFCUT_COUNT 126
#define CPX_CALLBACK_INFO_NODE_SIINF 201
#define CPX_CALLBACK_INFO_NODE_NIINF 202
#define CPX_CALLBACK_INFO_NODE_ESTIMATE 203
#define CPX_CALLBACK_INFO_NODE_DEPTH 204
#define CPX_CALLBACK_INFO_NODE_OBJVAL 205
#define CPX_CALLBACK_INFO_NODE_TYPE 206
#define CPX_CALLBACK_INFO_NODE_VAR 207
#define CPX_CALLBACK_INFO_NODE_SOS 208
#define CPX_CALLBACK_INFO_NODE_SEQNUM 209
#define CPX_CALLBACK_INFO_NODE_USERHANDLE 210
#define CPX_CALLBACK_INFO_NODE_NODENUM 211
#define CPX_CALLBACK_INFO_SOS_TYPE 240
#define CPX_CALLBACK_INFO_SOS_SIZE 241
#define CPX_CALLBACK_INFO_SOS_IS_FEASIBLE 242
#define CPX_CALLBACK_INFO_SOS_MEMBER_INDEX 244
#define CPX_CALLBACK_INFO_SOS_MEMBER_REFVAL 246
#define CPX_CALLBACK_INFO_SOS_NUM 247
#define CPX_CALLBACK_INFO_IC_NUM 260
#define CPX_CALLBACK_INFO_IC_IMPLYING_VAR 261
#define CPX_CALLBACK_INFO_IC_IMPLIED_VAR 262
#define CPX_CALLBACK_INFO_IC_SENSE 263
#define CPX_CALLBACK_INFO_IC_COMPL 264
#define CPX_CALLBACK_INFO_IC_RHS 265
#define CPX_CALLBACK_INFO_IC_IS_FEASIBLE 266
#define CPX_INCUMBENT_ID -1
#define CPX_CALLBACK_DEFAULT 0
#define CPX_CALLBACK_SET 2
#define CPX_CALLBACK_FAIL 1
#define CPX_INTEGER_FEASIBLE 0
#define CPX_INTEGER_INFEASIBLE 1
#define CPX_IMPLIED_INTEGER_FEASIBLE 2
#define CPX_PARAM_BRDIR 2001
#define CPX_PARAM_BTTOL 2002
#define CPX_PARAM_CLIQUES 2003
#define CPX_PARAM_COEREDIND 2004
#define CPX_PARAM_COVERS 2005
#define CPX_PARAM_CUTLO 2006
#define CPX_PARAM_CUTUP 2007
#define CPX_PARAM_EPAGAP 2008
#define CPX_PARAM_EPGAP 2009
#define CPX_PARAM_EPINT 2010
#define CPX_PARAM_MIPDISPLAY 2012
#define CPX_PARAM_MIPINTERVAL 2013
#define CPX_PARAM_INTSOLLIM 2015
#define CPX_PARAM_NODEFILEIND 2016
#define CPX_PARAM_NODELIM 2017
#define CPX_PARAM_NODESEL 2018
#define CPX_PARAM_OBJDIF 2019
#define CPX_PARAM_MIPORDIND 2020
#define CPX_PARAM_RELOBJDIF 2022
#define CPX_PARAM_STARTALG 2025
#define CPX_PARAM_SUBALG 2026
#define CPX_PARAM_TRELIM 2027
#define CPX_PARAM_VARSEL 2028
#define CPX_PARAM_BNDSTRENIND 2029
#define CPX_PARAM_HEURFREQ 2031
#define CPX_PARAM_MIPORDTYPE 2032
#define CPX_PARAM_CUTSFACTOR 2033
#define CPX_PARAM_RELAXPREIND 2034
#define CPX_PARAM_PRESLVND 2037
#define CPX_PARAM_BBINTERVAL 2039
#define CPX_PARAM_FLOWCOVERS 2040
#define CPX_PARAM_IMPLBD 2041
#define CPX_PARAM_PROBE 2042
#define CPX_PARAM_GUBCOVERS 2044
#define CPX_PARAM_STRONGCANDLIM 2045
#define CPX_PARAM_STRONGITLIM 2046
#define CPX_PARAM_FRACCAND 2048
#define CPX_PARAM_FRACCUTS 2049
#define CPX_PARAM_FRACPASS 2050
#define CPX_PARAM_FLOWPATHS 2051
#define CPX_PARAM_MIRCUTS 2052
#define CPX_PARAM_DISJCUTS 2053
#define CPX_PARAM_AGGCUTLIM 2054
#define CPX_PARAM_MIPCBREDLP 2055
#define CPX_PARAM_CUTPASS 2056
#define CPX_PARAM_MIPEMPHASIS 2058
#define CPX_PARAM_SYMMETRY 2059
#define CPX_PARAM_DIVETYPE 2060
#define CPX_PARAM_RINSHEUR 2061
#define CPX_PARAM_SUBMIPNODELIM 2062
#define CPX_PARAM_LBHEUR 2063
#define CPX_PARAM_REPEATPRESOLVE 2064
#define CPX_PARAM_PROBETIME 2065
#define CPX_PARAM_POLISHTIME 2066
#define CPX_PARAM_REPAIRTRIES 2067
#define CPX_PARAM_EPLIN 2068
#define CPX_PARAM_EPRELAX 2073
#define CPX_PARAM_FPHEUR 2098
#define CPX_PARAM_EACHCUTLIM 2102
#define CPX_PARAM_SOLNPOOLCAPACITY 2103
#define CPX_PARAM_SOLNPOOLREPLACE 2104
#define CPX_PARAM_SOLNPOOLGAP 2105
#define CPX_PARAM_SOLNPOOLAGAP 2106
#define CPX_PARAM_SOLNPOOLINTENSITY 2107
#define CPX_PARAM_POPULATELIM 2108
#define CPX_PARAM_MIPSEARCH 2109
#define CPX_PARAM_MIQCPSTRAT 2110
#define CPX_PARAM_ZEROHALFCUTS 2111
#define CPX_PARAM_POLISHAFTEREPAGAP 2126
#define CPX_PARAM_POLISHAFTEREPGAP 2127
#define CPX_PARAM_POLISHAFTERNODE 2128
#define CPX_PARAM_POLISHAFTERINTSOL 2129
#define CPX_PARAM_POLISHAFTERTIME 2130
#define CPX_PARAM_MCFCUTS 2134
  CPXLIBAPI
    int CPXPUBLIC
    CPXcopyctype (CPXCENVptr env, CPXLPptr lp, const char *xctype);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopyorder (CPXCENVptr env, CPXLPptr lp, int cnt,
                  const int *indices, const int *priority,
                  const int *direction);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopysos (CPXCENVptr env, CPXLPptr lp, int numsos,
                int numsosnz, const char *sostype,
                const int *sosbeg, const int *sosind,
                const double *soswt, char **sosname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopymipstart (CPXCENVptr env, CPXLPptr lp, int cnt,
                     const int *indices, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgmipstart (CPXCENVptr env, CPXLPptr lp, int cnt,
                    const int *indices, const double *values);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt,
                     const int *mipstartindices, int nzcnt,
                     const int *beg, const int *varindices,
                     const double *values, const int *effortlevel);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddmipstarts (CPXCENVptr env, CPXLPptr lp, int mcnt, int nzcnt,
                     const int *beg, const int *varindices,
                     const double *values, const int *effortlevel,
                     char **mipstartname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelmipstarts (CPXCENVptr env, CPXLPptr lp, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelsetmipstarts (CPXCENVptr env, CPXLPptr lp, int *delstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrefinemipstartconflict (CPXCENVptr env, CPXLPptr lp,
                               int mipstartindex, int *confnumrows_p,
                               int *confnumcols_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXrefinemipstartconflictext (CPXCENVptr env, CPXLPptr lp,
                                  int mipstartindex, int grpcnt, int concnt,
                                  const double *grppref, const int *grpbeg,
                                  const int *grpind, const char *grptype);
    CPXLIBAPI int CPXPUBLIC CPXmipopt (CPXCENVptr env, CPXLPptr lp);
#define CPXgetmipobjval(env,lp,objval_p) \
           CPXgetobjval(env, lp, objval_p)
#define CPXgetmipx(env,lp,x,begin,end) \
           CPXgetx(env, lp, x, begin, end)
#define CPXgetmipslack(env,lp,slack,begin,end) \
           CPXgetslack(env, lp, slack, begin, end)
#define CPXgetmipqconstrslack(env,lp,qcslack,begin,end) \
           CPXgetqconstrslack(env, lp, qcslack, begin, end)
    CPXLIBAPI int CPXPUBLIC CPXgetmipitcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetbestobjval (CPXCENVptr env, CPXCLPptr lp, double *objval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetmiprelgap (CPXCENVptr env, CPXCLPptr lp, double *gap_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetcutoff (CPXCENVptr env, CPXCLPptr lp, double *cutoff_p);
    CPXLIBAPI int CPXPUBLIC CPXgetnodecnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnodeleftcnt (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnodeint (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetnumcuts (CPXCENVptr env, CPXCLPptr lp, int cuttype, int *num_p);
    CPXLIBAPI int CPXPUBLIC CPXgetnummipstarts (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetmipstart (CPXCENVptr env, CPXCLPptr lp, int *cnt_p,
                    int *indices, double *value, int mipstartspace,
                    int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetmipstarts (CPXCENVptr env, CPXCLPptr lp,
                     int *nzcnt_p, int *beg, int *varindices,
                     double *values, int *effortlevel,
                     int startspace, int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetmipstartname (CPXCENVptr env, CPXCLPptr lp, char **name,
                        char *store, int storesz, int *surplus_p, int begin,
                        int end);
    CPXLIBAPI int CPXPUBLIC CPXgetmipstartindex (CPXCENVptr env, CPXCLPptr lp,
                                                 const char *lname_str,
                                                 int *index_p);
    CPXLIBAPI int CPXPUBLIC CPXgetsolnpoolmipstart (CPXCENVptr env,
                                                    CPXCLPptr lp, int soln,
                                                    int *cnt_p, int *indices,
                                                    double *value,
                                                    int mipstartspace,
                                                    int *surplus_p);
    CPXLIBAPI int CPXPUBLIC CPXgetsolnpoolnummipstarts (CPXCENVptr env,
                                                        CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetsubstat (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetsubmethod (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgctype (CPXCENVptr env, CPXLPptr lp, int cnt,
                 const int *indices, const char *xctype);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddsos (CPXCENVptr env, CPXLPptr lp, int numsos,
               int numsosnz, const char *sostype,
               const int *sosbeg, const int *sosind,
               const double *soswt, char **sosname);
    CPXLIBAPI
    int CPXPUBLIC CPXdelsetsos (CPXCENVptr env, CPXLPptr lp, int *delset);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetctype (CPXCENVptr env, CPXCLPptr lp, char *xctype,
                 int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetnumsos (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsos (CPXCENVptr env, CPXCLPptr lp, int *numsosnz_p,
               char *sostype, int *sosbeg, int *sosind,
               double *soswt, int sosspace, int *surplus_p,
               int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsosname (CPXCENVptr env, CPXCLPptr lp, char **name,
                   char *namestore, int storespace,
                   int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsosindex (CPXCENVptr env, CPXCLPptr lp,
                    const char *lname_str, int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsosinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x,
                     double *infeasout, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC CPXgetnumindconstrs (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetindconstr (CPXCENVptr env, CPXCLPptr lp, int *indvar_p,
                     int *complemented_p, int *nzcnt_p, double *rhs_p,
                     char *sense_p, int *linind, double *linval, int space,
                     int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetindicator (CPXCENVptr env, CPXCLPptr lp, int *indvar_p,
                      int *complemented_p, int *nzcnt_p, double *rhs_p,
                      char *sense_p, int *ind, double *val, int space,
                      int *surplus_p, int *type_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetindconstrindex (CPXCENVptr env, CPXCLPptr lp,
                          const char *lname_str, int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetindconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                         int bufspace, int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetindconstrslack (CPXCENVptr env, CPXCLPptr lp, double *indslack,
                          int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXindconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                            const double *x, double *indslack);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetindconstrinfeas (CPXCENVptr env, CPXCLPptr lp, const double *x,
                           double *infeasout, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelindconstrs (CPXCENVptr env, CPXLPptr lp, int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetnumint (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumbin (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumsemicont (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumsemiint (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetorder (CPXCENVptr env, CPXCLPptr lp, int *cnt_p,
                 int *indices, int *priority, int *direction,
                 int ordspace, int *surplus_p);
#define CPX_SOLNPOOL_FIFO 0
#define CPX_SOLNPOOL_OBJ 1
#define CPX_SOLNPOOL_DIV 2
#define CPX_SOLNPOOL_FILTER_DIVERSITY 1
#define CPX_SOLNPOOL_FILTER_RANGE 2
    CPXLIBAPI int CPXPUBLIC CPXpopulate (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetsolnpoolnumfilters (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddsolnpooldivfilter (CPXCENVptr env, CPXLPptr lp,
                             double lower_bound, double upper_bound,
                             int nzcnt, const int *ind,
                             const double *weight, const double *refval,
                             const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXaddsolnpoolrngfilter (CPXCENVptr env, CPXLPptr lp, double lb,
                             double ub, int nzcnt, const int *ind,
                             const double *val, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolfiltertype (CPXCENVptr env, CPXCLPptr lp, int *ftype_p,
                              int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpooldivfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lowercutoff_p, double *upper_cutoff_p,
                             int *nzcnt_p, int *ind, double *val,
                             double *refval, int space, int *surplus_p,
                             int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolfilter (CPXCENVptr env, CPXCLPptr lp, int *ftype_p,
                          double *lowercutoff_p, double *upper_cutoff_p,
                          int *nzcnt_p, int *ind, double *val,
                          double *refval, int space, int *surplus_p,
                          int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolrngfilter (CPXCENVptr env, CPXCLPptr lp,
                             double *lb_p, double *ub_p,
                             int *nzcnt_p, int *ind, double *val,
                             int space, int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolfiltername (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                              int bufspace, int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolfilterindex (CPXCENVptr env, CPXCLPptr lp,
                               const char *lname_str, int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelsetsolnpoolfilters (CPXCENVptr env, CPXLPptr lp, int *delstat);
    CPXLIBAPI
    int CPXPUBLIC CPXgetsolnpoolnumsolns (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXgetsolnpoolnumreplaced (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolmeanobjval (CPXCENVptr env, CPXCLPptr lp,
                              double *meanobjval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolobjval (CPXCENVptr env, CPXCLPptr lp,
                          int soln, double *objval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolx (CPXCENVptr env, CPXCLPptr lp,
                     int soln, double *x, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolslack (CPXCENVptr env, CPXCLPptr lp,
                         int soln, double *slack, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolqconstrslack (CPXCENVptr env, CPXCLPptr lp,
                                int soln, double *qcslack,
                                int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolsolnname (CPXCENVptr env, CPXCLPptr lp, char *store,
                            int storesz, int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetsolnpoolsolnindex (CPXCENVptr env, CPXCLPptr lp,
                             const char *lname_str, int *index_p);
    CPXLIBAPI int CPXPUBLIC CPXdelsolnpoolsolns (CPXCENVptr env, CPXLPptr lp,
                                                 int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXdelsetsolnpoolsolns (CPXCENVptr env,
                                                    CPXLPptr lp,
                                                    int *delstat);
    CPXLIBAPI int CPXPUBLIC CPXreadcopyorder (CPXCENVptr env, CPXLPptr lp,
                                              const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXreadcopysolnpoolfilters (CPXCENVptr env,
                                                        CPXLPptr lp,
                                                        const char
                                                        *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXreadcopymipstart (CPXCENVptr env, CPXLPptr lp,
                                                 const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXreadcopymipstarts (CPXCENVptr env, CPXLPptr lp,
                                                  const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXordwrite (CPXCENVptr env, CPXCLPptr lp,
                                         const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXmstwrite (CPXCENVptr env, CPXCLPptr lp,
                                         const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXwritemipstarts (CPXCENVptr env, CPXCLPptr lp,
                                               const char *filename_str,
                                               int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXmstwritesolnpool (CPXCENVptr env, CPXCLPptr lp,
                                                 int soln,
                                                 const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXmstwritesolnpoolall (CPXCENVptr env,
                                                    CPXCLPptr lp,
                                                    const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXfltwrite (CPXCENVptr env, CPXCLPptr lp,
                                         const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXcheckcopyctype (CPXCENVptr env, CPXCLPptr lp,
                                               const char *xctype);
    CPXLIBAPI int CPXPUBLIC CPXcheckcopysos (CPXCENVptr env, CPXCLPptr lp,
                                             int numsos, int numsosnz,
                                             const char *sostype,
                                             const int *sosbeg,
                                             const int *sosind,
                                             const double *soswt,
                                             char **sosname);
    CPXLIBAPI int CPXPUBLIC CPXEchgsosname (CPXCENVptr env, CPXLPptr lp,
                                            int cnt, const int *indices,
                                            char **newname);
    CPXLIBAPI int CPXPUBLIC CPXsetinfocallbackfunc (CPXENVptr env,
                                                    int (CPXPUBLIC *
                                                         callback)
                                                    (CPXCENVptr, void *, int,
                                                     void *), void *cbhandle);
    CPXLIBAPI int CPXPUBLIC CPXgetinfocallbackfunc (CPXCENVptr env,
                                                    int (CPXPUBLIC **
                                                         callback_p)
                                                    (CPXCENVptr, void *, int,
                                                     void *),
                                                    void **cbhandle_p);
    CPXLIBAPI int CPXPUBLIC CPXsetmipcallbackfunc (CPXENVptr env,
                                                   int (CPXPUBLIC *
                                                        callback) (CPXCENVptr,
                                                                   void *,
                                                                   int,
                                                                   void *),
                                                   void *cbhandle);
    CPXLIBAPI int CPXPUBLIC CPXgetmipcallbackfunc (CPXCENVptr env,
                                                   int (CPXPUBLIC **
                                                        callback_p)
                                                   (CPXCENVptr, void *, int,
                                                    void *),
                                                   void **cbhandle_p);
#define CALLBACK_BRANCH_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, int brtype, int brset,\
   int nodecnt, int bdcnt, const double *nodeest, const int *nodebeg,\
   const int *xindex, const char *lu, const int *bd, int *useraction_p
#define CALLBACK_NODE_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, int *nodeindex, int *useraction
#define CALLBACK_HEURISTIC_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, double *objval_p, double *x,\
   int *checkfeas_p, int *useraction_p
#define CALLBACK_SOLVE_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, int *useraction
#define CALLBACK_CUT_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, int *useraction_p
#define CALLBACK_INCUMBENT_ARGS CPXCENVptr xenv, void *cbdata,\
   int wherefrom, void *cbhandle, double objval, double *x,\
   int *isfeas_p, int *useraction_p
#define CALLBACK_DELETENODE_ARGS CPXCENVptr xenv,\
   int wherefrom, void *cbhandle, int seqnum, void *handle
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetbranchcallbackfunc (CPXENVptr env,
                              int (CPXPUBLIC * branchcallback)
                              (CALLBACK_BRANCH_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetbranchnosolncallbackfunc (CPXENVptr env,
                                    int (CPXPUBLIC * branchnosolncallback)
                                    (CALLBACK_BRANCH_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetcutcallbackfunc (CPXENVptr env,
                           int (CPXPUBLIC * cutcallback)
                           (CALLBACK_CUT_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetnodecallbackfunc (CPXENVptr env,
                            int (CPXPUBLIC * nodecallback)
                            (CALLBACK_NODE_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetheuristiccallbackfunc (CPXENVptr env,
                                 int (CPXPUBLIC * heuristiccallback)
                                 (CALLBACK_HEURISTIC_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetincumbentcallbackfunc (CPXENVptr env,
                                 int (CPXPUBLIC * incumbentcallback)
                                 (CALLBACK_INCUMBENT_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetsolvecallbackfunc (CPXENVptr env,
                             int (CPXPUBLIC * solvecallback)
                             (CALLBACK_SOLVE_ARGS), void *cbhandle);
    CPXLIBAPI
    int CPXPUBLIC
    CPXsetdeletenodecallbackfunc (CPXENVptr env,
                                  void (CPXPUBLIC * deletecallback)
                                  (CALLBACK_DELETENODE_ARGS), void *cbhandle);
    CPXLIBAPI
    void CPXPUBLIC
    CPXgetbranchcallbackfunc (CPXCENVptr env,
                              int (CPXPUBLIC ** branchcallback_p)
                              (CALLBACK_BRANCH_ARGS), void **cbhandle_p);
    CPXLIBAPI
    void CPXPUBLIC
    CPXgetbranchnosolncallbackfunc (CPXCENVptr env,
                                    int (CPXPUBLIC ** branchnosolncallback_p)
                                    (CALLBACK_BRANCH_ARGS),
                                    void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetcutcallbackfunc (CPXCENVptr env,
                                                    int (CPXPUBLIC **
                                                         cutcallback_p)
                                                    (CALLBACK_CUT_ARGS),
                                                    void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetnodecallbackfunc (CPXCENVptr env,
                                                     int (CPXPUBLIC **
                                                          nodecallback_p)
                                                     (CALLBACK_NODE_ARGS),
                                                     void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetheuristiccallbackfunc (CPXCENVptr env,
                                                          int (CPXPUBLIC **
                                                               heuristiccallback_p)
                                                          (CALLBACK_HEURISTIC_ARGS),
                                                          void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetincumbentcallbackfunc (CPXCENVptr env,
                                                          int (CPXPUBLIC **
                                                               incumbentcallback_p)
                                                          (CALLBACK_INCUMBENT_ARGS),
                                                          void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetsolvecallbackfunc (CPXCENVptr env,
                                                      int (CPXPUBLIC **
                                                           solvecallback_p)
                                                      (CALLBACK_SOLVE_ARGS),
                                                      void **cbhandle_p);
    CPXLIBAPI void CPXPUBLIC CPXgetdeletenodecallbackfunc (CPXCENVptr env,
                                                           void (CPXPUBLIC **
                                                                 deletecallback_p)
                                                           (CALLBACK_DELETENODE_ARGS),
                                                           void **cbhandle_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodelp (CPXCENVptr env,
                                                  void *cbdata, int wherefrom,
                                                  CPXLPptr * nodelp_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodeinfo (CPXCENVptr env,
                                                    void *cbdata,
                                                    int wherefrom,
                                                    int nodeindex,
                                                    int whichinfo,
                                                    void *result_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackseqinfo (CPXCENVptr env,
                                                   void *cbdata,
                                                   int wherefrom, int seqid,
                                                   int whichinfo,
                                                   void *result_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacksosinfo (CPXCENVptr env,
                                                   void *cbdata,
                                                   int wherefrom,
                                                   int sosindex, int member,
                                                   int whichinfo,
                                                   void *result_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackindicatorinfo (CPXCENVptr env,
                                                         void *cbdata,
                                                         int wherefrom,
                                                         int iindex,
                                                         int whichinfo,
                                                         void *result_p);
    CPXLIBAPI int CPXPUBLIC CPXcutcallbackadd (CPXCENVptr env, void *cbdata,
                                               int wherefrom, int nzcnt,
                                               double rhs, int sense,
                                               const int *cutind,
                                               const double *cutval,
                                               int purgeable);
    CPXLIBAPI int CPXPUBLIC CPXcutcallbackaddlocal (CPXCENVptr env,
                                                    void *cbdata,
                                                    int wherefrom, int nzcnt,
                                                    double rhs, int sense,
                                                    const int *cutind,
                                                    const double *cutval);
    CPXLIBAPI int CPXPUBLIC CPXbranchcallbackbranchbds (CPXCENVptr env,
                                                        void *cbdata,
                                                        int wherefrom,
                                                        double nodeest,
                                                        int cnt,
                                                        const int *indices,
                                                        const char *lu,
                                                        const int *bd,
                                                        void *userhandle,
                                                        int *seqnum_p);
    CPXLIBAPI int CPXPUBLIC CPXbranchcallbackbranchgeneral (CPXCENVptr env,
                                                            void *cbdata,
                                                            int wherefrom,
                                                            double nodeest,
                                                            int varcnt,
                                                            const int *varind,
                                                            const char *varlu,
                                                            const int *varbd,
                                                            int rcnt,
                                                            int nzcnt,
                                                            const double *rhs,
                                                            const char *sense,
                                                            const int
                                                            *rmatbeg,
                                                            const int
                                                            *rmatind,
                                                            const double
                                                            *rmatval,
                                                            void *userhandle,
                                                            int *seqnum_p);
    CPXLIBAPI int CPXPUBLIC CPXbranchcallbackbranchconstraints (CPXCENVptr
                                                                env,
                                                                void *cbdata,
                                                                int wherefrom,
                                                                double
                                                                nodeest,
                                                                int rcnt,
                                                                int nzcnt,
                                                                const double
                                                                *rhs,
                                                                const char
                                                                *sense,
                                                                const int
                                                                *rmatbeg,
                                                                const int
                                                                *rmatind,
                                                                const double
                                                                *rmatval,
                                                                void
                                                                *userhandle,
                                                                int
                                                                *seqnum_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodex (CPXCENVptr env, void *cbdata,
                                                 int wherefrom, double *x,
                                                 int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodeobjval (CPXCENVptr env,
                                                      void *cbdata,
                                                      int wherefrom,
                                                      double *objval_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackctype (CPXCENVptr env, void *cbdata,
                                                 int wherefrom, char *xctype,
                                                 int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackorder (CPXCENVptr env, void *cbdata,
                                                 int wherefrom, int *priority,
                                                 int *direction, int begin,
                                                 int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackpseudocosts (CPXCENVptr env,
                                                       void *cbdata,
                                                       int wherefrom,
                                                       double *uppc,
                                                       double *downpc,
                                                       int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackincumbent (CPXCENVptr env,
                                                     void *cbdata,
                                                     int wherefrom, double *x,
                                                     int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodeintfeas (CPXCENVptr env,
                                                       void *cbdata,
                                                       int wherefrom,
                                                       int *feas, int begin,
                                                       int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackgloballb (CPXCENVptr env,
                                                    void *cbdata,
                                                    int wherefrom, double *lb,
                                                    int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackglobalub (CPXCENVptr env,
                                                    void *cbdata,
                                                    int wherefrom, double *ub,
                                                    int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodelb (CPXCENVptr env,
                                                  void *cbdata, int wherefrom,
                                                  double *lb, int begin,
                                                  int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodeub (CPXCENVptr env,
                                                  void *cbdata, int wherefrom,
                                                  double *ub, int begin,
                                                  int end);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacklp (CPXCENVptr env, void *cbdata,
                                              int wherefrom,
                                              CPXCLPptr * lp_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbacknodestat (CPXCENVptr env,
                                                    void *cbdata,
                                                    int wherefrom,
                                                    int *nodestat_p);
    CPXLIBAPI int CPXPUBLIC CPXgetcallbackbranchconstraints (CPXCENVptr env,
                                                             void *cbdata,
                                                             int wherefrom,
                                                             int which,
                                                             int *cuts_p,
                                                             int *nzcnt_p,
                                                             double *rhs,
                                                             char *sense,
                                                             int *rmatbeg,
                                                             int *rmatind,
                                                             double *rmatval,
                                                             int rmatsz,
                                                             int *surplus_p);
    CPXLIBAPI int CPXPUBLIC CPXaddusercuts (CPXCENVptr env, CPXLPptr lp,
                                            int rcnt, int nzcnt,
                                            const double *rhs,
                                            const char *sense,
                                            const int *rmatbeg,
                                            const int *rmatind,
                                            const double *rmatval,
                                            char **rowname);
    CPXLIBAPI int CPXPUBLIC CPXaddlazyconstraints (CPXCENVptr env,
                                                   CPXLPptr lp, int rcnt,
                                                   int nzcnt,
                                                   const double *rhs,
                                                   const char *sense,
                                                   const int *rmatbeg,
                                                   const int *rmatind,
                                                   const double *rmatval,
                                                   char **rowname);
    CPXLIBAPI int CPXPUBLIC CPXfreeusercuts (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC CPXfreelazyconstraints (CPXCENVptr env, CPXLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetusercuts (CPXCENVptr env, CPXCLPptr lp,
                     int *rcnt_p, int *nzcnt_p,
                     double **zrhs_p, char **zsense_p,
                     int **rmatbeg_p, int **rmatind_p, double **rmatval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetusercutname (CPXCENVptr env, CPXCLPptr lp,
                        char *buf_str, int bufspace, int *surplus_p,
                        int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetlazyconstraints (CPXCENVptr env, CPXCLPptr lp,
                            int *rcnt_p, int *nzcnt_p,
                            double **zrhs_p, char **zsense_p,
                            int **rmatbeg_p, int **rmatind_p,
                            double **rmatval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetlazyconstraintname (CPXCENVptr env, CPXCLPptr lp,
                               char *buf_str, int bufspace, int *surplus_p,
                               int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXordread (CPXCENVptr env, const char *filename_str, int numcols,
                char **colname, int *cnt_p, int *indices,
                int *priority, int *direction);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __GCDEFS_H
#define __GCDEFS_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPXERR_UNSUPPORTED_CONSTRAINT_TYPE 1212
#define CPXERR_ILL_DEFINED_PWL 1213
#define CPX_CON_LOWER_BOUND 1
#define CPX_CON_UPPER_BOUND 2
#define CPX_CON_LINEAR 3
#define CPX_CON_QUADRATIC 4
#define CPX_CON_SOS 5
#define CPX_CON_INDICATOR 6
#define CPX_CON_MINEXPR 7
#define CPX_CON_MAXEXPR 8
#define CPX_CON_PWL 9
#define CPX_CON_ABS 9
#define CPX_CON_DISJCST 10
#define CPX_CON_INDDISJCST 11
#define CPX_CON_SETVAR 12
#define CPX_CON_SETVARMEMBER 13
#define CPX_CON_SETVARCARD 14
#define CPX_CON_SETVARSUM 15
#define CPX_CON_SETVARMIN 16
#define CPX_CON_SETVARMAX 17
#define CPX_CON_SETVARSUBSET 18
#define CPX_CON_SETVARDOMAIN 19
#define CPX_CON_SETVARUNION 20
#define CPX_CON_SETVARINTERSECTION 21
#define CPX_CON_SETVARNULLINTERSECT 22
#define CPX_CON_SETVARINTERSECT 23
#define CPX_CON_SETVAREQ 24
#define CPX_CON_SETVARNEQ 25
#define CPX_CON_SETVARNEQCST 26
#define CPX_CON_LAST_CONTYPE 27
  CPXLIBAPI
    int CPXPUBLIC
    CPXaddindconstr (CPXCENVptr env, CPXLPptr lp, int indvar,
                     int complemented, int nzcnt, double rhs, int sense,
                     const int *linind, const double *linval,
                     const char *indname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetnumgconstrs (CPXCENVptr env, CPXCLPptr lp, int contype);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEdelgconstrs (CPXCENVptr env, CPXLPptr lp, int contype,
                     int beg, int end);
#define CPX_INDICATOR_IF 1
#define CPX_INDICATOR_ONLYIF 2
#define CPX_INDICATOR_IFANDONLYIF 3
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddindconstr (CPXCENVptr env, CPXLPptr lp, int indicator,
                      int complemented, int linnzcnt, double rhs,
                      int sense, const int *linind, const double *linval,
                      int type, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddminexpr (CPXCENVptr env, CPXLPptr lp, int y,
                    double constant, int nexpr,
                    int nnz, const int *matbeg, const int *matind,
                    const double *matval, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddmaxexpr (CPXCENVptr env, CPXLPptr lp, int y,
                    double constant, int nexpr,
                    int nnz, const int *matbeg, const int *matind,
                    const double *matval, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddpwl (CPXCENVptr env, CPXLPptr lp, int y,
                int npoints, double *point, int nslopes, double *slope,
                double a, double b, int x, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddabs (CPXCENVptr env, CPXLPptr lp, int y, int x,
                const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddsetvar (CPXCENVptr env, CPXLPptr lp, const int npvalues,
                   const double *pvalues, const int nrvalues,
                   const double *rvalues, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEchgsetvar (CPXCENVptr env, CPXLPptr lp, const int setvarid,
                   const int npvalues, const double *pvalues,
                   const int nrvalues, const double *rvalues);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEgetsetvarvalues (CPXCENVptr env, CPXLPptr lp, const int setvarid,
                         const int nvalues, const int *values, int *soln);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddsetvarmember (CPXCENVptr env, CPXLPptr lp, const int indvarid,
                         const int setvarid, const double value,
                         const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddsetvarcard (CPXCENVptr env, CPXLPptr lp, const int cardvarid,
                       const int setvarid, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEaddsetvarsum (CPXCENVptr env, CPXLPptr lp, const int sumvarid,
                      const int setvarid, const int nvalues,
                      const double *vals, const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarmin (CPXCENVptr env, CPXLPptr lp,
                                              const int minvarid,
                                              const int setvarid,
                                              const int nvalues,
                                              const double *vals,
                                              const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarmax (CPXCENVptr env, CPXLPptr lp,
                                              const int maxvarid,
                                              const int setvarid,
                                              const int nvalues,
                                              const double *vals,
                                              const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarsubset (CPXCENVptr env, CPXLPptr lp,
                                                 const int setvar1,
                                                 const int setvar2,
                                                 const int strict,
                                                 const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvardomain (CPXCENVptr env, CPXLPptr lp,
                                                 const int setvar,
                                                 const int nvalues,
                                                 const double *values,
                                                 const int possible,
                                                 const int required,
                                                 const int forbidden,
                                                 const int strict,
                                                 const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarunion (CPXCENVptr env, CPXLPptr lp,
                                                const int unionsetvar,
                                                const int servar1,
                                                const int setvar2,
                                                const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarintersection (CPXCENVptr env,
                                                       CPXLPptr lp,
                                                       const int unionsetvar,
                                                       const int servar1,
                                                       const int setvar2,
                                                       const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarnullintersect (CPXCENVptr env,
                                                        CPXLPptr lp,
                                                        const int servar1,
                                                        const int setvar2,
                                                        const char
                                                        *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarintersect (CPXCENVptr env,
                                                    CPXLPptr lp,
                                                    const int servar1,
                                                    const int setvar2,
                                                    const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvareq (CPXCENVptr env, CPXLPptr lp,
                                             const int servar1,
                                             const int setvar2,
                                             const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarneq (CPXCENVptr env, CPXLPptr lp,
                                              const int servar1,
                                              const int setvar2,
                                              const char *lname_str);
    CPXLIBAPI int CPXPUBLIC CPXEaddsetvarneqcst (CPXCENVptr env, CPXLPptr lp,
                                                 const int servar1,
                                                 const int nvalues,
                                                 const double *values,
                                                 const char *lname_str);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __CPXNET_H
#define __CPXNET_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPX_PARAM_NETITLIM 5001
#define CPX_PARAM_NETEPOPT 5002
#define CPX_PARAM_NETEPRHS 5003
#define CPX_PARAM_NETPPRIIND 5004
#define CPX_PARAM_NETDISPLAY 5005
#define CPXERR_NET_DATA 1530
#define CPXERR_NOT_MIN_COST_FLOW 1531
#define CPXERR_BAD_ROW_ID 1532
#define CPXERR_BAD_CHAR 1537
#define CPXERR_NET_FILE_SHORT 1538
#define CPXNET_NO_DISPLAY_OBJECTIVE 0
#define CPXNET_TRUE_OBJECTIVE 1
#define CPXNET_PENALIZED_OBJECTIVE 2
#define CPXNET_PRICE_AUTO 0
#define CPXNET_PRICE_PARTIAL 1
#define CPXNET_PRICE_MULT_PART 2
#define CPXNET_PRICE_SORT_MULT_PART 3
  CPXLIBAPI
    CPXNETptr CPXPUBLIC
    CPXNETcreateprob (CPXENVptr env, int *status_p, const char *name_str);
    CPXLIBAPI int CPXPUBLIC CPXNETfreeprob (CPXENVptr env, CPXNETptr * net_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETcopynet (CPXCENVptr env, CPXNETptr net, int objsen,
                   int nnodes, const double *supply, char **nnames,
                   int narcs, const int *fromnode, const int *tonode,
                   const double *low, const double *up, const double *obj,
                   char **anames);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETcopybase (CPXCENVptr env, CPXNETptr net,
                    const int *astat, const int *nstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETaddnodes (CPXCENVptr env, CPXNETptr net, int nnodes,
                    const double *supply, char **name);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETaddarcs (CPXCENVptr env, CPXNETptr net, int narcs,
                   const int *fromnode, const int *tonode,
                   const double *low, const double *up,
                   const double *obj, char **anames);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETdelnodes (CPXCENVptr env, CPXNETptr net, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETdelarcs (CPXCENVptr env, CPXNETptr net, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETdelset (CPXCENVptr env, CPXNETptr net,
                  int *whichnodes, int *whicharcs);
    CPXLIBAPI int CPXPUBLIC CPXNETprimopt (CPXCENVptr env, CPXNETptr net);
    CPXLIBAPI int CPXPUBLIC CPXNETgetstat (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetobjval (CPXCENVptr env, CPXCNETptr net, double *objval_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetx (CPXCENVptr env, CPXCNETptr net, double *x,
                int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetpi (CPXCENVptr env, CPXCNETptr net, double *pi,
                 int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetslack (CPXCENVptr env, CPXCNETptr net, double *slack,
                    int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetdj (CPXCENVptr env, CPXCNETptr net, double *dj,
                 int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXNETgetitcnt (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC CPXNETgetphase1cnt (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetbase (CPXCENVptr env, CPXCNETptr net, int *astat, int *nstat);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETsolution (CPXCENVptr env, CPXCNETptr net, int *netstat_p,
                    double *objval_p, double *x, double *pi,
                    double *slack, double *dj);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETsolninfo (CPXCENVptr env, CPXCNETptr net,
                    int *pfeasind_p, int *dfeasind_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgname (CPXCENVptr env, CPXNETptr net, int key,
                   int vindex, const char *name_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgarcname (CPXCENVptr env, CPXNETptr net, int cnt,
                      const int *indices, char **newname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgnodename (CPXCENVptr env, CPXNETptr net, int cnt,
                       const int *indices, char **newname);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgobjsen (CPXCENVptr env, CPXNETptr net, int maxormin);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgbds (CPXCENVptr env, CPXNETptr net,
                  int cnt, const int *indices, const char *lu,
                  const double *bd);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgarcnodes (CPXCENVptr env, CPXNETptr net,
                       int cnt, const int *indices, const int *fromnode,
                       const int *tonode);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgobj (CPXCENVptr env, CPXNETptr net,
                  int cnt, const int *indices, const double *obj);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETchgsupply (CPXCENVptr env, CPXNETptr net,
                     int cnt, const int *indices, const double *supply);
    CPXLIBAPI int CPXPUBLIC CPXNETgetobjsen (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetsupply (CPXCENVptr env, CPXCNETptr net, double *supply,
                     int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetprobname (CPXCENVptr env, CPXCNETptr net, char *buf_str,
                       int bufspace, int *surplus_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetnodename (CPXCENVptr env, CPXCNETptr net,
                       char **nnames, char *namestore, int namespc,
                       int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetarcname (CPXCENVptr env, CPXCNETptr net,
                      char **nnames, char *namestore, int namespc,
                      int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetlb (CPXCENVptr env, CPXCNETptr net, double *low,
                 int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetub (CPXCENVptr env, CPXCNETptr net,
                 double *up, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetobj (CPXCENVptr env, CPXCNETptr net,
                  double *obj, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetarcnodes (CPXCENVptr env, CPXCNETptr net,
                       int *fromnode, int *tonode, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetnodearcs (CPXCENVptr env, CPXCNETptr net, int *arccnt_p,
                       int *arcbeg, int *arc, int arcspace, int *surplus_p,
                       int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC CPXNETgetnumnodes (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI int CPXPUBLIC CPXNETgetnumarcs (CPXCENVptr env, CPXCNETptr net);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetnodeindex (CPXCENVptr env, CPXCNETptr net, const char *lname_str,
                        int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETgetarcindex (CPXCENVptr env, CPXCNETptr net, const char *lname_str,
                       int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXNETreadcopyprob (CPXCENVptr env, CPXNETptr net,
                        const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXNETreadcopybase (CPXCENVptr env, CPXNETptr net,
                                                const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXNETwriteprob (CPXCENVptr env, CPXCNETptr net,
                                             const char *filename_str,
                                             const char *format_str);
    CPXLIBAPI int CPXPUBLIC CPXNETbasewrite (CPXCENVptr env, CPXCNETptr net,
                                             const char *filename_str);
    CPXLIBAPI int CPXPUBLIC CPXNETcheckcopynet (CPXCENVptr env, CPXNETptr net,
                                                int objsen, int nnodes,
                                                const double *supply,
                                                char **nnames, int narcs,
                                                const int *fromnode,
                                                const int *tonode,
                                                const double *low,
                                                const double *up,
                                                const double *obj,
                                                char **aname);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __QPDEFS_H
#define __QPDEFS_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPXERR_Q_NOT_POS_DEF 5002
#define CPXERR_NOT_QP 5004
#define CPXERR_Q_DUP_ENTRY 5011
#define CPXERR_Q_NOT_SYMMETRIC 5012
#define CPXERR_Q_NOT_INDEF 5014
#define CPX_PARAM_QPNZREADLIM 4001
#define CPX_PARAM_QPMAKEPSDIND 4010
  CPXLIBAPI
    int CPXPUBLIC
    CPXcopyquad (CPXCENVptr env, CPXLPptr lp, const int *qmatbeg,
                 const int *qmatcnt, const int *qmatind,
                 const double *qmatval);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcopyqpsep (CPXCENVptr env, CPXLPptr lp, const double *qsepvec);
    CPXLIBAPI
    int CPXPUBLIC
    CPXchgqpcoef (CPXCENVptr env, CPXLPptr lp, int i, int j, double newvalue);
    CPXLIBAPI int CPXPUBLIC CPXgetnumqpnz (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI int CPXPUBLIC CPXgetnumquad (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqpcoef (CPXCENVptr env, CPXCLPptr lp, int rownum, int colnum,
                  double *coef_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetquad (CPXCENVptr env, CPXCLPptr lp, int *nzcnt_p,
                int *qmatbeg, int *qmatind, double *qmatval,
                int qmatspace, int *surplus_p, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXqpindefcertificate (CPXCENVptr env, CPXCLPptr lp, double *x);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckcopyqpsep (CPXCENVptr env, CPXCLPptr lp, const double *qsepvec);
    CPXLIBAPI
    int CPXPUBLIC
    CPXcheckcopyquad (CPXCENVptr env, CPXCLPptr lp, const int *qmatbeg,
                      const int *qmatcnt, const int *qmatind,
                      const double *qmatval);
    CPXLIBAPI int CPXPUBLIC CPXqpopt (CPXCENVptr env, CPXLPptr lp);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif
#ifndef __SOCPDEFS_H
#define __SOCPDEFS_H
#ifdef _WIN32
#pragma pack(push, 8)
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define CPXERR_QCP_SENSE 6002
  CPXLIBAPI
    int CPXPUBLIC
    CPXaddqconstr (CPXCENVptr env, CPXLPptr lp,
                   int linnzcnt, int quadnzcnt, double rhs, int sense,
                   const int *linind, const double *linval,
                   const int *quadrow, const int *quadcol,
                   const double *quadval, const char *lname_str);
    CPXLIBAPI
    int CPXPUBLIC
    CPXdelqconstrs (CPXCENVptr env, CPXLPptr lp, int begin, int end);
    CPXLIBAPI int CPXPUBLIC CPXgetnumqconstrs (CPXCENVptr env, CPXCLPptr lp);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqconstrindex (CPXCENVptr env, CPXCLPptr lp,
                        const char *lname_str, int *index_p);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqconstr (CPXCENVptr env, CPXCLPptr lp,
                   int *linnzcnt_p, int *quadnzcnt_p,
                   double *rhs_p, char *sense_p,
                   int *linind, double *linval,
                   int linspace, int *linsurplus_p,
                   int *quadrow, int *quadcol, double *quadval,
                   int quadspace, int *quadsurplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqconstrname (CPXCENVptr env, CPXCLPptr lp, char *buf_str,
                       int bufspace, int *surplus_p, int which);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqconstrslack (CPXCENVptr env, CPXCLPptr lp, double *qcslack,
                        int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXqconstrslackfromx (CPXCENVptr env, CPXCLPptr lp,
                          const double *x, double *qcslack);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetqconstrinfeas (CPXCENVptr env,
                         CPXCLPptr lp,
                         const double *x,
                         double *infeasout, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXgetxqxax (CPXCENVptr env, CPXCLPptr lp,
                 double *xqxax, int begin, int end);
    CPXLIBAPI
    int CPXPUBLIC
    CPXEchgqcname (CPXCENVptr env, CPXLPptr lp,
                   int cnt, const int *indices, char **newname);
#ifdef __cplusplus
}
#endif
#ifdef _WIN32
#pragma pack(pop)
#endif

#endif                          /* _CPLEX_H */
