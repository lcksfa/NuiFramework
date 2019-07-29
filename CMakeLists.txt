cmake_minimum_required(VERSION 3.0.0)
set(This myboy)
project(${This} VERSION 0.1.0)
enable_testing()

add_subdirectory(toolkits)
add_subdirectory(src)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
