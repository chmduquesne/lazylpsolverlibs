#
# Cross-compilation
#
set ( CMAKE_SYSTEM_NAME "Windows" CACHE STRING "Target platform" )

# which compilers to use for C and C++
SET ( CMAKE_C_COMPILER i586-mingw32msvc-gcc )
SET ( CMAKE_CXX_COMPILER i586-mingw32msvc-g++ )
SET ( CMAKE_RC_COMPILER i586-mingw32msvc-windres )

set ( CMAKE_FIND_ROOT_PATH "~/.wine/drive_c/Program Files/GnuWin32/" )
set ( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER )
set ( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY )
set ( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY )

#set ( CMAKE_SYSTEM_LIBRARY_PATH ${CMAKE_SYSTEM_LIBRARY_PATH} )
#set ( CMAKE_SYSTEM_INCLUDE_PATH ${CMAKE_SYSTEM_INCLUDE_PATH} ) # if not defined, it puts /usr/include too

set ( CPLEX_HEADER_PATH "./include" CACHE PATH "Where to find cplex header directory ilcplex/cplex.h" )
set ( GUROBI_HEADER_PATH "./include" CACHE PATH "Where to find gurobi header gurobi_c.h" )
set ( XPRESS_HEADER_PATH "./include" CACHE PATH "Where to find xpress header xprs.h" )
set ( GLPK_HEADER_PATH "./include" CACHE PATH "Where to find glpk header glpk.h" )
