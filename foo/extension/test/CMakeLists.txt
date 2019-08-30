project(extension_test LANGUAGES CXX)

add_executable(extension_test test_ExtensionClass.cpp)

target_link_libraries(extension_test PRIVATE foo)

add_test(NAME extension_test COMMAND $<TARGET_FILE:extension_test>)
