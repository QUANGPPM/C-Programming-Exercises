cmake_minimum_required(VERSION 3.25)
project(C_Assigments C)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Export compile commands for language servers and tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#library
set(LIB_SOURCES
    hardware.c
    Logger/logger.c
    Motor/motor.c
)

# create excecute target
add_executable(main main.c ${LIB_SOURCES})

# Include directories
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR} Logger Motor)
