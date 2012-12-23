DEFAULT_INCLUDES = -I@top_builddir@/library_src

TESTS = \
	startup.sh

check_PROGRAMS = \
	startup_cblas startup_f77blas   # test library startup

startup_cblas_SOURCES = startup_cblas.c
startup_cblas_LDADD = @top_builddir@/library_src/liblinalg_cblas.la
startup_cblas_LDFLAGS = -ldl


startup_f77blas_SOURCES = startup_f77blas.f
startup_f77blas_LDADD = @top_builddir@/library_src/liblinalg_f77blas.la
startup_f77blas_LDFLAGS = -ldl

CFLAGS = -Wall -g -O0
