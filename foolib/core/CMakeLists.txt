file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(core STATIC ${sources} ${headers})
set_target_properties(core PROPERTIES CXX_STANDARD 11 LINKER_LANGUAGE CXX)
target_compile_definitions(core PRIVATE FOO_LIBRARY=1)

target_include_directories(core PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)