project(foo)

option(BUILD_SHARED_LIBS "Build FOO as shared library." ON)
option(BUILD_FOO_EXTENSION "Build FOO with module EXTENSION." ON)

add_subdirectory(core)
if(BUILD_FOO_EXTENSION)
	add_subdirectory(extension)
endif()

# Create library
add_library(foo foo.cpp)
set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

# Set compile definitions to export symbols
target_compile_definitions(foo PRIVATE FOO_LIBRARY=1)
if (BUILD_SHARED_LIBS)
	target_compile_definitions(foo PRIVATE FOO_SHARED=1)
endif()

# Link core and extension
target_link_libraries(foo PUBLIC core)
if(BUILD_FOO_EXTENSION)
	target_link_libraries(foo PUBLIC extension)
endif()

# Install library
install(TARGETS foo DESTINATION lib)
install(DIRECTORY core/include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
if(BUILD_FOO_EXTENSION)
	install(DIRECTORY extension/include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
endif()

# Unit testing
if(BUILD_TESTING)
	add_subdirectory(core/test)
	if(BUILD_FOO_EXTENSION)
		add_subdirectory(extension/test)
	endif()
endif()