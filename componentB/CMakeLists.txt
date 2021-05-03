cmake_minimum_required(VERSION 3.16)
project(componentB VERSION 1.0 LANGUAGES C CXX)

set(${PROJECT_NAME}_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(${PROJECT_NAME}_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/.gitignore "*")

# Increase me everytime you changes the interface
set(SO_VERSION 1)

include(GNUInstallDirs)
include(CTest)
enable_testing()

# Find packages
find_package(componentA REQUIRED)

# Sources
file(GLOB_RECURSE ${PROJECT_NAME}_PUBLIC_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*)

set(${PROJECT_NAME}_SOURCES 
	componentB.cpp
)

# Target: shared
add_library(${PROJECT_NAME}-lib SHARED ${${PROJECT_NAME}_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME}-lib)

set_target_properties(${PROJECT_NAME}-lib PROPERTIES OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT 1)
set_target_properties(${PROJECT_NAME}-lib PROPERTIES PUBLIC_HEADER "${${PROJECT_NAME}_PUBLIC_HEADERS}")
set_target_properties(${PROJECT_NAME}-lib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES SOVERSION ${SO_VERSION})
target_include_directories(${PROJECT_NAME}-lib
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}		
)
#target_link_libraries(${PROJECT_NAME}-lib PUBLIC Boost::boost Threads::Threads rt)
#target_link_libraries(${PROJECT_NAME}-lib PRIVATE systemd Boost::system Boost::filesystem Boost::iostreams Boost::program_options)
install(TARGETS ${PROJECT_NAME}-lib
		EXPORT ${PROJECT_NAME}-targets
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
		)

export(TARGETS ${PROJECT_NAME}-lib APPEND FILE ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Config.cmake)

# Target: static
add_library(${PROJECT_NAME}-slib STATIC ${${PROJECT_NAME}_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME}-static ALIAS ${PROJECT_NAME}-slib)
set_target_properties(${PROJECT_NAME}-slib PROPERTIES OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT 1)
set_target_properties(${PROJECT_NAME}-slib PROPERTIES PUBLIC_HEADER "${${PROJECT_NAME}_PUBLIC_HEADERS}")
set_target_properties(${PROJECT_NAME}-slib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME}-slib PROPERTIES SOVERSION ${SO_VERSION})
target_include_directories(${PROJECT_NAME}-slib
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}		
)
#target_link_libraries(${PROJECT_NAME}-slib PUBLIC Boost::boost Threads::Threads rt)
#target_link_libraries(${PROJECT_NAME}-slib PRIVATE systemd Boost::system Boost::filesystem Boost::iostreams Boost::program_options)
install(TARGETS ${PROJECT_NAME}-slib
		EXPORT ${PROJECT_NAME}-targets
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
		)
export(TARGETS ${PROJECT_NAME}-slib APPEND FILE ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}Config.cmake)

# Configurations files
file(GLOB_RECURSE ${PROJECT_NAME}_CONFIGS ${CMAKE_CURRENT_SOURCE_DIR}/conf/*)
if (${PROJECT_NAME}_CONFIGS)
	install(FILES ${${PROJECT_NAME}_CONFIGS} DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}/${PROJECT_NAME})
endif()

# Target: Tests
add_subdirectory(tests)

# Install
include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake)
install(EXPORT ${PROJECT_NAME}-targets FILE ${PROJECT_NAME}Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}/cmake)

# Package
export(PACKAGE ${PROJECT_NAME})
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/_package/${PROJECT_NAME}Config.cmake "# Empty file to trick find_package when added by add_subdirectory")
set(${PROJECT_NAME}_DIR ${CMAKE_CURRENT_BINARY_DIR}/_package CACHE PATH "${PROJECT_NAME} config directory" FORCE)

# CPack
set(CPACK_GENERATOR TGZ)	
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_TGZ_COMPONENT_INSTALL ON)
include(CPack)
