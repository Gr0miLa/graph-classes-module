cmake_minimum_required(VERSION 3.25.0)

project(graphs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GRAPHS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(UTILS_DIR ${CMAKE_SOURCE_DIR}/utils)

add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(utils)
