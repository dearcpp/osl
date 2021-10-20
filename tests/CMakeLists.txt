include(GoogleTest)

set(TESTS_EXECUTABLE "${PROJECT_NAME}_tests")

add_executable(${TESTS_EXECUTABLE}
    "${CMAKE_CURRENT_LIST_DIR}/allocator/allocator.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/array/array.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/math/math.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/memory/memory.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/queue/queue.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/string/string.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/utility/utility.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/vector/vector.cpp")

target_link_libraries(${TESTS_EXECUTABLE} PRIVATE gtest_main osl)
gtest_discover_tests(${TESTS_EXECUTABLE})
