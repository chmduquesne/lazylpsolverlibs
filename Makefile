# This part of the project does not require any closed-source header to
# build and the results can be distributed with no problem.

PREFIX=/usr/local
LIBS=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so

CC=gcc

all: $(LIBS)

generate_stubs:
	sh tools/generate_stub.sh cplex ilcplex/cplex.h tools/cplex_symbols ./cplex
	sh tools/generate_stub.sh xprs xprs.h tools/xprs_symbols ./xprs
	sh tools/generate_stub.sh gurobi gurobi_c.h tools/gurobi_symbols ./gurobi
	sh tools/generate_stub.sh glpk glpk.h tools/glpk_symbols ./glpk

lib: generate_stubs
	mkdir -p lib

lib/liblazycplex.so: lib
	$(CC) -Wall -shared ./cplex/lazy_cplex.c -I common -fPIC -o lib/liblazycplex.so

lib/liblazyxprs.so: lib
	$(CC) -Wall -shared ./xprs/lazy_xprs.c -I common -fPIC -o lib/liblazyxprs.so

lib/liblazygurobi.so: lib
	$(CC) -Wall -shared ./gurobi/lazy_gurobi_c.c -I common -fPIC -o lib/liblazygurobi.so

lib/liblazyglpk.so: lib
	$(CC) -Wall -shared ./glpk/lazy_glpk.c -I common -fPIC -o lib/liblazyglpk.so

install:
	install -Dm644 lib/liblazycplex.so $(PREFIX)/lib/liblazycplex.so
	install -Dm644 lib/liblazyxprs.so $(PREFIX)/lib/liblazyxprs.so
	install -Dm644 lib/liblazygurobi.so $(PREFIX)/lib/liblazygurobi.so
	install -Dm644 lib/liblazyglpk.so $(PREFIX)/lib/liblazyglpk.so
	install -Dm644 cplex/lazy_cplex.h $(PREFIX)/include/lazy_cplex.h
	install -Dm644 xprs/lazy_xprs.h $(PREFIX)/include/lazy_xprs.h
	install -Dm644 gurobi/lazy_gurobi_c.h $(PREFIX)/include/lazy_gurobi_c.h
	install -Dm644 glpk/lazy_glpk.h $(PREFIX)/include/lazy_glpk.h
	install -Dm644 common/lazy_loading_status.h $(PREFIX)/include/lazy_loading_status.h

clean:
	rm -rf lib
