set(TARGET_NAME algorithms)

file(GLOB_RECURSE SRC *.cpp *.hpp *.h)

add_library(${TARGET_NAME} STATIC ${SRC})

target_include_directories(${TARGET_NAME} PUBLIC ${GRAPHS_INCLUDE_DIR}/algorithms ${GRAPHS_INCLUDE_DIR}/graphs ${UTILS_DIR})