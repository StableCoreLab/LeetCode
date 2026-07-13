#include<gtest/gtest.h>
#include "Hash/LengthOfLongestSubstring/LengthOfLongestSubstring.h"


TEST(LengthOfLongestSubstringTest, Test1)
{
    LengthOfLongestSubstring lengthOfLongestSubstring;
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring.Solve(s);
    ASSERT_EQ(result, 3);
}