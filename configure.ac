AC_INIT([lazylpsolverlibs], [1.0.0], [chmd@chmd.fr], [lazylpsolverlibs],
        [https://code.google.com/p/lazylpsolverlibs/])
GENERIC_LIBRARY_VERSION="1:0:0"
#                        | | |
#                 +------+ | +---+
#                 |        |     |
#              current:revision:age
#                 |        |     |
#                 |        |     +- increment if interfaces have
#                 |        |        been added; set to zero if
#                 |        |        interfaces have been removed or
#                 |        |        changed
#                 |        +- increment if source code has changed;
#                 |           set to zero if current is incremented
#                 +- increment if interfaces have been added, removed
#                    or changed
AC_SUBST(GENERIC_LIBRARY_VERSION)
DATE=`date +"%B %e, %Y"`
AC_SUBST(DATE)
AC_PREREQ([2.59])
AC_PROG_CC
LT_INIT
AM_INIT_AUTOMAKE([1.10 no-define])
PKG_CHECK_MODULES([GMODULE], [gmodule-2.0 >= 0])
AC_CONFIG_FILES([Makefile \
                 lib/pkgconfig/lazycplex.pc \
                 lib/pkgconfig/lazyxprs.pc \
                 lib/pkgconfig/lazygurobi.pc \
                 lib/pkgconfig/lazyglpk.pc \
                 share/man/man1/lazycplex-config.1 \
                 share/man/man1/lazyxprs-config.1 \
                 share/man/man1/lazygurobi-config.1 \
                 share/man/man1/lazyglpk-config.1])
AC_OUTPUT
