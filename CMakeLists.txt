cmake_minimum_required(VERSION 3.0.0)

project(osl VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 17)

set(OSL_EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")
set(OSL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(OSL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE OSL_SRC_FILES
    "${OSL_SRC_DIR}/*.cpp"
)

add_library(${PROJECT_NAME} ${OSL_SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${OSL_INCLUDE_DIR}/")

# Options
option(OSL_BUILD_TESTS "Build the OSL test programs" TRUE)

if (OSL_BUILD_TESTS)
 add_subdirectory("${OSL_EXAMPLES_DIR}/allocator/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/array/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/list/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/math/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/memory/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/queue/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/string/")
 add_subdirectory("${OSL_EXAMPLES_DIR}/vector/")
endif ()
