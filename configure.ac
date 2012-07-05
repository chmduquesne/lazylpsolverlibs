AC_INIT([lazylpsolverlibs], [0.1.50], [chmd@chmd.fr], [lazylpsolverlibs],
        [https://code.google.com/p/lazylpsolverlibs/])
AC_PREREQ([2.59])
AC_PROG_CC
LT_INIT
AM_INIT_AUTOMAKE([1.10 no-define])
AC_SUBST(GENERIC_LIBRARY_VERSION)
PKG_CHECK_MODULES([GMODULE], [gmodule-2.0 >= 0])
AC_CONFIG_FILES([Makefile \
                 lib/pkgconfig/lazycplex.pc \
                 lib/pkgconfig/lazyxprs.pc \
                 lib/pkgconfig/lazygurobi.pc \
                 lib/pkgconfig/lazyglpk.pc \
                 share/man/man1/lazycplex_test.1 \
                 share/man/man1/lazyxprs_test.1 \
                 share/man/man1/lazygurobi_test.1 \
                 share/man/man1/lazyglpk_test.1])
AC_OUTPUT
