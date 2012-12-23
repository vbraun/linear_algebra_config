#ifndef LINEAR_ALGEBRA_F77BLAS__H
#define LINEAR_ALGEBRA_F77BLAS__H

/* C headers for the Fortran 77 BLAS interface
 *
 * You should be using the CBLAS interface if you write C code, of
 * course.
 *
 * Functions are ordered as in the Fortran BLAS quick reference card
 * with prefixes _(s, d, c, z) as appropriate.
 * 
 * The names have all a trailing underscore, which is a convention
 * followed by most Fortran compilers.
 */


typedef long int integer;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;

#define VOID void
typedef VOID C_f;
typedef VOID H_f;
typedef VOID Z_f;
typedef doublereal E_f;


/*
 * ===========================================================================
 * Prototypes for level 1 BLAS routines
 * ===========================================================================
 */

int srotg_(real *sa, real *sb, real *c__, real *s);
int drotg_(doublereal *da, doublereal *db, doublereal *c__, doublereal *s);
int crotg_(complex *ca, complex *cb, real *c__, complex *s);
int zrotg_(doublecomplex *ca, doublecomplex *cb, doublereal *c__, doublecomplex *s);

int srot_(integer *n, real *sx, integer *incx, real *sy, integer *incy, real *c__, real *s);
int drot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy, doublereal *c__, doublereal *s);

int sswap_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
int dswap_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
int cswap_(integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
int zswap_(integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

int sscal_(integer *n, real *sa, real *sx, integer *incx);
int dscal_(integer *n, doublereal *da, doublereal *dx, integer *incx);
int cscal_(integer *n, complex *ca, complex *cx, integer *incx);
int zscal_(integer *n, doublecomplex *za, doublecomplex *zx, integer *incx);

int scopy_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
int dcopy_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
int ccopy_(integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
int zcopy_(integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

int saxpy_(integer *n, real *sa, real *sx, integer *incx, real *sy, integer *incy);
int daxpy_(integer *n, doublereal *da, doublereal *dx, integer *incx, doublereal *dy, integer *incy);
int caxpy_(integer *n, complex *ca, complex *cx, integer *incx, complex *cy, integer *incy);
int zaxpy_(integer *n, doublecomplex *za, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

E_f sdot_(integer *n, real *sx, integer *incx, real *sy, integer *incy);
doublereal ddot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, integer *incy);

C_f cdotu_(complex * ret_val, integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
Z_f zdotu_(doublecomplex * ret_val, integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

C_f cdotc_(complex * ret_val, integer *n, complex *cx, integer *incx, complex *cy, integer *incy);
Z_f zdotc_(doublecomplex * ret_val, integer *n, doublecomplex *zx, integer *incx, doublecomplex *zy, integer *incy);

E_f snrm2_(integer *n, real *x, integer *incx);
doublereal dnrm2_(integer *n, doublereal *x, integer *incx);

E_f sasum_(integer *n, real *sx, integer *incx);
doublereal dasum_(integer *n, doublereal *dx, integer *incx);

integer isamax_(integer *n, real *sx, integer *incx);
integer idamax_(integer *n, doublereal *dx, integer *incx);


/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */


/*
 * ===========================================================================
 * Prototypes for level 3 BLAS
 * ===========================================================================
 */

int dgemm_(char *transa, char *transb, integer *m, integer *n, integer *k, doublereal *alpha, doublereal *a, integer *lda, doublereal *b, integer *ldb, doublereal *beta, doublereal *c, integer *ldc);

#endif /* LINEAR_ALGEBRA_F77BLAS__H */
