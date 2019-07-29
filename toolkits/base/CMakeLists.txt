# cmake file for duilib
#Author lcksfa(yousaid820@163.com)
#Created: 2019/07/29

set(This base)
set(cxx)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} Root_src)
FILE(GLOB SRCFILES
  encrypt/*.cpp
  file/*.cpp
  framework/*.cpp
  hardware/*.cpp
  memory/*.cpp
  network/*.cpp
  synchronzation/*.cpp
  thread/*.cpp
  time/*.cpp
  util/*.cpp
  win32/*.cpp )
include_directories(../)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DUNICODE -D_UNICODE)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(${This} STATIC  ${SRCFILES})

set_target_properties(${This} PROPERTIES OUTPUT_NAME "base")
