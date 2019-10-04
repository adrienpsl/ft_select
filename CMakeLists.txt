cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 99)

# ------------------------------------------------------------------------------
#    Set up
# ------------------------------------------------------------------------------
project(ft_select C)

# ------------------------------------------------------------------------------
#    compilation flag
# ------------------------------------------------------------------------------
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
add_subdirectory(libft)

# ------------------------------------------------------------------------------
#    Libary Init
# ------------------------------------------------------------------------------
add_library(${PROJECT_NAME}_lib "")
target_include_directories(${PROJECT_NAME}_lib PUBLIC includes)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME}_lib libft)

# ------------------------------------------------------------------------------
#    Project Binary
# ------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

## ------------------------------------------------------------------------------
##    Unit test Binary
## ------------------------------------------------------------------------------
#add_executable(${PROJECT_NAME}_unit_test unit.test/main.test.c)
#add_subdirectory(unit.test)
#target_link_libraries(${PROJECT_NAME}_unit_test ${PROJECT_NAME}_lib)
#
#
## ------------------------------------------------------------------------------
##    End to End binary
## ------------------------------------------------------------------------------
#add_executable(${PROJECT_NAME}_e2e main/ft_ms.main.test_mode.c)
#target_link_libraries(${PROJECT_NAME}_e2e ${PROJECT_NAME}_lib)
