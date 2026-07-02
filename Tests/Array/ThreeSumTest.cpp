#include <gtest/gtest.h>

#include "Array/ThreeSum/ThreeSum.h"

TEST(ThreeSumTest, Example1)
{
    ThreeSum solver;

    std::vector<int> nums{-1, 0, 1, 2, -1, -4};

    auto result = solver.Solve(nums);

    EXPECT_EQ(result.size(), 2);
}