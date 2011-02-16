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

# Libraries to compile

# cplex
# ldd libclplex121.so
#        linux-vdso.so.1 =>  (0x00007fffc6bff000)
#        libstdc++.so.5 => /usr/lib64/libstdc++.so.5 (0x00007fd537af2000)
#        libm.so.6 => /lib64/libm.so.6 (0x00007fd53786d000)
#        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007fd537657000)
#        libpthread.so.0 => /lib64/libpthread.so.0 (0x00007fd53743b000)
#        libc.so.6 => /lib64/libc.so.6 (0x00007fd5370bb000)
#        /lib64/ld-linux-x86-64.so.2 (0x0000003036e00000)
add_library(lazycplex SHARED lazy_cplex.c)
target_link_libraries (lazycplex ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
install(TARGETS lazycplex DESTINATION lib)
install(FILES lazy_cplex.h DESTINATION include)

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
add_library(lazyglpk SHARED lazy_glpk.c)
target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
install(TARGETS lazyglpk DESTINATION lib)
install(FILES lazy_glpk.h DESTINATION include)

# gurobi
# ldd libgurobi30.so
#         linux-vdso.so.1 =>  (0x00007fffed59b000)
#         libc.so.6 => /lib/libc.so.6 (0x00007f4bc129d000)
#         /lib64/ld-linux-x86-64.so.2 (0x00007f4bc1c9a000)
add_library(lazygurobi SHARED lazy_gurobi_c.c)
target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
install(TARGETS lazygurobi DESTINATION lib)
install(FILES lazy_gurobi_c.h DESTINATION include)

# xpress
# ldd libxprs.so
#         linux-vdso.so.1 =>  (0x00007fff5a3ff000)
#         libm.so.6 => /lib64/libm.so.6 (0x00007f7ef0f67000)
#         libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f7ef0d4a000)
#         librt.so.1 => /lib64/librt.so.1 (0x00007f7ef0b42000)
#         libxprl.so.x7.0 => not found
#         libc.so.6 => /lib64/libc.so.6 (0x00007f7ef07c2000)
#         /lib64/ld-linux-x86-64.so.2 (0x0000003036e00000)
add_library(lazyxprs SHARED lazy_xprs.c)
target_link_libraries (lazyxprs ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
install(TARGETS lazyxprs DESTINATION lib)
install(FILES lazy_xprs.h DESTINATION include)

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

# Fedora package
INCLUDE(CPack)
