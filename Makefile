# This part of the project does not require any closed-source header to
# build and the results can be distributed with no problem.

include config.mk

LIBS=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so

all: options ${LIBS}

options:
	@echo build options:
	@echo "CFLAGS = ${CFLAGS}"
	@echo "CC     = ${CC}"

generate_stubs:
	sh tools/generate_stub.sh cplex ilcplex/cplex.h tools/cplex_symbols ./cplex
	sh tools/generate_stub.sh xprs xprs.h tools/xprs_symbols ./xprs
	sh tools/generate_stub.sh gurobi gurobi_c.h tools/gurobi_symbols ./gurobi
	sh tools/generate_stub.sh glpk glpk.h tools/glpk_symbols ./glpk

lib: generate_stubs
	mkdir -p lib

lib/liblazycplex.so: lib
	${CC} -shared -fPIC -I common ./cplex/lazy_cplex.c -o lib/liblazycplex.so ${CFLAGS}

lib/liblazyxprs.so: lib
	${CC} -shared -fPIC -I common ./xprs/lazy_xprs.c -o lib/liblazyxprs.so ${CFLAGS}

lib/liblazygurobi.so: lib
	${CC} -shared -fPIC -I common ./gurobi/lazy_gurobi_c.c -o lib/liblazygurobi.so ${CFLAGS}

lib/liblazyglpk.so: lib
	${CC} -shared -fPIC -I common ./glpk/lazy_glpk.c -o lib/liblazyglpk.so ${CFLAGS}

install: all
	@echo installing libraries to ${DESTDIR}${PREFIX}/lib
	mkdir -p ${DESTDIR}${PREFIX}/lib
	install -Dm644 lib/liblazycplex.so ${DESTDIR}${PREFIX}/lib/liblazycplex.so
	install -Dm644 lib/liblazyxprs.so ${DESTDIR}${PREFIX}/lib/liblazyxprs.so
	install -Dm644 lib/liblazygurobi.so ${DESTDIR}${PREFIX}/lib/liblazygurobi.so
	install -Dm644 lib/liblazyglpk.so ${DESTDIR}${PREFIX}/lib/liblazyglpk.so
	@echo installing headers to ${DESTDIR}${PREFIX}/include
	mkdir -p ${DESTDIR}${PREFIX}/include
	install -Dm644 cplex/lazy_cplex.h ${DESTDIR}${PREFIX}/include/lazy_cplex.h
	install -Dm644 xprs/lazy_xprs.h ${DESTDIR}${PREFIX}/include/lazy_xprs.h
	install -Dm644 gurobi/lazy_gurobi_c.h ${DESTDIR}${PREFIX}/include/lazy_gurobi_c.h
	install -Dm644 glpk/lazy_glpk.h ${DESTDIR}${PREFIX}/include/lazy_glpk.h
	install -Dm644 common/lazy_loading_status.h ${DESTDIR}${PREFIX}/include/lazy_loading_status.h

uninstall:
	@echo removing libraries from ${DESTDIR}${PREFIX}/lib
	rm -f ${DESTDIR}${PREFIX}/lib/liblazycplex.so
	rm -f ${DESTDIR}${PREFIX}/lib/liblazyxprs.so
	rm -f ${DESTDIR}${PREFIX}/lib/liblazygurobi.so
	rm -f ${DESTDIR}${PREFIX}/lib/liblazyglpk.so
	@echo removing headers from ${DESTDIR}${PREFIX}/include
	rm -f ${DESTDIR}${PREFIX}/include/lazy_cplex.h
	rm -f ${DESTDIR}${PREFIX}/include/lazy_xprs.h
	rm -f ${DESTDIR}${PREFIX}/include/lazy_gurobi_c.h
	rm -f ${DESTDIR}${PREFIX}/include/lazy_glpk.h
	rm -f ${DESTDIR}${PREFIX}/include/lazy_loading_status.h

clean:
	rm -rf lib dist

dist: archive

archive:
	mkdir -p dist
	hg archive dist/lazylpsolverlibs-${VERSION}.tar.gz -X ".hg*"

deb:
	mkdir -p dist
	rm -rf /tmp/installdir
	${MAKE} install DESTDIR=/tmp/installdir PREFIX=/usr
	cd dist && /var/lib/gems/1.8/gems/fpm-0.3.11/bin/fpm -s dir -t deb -n lazylpsolverlibs -v ${VERSION} -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev (>0)"
