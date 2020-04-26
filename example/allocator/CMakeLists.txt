project(allocator)

add_executable(${PROJECT_NAME} "${OSL_EXAMPLE_DIR}/allocator/allocator.cpp")
target_link_libraries(${PROJECT_NAME} OSL)
