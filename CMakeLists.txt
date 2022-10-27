project(CCIT-C)
cmake_minimum_required(VERSION 3.19)

set(CMAKE_C_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_definitions(GNU_COMPILER)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.2)
        add_compile_definitions(GCC_BUILTIN_CHECKED_ARITHMETIC)
    endif ()
endif ()

add_library(
        common-lib STATIC
        array.c
        string.c
        common.c
)

add_executable(demo demo.c)
target_link_libraries(demo common-lib)

add_executable(demo2 demo2.c)
target_link_libraries(demo2 common-lib)

add_subdirectory(tasks1)
