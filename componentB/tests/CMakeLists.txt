# find_package(GTest REQUIRED)
# find_package(fakeit REQUIRED)

# file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/files)
# file(GLOB TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/files/*)
# file(COPY ${TESTS_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/files)

# if (${${PROJECT_NAME}_CONFIGS}})
# 	file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/conf)
# 	file(COPY ${${PROJECT_NAME}_CONFIGS}} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/conf)
# endif()

# include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME})

# FILE(GLOB TESTS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
# foreach(file ${TESTS_SOURCES})

# 	file(RELATIVE_PATH testname ${CMAKE_SOURCE_DIR} ${file})
# 	string(REGEX REPLACE "\.cpp" "" testname ${testname})
# 	string(REGEX REPLACE " " "_" testname ${testname})
# 	string(REGEX REPLACE "\\\\" "/" testname ${testname})
# 	string(REGEX REPLACE "/" "-" testname ${testname})

# 	add_executable(${testname} ${file})
# 	target_link_libraries(${testname} PRIVATE gmock_main gmock gtest dl fakeit ${PROJECT_NAME}-slib)
# 	target_include_directories(${testname} SYSTEM BEFORE INTERFACE "${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")

# 	#add_test(${testname} ${testname})
# 	gtest_discover_tests(${testname} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# 	# if (INSTALL_TESTS)
# 	# 	install(TARGETS ${testname}	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})		
# 	# endif()
	
# endforeach(file)
