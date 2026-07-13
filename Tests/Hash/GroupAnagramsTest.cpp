#include <gtest/gtest.h>
#include "Hash/GroupAnagrams/GroupAnagrams.h"

TEST(GroupAnagramsTest, Test1)
{
    GroupAnagrams groupAnagrams;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams.Solve(strs);
    // Add assertions here
}
