VERSION=0.0.3
DESTDIR=/usr/local

# paths
PREFIX=/usr/local

# LINUX
CFLAGS=-ansi -Wall -Os -I tools/include
LDFLAGS=
CC=cc

# WINE (ubuntu)
#CFLAGS=-ansi -Wall -Os -I tools/include -DBUILD_CPXSTATIC -I ~/.wine/drive_c/Program\ Files/GnuWin32/include
#LDFLAGS=-L ~/.wine/drive_c/Program\ Files/GnuWin32/lib
#CC=i586-mingw32msvc-gcc

# WINE (archlinux)
#CFLAGS=-ansi -Wall -Os -I tools/include -DBUILD_CPXSTATIC -I ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/include
#LDFLAGS=-L ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/lib
#CC=i486-mingw32-gcc
