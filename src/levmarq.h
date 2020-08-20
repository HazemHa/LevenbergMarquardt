#pragma once



#ifdef LBM_STATIC
#define LBM_API static
#else
#define LBM_API extern
#endif


#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
  int verbose;
  int max_it;
  double init_lambda;
  double up_factor;
  double down_factor;
  double target_derr;
  int final_it;
  double final_err;
  double final_derr;
} LMstat;

LBM_API void levmarq_init(LMstat *lmstat);

LBM_API int levmarq(int npar, double *par, int ny, double *y, double *dysq,
        double (*func)(double *, double, void *),
        void (*grad)(double *, double *, double, void *),
	    void *fdata, LMstat *lmstat);

LBM_API double error_func(double *par, int ny, double *y, double *dysq,
          double (*func)(double *, double, void *), void *fdata);

LBM_API void solve_axb_cholesky(int n, double *l , double *x , double *b );

LBM_API int cholesky_decomp(int n, double *l, double *a);



#ifdef __cplusplus
}
#endif
