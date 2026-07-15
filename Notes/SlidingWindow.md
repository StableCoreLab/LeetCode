# Sliding Window

## 适用场景

- 连续子串 / 子数组
- 需要维护一个动态区间
- 题目要求“最长”“最短”“所有满足条件的起点”

## 当前题目对应

### `3. Longest Substring Without Repeating Characters`

窗口定义：

- `left` 到 `right` 表示当前无重复子串
- `unordered_map<char, int>` 记录字符最近一次出现的位置

更新规则：

- 扩张：`right` 每次向右走一格
- 如果当前字符在窗口内重复，移动 `left`
- 每次更新答案 `right - left + 1`

关键点：

- `left` 不能回退，只能右移
- 记录的是“最近位置”，不是出现次数

### `30. Substring with Concatenation of All Words`

这是“定长单词版滑动窗口”：

- 每个单词长度相同
- 窗口每次按 `wordLength` 跳
- 需要两个哈希表：
  - `need`：目标单词频次
  - `window`：当前窗口频次

做法：

- 从 `0` 到 `wordLength - 1` 分别作为起点
- `right` 每次取一个定长单词
- 如果单词合法，加入窗口并检查是否超频
- 超频时不断移动 `left`
- 当窗口内单词数等于 `wordCount` 时记录答案

## 通用模板

```cpp
for (int left = 0, right = 0; right < n; ++right) {
    加入 s[right];

    while (窗口不合法) {
        移除 s[left];
        ++left;
    }

    更新答案;
}
```

## 复杂度

### `Longest Substring Without Repeating Characters`

- 时间复杂度：`O(n)`
- 空间复杂度：`O(k)`，`k` 为字符种类数

### `Substring with Concatenation of All Words`

- 时间复杂度：`O(n * wordLength)` 量级
- 空间复杂度：`O(m)`，`m` 为不同单词数

## 易错点

- 把“子串”问题写成回溯，复杂度容易失控。
- `left` 收缩时要同步维护窗口状态。
- 定长单词窗口里，指针移动步长不是 `1`，而是 `wordLength`。
- 出现非法单词时，要整体清空当前窗口状态。
