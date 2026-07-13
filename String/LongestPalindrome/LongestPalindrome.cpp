#include "LongestPalindrome.h"

std::string LongestPalindrome::Solve(const std::string& s)
{
    int length = static_cast<int>(s.size());
    if (length < 2)
        return s;
    int maxLength = 1;
    int maxStart = 0;

    for (int i = 0; i < length; ++i)
    {
        // 奇数长度回文，例如 aba
        int currentLength = AroundCenter(s, i, i);

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            maxStart = i - (currentLength - 1) / 2;
        }

        // 偶数长度回文，例如 abba
        currentLength = AroundCenter(s, i, i + 1);

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            maxStart = i - (currentLength - 1) / 2;
        }
    }
    return s.substr(maxStart, maxLength);
}

int LongestPalindrome::AroundCenter(const std::string& s, int left, int right)
{
    int length = static_cast<int>(s.size());
    int maxLength = 0;
    while (left >= 0 && right < length && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return right - left - 1;
}
