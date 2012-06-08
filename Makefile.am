lib_LTLIBRARIES = lib/liblazycplex.la \
				  lib/liblazyxprs.la \
				  lib/liblazygurobi.la \
				  lib/liblazyglpk.la

lib_liblazycplex_la_SOURCES = src/lazycplex.c
lib_liblazycplex_la_CFLAGS = $(GMODULE_CFLAGS) -I tools/include
lib_liblazycplex_la_LIBADD = $(GMODULE_LIBS)
lib_liblazycplex_la_LDFLAGS = -no-undefined

lib_liblazyxprs_la_SOURCES = src/lazyxprs.c
lib_liblazyxprs_la_CFLAGS = $(GMODULE_CFLAGS) -I tools/include
lib_liblazyxprs_la_LIBADD = $(GMODULE_LIBS)
lib_liblazyxprs_la_LDFLAGS = -no-undefined

lib_liblazygurobi_la_SOURCES = src/lazygurobi.c
lib_liblazygurobi_la_CFLAGS = $(GMODULE_CFLAGS) -I tools/include
lib_liblazygurobi_la_LIBADD = $(GMODULE_LIBS) -lm
lib_liblazygurobi_la_LDFLAGS = -no-undefined

lib_liblazyglpk_la_SOURCES = src/lazyglpk.c
lib_liblazyglpk_la_CFLAGS = $(GMODULE_CFLAGS) -I tools/include
lib_liblazyglpk_la_LIBADD = $(GMODULE_LIBS)
lib_liblazyglpk_la_LDFLAGS = -no-undefined


bin_PROGRAMS = bin/test_lazycplex \
			   bin/test_lazyxprs \
			   bin/test_lazygurobi \
			   bin/test_lazyglpk

bin_test_lazycplex_SOURCES = test/test_lazycplex.c
bin_test_lazycplex_LDADD = lib/liblazycplex.la

bin_test_lazyxprs_SOURCES = test/test_lazyxprs.c
bin_test_lazyxprs_LDADD = lib/liblazyxprs.la

bin_test_lazygurobi_SOURCES = test/test_lazygurobi.c
bin_test_lazygurobi_LDADD = lib/liblazygurobi.la

bin_test_lazyglpk_SOURCES = test/test_lazyglpk.c
bin_test_lazyglpk_LDADD = lib/liblazyglpk.la

