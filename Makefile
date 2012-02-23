# This part of the project does not require any closed-source header to
# build and the results can be distributed with no problem.

include config.mk

ifeq ('cc', ${CC})
LIB=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so
else
LIB=lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll
endif
BIN=bin/test_lazylpsolverlibs
OBJ=test/test_lazycplex.o test/test_lazyxprs.o test/test_lazygurobi.o test/test_lazyglpk.o test/test_lazylibs.o

all: options ${LIB} ${BIN}

options:
	@echo build options:
	@echo "CFLAGS = ${CFLAGS}"
	@echo "CC     = ${CC}"

# For your convenience, an archive of solver headers can be downloaded.
download:
	wget -c https://lazylpsolverlibs.googlecode.com/files/solver_headers.tar.gz
	tar xzf solver_headers.tar.gz -C tools
	rm solver_headers.tar.gz

generate_stubs:
	sh tools/generate_stub.sh cplex ilcplex/cplex.h tools/cplex_symbols include src
	sh tools/generate_stub.sh xprs xprs.h tools/xprs_symbols include src
	sh tools/generate_stub.sh gurobi_c gurobi_c.h tools/gurobi_symbols include src
	sh tools/generate_stub.sh glpk glpk.h tools/glpk_symbols include src

src/lazy_%.c: generate_stubs

# WINDOWS
src/%.o: src/%.c
	${CC} -c -DBUILDING_LAZYLPSOLVERLIBS -I include $< -o $@ ${CFLAGS}

lib/lazy%.dll: src/lazy_%.o
	@mkdir -p lib
	${CC} -shared -o $@ $< -Wl,--output-def,${@:%.dll=%.def},--out-implib,${@:lib/%.dll=lib/lib%.a} -lltdl ${LDFLAGS}

lib/lazygurobi.dll: src/lazy_gurobi_c.o
	@mkdir -p lib
	${CC} -shared -o $@ $< -Wl,--output-def,${@:%.dll=%.def},--out-implib,${@:lib/%.dll=lib/lib%.a} -lltdl ${LDFLAGS}

# LINUX
lib/liblazy%.so: src/lazy_%.c
	@mkdir -p lib
	${CC} -shared -fPIC -I include $< -o $@ ${CFLAGS}

lib/liblazygurobi.so: src/lazy_gurobi_c.c
	@mkdir -p lib
	${CC} -shared -fPIC -I include $< -o $@ ${CFLAGS}

%.o: %.c
	$(CC) -Wall -I include -c $< -o $@ ${CFLAGS}

bin/test_lazylpsolverlibs: ${LIB} ${OBJ}
	mkdir -p bin
	$(CC) -Wall -L lib -lltdl -llazycplex -llazyxprs -llazygurobi -llazyglpk ${OBJ} -o bin/test_lazylpsolverlibs ${CFLAGS} ${LDFLAGS}

install: all
	@echo installing libraries to ${DESTDIR}${PREFIX}/lib
	mkdir -p ${DESTDIR}${PREFIX}/lib
	install -Dm644 lib/liblazycplex.so ${DESTDIR}${PREFIX}/lib/liblazycplex.so
	install -Dm644 lib/liblazyxprs.so ${DESTDIR}${PREFIX}/lib/liblazyxprs.so
	install -Dm644 lib/liblazygurobi.so ${DESTDIR}${PREFIX}/lib/liblazygurobi.so
	install -Dm644 lib/liblazyglpk.so ${DESTDIR}${PREFIX}/lib/liblazyglpk.so
	@echo installing headers to ${DESTDIR}${PREFIX}/include
	mkdir -p ${DESTDIR}${PREFIX}/include
	install -Dm644 include/lazy_cplex.h ${DESTDIR}${PREFIX}/include/lazy_cplex.h
	install -Dm644 include/lazy_xprs.h ${DESTDIR}${PREFIX}/include/lazy_xprs.h
	install -Dm644 include/lazy_gurobi_c.h ${DESTDIR}${PREFIX}/include/lazy_gurobi_c.h
	install -Dm644 include/lazy_glpk.h ${DESTDIR}${PREFIX}/include/lazy_glpk.h
	install -Dm644 include/lazy_loading_status.h ${DESTDIR}${PREFIX}/include/lazy_loading_status.h

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
	rm -rf lib bin dist test/*.o src/*.o

dist: archive

archive:
	mkdir -p dist
	hg archive dist/lazylpsolverlibs-${VERSION}.tar.gz -X ".hg*"

deb:
	mkdir -p dist
	rm -rf /tmp/installdir
	${MAKE} install DESTDIR=/tmp/installdir PREFIX=/usr
	cd dist && fpm -s dir -t deb -n lazylpsolverlibs -v ${VERSION} -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev (>=0)"

rpm:
	mkdir -p dist
	rm -rf /tmp/installdir
	${MAKE} install DESTDIR=/tmp/installdir PREFIX=/usr
	cd dist && fpm -s dir -t rpm -n lazylpsolverlibs -v ${VERSION} -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev (>=0)"
