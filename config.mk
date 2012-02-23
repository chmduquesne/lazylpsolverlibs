VERSION=0.0.3
DESTDIR=/usr/local

# paths
PREFIX=/usr/local

# flags
#CFLAGS=-ansi -Wall -Os -I tools/include
#CFLAGS=-ansi -Wall -Os -I tools/include -I ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/include
CFLAGS=-ansi -Wall -Os -I tools/include -DBUILD_CPXSTATIC -I ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/include
LDFLAGS=-L ~/.wine/drive_c/Program\ Files\ \(x86\)/GnuWin32/lib

# compiler and linker
#CC=cc
CC=i486-mingw32-gcc
#CC=i586-mingw32msvc-gcc
