#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>

#include "linalg_cblas.h"
#include "macros.h"


static void* library_handle = NULL;


typedef void (*ptr_cblas_zdotc_sub)
    (const int N, const void *X, const int incX,
     const void *Y, const int incY, void *dotc);

typedef void (*ptr_cblas_dgemm)
    (const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
     const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
     const int K, const double alpha, const double *A,
     const int lda, const double *B, const int ldb,
     const double beta, double *C, const int ldc);


static ptr_cblas_zdotc_sub cblas_zdotc_sub_implementation = NULL;
static ptr_cblas_dgemm     cblas_dgemm_implementation = NULL;


void init_cblas(void)
{
    cblas_zdotc_sub_implementation = (ptr_cblas_zdotc_sub)
      dlsym(library_handle, "cblas_zdotc_sub");
    cblas_dgemm_implementation = (ptr_cblas_dgemm)
      dlsym(library_handle, "cblas_dgemm");
    printf("Address of cblas_zdotc_sub: %x\n", cblas_zdotc_sub_implementation);
    printf("Address of cblas_dgemm: %x\n", cblas_dgemm_implementation);
}


LINEAR_ALGEBRA_CONSTRUCTOR
void init(void) { 
  // const char *library_name = "libcblas.so";
  const char *library_name = "libgslcblas.so";
  library_handle = dlopen(library_name, RTLD_LAZY);
  if (library_handle == NULL) {
    fprintf(stderr, "Unable to load library %s, got %s.", library_name, dlerror());
  } else {
    init_cblas();
  }
}


LINEAR_ALGEBRA_DESTRUCTOR
void fini(void) {
  printf("destructor\n");
  if (library_handle != NULL)
    dlclose(library_handle);
}


LINEAR_ALGEBRA_EXPORTED_SYMBOL
void cblas_zdotc_sub(const int N, const void *X, const int incX,
                     const void *Y, const int incY, void *dotc)
{
  cblas_zdotc_sub_implementation(N, X, incX, 
                                 Y, incY, dotc);
}


LINEAR_ALGEBRA_EXPORTED_SYMBOL
void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc)
{
  cblas_dgemm_implementation(Order, TransA, 
                             TransB, M, N, 
                             K, alpha, A, 
                             lda, B, ldb, 
                             beta, C, ldc);
}