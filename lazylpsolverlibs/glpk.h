#ifndef _GLPK_H
#define _GLPK_H

/*
 * This header was partly generated from a solver header of the same name,
 * to make lazylpsolverlibs callable. It contains only constants,
 * structures, and macros generated from the original header, and thus,
 * contains no copyrightable information.
 *
 * Additionnal hand editing was also probably performed.
 */

#include <stdarg.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C"
{
#endif
#define GLP_MAJOR_VERSION 4
#define GLP_MINOR_VERSION 43
#ifndef GLP_PROB_DEFINED
#define GLP_PROB_DEFINED
  typedef struct
  {
    double _opaque_prob[100];
  } glp_prob;
#endif
#define GLP_MIN 1
#define GLP_MAX 2
#define GLP_CV 1
#define GLP_IV 2
#define GLP_BV 3
#define GLP_FR 1
#define GLP_LO 2
#define GLP_UP 3
#define GLP_DB 4
#define GLP_FX 5
#define GLP_BS 1
#define GLP_NL 2
#define GLP_NU 3
#define GLP_NF 4
#define GLP_NS 5
#define GLP_SF_GM 0x01
#define GLP_SF_EQ 0x10
#define GLP_SF_2N 0x20
#define GLP_SF_SKIP 0x40
#define GLP_SF_AUTO 0x80
#define GLP_SOL 1
#define GLP_IPT 2
#define GLP_MIP 3
#define GLP_UNDEF 1
#define GLP_FEAS 2
#define GLP_INFEAS 3
#define GLP_NOFEAS 4
#define GLP_OPT 5
#define GLP_UNBND 6
  typedef struct
  {
    int msg_lev;
    int type;
#define GLP_BF_FT 1
#define GLP_BF_BG 2
#define GLP_BF_GR 3
    int lu_size;
    double piv_tol;
    int piv_lim;
    int suhl;
    double eps_tol;
    double max_gro;
    int nfs_max;
    double upd_tol;
    int nrs_max;
    int rs_size;
    double foo_bar[38];
  } glp_bfcp;
  typedef struct
  {
    int msg_lev;
#define GLP_MSG_OFF 0
#define GLP_MSG_ERR 1
#define GLP_MSG_ON 2
#define GLP_MSG_ALL 3
#define GLP_MSG_DBG 4
    int meth;
#define GLP_PRIMAL 1
#define GLP_DUALP 2
#define GLP_DUAL 3
    int pricing;
#define GLP_PT_STD 0x11
#define GLP_PT_PSE 0x22
    int r_test;
#define GLP_RT_STD 0x11
#define GLP_RT_HAR 0x22
    double tol_bnd;
    double tol_dj;
    double tol_piv;
    double obj_ll;
    double obj_ul;
    int it_lim;
    int tm_lim;
    int out_frq;
    int out_dly;
    int presolve;
    double foo_bar[36];
  } glp_smcp;
  typedef struct
  {
    int msg_lev;
    int ord_alg;
#define GLP_ORD_NONE 0
#define GLP_ORD_QMD 1
#define GLP_ORD_AMD 2
#define GLP_ORD_SYMAMD 3
    double foo_bar[48];
  } glp_iptcp;
#ifndef GLP_TREE_DEFINED
#define GLP_TREE_DEFINED
  typedef struct
  {
    double _opaque_tree[100];
  } glp_tree;
#endif
  typedef struct
  {
    int msg_lev;
    int br_tech;
#define GLP_BR_FFV 1
#define GLP_BR_LFV 2
#define GLP_BR_MFV 3
#define GLP_BR_DTH 4
#define GLP_BR_PCH 5
    int bt_tech;
#define GLP_BT_DFS 1
#define GLP_BT_BFS 2
#define GLP_BT_BLB 3
#define GLP_BT_BPH 4
    double tol_int;
    double tol_obj;
    int tm_lim;
    int out_frq;
    int out_dly;
    void (*cb_func) (glp_tree * T, void *info);
    void *cb_info;
    int cb_size;
    int pp_tech;
#define GLP_PP_NONE 0
#define GLP_PP_ROOT 1
#define GLP_PP_ALL 2
    double mip_gap;
    int mir_cuts;
    int gmi_cuts;
    int cov_cuts;
    int clq_cuts;
    int presolve;
    int binarize;
    int fp_heur;
    double foo_bar[30];
  } glp_iocp;
  typedef struct
  {
    int level;
    int origin;
#define GLP_RF_REG 0
#define GLP_RF_LAZY 1
#define GLP_RF_CUT 2
    int klass;
#define GLP_RF_GMI 1
#define GLP_RF_MIR 2
#define GLP_RF_COV 3
#define GLP_RF_CLQ 4
    double foo_bar[7];
  } glp_attr;
#define GLP_ON 1
#define GLP_OFF 0
#define GLP_IROWGEN 0x01
#define GLP_IBINGO 0x02
#define GLP_IHEUR 0x03
#define GLP_ICUTGEN 0x04
#define GLP_IBRANCH 0x05
#define GLP_ISELECT 0x06
#define GLP_IPREPRO 0x07
#define GLP_NO_BRNCH 0
#define GLP_DN_BRNCH 1
#define GLP_UP_BRNCH 2
#define GLP_EBADB 0x01
#define GLP_ESING 0x02
#define GLP_ECOND 0x03
#define GLP_EBOUND 0x04
#define GLP_EFAIL 0x05
#define GLP_EOBJLL 0x06
#define GLP_EOBJUL 0x07
#define GLP_EITLIM 0x08
#define GLP_ETMLIM 0x09
#define GLP_ENOPFS 0x0A
#define GLP_ENODFS 0x0B
#define GLP_EROOT 0x0C
#define GLP_ESTOP 0x0D
#define GLP_EMIPGAP 0x0E
#define GLP_ENOFEAS 0x0F
#define GLP_ENOCVG 0x10
#define GLP_EINSTAB 0x11
#define GLP_EDATA 0x12
#define GLP_ERANGE 0x13
#define GLP_KKT_PE 1
#define GLP_KKT_PB 2
#define GLP_KKT_DE 3
#define GLP_KKT_DB 4
#define GLP_KKT_CS 5
#define GLP_MPS_DECK 1
#define GLP_MPS_FILE 2
  typedef struct
  {
    int blank;
    char *obj_name;
    double tol_mps;
    double foo_bar[17];
  } glp_mpscp;
  typedef struct
  {
    double foo_bar[20];
  } glp_cpxcp;
#ifndef GLP_TRAN_DEFINED
#define GLP_TRAN_DEFINED
  typedef struct
  {
    double _opaque_tran[100];
  } glp_tran;
#endif
  glp_prob *glp_create_prob (void);
  void glp_set_prob_name (glp_prob * P, const char *name);
  void glp_set_obj_name (glp_prob * P, const char *name);
  void glp_set_obj_dir (glp_prob * P, int dir);
  int glp_add_rows (glp_prob * P, int nrs);
  int glp_add_cols (glp_prob * P, int ncs);
  void glp_set_row_name (glp_prob * P, int i, const char *name);
  void glp_set_col_name (glp_prob * P, int j, const char *name);
  void glp_set_row_bnds (glp_prob * P, int i, int type, double lb, double ub);
  void glp_set_col_bnds (glp_prob * P, int j, int type, double lb, double ub);
  void glp_set_obj_coef (glp_prob * P, int j, double coef);
  void glp_set_mat_row (glp_prob * P, int i, int len, const int ind[],
                        const double val[]);
  void glp_set_mat_col (glp_prob * P, int j, int len, const int ind[],
                        const double val[]);
  void glp_load_matrix (glp_prob * P, int ne, const int ia[],
                        const int ja[], const double ar[]);
  int glp_check_dup (int m, int n, int ne, const int ia[], const int ja[]);
  void glp_sort_matrix (glp_prob * P);
  void glp_del_rows (glp_prob * P, int nrs, const int num[]);
  void glp_del_cols (glp_prob * P, int ncs, const int num[]);
  void glp_copy_prob (glp_prob * dest, glp_prob * prob, int names);
  void glp_erase_prob (glp_prob * P);
  void glp_delete_prob (glp_prob * P);
  const char *glp_get_prob_name (glp_prob * P);
  const char *glp_get_obj_name (glp_prob * P);
  int glp_get_obj_dir (glp_prob * P);
  int glp_get_num_rows (glp_prob * P);
  int glp_get_num_cols (glp_prob * P);
  const char *glp_get_row_name (glp_prob * P, int i);
  const char *glp_get_col_name (glp_prob * P, int j);
  int glp_get_row_type (glp_prob * P, int i);
  double glp_get_row_lb (glp_prob * P, int i);
  double glp_get_row_ub (glp_prob * P, int i);
  int glp_get_col_type (glp_prob * P, int j);
  double glp_get_col_lb (glp_prob * P, int j);
  double glp_get_col_ub (glp_prob * P, int j);
  double glp_get_obj_coef (glp_prob * P, int j);
  int glp_get_num_nz (glp_prob * P);
  int glp_get_mat_row (glp_prob * P, int i, int ind[], double val[]);
  int glp_get_mat_col (glp_prob * P, int j, int ind[], double val[]);
  void glp_create_index (glp_prob * P);
  int glp_find_row (glp_prob * P, const char *name);
  int glp_find_col (glp_prob * P, const char *name);
  void glp_delete_index (glp_prob * P);
  void glp_set_rii (glp_prob * P, int i, double rii);
  void glp_set_sjj (glp_prob * P, int j, double sjj);
  double glp_get_rii (glp_prob * P, int i);
  double glp_get_sjj (glp_prob * P, int j);
  void glp_scale_prob (glp_prob * P, int flags);
  void glp_unscale_prob (glp_prob * P);
  void glp_set_row_stat (glp_prob * P, int i, int stat);
  void glp_set_col_stat (glp_prob * P, int j, int stat);
  void glp_std_basis (glp_prob * P);
  void glp_adv_basis (glp_prob * P, int flags);
  void glp_cpx_basis (glp_prob * P);
  int glp_simplex (glp_prob * P, const glp_smcp * parm);
  int glp_exact (glp_prob * P, const glp_smcp * parm);
  void glp_init_smcp (glp_smcp * parm);
  int glp_get_status (glp_prob * P);
  int glp_get_prim_stat (glp_prob * P);
  int glp_get_dual_stat (glp_prob * P);
  double glp_get_obj_val (glp_prob * P);
  int glp_get_row_stat (glp_prob * P, int i);
  double glp_get_row_prim (glp_prob * P, int i);
  double glp_get_row_dual (glp_prob * P, int i);
  int glp_get_col_stat (glp_prob * P, int j);
  double glp_get_col_prim (glp_prob * P, int j);
  double glp_get_col_dual (glp_prob * P, int j);
  int glp_get_unbnd_ray (glp_prob * P);
  int glp_interior (glp_prob * P, const glp_iptcp * parm);
  void glp_init_iptcp (glp_iptcp * parm);
  int glp_ipt_status (glp_prob * P);
  double glp_ipt_obj_val (glp_prob * P);
  double glp_ipt_row_prim (glp_prob * P, int i);
  double glp_ipt_row_dual (glp_prob * P, int i);
  double glp_ipt_col_prim (glp_prob * P, int j);
  double glp_ipt_col_dual (glp_prob * P, int j);
  void glp_set_col_kind (glp_prob * P, int j, int kind);
  int glp_get_col_kind (glp_prob * P, int j);
  int glp_get_num_int (glp_prob * P);
  int glp_get_num_bin (glp_prob * P);
  int glp_intopt (glp_prob * P, const glp_iocp * parm);
  void glp_init_iocp (glp_iocp * parm);
  int glp_mip_status (glp_prob * P);
  double glp_mip_obj_val (glp_prob * P);
  double glp_mip_row_val (glp_prob * P, int i);
  double glp_mip_col_val (glp_prob * P, int j);
  int glp_print_sol (glp_prob * P, const char *fname);
  int glp_read_sol (glp_prob * P, const char *fname);
  int glp_write_sol (glp_prob * P, const char *fname);
  int glp_print_ranges (glp_prob * P, int len, const int list[],
                        int flags, const char *fname);
  int glp_print_ipt (glp_prob * P, const char *fname);
  int glp_read_ipt (glp_prob * P, const char *fname);
  int glp_write_ipt (glp_prob * P, const char *fname);
  int glp_print_mip (glp_prob * P, const char *fname);
  int glp_read_mip (glp_prob * P, const char *fname);
  int glp_write_mip (glp_prob * P, const char *fname);
  int glp_bf_exists (glp_prob * P);
  int glp_factorize (glp_prob * P);
  int glp_bf_updated (glp_prob * P);
  void glp_get_bfcp (glp_prob * P, glp_bfcp * parm);
  void glp_set_bfcp (glp_prob * P, const glp_bfcp * parm);
  int glp_get_bhead (glp_prob * P, int k);
  int glp_get_row_bind (glp_prob * P, int i);
  int glp_get_col_bind (glp_prob * P, int j);
  void glp_ftran (glp_prob * P, double x[]);
  void glp_btran (glp_prob * P, double x[]);
  int glp_warm_up (glp_prob * P);
  int glp_eval_tab_row (glp_prob * P, int k, int ind[], double val[]);
  int glp_eval_tab_col (glp_prob * P, int k, int ind[], double val[]);
  int glp_transform_row (glp_prob * P, int len, int ind[], double val[]);
  int glp_transform_col (glp_prob * P, int len, int ind[], double val[]);
  int glp_prim_rtest (glp_prob * P, int len, const int ind[],
                      const double val[], int dir, double eps);
  int glp_dual_rtest (glp_prob * P, int len, const int ind[],
                      const double val[], int dir, double eps);
  void glp_analyze_bound (glp_prob * P, int k, double *value1, int *var1,
                          double *value2, int *var2);
  void glp_analyze_coef (glp_prob * P, int k, double *coef1, int *var1,
                         double *value1, double *coef2, int *var2,
                         double *value2);
  int glp_ios_reason (glp_tree * T);
  glp_prob *glp_ios_get_prob (glp_tree * T);
  void glp_ios_tree_size (glp_tree * T, int *a_cnt, int *n_cnt, int *t_cnt);
  int glp_ios_curr_node (glp_tree * T);
  int glp_ios_next_node (glp_tree * T, int p);
  int glp_ios_prev_node (glp_tree * T, int p);
  int glp_ios_up_node (glp_tree * T, int p);
  int glp_ios_node_level (glp_tree * T, int p);
  double glp_ios_node_bound (glp_tree * T, int p);
  int glp_ios_best_node (glp_tree * T);
  double glp_ios_mip_gap (glp_tree * T);
  void *glp_ios_node_data (glp_tree * T, int p);
  void glp_ios_row_attr (glp_tree * T, int i, glp_attr * attr);
  int glp_ios_pool_size (glp_tree * T);
  int glp_ios_add_row (glp_tree * T,
                       const char *name, int klass, int flags, int len,
                       const int ind[], const double val[], int type,
                       double rhs);
  void glp_ios_del_row (glp_tree * T, int i);
  void glp_ios_clear_pool (glp_tree * T);
  int glp_ios_can_branch (glp_tree * T, int j);
  void glp_ios_branch_upon (glp_tree * T, int j, int sel);
  void glp_ios_select_node (glp_tree * T, int p);
  int glp_ios_heur_sol (glp_tree * T, const double x[]);
  void glp_ios_terminate (glp_tree * T);
  void glp_init_mpscp (glp_mpscp * parm);
  int glp_read_mps (glp_prob * P, int fmt, const glp_mpscp * parm,
                    const char *fname);
  int glp_write_mps (glp_prob * P, int fmt, const glp_mpscp * parm,
                     const char *fname);
  void glp_init_cpxcp (glp_cpxcp * parm);
  int glp_read_lp (glp_prob * P, const glp_cpxcp * parm, const char *fname);
  int glp_write_lp (glp_prob * P, const glp_cpxcp * parm, const char *fname);
  int glp_read_prob (glp_prob * P, int flags, const char *fname);
  int glp_write_prob (glp_prob * P, int flags, const char *fname);
  glp_tran *glp_mpl_alloc_wksp (void);
  int glp_mpl_read_model (glp_tran * tran, const char *fname, int skip);
  int glp_mpl_read_data (glp_tran * tran, const char *fname);
  int glp_mpl_generate (glp_tran * tran, const char *fname);
  void glp_mpl_build_prob (glp_tran * tran, glp_prob * prob);
  int glp_mpl_postsolve (glp_tran * tran, glp_prob * prob, int sol);
  void glp_mpl_free_wksp (glp_tran * tran);
  int glp_main (int argc, const char *argv[]);
#ifndef GLP_LONG_DEFINED
#define GLP_LONG_DEFINED
  typedef struct
  {
    int lo, hi;
  } glp_long;
#endif
  int glp_init_env (void);
  const char *glp_version (void);
  int glp_free_env (void);
  void glp_printf (const char *fmt, ...);
  void glp_vprintf (const char *fmt, va_list arg);
  int glp_term_out (int flag);
  void glp_term_hook (int (*func) (void *info, const char *s), void *info);
  int glp_open_tee (const char *fname);
  int glp_close_tee (void);
#ifndef GLP_ERROR_DEFINED
#define GLP_ERROR_DEFINED
  typedef void (*_glp_error) (const char *fmt, ...);
#endif
#define glp_error glp_error_(__FILE__, __LINE__)
  _glp_error glp_error_ (const char *file, int line);
#define glp_assert(expr) \
      ((void)((expr) || (glp_assert_(#expr, __FILE__, __LINE__), 1)))
  void glp_assert_ (const char *expr, const char *file, int line);
  void glp_error_hook (void (*func) (void *info), void *info);
  void *glp_malloc (int size);
  void *glp_calloc (int n, int size);
  void glp_free (void *ptr);
  void glp_mem_limit (int limit);
  void glp_mem_usage (int *count, int *cpeak, glp_long * total,
                      glp_long * tpeak);
  glp_long glp_time (void);
  double glp_difftime (glp_long t1, glp_long t0);
#ifndef GLP_DATA_DEFINED
#define GLP_DATA_DEFINED
  typedef struct
  {
    double _opaque_data[100];
  } glp_data;
#endif
  glp_data *glp_sdf_open_file (const char *fname);
  void glp_sdf_set_jump (glp_data * data, void *jump);
  void glp_sdf_error (glp_data * data, const char *fmt, ...);
  void glp_sdf_warning (glp_data * data, const char *fmt, ...);
  int glp_sdf_read_int (glp_data * data);
  double glp_sdf_read_num (glp_data * data);
  const char *glp_sdf_read_item (glp_data * data);
  const char *glp_sdf_read_text (glp_data * data);
  int glp_sdf_line (glp_data * data);
  void glp_sdf_close_file (glp_data * data);
  typedef struct _glp_graph glp_graph;
  typedef struct _glp_vertex glp_vertex;
  typedef struct _glp_arc glp_arc;
  struct _glp_graph
  {
    void *pool;
    char *name;
    int nv_max;
    int nv;
    int na;
    glp_vertex **v;
    void *index;
    int v_size;
    int a_size;
  };
  struct _glp_vertex
  {
    int i;
    char *name;
    void *entry;
    void *data;
    void *temp;
    glp_arc *in;
    glp_arc *out;
  };
  struct _glp_arc
  {
    glp_vertex *tail;
    glp_vertex *head;
    void *data;
    void *temp;
    glp_arc *t_prev;
    glp_arc *t_next;
    glp_arc *h_prev;
    glp_arc *h_next;
  };
  glp_graph *glp_create_graph (int v_size, int a_size);
  void glp_set_graph_name (glp_graph * G, const char *name);
  int glp_add_vertices (glp_graph * G, int nadd);
  void glp_set_vertex_name (glp_graph * G, int i, const char *name);
  glp_arc *glp_add_arc (glp_graph * G, int i, int j);
  void glp_del_vertices (glp_graph * G, int ndel, const int num[]);
  void glp_del_arc (glp_graph * G, glp_arc * a);
  void glp_erase_graph (glp_graph * G, int v_size, int a_size);
  void glp_delete_graph (glp_graph * G);
  void glp_create_v_index (glp_graph * G);
  int glp_find_vertex (glp_graph * G, const char *name);
  void glp_delete_v_index (glp_graph * G);
  int glp_read_graph (glp_graph * G, const char *fname);
  int glp_write_graph (glp_graph * G, const char *fname);
  void glp_mincost_lp (glp_prob * P, glp_graph * G, int names, int v_rhs,
                       int a_low, int a_cap, int a_cost);
  int glp_mincost_okalg (glp_graph * G, int v_rhs, int a_low, int a_cap,
                         int a_cost, double *sol, int a_x, int v_pi);
  void glp_maxflow_lp (glp_prob * P, glp_graph * G, int names, int s,
                       int t, int a_cap);
  int glp_maxflow_ffalg (glp_graph * G, int s, int t, int a_cap,
                         double *sol, int a_x, int v_cut);
  int glp_check_asnprob (glp_graph * G, int v_set);
#define GLP_ASN_MIN 1
#define GLP_ASN_MAX 2
#define GLP_ASN_MMP 3
  int glp_asnprob_lp (glp_prob * P, int form, glp_graph * G, int names,
                      int v_set, int a_cost);
  int glp_asnprob_okalg (int form, glp_graph * G, int v_set, int a_cost,
                         double *sol, int a_x);
  int glp_asnprob_hall (glp_graph * G, int v_set, int a_x);
  int glp_read_mincost (glp_graph * G, int v_rhs, int a_low, int a_cap,
                        int a_cost, const char *fname);
  int glp_write_mincost (glp_graph * G, int v_rhs, int a_low, int a_cap,
                         int a_cost, const char *fname);
  int glp_read_maxflow (glp_graph * G, int *s, int *t, int a_cap,
                        const char *fname);
  int glp_write_maxflow (glp_graph * G, int s, int t, int a_cap,
                         const char *fname);
  int glp_read_asnprob (glp_graph * G, int v_set, int a_cost, const char
                        *fname);
  int glp_write_asnprob (glp_graph * G, int v_set, int a_cost, const char
                         *fname);
  int glp_read_ccdata (glp_graph * G, int v_wgt, const char *fname);
  int glp_write_ccdata (glp_graph * G, int v_wgt, const char *fname);
  int glp_netgen (glp_graph * G, int v_rhs, int a_cap, int a_cost,
                  const int parm[1 + 15]);
  int glp_gridgen (glp_graph * G, int v_rhs, int a_cap, int a_cost,
                   const int parm[1 + 14]);
  int glp_rmfgen (glp_graph * G, int *s, int *t, int a_cap,
                  const int parm[1 + 5]);
  int glp_weak_comp (glp_graph * G, int v_num);
  int glp_strong_comp (glp_graph * G, int v_num);
  int glp_top_sort (glp_graph * G, int v_num);
  int glp_wclique_exact (glp_graph * G, int v_wgt, double *sol, int v_set);
#define LPX glp_prob
#define LPX_LP 100
#define LPX_MIP 101
#define LPX_FR 110
#define LPX_LO 111
#define LPX_UP 112
#define LPX_DB 113
#define LPX_FX 114
#define LPX_MIN 120
#define LPX_MAX 121
#define LPX_P_UNDEF 132
#define LPX_P_FEAS 133
#define LPX_P_INFEAS 134
#define LPX_P_NOFEAS 135
#define LPX_D_UNDEF 136
#define LPX_D_FEAS 137
#define LPX_D_INFEAS 138
#define LPX_D_NOFEAS 139
#define LPX_BS 140
#define LPX_NL 141
#define LPX_NU 142
#define LPX_NF 143
#define LPX_NS 144
#define LPX_T_UNDEF 150
#define LPX_T_OPT 151
#define LPX_CV 160
#define LPX_IV 161
#define LPX_I_UNDEF 170
#define LPX_I_OPT 171
#define LPX_I_FEAS 172
#define LPX_I_NOFEAS 173
#define LPX_OPT 180
#define LPX_FEAS 181
#define LPX_INFEAS 182
#define LPX_NOFEAS 183
#define LPX_UNBND 184
#define LPX_UNDEF 185
#define LPX_E_OK 200
#define LPX_E_EMPTY 201
#define LPX_E_BADB 202
#define LPX_E_INFEAS 203
#define LPX_E_FAULT 204
#define LPX_E_OBJLL 205
#define LPX_E_OBJUL 206
#define LPX_E_ITLIM 207
#define LPX_E_TMLIM 208
#define LPX_E_NOFEAS 209
#define LPX_E_INSTAB 210
#define LPX_E_SING 211
#define LPX_E_NOCONV 212
#define LPX_E_NOPFS 213
#define LPX_E_NODFS 214
#define LPX_E_MIPGAP 215
#define LPX_K_MSGLEV 300
#define LPX_K_SCALE 301
#define LPX_K_DUAL 302
#define LPX_K_PRICE 303
#define LPX_K_RELAX 304
#define LPX_K_TOLBND 305
#define LPX_K_TOLDJ 306
#define LPX_K_TOLPIV 307
#define LPX_K_ROUND 308
#define LPX_K_OBJLL 309
#define LPX_K_OBJUL 310
#define LPX_K_ITLIM 311
#define LPX_K_ITCNT 312
#define LPX_K_TMLIM 313
#define LPX_K_OUTFRQ 314
#define LPX_K_OUTDLY 315
#define LPX_K_BRANCH 316
#define LPX_K_BTRACK 317
#define LPX_K_TOLINT 318
#define LPX_K_TOLOBJ 319
#define LPX_K_MPSINFO 320
#define LPX_K_MPSOBJ 321
#define LPX_K_MPSORIG 322
#define LPX_K_MPSWIDE 323
#define LPX_K_MPSFREE 324
#define LPX_K_MPSSKIP 325
#define LPX_K_LPTORIG 326
#define LPX_K_PRESOL 327
#define LPX_K_BINARIZE 328
#define LPX_K_USECUTS 329
#define LPX_K_BFTYPE 330
#define LPX_K_MIPGAP 331
#define LPX_C_COVER 0x01
#define LPX_C_CLIQUE 0x02
#define LPX_C_GOMORY 0x04
#define LPX_C_MIR 0x08
#define LPX_C_ALL 0xFF
  typedef struct
  {
    double pe_ae_max;
    int pe_ae_row;
    double pe_re_max;
    int pe_re_row;
    int pe_quality;
    double pb_ae_max;
    int pb_ae_ind;
    double pb_re_max;
    int pb_re_ind;
    int pb_quality;
    double de_ae_max;
    int de_ae_col;
    double de_re_max;
    int de_re_col;
    int de_quality;
    double db_ae_max;
    int db_ae_ind;
    double db_re_max;
    int db_re_ind;
    int db_quality;
    double cs_ae_max;
    int cs_ae_ind;
    double cs_re_max;
    int cs_re_ind;
    int cs_quality;
  } LPXKKT;
#define lpx_create_prob _glp_lpx_create_prob
  LPX *lpx_create_prob (void);
#define lpx_set_prob_name _glp_lpx_set_prob_name
  void lpx_set_prob_name (LPX * lp, const char *name);
#define lpx_set_obj_name _glp_lpx_set_obj_name
  void lpx_set_obj_name (LPX * lp, const char *name);
#define lpx_set_obj_dir _glp_lpx_set_obj_dir
  void lpx_set_obj_dir (LPX * lp, int dir);
#define lpx_add_rows _glp_lpx_add_rows
  int lpx_add_rows (LPX * lp, int nrs);
#define lpx_add_cols _glp_lpx_add_cols
  int lpx_add_cols (LPX * lp, int ncs);
#define lpx_set_row_name _glp_lpx_set_row_name
  void lpx_set_row_name (LPX * lp, int i, const char *name);
#define lpx_set_col_name _glp_lpx_set_col_name
  void lpx_set_col_name (LPX * lp, int j, const char *name);
#define lpx_set_row_bnds _glp_lpx_set_row_bnds
  void lpx_set_row_bnds (LPX * lp, int i, int type, double lb, double ub);
#define lpx_set_col_bnds _glp_lpx_set_col_bnds
  void lpx_set_col_bnds (LPX * lp, int j, int type, double lb, double ub);
#define lpx_set_obj_coef _glp_lpx_set_obj_coef
  void lpx_set_obj_coef (glp_prob * lp, int j, double coef);
#define lpx_set_mat_row _glp_lpx_set_mat_row
  void lpx_set_mat_row (LPX * lp, int i, int len, const int ind[],
                        const double val[]);
#define lpx_set_mat_col _glp_lpx_set_mat_col
  void lpx_set_mat_col (LPX * lp, int j, int len, const int ind[],
                        const double val[]);
#define lpx_load_matrix _glp_lpx_load_matrix
  void lpx_load_matrix (LPX * lp, int ne, const int ia[], const int ja[],
                        const double ar[]);
#define lpx_del_rows _glp_lpx_del_rows
  void lpx_del_rows (LPX * lp, int nrs, const int num[]);
#define lpx_del_cols _glp_lpx_del_cols
  void lpx_del_cols (LPX * lp, int ncs, const int num[]);
#define lpx_delete_prob _glp_lpx_delete_prob
  void lpx_delete_prob (LPX * lp);
#define lpx_get_prob_name _glp_lpx_get_prob_name
  const char *lpx_get_prob_name (LPX * lp);
#define lpx_get_obj_name _glp_lpx_get_obj_name
  const char *lpx_get_obj_name (LPX * lp);
#define lpx_get_obj_dir _glp_lpx_get_obj_dir
  int lpx_get_obj_dir (LPX * lp);
#define lpx_get_num_rows _glp_lpx_get_num_rows
  int lpx_get_num_rows (LPX * lp);
#define lpx_get_num_cols _glp_lpx_get_num_cols
  int lpx_get_num_cols (LPX * lp);
#define lpx_get_row_name _glp_lpx_get_row_name
  const char *lpx_get_row_name (LPX * lp, int i);
#define lpx_get_col_name _glp_lpx_get_col_name
  const char *lpx_get_col_name (LPX * lp, int j);
#define lpx_get_row_type _glp_lpx_get_row_type
  int lpx_get_row_type (LPX * lp, int i);
#define lpx_get_row_lb _glp_lpx_get_row_lb
  double lpx_get_row_lb (LPX * lp, int i);
#define lpx_get_row_ub _glp_lpx_get_row_ub
  double lpx_get_row_ub (LPX * lp, int i);
#define lpx_get_row_bnds _glp_lpx_get_row_bnds
  void lpx_get_row_bnds (LPX * lp, int i, int *typx, double *lb, double *ub);
#define lpx_get_col_type _glp_lpx_get_col_type
  int lpx_get_col_type (LPX * lp, int j);
#define lpx_get_col_lb _glp_lpx_get_col_lb
  double lpx_get_col_lb (LPX * lp, int j);
#define lpx_get_col_ub _glp_lpx_get_col_ub
  double lpx_get_col_ub (LPX * lp, int j);
#define lpx_get_col_bnds _glp_lpx_get_col_bnds
  void lpx_get_col_bnds (LPX * lp, int j, int *typx, double *lb, double *ub);
#define lpx_get_obj_coef _glp_lpx_get_obj_coef
  double lpx_get_obj_coef (LPX * lp, int j);
#define lpx_get_num_nz _glp_lpx_get_num_nz
  int lpx_get_num_nz (LPX * lp);
#define lpx_get_mat_row _glp_lpx_get_mat_row
  int lpx_get_mat_row (LPX * lp, int i, int ind[], double val[]);
#define lpx_get_mat_col _glp_lpx_get_mat_col
  int lpx_get_mat_col (LPX * lp, int j, int ind[], double val[]);
#define lpx_create_index _glp_lpx_create_index
  void lpx_create_index (LPX * lp);
#define lpx_find_row _glp_lpx_find_row
  int lpx_find_row (LPX * lp, const char *name);
#define lpx_find_col _glp_lpx_find_col
  int lpx_find_col (LPX * lp, const char *name);
#define lpx_delete_index _glp_lpx_delete_index
  void lpx_delete_index (LPX * lp);
#define lpx_scale_prob _glp_lpx_scale_prob
  void lpx_scale_prob (LPX * lp);
#define lpx_unscale_prob _glp_lpx_unscale_prob
  void lpx_unscale_prob (LPX * lp);
#define lpx_set_row_stat _glp_lpx_set_row_stat
  void lpx_set_row_stat (LPX * lp, int i, int stat);
#define lpx_set_col_stat _glp_lpx_set_col_stat
  void lpx_set_col_stat (LPX * lp, int j, int stat);
#define lpx_std_basis _glp_lpx_std_basis
  void lpx_std_basis (LPX * lp);
#define lpx_adv_basis _glp_lpx_adv_basis
  void lpx_adv_basis (LPX * lp);
#define lpx_cpx_basis _glp_lpx_cpx_basis
  void lpx_cpx_basis (LPX * lp);
#define lpx_simplex _glp_lpx_simplex
  int lpx_simplex (LPX * lp);
#define lpx_exact _glp_lpx_exact
  int lpx_exact (LPX * lp);
#define lpx_get_status _glp_lpx_get_status
  int lpx_get_status (LPX * lp);
#define lpx_get_prim_stat _glp_lpx_get_prim_stat
  int lpx_get_prim_stat (LPX * lp);
#define lpx_get_dual_stat _glp_lpx_get_dual_stat
  int lpx_get_dual_stat (LPX * lp);
#define lpx_get_obj_val _glp_lpx_get_obj_val
  double lpx_get_obj_val (LPX * lp);
#define lpx_get_row_stat _glp_lpx_get_row_stat
  int lpx_get_row_stat (LPX * lp, int i);
#define lpx_get_row_prim _glp_lpx_get_row_prim
  double lpx_get_row_prim (LPX * lp, int i);
#define lpx_get_row_dual _glp_lpx_get_row_dual
  double lpx_get_row_dual (LPX * lp, int i);
#define lpx_get_row_info _glp_lpx_get_row_info
  void lpx_get_row_info (LPX * lp, int i, int *tagx, double *vx, double *dx);
#define lpx_get_col_stat _glp_lpx_get_col_stat
  int lpx_get_col_stat (LPX * lp, int j);
#define lpx_get_col_prim _glp_lpx_get_col_prim
  double lpx_get_col_prim (LPX * lp, int j);
#define lpx_get_col_dual _glp_lpx_get_col_dual
  double lpx_get_col_dual (glp_prob * lp, int j);
#define lpx_get_col_info _glp_lpx_get_col_info
  void lpx_get_col_info (LPX * lp, int j, int *tagx, double *vx, double *dx);
#define lpx_get_ray_info _glp_lpx_get_ray_info
  int lpx_get_ray_info (LPX * lp);
#define lpx_check_kkt _glp_lpx_check_kkt
  void lpx_check_kkt (LPX * lp, int scaled, LPXKKT * kkt);
#define lpx_warm_up _glp_lpx_warm_up
  int lpx_warm_up (LPX * lp);
#define lpx_eval_tab_row _glp_lpx_eval_tab_row
  int lpx_eval_tab_row (LPX * lp, int k, int ind[], double val[]);
#define lpx_eval_tab_col _glp_lpx_eval_tab_col
  int lpx_eval_tab_col (LPX * lp, int k, int ind[], double val[]);
#define lpx_transform_row _glp_lpx_transform_row
  int lpx_transform_row (LPX * lp, int len, int ind[], double val[]);
#define lpx_transform_col _glp_lpx_transform_col
  int lpx_transform_col (LPX * lp, int len, int ind[], double val[]);
#define lpx_prim_ratio_test _glp_lpx_prim_ratio_test
  int lpx_prim_ratio_test (LPX * lp, int len, const int ind[],
                           const double val[], int how, double tol);
#define lpx_dual_ratio_test _glp_lpx_dual_ratio_test
  int lpx_dual_ratio_test (LPX * lp, int len, const int ind[],
                           const double val[], int how, double tol);
#define lpx_interior _glp_lpx_interior
  int lpx_interior (LPX * lp);
#define lpx_ipt_status _glp_lpx_ipt_status
  int lpx_ipt_status (LPX * lp);
#define lpx_ipt_obj_val _glp_lpx_ipt_obj_val
  double lpx_ipt_obj_val (LPX * lp);
#define lpx_ipt_row_prim _glp_lpx_ipt_row_prim
  double lpx_ipt_row_prim (LPX * lp, int i);
#define lpx_ipt_row_dual _glp_lpx_ipt_row_dual
  double lpx_ipt_row_dual (LPX * lp, int i);
#define lpx_ipt_col_prim _glp_lpx_ipt_col_prim
  double lpx_ipt_col_prim (LPX * lp, int j);
#define lpx_ipt_col_dual _glp_lpx_ipt_col_dual
  double lpx_ipt_col_dual (LPX * lp, int j);
#define lpx_set_class _glp_lpx_set_class
  void lpx_set_class (LPX * lp, int klass);
#define lpx_get_class _glp_lpx_get_class
  int lpx_get_class (LPX * lp);
#define lpx_set_col_kind _glp_lpx_set_col_kind
  void lpx_set_col_kind (LPX * lp, int j, int kind);
#define lpx_get_col_kind _glp_lpx_get_col_kind
  int lpx_get_col_kind (LPX * lp, int j);
#define lpx_get_num_int _glp_lpx_get_num_int
  int lpx_get_num_int (LPX * lp);
#define lpx_get_num_bin _glp_lpx_get_num_bin
  int lpx_get_num_bin (LPX * lp);
#define lpx_integer _glp_lpx_integer
  int lpx_integer (LPX * lp);
#define lpx_intopt _glp_lpx_intopt
  int lpx_intopt (LPX * lp);
#define lpx_mip_status _glp_lpx_mip_status
  int lpx_mip_status (LPX * lp);
#define lpx_mip_obj_val _glp_lpx_mip_obj_val
  double lpx_mip_obj_val (LPX * lp);
#define lpx_mip_row_val _glp_lpx_mip_row_val
  double lpx_mip_row_val (LPX * lp, int i);
#define lpx_mip_col_val _glp_lpx_mip_col_val
  double lpx_mip_col_val (LPX * lp, int j);
#define lpx_check_int _glp_lpx_check_int
  void lpx_check_int (LPX * lp, LPXKKT * kkt);
#define lpx_reset_parms _glp_lpx_reset_parms
  void lpx_reset_parms (LPX * lp);
#define lpx_set_int_parm _glp_lpx_set_int_parm
  void lpx_set_int_parm (LPX * lp, int parm, int val);
#define lpx_get_int_parm _glp_lpx_get_int_parm
  int lpx_get_int_parm (LPX * lp, int parm);
#define lpx_set_real_parm _glp_lpx_set_real_parm
  void lpx_set_real_parm (LPX * lp, int parm, double val);
#define lpx_get_real_parm _glp_lpx_get_real_parm
  double lpx_get_real_parm (LPX * lp, int parm);
#define lpx_read_mps _glp_lpx_read_mps
  LPX *lpx_read_mps (const char *fname);
#define lpx_write_mps _glp_lpx_write_mps
  int lpx_write_mps (LPX * lp, const char *fname);
#define lpx_read_bas _glp_lpx_read_bas
  int lpx_read_bas (LPX * lp, const char *fname);
#define lpx_write_bas _glp_lpx_write_bas
  int lpx_write_bas (LPX * lp, const char *fname);
#define lpx_read_freemps _glp_lpx_read_freemps
  LPX *lpx_read_freemps (const char *fname);
#define lpx_write_freemps _glp_lpx_write_freemps
  int lpx_write_freemps (LPX * lp, const char *fname);
#define lpx_read_cpxlp _glp_lpx_read_cpxlp
  LPX *lpx_read_cpxlp (const char *fname);
#define lpx_write_cpxlp _glp_lpx_write_cpxlp
  int lpx_write_cpxlp (LPX * lp, const char *fname);
#define lpx_read_model _glp_lpx_read_model
  LPX *lpx_read_model (const char *model, const char *data,
                       const char *output);
#define lpx_print_prob _glp_lpx_print_prob
  int lpx_print_prob (LPX * lp, const char *fname);
#define lpx_print_sol _glp_lpx_print_sol
  int lpx_print_sol (LPX * lp, const char *fname);
#define lpx_print_sens_bnds _glp_lpx_print_sens_bnds
  int lpx_print_sens_bnds (LPX * lp, const char *fname);
#define lpx_print_ips _glp_lpx_print_ips
  int lpx_print_ips (LPX * lp, const char *fname);
#define lpx_print_mip _glp_lpx_print_mip
  int lpx_print_mip (LPX * lp, const char *fname);
#define lpx_is_b_avail _glp_lpx_is_b_avail
  int lpx_is_b_avail (LPX * lp);
#define lpx_write_pb _glp_lpx_write_pb
  int lpx_write_pb (LPX * lp, const char *fname, int normalized,
                    int binarize);
#define lpx_main _glp_lpx_main
  int lpx_main (int argc, const char *argv[]);
#ifdef __cplusplus
}
#endif

#endif                          /* _GLPK_H */
