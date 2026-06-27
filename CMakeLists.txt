
cmake_minimum_required(VERSION 3.10)
project(C-Assigments C)

add_executable(C-Assigments
    main.c
    ActivityLog/activity_log.c
    Logger/logger.c
    TaskNode/task_node.c
)

target_include_directories(C-Assigments PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ActivityLog
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/TaskNode
)
