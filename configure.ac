AC_PREREQ([2.66])
AC_INIT([linalg], [1.0.0], [vbraun.name@gmail.com])

AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE

AC_PROG_CC_C99

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([library_src/linalg_cblas.h])
AC_CONFIG_HEADERS([library_src/config.h])

AC_CONFIG_FILES([
  Makefile
  library_src/Makefile
  test/Makefile
])

LT_INIT([dlopen])
gl_VISIBILITY

AC_OUTPUT
