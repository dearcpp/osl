project(allocator)

add_executable(${PROJECT_NAME} "${OSL_EXAMPLE_DIR}/${PROJECT_NAME}/${PROJECT_NAME}.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE osl)
