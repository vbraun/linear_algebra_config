#include <linalg_cblas.h>
#include <malloc.h>

/* 
 * Test that we can load and use liblinalg_cblas without falling flat
 * on our face. No tests for mathematical correctness.
 *
 */


typedef struct{ double re; double im; } double_complex;

void blas_level_1() {
  const int N = 10;
  int n, inc_a = 1, inc_b = 1;
  double_complex a[N], b[N], c;
  for (int i = 0; i < N; i++ ) {
    a[i].re = i; 
    a[i].im = 2*i;
    b[i].re = N-i; 
    b[i].im = 2*i;
  }
  cblas_zdotc_sub(N, a, inc_a, b, inc_b, &c);
}


void blas_level_3() {
  int n = 44;
  int m = 88;
  double *A = (double*) malloc(n*n*sizeof(double));
  double *B = (double*) malloc(n*m*sizeof(double));
  double *C = (double*) malloc(n*m*sizeof(double));
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
              n, m, n, 1.0, 
              A, n, B, m, 
              0.0, C, m);
}


int main(void) {
  blas_level_1();
  blas_level_3();
  return 0;
}
