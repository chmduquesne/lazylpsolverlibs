# lazylpsolverlibs - libraries for loading solvers lazily

include config.mk

TST_SRC=$(wildcard test/*.c)
TST_OBJ=$(TST_SRC:%.c=%.o)

# LIB and BIN must be specified in config.mk
all: $(LIB) $(BIN)

dirs:
	@mkdir -p lib
	@mkdir -p bin
	@mkdir -p dist

# WINE
lib/%.dll: src/%.c dirs
	$(CC) -c -DBUILDING_LAZYLPSOLVERLIBS -DBUILD_CPXSTATIC -I include $< -o $(<:%.c=%.o) $(CFLAGS)
	$(CC) -shared -o $@ $(<:%.c=%.o) -Wl,--output-def,$(@:%.dll=%.def),--out-implib,$(@:lib/%.dll=lib/lib%.a) -lltdl $(LDFLAGS)

bin/test_lazylpsolverlibs.exe: $(LIB) $(TST_OBJ) dirs
	$(CC) $(TST_OBJ) -o bin/test_lazylpsolverlibs.exe -lltdl lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll $(LDFLAGS)

# LINUX
lib/lib%.so: src/%.c dirs
	$(CC) -shared -fPIC -I include $< -o $@ $(CFLAGS)

bin/test_lazylpsolverlibs: $(LIB) $(TST_OBJ) dirs
	$(CC) $(TST_OBJ) -o bin/test_lazylpsolverlibs -lltdl -llazycplex -llazyxprs -llazygurobi -llazyglpk -Llib $(LDFLAGS)

# BOTH PLATFORMS
%.o: %.c
	$(CC) -I include -c  $< -o $@ $(CFLAGS)

# For your convenience, an archive of solver headers can be downloaded.
download:
	wget -c https://lazylpsolverlibs.googlecode.com/files/solver_headers.tar.gz
	tar xzf solver_headers.tar.gz -C tools
	rm solver_headers.tar.gz

# This target to regenerate the files. For maintenance only.
generate_stubs:
	sh tools/generate_stub.sh cplex ilcplex/cplex.h tools/cplex_symbols include src
	sh tools/generate_stub.sh xprs xprs.h tools/xprs_symbols include src
	sh tools/generate_stub.sh gurobi gurobi_c.h tools/gurobi_symbols include src
	sh tools/generate_stub.sh glpk glpk.h tools/glpk_symbols include src

install: all
	@echo installing libraries to $(DESTDIR)$(PREFIX)/lib
	@mkdir -p $(DESTDIR)$(PREFIX)/lib
	@install -Dm644 lib/liblazycplex.so $(DESTDIR)$(PREFIX)/lib/liblazycplex.so
	@install -Dm644 lib/liblazyxprs.so $(DESTDIR)$(PREFIX)/lib/liblazyxprs.so
	@install -Dm644 lib/liblazygurobi.so $(DESTDIR)$(PREFIX)/lib/liblazygurobi.so
	@install -Dm644 lib/liblazyglpk.so $(DESTDIR)$(PREFIX)/lib/liblazyglpk.so
	@echo installing headers to $(DESTDIR)$(PREFIX)/include
	@mkdir -p $(DESTDIR)$(PREFIX)/include
	@install -Dm644 include/lazycplex.h $(DESTDIR)$(PREFIX)/include/lazycplex.h
	@install -Dm644 include/lazyxprs.h $(DESTDIR)$(PREFIX)/include/lazyxprs.h
	@install -Dm644 include/lazygurobi.h $(DESTDIR)$(PREFIX)/include/lazygurobi.h
	@install -Dm644 include/lazyglpk.h $(DESTDIR)$(PREFIX)/include/lazyglpk.h
	@install -Dm644 include/lazy_loading_status.h $(DESTDIR)$(PREFIX)/include/lazy_loading_status.h
	@echo installing binary to $(DESTDIR)$(PREFIX)/bin
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@install -Dm755 bin/test_lazylpsolverlibs $(DESTDIR)$(PREFIX)/bin/test_lazylpsolverlibs

uninstall:
	@echo removing libraries from $(DESTDIR)$(PREFIX)/lib
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazycplex.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazyxprs.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazygurobi.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazyglpk.so
	@echo removing headers from $(DESTDIR)$(PREFIX)/include
	@rm -f $(DESTDIR)$(PREFIX)/include/lazycplex.h
	@rm -f $(DESTDIR)$(PREFIX)/include/lazyxprs.h
	@rm -f $(DESTDIR)$(PREFIX)/include/lazygurobi.h
	@rm -f $(DESTDIR)$(PREFIX)/include/lazyglpk.h
	@rm -f $(DESTDIR)$(PREFIX)/include/lazy_loading_status.h
	@echo removing headers from $(DESTDIR)$(PREFIX)/bin
	@rm -f $(DESTDIR)$(PREFIX)/bin/test_lazylpsolverlibs

clean:
	rm -rf lib bin test/*.o src/*.o

distclean: clean
	rm -rf dist

package: dist deb rpm nsis

dist: clean
	@echo creating dist tarball
	@mkdir -p lazylpsolverlibs-$(VERSION)
	@cp -R AUTHORS config.mk COPYING include INSTALL Makefile README ROADMAP CHANGELOG src test tools lazylpsolverlibs-$(VERSION)
	@rm -rf lazylpsolverlibs-$(VERSION)/include
	@tar cvzf lazylpsolverlibs-$(VERSION).tar.gz lazylpsolverlibs-$(VERSION)
	@mv lazylpsolverlibs-$(VERSION).tar.gz dist
	@rm -rf lazylpsolverlibs-$(VERSION)

deb:
	@echo creating debian package
	@$(MAKE) clean
	@$(MAKE) TARGET=LINUX
	@rm -rf /tmp/installdir
	@$(MAKE) install DESTDIR=/tmp/installdir PREFIX=/usr
	@$(FPM) -s dir -t deb -n lazylpsolverlibs -v $(VERSION) -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libltdl-dev(>=0)"
	@mv lazylpsolverlibs-*.deb dist

rpm:
	@echo creating fedora package
	@$(MAKE) clean
	@$(MAKE) TARGET=LINUX
	@rm -rf /tmp/installdir
	@$(MAKE) install DESTDIR=/tmp/installdir PREFIX=/usr
	@$(FPM) -s dir -t rpm -n lazylpsolverlibs -v $(VERSION) -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.rpm -d "libltdl-dev(>=0)"
	@mv lazylpsolverlibs-*.rpm dist

nsis:
	@$(MAKE) clean
	@$(MAKE) TARGET=WINE
	@cp tools/lazylpsolverlibs.nsi lazylpsolverlibs.nsi
	@sed -i "s/VERSION/$(VERSION)/g" lazylpsolverlibs.nsi
	@cp lib/lazycplex.dll bin
	@cp lib/lazyxprs.dll bin
	@cp lib/lazygurobi.dll bin
	@cp lib/lazyglpk.dll bin
	@makensis lazylpsolverlibs.nsi
	@rm lazylpsolverlibs.nsi
	@rm bin/lazycplex.dll
	@rm bin/lazyxprs.dll
	@rm bin/lazygurobi.dll
	@rm bin/lazyglpk.dll
	@mv lazylpsolverlibs-$(VERSION)_installer.exe dist
