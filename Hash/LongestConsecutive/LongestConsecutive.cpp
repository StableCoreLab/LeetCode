#include "LongestConsecutive.h"
#include <unordered_set>

int LongestConsecutive::Solve(vector<int>& nums)
{
    int result = 0;
    unordered_set<int> numsSet(nums.begin(), nums.end());
    for (auto num : numsSet)
    {
        if (!numsSet.count(num - 1))
        {
            int current = num;
            int length = 1;
            while (numsSet.count(current+1))
            {
                current++;
                length++;
            }
            result = std::max(result, length);
        }
    }
    return result;
}
