#include "ThreeSum.h"
#include <algorithm>

std::vector<std::vector<int>> ThreeSum::Solve(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    size_t n = nums.size();
    for (size_t i = 0; i < n - 2; ++i)
    {
        //固定第1个数去重
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        if(nums[i]>0)
        {
            break;
        }

        size_t left = i + 1;
        size_t right = n -1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                //固定第2个数去重
                while(left < right && nums[left] == nums[left + 1])
                {
                    ++left;
                }
                //固定第3个数去重
                while(left < right && nums[right] == nums[right -1])
                {
                    --right;
                }
                ++left;
                --right;
            }else if(sum < 0)
            {
                ++left;
            }else
            {
                --right;
            }
        }
    }
    return result;
}
