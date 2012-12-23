
lib_LTLIBRARIES = liblinalg_cblas.la liblinalg_f77blas.la

nobase_include_headers = \
	linalg_cblas.h linalg_f77blas.h


liblinalg_cblas_la_SOURCES = \
	setup.h setup.c macros.h cblas.c

liblinalg_cblas_la_CFLAGS = \
	-DBUILDING_LINEAR_ALGEBRA_LIBRARY \
	-DCONFIG_H $(CFLAG_VISIBILITY)
liblinalg_cblas_la_LDFLAGS = -ldl



liblinalg_f77blas_la_SOURCES = \
	setup.h setup.c macros.h f77blas.c

liblinalg_f77blas_la_CFLAGS = \
	-DBUILDING_LINEAR_ALGEBRA_LIBRARY \
	-DCONFIG_H $(CFLAG_VISIBILITY)
liblinalg_f77blas_la_LDFLAGS = -ldl

