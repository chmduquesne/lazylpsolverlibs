VERSION = 0.1.2
DESTDIR =

# paths
PREFIX = /usr/local

TARGET = LINUX

ifeq ($(TARGET),WINE)
  CFLAGS          = -g -Wall -O2 -I tools/include -fno-strict-aliasing -Wno-attributes
  LDFLAGS         =
  CC              = i586-mingw32msvc-gcc
  PKGCONFIG       = PKG_CONFIG_LIBDIR=tools/wine/lib/pkgconfig pkg-config --define-variable=prefix=tools/wine
  LIBPREFIX       =
  LIBSUFFIX       = .dll
  BINSUFFIX       = .exe
  LINKCMD         = $(CC) -shared -Wl,-no-undefined,--enable-runtime-pseudo-reloc
  BUILDLIB_CFLAGS = -DBUILD_CPXSTATIC
  PREPROCESSOR    = 'i586-mingw32msvc-cpp -DBUILD_CPXSTATIC'
endif

ifeq ($(TARGET),LINUX)
  CFLAGS          = -g -Wall -O2 -I tools/include
  LDFLAGS         =
  CC              = cc
  PKGCONFIG       = pkg-config
  LIBPREFIX       = lib
  LIBSUFFIX       = .so
  BINSUFFIX       =
  LINKCMD         = $(CC) -shared
  BUILDLIB_CFLAGS = -fPIC
  PREPROCESSOR    = cpp
endif

GMODULE_CFLAGS    = `$(PKGCONFIG) --cflags gmodule-2.0`
GMODULE_LDFLAGS   = `$(PKGCONFIG) --libs gmodule-2.0`
LLSL_LDFLAGS      = -llazycplex -llazyxprs -llazygurobi -llazyglpk -Llib
FPM               = /var/lib/gems/1.8/gems/fpm-0.3.11/bin/fpm
