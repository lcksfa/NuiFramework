cmake_minimum_required(VERSION 3.0.0)
set(This module)
FILE(GLOB SRCFILES *.cc)
add_library(${This} STATIC ${SRCFILES})
# add fmt library
find_package(fmt CONFIG REQUIRED)
# add sqlite3 library
find_package(sqlite3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${This} PRIVATE fmt::fmt fmt::fmt-header-only spdlog::spdlog sqlite3 base shared)
find_package(cpprestsdk CONFIG REQUIRED)
# Note: 1 target(s) were omitted.
target_link_libraries(${This} PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_boost_internal cpprestsdk::cpprestsdk_openssl_internal)
