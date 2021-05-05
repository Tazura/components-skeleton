cmake_minimum_required(VERSION 3.16)
project(components-skeleton VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/.gitignore "*")

add_subdirectory(componentA)
add_subdirectory(componentB)
