
lib_LTLIBRARIES = liblinalg_cblas.la

nobase_include_headers = \
	linalg_cblas.h 

liblinalg_cblas_la_SOURCES = \
	macros.h cblas.c


liblinalg_cblas_la_CFLAGS = \
	-DBUILDING_LINEAR_ALGEBRA_LIBRARY \
	-DCONFIG_H $(CFLAG_VISIBILITY)
liblinalg_cblas_la_LDFLAGS = -ldl

