
cmake_minimum_required(VERSION 3.10)
project(CAssignments C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

include_directories(Dispatcher Sensors)

add_executable(CAssignments main.c 
                Dispatcher/dispatcher.c 
                Sensors/sensor.c)

