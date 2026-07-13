#include <gtest/gtest.h>
#include "BinarySearch/FindMedianSortedArrays/FindMedianSortedArrays.h"

TEST(FindMedianSortedArraysTest, Test1)
{
    FindMedianSortedArrays findMedian;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    auto result = findMedian.Solve(nums1, nums2);
    EXPECT_DOUBLE_EQ(result, 2.0);
    result = findMedian.Solve({}, {});
    EXPECT_DOUBLE_EQ(result, 0.0);
    
    // Add assertions here
}
