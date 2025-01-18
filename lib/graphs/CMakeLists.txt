set(TARGET_NAME graphs)

file(GLOB_RECURSE SRC *.cpp *.hpp *.h)

add_library(${TARGET_NAME} STATIC ${SRC})

target_include_directories(${TARGET_NAME} PUBLIC ${GRAPHS_INCLUDE_DIR}/graphs ${UTILS_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC utils)