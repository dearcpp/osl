cmake_minimum_required(VERSION 3.0.0)

project(osl VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set(OSL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(OSL_TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(OSL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(OSL_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

file(GLOB_RECURSE OSL_SRC_FILES
    "${OSL_SRC_DIR}/*.cpp"
)

set(OSL_LIBRARY ${PROJECT_NAME})
add_library(${OSL_LIBRARY} ${OSL_SRC_FILES})
target_include_directories(${OSL_LIBRARY} PUBLIC ${OSL_INCLUDE_DIR})

option(OSL_BUILD_TESTS "Build the OSL test programs" TRUE)

if (OSL_BUILD_TESTS)
 add_subdirectory("${OSL_LIB_DIR}/googletest")
 enable_testing()
 add_subdirectory("${OSL_TESTS_DIR}")
endif ()
