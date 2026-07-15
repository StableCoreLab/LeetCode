# STL

## 当前题目里用到的 STL 组件

- `vector`
  - 动态数组，适合保存答案、下标列表、分组结果。
  - 当前题目：
    - `Two Sum` 返回两个下标
    - `Three Sum` 返回三元组列表
    - `Group Anagrams` 返回分组后的二维数组

- `string`
  - 适合处理子串、回文、排序后的 key。
  - 当前题目：
    - `Longest Palindrome`
    - `Substring with Concatenation of All Words`
    - `Group Anagrams`

- `unordered_map`
  - 平均 `O(1)` 查找，适合做计数、位置记录、映射。
  - 当前题目：
    - `Two Sum`
    - `Longest Substring Without Repeating Characters`
    - `Group Anagrams`
    - `Substring with Concatenation of All Words`

- `unordered_set`
  - 平均 `O(1)` 判存在，适合去重和快速判断。
  - 当前题目：
    - `Longest Consecutive Sequence`

- `sort`
  - 排序后常和双指针、分组 key 一起使用。
  - 当前题目：
    - `Three Sum`
    - `Group Anagrams`

- `max` / `min`
  - 更新区间答案、处理中位数分割边界。
  - 当前题目：
    - `Longest Substring Without Repeating Characters`
    - `Longest Consecutive Sequence`
    - `Median of Two Sorted Arrays`

## 常见写法

```cpp
std::sort(nums.begin(), nums.end());

std::unordered_map<char, int> lastIndex;
std::unordered_set<int> numsSet(nums.begin(), nums.end());

result.push_back({a, b, c});
```

## 使用要点

- `unordered_map` / `unordered_set` 不保证遍历顺序。
- `sort` 会修改原数组，题目不允许改动时要先拷贝。
- `substr(pos, len)` 会创建新字符串，频繁调用时要注意常数开销。
- `vector<vector<int>>`、`vector<vector<string>>` 很适合直接表示分组类答案。

## 对应题目

- `1. Two Sum`
- `3. Longest Substring Without Repeating Characters`
- `4. Median of Two Sorted Arrays`
- `15. Three Sum`
- `49. Group Anagrams`
- `128. Longest Consecutive Sequence`
- `5. Longest Palindromic Substring`
- `30. Substring with Concatenation of All Words`
