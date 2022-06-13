cmake_minimum_required(VERSION 3.21)

project(GTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        GTest GTest.cpp
        ../include/OneParameter.h
        ../include/TwoParameter.h
        ../include/OneParameter.inl
        ../include/TwoParameter.inl
        ../include/Handler.h
        ../include/Handler.inl)

include_directories(
        ../include
        ../src
)

## Googletest add

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_test(GTest example_test COMMAND example)
include(GoogleTest)
gtest_discover_tests(GTest)

target_include_directories(GTest PUBLIC ${CMAKE_SOURCE_DIR}/include/)

target_link_libraries(GTest PRIVATE gtest_main)