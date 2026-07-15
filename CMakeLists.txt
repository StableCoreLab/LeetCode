cmake_minimum_required(VERSION 3.20)

# VS multi-config generator:
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

# GoogleTest
set(GOOGLETEST_SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/googletest-src")
set(GOOGLETEST_BINARY_DIR "${CMAKE_BINARY_DIR}/_deps/googletest-build")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

if (EXISTS "${GOOGLETEST_SOURCE_DIR}/CMakeLists.txt")
    add_subdirectory("${GOOGLETEST_SOURCE_DIR}" "${GOOGLETEST_BINARY_DIR}" EXCLUDE_FROM_ALL)
else()
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

set(SOURCE_FILES
    Array/ThreeSum/ThreeSum.cpp
    Array/ThreeSum/ThreeSum.h
    BinarySearch/FindMedianSortedArrays/FindMedianSortedArrays.cpp
    BinarySearch/FindMedianSortedArrays/FindMedianSortedArrays.h
    Hash/TwoNums/TwoNums.cpp
    Hash/TwoNums/TwoNums.h
    Hash/GroupAnagrams/GroupAnagrams.cpp
    Hash/GroupAnagrams/GroupAnagrams.h
    Hash/LengthOfLongestSubstring/LengthOfLongestSubstring.cpp
    Hash/LengthOfLongestSubstring/LengthOfLongestSubstring.h
    Hash/LongestConsecutive/LongestConsecutive.cpp
    Hash/LongestConsecutive/LongestConsecutive.h
    String/LongestPalindrome/LongestPalindrome.cpp
    String/LongestPalindrome/LongestPalindrome.h
    String/FindSubString/FindSubString.cpp
    String/FindSubString/FindSubString.h
)

add_executable(LeetCodeTests
    ${SOURCE_FILES}
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
