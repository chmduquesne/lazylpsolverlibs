VERSION=0.1.0
DESTDIR=/usr/local

# paths
PREFIX=/usr/local

TARGET=LINUX

# flags for building a wine version (ubuntu)
ifeq ($(TARGET),WINE)

CFLAGS=-g -Wall -O2 -I tools/include
LDFLAGS=
CC=i586-mingw32msvc-gcc
LIB=lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll
BIN=bin/test_lazylpsolverlibs.exe
PKGCONFIG=PKG_CONFIG_LIBDIR=~/.wine/drive_c/Program\ Files/GnuWin32/lib/pkgconfig pkg-config --define-variable=prefix='/home/cduquesne/.wine/drive_c/Program\ Files/GnuWin32/'

endif

# flags for building a native version (ubuntu)
ifeq ($(TARGET),LINUX)

CFLAGS=-g -Wall -O2 -I tools/include
LDFLAGS=
CC=cc
LIB=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so
BIN=bin/test_lazylpsolverlibs
FPM=/var/lib/gems/1.8/gems/fpm-0.3.11/bin/fpm
PKGCONFIG=pkg-config

endif

# Note: (archlinux)
#CFLAGS=-Wall -Os -I tools/include -I ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/include
#LDFLAGS=-L ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/lib
#CC=i486-mingw32-gcc
