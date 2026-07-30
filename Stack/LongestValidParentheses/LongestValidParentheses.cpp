#include "LongestValidParentheses.h"
#include <vector>
#include <stack>

int LongestValidParentheses::Solve(const std::string& s)
{
    std::stack<int> parenthesesStack;
    int maxLength = 0;
    parenthesesStack.push(-1);
    for (int i = 0; i < static_cast<int>(s.size()); ++i)
    {
        if (s[i] == ')')
        {
            parenthesesStack.pop();
            if (parenthesesStack.empty())
                parenthesesStack.push(i);
            else
            {
                maxLength = (std::max)(maxLength, i - parenthesesStack.top());
            }
        } else
        {
            parenthesesStack.push(i);
        }
    }
    return maxLength;
}

int LongestValidParentheses::Solvedp(const std::string& s)
{
    if (s.size() <= 1)
        return 0;
    std::vector dp(s.size(), 0);
    int maxLength = 0;
    int strLength = static_cast<int>(s.size());
    for (int i = 1; i < strLength; ++i)
    {
        if (s[i] == ')')
        {
            // 情况1：()
            if (s[i - 1] == '(')
            {
                dp[i] = 2;
                if (i >= 2)
                    dp[i] += dp[i - 2];
                // dp[i] = (i>=2?dp[i-2]:0)+2;
            }
            // 情况2：(()) 或 ()(())
            else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + 2;
                int preIndex = i - dp[i - 1] - 2;
                if (preIndex >= 0)
                    dp[i] += dp[preIndex];
            }
            maxLength = (std::max)(maxLength, dp[i]);
        }
    }
    return maxLength;
}

int LongestValidParentheses::SolveTwoPass(const std::string& s)
{
    int maxLength = 0;
    int left = 0;
    int right = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            ++left;
        } else
        {
            ++right;
        }
        if (left == right)
        {
            maxLength = (std::max)(maxLength, right * 2);
        } else if (right > left)
        {
            left = right = 0;
        }
    }

    left = right = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == ')')
        {
            ++right;
        } else
        {
            ++left;
        }
        if (left == right)
        {
            maxLength = (std::max)(maxLength, left * 2);
        } else if (left > right)
        {
            left = right = 0;
        }
    }
    return maxLength;
}
