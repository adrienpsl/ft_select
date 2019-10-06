cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 99)

# ------------------------------------------------------------------------------
#    Set up
# ------------------------------------------------------------------------------
project(ft_select C)

# ------------------------------------------------------------------------------
#    compilation flag
# ------------------------------------------------------------------------------
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wmissing-prototypes")
add_subdirectory(libft)

# ------------------------------------------------------------------------------
#    Libary Init
# ------------------------------------------------------------------------------
file(GLOB_RECURSE sources_files src/*.c)
add_library(${PROJECT_NAME}_lib ${sources_files})
target_include_directories(${PROJECT_NAME}_lib PUBLIC includes)
target_link_libraries(${PROJECT_NAME}_lib libft)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}_lib ${CURSES_LIBRARIES})
# ------------------------------------------------------------------------------
#    Project Binary
# ------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

## ------------------------------------------------------------------------------
##    Unit test Binary
## ------------------------------------------------------------------------------
file(GLOB_RECURSE unit_files unit.test/*.c)
add_executable(${PROJECT_NAME}_unit_test ${unit_files})
target_link_libraries(${PROJECT_NAME}_unit_test ${PROJECT_NAME}_lib)
#
#
## ------------------------------------------------------------------------------
##    End to End binary
## ------------------------------------------------------------------------------
#add_executable(${PROJECT_NAME}_e2e main/ft_ms.main.test_mode.c)
#target_link_libraries(${PROJECT_NAME}_e2e ${PROJECT_NAME}_lib)
