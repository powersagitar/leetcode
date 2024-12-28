cmake_minimum_required(VERSION 3.31)

project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(
    jump-game-brute-force
    55-jump-game/brute-force.cc
)

target_link_libraries(
    jump-game-brute-force
    GTest::gtest_main
)

add_executable(
    jump-game
    55-jump-game/main.cc
)

target_link_libraries(
    jump-game
    GTest::gtest_main
)
