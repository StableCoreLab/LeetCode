#include "TwoNums.h"
#include <unordered_map>

std::vector<int> TwoNums::Solve(std::vector<int>& nums, int target)
{
    std::vector<int> result;
    std::unordered_map<int, int> numMap;
    for(auto i = 0; i < nums.size(); ++i)
    {
        numMap[nums[i]] = i;
    }
    for(auto i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        if(numMap.find(complement) != numMap.end() && numMap[complement] != i)
        {
            result.push_back(i);
            result.push_back(numMap[complement]);
            numMap.erase(nums[i]);
            numMap.erase(complement);
        }
    }
    return result;
}
