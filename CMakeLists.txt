cmake_minimum_required(VERSION 3.10)

# Set the name of your project
project(GameEngine CXX)

# Set the desired C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Ensure compliance with the C++ standard

# Collect source files from the root directory and specific subdirectories.
# This approach allows adding new .cpp files to these locations without
# modifying CMakeLists.txt, while avoiding unintended files (like CMake's internal ones).
# If you add new top-level subdirectories with source files, you would need to add
# another 'file(GLOB ...)' line for that new directory.
file(GLOB ROOT_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB GAME_ENGINE_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/game_system/*.cpp")

set(SOURCE_FILES ${ROOT_SOURCE_FILES} ${GAME_ENGINE_SOURCE_FILES})

# Add directories containing header files (.hpp) to the search path
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/game_system # To find Character.hpp
)

# Create an executable named 'my_game_engine' from the found source files
add_executable(my_game ${SOURCE_FILES})