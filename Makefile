# lazylpsolverlibs - libraries for loading solvers lazily

include config.mk

#ifeq ('cc',${CC})
#LIB=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so
#BIN=bin/test_lazylpsolverlibs
#else
LIB=lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll
BIN=bin/test_lazylpsolverlibs.exe
#endif
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

lib:
	@mkdir -p lib

# WINDOWS
src/%.o: src/%.c
	${CC} -c -DBUILDING_LAZYLPSOLVERLIBS -I include $< -o $@ ${CFLAGS}

lib/lazy%.dll: src/lazy_%.o lib
	${CC} -shared -o $@ $< -Wl,--output-def,${@:%.dll=%.def},--out-implib,${@:lib/%.dll=lib/lib%.a} -lltdl ${LDFLAGS}

lib/lazygurobi.dll: src/lazy_gurobi_c.o lib
	${CC} -shared -o $@ $< -Wl,--output-def,${@:%.dll=%.def},--out-implib,${@:lib/%.dll=lib/lib%.a} -lltdl ${LDFLAGS}

# LINUX
lib/liblazy%.so: src/lazy_%.c lib
	${CC} -shared -fPIC -I include $< -o $@ ${CFLAGS}

lib/liblazygurobi.so: src/lazy_gurobi_c.c lib
	${CC} -shared -fPIC -I include $< -o $@ ${CFLAGS}

%.o: %.c
	${CC} -I include -c  $< -o $@ ${CFLAGS}

bin:
	@mkdir -p bin

bin/test_lazylpsolverlibs: ${LIB} ${OBJ} bin
	$(CC) ${OBJ} -o bin/test_lazylpsolverlibs -lltdl -llazycplex -llazyxprs -llazygurobi -llazyglpk -Llib ${CFLAGS} ${LDFLAGS}

bin/test_lazylpsolverlibs.exe: ${LIB} ${OBJ} bin
	$(CC) ${OBJ} -o bin/test_lazylpsolverlibs.exe -lltdl lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll ${CFLAGS} ${LDFLAGS}

install: all
	@echo installing libraries to ${DESTDIR}${PREFIX}/lib
	@mkdir -p ${DESTDIR}${PREFIX}/lib
	install -Dm644 lib/liblazycplex.so ${DESTDIR}${PREFIX}/lib/liblazycplex.so
	install -Dm644 lib/liblazyxprs.so ${DESTDIR}${PREFIX}/lib/liblazyxprs.so
	install -Dm644 lib/liblazygurobi.so ${DESTDIR}${PREFIX}/lib/liblazygurobi.so
	install -Dm644 lib/liblazyglpk.so ${DESTDIR}${PREFIX}/lib/liblazyglpk.so
	@echo installing headers to ${DESTDIR}${PREFIX}/include
	@mkdir -p ${DESTDIR}${PREFIX}/include
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

dist: clean
	@echo creating dist tarball
	@mkdir -p lazylpsolverlibs-${VERSION}
	@cp -R AUTHORS config.mk COPYING include INSTALL Makefile README ROADMAP src test tools lazylpsolverlibs-${VERSION}
	@tar cvzf lazylpsolverlibs-${VERSION}.tar.gz lazylpsolverlibs-${VERSION}
	@rm -rf lazylpsolverlibs-${VERSION}

deb: all
	mkdir -p dist
	rm -rf /tmp/installdir
	${MAKE} install DESTDIR=/tmp/installdir PREFIX=/usr
	fpm -s dir -t deb -n lazylpsolverlibs -v ${VERSION} -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev (>=0)"
	mv lazylpsolverlibs-*.deb dist

rpm: all
	mkdir -p dist
	rm -rf /tmp/installdir
	${MAKE} install DESTDIR=/tmp/installdir PREFIX=/usr
	fpm -s dir -t rpm -n lazylpsolverlibs -v ${VERSION} -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev (>=0)"
	mv lazylpsolverlibs-*.rpm dist

nsis: all
	@mkdir -p dist
	@cp tools/lazylpsolverlibs.nsi dist
	@sed -i "s/VERSION/${VERSION}/" dist/lazylpsolverlibs.nsi
	@makensis dist/lazylpsolverlibs.nsi
	@rm dist/lazylpsolverlibs.nsi
