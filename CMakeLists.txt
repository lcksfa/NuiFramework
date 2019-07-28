cmake_minimum_required(VERSION 3.0.0)
set(This v3myboy)
project(${This} VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(include)
# add all the cc file automate in src folder
FILE(GLOB SRCFILES src/*.cc)
# set(SOURCES src/*.cc  main.cc)
# add_executable(${This} ${SOURCES})
add_library(${This} ${SRCFILES})

# add fmt library
find_package(fmt CONFIG REQUIRED)
# add sqlite3 library
find_package(sqlite3 CONFIG REQUIRED)
target_link_libraries(${This} PRIVATE fmt::fmt fmt::fmt-header-only sqlite3)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# unittest
# catch2 test head#############################
find_path(CATCH_INCLUDE_DIR catch.hpp)
include_directories(${CATCH_INCLUDE_DIR})
add_executable(unit_tests
	test/test_me.cc
)
target_link_libraries(unit_tests ${This})
add_test(
    NAME ${This}
    COMMAND unit_tests
    )


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)