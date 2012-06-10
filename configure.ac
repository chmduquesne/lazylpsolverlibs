AC_INIT([lazylpsolverlibs], [0.1.2], [chmd@chmd.fr], [lazylpsolverlibs],
        [https://code.google.com/p/lazylpsolverlibs/])
AC_PREREQ([2.59])
AC_PROG_CC
LT_INIT
AM_INIT_AUTOMAKE([1.10 no-define])
GENERIC_LIBRARY_VERSION="0:0:0"
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
AC_CHECK_HEADERS([ilcplex/cplex.h], [HAVE_CPLEX=1], [HAVE_CPLEX=0], [])
AM_CONDITIONAL([HAVE_CPLEX], [test "$HAVE_CPLEX" -eq 1])
AC_CHECK_HEADERS([gurobi_c.h], [HAVE_GUROBI=1], [HAVE_GUROBI=0], [])
AM_CONDITIONAL([HAVE_GUROBI], [test "$HAVE_GUROBI" -eq 1])
AC_CHECK_HEADERS([xprs.h], [HAVE_XPRESS=1], [HAVE_XPRESS=0], [])
AM_CONDITIONAL([HAVE_XPRESS], [test "$HAVE_XPRESS" -eq 1])
AC_CHECK_HEADERS([glpk.h], [HAVE_GLPK=1], [HAVE_GLPK=0], [])
AM_CONDITIONAL([HAVE_GLPK], [test "$HAVE_GLPK" -eq 1])
AC_CONFIG_FILES([Makefile lazycplex.pc lazyxprs.pc lazygurobi.pc lazyglpk.pc])
AC_OUTPUT
