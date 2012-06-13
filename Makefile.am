lib_LTLIBRARIES =
bin_PROGRAMS =
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA =

# lazycplex
lib_LTLIBRARIES += lib/liblazycplex.la
bin_PROGRAMS += bin/test_lazycplex
pkgconfig_DATA += lazycplex.pc

lib_liblazycplex_la_SOURCES = src/lazycplex.c
lib_liblazycplex_la_CFLAGS = $(GMODULE_CFLAGS) -I lazylpsolverlibs
lib_liblazycplex_la_LIBADD = $(GMODULE_LIBS)
lib_liblazycplex_la_LDFLAGS = -no-undefined --enable-runtime-pseudo-reloc

bin_test_lazycplex_SOURCES = test/test_lazycplex.c
bin_test_lazycplex_CFLAGS = -I lazylpsolverlibs
bin_test_lazycplex_LDFLAGS = lib/liblazycplex.la

# lazyxprx
lib_LTLIBRARIES += lib/liblazyxprs.la
bin_PROGRAMS += bin/test_lazyxprs
pkgconfig_DATA += lazyxprs.pc

lib_liblazyxprs_la_SOURCES = src/lazyxprs.c
lib_liblazyxprs_la_CFLAGS = $(GMODULE_CFLAGS) -I lazylpsolverlibs
lib_liblazyxprs_la_LIBADD = $(GMODULE_LIBS)
lib_liblazyxprs_la_LDFLAGS = -no-undefined --enable-runtime-pseudo-reloc

bin_test_lazyxprs_SOURCES = test/test_lazyxprs.c
bin_test_lazyxprs_CFLAGS = -I lazylpsolverlibs
bin_test_lazyxprs_LDFLAGS = lib/liblazyxprs.la

# lazygurobi
lib_LTLIBRARIES += lib/liblazygurobi.la
bin_PROGRAMS += bin/test_lazygurobi
pkgconfig_DATA += lazygurobi.pc

lib_liblazygurobi_la_SOURCES = src/lazygurobi.c
lib_liblazygurobi_la_CFLAGS = $(GMODULE_CFLAGS) -I lazylpsolverlibs
lib_liblazygurobi_la_LIBADD = $(GMODULE_LIBS) -lm
lib_liblazygurobi_la_LDFLAGS = -no-undefined --enable-runtime-pseudo-reloc

bin_test_lazygurobi_SOURCES = test/test_lazygurobi.c
bin_test_lazygurobi_CFLAGS = -I lazylpsolverlibs
bin_test_lazygurobi_LDFLAGS = lib/liblazygurobi.la

# lazyglpk
lib_LTLIBRARIES += lib/liblazyglpk.la
bin_PROGRAMS += bin/test_lazyglpk
pkgconfig_DATA += lazyglpk.pc

lib_liblazyglpk_la_SOURCES = src/lazyglpk.c
lib_liblazyglpk_la_CFLAGS = $(GMODULE_CFLAGS) -I lazylpsolverlibs
lib_liblazyglpk_la_LIBADD = $(GMODULE_LIBS)
lib_liblazyglpk_la_LDFLAGS = -no-undefined --enable-runtime-pseudo-reloc

bin_test_lazyglpk_SOURCES = test/test_lazyglpk.c
bin_test_lazyglpk_CFLAGS = -I lazylpsolverlibs
bin_test_lazyglpk_LDFLAGS = lib/liblazyglpk.la

nobase_include_HEADERS =  lazylpsolverlibs/ilcplex/cplex.h \
                          lazylpsolverlibs/xprs.h \
                          lazylpsolverlibs/gurobi_c.h \
                          lazylpsolverlibs/glpk.h
dist_data_DATA = tools/stublib.sh \
                 tools/filter_header.sh \
                 tools/package.sh \
                 tools/lazylpsolverlibs.nsi

# This target to regenerate the files. For maintenance only.
generate_stubs:
	sh tools/stublib.sh -l cplex123,cplex121,cplex120,cplex112,cplex111,cplex110,cplex102,cplex101,cplex100,cplex91,cplex90,cplex81,cplex80,cplex75,cplex71,cplex70,cplex66,cplex65,cplex60,cplex50,cplex40,cplex30,cplex21,cplex20 -e LAZYLPSOLVERLIBS_CPLEX_LIB_PATH -f /usr/lib/libcplex.so -i lazylpsolverlibs/ilcplex/cplex.h -d"<ilcplex/cplex.h>" -c"cpp $(CPPFLAGS)" > src/lazycplex.c
	sh tools/stublib.sh -l gurobi50,gurobi461,gurobi452,gurobi402,gurobi303 -e LAZYLPSOLVERLIBS_GUROBI_LIB_PATH -f /usr/lib/libgurobi.so -i lazylpsolverlibs/gurobi_c.h -d"<gurobi_c.h>" -c"cpp $(CPPFLAGS)" > src/lazygurobi.c
	sh tools/stublib.sh -l xprs -e LAZYLPSOLVERLIBS_XPRS_LIB_PATH -f /usr/lib/libxprs.so -i lazylpsolverlibs/xprs.h -d"<xprs.h>" -c"cpp $(CPPFLAGS)" > src/lazyxprs.c
	sh tools/stublib.sh -l glpk -e LAZYLPSOLVERLIBS_GLPK_LIB_PATH -f /usr/lib/libglpk.so -i lazylpsolverlibs/glpk.h -d"<glpk.h>" -c"cpp $(CPPFLAGS)" > src/lazyglpk.c
