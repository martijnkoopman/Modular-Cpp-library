project(foo)

option(BUILD_SHARED_LIBS "Build spatiumgl as shared library." ON)
set(CMAKE_DEBUG_POSTFIX "d")

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

# Install CMake config file
set(INSTALL_INCLUDE_DIRS ${CMAKE_INSTALL_PREFIX}/include)
set(INSTALL_LIBRARIES ${CMAKE_INSTALL_PREFIX}/lib/foo.lib ${CMAKE_INSTALL_PREFIX}/lib/food.lib)
include(CMakePackageConfigHelpers)
configure_package_config_file(FooConfig.cmake.in 
							  ${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake
                              INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}
                              PATH_VARS INSTALL_INCLUDE_DIRS INSTALL_LIBRARIES)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake 
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})