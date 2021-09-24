if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_BINDJULIA bindjulia)

FIND_PATH(
    BINDJULIA_INCLUDE_DIRS
    NAMES bindjulia/api.h
    HINTS $ENV{BINDJULIA_DIR}/include
        ${PC_BINDJULIA_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BINDJULIA_LIBRARIES
    NAMES gnuradio-bindjulia
    HINTS $ENV{BINDJULIA_DIR}/lib
        ${PC_BINDJULIA_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/bindjuliaTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BINDJULIA DEFAULT_MSG BINDJULIA_LIBRARIES BINDJULIA_INCLUDE_DIRS)
MARK_AS_ADVANCED(BINDJULIA_LIBRARIES BINDJULIA_INCLUDE_DIRS)
