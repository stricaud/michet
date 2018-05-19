cmake_minimum_required(VERSION 2.8)

project(michet-project)
message("CMake system name: ${CMAKE_SYSTEM_NAME}")

find_package(BISON)
find_package(FLEX)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
message(FATAL_ERROR "CMake generation is not allowed within the source directory!
Remove the CMakeCache.txt file and try again from another folder, e.g.:

   rm CMakeCache.txt
   mkdir build
   cd build
   cmake ..
")
endif()

add_definitions(-g)

file(STRINGS VERSION VERSION)
set(MICHET_VERSION ${VERSION})
configure_file("src/lib/include/michet/version.h.cmake" "src/lib/include/michet/version.h")

message("Install Prefix:" ${CMAKE_INSTALL_PREFIX})
message("Lib Prefix:" ${CMAKE_SHARED_LIBRARY_PREFIX})
file(TO_NATIVE_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_SHARED_LIBRARY_PREFIX}/michet-${VERSION}/generators/x86_64/" GENERATORS_DIR)
message("Generators dir:" ${GENERATORS_DIR})

set(MICHET_INCLUDE_DIRS "${michet-project_SOURCE_DIR}/src/lib/include/" "${michet-project_BINARY_DIR}/src/lib/include")
set(MICHET_LIBRARY "${michet-project_BINARY_DIR}/src/lib/libmichet.so")

add_subdirectory(src)
