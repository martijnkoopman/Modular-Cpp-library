file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(extension STATIC ${sources} ${headers})
set_target_properties(extension PROPERTIES CXX_STANDARD 11 LINKER_LANGUAGE CXX)
target_compile_definitions(extension PRIVATE FOO_LIBRARY=1)

target_include_directories(extension PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)
	
target_link_libraries(extension PRIVATE core)

# Add an extra dependency:
#find_package(OpenGL REQUIRED)
#target_include_directories(extension PRIVATE
#  ${OPENGL_INCLUDE_DIR})
#target_link_libraries(extension PRIVATE ${OPENGL_gl_LIBRARY})
