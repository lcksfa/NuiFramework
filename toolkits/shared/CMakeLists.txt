# cmake file for duilib
#Author lcksfa(yousaid820@163.com)
#Created: 2019/07/29

set(This shared)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} Root_src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(../)
add_definitions(-DUNICODE -D_UNICODE)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(${This} STATIC  ${Root_src})

set_target_properties(${This} PROPERTIES OUTPUT_NAME "shared")
# add_custom_command(TARGET ${This} POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   ${PROJECT_BINARY_DIR}/lib/duilib.dll ${PROJECT_SOURCE_DIR}/bin/duilib.dll)
