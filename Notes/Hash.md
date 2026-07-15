# Hash

## 适用场景

- 快速判断某个值是否存在
- 记录元素出现位置
- 做计数、分组、去重

## 当前题目对应

### `1. Two Sum`

- `unordered_map<值, 下标>`
- 一边遍历，一边查 `target - nums[i]` 是否已经出现

当前仓库实现是先建表再查找，也能做出来，但更常见的是单次遍历：

```cpp
for (int i = 0; i < nums.size(); ++i) {
    int x = target - nums[i];
    if (numMap.count(x)) return {numMap[x], i};
    numMap[nums[i]] = i;
}
```

### `49. Group Anagrams`

- 把排序后的字符串作为 key
- `unordered_map<string, vector<string>>` 做分组

### `128. Longest Consecutive Sequence`

- 用 `unordered_set` 存所有数字
- 只从“连续段起点”开始扩展
- 起点判定：`num - 1` 不存在

这样每个数最多被访问常数次，避免重复扩展。

### `3. Longest Substring Without Repeating Characters`

- 哈希表记录字符最近出现位置
- 配合滑动窗口维护无重复区间

### `30. Substring with Concatenation of All Words`

- `need` 记录目标词频
- `window` 记录当前词频

## 常见模型

- `值 -> 下标`
- `值 -> 次数`
- `排序后字符串 -> 分组列表`
- `集合判存在`

## 复杂度特点

- 平均时间复杂度通常是 `O(1)` 查找 / 插入
- 最坏情况下可能退化，但面试和题解里通常按平均复杂度分析

## 易错点

- `unordered_map[key]` 会在 key 不存在时自动插入默认值。
- 分组题里如果 key 设计不稳定，结果就会错。
- 用集合做连续序列时，不要从每个元素都往后扩展，否则会退化成 `O(n^2)`。
