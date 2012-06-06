# lazylpsolverlibs - libraries for loading solvers lazily

include config.mk

TST_SRC=$(wildcard test/*.c)
TST_OBJ=$(TST_SRC:test/%.c=bin/%.o)

LIB = lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX)  \
      lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX)   \
      lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX) \
      lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX)

BIN = bin/test_lazycplex$(BINSUFFIX) \
      bin/test_lazyxprs$(BINSUFFIX) \
      bin/test_lazygurobi$(BINSUFFIX) \
      bin/test_lazyglpk$(BINSUFFIX)

all: $(LIB) $(BIN)

dirs:
	@mkdir -p lib
	@mkdir -p bin
	@mkdir -p dist

lib/%.o: src/%.c dirs
	$(CC) -c $< -o $@ $(GMODULE_CFLAGS) $(BUILDLIB_CFLAGS) $(CFLAGS)

bin/%$(BINSUFFIX): test/%.c
	$(CC) $< -o $@ $(GMODULE_CFLAGS) $(GMODULE_LDFLAGS) $(LLSL_CFLAGS) $(CFLAGS) $(LLSL_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX): lib/lazycplex.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazycplex$(LIBSUFFIX) lib/lazycplex.o $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX): lib/lazyxprs.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazyxprs$(LIBSUFFIX) lib/lazyxprs.o $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX): lib/lazygurobi.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazygurobi$(LIBSUFFIX) lib/lazygurobi.o -lm $(GMODULE_LDFLAGS) $(LDFLAGS)

lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX): lib/lazyglpk.o
	$(LINKCMD) -o lib/$(LIBPREFIX)lazyglpk$(LIBSUFFIX) lib/lazyglpk.o $(GMODULE_LDFLAGS) $(LDFLAGS)

# For your convenience, an archive of solver headers can be downloaded.
download:
	wget -c https://lazylpsolverlibs.googlecode.com/files/solver_headers.tar.gz
	tar xzf solver_headers.tar.gz -C tools
	rm solver_headers.tar.gz

# This target to regenerate the files. For maintenance only.
generate_stubs:
	sh tools/stublib.sh -l cplex123,cplex121,cplex120,cplex112,cplex111,cplex110,cplex102,cplex101,cplex100,cplex91,cplex90,cplex81,cplex80,cplex75,cplex71,cplex70,cplex66,cplex65,cplex60,cplex50,cplex40,cplex30,cplex21,cplex20 -e LAZYLPSOLVERLIBS_CPLEX_LIB_PATH -f /usr/lib/libcplex.so -i tools/include/ilcplex/cplex.h -d"<ilcplex/cplex.h>" -c$(PREPROCESSOR) > src/lazycplex.c
	sh tools/stublib.sh -l gurobi50,gurobi461,gurobi452,gurobi402,gurobi303 -e LAZYLPSOLVERLIBS_GUROBI_LIB_PATH -f /usr/lib/libgurobi.so -i tools/include/gurobi_c.h -d"<gurobi_c.h>" -c$(PREPROCESSOR) > src/lazygurobi.c
	sh tools/stublib.sh -l xprs -e LAZYLPSOLVERLIBS_XPRS_LIB_PATH -f /usr/lib/libxprs.so -i tools/include/xprs.h -d"<xprs.h>" -c$(PREPROCESSOR) > src/lazyxprs.c
	sh tools/stublib.sh -l glpk -e LAZYLPSOLVERLIBS_GLPK_LIB_PATH -f /usr/lib/libglpk.so -i tools/include/glpk.h -d"<glpk.h>" -c$(PREPROCESSOR) > src/lazyglpk.c

install: all
	@echo installing libraries to $(DESTDIR)$(PREFIX)/lib
	@mkdir -p $(DESTDIR)$(PREFIX)/lib
	@install -Dm644 lib/liblazycplex.so $(DESTDIR)$(PREFIX)/lib/liblazycplex.so
	@install -Dm644 lib/liblazyxprs.so $(DESTDIR)$(PREFIX)/lib/liblazyxprs.so
	@install -Dm644 lib/liblazygurobi.so $(DESTDIR)$(PREFIX)/lib/liblazygurobi.so
	@install -Dm644 lib/liblazyglpk.so $(DESTDIR)$(PREFIX)/lib/liblazyglpk.so
	@echo installing binaries to $(DESTDIR)$(PREFIX)/bin
	@mkdir -p $(DESTDIR)$(PREFIX)/bin

uninstall:
	@echo removing libraries from $(DESTDIR)$(PREFIX)/lib
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazycplex.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazyxprs.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazygurobi.so
	@rm -f $(DESTDIR)$(PREFIX)/lib/liblazyglpk.so
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
	@rm -rf lazylpsolverlibs-$(VERSION)/tools/wine
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
