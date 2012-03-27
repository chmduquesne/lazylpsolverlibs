VERSION = 0.1.2
DESTDIR = /usr/local

# paths
PREFIX = /usr/local

TARGET = LINUX

# flags for building a wine version (ubuntu)
ifeq ($(TARGET),WINE)
  CFLAGS          = -g -Wall -O2 -I tools/include
  LDFLAGS         =
  CC              = i586-mingw32msvc-gcc
  PKGCONFIG       = PKG_CONFIG_LIBDIR=tools/wine/lib/pkgconfig pkg-config --define-variable=prefix=tools/wine
  LIBPREFIX       =
  LIBSUFFIX       = .dll
  BINSUFFIX       = .exe
  LINKCMD         = $(CC) -shared
  BUILDLIB_CFLAGS = -DBUILDING_LAZYLPSOLVERLIBS -DBUILD_CPXSTATIC -I include
endif
# flags for building a native version (ubuntu)
ifeq ($(TARGET),LINUX)
  CFLAGS          = -g -Wall -O2 -I tools/include
  LDFLAGS         =
  CC              = cc
  PKGCONFIG       = pkg-config
  LIBPREFIX       = lib
  LIBSUFFIX       = .so
  BINSUFFIX       =
  LINKCMD         = $(CC) -shared
  BUILDLIB_CFLAGS = -fPIC -I include
endif

GMODULE_CFLAGS    = `$(PKGCONFIG) --cflags gmodule-2.0`
GMODULE_LDFLAGS   = `$(PKGCONFIG) --libs gmodule-2.0`
LAZYLPSOLVERLIBS_CFLAGS  = -I include
LAZYLPSOLVERLIBS_LDFLAGS = -llazycplex -llazyxprs -llazygurobi -llazyglpk -Llib
FPM               = /var/lib/gems/1.8/gems/fpm-0.3.11/bin/fpm
