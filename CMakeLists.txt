cmake_minimum_required(VERSION 2.8)

project(michet-project)
message("CMake system name: ${CMAKE_SYSTEM_NAME}")

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
message(FATAL_ERROR "CMake generation is not allowed within the source directory!
Remove the CMakeCache.txt file and try again from another folder, e.g.:

   rm CMakeCache.txt
   mkdir build
   cd build
   cmake ..
")
endif()

set(MICHET_INCLUDE_DIRS "${michet-project_SOURCE_DIR}/src/lib/include/" "${michet-project_BINARY_DIR}/src/lib/include")

add_subdirectory(src)
