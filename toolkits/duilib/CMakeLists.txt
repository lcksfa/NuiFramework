# cmake file for duilib
#Author lcksfa(yousaid820@163.com)
#Created: 2019/07/29


aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} Root_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Animation Animation_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Control Control_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Core Core_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Box Box_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Utils Utils_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Render Render_src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Animation)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Box)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Control)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Render)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Utils)
include_directories(../)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(duilib STATIC ${Animation_src} ${Box_src} ${Control_src} ${Core_src} ${Render_src} ${Utils_src} ${Root_src})
add_definitions(-DUNICODE -D_UNICODE)
add_definitions(-DUILIB_EXPORTS)
target_link_libraries(duilib comctl32 base Shlwapi Gdiplus Msimg32 Winmm)
set_target_properties(duilib PROPERTIES OUTPUT_NAME "duilib")
# add_custom_command(TARGET duilib POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   ${PROJECT_BINARY_DIR}/lib/duilib.dll ${PROJECT_SOURCE_DIR}/bin/duilib.dll)
