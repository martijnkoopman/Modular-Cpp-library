project(foolib)

option(BUILD_SHARED_LIBS "Build spatiumgl as shared library." ON)

add_subdirectory(core)
add_subdirectory(extension)

# Create library
add_library(foolib foo.cpp)
set_target_properties(foolib PROPERTIES LINKER_LANGUAGE CXX)

# Set compile definitions to export symbols
target_compile_definitions(foolib PRIVATE FOO_LIBRARY=1)
if (BUILD_SHARED_LIBS)
	target_compile_definitions(foolib PRIVATE FOO_SHARED=1)
endif()

# Link core and extension
target_link_libraries(foolib PUBLIC core)
target_link_libraries(foolib PUBLIC extension)

# Install library
install(TARGETS foolib)
install(DIRECTORY ${aa} core/include/ extension/include/ DESTINATION include
        FILES_MATCHING PATTERN "*.hpp")

# Unit testing
if(BUILD_TESTING)
	add_subdirectory(core/test)
	add_subdirectory(extension/test)
endif()