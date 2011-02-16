cmake_minimum_required (VERSION 2.6)
project (lazylpsolverlibs)

# System checks
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# libltdl is obviously necessary
find_package(LTDL REQUIRED)
include_directories(${LTDL_INCLUDE_DIRS})

# cplex and xprs are linked to pthread
find_package(PTHREAD REQUIRED)
include_directories(${PTHREAD_INCLUDE_DIR})

find_path(CPLEX_HEADER_PATH "cplex.h" PATH_SUFFIXES "ilcplex")
find_path(GLPK_HEADER_PATH "glpk.h")
find_path(GUROBI_HEADER_PATH "gurobi_c.h")
find_path(XPRESS_HEADER_PATH "xprs.h")

# Libraries to compile

# cplex
# ldd libcplex121.so
#        linux-vdso.so.1 =>  (0x00007fffc6bff000)
#        libstdc++.so.5 => /usr/lib64/libstdc++.so.5 (0x00007fd537af2000)
#        libm.so.6 => /lib64/libm.so.6 (0x00007fd53786d000)
#        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007fd537657000)
#        libpthread.so.0 => /lib64/libpthread.so.0 (0x00007fd53743b000)
#        libc.so.6 => /lib64/libc.so.6 (0x00007fd5370bb000)
#        /lib64/ld-linux-x86-64.so.2 (0x0000003036e00000)
# ldd -u libcplex121.so
# Unused direct dependencies:
#
#         /lib64/libm.so.6
#         /lib64/libgcc_s.so.1
#         /lib64/libpthread.so.0
if(CPLEX_HEADER_PATH)
    include_directories(${CPLEX_HEADER_PATH})
    add_library(lazycplex SHARED lazy_cplex.c)
    target_link_libraries (lazycplex ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
    install(TARGETS lazycplex DESTINATION lib)
    install(FILES lazy_cplex.h DESTINATION include)
else(CPLEX_HEADER_PATH-NOTFOUND)
    message("Cplex header not found: skipping liblazycplex")
    set(CPLEX_HEADER_PATH)
endif(CPLEX_HEADER_PATH)

# glpk
# ldd /usr/lib/libglpk.so
#        linux-vdso.so.1 =>  (0x00007fffe59ff000)
#        libltdl.so.7 => /usr/lib/libltdl.so.7 (0x00007fd1a1246000)
#        libdl.so.2 => /lib/libdl.so.2 (0x00007fd1a1042000)
#        libz.so.1 => /lib/libz.so.1 (0x00007fd1a0e29000)
#        libgmp.so.3 => /usr/lib/libgmp.so.3 (0x00007fd1a0bc9000)
#        libm.so.6 => /lib/libm.so.6 (0x00007fd1a0946000)
#        libc.so.6 => /lib/libc.so.6 (0x00007fd1a05c2000)
#        /lib64/ld-linux-x86-64.so.2 (0x00007fd1a1736000)
# ldd -u libglpk.so
# Unused direct dependencies:
#
#         /usr/lib/libltdl.so.7
#         /lib/libdl.so.2
#         /lib/libz.so.1
#         /usr/lib/libgmp.so.3
#         /lib/libm.so.6
if(GLPK_HEADER_PATH)
    include_directories(${GLPK_HEADER_PATH})
    add_library(lazyglpk SHARED lazy_glpk.c)
    target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
    install(TARGETS lazyglpk DESTINATION lib)
    install(FILES lazy_glpk.h DESTINATION include)
else(GLPK_HEADER_PATH)
    message("Glpk header not found: skipping liblazyglpk")
    set(GLPK_HEADER_PATH)
endif(GLPK_HEADER_PATH)

# gurobi
# ldd libgurobi30.so
#         linux-vdso.so.1 =>  (0x00007fffed59b000)
#         libc.so.6 => /lib/libc.so.6 (0x00007f4bc129d000)
#         /lib64/ld-linux-x86-64.so.2 (0x00007f4bc1c9a000)
# ldd -u /usr/local/lib/libgurobi30.so
# Unused direct dependencies:
if(GUROBI_HEADER_PATH)
    include_directories(${GUROBI_HEADER_PATH})
    add_library(lazygurobi SHARED lazy_gurobi_c.c)
    target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
    install(TARGETS lazygurobi DESTINATION lib)
    install(FILES lazy_gurobi_c.h DESTINATION include)
else(GUROBI_HEADER_PATH)
    message("Gurobi header not found: skipping liblazygurobi")
    set(GUROBI_HEADER_PATH)
endif(GUROBI_HEADER_PATH)

# xpress
# ldd libxprs.so
#         linux-vdso.so.1 =>  (0x00007fff5a3ff000)
#         libm.so.6 => /lib64/libm.so.6 (0x00007f7ef0f67000)
#         libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f7ef0d4a000)
#         librt.so.1 => /lib64/librt.so.1 (0x00007f7ef0b42000)
#         libxprl.so.x7.0 => not found
#         libc.so.6 => /lib64/libc.so.6 (0x00007f7ef07c2000)
#         /lib64/ld-linux-x86-64.so.2 (0x0000003036e00000)
# ldd -u /opt/xpressmp/lib/libxprs.so
# Unused direct dependencies:
#
#         /lib64/libm.so.6
#         /lib64/libpthread.so.0
#         /lib64/librt.so.1
if(XPRESS_HEADER_PATH)
    include_directories(${XPRESS_HEADER_PATH})
    add_library(lazyxprs SHARED lazy_xprs.c)
    target_link_libraries (lazyxprs ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
    install(TARGETS lazyxprs DESTINATION lib)
    install(FILES lazy_xprs.h DESTINATION include)
else(XPRESS_HEADER_PATH)
    message("Xpress header not found: skipping liblazyxprs")
    set(XPRESS_HEADER_PATH)
endif(XPRESS_HEADER_PATH)

# Install targets

# Packaging
if(WIN32)
set(CPACK_GENERATOR "NSIS")
else(WIN32)
set(CPACK_GENERATOR "DEB;RPM")
endif(WIN32)

# General packaging settings
set(CPACK_PACKAGE_SUMMARY "set of libraries allowing to load lp solvers lazily")
set(CPACK_PACKAGE_NAME "lazylpsolverlibs")
set(CPACK_PACKAGE_VERSION "1")
set(CPACK_PACKAGE_CONTACT "Christophe-Marie Duquesne <chm.duquesne@gmail.com>")

# Debian specific
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libgcc1, libltdl-dev")

# Fedora specific
set(CPACK_RPM_PACKAGE_REQUIRES "libc6, libgcc1, libltdl-dev")

INCLUDE(CPack)
