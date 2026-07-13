#include "LengthOfLongestSubstring.h"

int LengthOfLongestSubstring::Solve(std::string& text)
{
    std::unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    for(auto left = 0, right = 0; right < text.length(); ++right)
    {
        char currentChar = text[right];
        if(charIndexMap.count(currentChar) && charIndexMap[currentChar] >= left)
        {
            left = charIndexMap[currentChar] + 1, left;
        }
        charIndexMap[currentChar] = right;
        maxLength = std::max(maxLength, right - left + 1);
    }
    return maxLength;
}