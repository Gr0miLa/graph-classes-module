set(TARGET_NAME utils)

file(GLOB_RECURSE SRC *.cpp *.hpp *.h)

add_library(${TARGET_NAME} STATIC ${SRC})