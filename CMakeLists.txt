cmake_minimum_required(VERSION 3.20)

# VS 多配置生成器下，统一使用动态库运行时
# Debug -> /MDd
# Release -> /MD
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

project(LeetCodeTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/MP /utf-8)
endif()

#GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# 避免Windows下的GTest 强行使用自己的CRT设置
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES
    Array/ThreeSum/ThreeSum.cpp
    Array/ThreeSum/ThreeSum.h
)

# set(TEST_FILES
#     Tests/Array/ThreeSumTest.cpp
# )

add_executable(LeetCodeTests
    ${SOURCE_FILES}
    # ${TEST_FILES}
)

file(GLOB_RECURSE TEST_FILES
    CONFIGURE_DEPENDS
    Tests/*.cpp
)

target_sources(LeetCodeTests PRIVATE
    ${TEST_FILES}
)

target_include_directories(LeetCodeTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(LeetCodeTests
    PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LeetCodeTests)

