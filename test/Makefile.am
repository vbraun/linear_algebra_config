DEFAULT_INCLUDES = -I@top_builddir@/library_src

check_PROGRAMS = \
	startup   # test library startup

startup_SOURCES = startup.c
# test_CFLAGS = 
startup_LDADD = @top_builddir@/library_src/liblinalg_cblas.la
startup_LDFLAGS = -ldl
