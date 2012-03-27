# lazylpsolverlibs - libraries for loading solvers lazily

include config.mk

TST_SRC=$(wildcard test/*.c)
TST_OBJ=$(TST_SRC:test/%.c=bin/%.o)

# LIB and BIN must be specified in config.mk

LIB = lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX) \
	  lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX)  \
	  lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX)\
	  lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX)
BIN = bin/test_lazylpsolverlibs$(BINSUFFIX)

all: $(LIB) $(BIN)

dirs:
	@mkdir -p lib
	@mkdir -p bin
	@mkdir -p dist

lib/%.o: src/%.c dirs
	$(CC) $(BUILDLIB_CFLAGS) $(GMODULE_CFLAGS) $(CFLAGS) -c $< -o $@

bin/%.o: test/%.c
	$(CC) -c $< -o $@ $(GMODULE_CFLAGS) $(LAZYLPSOLVERLIBS_CFLAGS) $(CFLAGS)

lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX): lib/lazycplex.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX) lib/lazycplex.o $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX): lib/lazyxprs.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX) lib/lazyxprs.o $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX): lib/lazygurobi.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX) lib/lazygurobi.o $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX): lib/lazyglpk.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX) lib/lazyglpk.o $(GMODULE_LDFLAGS) $(LDFLAGS)

bin/test_lazylpsolverlibs$(BINSUFFIX): $(LIB) $(TST_OBJ) dirs
	$(CC) $(TST_OBJ) -o bin/test_lazylpsolverlibs$(BINSUFFIX) $(GMODULE_LDFLAGS) $(LAZYLPSOLVERLIBS_LDFLAGS) $(LDFLAGS)

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

upload:
	 googlecode_upload -s"Source distribution" -plazylpsolverlibs -lFeatured,Type-Source dist/lazylpsolverlibs-$(VERSION).tar.gz
	 googlecode_upload -s"Debian Package" -plazylpsolverlibs -lFeatured,Type-Package dist/lazylpsolverlibs-$(VERSION)*.deb
	 googlecode_upload -s"Fedora Package" -plazylpsolverlibs -lFeatured,Type-Package dist/lazylpsolverlibs-$(VERSION)*.rpm
	 googlecode_upload -s"Windows installer" -plazylpsolverlibs -lFeatured,Type-Installer dist/lazylpsolverlibs-$(VERSION)_installer.exe


dist: dirs
	@echo creating dist tarball
	@mkdir -p lazylpsolverlibs-$(VERSION)
	@cp -R AUTHORS config.mk COPYING include INSTALL Makefile README ROADMAP CHANGELOG src test tools lazylpsolverlibs-$(VERSION)
	@rm -rf lazylpsolverlibs-$(VERSION)/tools/include
	@tar cvzf lazylpsolverlibs-$(VERSION).tar.gz lazylpsolverlibs-$(VERSION)
	@mv lazylpsolverlibs-$(VERSION).tar.gz dist
	@rm -rf lazylpsolverlibs-$(VERSION)

deb:
	@echo creating debian package
	@$(MAKE) clean
	@$(MAKE) TARGET=LINUX
	@rm -rf /tmp/installdir
	@$(MAKE) install DESTDIR=/tmp/installdir PREFIX=/usr
	@$(FPM) -s dir -t deb -n lazylpsolverlibs -v $(VERSION) -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.deb -d "libglib2.0-dev(>=0)"
	@mv lazylpsolverlibs-*.deb dist

rpm:
	@echo creating fedora package
	@$(MAKE) clean
	@$(MAKE) TARGET=LINUX
	@rm -rf /tmp/installdir
	@$(MAKE) install DESTDIR=/tmp/installdir PREFIX=/usr
	@$(FPM) -s dir -t rpm -n lazylpsolverlibs -v $(VERSION) -C /tmp/installdir -p lazylpsolverlibs-VERSION_ARCH.rpm -d "libglib2.0-dev(>=0)"
	@mv lazylpsolverlibs-*.rpm dist

tools/wine:
	mkdir tools/wine
	wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip
	unzip glib-dev_2.28.8-1_win32.zip -d tools/wine
	rm glib-dev_2.28.8-1_win32.zip
	wget -c http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime-dev_0.18.1.1-2_win32.zip
	unzip gettext-runtime-dev_0.18.1.1-2_win32.zip -d tools/wine
	rm gettext-runtime-dev_0.18.1.1-2_win32.zip

nsis: tools/wine
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
