project(core_test LANGUAGES CXX)

add_executable(${PROJECT_NAME} test_CoreClass.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE foolib)

add_test(unit ${PROJECT_NAME})