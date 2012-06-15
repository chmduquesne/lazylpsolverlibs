#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>

/*
 * returns true if the environment variable LAZYLPSOLVERLIBS_DEBUG is set
 * to "on", 0 otherwise
 */
int debug_enabled() {
    const char * LAZYLPSOLVERLIBS_DEBUG;
    LAZYLPSOLVERLIBS_DEBUG = getenv("LAZYLPSOLVERLIBS_DEBUG");
    if (LAZYLPSOLVERLIBS_DEBUG != NULL)
        if (strncmp(LAZYLPSOLVERLIBS_DEBUG, "on", 3) == 0)
            return 1;
    return 0;
}

/* handle to the library */
GModule *module = NULL;

/* searches and loads the actual library */
int load_module(){
    char *path;
    int debug;
    debug = debug_enabled();
    /* environment variable */
    char *LAZYLPSOLVERLIBS_GLPK_LIB;
    LAZYLPSOLVERLIBS_GLPK_LIB = getenv("LAZYLPSOLVERLIBS_GLPK_LIB");
    if (!module) {
        if (debug) fprintf (stderr, "lazylpsolverlibs: attempting to load library from %s\n", "/usr/lib/libglpk.so");
        module = g_module_open("/usr/lib/libglpk.so", G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
    }
    if (LAZYLPSOLVERLIBS_GLPK_LIB != NULL) {
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: attempting to load library from %s\n", LAZYLPSOLVERLIBS_GLPK_LIB);
            module = g_module_open(LAZYLPSOLVERLIBS_GLPK_LIB, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        }
    }
    if (!module) {
#ifdef _WIN32
        path = g_module_build_path(NULL, "glpk.dll");
#else
        path = g_module_build_path(NULL, "glpk");
#endif
        if (debug) fprintf (stderr, "lazylpsolverlibs: attempting to load library from %s\n", path);
        module = g_module_open(path, G_MODULE_BIND_LAZY|G_MODULE_BIND_LOCAL);
        g_free(path);
    }
    return (module != NULL);
}

/* imported functions */

glp_prob *(*__symbolic_glp_create_prob) (void) = NULL;
void (*__symbolic_glp_set_prob_name) (glp_prob * P, const char *name) = NULL;
void (*__symbolic_glp_set_obj_name) (glp_prob * P, const char *name) = NULL;
void (*__symbolic_glp_set_obj_dir) (glp_prob * P, int dir) = NULL;
int (*__symbolic_glp_add_rows) (glp_prob * P, int nrs) = NULL;
int (*__symbolic_glp_add_cols) (glp_prob * P, int ncs) = NULL;
void (*__symbolic_glp_set_row_name) (glp_prob * P, int i, const char *name) = NULL;
void (*__symbolic_glp_set_col_name) (glp_prob * P, int j, const char *name) = NULL;
void (*__symbolic_glp_set_row_bnds) (glp_prob * P, int i, int type, double lb, double ub) = NULL;
void (*__symbolic_glp_set_col_bnds) (glp_prob * P, int j, int type, double lb, double ub) = NULL;
void (*__symbolic_glp_set_obj_coef) (glp_prob * P, int j, double coef) = NULL;
void (*__symbolic_glp_set_mat_row) (glp_prob * P, int i, int len, const int ind[], const double val[]) = NULL;
void (*__symbolic_glp_set_mat_col) (glp_prob * P, int j, int len, const int ind[], const double val[]) = NULL;
void (*__symbolic_glp_load_matrix) (glp_prob * P, int ne, const int ia[], const int ja[], const double ar[]) = NULL;
int (*__symbolic_glp_check_dup) (int m, int n, int ne, const int ia[], const int ja[]) = NULL;
void (*__symbolic_glp_sort_matrix) (glp_prob * P) = NULL;
void (*__symbolic_glp_del_rows) (glp_prob * P, int nrs, const int num[]) = NULL;
void (*__symbolic_glp_del_cols) (glp_prob * P, int ncs, const int num[]) = NULL;
void (*__symbolic_glp_copy_prob) (glp_prob * dest, glp_prob * prob, int names) = NULL;
void (*__symbolic_glp_erase_prob) (glp_prob * P) = NULL;
void (*__symbolic_glp_delete_prob) (glp_prob * P) = NULL;
const char *(*__symbolic_glp_get_prob_name) (glp_prob * P) = NULL;
const char *(*__symbolic_glp_get_obj_name) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_obj_dir) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_num_rows) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_num_cols) (glp_prob * P) = NULL;
const char *(*__symbolic_glp_get_row_name) (glp_prob * P, int i) = NULL;
const char *(*__symbolic_glp_get_col_name) (glp_prob * P, int j) = NULL;
int (*__symbolic_glp_get_row_type) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_get_row_lb) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_get_row_ub) (glp_prob * P, int i) = NULL;
int (*__symbolic_glp_get_col_type) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_get_col_lb) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_get_col_ub) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_get_obj_coef) (glp_prob * P, int j) = NULL;
int (*__symbolic_glp_get_num_nz) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_mat_row) (glp_prob * P, int i, int ind[], double val[]) = NULL;
int (*__symbolic_glp_get_mat_col) (glp_prob * P, int j, int ind[], double val[]) = NULL;
void (*__symbolic_glp_create_index) (glp_prob * P) = NULL;
int (*__symbolic_glp_find_row) (glp_prob * P, const char *name) = NULL;
int (*__symbolic_glp_find_col) (glp_prob * P, const char *name) = NULL;
void (*__symbolic_glp_delete_index) (glp_prob * P) = NULL;
void (*__symbolic_glp_set_rii) (glp_prob * P, int i, double rii) = NULL;
void (*__symbolic_glp_set_sjj) (glp_prob * P, int j, double sjj) = NULL;
double (*__symbolic_glp_get_rii) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_get_sjj) (glp_prob * P, int j) = NULL;
void (*__symbolic_glp_scale_prob) (glp_prob * P, int flags) = NULL;
void (*__symbolic_glp_unscale_prob) (glp_prob * P) = NULL;
void (*__symbolic_glp_set_row_stat) (glp_prob * P, int i, int stat) = NULL;
void (*__symbolic_glp_set_col_stat) (glp_prob * P, int j, int stat) = NULL;
void (*__symbolic_glp_std_basis) (glp_prob * P) = NULL;
void (*__symbolic_glp_adv_basis) (glp_prob * P, int flags) = NULL;
void (*__symbolic_glp_cpx_basis) (glp_prob * P) = NULL;
int (*__symbolic_glp_simplex) (glp_prob * P, const glp_smcp * parm) = NULL;
int (*__symbolic_glp_exact) (glp_prob * P, const glp_smcp * parm) = NULL;
void (*__symbolic_glp_init_smcp) (glp_smcp * parm) = NULL;
int (*__symbolic_glp_get_status) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_prim_stat) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_dual_stat) (glp_prob * P) = NULL;
double (*__symbolic_glp_get_obj_val) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_row_stat) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_get_row_prim) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_get_row_dual) (glp_prob * P, int i) = NULL;
int (*__symbolic_glp_get_col_stat) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_get_col_prim) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_get_col_dual) (glp_prob * P, int j) = NULL;
int (*__symbolic_glp_get_unbnd_ray) (glp_prob * P) = NULL;
int (*__symbolic_glp_interior) (glp_prob * P, const glp_iptcp * parm) = NULL;
void (*__symbolic_glp_init_iptcp) (glp_iptcp * parm) = NULL;
int (*__symbolic_glp_ipt_status) (glp_prob * P) = NULL;
double (*__symbolic_glp_ipt_obj_val) (glp_prob * P) = NULL;
double (*__symbolic_glp_ipt_row_prim) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_ipt_row_dual) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_ipt_col_prim) (glp_prob * P, int j) = NULL;
double (*__symbolic_glp_ipt_col_dual) (glp_prob * P, int j) = NULL;
void (*__symbolic_glp_set_col_kind) (glp_prob * P, int j, int kind) = NULL;
int (*__symbolic_glp_get_col_kind) (glp_prob * P, int j) = NULL;
int (*__symbolic_glp_get_num_int) (glp_prob * P) = NULL;
int (*__symbolic_glp_get_num_bin) (glp_prob * P) = NULL;
int (*__symbolic_glp_intopt) (glp_prob * P, const glp_iocp * parm) = NULL;
void (*__symbolic_glp_init_iocp) (glp_iocp * parm) = NULL;
int (*__symbolic_glp_mip_status) (glp_prob * P) = NULL;
double (*__symbolic_glp_mip_obj_val) (glp_prob * P) = NULL;
double (*__symbolic_glp_mip_row_val) (glp_prob * P, int i) = NULL;
double (*__symbolic_glp_mip_col_val) (glp_prob * P, int j) = NULL;
int (*__symbolic_glp_print_sol) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_read_sol) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_write_sol) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_print_ranges) (glp_prob * P, int len, const int list[], int flags, const char *fname) = NULL;
int (*__symbolic_glp_print_ipt) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_read_ipt) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_write_ipt) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_print_mip) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_read_mip) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_write_mip) (glp_prob * P, const char *fname) = NULL;
int (*__symbolic_glp_bf_exists) (glp_prob * P) = NULL;
int (*__symbolic_glp_factorize) (glp_prob * P) = NULL;
int (*__symbolic_glp_bf_updated) (glp_prob * P) = NULL;
void (*__symbolic_glp_get_bfcp) (glp_prob * P, glp_bfcp * parm) = NULL;
void (*__symbolic_glp_set_bfcp) (glp_prob * P, const glp_bfcp * parm) = NULL;
int (*__symbolic_glp_get_bhead) (glp_prob * P, int k) = NULL;
int (*__symbolic_glp_get_row_bind) (glp_prob * P, int i) = NULL;
int (*__symbolic_glp_get_col_bind) (glp_prob * P, int j) = NULL;
void (*__symbolic_glp_ftran) (glp_prob * P, double x[]) = NULL;
void (*__symbolic_glp_btran) (glp_prob * P, double x[]) = NULL;
int (*__symbolic_glp_warm_up) (glp_prob * P) = NULL;
int (*__symbolic_glp_eval_tab_row) (glp_prob * P, int k, int ind[], double val[]) = NULL;
int (*__symbolic_glp_eval_tab_col) (glp_prob * P, int k, int ind[], double val[]) = NULL;
int (*__symbolic_glp_transform_row) (glp_prob * P, int len, int ind[], double val[]) = NULL;
int (*__symbolic_glp_transform_col) (glp_prob * P, int len, int ind[], double val[]) = NULL;
int (*__symbolic_glp_prim_rtest) (glp_prob * P, int len, const int ind[], const double val[], int dir, double eps) = NULL;
int (*__symbolic_glp_dual_rtest) (glp_prob * P, int len, const int ind[], const double val[], int dir, double eps) = NULL;
void (*__symbolic_glp_analyze_bound) (glp_prob * P, int k, double *value1, int *var1, double *value2, int *var2) = NULL;
void (*__symbolic_glp_analyze_coef) (glp_prob * P, int k, double *coef1, int *var1, double *value1, double *coef2, int *var2, double *value2) = NULL;
int (*__symbolic_glp_ios_reason) (glp_tree * T) = NULL;
glp_prob *(*__symbolic_glp_ios_get_prob) (glp_tree * T) = NULL;
void (*__symbolic_glp_ios_tree_size) (glp_tree * T, int *a_cnt, int *n_cnt, int *t_cnt) = NULL;
int (*__symbolic_glp_ios_curr_node) (glp_tree * T) = NULL;
int (*__symbolic_glp_ios_next_node) (glp_tree * T, int p) = NULL;
int (*__symbolic_glp_ios_prev_node) (glp_tree * T, int p) = NULL;
int (*__symbolic_glp_ios_up_node) (glp_tree * T, int p) = NULL;
int (*__symbolic_glp_ios_node_level) (glp_tree * T, int p) = NULL;
double (*__symbolic_glp_ios_node_bound) (glp_tree * T, int p) = NULL;
int (*__symbolic_glp_ios_best_node) (glp_tree * T) = NULL;
double (*__symbolic_glp_ios_mip_gap) (glp_tree * T) = NULL;
void *(*__symbolic_glp_ios_node_data) (glp_tree * T, int p) = NULL;
void (*__symbolic_glp_ios_row_attr) (glp_tree * T, int i, glp_attr * attr) = NULL;
int (*__symbolic_glp_ios_pool_size) (glp_tree * T) = NULL;
int (*__symbolic_glp_ios_add_row) (glp_tree * T, const char *name, int klass, int flags, int len, const int ind[], const double val[], int type, double rhs) = NULL;
void (*__symbolic_glp_ios_del_row) (glp_tree * T, int i) = NULL;
void (*__symbolic_glp_ios_clear_pool) (glp_tree * T) = NULL;
int (*__symbolic_glp_ios_can_branch) (glp_tree * T, int j) = NULL;
void (*__symbolic_glp_ios_branch_upon) (glp_tree * T, int j, int sel) = NULL;
void (*__symbolic_glp_ios_select_node) (glp_tree * T, int p) = NULL;
int (*__symbolic_glp_ios_heur_sol) (glp_tree * T, const double x[]) = NULL;
void (*__symbolic_glp_ios_terminate) (glp_tree * T) = NULL;
void (*__symbolic_glp_init_mpscp) (glp_mpscp * parm) = NULL;
int (*__symbolic_glp_read_mps) (glp_prob * P, int fmt, const glp_mpscp * parm, const char *fname) = NULL;
int (*__symbolic_glp_write_mps) (glp_prob * P, int fmt, const glp_mpscp * parm, const char *fname) = NULL;
void (*__symbolic_glp_init_cpxcp) (glp_cpxcp * parm) = NULL;
int (*__symbolic_glp_read_lp) (glp_prob * P, const glp_cpxcp * parm, const char *fname) = NULL;
int (*__symbolic_glp_write_lp) (glp_prob * P, const glp_cpxcp * parm, const char *fname) = NULL;
int (*__symbolic_glp_read_prob) (glp_prob * P, int flags, const char *fname) = NULL;
int (*__symbolic_glp_write_prob) (glp_prob * P, int flags, const char *fname) = NULL;
glp_tran *(*__symbolic_glp_mpl_alloc_wksp) (void) = NULL;
int (*__symbolic_glp_mpl_read_model) (glp_tran * tran, const char *fname, int skip) = NULL;
int (*__symbolic_glp_mpl_read_data) (glp_tran * tran, const char *fname) = NULL;
int (*__symbolic_glp_mpl_generate) (glp_tran * tran, const char *fname) = NULL;
void (*__symbolic_glp_mpl_build_prob) (glp_tran * tran, glp_prob * prob) = NULL;
int (*__symbolic_glp_mpl_postsolve) (glp_tran * tran, glp_prob * prob, int sol) = NULL;
void (*__symbolic_glp_mpl_free_wksp) (glp_tran * tran) = NULL;
int (*__symbolic_glp_main) (int argc, const char *argv[]) = NULL;
int (*__symbolic_glp_init_env) (void) = NULL;
const char *(*__symbolic_glp_version) (void) = NULL;
int (*__symbolic_glp_free_env) (void) = NULL;
void (*__symbolic_glp_printf) (const char *fmt, ...) = NULL;
void (*__symbolic_glp_vprintf) (const char *fmt, va_list arg) = NULL;
int (*__symbolic_glp_term_out) (int flag) = NULL;
void (*__symbolic_glp_term_hook) (int (*func) (void *info, const char *s), void *info) = NULL;
int (*__symbolic_glp_open_tee) (const char *fname) = NULL;
int (*__symbolic_glp_close_tee) (void) = NULL;
_glp_error (*__symbolic_glp_error_) (const char *file, int line) = NULL;
void (*__symbolic_glp_assert_) (const char *expr, const char *file, int line) = NULL;
void (*__symbolic_glp_error_hook) (void (*func) (void *info), void *info) = NULL;
void *(*__symbolic_glp_malloc) (int size) = NULL;
void *(*__symbolic_glp_calloc) (int n, int size) = NULL;
void (*__symbolic_glp_free) (void *ptr) = NULL;
void (*__symbolic_glp_mem_limit) (int limit) = NULL;
void (*__symbolic_glp_mem_usage) (int *count, int *cpeak, glp_long * total, glp_long * tpeak) = NULL;
glp_long (*__symbolic_glp_time) (void) = NULL;
double (*__symbolic_glp_difftime) (glp_long t1, glp_long t0) = NULL;
glp_data *(*__symbolic_glp_sdf_open_file) (const char *fname) = NULL;
void (*__symbolic_glp_sdf_set_jump) (glp_data * data, void *jump) = NULL;
void (*__symbolic_glp_sdf_error) (glp_data * data, const char *fmt, ...) = NULL;
void (*__symbolic_glp_sdf_warning) (glp_data * data, const char *fmt, ...) = NULL;
int (*__symbolic_glp_sdf_read_int) (glp_data * data) = NULL;
double (*__symbolic_glp_sdf_read_num) (glp_data * data) = NULL;
const char *(*__symbolic_glp_sdf_read_item) (glp_data * data) = NULL;
const char *(*__symbolic_glp_sdf_read_text) (glp_data * data) = NULL;
int (*__symbolic_glp_sdf_line) (glp_data * data) = NULL;
void (*__symbolic_glp_sdf_close_file) (glp_data * data) = NULL;
glp_graph *(*__symbolic_glp_create_graph) (int v_size, int a_size) = NULL;
void (*__symbolic_glp_set_graph_name) (glp_graph * G, const char *name) = NULL;
int (*__symbolic_glp_add_vertices) (glp_graph * G, int nadd) = NULL;
void (*__symbolic_glp_set_vertex_name) (glp_graph * G, int i, const char *name) = NULL;
glp_arc *(*__symbolic_glp_add_arc) (glp_graph * G, int i, int j) = NULL;
void (*__symbolic_glp_del_vertices) (glp_graph * G, int ndel, const int num[]) = NULL;
void (*__symbolic_glp_del_arc) (glp_graph * G, glp_arc * a) = NULL;
void (*__symbolic_glp_erase_graph) (glp_graph * G, int v_size, int a_size) = NULL;
void (*__symbolic_glp_delete_graph) (glp_graph * G) = NULL;
void (*__symbolic_glp_create_v_index) (glp_graph * G) = NULL;
int (*__symbolic_glp_find_vertex) (glp_graph * G, const char *name) = NULL;
void (*__symbolic_glp_delete_v_index) (glp_graph * G) = NULL;
int (*__symbolic_glp_read_graph) (glp_graph * G, const char *fname) = NULL;
int (*__symbolic_glp_write_graph) (glp_graph * G, const char *fname) = NULL;
void (*__symbolic_glp_mincost_lp) (glp_prob * P, glp_graph * G, int names, int v_rhs, int a_low, int a_cap, int a_cost) = NULL;
int (*__symbolic_glp_mincost_okalg) (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, double *sol, int a_x, int v_pi) = NULL;
void (*__symbolic_glp_maxflow_lp) (glp_prob * P, glp_graph * G, int names, int s, int t, int a_cap) = NULL;
int (*__symbolic_glp_maxflow_ffalg) (glp_graph * G, int s, int t, int a_cap, double *sol, int a_x, int v_cut) = NULL;
int (*__symbolic_glp_check_asnprob) (glp_graph * G, int v_set) = NULL;
int (*__symbolic_glp_asnprob_lp) (glp_prob * P, int form, glp_graph * G, int names, int v_set, int a_cost) = NULL;
int (*__symbolic_glp_asnprob_okalg) (int form, glp_graph * G, int v_set, int a_cost, double *sol, int a_x) = NULL;
int (*__symbolic_glp_asnprob_hall) (glp_graph * G, int v_set, int a_x) = NULL;
int (*__symbolic_glp_read_mincost) (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, const char *fname) = NULL;
int (*__symbolic_glp_write_mincost) (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, const char *fname) = NULL;
int (*__symbolic_glp_read_maxflow) (glp_graph * G, int *s, int *t, int a_cap, const char *fname) = NULL;
int (*__symbolic_glp_write_maxflow) (glp_graph * G, int s, int t, int a_cap, const char *fname) = NULL;
int (*__symbolic_glp_read_asnprob) (glp_graph * G, int v_set, int a_cost, const char *fname) = NULL;
int (*__symbolic_glp_write_asnprob) (glp_graph * G, int v_set, int a_cost, const char *fname) = NULL;
int (*__symbolic_glp_read_ccdata) (glp_graph * G, int v_wgt, const char *fname) = NULL;
int (*__symbolic_glp_write_ccdata) (glp_graph * G, int v_wgt, const char *fname) = NULL;
int (*__symbolic_glp_netgen) (glp_graph * G, int v_rhs, int a_cap, int a_cost, const int parm[1 + 15]) = NULL;
int (*__symbolic_glp_gridgen) (glp_graph * G, int v_rhs, int a_cap, int a_cost, const int parm[1 + 14]) = NULL;
int (*__symbolic_glp_rmfgen) (glp_graph * G, int *s, int *t, int a_cap, const int parm[1 + 5]) = NULL;
int (*__symbolic_glp_weak_comp) (glp_graph * G, int v_num) = NULL;
int (*__symbolic_glp_strong_comp) (glp_graph * G, int v_num) = NULL;
int (*__symbolic_glp_top_sort) (glp_graph * G, int v_num) = NULL;
int (*__symbolic_glp_wclique_exact) (glp_graph * G, int v_wgt, double *sol, int v_set) = NULL;
glp_prob *(*__symbolic__glp_lpx_create_prob) (void) = NULL;
void (*__symbolic__glp_lpx_set_prob_name) (glp_prob * lp, const char *name) = NULL;
void (*__symbolic__glp_lpx_set_obj_name) (glp_prob * lp, const char *name) = NULL;
void (*__symbolic__glp_lpx_set_obj_dir) (glp_prob * lp, int dir) = NULL;
int (*__symbolic__glp_lpx_add_rows) (glp_prob * lp, int nrs) = NULL;
int (*__symbolic__glp_lpx_add_cols) (glp_prob * lp, int ncs) = NULL;
void (*__symbolic__glp_lpx_set_row_name) (glp_prob * lp, int i, const char *name) = NULL;
void (*__symbolic__glp_lpx_set_col_name) (glp_prob * lp, int j, const char *name) = NULL;
void (*__symbolic__glp_lpx_set_row_bnds) (glp_prob * lp, int i, int type, double lb, double ub) = NULL;
void (*__symbolic__glp_lpx_set_col_bnds) (glp_prob * lp, int j, int type, double lb, double ub) = NULL;
void (*__symbolic__glp_lpx_set_obj_coef) (glp_prob * lp, int j, double coef) = NULL;
void (*__symbolic__glp_lpx_set_mat_row) (glp_prob * lp, int i, int len, const int ind[], const double val[]) = NULL;
void (*__symbolic__glp_lpx_set_mat_col) (glp_prob * lp, int j, int len, const int ind[], const double val[]) = NULL;
void (*__symbolic__glp_lpx_load_matrix) (glp_prob * lp, int ne, const int ia[], const int ja[], const double ar[]) = NULL;
void (*__symbolic__glp_lpx_del_rows) (glp_prob * lp, int nrs, const int num[]) = NULL;
void (*__symbolic__glp_lpx_del_cols) (glp_prob * lp, int ncs, const int num[]) = NULL;
void (*__symbolic__glp_lpx_delete_prob) (glp_prob * lp) = NULL;
const char *(*__symbolic__glp_lpx_get_prob_name) (glp_prob * lp) = NULL;
const char *(*__symbolic__glp_lpx_get_obj_name) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_obj_dir) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_num_rows) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_num_cols) (glp_prob * lp) = NULL;
const char *(*__symbolic__glp_lpx_get_row_name) (glp_prob * lp, int i) = NULL;
const char *(*__symbolic__glp_lpx_get_col_name) (glp_prob * lp, int j) = NULL;
int (*__symbolic__glp_lpx_get_row_type) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_get_row_lb) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_get_row_ub) (glp_prob * lp, int i) = NULL;
void (*__symbolic__glp_lpx_get_row_bnds) (glp_prob * lp, int i, int *typx, double *lb, double *ub) = NULL;
int (*__symbolic__glp_lpx_get_col_type) (glp_prob * lp, int j) = NULL;
double (*__symbolic__glp_lpx_get_col_lb) (glp_prob * lp, int j) = NULL;
double (*__symbolic__glp_lpx_get_col_ub) (glp_prob * lp, int j) = NULL;
void (*__symbolic__glp_lpx_get_col_bnds) (glp_prob * lp, int j, int *typx, double *lb, double *ub) = NULL;
double (*__symbolic__glp_lpx_get_obj_coef) (glp_prob * lp, int j) = NULL;
int (*__symbolic__glp_lpx_get_num_nz) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_mat_row) (glp_prob * lp, int i, int ind[], double val[]) = NULL;
int (*__symbolic__glp_lpx_get_mat_col) (glp_prob * lp, int j, int ind[], double val[]) = NULL;
void (*__symbolic__glp_lpx_create_index) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_find_row) (glp_prob * lp, const char *name) = NULL;
int (*__symbolic__glp_lpx_find_col) (glp_prob * lp, const char *name) = NULL;
void (*__symbolic__glp_lpx_delete_index) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_scale_prob) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_unscale_prob) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_set_row_stat) (glp_prob * lp, int i, int stat) = NULL;
void (*__symbolic__glp_lpx_set_col_stat) (glp_prob * lp, int j, int stat) = NULL;
void (*__symbolic__glp_lpx_std_basis) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_adv_basis) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_cpx_basis) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_simplex) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_exact) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_status) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_prim_stat) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_dual_stat) (glp_prob * lp) = NULL;
double (*__symbolic__glp_lpx_get_obj_val) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_row_stat) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_get_row_prim) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_get_row_dual) (glp_prob * lp, int i) = NULL;
void (*__symbolic__glp_lpx_get_row_info) (glp_prob * lp, int i, int *tagx, double *vx, double *dx) = NULL;
int (*__symbolic__glp_lpx_get_col_stat) (glp_prob * lp, int j) = NULL;
double (*__symbolic__glp_lpx_get_col_prim) (glp_prob * lp, int j) = NULL;
double (*__symbolic__glp_lpx_get_col_dual) (glp_prob * lp, int j) = NULL;
void (*__symbolic__glp_lpx_get_col_info) (glp_prob * lp, int j, int *tagx, double *vx, double *dx) = NULL;
int (*__symbolic__glp_lpx_get_ray_info) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_check_kkt) (glp_prob * lp, int scaled, LPXKKT * kkt) = NULL;
int (*__symbolic__glp_lpx_warm_up) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_eval_tab_row) (glp_prob * lp, int k, int ind[], double val[]) = NULL;
int (*__symbolic__glp_lpx_eval_tab_col) (glp_prob * lp, int k, int ind[], double val[]) = NULL;
int (*__symbolic__glp_lpx_transform_row) (glp_prob * lp, int len, int ind[], double val[]) = NULL;
int (*__symbolic__glp_lpx_transform_col) (glp_prob * lp, int len, int ind[], double val[]) = NULL;
int (*__symbolic__glp_lpx_prim_ratio_test) (glp_prob * lp, int len, const int ind[], const double val[], int how, double tol) = NULL;
int (*__symbolic__glp_lpx_dual_ratio_test) (glp_prob * lp, int len, const int ind[], const double val[], int how, double tol) = NULL;
int (*__symbolic__glp_lpx_interior) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_ipt_status) (glp_prob * lp) = NULL;
double (*__symbolic__glp_lpx_ipt_obj_val) (glp_prob * lp) = NULL;
double (*__symbolic__glp_lpx_ipt_row_prim) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_ipt_row_dual) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_ipt_col_prim) (glp_prob * lp, int j) = NULL;
double (*__symbolic__glp_lpx_ipt_col_dual) (glp_prob * lp, int j) = NULL;
void (*__symbolic__glp_lpx_set_class) (glp_prob * lp, int klass) = NULL;
int (*__symbolic__glp_lpx_get_class) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_set_col_kind) (glp_prob * lp, int j, int kind) = NULL;
int (*__symbolic__glp_lpx_get_col_kind) (glp_prob * lp, int j) = NULL;
int (*__symbolic__glp_lpx_get_num_int) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_get_num_bin) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_integer) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_intopt) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_mip_status) (glp_prob * lp) = NULL;
double (*__symbolic__glp_lpx_mip_obj_val) (glp_prob * lp) = NULL;
double (*__symbolic__glp_lpx_mip_row_val) (glp_prob * lp, int i) = NULL;
double (*__symbolic__glp_lpx_mip_col_val) (glp_prob * lp, int j) = NULL;
void (*__symbolic__glp_lpx_check_int) (glp_prob * lp, LPXKKT * kkt) = NULL;
void (*__symbolic__glp_lpx_reset_parms) (glp_prob * lp) = NULL;
void (*__symbolic__glp_lpx_set_int_parm) (glp_prob * lp, int parm, int val) = NULL;
int (*__symbolic__glp_lpx_get_int_parm) (glp_prob * lp, int parm) = NULL;
void (*__symbolic__glp_lpx_set_real_parm) (glp_prob * lp, int parm, double val) = NULL;
double (*__symbolic__glp_lpx_get_real_parm) (glp_prob * lp, int parm) = NULL;
glp_prob *(*__symbolic__glp_lpx_read_mps) (const char *fname) = NULL;
int (*__symbolic__glp_lpx_write_mps) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_read_bas) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_write_bas) (glp_prob * lp, const char *fname) = NULL;
glp_prob *(*__symbolic__glp_lpx_read_freemps) (const char *fname) = NULL;
int (*__symbolic__glp_lpx_write_freemps) (glp_prob * lp, const char *fname) = NULL;
glp_prob *(*__symbolic__glp_lpx_read_cpxlp) (const char *fname) = NULL;
int (*__symbolic__glp_lpx_write_cpxlp) (glp_prob * lp, const char *fname) = NULL;
glp_prob *(*__symbolic__glp_lpx_read_model) (const char *model, const char *data, const char *output) = NULL;
int (*__symbolic__glp_lpx_print_prob) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_print_sol) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_print_sens_bnds) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_print_ips) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_print_mip) (glp_prob * lp, const char *fname) = NULL;
int (*__symbolic__glp_lpx_is_b_avail) (glp_prob * lp) = NULL;
int (*__symbolic__glp_lpx_write_pb) (glp_prob * lp, const char *fname, int normalized, int binarize) = NULL;
int (*__symbolic__glp_lpx_main) (int argc, const char *argv[]) = NULL;

