cmake_minimum_required(VERSION 3.0.0)
set(This module)
FILE(GLOB SRCFILES *.cc)
add_library(${This} STATIC ${SRCFILES})

# add fmt library
find_package(fmt CONFIG REQUIRED)
# add sqlite3 library
find_package(sqlite3 CONFIG REQUIRED)
target_link_libraries(${This} PRIVATE fmt::fmt fmt::fmt-header-only sqlite3 base shared)
