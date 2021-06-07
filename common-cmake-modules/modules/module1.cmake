message("module1 - 1111")

if (MSVC)
	set(CMAKE_STATIC_LIBRARY_SUFFIX "-s.lib" CACHE STRING "" FORCE)
	set(CMAKE_DEBUG_POSTFIX "-dbg" CACHE STRING "" FORCE)
endif()

if (LINUX)
	
endif()
