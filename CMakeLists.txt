cmake_minimum_required(VERSION 3.0.0)

project(OSL VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 17)

set(OSL_EXAMPLE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/example")
set(OSL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(OSL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include_directories("${OSL_INCLUDE_DIR}/")

file(GLOB_RECURSE OSL_SRC_FILES
    "${OSL_INCLUDE_DIR}/*.h"
    "${OSL_INCLUDE_DIR}/*.hpp"
    "${OSL_SRC_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} STATIC ${OSL_SRC_FILES})

# Options
option(OSL_BUILD_TESTS "Build the OSL test programs" TRUE)

if (OSL_BUILD_TESTS)
 add_subdirectory("${OSL_EXAMPLE_DIR}/allocator/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/array/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/memory/")
 add_subdirectory("${OSL_EXAMPLE_DIR}/stack/")
endif ()