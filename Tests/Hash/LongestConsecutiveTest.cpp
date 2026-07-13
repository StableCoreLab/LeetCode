#include <gtest/gtest.h>
#include "Hash/LongestConsecutive/LongestConsecutive.h"

TEST(LongestConsecutiveTest, Test1)
{
    LongestConsecutive lc;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(lc.Solve(nums), 4);
    nums = {100, 4, 200, 1, 3, 6};
    EXPECT_EQ(lc.Solve(nums), 2);
}
