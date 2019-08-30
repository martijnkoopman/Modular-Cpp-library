cmake_minimum_required(VERSION 3.3)

project(foolib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

option(BUILD_TESTING "Build the testing tree." OFF)
if(BUILD_TESTING)
	enable_testing()
endif()

add_subdirectory(foo)
add_subdirectory(app)