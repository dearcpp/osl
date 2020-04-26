cmake_minimum_required(VERSION 3.0.0)

project(OSL VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/")
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/")

set (CMAKE_CXX_STANDARD 17)

set(OSL_EXAMPLE_DIR "${CMAKE_SOURCE_DIR}/example")
set(OSL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(OSL_SRC_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories("${OSL_INCLUDE_DIR}/")

file(GLOB_RECURSE OSL_SRC_FILES
    "${OSL_INCLUDE_DIR}/*.h"
    "${OSL_INCLUDE_DIR}/*.hpp"
    "${OSL_SRC_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} STATIC ${OSL_SRC_FILES})

add_subdirectory("${OSL_EXAMPLE_DIR}/memory/")
add_subdirectory("${OSL_EXAMPLE_DIR}/allocator/")
