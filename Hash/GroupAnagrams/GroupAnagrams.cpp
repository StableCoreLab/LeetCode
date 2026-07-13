#include "GroupAnagrams.h"
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> GroupAnagrams::Solve(std::vector<std::string>& strs)
{
    std::vector<std::vector<std::string>> result{};
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
    for (auto& str : strs)
    {
        std::string strCopy = str;
        std::sort(strCopy.begin(), strCopy.end());
        anagramGroups[strCopy].push_back(str);
    }
    for (auto& group : anagramGroups)
    {
        result.push_back(group.second);
    }
    return result;
}
