cmake_minimum_required(VERSION 3.16)
project(common-cmake-modules VERSION 1.0 LANGUAGES NONE)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/.gitignore "*")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/modules ${CMAKE_CURRENT_BINARY_DIR}/modules COPY_ON_ERROR SYMBOLIC)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake @ONLY)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)

install(FILES   ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake 
                ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/modules DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

# Package
export(PACKAGE ${PROJECT_NAME})

# Support find_package while added by add_subdirectory
set(${PROJECT_NAME}_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "" FORCE)

#include(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake)

# CPack
set(CPACK_GENERATOR TGZ)	
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_TGZ_COMPONENT_INSTALL ON)

set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_SOURCE_IGNORE_FILES \\.git build/ ".*~$")
include(CPack)
