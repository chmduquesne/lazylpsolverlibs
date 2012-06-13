AC_INIT([lazylpsolverlibs], [0.1.3], [chmd@chmd.fr], [lazylpsolverlibs],
        [https://code.google.com/p/lazylpsolverlibs/])
AC_PREREQ([2.59])
AC_PROG_CC
LT_INIT
AM_INIT_AUTOMAKE([1.10 no-define])
GENERIC_LIBRARY_VERSION="0:1:3"
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
PKG_CHECK_MODULES([GMODULE], [gmodule-2.0 >= 0])
AC_CONFIG_FILES([Makefile lazycplex.pc lazyxprs.pc lazygurobi.pc lazyglpk.pc])
AC_OUTPUT
