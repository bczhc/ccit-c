add_executable(task1 task1.c lib.c)
target_link_libraries(task1 common-lib)

add_executable(task1-safe task1_safe.c lib.c)
target_link_libraries(task1-safe common-lib)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)
include_directories(${GTK_INCLUDE_DIRS})

add_executable(task1-gtk task1_gtk.c lib.c)
target_link_libraries(task1-gtk ${GTK_LIBRARIES})
target_compile_definitions(
        task1-gtk PRIVATE
        BUILDER_FILE="${CMAKE_CURRENT_SOURCE_DIR}/gtk-ui.ui"
)
target_link_libraries(task1-gtk common-lib)