project(CCIT-C)
cmake_minimum_required(VERSION 3.19)

set(CMAKE_C_STANDARD 17)

add_library(
        my-lib STATIC
        array.c
        string.c
        common.c
)

add_executable(task1 tasks/task1.c)
target_link_libraries(task1 my-lib)

add_executable(task1-safe tasks/task1_safe.c)
target_link_libraries(task1-safe my-lib)

add_executable(demo demo.c)
target_link_libraries(demo my-lib)

add_executable(demo2 demo2.c)
target_link_libraries(demo2 my-lib)
