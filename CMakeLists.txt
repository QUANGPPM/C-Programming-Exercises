cmake_minimum_required(VERSION 3.10) # Specify the minimum required CMake version
project(MyGameEngine CXX) # Define your project name and specify C++ as the language

# Set output directory for executables to keep the build directory clean
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17) # Set the C++ standard to C++17 (or 14, 20, etc., as needed)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure the specified C++ standard is strictly enforced
set(CMAKE_CXX_EXTENSIONS OFF) # Disable GNU extensions to ensure compliance with the C++ standard

# Explicitly list source files for better reliability and maintainability.
# This avoids issues with CMake not detecting new files added via globbing.
add_executable(my_game_engine
    main.cpp
    game_engine/Character.cpp
    game_engine/Weapon.cpp # Assuming this file exists
    # Add any other .cpp files here as your project grows, e.g., game_engine/Skill.cpp
)

# Set common compiler flags for the target
target_compile_options(my_game_engine PRIVATE
    -Wall -Wextra -Wpedantic # Enable common warnings for better code quality and catching potential issues
)

# Set specific compiler flags for Debug and Release configurations
target_compile_options(my_game_engine PRIVATE
    $<$<CONFIG:Debug>:-g> # Enable debug symbols in Debug builds for easier debugging
    $<$<CONFIG:Release>:-O3 -DNDEBUG> # Enable aggressive optimizations and define NDEBUG in Release builds for performance
)

# Use target_include_directories to associate include paths directly with the target.
# 'PRIVATE' means these include directories are only used when compiling 'my_game_engine'.
target_include_directories(my_game_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/game_engine
    # Add other include directories if your project structure requires them
)
