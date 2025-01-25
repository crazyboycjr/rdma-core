# FindPhoenixSyscalls.cmake
# Module to find the phoenix_syscalls library and headers

# Allow user to specify a custom root path for phoenix_syscalls
if(NOT DEFINED PHOENIX_SYSCALLS_PREFIX)
  set(PHOENIX_SYSCALLS_PREFIX "/tmp/phoenix" CACHE PATH "Directory for phoenix_syscalls installation")
endif()

# Search for the include directory containing phoenix_syscalls.h
find_path(PHOENIX_SYSCALLS_INCLUDE_DIRS
  NAMES phoenix_syscalls.h
  PATHS ${PHOENIX_SYSCALLS_PREFIX} ${PHOENIX_SYSCALLS_PREFIX}/include /usr/include /usr/local/include
  PATH_SUFFIXES phoenix_syscalls
)

# Search for the shared or static library
find_library(PHOENIX_SYSCALLS_LIBRARIES
  NAMES phoenix_syscalls
  PATHS
    ${PHOENIX_SYSCALLS_PREFIX}
    ${PHOENIX_SYSCALLS_PREFIX}/lib
    ${PHOENIX_SYSCALLS_PREFIX}/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /usr/lib
    /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}
    /usr/local/lib
    /usr/local/lib/${CMAKE_LIBRARY_ARCHITECTURE}
  PATH_SUFFIXES ""
)

# Set the PhoenixSyscalls_FOUND variable to true if both the include directory and library were found
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  PhoenixSyscalls FOUND_VAR PhoenixSyscalls_FOUND
  REQUIRED_VARS PHOENIX_SYSCALLS_INCLUDE_DIRS PHOENIX_SYSCALLS_LIBRARIES
)

# If the library and headers are found, export variables
if(PhoenixSyscalls_FOUND)
  set(PHOENIX_SYSCALLS_INCLUDE_DIRS ${PHOENIX_SYSCALLS_INCLUDE_DIRS})
  set(PHOENIX_SYSCALLS_LIBRARIES ${PHOENIX_SYSCALLS_LIBRARIES})
else()
  set(PHOENIX_SYSCALLS_INCLUDE_DIRS "")
  set(PHOENIX_SYSCALLS_LIBRARIES "")
endif()