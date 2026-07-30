#include <gtest/gtest.h>
#include "stack/LongestValidParentheses/LongestValidParentheses.h"

TEST(LongestValidParenthesesTest, TestSolve1)
{
    LongestValidParentheses solver;
    std::string input = "(()";
    int expected = 2;
    EXPECT_EQ(solver.Solve(input), expected);
}
TEST(LongestValidParenthesesTest, TestSolve2)
{
    LongestValidParentheses solver;
    std::string input = ")()())";
    int expected = 4;
    EXPECT_EQ(solver.Solve(input), expected);
}

TEST(LongestValidParenthesesTest, TestSolvedp)
{
    LongestValidParentheses solver;
    std::string input = "(()";
    int expected = 2;
    EXPECT_EQ(solver.Solvedp(input), expected);
    input = ")()())";
    expected = 4;
    EXPECT_EQ(solver.Solvedp(input), expected);
}

TEST(LongestValidParenthesesTest, TestSolveTwoPass)
{
    LongestValidParentheses solver;
    std::string input = "(()";
    int expected = 2;
    EXPECT_EQ(solver.SolveTwoPass(input), expected);
    input = ")()())";
    expected = 4;
    EXPECT_EQ(solver.SolveTwoPass(input), expected);
}
