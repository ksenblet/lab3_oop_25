cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(main
    src/main.cpp
    src/point.cpp
    src/figure.cpp
    src/triangle.cpp
    src/square.cpp
    src/octagon.cpp
    src/arrayPoints.cpp
    src/arrayFigures.cpp
)

add_executable(figure_tests
    tests/pointTest.cpp
    tests/figuresTest.cpp
    tests/arraysTest.cpp
    src/point.cpp
    src/figure.cpp
    src/triangle.cpp
    src/square.cpp
    src/octagon.cpp
    src/arrayPoints.cpp
    src/arrayFigures.cpp
)

target_link_libraries(figure_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(figure_tests)