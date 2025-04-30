cmake_minimum_required(VERSION 3.10)
project(Wojna)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/gra.cpp
    src/karty.cpp
)

set(TEST_SOURCES
    tests/test.cpp
    src/gra.cpp
    src/karty.cpp
)

add_executable(stl_wojna ${SOURCES})

add_executable(stl_tests ${TEST_SOURCES})
