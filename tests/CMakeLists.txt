cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Google Test is a C++ framework, so test executables are C++.
set(TEST_SOURCES
    unit_test.cpp
)

add_executable(project_tests ${TEST_SOURCES})

target_link_libraries(project_tests PRIVATE
    project_lib
    gtest_main
)

target_include_directories(project_tests PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/App
    ${CMAKE_SOURCE_DIR}/ConfigManager
    ${CMAKE_SOURCE_DIR}/ErrorHandling
    ${CMAKE_SOURCE_DIR}/Logger
)

include(GoogleTest)
gtest_discover_tests(project_tests)
