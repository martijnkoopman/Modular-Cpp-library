project(foo)

option(BUILD_SHARED_LIBS "Build spatiumgl as shared library." ON)

add_subdirectory(core)
add_subdirectory(extension)

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
target_link_libraries(foo PUBLIC extension)

# Install library
install(TARGETS foo)
install(DIRECTORY ${aa} core/include/ extension/include/ DESTINATION include
        FILES_MATCHING PATTERN "*.hpp")

# Unit testing
if(BUILD_TESTING)
	add_subdirectory(core/test)
	add_subdirectory(extension/test)
endif()