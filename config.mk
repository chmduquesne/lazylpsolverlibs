VERSION=0.0.3
DESTDIR=/usr/local

# paths
PREFIX=/usr/local

# LINUX
#CFLAGS=-ansi -Wall -Os -I tools/include
#LDFLAGS=
#CC=cc
#LIB=lib/liblazycplex.so lib/liblazyxprs.so lib/liblazygurobi.so lib/liblazyglpk.so
#BIN=bin/test_lazylpsolverlibs

# WINE (ubuntu)
CFLAGS=-ansi -g -Wall -I tools/include -I ~/.wine/drive_c/Program\ Files/GnuWin32/include
LDFLAGS=-L ~/.wine/drive_c/Program\ Files/GnuWin32/lib
CC=i586-mingw32msvc-gcc
LIB=lib/lazycplex.dll lib/lazyxprs.dll lib/lazygurobi.dll lib/lazyglpk.dll
BIN=bin/test_lazylpsolverlibs.exe

# WINE (archlinux)
#CFLAGS=-ansi -Wall -Os -I tools/include -DBUILD_CPXSTATIC -I ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/include
#LDFLAGS=-L ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/lib
#CC=i486-mingw32-gcc
