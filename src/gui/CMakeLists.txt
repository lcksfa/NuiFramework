cmake_minimum_required(VERSION 3.0.0)

include_directories(${PROJECT_SOURCE_DIR}/toolkits)
include_directories(${PROJECT_SOURCE_DIR}/src)
add_definitions(-DUNICODE -D_UNICODE)
# add all the cc file automate in src folder
FILE(GLOB SRCFILES *.cc)
# set(SOURCES src/*.cc  main.cc)
add_executable(${PROJECT_NAME} ${SRCFILES} mydearboy.rc)
target_link_libraries(${PROJECT_NAME} PRIVATE  base shared  duilib module)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)