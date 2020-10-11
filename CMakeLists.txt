cmake_minimum_required(VERSION 3.0.0)

project(OSL VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 17)

set(OSL_EXAMPLE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/example")
set(OSL_LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

include_directories("${OSL_LIBS_DIR}/")

file(GLOB_RECURSE OSL_SRC_FILES
    "${OSL_LIBS_DIR}/*.hpp"
)

# Options
option(OSL_BUILD_TESTS "Build the OSL test programs" TRUE)

if (OSL_BUILD_TESTS)
 add_subdirectory("${OSL_EXAMPLE_DIR}/allocator/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/array/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/list/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/math/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/memory/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/queue/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/string/")
endif ()