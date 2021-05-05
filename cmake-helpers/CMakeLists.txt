cmake_minimum_required(VERSION 3.16)
project(cmake-helpers VERSION 1.0 LANGUAGES NONE)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/.gitignore "*")

include(GNUInstallDirs)

