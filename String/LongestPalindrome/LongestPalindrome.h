#pragma once
#include <string>

class LongestPalindrome {
public:
    std::string Solve(const std::string& s);

private:
    int AroundCenter(const std::string& s, int left, int right);
};
