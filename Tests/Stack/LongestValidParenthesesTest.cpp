#include <gtest/gtest.h>
#include "stack/LongestValidParentheses/LongestValidParentheses.h"

TEST(LongestValidParenthesesTest, Test1)
{
    LongestValidParentheses solver;
    std::string input = "(()";
    int expected = 2;
    EXPECT_EQ(solver.Solve(input), expected);
}