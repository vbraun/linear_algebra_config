#include <dlfcn.h>
#include <stdio.h>

#define LINALG_NAME "linalg_f77blas"

#include "linalg_f77blas.h"
#include "macros.h"
#include "setup.h"



static void* library_handle = NULL;


typedef Z_f (*ptr_zdotc)
    (doublecomplex * ret_val, integer *n, doublecomplex *zx, 
     integer *incx, doublecomplex *zy, integer *incy);

typedef int (*ptr_dgemm)
    (char *transa, char *transb, integer *m, integer *n, integer *k, 
     doublereal *alpha, doublereal *a, integer *lda, doublereal *b, 
     integer *ldb, doublereal *beta, doublereal *c, integer *ldc);

static ptr_zdotc zdotc_implementation = NULL;
static ptr_dgemm dgemm_implementation = NULL;


void init_f77blas()
{
    zdotc_implementation = (ptr_zdotc)
      dlsym(library_handle, "zdotc_");
    dgemm_implementation = (ptr_dgemm)
      dlsym(library_handle, "dgemm_");
    printf("Address of zdotc: %x\n", zdotc_implementation);
    printf("Address of dgemm: %x\n", dgemm_implementation);
}


LINEAR_ALGEBRA_CONSTRUCTOR
void init() { 
  const char *library_name = get_library_name();
  if (library_name == NULL) {
    fprintf(stderr, LINALG_NAME ": No Fortran BLAS implementation found.\n");
    return;
  }
  library_handle = dlopen(library_name, RTLD_LAZY);
  if (library_handle == NULL) {
    fprintf(stderr, LINALG_NAME ": %s.\n", dlerror());
  } else {
    init_f77blas();
  }
}


LINEAR_ALGEBRA_DESTRUCTOR
void fini() {
  printf("destructor\n");
  if (library_handle != NULL)
    dlclose(library_handle);
}



LINEAR_ALGEBRA_EXPORTED_SYMBOL
Z_f zdotc_(doublecomplex * ret_val, integer *n, doublecomplex *zx, 
           integer *incx, doublecomplex *zy, integer *incy)
{
  zdotc_implementation(ret_val, n, zx, incx, zy, incy);
}



LINEAR_ALGEBRA_EXPORTED_SYMBOL
int dgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, 
           doublereal *alpha, doublereal *a, integer *lda, doublereal *b, 
           integer *ldb, doublereal *beta, doublereal *c, integer *ldc)
{
  return dgemm_implementation(transa, transb, m, n, k, 
                              alpha, a, lda, b, 
                              ldb, beta, c, ldc);
}
