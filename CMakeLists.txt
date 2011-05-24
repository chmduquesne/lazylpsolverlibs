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

# gurobi links to libm
find_library(M_LIB m)

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
    set(COMPILED_WITH_CPLEX_SUPPORT 1)
    add_definitions( -DBUILD_CPXSTATIC )
    include_directories(${CPLEX_HEADER_PATH})
    if(WIN32)
        add_library(lazycplex STATIC lazy_cplex.c)
    else(WIN32)
        add_library(lazycplex SHARED lazy_cplex.c)
    endif(WIN32)
    target_link_libraries (lazycplex ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
    install(TARGETS lazycplex DESTINATION lib)
    install(FILES lazy_cplex.h DESTINATION include)
else(CPLEX_HEADER_PATH)
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
    set(COMPILED_WITH_GLPK_SUPPORT 1)
    include_directories(${GLPK_HEADER_PATH})
    if(WIN32)
        add_library(lazyglpk STATIC lazy_glpk.c)
    else(WIN32)
        add_library(lazyglpk SHARED lazy_glpk.c)
    endif(WIN32)
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
    set(COMPILED_WITH_GUROBI_SUPPORT 1)
    include_directories(${GUROBI_HEADER_PATH})
    if(WIN32)
        add_library(lazygurobi STATIC lazy_gurobi_c.c)
    else(WIN32)
        add_library(lazygurobi SHARED lazy_gurobi_c.c)
    endif(WIN32)
    target_link_libraries (lazygurobi ${LTDL_LIBRARIES} ${M_LIB})
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
    set(COMPILED_WITH_XPRESS_SUPPORT 1)
    include_directories(${XPRESS_HEADER_PATH})
    if(WIN32)
        add_library(lazyxprs STATIC lazy_xprs.c)
    else(WIN32)
        add_library(lazyxprs SHARED lazy_xprs.c)
    endif(WIN32)
    target_link_libraries (lazyxprs ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
    install(TARGETS lazyxprs DESTINATION lib)
    install(FILES lazy_xprs.h DESTINATION include)
else(XPRESS_HEADER_PATH)
    message("Xpress header not found: skipping liblazyxprs")
    set(XPRESS_HEADER_PATH)
endif(XPRESS_HEADER_PATH)

# Last install target
if(CPLEX_HEADER_PATH OR GLPK_HEADER_PATH OR GUROBI_HEADER_PATH OR XPRESS_HEADER_PATH)
    configure_file ("config.h.in" "config.h")
    include_directories("${PROJECT_BINARY_DIR}")
    install(FILES lazy_loading_status.h DESTINATION include)

    add_executable(lazylpsolverlibs
        test_lazygurobi.c
        test_lazycplex.c
        test_lazyglpk.c
        test_lazyxprs.c
        test_lazylibs.c)

    if (CPLEX_HEADER_PATH)
    target_link_libraries (lazylpsolverlibs lazycplex)
    endif (CPLEX_HEADER_PATH)
    if (XPRESS_HEADER_PATH)
    target_link_libraries (lazylpsolverlibs lazyxprs)
    endif (XPRESS_HEADER_PATH)
    if (GUROBI_HEADER_PATH)
    target_link_libraries (lazylpsolverlibs lazygurobi)
    endif (GUROBI_HEADER_PATH)
    if (GLPK_HEADER_PATH)
    target_link_libraries (lazylpsolverlibs lazyglpk)
    endif (GLPK_HEADER_PATH)

    install(TARGETS lazylpsolverlibs DESTINATION bin)
endif(CPLEX_HEADER_PATH OR GLPK_HEADER_PATH OR GUROBI_HEADER_PATH OR XPRESS_HEADER_PATH)


# Packaging
if(WIN32)
set(CPACK_GENERATOR "NSIS")
else(WIN32)
set(CPACK_GENERATOR "DEB;RPM")
endif(WIN32)

# General packaging settings
set(CPACK_PACKAGE_SUMMARY "set of libraries allowing to load lp solvers lazily")
set(CPACK_PACKAGE_NAME "lazylpsolverlibs")
set(CPACK_PACKAGE_VERSION "0.0.1")
set(CPACK_PACKAGE_CONTACT "Christophe-Marie Duquesne <chm.duquesne@gmail.com>")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")

# Debian specific
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libltdl-dev")

# Fedora specific
set(CPACK_RPM_PACKAGE_REQUIRES "libltdl-dev")

# Windows specific
set(CPACK_NSIS_MODIFY_PATH ON)

INCLUDE(CPack)
