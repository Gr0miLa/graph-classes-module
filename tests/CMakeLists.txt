set(TARGET_NAME tests)

file(GLOB_RECURSE SRC *.cpp *.hpp *.h)

add_executable(${TARGET_NAME} ${SRC})

target_include_directories(${TARGET_NAME} PUBLIC ${GRAPHS_INCLUDE_DIR}/algorithms ${GRAPHS_INCLUDE_DIR}/graphs ${UTILS_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC utils graphs algorithms)
