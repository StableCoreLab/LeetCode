#include <gtest/gtest.h>
#include "String/LongestPalindrome/LongestPalindrome.h"

TEST(LongestPalindromeTest, BasicTests)
{
    LongestPalindrome longestPalindrome;
    EXPECT_EQ(longestPalindrome.Solve(""), "");
    EXPECT_EQ(longestPalindrome.Solve("a"), "a");
    EXPECT_EQ(longestPalindrome.Solve("ac"), "a");  // or "c"
    EXPECT_EQ(longestPalindrome.Solve("abc"), "a");
    EXPECT_EQ(longestPalindrome.Solve("aa"), "aa");
    EXPECT_EQ(longestPalindrome.Solve("babad"), "bab");  // or "aba"
    EXPECT_EQ(longestPalindrome.Solve("cbbd"), "bb");
    EXPECT_EQ(longestPalindrome.Solve("noon"), "noon");
    EXPECT_EQ(longestPalindrome.Solve("abba"), "abba");
    EXPECT_EQ(longestPalindrome.Solve("cbbd"), "bb");
    EXPECT_EQ(longestPalindrome.Solve("racecar"), "racecar");
}
