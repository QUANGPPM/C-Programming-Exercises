cmake_minimum_required(VERSION 3.16)
project(C_Assigments C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

set(LIB_SOURCES
    ConfigManager/config_manager.c
    ErrorHandling/error_handling.c
    Logger/logger.c
)

add_library(project_lib STATIC ${LIB_SOURCES})

target_include_directories(project_lib PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/App
    ${CMAKE_SOURCE_DIR}/ConfigManager
    ${CMAKE_SOURCE_DIR}/ErrorHandling
    ${CMAKE_SOURCE_DIR}/Logger
)

add_executable(C_Assigments App/main.c)
target_link_libraries(C_Assigments PRIVATE project_lib)

target_include_directories(C_Assigments PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/App
    ${CMAKE_SOURCE_DIR}/ConfigManager
    ${CMAKE_SOURCE_DIR}/ErrorHandling
    ${CMAKE_SOURCE_DIR}/Logger
)

add_subdirectory(tests)
