#
# Cross-compilation
#
# the name of the target operating system
SET(CMAKE_SYSTEM_NAME Windows)

# which compilers to use for C and C++
SET(CMAKE_C_COMPILER i586-mingw32msvc-gcc)
SET(CMAKE_CXX_COMPILER i586-mingw32msvc-g++)

# here is the target environment located
SET(CMAKE_FIND_ROOT_PATH  /usr/i586-mingw32msvc "~/.wine/drive_c/Program\ Files/GnuWin32/" )

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set (CPLEX_HEADER_PATH "./include" CACHE PATH "Where to find cplex header directory ilcplex/cplex.h")
set (GUROBI_HEADER_PATH "./include" CACHE PATH "Where to find gurobi header gurobi_c.h")
set (XPRESS_HEADER_PATH "./include" CACHE PATH "Where to find xpress header xprs.h")
set (GLPK_HEADER_PATH "./include" CACHE PATH "Where to find glpk header glpk.h")
