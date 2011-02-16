cmake_minimum_required (VERSION 2.6)
project (lazylpsolverlibs)

# System checks
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# libltdl is obviously necessary
find_package(LTDL REQUIRED)
include_directories(${LTDL_INCLUDE_DIRS})

# cplex is linked to pthread
find_package(PTHREAD REQUIRED)
include_directories(${PTHREAD_INCLUDE_DIR})

# Libraries to compile
# cplex
add_library(lazycplex SHARED lazy_cplex.c)
target_link_libraries (lazycplex ${LTDL_LIBRARIES} ${PTHREAD_LIBRARIES})
install(TARGETS lazycplex DESTINATION lib)
install(FILES lazy_cplex.h DESTINATION include)

# glpk
add_library(lazyglpk SHARED lazy_glpk.c)
target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
install(TARGETS lazyglpk DESTINATION lib)
install(FILES lazy_glpk.h DESTINATION include)

# gurobi
add_library(lazygurobi SHARED lazy_gurobi_c.c)
target_link_libraries (lazyglpk ${LTDL_LIBRARIES})
install(TARGETS lazygurobi DESTINATION lib)
install(FILES lazy_gurobi_c.h DESTINATION include)

# xpress
add_library(lazyxprs SHARED lazy_xprs.c)
target_link_libraries (lazyxprs ${LTDL_LIBRARIES})
install(TARGETS lazyxprs DESTINATION lib)
install(FILES lazy_xprs.h DESTINATION include)

# Install targets

# Packaging
set(CPACK_GENERATOR "DEB;RPM;NSIS")

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
