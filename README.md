# LeetCode

刷 LeetCode 的 C++ 练习仓库，使用 `CMake + GoogleTest` 管理题解与测试。

## 目录结构

```text
LeetCode/
|-- CMakeLists.txt                 # 顶层 CMake 配置
|-- README.md                      # 仓库说明、刷题统计
|-- .gitignore
|
|-- Docs/                          # 每题题解、思路记录
|   |-- 0001_TwoSum.md
|   |-- 0002_AddTwoNumbers.md
|   |-- 0015_ThreeSum.md
|   |-- ...
|
|-- Notes/                         # 算法知识总结
|   |-- STL.md
|   |-- BinarySearch.md
|   |-- TwoPointers.md
|   |-- SlidingWindow.md
|   |-- DynamicProgramming.md
|   |-- Graph.md
|   |-- ...
|
|-- Templates/                     # 常用算法模板
|   |-- BinarySearch.h
|   |-- UnionFind.h
|   |-- SegmentTree.h
|   |-- FenwickTree.h
|   |-- Trie.h
|   |-- Dijkstra.h
|   |-- ...
|
|-- Utils/                         # 公共工具
|   |-- ListNode.h
|   |-- TreeNode.h
|   |-- Print.h
|   |-- Random.h
|   |-- TestHelper.h
|
|-- Progress/                      # 刷题记录
|   |-- 2026-07.md
|   |-- 2026-08.md
|   |-- ...
|
|-- Array/
|   |-- ThreeSum/
|   |   |-- ThreeSum.h
|   |   |-- ThreeSum.cpp
|   |-- ...
|
|-- LinkedList/
|   |-- ...
|
|-- String/
|
|-- Hash/
|   |-- GroupAnagrams/
|   |   |-- GroupAnagrams.h
|   |   |-- GroupAnagrams.cpp
|   |-- LengthOfLongestSubstring/
|   |   |-- LengthOfLongestSubstring.h
|   |   |-- LengthOfLongestSubstring.cpp
|   |-- LongestConsecutive/
|   |   |-- LongestConsecutive.h
|   |   |-- LongestConsecutive.cpp
|   |-- TwoNums/
|   |   |-- TwoNums.h
|   |   |-- TwoNums.cpp
|   |-- ...
|
|-- Stack/
|
|-- Queue/
|
|-- BinarySearch/
|   |-- FindMedianSortedArrays/
|   |   |-- FindMedianSortedArrays.h
|   |   |-- FindMedianSortedArrays.cpp
|   |-- ...
|
|-- Tree/
|
|-- Graph/
|
|-- Heap/
|
|-- Backtracking/
|
|-- DynamicProgramming/
|
|-- Greedy/
|
|-- Trie/
|
|-- UnionFind/
|
|-- PrefixSum/
|
|-- Bit/
|
|-- Math/
|
|-- Tests/
|   |-- Array/
|   |   |-- ThreeSumTest.cpp
|   |   |-- ...
|   |-- BinarySearch/
|   |   |-- FindMedianSortedArraysTest.cpp
|   |   |-- ...
|   |-- Hash/
|   |   |-- GroupAnagramsTest.cpp
|   |   |-- LengthOfLongestSubstring.cpp
|   |   |-- LongestConsecutiveTest.cpp
|   |   |-- TwoNumTest.cpp
|   |-- LinkedList/
|   |-- Tree/
|   |-- Graph/
|   |-- ...
|
|-- Build/                         # 本地构建目录
```

## 已完成题目

### Array

- `15. Three Sum` - Medium

### Binary Search

- `4. Median of Two Sorted Arrays` - Hard

### Hash

- `1. Two Sum` - Easy
- `3. Longest Substring Without Repeating Characters` - Medium
- `49. Group Anagrams` - Medium
- `128. Longest Consecutive Sequence` - Medium

## 测试覆盖

- `Tests/Array/ThreeSumTest.cpp`
- `Tests/BinarySearch/FindMedianSortedArraysTest.cpp`
- `Tests/Hash/GroupAnagramsTest.cpp`
- `Tests/Hash/LengthOfLongestSubstring.cpp`
- `Tests/Hash/LongestConsecutiveTest.cpp`
- `Tests/Hash/TwoNumTest.cpp`

## 统计

- Easy: `1`
- Medium: `4`
- Hard: `1`
- Total: `6`
