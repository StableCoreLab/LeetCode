#include <gtest/gtest.h>
#include "Hash/TwoNums/TwoNums.h"

TEST(TwoNumsTest, TestCase1)
{
    TwoNums twoNums;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected = {0, 1};
    std::vector<int> result = twoNums.Solve(nums, target);
    EXPECT_EQ(result, expected);
}