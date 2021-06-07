cmake_minimum_required(VERSION 3.16)
project(components-skeleton VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/.gitignore "*")


add_subdirectory(common-cmake-modules)
add_subdirectory(componentA)
add_subdirectory(componentB)



# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
