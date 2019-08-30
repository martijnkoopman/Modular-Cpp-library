project(core_test LANGUAGES CXX)

add_executable(core_test test_CoreClass.cpp)

target_link_libraries(core_test PRIVATE foo)

add_test(NAME core_test COMMAND $<TARGET_FILE:core_test>)
