#include<gtest/gtest.h>
#include "String/FindSubString/FindSubString.h"

TEST(FindSubStringTest, BasicTests)
{
    FindSubString findSubString;	
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> expected = {0,9};
    EXPECT_EQ(findSubString.Solve2(s, words), expected);
	
    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","word"};
    expected = {};
    EXPECT_EQ(findSubString.Solve2(s, words), expected);

    s = "barfoofoobarthefoobarman";
    words = {"bar","foo","the"};
    expected = {6,9,12};
    EXPECT_EQ(findSubString.Solve2(s, words), expected);
}