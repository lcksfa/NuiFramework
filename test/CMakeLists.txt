cmake_minimum_required(VERSION 3.0.0)
set(This unittest)

# unittest
# catch2 test head#############################
find_path(CATCH_INCLUDE_DIR catch.hpp)
include_directories(${CATCH_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/logic)
add_executable(${This}
	test_me.cc
)
target_link_libraries(${This} logic)
add_test(
    NAME ${This}
    COMMAND ${This}
    )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)