/* hijacked functions */

glp_prob *glp_create_prob (void){
    int debug;
    if (!__symbolic_glp_create_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_create_prob", (gpointer *) &__symbolic_glp_create_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_create_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_create_prob.\n");
        }
    }
    return __symbolic_glp_create_prob();
}
void glp_set_prob_name (glp_prob * P, const char *name){
    int debug;
    if (!__symbolic_glp_set_prob_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_prob_name", (gpointer *) &__symbolic_glp_set_prob_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_prob_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_prob_name.\n");
        }
    }
    return __symbolic_glp_set_prob_name(P, name);
}
void glp_set_obj_name (glp_prob * P, const char *name){
    int debug;
    if (!__symbolic_glp_set_obj_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_obj_name", (gpointer *) &__symbolic_glp_set_obj_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_obj_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_obj_name.\n");
        }
    }
    return __symbolic_glp_set_obj_name(P, name);
}
void glp_set_obj_dir (glp_prob * P, int dir){
    int debug;
    if (!__symbolic_glp_set_obj_dir) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_obj_dir", (gpointer *) &__symbolic_glp_set_obj_dir)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_obj_dir could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_obj_dir.\n");
        }
    }
    return __symbolic_glp_set_obj_dir(P, dir);
}
int glp_add_rows (glp_prob * P, int nrs){
    int debug;
    if (!__symbolic_glp_add_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_add_rows", (gpointer *) &__symbolic_glp_add_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_add_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_add_rows.\n");
        }
    }
    return __symbolic_glp_add_rows(P, nrs);
}
int glp_add_cols (glp_prob * P, int ncs){
    int debug;
    if (!__symbolic_glp_add_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_add_cols", (gpointer *) &__symbolic_glp_add_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_add_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_add_cols.\n");
        }
    }
    return __symbolic_glp_add_cols(P, ncs);
}
void glp_set_row_name (glp_prob * P, int i, const char *name){
    int debug;
    if (!__symbolic_glp_set_row_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_row_name", (gpointer *) &__symbolic_glp_set_row_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_row_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_row_name.\n");
        }
    }
    return __symbolic_glp_set_row_name(P, i, name);
}
void glp_set_col_name (glp_prob * P, int j, const char *name){
    int debug;
    if (!__symbolic_glp_set_col_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_col_name", (gpointer *) &__symbolic_glp_set_col_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_col_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_col_name.\n");
        }
    }
    return __symbolic_glp_set_col_name(P, j, name);
}
void glp_set_row_bnds (glp_prob * P, int i, int type, double lb, double ub){
    int debug;
    if (!__symbolic_glp_set_row_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_row_bnds", (gpointer *) &__symbolic_glp_set_row_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_row_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_row_bnds.\n");
        }
    }
    return __symbolic_glp_set_row_bnds(P, i, type, lb, ub);
}
void glp_set_col_bnds (glp_prob * P, int j, int type, double lb, double ub){
    int debug;
    if (!__symbolic_glp_set_col_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_col_bnds", (gpointer *) &__symbolic_glp_set_col_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_col_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_col_bnds.\n");
        }
    }
    return __symbolic_glp_set_col_bnds(P, j, type, lb, ub);
}
void glp_set_obj_coef (glp_prob * P, int j, double coef){
    int debug;
    if (!__symbolic_glp_set_obj_coef) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_obj_coef", (gpointer *) &__symbolic_glp_set_obj_coef)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_obj_coef could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_obj_coef.\n");
        }
    }
    return __symbolic_glp_set_obj_coef(P, j, coef);
}
void glp_set_mat_row (glp_prob * P, int i, int len, const int ind[], const double val[]){
    int debug;
    if (!__symbolic_glp_set_mat_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_mat_row", (gpointer *) &__symbolic_glp_set_mat_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_mat_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_mat_row.\n");
        }
    }
    return __symbolic_glp_set_mat_row(P, i, len, ind, val);
}
void glp_set_mat_col (glp_prob * P, int j, int len, const int ind[], const double val[]){
    int debug;
    if (!__symbolic_glp_set_mat_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_mat_col", (gpointer *) &__symbolic_glp_set_mat_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_mat_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_mat_col.\n");
        }
    }
    return __symbolic_glp_set_mat_col(P, j, len, ind, val);
}
void glp_load_matrix (glp_prob * P, int ne, const int ia[], const int ja[], const double ar[]){
    int debug;
    if (!__symbolic_glp_load_matrix) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_load_matrix", (gpointer *) &__symbolic_glp_load_matrix)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_load_matrix could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_load_matrix.\n");
        }
    }
    return __symbolic_glp_load_matrix(P, ne, ia, ja, ar);
}
int glp_check_dup (int m, int n, int ne, const int ia[], const int ja[]){
    int debug;
    if (!__symbolic_glp_check_dup) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_check_dup", (gpointer *) &__symbolic_glp_check_dup)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_check_dup could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_check_dup.\n");
        }
    }
    return __symbolic_glp_check_dup(m, n, ne, ia, ja);
}
void glp_sort_matrix (glp_prob * P){
    int debug;
    if (!__symbolic_glp_sort_matrix) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sort_matrix", (gpointer *) &__symbolic_glp_sort_matrix)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sort_matrix could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sort_matrix.\n");
        }
    }
    return __symbolic_glp_sort_matrix(P);
}
void glp_del_rows (glp_prob * P, int nrs, const int num[]){
    int debug;
    if (!__symbolic_glp_del_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_del_rows", (gpointer *) &__symbolic_glp_del_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_del_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_del_rows.\n");
        }
    }
    return __symbolic_glp_del_rows(P, nrs, num);
}
void glp_del_cols (glp_prob * P, int ncs, const int num[]){
    int debug;
    if (!__symbolic_glp_del_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_del_cols", (gpointer *) &__symbolic_glp_del_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_del_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_del_cols.\n");
        }
    }
    return __symbolic_glp_del_cols(P, ncs, num);
}
void glp_copy_prob (glp_prob * dest, glp_prob * prob, int names){
    int debug;
    if (!__symbolic_glp_copy_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_copy_prob", (gpointer *) &__symbolic_glp_copy_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_copy_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_copy_prob.\n");
        }
    }
    return __symbolic_glp_copy_prob(dest, prob, names);
}
void glp_erase_prob (glp_prob * P){
    int debug;
    if (!__symbolic_glp_erase_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_erase_prob", (gpointer *) &__symbolic_glp_erase_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_erase_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_erase_prob.\n");
        }
    }
    return __symbolic_glp_erase_prob(P);
}
void glp_delete_prob (glp_prob * P){
    int debug;
    if (!__symbolic_glp_delete_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_delete_prob", (gpointer *) &__symbolic_glp_delete_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_delete_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_delete_prob.\n");
        }
    }
    return __symbolic_glp_delete_prob(P);
}
const char *glp_get_prob_name (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_prob_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_prob_name", (gpointer *) &__symbolic_glp_get_prob_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_prob_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_prob_name.\n");
        }
    }
    return __symbolic_glp_get_prob_name(P);
}
const char *glp_get_obj_name (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_obj_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_obj_name", (gpointer *) &__symbolic_glp_get_obj_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_obj_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_obj_name.\n");
        }
    }
    return __symbolic_glp_get_obj_name(P);
}
int glp_get_obj_dir (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_obj_dir) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_obj_dir", (gpointer *) &__symbolic_glp_get_obj_dir)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_obj_dir could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_obj_dir.\n");
        }
    }
    return __symbolic_glp_get_obj_dir(P);
}
int glp_get_num_rows (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_num_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_num_rows", (gpointer *) &__symbolic_glp_get_num_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_num_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_num_rows.\n");
        }
    }
    return __symbolic_glp_get_num_rows(P);
}
int glp_get_num_cols (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_num_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_num_cols", (gpointer *) &__symbolic_glp_get_num_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_num_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_num_cols.\n");
        }
    }
    return __symbolic_glp_get_num_cols(P);
}
const char *glp_get_row_name (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_name", (gpointer *) &__symbolic_glp_get_row_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_name.\n");
        }
    }
    return __symbolic_glp_get_row_name(P, i);
}
const char *glp_get_col_name (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_name", (gpointer *) &__symbolic_glp_get_col_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_name.\n");
        }
    }
    return __symbolic_glp_get_col_name(P, j);
}
int glp_get_row_type (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_type) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_type", (gpointer *) &__symbolic_glp_get_row_type)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_type could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_type.\n");
        }
    }
    return __symbolic_glp_get_row_type(P, i);
}
double glp_get_row_lb (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_lb) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_lb", (gpointer *) &__symbolic_glp_get_row_lb)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_lb could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_lb.\n");
        }
    }
    return __symbolic_glp_get_row_lb(P, i);
}
double glp_get_row_ub (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_ub) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_ub", (gpointer *) &__symbolic_glp_get_row_ub)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_ub could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_ub.\n");
        }
    }
    return __symbolic_glp_get_row_ub(P, i);
}
int glp_get_col_type (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_type) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_type", (gpointer *) &__symbolic_glp_get_col_type)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_type could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_type.\n");
        }
    }
    return __symbolic_glp_get_col_type(P, j);
}
double glp_get_col_lb (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_lb) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_lb", (gpointer *) &__symbolic_glp_get_col_lb)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_lb could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_lb.\n");
        }
    }
    return __symbolic_glp_get_col_lb(P, j);
}
double glp_get_col_ub (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_ub) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_ub", (gpointer *) &__symbolic_glp_get_col_ub)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_ub could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_ub.\n");
        }
    }
    return __symbolic_glp_get_col_ub(P, j);
}
double glp_get_obj_coef (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_obj_coef) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_obj_coef", (gpointer *) &__symbolic_glp_get_obj_coef)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_obj_coef could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_obj_coef.\n");
        }
    }
    return __symbolic_glp_get_obj_coef(P, j);
}
int glp_get_num_nz (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_num_nz) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_num_nz", (gpointer *) &__symbolic_glp_get_num_nz)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_num_nz could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_num_nz.\n");
        }
    }
    return __symbolic_glp_get_num_nz(P);
}
int glp_get_mat_row (glp_prob * P, int i, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_get_mat_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_mat_row", (gpointer *) &__symbolic_glp_get_mat_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_mat_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_mat_row.\n");
        }
    }
    return __symbolic_glp_get_mat_row(P, i, ind, val);
}
int glp_get_mat_col (glp_prob * P, int j, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_get_mat_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_mat_col", (gpointer *) &__symbolic_glp_get_mat_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_mat_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_mat_col.\n");
        }
    }
    return __symbolic_glp_get_mat_col(P, j, ind, val);
}
void glp_create_index (glp_prob * P){
    int debug;
    if (!__symbolic_glp_create_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_create_index", (gpointer *) &__symbolic_glp_create_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_create_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_create_index.\n");
        }
    }
    return __symbolic_glp_create_index(P);
}
int glp_find_row (glp_prob * P, const char *name){
    int debug;
    if (!__symbolic_glp_find_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_find_row", (gpointer *) &__symbolic_glp_find_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_find_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_find_row.\n");
        }
    }
    return __symbolic_glp_find_row(P, name);
}
int glp_find_col (glp_prob * P, const char *name){
    int debug;
    if (!__symbolic_glp_find_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_find_col", (gpointer *) &__symbolic_glp_find_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_find_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_find_col.\n");
        }
    }
    return __symbolic_glp_find_col(P, name);
}
void glp_delete_index (glp_prob * P){
    int debug;
    if (!__symbolic_glp_delete_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_delete_index", (gpointer *) &__symbolic_glp_delete_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_delete_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_delete_index.\n");
        }
    }
    return __symbolic_glp_delete_index(P);
}
void glp_set_rii (glp_prob * P, int i, double rii){
    int debug;
    if (!__symbolic_glp_set_rii) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_rii", (gpointer *) &__symbolic_glp_set_rii)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_rii could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_rii.\n");
        }
    }
    return __symbolic_glp_set_rii(P, i, rii);
}
void glp_set_sjj (glp_prob * P, int j, double sjj){
    int debug;
    if (!__symbolic_glp_set_sjj) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_sjj", (gpointer *) &__symbolic_glp_set_sjj)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_sjj could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_sjj.\n");
        }
    }
    return __symbolic_glp_set_sjj(P, j, sjj);
}
double glp_get_rii (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_rii) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_rii", (gpointer *) &__symbolic_glp_get_rii)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_rii could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_rii.\n");
        }
    }
    return __symbolic_glp_get_rii(P, i);
}
double glp_get_sjj (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_sjj) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_sjj", (gpointer *) &__symbolic_glp_get_sjj)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_sjj could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_sjj.\n");
        }
    }
    return __symbolic_glp_get_sjj(P, j);
}
void glp_scale_prob (glp_prob * P, int flags){
    int debug;
    if (!__symbolic_glp_scale_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_scale_prob", (gpointer *) &__symbolic_glp_scale_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_scale_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_scale_prob.\n");
        }
    }
    return __symbolic_glp_scale_prob(P, flags);
}
void glp_unscale_prob (glp_prob * P){
    int debug;
    if (!__symbolic_glp_unscale_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_unscale_prob", (gpointer *) &__symbolic_glp_unscale_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_unscale_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_unscale_prob.\n");
        }
    }
    return __symbolic_glp_unscale_prob(P);
}
void glp_set_row_stat (glp_prob * P, int i, int stat){
    int debug;
    if (!__symbolic_glp_set_row_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_row_stat", (gpointer *) &__symbolic_glp_set_row_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_row_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_row_stat.\n");
        }
    }
    return __symbolic_glp_set_row_stat(P, i, stat);
}
void glp_set_col_stat (glp_prob * P, int j, int stat){
    int debug;
    if (!__symbolic_glp_set_col_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_col_stat", (gpointer *) &__symbolic_glp_set_col_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_col_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_col_stat.\n");
        }
    }
    return __symbolic_glp_set_col_stat(P, j, stat);
}
void glp_std_basis (glp_prob * P){
    int debug;
    if (!__symbolic_glp_std_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_std_basis", (gpointer *) &__symbolic_glp_std_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_std_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_std_basis.\n");
        }
    }
    return __symbolic_glp_std_basis(P);
}
void glp_adv_basis (glp_prob * P, int flags){
    int debug;
    if (!__symbolic_glp_adv_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_adv_basis", (gpointer *) &__symbolic_glp_adv_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_adv_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_adv_basis.\n");
        }
    }
    return __symbolic_glp_adv_basis(P, flags);
}
void glp_cpx_basis (glp_prob * P){
    int debug;
    if (!__symbolic_glp_cpx_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_cpx_basis", (gpointer *) &__symbolic_glp_cpx_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_cpx_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_cpx_basis.\n");
        }
    }
    return __symbolic_glp_cpx_basis(P);
}
int glp_simplex (glp_prob * P, const glp_smcp * parm){
    int debug;
    if (!__symbolic_glp_simplex) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_simplex", (gpointer *) &__symbolic_glp_simplex)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_simplex could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_simplex.\n");
        }
    }
    return __symbolic_glp_simplex(P, parm);
}
int glp_exact (glp_prob * P, const glp_smcp * parm){
    int debug;
    if (!__symbolic_glp_exact) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_exact", (gpointer *) &__symbolic_glp_exact)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_exact could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_exact.\n");
        }
    }
    return __symbolic_glp_exact(P, parm);
}
void glp_init_smcp (glp_smcp * parm){
    int debug;
    if (!__symbolic_glp_init_smcp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_smcp", (gpointer *) &__symbolic_glp_init_smcp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_smcp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_smcp.\n");
        }
    }
    return __symbolic_glp_init_smcp(parm);
}
int glp_get_status (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_status", (gpointer *) &__symbolic_glp_get_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_status.\n");
        }
    }
    return __symbolic_glp_get_status(P);
}
int glp_get_prim_stat (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_prim_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_prim_stat", (gpointer *) &__symbolic_glp_get_prim_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_prim_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_prim_stat.\n");
        }
    }
    return __symbolic_glp_get_prim_stat(P);
}
int glp_get_dual_stat (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_dual_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_dual_stat", (gpointer *) &__symbolic_glp_get_dual_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_dual_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_dual_stat.\n");
        }
    }
    return __symbolic_glp_get_dual_stat(P);
}
double glp_get_obj_val (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_obj_val", (gpointer *) &__symbolic_glp_get_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_obj_val.\n");
        }
    }
    return __symbolic_glp_get_obj_val(P);
}
int glp_get_row_stat (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_stat", (gpointer *) &__symbolic_glp_get_row_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_stat.\n");
        }
    }
    return __symbolic_glp_get_row_stat(P, i);
}
double glp_get_row_prim (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_prim", (gpointer *) &__symbolic_glp_get_row_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_prim.\n");
        }
    }
    return __symbolic_glp_get_row_prim(P, i);
}
double glp_get_row_dual (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_dual", (gpointer *) &__symbolic_glp_get_row_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_dual.\n");
        }
    }
    return __symbolic_glp_get_row_dual(P, i);
}
int glp_get_col_stat (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_stat", (gpointer *) &__symbolic_glp_get_col_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_stat.\n");
        }
    }
    return __symbolic_glp_get_col_stat(P, j);
}
double glp_get_col_prim (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_prim", (gpointer *) &__symbolic_glp_get_col_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_prim.\n");
        }
    }
    return __symbolic_glp_get_col_prim(P, j);
}
double glp_get_col_dual (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_dual", (gpointer *) &__symbolic_glp_get_col_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_dual.\n");
        }
    }
    return __symbolic_glp_get_col_dual(P, j);
}
int glp_get_unbnd_ray (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_unbnd_ray) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_unbnd_ray", (gpointer *) &__symbolic_glp_get_unbnd_ray)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_unbnd_ray could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_unbnd_ray.\n");
        }
    }
    return __symbolic_glp_get_unbnd_ray(P);
}
int glp_interior (glp_prob * P, const glp_iptcp * parm){
    int debug;
    if (!__symbolic_glp_interior) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_interior", (gpointer *) &__symbolic_glp_interior)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_interior could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_interior.\n");
        }
    }
    return __symbolic_glp_interior(P, parm);
}
void glp_init_iptcp (glp_iptcp * parm){
    int debug;
    if (!__symbolic_glp_init_iptcp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_iptcp", (gpointer *) &__symbolic_glp_init_iptcp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_iptcp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_iptcp.\n");
        }
    }
    return __symbolic_glp_init_iptcp(parm);
}
int glp_ipt_status (glp_prob * P){
    int debug;
    if (!__symbolic_glp_ipt_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_status", (gpointer *) &__symbolic_glp_ipt_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_status.\n");
        }
    }
    return __symbolic_glp_ipt_status(P);
}
double glp_ipt_obj_val (glp_prob * P){
    int debug;
    if (!__symbolic_glp_ipt_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_obj_val", (gpointer *) &__symbolic_glp_ipt_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_obj_val.\n");
        }
    }
    return __symbolic_glp_ipt_obj_val(P);
}
double glp_ipt_row_prim (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_ipt_row_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_row_prim", (gpointer *) &__symbolic_glp_ipt_row_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_row_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_row_prim.\n");
        }
    }
    return __symbolic_glp_ipt_row_prim(P, i);
}
double glp_ipt_row_dual (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_ipt_row_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_row_dual", (gpointer *) &__symbolic_glp_ipt_row_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_row_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_row_dual.\n");
        }
    }
    return __symbolic_glp_ipt_row_dual(P, i);
}
double glp_ipt_col_prim (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_ipt_col_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_col_prim", (gpointer *) &__symbolic_glp_ipt_col_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_col_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_col_prim.\n");
        }
    }
    return __symbolic_glp_ipt_col_prim(P, j);
}
double glp_ipt_col_dual (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_ipt_col_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ipt_col_dual", (gpointer *) &__symbolic_glp_ipt_col_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ipt_col_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ipt_col_dual.\n");
        }
    }
    return __symbolic_glp_ipt_col_dual(P, j);
}
void glp_set_col_kind (glp_prob * P, int j, int kind){
    int debug;
    if (!__symbolic_glp_set_col_kind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_col_kind", (gpointer *) &__symbolic_glp_set_col_kind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_col_kind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_col_kind.\n");
        }
    }
    return __symbolic_glp_set_col_kind(P, j, kind);
}
int glp_get_col_kind (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_kind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_kind", (gpointer *) &__symbolic_glp_get_col_kind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_kind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_kind.\n");
        }
    }
    return __symbolic_glp_get_col_kind(P, j);
}
int glp_get_num_int (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_num_int) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_num_int", (gpointer *) &__symbolic_glp_get_num_int)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_num_int could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_num_int.\n");
        }
    }
    return __symbolic_glp_get_num_int(P);
}
int glp_get_num_bin (glp_prob * P){
    int debug;
    if (!__symbolic_glp_get_num_bin) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_num_bin", (gpointer *) &__symbolic_glp_get_num_bin)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_num_bin could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_num_bin.\n");
        }
    }
    return __symbolic_glp_get_num_bin(P);
}
int glp_intopt (glp_prob * P, const glp_iocp * parm){
    int debug;
    if (!__symbolic_glp_intopt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_intopt", (gpointer *) &__symbolic_glp_intopt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_intopt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_intopt.\n");
        }
    }
    return __symbolic_glp_intopt(P, parm);
}
void glp_init_iocp (glp_iocp * parm){
    int debug;
    if (!__symbolic_glp_init_iocp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_iocp", (gpointer *) &__symbolic_glp_init_iocp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_iocp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_iocp.\n");
        }
    }
    return __symbolic_glp_init_iocp(parm);
}
int glp_mip_status (glp_prob * P){
    int debug;
    if (!__symbolic_glp_mip_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mip_status", (gpointer *) &__symbolic_glp_mip_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mip_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mip_status.\n");
        }
    }
    return __symbolic_glp_mip_status(P);
}
double glp_mip_obj_val (glp_prob * P){
    int debug;
    if (!__symbolic_glp_mip_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mip_obj_val", (gpointer *) &__symbolic_glp_mip_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mip_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mip_obj_val.\n");
        }
    }
    return __symbolic_glp_mip_obj_val(P);
}
double glp_mip_row_val (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_mip_row_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mip_row_val", (gpointer *) &__symbolic_glp_mip_row_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mip_row_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mip_row_val.\n");
        }
    }
    return __symbolic_glp_mip_row_val(P, i);
}
double glp_mip_col_val (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_mip_col_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mip_col_val", (gpointer *) &__symbolic_glp_mip_col_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mip_col_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mip_col_val.\n");
        }
    }
    return __symbolic_glp_mip_col_val(P, j);
}
int glp_print_sol (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_print_sol) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_print_sol", (gpointer *) &__symbolic_glp_print_sol)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_print_sol could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_print_sol.\n");
        }
    }
    return __symbolic_glp_print_sol(P, fname);
}
int glp_read_sol (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_read_sol) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_sol", (gpointer *) &__symbolic_glp_read_sol)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_sol could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_sol.\n");
        }
    }
    return __symbolic_glp_read_sol(P, fname);
}
int glp_write_sol (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_write_sol) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_sol", (gpointer *) &__symbolic_glp_write_sol)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_sol could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_sol.\n");
        }
    }
    return __symbolic_glp_write_sol(P, fname);
}
int glp_print_ranges (glp_prob * P, int len, const int list[], int flags, const char *fname){
    int debug;
    if (!__symbolic_glp_print_ranges) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_print_ranges", (gpointer *) &__symbolic_glp_print_ranges)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_print_ranges could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_print_ranges.\n");
        }
    }
    return __symbolic_glp_print_ranges(P, len, list, flags, fname);
}
int glp_print_ipt (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_print_ipt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_print_ipt", (gpointer *) &__symbolic_glp_print_ipt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_print_ipt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_print_ipt.\n");
        }
    }
    return __symbolic_glp_print_ipt(P, fname);
}
int glp_read_ipt (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_read_ipt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_ipt", (gpointer *) &__symbolic_glp_read_ipt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_ipt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_ipt.\n");
        }
    }
    return __symbolic_glp_read_ipt(P, fname);
}
int glp_write_ipt (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_write_ipt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_ipt", (gpointer *) &__symbolic_glp_write_ipt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_ipt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_ipt.\n");
        }
    }
    return __symbolic_glp_write_ipt(P, fname);
}
int glp_print_mip (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_print_mip) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_print_mip", (gpointer *) &__symbolic_glp_print_mip)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_print_mip could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_print_mip.\n");
        }
    }
    return __symbolic_glp_print_mip(P, fname);
}
int glp_read_mip (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_read_mip) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_mip", (gpointer *) &__symbolic_glp_read_mip)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_mip could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_mip.\n");
        }
    }
    return __symbolic_glp_read_mip(P, fname);
}
int glp_write_mip (glp_prob * P, const char *fname){
    int debug;
    if (!__symbolic_glp_write_mip) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_mip", (gpointer *) &__symbolic_glp_write_mip)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_mip could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_mip.\n");
        }
    }
    return __symbolic_glp_write_mip(P, fname);
}
int glp_bf_exists (glp_prob * P){
    int debug;
    if (!__symbolic_glp_bf_exists) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_bf_exists", (gpointer *) &__symbolic_glp_bf_exists)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_bf_exists could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_bf_exists.\n");
        }
    }
    return __symbolic_glp_bf_exists(P);
}
int glp_factorize (glp_prob * P){
    int debug;
    if (!__symbolic_glp_factorize) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_factorize", (gpointer *) &__symbolic_glp_factorize)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_factorize could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_factorize.\n");
        }
    }
    return __symbolic_glp_factorize(P);
}
int glp_bf_updated (glp_prob * P){
    int debug;
    if (!__symbolic_glp_bf_updated) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_bf_updated", (gpointer *) &__symbolic_glp_bf_updated)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_bf_updated could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_bf_updated.\n");
        }
    }
    return __symbolic_glp_bf_updated(P);
}
void glp_get_bfcp (glp_prob * P, glp_bfcp * parm){
    int debug;
    if (!__symbolic_glp_get_bfcp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_bfcp", (gpointer *) &__symbolic_glp_get_bfcp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_bfcp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_bfcp.\n");
        }
    }
    return __symbolic_glp_get_bfcp(P, parm);
}
void glp_set_bfcp (glp_prob * P, const glp_bfcp * parm){
    int debug;
    if (!__symbolic_glp_set_bfcp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_bfcp", (gpointer *) &__symbolic_glp_set_bfcp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_bfcp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_bfcp.\n");
        }
    }
    return __symbolic_glp_set_bfcp(P, parm);
}
int glp_get_bhead (glp_prob * P, int k){
    int debug;
    if (!__symbolic_glp_get_bhead) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_bhead", (gpointer *) &__symbolic_glp_get_bhead)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_bhead could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_bhead.\n");
        }
    }
    return __symbolic_glp_get_bhead(P, k);
}
int glp_get_row_bind (glp_prob * P, int i){
    int debug;
    if (!__symbolic_glp_get_row_bind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_row_bind", (gpointer *) &__symbolic_glp_get_row_bind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_row_bind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_row_bind.\n");
        }
    }
    return __symbolic_glp_get_row_bind(P, i);
}
int glp_get_col_bind (glp_prob * P, int j){
    int debug;
    if (!__symbolic_glp_get_col_bind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_get_col_bind", (gpointer *) &__symbolic_glp_get_col_bind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_get_col_bind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_get_col_bind.\n");
        }
    }
    return __symbolic_glp_get_col_bind(P, j);
}
void glp_ftran (glp_prob * P, double x[]){
    int debug;
    if (!__symbolic_glp_ftran) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ftran", (gpointer *) &__symbolic_glp_ftran)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ftran could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ftran.\n");
        }
    }
    return __symbolic_glp_ftran(P, x);
}
void glp_btran (glp_prob * P, double x[]){
    int debug;
    if (!__symbolic_glp_btran) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_btran", (gpointer *) &__symbolic_glp_btran)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_btran could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_btran.\n");
        }
    }
    return __symbolic_glp_btran(P, x);
}
int glp_warm_up (glp_prob * P){
    int debug;
    if (!__symbolic_glp_warm_up) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_warm_up", (gpointer *) &__symbolic_glp_warm_up)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_warm_up could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_warm_up.\n");
        }
    }
    return __symbolic_glp_warm_up(P);
}
int glp_eval_tab_row (glp_prob * P, int k, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_eval_tab_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_eval_tab_row", (gpointer *) &__symbolic_glp_eval_tab_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_eval_tab_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_eval_tab_row.\n");
        }
    }
    return __symbolic_glp_eval_tab_row(P, k, ind, val);
}
int glp_eval_tab_col (glp_prob * P, int k, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_eval_tab_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_eval_tab_col", (gpointer *) &__symbolic_glp_eval_tab_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_eval_tab_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_eval_tab_col.\n");
        }
    }
    return __symbolic_glp_eval_tab_col(P, k, ind, val);
}
int glp_transform_row (glp_prob * P, int len, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_transform_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_transform_row", (gpointer *) &__symbolic_glp_transform_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_transform_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_transform_row.\n");
        }
    }
    return __symbolic_glp_transform_row(P, len, ind, val);
}
int glp_transform_col (glp_prob * P, int len, int ind[], double val[]){
    int debug;
    if (!__symbolic_glp_transform_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_transform_col", (gpointer *) &__symbolic_glp_transform_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_transform_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_transform_col.\n");
        }
    }
    return __symbolic_glp_transform_col(P, len, ind, val);
}
int glp_prim_rtest (glp_prob * P, int len, const int ind[], const double val[], int dir, double eps){
    int debug;
    if (!__symbolic_glp_prim_rtest) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_prim_rtest", (gpointer *) &__symbolic_glp_prim_rtest)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_prim_rtest could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_prim_rtest.\n");
        }
    }
    return __symbolic_glp_prim_rtest(P, len, ind, val, dir, eps);
}
int glp_dual_rtest (glp_prob * P, int len, const int ind[], const double val[], int dir, double eps){
    int debug;
    if (!__symbolic_glp_dual_rtest) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_dual_rtest", (gpointer *) &__symbolic_glp_dual_rtest)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_dual_rtest could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_dual_rtest.\n");
        }
    }
    return __symbolic_glp_dual_rtest(P, len, ind, val, dir, eps);
}
void glp_analyze_bound (glp_prob * P, int k, double *value1, int *var1, double *value2, int *var2){
    int debug;
    if (!__symbolic_glp_analyze_bound) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_analyze_bound", (gpointer *) &__symbolic_glp_analyze_bound)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_analyze_bound could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_analyze_bound.\n");
        }
    }
    return __symbolic_glp_analyze_bound(P, k, value1, var1, value2, var2);
}
void glp_analyze_coef (glp_prob * P, int k, double *coef1, int *var1, double *value1, double *coef2, int *var2, double *value2){
    int debug;
    if (!__symbolic_glp_analyze_coef) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_analyze_coef", (gpointer *) &__symbolic_glp_analyze_coef)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_analyze_coef could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_analyze_coef.\n");
        }
    }
    return __symbolic_glp_analyze_coef(P, k, coef1, var1, value1, coef2, var2, value2);
}
int glp_ios_reason (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_reason) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_reason", (gpointer *) &__symbolic_glp_ios_reason)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_reason could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_reason.\n");
        }
    }
    return __symbolic_glp_ios_reason(T);
}
glp_prob *glp_ios_get_prob (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_get_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_get_prob", (gpointer *) &__symbolic_glp_ios_get_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_get_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_get_prob.\n");
        }
    }
    return __symbolic_glp_ios_get_prob(T);
}
void glp_ios_tree_size (glp_tree * T, int *a_cnt, int *n_cnt, int *t_cnt){
    int debug;
    if (!__symbolic_glp_ios_tree_size) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_tree_size", (gpointer *) &__symbolic_glp_ios_tree_size)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_tree_size could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_tree_size.\n");
        }
    }
    return __symbolic_glp_ios_tree_size(T, a_cnt, n_cnt, t_cnt);
}
int glp_ios_curr_node (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_curr_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_curr_node", (gpointer *) &__symbolic_glp_ios_curr_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_curr_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_curr_node.\n");
        }
    }
    return __symbolic_glp_ios_curr_node(T);
}
int glp_ios_next_node (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_next_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_next_node", (gpointer *) &__symbolic_glp_ios_next_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_next_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_next_node.\n");
        }
    }
    return __symbolic_glp_ios_next_node(T, p);
}
int glp_ios_prev_node (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_prev_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_prev_node", (gpointer *) &__symbolic_glp_ios_prev_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_prev_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_prev_node.\n");
        }
    }
    return __symbolic_glp_ios_prev_node(T, p);
}
int glp_ios_up_node (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_up_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_up_node", (gpointer *) &__symbolic_glp_ios_up_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_up_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_up_node.\n");
        }
    }
    return __symbolic_glp_ios_up_node(T, p);
}
int glp_ios_node_level (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_node_level) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_node_level", (gpointer *) &__symbolic_glp_ios_node_level)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_node_level could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_node_level.\n");
        }
    }
    return __symbolic_glp_ios_node_level(T, p);
}
double glp_ios_node_bound (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_node_bound) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_node_bound", (gpointer *) &__symbolic_glp_ios_node_bound)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_node_bound could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_node_bound.\n");
        }
    }
    return __symbolic_glp_ios_node_bound(T, p);
}
int glp_ios_best_node (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_best_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_best_node", (gpointer *) &__symbolic_glp_ios_best_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_best_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_best_node.\n");
        }
    }
    return __symbolic_glp_ios_best_node(T);
}
double glp_ios_mip_gap (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_mip_gap) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_mip_gap", (gpointer *) &__symbolic_glp_ios_mip_gap)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_mip_gap could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_mip_gap.\n");
        }
    }
    return __symbolic_glp_ios_mip_gap(T);
}
void *glp_ios_node_data (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_node_data) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_node_data", (gpointer *) &__symbolic_glp_ios_node_data)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_node_data could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_node_data.\n");
        }
    }
    return __symbolic_glp_ios_node_data(T, p);
}
void glp_ios_row_attr (glp_tree * T, int i, glp_attr * attr){
    int debug;
    if (!__symbolic_glp_ios_row_attr) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_row_attr", (gpointer *) &__symbolic_glp_ios_row_attr)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_row_attr could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_row_attr.\n");
        }
    }
    return __symbolic_glp_ios_row_attr(T, i, attr);
}
int glp_ios_pool_size (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_pool_size) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_pool_size", (gpointer *) &__symbolic_glp_ios_pool_size)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_pool_size could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_pool_size.\n");
        }
    }
    return __symbolic_glp_ios_pool_size(T);
}
int glp_ios_add_row (glp_tree * T, const char *name, int klass, int flags, int len, const int ind[], const double val[], int type, double rhs){
    int debug;
    if (!__symbolic_glp_ios_add_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_add_row", (gpointer *) &__symbolic_glp_ios_add_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_add_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_add_row.\n");
        }
    }
    return __symbolic_glp_ios_add_row(T, name, klass, flags, len, ind, val, type, rhs);
}
void glp_ios_del_row (glp_tree * T, int i){
    int debug;
    if (!__symbolic_glp_ios_del_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_del_row", (gpointer *) &__symbolic_glp_ios_del_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_del_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_del_row.\n");
        }
    }
    return __symbolic_glp_ios_del_row(T, i);
}
void glp_ios_clear_pool (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_clear_pool) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_clear_pool", (gpointer *) &__symbolic_glp_ios_clear_pool)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_clear_pool could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_clear_pool.\n");
        }
    }
    return __symbolic_glp_ios_clear_pool(T);
}
int glp_ios_can_branch (glp_tree * T, int j){
    int debug;
    if (!__symbolic_glp_ios_can_branch) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_can_branch", (gpointer *) &__symbolic_glp_ios_can_branch)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_can_branch could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_can_branch.\n");
        }
    }
    return __symbolic_glp_ios_can_branch(T, j);
}
void glp_ios_branch_upon (glp_tree * T, int j, int sel){
    int debug;
    if (!__symbolic_glp_ios_branch_upon) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_branch_upon", (gpointer *) &__symbolic_glp_ios_branch_upon)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_branch_upon could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_branch_upon.\n");
        }
    }
    return __symbolic_glp_ios_branch_upon(T, j, sel);
}
void glp_ios_select_node (glp_tree * T, int p){
    int debug;
    if (!__symbolic_glp_ios_select_node) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_select_node", (gpointer *) &__symbolic_glp_ios_select_node)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_select_node could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_select_node.\n");
        }
    }
    return __symbolic_glp_ios_select_node(T, p);
}
int glp_ios_heur_sol (glp_tree * T, const double x[]){
    int debug;
    if (!__symbolic_glp_ios_heur_sol) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_heur_sol", (gpointer *) &__symbolic_glp_ios_heur_sol)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_heur_sol could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_heur_sol.\n");
        }
    }
    return __symbolic_glp_ios_heur_sol(T, x);
}
void glp_ios_terminate (glp_tree * T){
    int debug;
    if (!__symbolic_glp_ios_terminate) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_ios_terminate", (gpointer *) &__symbolic_glp_ios_terminate)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_ios_terminate could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_ios_terminate.\n");
        }
    }
    return __symbolic_glp_ios_terminate(T);
}
void glp_init_mpscp (glp_mpscp * parm){
    int debug;
    if (!__symbolic_glp_init_mpscp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_mpscp", (gpointer *) &__symbolic_glp_init_mpscp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_mpscp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_mpscp.\n");
        }
    }
    return __symbolic_glp_init_mpscp(parm);
}
int glp_read_mps (glp_prob * P, int fmt, const glp_mpscp * parm, const char *fname){
    int debug;
    if (!__symbolic_glp_read_mps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_mps", (gpointer *) &__symbolic_glp_read_mps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_mps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_mps.\n");
        }
    }
    return __symbolic_glp_read_mps(P, fmt, parm, fname);
}
int glp_write_mps (glp_prob * P, int fmt, const glp_mpscp * parm, const char *fname){
    int debug;
    if (!__symbolic_glp_write_mps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_mps", (gpointer *) &__symbolic_glp_write_mps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_mps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_mps.\n");
        }
    }
    return __symbolic_glp_write_mps(P, fmt, parm, fname);
}
void glp_init_cpxcp (glp_cpxcp * parm){
    int debug;
    if (!__symbolic_glp_init_cpxcp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_cpxcp", (gpointer *) &__symbolic_glp_init_cpxcp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_cpxcp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_cpxcp.\n");
        }
    }
    return __symbolic_glp_init_cpxcp(parm);
}
int glp_read_lp (glp_prob * P, const glp_cpxcp * parm, const char *fname){
    int debug;
    if (!__symbolic_glp_read_lp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_lp", (gpointer *) &__symbolic_glp_read_lp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_lp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_lp.\n");
        }
    }
    return __symbolic_glp_read_lp(P, parm, fname);
}
int glp_write_lp (glp_prob * P, const glp_cpxcp * parm, const char *fname){
    int debug;
    if (!__symbolic_glp_write_lp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_lp", (gpointer *) &__symbolic_glp_write_lp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_lp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_lp.\n");
        }
    }
    return __symbolic_glp_write_lp(P, parm, fname);
}
int glp_read_prob (glp_prob * P, int flags, const char *fname){
    int debug;
    if (!__symbolic_glp_read_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_prob", (gpointer *) &__symbolic_glp_read_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_prob.\n");
        }
    }
    return __symbolic_glp_read_prob(P, flags, fname);
}
int glp_write_prob (glp_prob * P, int flags, const char *fname){
    int debug;
    if (!__symbolic_glp_write_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_prob", (gpointer *) &__symbolic_glp_write_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_prob.\n");
        }
    }
    return __symbolic_glp_write_prob(P, flags, fname);
}
glp_tran *glp_mpl_alloc_wksp (void){
    int debug;
    if (!__symbolic_glp_mpl_alloc_wksp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_alloc_wksp", (gpointer *) &__symbolic_glp_mpl_alloc_wksp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_alloc_wksp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_alloc_wksp.\n");
        }
    }
    return __symbolic_glp_mpl_alloc_wksp();
}
int glp_mpl_read_model (glp_tran * tran, const char *fname, int skip){
    int debug;
    if (!__symbolic_glp_mpl_read_model) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_read_model", (gpointer *) &__symbolic_glp_mpl_read_model)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_read_model could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_read_model.\n");
        }
    }
    return __symbolic_glp_mpl_read_model(tran, fname, skip);
}
int glp_mpl_read_data (glp_tran * tran, const char *fname){
    int debug;
    if (!__symbolic_glp_mpl_read_data) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_read_data", (gpointer *) &__symbolic_glp_mpl_read_data)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_read_data could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_read_data.\n");
        }
    }
    return __symbolic_glp_mpl_read_data(tran, fname);
}
int glp_mpl_generate (glp_tran * tran, const char *fname){
    int debug;
    if (!__symbolic_glp_mpl_generate) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_generate", (gpointer *) &__symbolic_glp_mpl_generate)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_generate could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_generate.\n");
        }
    }
    return __symbolic_glp_mpl_generate(tran, fname);
}
void glp_mpl_build_prob (glp_tran * tran, glp_prob * prob){
    int debug;
    if (!__symbolic_glp_mpl_build_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_build_prob", (gpointer *) &__symbolic_glp_mpl_build_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_build_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_build_prob.\n");
        }
    }
    return __symbolic_glp_mpl_build_prob(tran, prob);
}
int glp_mpl_postsolve (glp_tran * tran, glp_prob * prob, int sol){
    int debug;
    if (!__symbolic_glp_mpl_postsolve) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_postsolve", (gpointer *) &__symbolic_glp_mpl_postsolve)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_postsolve could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_postsolve.\n");
        }
    }
    return __symbolic_glp_mpl_postsolve(tran, prob, sol);
}
void glp_mpl_free_wksp (glp_tran * tran){
    int debug;
    if (!__symbolic_glp_mpl_free_wksp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mpl_free_wksp", (gpointer *) &__symbolic_glp_mpl_free_wksp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mpl_free_wksp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mpl_free_wksp.\n");
        }
    }
    return __symbolic_glp_mpl_free_wksp(tran);
}
int glp_main (int argc, const char *argv[]){
    int debug;
    if (!__symbolic_glp_main) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_main", (gpointer *) &__symbolic_glp_main)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_main could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_main.\n");
        }
    }
    return __symbolic_glp_main(argc, argv);
}
int glp_init_env (void){
    int debug;
    if (!__symbolic_glp_init_env) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_init_env", (gpointer *) &__symbolic_glp_init_env)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_init_env could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_init_env.\n");
        }
    }
    return __symbolic_glp_init_env();
}
const char *glp_version (void){
    int debug;
    if (!__symbolic_glp_version) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_version", (gpointer *) &__symbolic_glp_version)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_version could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_version.\n");
        }
    }
    return __symbolic_glp_version();
}
int glp_free_env (void){
    int debug;
    if (!__symbolic_glp_free_env) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_free_env", (gpointer *) &__symbolic_glp_free_env)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_free_env could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_free_env.\n");
        }
    }
    return __symbolic_glp_free_env();
}
void glp_printf (const char *fmt, ...){
    int debug;
    if (!__symbolic_glp_printf) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_printf", (gpointer *) &__symbolic_glp_printf)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_printf could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_printf.\n");
        }
    }
    return __symbolic_glp_printf(fmt);
}
void glp_vprintf (const char *fmt, va_list arg){
    int debug;
    if (!__symbolic_glp_vprintf) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_vprintf", (gpointer *) &__symbolic_glp_vprintf)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_vprintf could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_vprintf.\n");
        }
    }
    return __symbolic_glp_vprintf(fmt, arg);
}
int glp_term_out (int flag){
    int debug;
    if (!__symbolic_glp_term_out) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_term_out", (gpointer *) &__symbolic_glp_term_out)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_term_out could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_term_out.\n");
        }
    }
    return __symbolic_glp_term_out(flag);
}
void glp_term_hook (int (*func) (void *info, const char *s), void *info){
    int debug;
    if (!__symbolic_glp_term_hook) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_term_hook", (gpointer *) &__symbolic_glp_term_hook)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_term_hook could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_term_hook.\n");
        }
    }
    return __symbolic_glp_term_hook(func, info);
}
int glp_open_tee (const char *fname){
    int debug;
    if (!__symbolic_glp_open_tee) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_open_tee", (gpointer *) &__symbolic_glp_open_tee)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_open_tee could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_open_tee.\n");
        }
    }
    return __symbolic_glp_open_tee(fname);
}
int glp_close_tee (void){
    int debug;
    if (!__symbolic_glp_close_tee) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_close_tee", (gpointer *) &__symbolic_glp_close_tee)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_close_tee could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_close_tee.\n");
        }
    }
    return __symbolic_glp_close_tee();
}
_glp_error glp_error_ (const char *file, int line){
    int debug;
    if (!__symbolic_glp_error_) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_error_", (gpointer *) &__symbolic_glp_error_)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_error_ could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_error_.\n");
        }
    }
    return __symbolic_glp_error_(file, line);
}
void glp_assert_ (const char *expr, const char *file, int line){
    int debug;
    if (!__symbolic_glp_assert_) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_assert_", (gpointer *) &__symbolic_glp_assert_)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_assert_ could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_assert_.\n");
        }
    }
    return __symbolic_glp_assert_(expr, file, line);
}
void glp_error_hook (void (*func) (void *info), void *info){
    int debug;
    if (!__symbolic_glp_error_hook) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_error_hook", (gpointer *) &__symbolic_glp_error_hook)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_error_hook could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_error_hook.\n");
        }
    }
    return __symbolic_glp_error_hook(func, info);
}
void *glp_malloc (int size){
    int debug;
    if (!__symbolic_glp_malloc) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_malloc", (gpointer *) &__symbolic_glp_malloc)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_malloc could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_malloc.\n");
        }
    }
    return __symbolic_glp_malloc(size);
}
void *glp_calloc (int n, int size){
    int debug;
    if (!__symbolic_glp_calloc) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_calloc", (gpointer *) &__symbolic_glp_calloc)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_calloc could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_calloc.\n");
        }
    }
    return __symbolic_glp_calloc(n, size);
}
void glp_free (void *ptr){
    int debug;
    if (!__symbolic_glp_free) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_free", (gpointer *) &__symbolic_glp_free)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_free could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_free.\n");
        }
    }
    return __symbolic_glp_free(ptr);
}
void glp_mem_limit (int limit){
    int debug;
    if (!__symbolic_glp_mem_limit) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mem_limit", (gpointer *) &__symbolic_glp_mem_limit)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mem_limit could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mem_limit.\n");
        }
    }
    return __symbolic_glp_mem_limit(limit);
}
void glp_mem_usage (int *count, int *cpeak, glp_long * total, glp_long * tpeak){
    int debug;
    if (!__symbolic_glp_mem_usage) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mem_usage", (gpointer *) &__symbolic_glp_mem_usage)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mem_usage could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mem_usage.\n");
        }
    }
    return __symbolic_glp_mem_usage(count, cpeak, total, tpeak);
}
glp_long glp_time (void){
    int debug;
    if (!__symbolic_glp_time) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_time", (gpointer *) &__symbolic_glp_time)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_time could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_time.\n");
        }
    }
    return __symbolic_glp_time();
}
double glp_difftime (glp_long t1, glp_long t0){
    int debug;
    if (!__symbolic_glp_difftime) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_difftime", (gpointer *) &__symbolic_glp_difftime)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_difftime could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_difftime.\n");
        }
    }
    return __symbolic_glp_difftime(t1, t0);
}
glp_data *glp_sdf_open_file (const char *fname){
    int debug;
    if (!__symbolic_glp_sdf_open_file) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_open_file", (gpointer *) &__symbolic_glp_sdf_open_file)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_open_file could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_open_file.\n");
        }
    }
    return __symbolic_glp_sdf_open_file(fname);
}
void glp_sdf_set_jump (glp_data * data, void *jump){
    int debug;
    if (!__symbolic_glp_sdf_set_jump) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_set_jump", (gpointer *) &__symbolic_glp_sdf_set_jump)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_set_jump could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_set_jump.\n");
        }
    }
    return __symbolic_glp_sdf_set_jump(data, jump);
}
void glp_sdf_error (glp_data * data, const char *fmt, ...){
    int debug;
    if (!__symbolic_glp_sdf_error) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_error", (gpointer *) &__symbolic_glp_sdf_error)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_error could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_error.\n");
        }
    }
    return __symbolic_glp_sdf_error(data, fmt);
}
void glp_sdf_warning (glp_data * data, const char *fmt, ...){
    int debug;
    if (!__symbolic_glp_sdf_warning) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_warning", (gpointer *) &__symbolic_glp_sdf_warning)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_warning could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_warning.\n");
        }
    }
    return __symbolic_glp_sdf_warning(data, fmt);
}
int glp_sdf_read_int (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_read_int) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_read_int", (gpointer *) &__symbolic_glp_sdf_read_int)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_read_int could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_read_int.\n");
        }
    }
    return __symbolic_glp_sdf_read_int(data);
}
double glp_sdf_read_num (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_read_num) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_read_num", (gpointer *) &__symbolic_glp_sdf_read_num)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_read_num could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_read_num.\n");
        }
    }
    return __symbolic_glp_sdf_read_num(data);
}
const char *glp_sdf_read_item (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_read_item) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_read_item", (gpointer *) &__symbolic_glp_sdf_read_item)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_read_item could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_read_item.\n");
        }
    }
    return __symbolic_glp_sdf_read_item(data);
}
const char *glp_sdf_read_text (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_read_text) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_read_text", (gpointer *) &__symbolic_glp_sdf_read_text)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_read_text could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_read_text.\n");
        }
    }
    return __symbolic_glp_sdf_read_text(data);
}
int glp_sdf_line (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_line) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_line", (gpointer *) &__symbolic_glp_sdf_line)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_line could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_line.\n");
        }
    }
    return __symbolic_glp_sdf_line(data);
}
void glp_sdf_close_file (glp_data * data){
    int debug;
    if (!__symbolic_glp_sdf_close_file) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_sdf_close_file", (gpointer *) &__symbolic_glp_sdf_close_file)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_sdf_close_file could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_sdf_close_file.\n");
        }
    }
    return __symbolic_glp_sdf_close_file(data);
}
glp_graph *glp_create_graph (int v_size, int a_size){
    int debug;
    if (!__symbolic_glp_create_graph) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_create_graph", (gpointer *) &__symbolic_glp_create_graph)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_create_graph could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_create_graph.\n");
        }
    }
    return __symbolic_glp_create_graph(v_size, a_size);
}
void glp_set_graph_name (glp_graph * G, const char *name){
    int debug;
    if (!__symbolic_glp_set_graph_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_graph_name", (gpointer *) &__symbolic_glp_set_graph_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_graph_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_graph_name.\n");
        }
    }
    return __symbolic_glp_set_graph_name(G, name);
}
int glp_add_vertices (glp_graph * G, int nadd){
    int debug;
    if (!__symbolic_glp_add_vertices) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_add_vertices", (gpointer *) &__symbolic_glp_add_vertices)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_add_vertices could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_add_vertices.\n");
        }
    }
    return __symbolic_glp_add_vertices(G, nadd);
}
void glp_set_vertex_name (glp_graph * G, int i, const char *name){
    int debug;
    if (!__symbolic_glp_set_vertex_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_set_vertex_name", (gpointer *) &__symbolic_glp_set_vertex_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_set_vertex_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_set_vertex_name.\n");
        }
    }
    return __symbolic_glp_set_vertex_name(G, i, name);
}
glp_arc *glp_add_arc (glp_graph * G, int i, int j){
    int debug;
    if (!__symbolic_glp_add_arc) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_add_arc", (gpointer *) &__symbolic_glp_add_arc)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_add_arc could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_add_arc.\n");
        }
    }
    return __symbolic_glp_add_arc(G, i, j);
}
void glp_del_vertices (glp_graph * G, int ndel, const int num[]){
    int debug;
    if (!__symbolic_glp_del_vertices) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_del_vertices", (gpointer *) &__symbolic_glp_del_vertices)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_del_vertices could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_del_vertices.\n");
        }
    }
    return __symbolic_glp_del_vertices(G, ndel, num);
}
void glp_del_arc (glp_graph * G, glp_arc * a){
    int debug;
    if (!__symbolic_glp_del_arc) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_del_arc", (gpointer *) &__symbolic_glp_del_arc)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_del_arc could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_del_arc.\n");
        }
    }
    return __symbolic_glp_del_arc(G, a);
}
void glp_erase_graph (glp_graph * G, int v_size, int a_size){
    int debug;
    if (!__symbolic_glp_erase_graph) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_erase_graph", (gpointer *) &__symbolic_glp_erase_graph)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_erase_graph could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_erase_graph.\n");
        }
    }
    return __symbolic_glp_erase_graph(G, v_size, a_size);
}
void glp_delete_graph (glp_graph * G){
    int debug;
    if (!__symbolic_glp_delete_graph) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_delete_graph", (gpointer *) &__symbolic_glp_delete_graph)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_delete_graph could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_delete_graph.\n");
        }
    }
    return __symbolic_glp_delete_graph(G);
}
void glp_create_v_index (glp_graph * G){
    int debug;
    if (!__symbolic_glp_create_v_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_create_v_index", (gpointer *) &__symbolic_glp_create_v_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_create_v_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_create_v_index.\n");
        }
    }
    return __symbolic_glp_create_v_index(G);
}
int glp_find_vertex (glp_graph * G, const char *name){
    int debug;
    if (!__symbolic_glp_find_vertex) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_find_vertex", (gpointer *) &__symbolic_glp_find_vertex)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_find_vertex could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_find_vertex.\n");
        }
    }
    return __symbolic_glp_find_vertex(G, name);
}
void glp_delete_v_index (glp_graph * G){
    int debug;
    if (!__symbolic_glp_delete_v_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_delete_v_index", (gpointer *) &__symbolic_glp_delete_v_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_delete_v_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_delete_v_index.\n");
        }
    }
    return __symbolic_glp_delete_v_index(G);
}
int glp_read_graph (glp_graph * G, const char *fname){
    int debug;
    if (!__symbolic_glp_read_graph) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_graph", (gpointer *) &__symbolic_glp_read_graph)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_graph could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_graph.\n");
        }
    }
    return __symbolic_glp_read_graph(G, fname);
}
int glp_write_graph (glp_graph * G, const char *fname){
    int debug;
    if (!__symbolic_glp_write_graph) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_graph", (gpointer *) &__symbolic_glp_write_graph)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_graph could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_graph.\n");
        }
    }
    return __symbolic_glp_write_graph(G, fname);
}
void glp_mincost_lp (glp_prob * P, glp_graph * G, int names, int v_rhs, int a_low, int a_cap, int a_cost){
    int debug;
    if (!__symbolic_glp_mincost_lp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mincost_lp", (gpointer *) &__symbolic_glp_mincost_lp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mincost_lp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mincost_lp.\n");
        }
    }
    return __symbolic_glp_mincost_lp(P, G, names, v_rhs, a_low, a_cap, a_cost);
}
int glp_mincost_okalg (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, double *sol, int a_x, int v_pi){
    int debug;
    if (!__symbolic_glp_mincost_okalg) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_mincost_okalg", (gpointer *) &__symbolic_glp_mincost_okalg)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_mincost_okalg could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_mincost_okalg.\n");
        }
    }
    return __symbolic_glp_mincost_okalg(G, v_rhs, a_low, a_cap, a_cost, sol, a_x, v_pi);
}
void glp_maxflow_lp (glp_prob * P, glp_graph * G, int names, int s, int t, int a_cap){
    int debug;
    if (!__symbolic_glp_maxflow_lp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_maxflow_lp", (gpointer *) &__symbolic_glp_maxflow_lp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_maxflow_lp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_maxflow_lp.\n");
        }
    }
    return __symbolic_glp_maxflow_lp(P, G, names, s, t, a_cap);
}
int glp_maxflow_ffalg (glp_graph * G, int s, int t, int a_cap, double *sol, int a_x, int v_cut){
    int debug;
    if (!__symbolic_glp_maxflow_ffalg) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_maxflow_ffalg", (gpointer *) &__symbolic_glp_maxflow_ffalg)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_maxflow_ffalg could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_maxflow_ffalg.\n");
        }
    }
    return __symbolic_glp_maxflow_ffalg(G, s, t, a_cap, sol, a_x, v_cut);
}
int glp_check_asnprob (glp_graph * G, int v_set){
    int debug;
    if (!__symbolic_glp_check_asnprob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_check_asnprob", (gpointer *) &__symbolic_glp_check_asnprob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_check_asnprob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_check_asnprob.\n");
        }
    }
    return __symbolic_glp_check_asnprob(G, v_set);
}
int glp_asnprob_lp (glp_prob * P, int form, glp_graph * G, int names, int v_set, int a_cost){
    int debug;
    if (!__symbolic_glp_asnprob_lp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_asnprob_lp", (gpointer *) &__symbolic_glp_asnprob_lp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_asnprob_lp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_asnprob_lp.\n");
        }
    }
    return __symbolic_glp_asnprob_lp(P, form, G, names, v_set, a_cost);
}
int glp_asnprob_okalg (int form, glp_graph * G, int v_set, int a_cost, double *sol, int a_x){
    int debug;
    if (!__symbolic_glp_asnprob_okalg) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_asnprob_okalg", (gpointer *) &__symbolic_glp_asnprob_okalg)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_asnprob_okalg could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_asnprob_okalg.\n");
        }
    }
    return __symbolic_glp_asnprob_okalg(form, G, v_set, a_cost, sol, a_x);
}
int glp_asnprob_hall (glp_graph * G, int v_set, int a_x){
    int debug;
    if (!__symbolic_glp_asnprob_hall) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_asnprob_hall", (gpointer *) &__symbolic_glp_asnprob_hall)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_asnprob_hall could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_asnprob_hall.\n");
        }
    }
    return __symbolic_glp_asnprob_hall(G, v_set, a_x);
}
int glp_read_mincost (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, const char *fname){
    int debug;
    if (!__symbolic_glp_read_mincost) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_mincost", (gpointer *) &__symbolic_glp_read_mincost)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_mincost could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_mincost.\n");
        }
    }
    return __symbolic_glp_read_mincost(G, v_rhs, a_low, a_cap, a_cost, fname);
}
int glp_write_mincost (glp_graph * G, int v_rhs, int a_low, int a_cap, int a_cost, const char *fname){
    int debug;
    if (!__symbolic_glp_write_mincost) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_mincost", (gpointer *) &__symbolic_glp_write_mincost)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_mincost could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_mincost.\n");
        }
    }
    return __symbolic_glp_write_mincost(G, v_rhs, a_low, a_cap, a_cost, fname);
}
int glp_read_maxflow (glp_graph * G, int *s, int *t, int a_cap, const char *fname){
    int debug;
    if (!__symbolic_glp_read_maxflow) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_maxflow", (gpointer *) &__symbolic_glp_read_maxflow)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_maxflow could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_maxflow.\n");
        }
    }
    return __symbolic_glp_read_maxflow(G, s, t, a_cap, fname);
}
int glp_write_maxflow (glp_graph * G, int s, int t, int a_cap, const char *fname){
    int debug;
    if (!__symbolic_glp_write_maxflow) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_maxflow", (gpointer *) &__symbolic_glp_write_maxflow)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_maxflow could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_maxflow.\n");
        }
    }
    return __symbolic_glp_write_maxflow(G, s, t, a_cap, fname);
}
int glp_read_asnprob (glp_graph * G, int v_set, int a_cost, const char *fname){
    int debug;
    if (!__symbolic_glp_read_asnprob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_asnprob", (gpointer *) &__symbolic_glp_read_asnprob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_asnprob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_asnprob.\n");
        }
    }
    return __symbolic_glp_read_asnprob(G, v_set, a_cost, fname);
}
int glp_write_asnprob (glp_graph * G, int v_set, int a_cost, const char *fname){
    int debug;
    if (!__symbolic_glp_write_asnprob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_asnprob", (gpointer *) &__symbolic_glp_write_asnprob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_asnprob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_asnprob.\n");
        }
    }
    return __symbolic_glp_write_asnprob(G, v_set, a_cost, fname);
}
int glp_read_ccdata (glp_graph * G, int v_wgt, const char *fname){
    int debug;
    if (!__symbolic_glp_read_ccdata) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_read_ccdata", (gpointer *) &__symbolic_glp_read_ccdata)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_read_ccdata could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_read_ccdata.\n");
        }
    }
    return __symbolic_glp_read_ccdata(G, v_wgt, fname);
}
int glp_write_ccdata (glp_graph * G, int v_wgt, const char *fname){
    int debug;
    if (!__symbolic_glp_write_ccdata) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_write_ccdata", (gpointer *) &__symbolic_glp_write_ccdata)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_write_ccdata could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_write_ccdata.\n");
        }
    }
    return __symbolic_glp_write_ccdata(G, v_wgt, fname);
}
int glp_netgen (glp_graph * G, int v_rhs, int a_cap, int a_cost, const int parm[1 + 15]){
    int debug;
    if (!__symbolic_glp_netgen) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_netgen", (gpointer *) &__symbolic_glp_netgen)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_netgen could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_netgen.\n");
        }
    }
    return __symbolic_glp_netgen(G, v_rhs, a_cap, a_cost, parm);
}
int glp_gridgen (glp_graph * G, int v_rhs, int a_cap, int a_cost, const int parm[1 + 14]){
    int debug;
    if (!__symbolic_glp_gridgen) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_gridgen", (gpointer *) &__symbolic_glp_gridgen)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_gridgen could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_gridgen.\n");
        }
    }
    return __symbolic_glp_gridgen(G, v_rhs, a_cap, a_cost, parm);
}
int glp_rmfgen (glp_graph * G, int *s, int *t, int a_cap, const int parm[1 + 5]){
    int debug;
    if (!__symbolic_glp_rmfgen) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_rmfgen", (gpointer *) &__symbolic_glp_rmfgen)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_rmfgen could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_rmfgen.\n");
        }
    }
    return __symbolic_glp_rmfgen(G, s, t, a_cap, parm);
}
int glp_weak_comp (glp_graph * G, int v_num){
    int debug;
    if (!__symbolic_glp_weak_comp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_weak_comp", (gpointer *) &__symbolic_glp_weak_comp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_weak_comp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_weak_comp.\n");
        }
    }
    return __symbolic_glp_weak_comp(G, v_num);
}
int glp_strong_comp (glp_graph * G, int v_num){
    int debug;
    if (!__symbolic_glp_strong_comp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_strong_comp", (gpointer *) &__symbolic_glp_strong_comp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_strong_comp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_strong_comp.\n");
        }
    }
    return __symbolic_glp_strong_comp(G, v_num);
}
int glp_top_sort (glp_graph * G, int v_num){
    int debug;
    if (!__symbolic_glp_top_sort) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_top_sort", (gpointer *) &__symbolic_glp_top_sort)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_top_sort could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_top_sort.\n");
        }
    }
    return __symbolic_glp_top_sort(G, v_num);
}
int glp_wclique_exact (glp_graph * G, int v_wgt, double *sol, int v_set){
    int debug;
    if (!__symbolic_glp_wclique_exact) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "glp_wclique_exact", (gpointer *) &__symbolic_glp_wclique_exact)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol glp_wclique_exact could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol glp_wclique_exact.\n");
        }
    }
    return __symbolic_glp_wclique_exact(G, v_wgt, sol, v_set);
}
glp_prob *_glp_lpx_create_prob (void){
    int debug;
    if (!__symbolic__glp_lpx_create_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_create_prob", (gpointer *) &__symbolic__glp_lpx_create_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_create_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_create_prob.\n");
        }
    }
    return __symbolic__glp_lpx_create_prob();
}
void _glp_lpx_set_prob_name (glp_prob * lp, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_set_prob_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_prob_name", (gpointer *) &__symbolic__glp_lpx_set_prob_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_prob_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_prob_name.\n");
        }
    }
    return __symbolic__glp_lpx_set_prob_name(lp, name);
}
void _glp_lpx_set_obj_name (glp_prob * lp, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_set_obj_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_obj_name", (gpointer *) &__symbolic__glp_lpx_set_obj_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_obj_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_obj_name.\n");
        }
    }
    return __symbolic__glp_lpx_set_obj_name(lp, name);
}
void _glp_lpx_set_obj_dir (glp_prob * lp, int dir){
    int debug;
    if (!__symbolic__glp_lpx_set_obj_dir) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_obj_dir", (gpointer *) &__symbolic__glp_lpx_set_obj_dir)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_obj_dir could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_obj_dir.\n");
        }
    }
    return __symbolic__glp_lpx_set_obj_dir(lp, dir);
}
int _glp_lpx_add_rows (glp_prob * lp, int nrs){
    int debug;
    if (!__symbolic__glp_lpx_add_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_add_rows", (gpointer *) &__symbolic__glp_lpx_add_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_add_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_add_rows.\n");
        }
    }
    return __symbolic__glp_lpx_add_rows(lp, nrs);
}
int _glp_lpx_add_cols (glp_prob * lp, int ncs){
    int debug;
    if (!__symbolic__glp_lpx_add_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_add_cols", (gpointer *) &__symbolic__glp_lpx_add_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_add_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_add_cols.\n");
        }
    }
    return __symbolic__glp_lpx_add_cols(lp, ncs);
}
void _glp_lpx_set_row_name (glp_prob * lp, int i, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_set_row_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_row_name", (gpointer *) &__symbolic__glp_lpx_set_row_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_row_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_row_name.\n");
        }
    }
    return __symbolic__glp_lpx_set_row_name(lp, i, name);
}
void _glp_lpx_set_col_name (glp_prob * lp, int j, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_set_col_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_col_name", (gpointer *) &__symbolic__glp_lpx_set_col_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_col_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_col_name.\n");
        }
    }
    return __symbolic__glp_lpx_set_col_name(lp, j, name);
}
void _glp_lpx_set_row_bnds (glp_prob * lp, int i, int type, double lb, double ub){
    int debug;
    if (!__symbolic__glp_lpx_set_row_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_row_bnds", (gpointer *) &__symbolic__glp_lpx_set_row_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_row_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_row_bnds.\n");
        }
    }
    return __symbolic__glp_lpx_set_row_bnds(lp, i, type, lb, ub);
}
void _glp_lpx_set_col_bnds (glp_prob * lp, int j, int type, double lb, double ub){
    int debug;
    if (!__symbolic__glp_lpx_set_col_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_col_bnds", (gpointer *) &__symbolic__glp_lpx_set_col_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_col_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_col_bnds.\n");
        }
    }
    return __symbolic__glp_lpx_set_col_bnds(lp, j, type, lb, ub);
}
void _glp_lpx_set_obj_coef (glp_prob * lp, int j, double coef){
    int debug;
    if (!__symbolic__glp_lpx_set_obj_coef) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_obj_coef", (gpointer *) &__symbolic__glp_lpx_set_obj_coef)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_obj_coef could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_obj_coef.\n");
        }
    }
    return __symbolic__glp_lpx_set_obj_coef(lp, j, coef);
}
void _glp_lpx_set_mat_row (glp_prob * lp, int i, int len, const int ind[], const double val[]){
    int debug;
    if (!__symbolic__glp_lpx_set_mat_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_mat_row", (gpointer *) &__symbolic__glp_lpx_set_mat_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_mat_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_mat_row.\n");
        }
    }
    return __symbolic__glp_lpx_set_mat_row(lp, i, len, ind, val);
}
void _glp_lpx_set_mat_col (glp_prob * lp, int j, int len, const int ind[], const double val[]){
    int debug;
    if (!__symbolic__glp_lpx_set_mat_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_mat_col", (gpointer *) &__symbolic__glp_lpx_set_mat_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_mat_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_mat_col.\n");
        }
    }
    return __symbolic__glp_lpx_set_mat_col(lp, j, len, ind, val);
}
void _glp_lpx_load_matrix (glp_prob * lp, int ne, const int ia[], const int ja[], const double ar[]){
    int debug;
    if (!__symbolic__glp_lpx_load_matrix) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_load_matrix", (gpointer *) &__symbolic__glp_lpx_load_matrix)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_load_matrix could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_load_matrix.\n");
        }
    }
    return __symbolic__glp_lpx_load_matrix(lp, ne, ia, ja, ar);
}
void _glp_lpx_del_rows (glp_prob * lp, int nrs, const int num[]){
    int debug;
    if (!__symbolic__glp_lpx_del_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_del_rows", (gpointer *) &__symbolic__glp_lpx_del_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_del_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_del_rows.\n");
        }
    }
    return __symbolic__glp_lpx_del_rows(lp, nrs, num);
}
void _glp_lpx_del_cols (glp_prob * lp, int ncs, const int num[]){
    int debug;
    if (!__symbolic__glp_lpx_del_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_del_cols", (gpointer *) &__symbolic__glp_lpx_del_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_del_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_del_cols.\n");
        }
    }
    return __symbolic__glp_lpx_del_cols(lp, ncs, num);
}
void _glp_lpx_delete_prob (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_delete_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_delete_prob", (gpointer *) &__symbolic__glp_lpx_delete_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_delete_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_delete_prob.\n");
        }
    }
    return __symbolic__glp_lpx_delete_prob(lp);
}
const char *_glp_lpx_get_prob_name (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_prob_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_prob_name", (gpointer *) &__symbolic__glp_lpx_get_prob_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_prob_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_prob_name.\n");
        }
    }
    return __symbolic__glp_lpx_get_prob_name(lp);
}
const char *_glp_lpx_get_obj_name (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_obj_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_obj_name", (gpointer *) &__symbolic__glp_lpx_get_obj_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_obj_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_obj_name.\n");
        }
    }
    return __symbolic__glp_lpx_get_obj_name(lp);
}
int _glp_lpx_get_obj_dir (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_obj_dir) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_obj_dir", (gpointer *) &__symbolic__glp_lpx_get_obj_dir)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_obj_dir could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_obj_dir.\n");
        }
    }
    return __symbolic__glp_lpx_get_obj_dir(lp);
}
int _glp_lpx_get_num_rows (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_num_rows) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_num_rows", (gpointer *) &__symbolic__glp_lpx_get_num_rows)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_num_rows could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_num_rows.\n");
        }
    }
    return __symbolic__glp_lpx_get_num_rows(lp);
}
int _glp_lpx_get_num_cols (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_num_cols) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_num_cols", (gpointer *) &__symbolic__glp_lpx_get_num_cols)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_num_cols could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_num_cols.\n");
        }
    }
    return __symbolic__glp_lpx_get_num_cols(lp);
}
const char *_glp_lpx_get_row_name (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_name", (gpointer *) &__symbolic__glp_lpx_get_row_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_name.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_name(lp, i);
}
const char *_glp_lpx_get_col_name (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_name) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_name", (gpointer *) &__symbolic__glp_lpx_get_col_name)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_name could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_name.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_name(lp, j);
}
int _glp_lpx_get_row_type (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_type) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_type", (gpointer *) &__symbolic__glp_lpx_get_row_type)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_type could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_type.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_type(lp, i);
}
double _glp_lpx_get_row_lb (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_lb) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_lb", (gpointer *) &__symbolic__glp_lpx_get_row_lb)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_lb could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_lb.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_lb(lp, i);
}
double _glp_lpx_get_row_ub (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_ub) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_ub", (gpointer *) &__symbolic__glp_lpx_get_row_ub)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_ub could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_ub.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_ub(lp, i);
}
void _glp_lpx_get_row_bnds (glp_prob * lp, int i, int *typx, double *lb, double *ub){
    int debug;
    if (!__symbolic__glp_lpx_get_row_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_bnds", (gpointer *) &__symbolic__glp_lpx_get_row_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_bnds.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_bnds(lp, i, typx, lb, ub);
}
int _glp_lpx_get_col_type (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_type) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_type", (gpointer *) &__symbolic__glp_lpx_get_col_type)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_type could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_type.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_type(lp, j);
}
double _glp_lpx_get_col_lb (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_lb) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_lb", (gpointer *) &__symbolic__glp_lpx_get_col_lb)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_lb could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_lb.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_lb(lp, j);
}
double _glp_lpx_get_col_ub (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_ub) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_ub", (gpointer *) &__symbolic__glp_lpx_get_col_ub)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_ub could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_ub.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_ub(lp, j);
}
void _glp_lpx_get_col_bnds (glp_prob * lp, int j, int *typx, double *lb, double *ub){
    int debug;
    if (!__symbolic__glp_lpx_get_col_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_bnds", (gpointer *) &__symbolic__glp_lpx_get_col_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_bnds.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_bnds(lp, j, typx, lb, ub);
}
double _glp_lpx_get_obj_coef (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_obj_coef) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_obj_coef", (gpointer *) &__symbolic__glp_lpx_get_obj_coef)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_obj_coef could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_obj_coef.\n");
        }
    }
    return __symbolic__glp_lpx_get_obj_coef(lp, j);
}
int _glp_lpx_get_num_nz (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_num_nz) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_num_nz", (gpointer *) &__symbolic__glp_lpx_get_num_nz)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_num_nz could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_num_nz.\n");
        }
    }
    return __symbolic__glp_lpx_get_num_nz(lp);
}
int _glp_lpx_get_mat_row (glp_prob * lp, int i, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_get_mat_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_mat_row", (gpointer *) &__symbolic__glp_lpx_get_mat_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_mat_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_mat_row.\n");
        }
    }
    return __symbolic__glp_lpx_get_mat_row(lp, i, ind, val);
}
int _glp_lpx_get_mat_col (glp_prob * lp, int j, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_get_mat_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_mat_col", (gpointer *) &__symbolic__glp_lpx_get_mat_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_mat_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_mat_col.\n");
        }
    }
    return __symbolic__glp_lpx_get_mat_col(lp, j, ind, val);
}
void _glp_lpx_create_index (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_create_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_create_index", (gpointer *) &__symbolic__glp_lpx_create_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_create_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_create_index.\n");
        }
    }
    return __symbolic__glp_lpx_create_index(lp);
}
int _glp_lpx_find_row (glp_prob * lp, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_find_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_find_row", (gpointer *) &__symbolic__glp_lpx_find_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_find_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_find_row.\n");
        }
    }
    return __symbolic__glp_lpx_find_row(lp, name);
}
int _glp_lpx_find_col (glp_prob * lp, const char *name){
    int debug;
    if (!__symbolic__glp_lpx_find_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_find_col", (gpointer *) &__symbolic__glp_lpx_find_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_find_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_find_col.\n");
        }
    }
    return __symbolic__glp_lpx_find_col(lp, name);
}
void _glp_lpx_delete_index (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_delete_index) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_delete_index", (gpointer *) &__symbolic__glp_lpx_delete_index)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_delete_index could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_delete_index.\n");
        }
    }
    return __symbolic__glp_lpx_delete_index(lp);
}
void _glp_lpx_scale_prob (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_scale_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_scale_prob", (gpointer *) &__symbolic__glp_lpx_scale_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_scale_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_scale_prob.\n");
        }
    }
    return __symbolic__glp_lpx_scale_prob(lp);
}
void _glp_lpx_unscale_prob (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_unscale_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_unscale_prob", (gpointer *) &__symbolic__glp_lpx_unscale_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_unscale_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_unscale_prob.\n");
        }
    }
    return __symbolic__glp_lpx_unscale_prob(lp);
}
void _glp_lpx_set_row_stat (glp_prob * lp, int i, int stat){
    int debug;
    if (!__symbolic__glp_lpx_set_row_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_row_stat", (gpointer *) &__symbolic__glp_lpx_set_row_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_row_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_row_stat.\n");
        }
    }
    return __symbolic__glp_lpx_set_row_stat(lp, i, stat);
}
void _glp_lpx_set_col_stat (glp_prob * lp, int j, int stat){
    int debug;
    if (!__symbolic__glp_lpx_set_col_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_col_stat", (gpointer *) &__symbolic__glp_lpx_set_col_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_col_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_col_stat.\n");
        }
    }
    return __symbolic__glp_lpx_set_col_stat(lp, j, stat);
}
void _glp_lpx_std_basis (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_std_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_std_basis", (gpointer *) &__symbolic__glp_lpx_std_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_std_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_std_basis.\n");
        }
    }
    return __symbolic__glp_lpx_std_basis(lp);
}
void _glp_lpx_adv_basis (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_adv_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_adv_basis", (gpointer *) &__symbolic__glp_lpx_adv_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_adv_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_adv_basis.\n");
        }
    }
    return __symbolic__glp_lpx_adv_basis(lp);
}
void _glp_lpx_cpx_basis (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_cpx_basis) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_cpx_basis", (gpointer *) &__symbolic__glp_lpx_cpx_basis)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_cpx_basis could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_cpx_basis.\n");
        }
    }
    return __symbolic__glp_lpx_cpx_basis(lp);
}
int _glp_lpx_simplex (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_simplex) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_simplex", (gpointer *) &__symbolic__glp_lpx_simplex)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_simplex could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_simplex.\n");
        }
    }
    return __symbolic__glp_lpx_simplex(lp);
}
int _glp_lpx_exact (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_exact) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_exact", (gpointer *) &__symbolic__glp_lpx_exact)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_exact could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_exact.\n");
        }
    }
    return __symbolic__glp_lpx_exact(lp);
}
int _glp_lpx_get_status (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_status", (gpointer *) &__symbolic__glp_lpx_get_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_status.\n");
        }
    }
    return __symbolic__glp_lpx_get_status(lp);
}
int _glp_lpx_get_prim_stat (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_prim_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_prim_stat", (gpointer *) &__symbolic__glp_lpx_get_prim_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_prim_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_prim_stat.\n");
        }
    }
    return __symbolic__glp_lpx_get_prim_stat(lp);
}
int _glp_lpx_get_dual_stat (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_dual_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_dual_stat", (gpointer *) &__symbolic__glp_lpx_get_dual_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_dual_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_dual_stat.\n");
        }
    }
    return __symbolic__glp_lpx_get_dual_stat(lp);
}
double _glp_lpx_get_obj_val (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_obj_val", (gpointer *) &__symbolic__glp_lpx_get_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_obj_val.\n");
        }
    }
    return __symbolic__glp_lpx_get_obj_val(lp);
}
int _glp_lpx_get_row_stat (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_stat", (gpointer *) &__symbolic__glp_lpx_get_row_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_stat.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_stat(lp, i);
}
double _glp_lpx_get_row_prim (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_prim", (gpointer *) &__symbolic__glp_lpx_get_row_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_prim.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_prim(lp, i);
}
double _glp_lpx_get_row_dual (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_get_row_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_dual", (gpointer *) &__symbolic__glp_lpx_get_row_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_dual.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_dual(lp, i);
}
void _glp_lpx_get_row_info (glp_prob * lp, int i, int *tagx, double *vx, double *dx){
    int debug;
    if (!__symbolic__glp_lpx_get_row_info) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_row_info", (gpointer *) &__symbolic__glp_lpx_get_row_info)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_row_info could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_row_info.\n");
        }
    }
    return __symbolic__glp_lpx_get_row_info(lp, i, tagx, vx, dx);
}
int _glp_lpx_get_col_stat (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_stat) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_stat", (gpointer *) &__symbolic__glp_lpx_get_col_stat)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_stat could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_stat.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_stat(lp, j);
}
double _glp_lpx_get_col_prim (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_prim", (gpointer *) &__symbolic__glp_lpx_get_col_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_prim.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_prim(lp, j);
}
double _glp_lpx_get_col_dual (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_dual", (gpointer *) &__symbolic__glp_lpx_get_col_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_dual.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_dual(lp, j);
}
void _glp_lpx_get_col_info (glp_prob * lp, int j, int *tagx, double *vx, double *dx){
    int debug;
    if (!__symbolic__glp_lpx_get_col_info) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_info", (gpointer *) &__symbolic__glp_lpx_get_col_info)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_info could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_info.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_info(lp, j, tagx, vx, dx);
}
int _glp_lpx_get_ray_info (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_ray_info) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_ray_info", (gpointer *) &__symbolic__glp_lpx_get_ray_info)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_ray_info could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_ray_info.\n");
        }
    }
    return __symbolic__glp_lpx_get_ray_info(lp);
}
void _glp_lpx_check_kkt (glp_prob * lp, int scaled, LPXKKT * kkt){
    int debug;
    if (!__symbolic__glp_lpx_check_kkt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_check_kkt", (gpointer *) &__symbolic__glp_lpx_check_kkt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_check_kkt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_check_kkt.\n");
        }
    }
    return __symbolic__glp_lpx_check_kkt(lp, scaled, kkt);
}
int _glp_lpx_warm_up (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_warm_up) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_warm_up", (gpointer *) &__symbolic__glp_lpx_warm_up)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_warm_up could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_warm_up.\n");
        }
    }
    return __symbolic__glp_lpx_warm_up(lp);
}
int _glp_lpx_eval_tab_row (glp_prob * lp, int k, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_eval_tab_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_eval_tab_row", (gpointer *) &__symbolic__glp_lpx_eval_tab_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_eval_tab_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_eval_tab_row.\n");
        }
    }
    return __symbolic__glp_lpx_eval_tab_row(lp, k, ind, val);
}
int _glp_lpx_eval_tab_col (glp_prob * lp, int k, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_eval_tab_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_eval_tab_col", (gpointer *) &__symbolic__glp_lpx_eval_tab_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_eval_tab_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_eval_tab_col.\n");
        }
    }
    return __symbolic__glp_lpx_eval_tab_col(lp, k, ind, val);
}
int _glp_lpx_transform_row (glp_prob * lp, int len, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_transform_row) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_transform_row", (gpointer *) &__symbolic__glp_lpx_transform_row)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_transform_row could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_transform_row.\n");
        }
    }
    return __symbolic__glp_lpx_transform_row(lp, len, ind, val);
}
int _glp_lpx_transform_col (glp_prob * lp, int len, int ind[], double val[]){
    int debug;
    if (!__symbolic__glp_lpx_transform_col) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_transform_col", (gpointer *) &__symbolic__glp_lpx_transform_col)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_transform_col could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_transform_col.\n");
        }
    }
    return __symbolic__glp_lpx_transform_col(lp, len, ind, val);
}
int _glp_lpx_prim_ratio_test (glp_prob * lp, int len, const int ind[], const double val[], int how, double tol){
    int debug;
    if (!__symbolic__glp_lpx_prim_ratio_test) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_prim_ratio_test", (gpointer *) &__symbolic__glp_lpx_prim_ratio_test)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_prim_ratio_test could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_prim_ratio_test.\n");
        }
    }
    return __symbolic__glp_lpx_prim_ratio_test(lp, len, ind, val, how, tol);
}
int _glp_lpx_dual_ratio_test (glp_prob * lp, int len, const int ind[], const double val[], int how, double tol){
    int debug;
    if (!__symbolic__glp_lpx_dual_ratio_test) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_dual_ratio_test", (gpointer *) &__symbolic__glp_lpx_dual_ratio_test)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_dual_ratio_test could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_dual_ratio_test.\n");
        }
    }
    return __symbolic__glp_lpx_dual_ratio_test(lp, len, ind, val, how, tol);
}
int _glp_lpx_interior (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_interior) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_interior", (gpointer *) &__symbolic__glp_lpx_interior)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_interior could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_interior.\n");
        }
    }
    return __symbolic__glp_lpx_interior(lp);
}
int _glp_lpx_ipt_status (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_ipt_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_status", (gpointer *) &__symbolic__glp_lpx_ipt_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_status.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_status(lp);
}
double _glp_lpx_ipt_obj_val (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_ipt_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_obj_val", (gpointer *) &__symbolic__glp_lpx_ipt_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_obj_val.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_obj_val(lp);
}
double _glp_lpx_ipt_row_prim (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_ipt_row_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_row_prim", (gpointer *) &__symbolic__glp_lpx_ipt_row_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_row_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_row_prim.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_row_prim(lp, i);
}
double _glp_lpx_ipt_row_dual (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_ipt_row_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_row_dual", (gpointer *) &__symbolic__glp_lpx_ipt_row_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_row_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_row_dual.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_row_dual(lp, i);
}
double _glp_lpx_ipt_col_prim (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_ipt_col_prim) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_col_prim", (gpointer *) &__symbolic__glp_lpx_ipt_col_prim)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_col_prim could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_col_prim.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_col_prim(lp, j);
}
double _glp_lpx_ipt_col_dual (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_ipt_col_dual) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_ipt_col_dual", (gpointer *) &__symbolic__glp_lpx_ipt_col_dual)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_ipt_col_dual could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_ipt_col_dual.\n");
        }
    }
    return __symbolic__glp_lpx_ipt_col_dual(lp, j);
}
void _glp_lpx_set_class (glp_prob * lp, int klass){
    int debug;
    if (!__symbolic__glp_lpx_set_class) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_class", (gpointer *) &__symbolic__glp_lpx_set_class)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_class could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_class.\n");
        }
    }
    return __symbolic__glp_lpx_set_class(lp, klass);
}
int _glp_lpx_get_class (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_class) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_class", (gpointer *) &__symbolic__glp_lpx_get_class)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_class could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_class.\n");
        }
    }
    return __symbolic__glp_lpx_get_class(lp);
}
void _glp_lpx_set_col_kind (glp_prob * lp, int j, int kind){
    int debug;
    if (!__symbolic__glp_lpx_set_col_kind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_col_kind", (gpointer *) &__symbolic__glp_lpx_set_col_kind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_col_kind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_col_kind.\n");
        }
    }
    return __symbolic__glp_lpx_set_col_kind(lp, j, kind);
}
int _glp_lpx_get_col_kind (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_get_col_kind) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_col_kind", (gpointer *) &__symbolic__glp_lpx_get_col_kind)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_col_kind could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_col_kind.\n");
        }
    }
    return __symbolic__glp_lpx_get_col_kind(lp, j);
}
int _glp_lpx_get_num_int (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_num_int) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_num_int", (gpointer *) &__symbolic__glp_lpx_get_num_int)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_num_int could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_num_int.\n");
        }
    }
    return __symbolic__glp_lpx_get_num_int(lp);
}
int _glp_lpx_get_num_bin (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_get_num_bin) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_num_bin", (gpointer *) &__symbolic__glp_lpx_get_num_bin)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_num_bin could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_num_bin.\n");
        }
    }
    return __symbolic__glp_lpx_get_num_bin(lp);
}
int _glp_lpx_integer (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_integer) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_integer", (gpointer *) &__symbolic__glp_lpx_integer)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_integer could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_integer.\n");
        }
    }
    return __symbolic__glp_lpx_integer(lp);
}
int _glp_lpx_intopt (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_intopt) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_intopt", (gpointer *) &__symbolic__glp_lpx_intopt)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_intopt could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_intopt.\n");
        }
    }
    return __symbolic__glp_lpx_intopt(lp);
}
int _glp_lpx_mip_status (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_mip_status) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_mip_status", (gpointer *) &__symbolic__glp_lpx_mip_status)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_mip_status could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_mip_status.\n");
        }
    }
    return __symbolic__glp_lpx_mip_status(lp);
}
double _glp_lpx_mip_obj_val (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_mip_obj_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_mip_obj_val", (gpointer *) &__symbolic__glp_lpx_mip_obj_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_mip_obj_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_mip_obj_val.\n");
        }
    }
    return __symbolic__glp_lpx_mip_obj_val(lp);
}
double _glp_lpx_mip_row_val (glp_prob * lp, int i){
    int debug;
    if (!__symbolic__glp_lpx_mip_row_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_mip_row_val", (gpointer *) &__symbolic__glp_lpx_mip_row_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_mip_row_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_mip_row_val.\n");
        }
    }
    return __symbolic__glp_lpx_mip_row_val(lp, i);
}
double _glp_lpx_mip_col_val (glp_prob * lp, int j){
    int debug;
    if (!__symbolic__glp_lpx_mip_col_val) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_mip_col_val", (gpointer *) &__symbolic__glp_lpx_mip_col_val)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_mip_col_val could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_mip_col_val.\n");
        }
    }
    return __symbolic__glp_lpx_mip_col_val(lp, j);
}
void _glp_lpx_check_int (glp_prob * lp, LPXKKT * kkt){
    int debug;
    if (!__symbolic__glp_lpx_check_int) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_check_int", (gpointer *) &__symbolic__glp_lpx_check_int)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_check_int could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_check_int.\n");
        }
    }
    return __symbolic__glp_lpx_check_int(lp, kkt);
}
void _glp_lpx_reset_parms (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_reset_parms) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_reset_parms", (gpointer *) &__symbolic__glp_lpx_reset_parms)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_reset_parms could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_reset_parms.\n");
        }
    }
    return __symbolic__glp_lpx_reset_parms(lp);
}
void _glp_lpx_set_int_parm (glp_prob * lp, int parm, int val){
    int debug;
    if (!__symbolic__glp_lpx_set_int_parm) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_int_parm", (gpointer *) &__symbolic__glp_lpx_set_int_parm)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_int_parm could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_int_parm.\n");
        }
    }
    return __symbolic__glp_lpx_set_int_parm(lp, parm, val);
}
int _glp_lpx_get_int_parm (glp_prob * lp, int parm){
    int debug;
    if (!__symbolic__glp_lpx_get_int_parm) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_int_parm", (gpointer *) &__symbolic__glp_lpx_get_int_parm)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_int_parm could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_int_parm.\n");
        }
    }
    return __symbolic__glp_lpx_get_int_parm(lp, parm);
}
void _glp_lpx_set_real_parm (glp_prob * lp, int parm, double val){
    int debug;
    if (!__symbolic__glp_lpx_set_real_parm) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_set_real_parm", (gpointer *) &__symbolic__glp_lpx_set_real_parm)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_set_real_parm could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_set_real_parm.\n");
        }
    }
    return __symbolic__glp_lpx_set_real_parm(lp, parm, val);
}
double _glp_lpx_get_real_parm (glp_prob * lp, int parm){
    int debug;
    if (!__symbolic__glp_lpx_get_real_parm) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_get_real_parm", (gpointer *) &__symbolic__glp_lpx_get_real_parm)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_get_real_parm could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_get_real_parm.\n");
        }
    }
    return __symbolic__glp_lpx_get_real_parm(lp, parm);
}
glp_prob *_glp_lpx_read_mps (const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_read_mps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_read_mps", (gpointer *) &__symbolic__glp_lpx_read_mps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_read_mps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_read_mps.\n");
        }
    }
    return __symbolic__glp_lpx_read_mps(fname);
}
int _glp_lpx_write_mps (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_write_mps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_write_mps", (gpointer *) &__symbolic__glp_lpx_write_mps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_write_mps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_write_mps.\n");
        }
    }
    return __symbolic__glp_lpx_write_mps(lp, fname);
}
int _glp_lpx_read_bas (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_read_bas) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_read_bas", (gpointer *) &__symbolic__glp_lpx_read_bas)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_read_bas could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_read_bas.\n");
        }
    }
    return __symbolic__glp_lpx_read_bas(lp, fname);
}
int _glp_lpx_write_bas (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_write_bas) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_write_bas", (gpointer *) &__symbolic__glp_lpx_write_bas)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_write_bas could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_write_bas.\n");
        }
    }
    return __symbolic__glp_lpx_write_bas(lp, fname);
}
glp_prob *_glp_lpx_read_freemps (const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_read_freemps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_read_freemps", (gpointer *) &__symbolic__glp_lpx_read_freemps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_read_freemps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_read_freemps.\n");
        }
    }
    return __symbolic__glp_lpx_read_freemps(fname);
}
int _glp_lpx_write_freemps (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_write_freemps) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_write_freemps", (gpointer *) &__symbolic__glp_lpx_write_freemps)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_write_freemps could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_write_freemps.\n");
        }
    }
    return __symbolic__glp_lpx_write_freemps(lp, fname);
}
glp_prob *_glp_lpx_read_cpxlp (const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_read_cpxlp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_read_cpxlp", (gpointer *) &__symbolic__glp_lpx_read_cpxlp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_read_cpxlp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_read_cpxlp.\n");
        }
    }
    return __symbolic__glp_lpx_read_cpxlp(fname);
}
int _glp_lpx_write_cpxlp (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_write_cpxlp) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_write_cpxlp", (gpointer *) &__symbolic__glp_lpx_write_cpxlp)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_write_cpxlp could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_write_cpxlp.\n");
        }
    }
    return __symbolic__glp_lpx_write_cpxlp(lp, fname);
}
glp_prob *_glp_lpx_read_model (const char *model, const char *data, const char *output){
    int debug;
    if (!__symbolic__glp_lpx_read_model) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_read_model", (gpointer *) &__symbolic__glp_lpx_read_model)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_read_model could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_read_model.\n");
        }
    }
    return __symbolic__glp_lpx_read_model(model, data, output);
}
int _glp_lpx_print_prob (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_print_prob) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_print_prob", (gpointer *) &__symbolic__glp_lpx_print_prob)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_print_prob could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_print_prob.\n");
        }
    }
    return __symbolic__glp_lpx_print_prob(lp, fname);
}
int _glp_lpx_print_sol (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_print_sol) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_print_sol", (gpointer *) &__symbolic__glp_lpx_print_sol)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_print_sol could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_print_sol.\n");
        }
    }
    return __symbolic__glp_lpx_print_sol(lp, fname);
}
int _glp_lpx_print_sens_bnds (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_print_sens_bnds) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_print_sens_bnds", (gpointer *) &__symbolic__glp_lpx_print_sens_bnds)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_print_sens_bnds could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_print_sens_bnds.\n");
        }
    }
    return __symbolic__glp_lpx_print_sens_bnds(lp, fname);
}
int _glp_lpx_print_ips (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_print_ips) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_print_ips", (gpointer *) &__symbolic__glp_lpx_print_ips)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_print_ips could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_print_ips.\n");
        }
    }
    return __symbolic__glp_lpx_print_ips(lp, fname);
}
int _glp_lpx_print_mip (glp_prob * lp, const char *fname){
    int debug;
    if (!__symbolic__glp_lpx_print_mip) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_print_mip", (gpointer *) &__symbolic__glp_lpx_print_mip)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_print_mip could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_print_mip.\n");
        }
    }
    return __symbolic__glp_lpx_print_mip(lp, fname);
}
int _glp_lpx_is_b_avail (glp_prob * lp){
    int debug;
    if (!__symbolic__glp_lpx_is_b_avail) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_is_b_avail", (gpointer *) &__symbolic__glp_lpx_is_b_avail)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_is_b_avail could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_is_b_avail.\n");
        }
    }
    return __symbolic__glp_lpx_is_b_avail(lp);
}
int _glp_lpx_write_pb (glp_prob * lp, const char *fname, int normalized, int binarize){
    int debug;
    if (!__symbolic__glp_lpx_write_pb) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_write_pb", (gpointer *) &__symbolic__glp_lpx_write_pb)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_write_pb could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_write_pb.\n");
        }
    }
    return __symbolic__glp_lpx_write_pb(lp, fname, normalized, binarize);
}
int _glp_lpx_main (int argc, const char *argv[]){
    int debug;
    if (!__symbolic__glp_lpx_main) {
        debug = debug_enabled();
        if (!module) {
            if (debug) fprintf (stderr, "lazylpsolverlibs: looking for a suitable library in the standard system path\n");
            if (!load_module()) {
                if (debug) fprintf (stderr, "lazylpsolverlibs: library lookup failed!\n");
                fprintf(stderr,
                "lazylpsolverlibs: could not load library. Suggestions:\n");
                fprintf(stderr,
                " - point the LAZYLPSOLVERLIBS_GLPK_LIB environment variable to the full path of the library\n");
                fprintf(stderr,
                " - or more secure, symlink /usr/lib/libglpk.so to the full path of the library (you need root access).\n");
            } else {
                if (debug) fprintf(stderr,"lazylpsolverlibs: Success!\n");
            }
        }
        if (!g_module_symbol(module, "_glp_lpx_main", (gpointer *) &__symbolic__glp_lpx_main)) {
            fprintf(stderr,
                "lazylpsolverlibs: the symbol _glp_lpx_main could not be found! Exiting your program to avoid a segfault.\n");
                exit(1);
        } else {
            if (debug) fprintf(stderr, "lazylpsolverlibs: sucessfully imported the symbol _glp_lpx_main.\n");
        }
    }
    return __symbolic__glp_lpx_main(argc, argv);
}
