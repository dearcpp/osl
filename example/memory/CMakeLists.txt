project(memory)

add_executable(${PROJECT_NAME} "${OSL_EXAMPLE_DIR}/memory/memory.cpp")
target_link_libraries(${PROJECT_NAME} OSL)
