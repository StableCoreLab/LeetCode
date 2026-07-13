#include "FindMedianSortedArrays.h"
#include <algorithm>
#include <climits>

double FindMedianSortedArrays::Solve(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    if (nums1.empty() && nums2.empty())
    {
        return 0.0;
    }

    if(nums1.size() > nums2.size())
    {
        return Solve(nums2, nums1);
    }

    auto nLength1 = nums1.size();
    auto nLength2 = nums2.size();
    int left = 0, right = nLength1;
    while(left <= right)
    {
        int mediumIndex1 = left + (right - left) / 2;
        int mediumIndex2 = (nLength1 + nLength2 + 1) / 2 - mediumIndex1;

        int nums1LeftMax = (mediumIndex1 == 0) ? INT_MIN : nums1[mediumIndex1 - 1];
        int nums1RightMin = (mediumIndex1 == nLength1) ? INT_MAX : nums1[mediumIndex1];

        int nums2LeftMax = (mediumIndex2 == 0) ? INT_MIN : nums2[mediumIndex2 - 1];
        int nums2RightMin = (mediumIndex2 == nLength2) ? INT_MAX : nums2[mediumIndex2];

        //找到正确切分
        if ((nums1LeftMax <= nums2RightMin) && (nums2LeftMax <=nums1RightMin))
		{
			auto leftMax = std::max(nums1LeftMax, nums2LeftMax);
			auto rightMin = std::min(nums1RightMin, nums2RightMin);
			if((nLength1 + nLength2)%2 == 1)
				return leftMax;
			else
				return (static_cast<double>(leftMax + rightMin))/2.0;
		}else if (nums1LeftMax > nums2RightMin)
		{
			right = mediumIndex1 - 1;
		}
		else
		{
			left = mediumIndex1 + 1;
		}	
    }
    return 0.0;
}
