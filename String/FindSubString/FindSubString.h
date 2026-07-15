#pragma once
#include <string>
#include <vector>
using namespace std;

class FindSubString
{
public:
    vector<int> Solve(const string& s, vector<string>& words);
    vector<int> Solve2(const string& s, vector<string>& words);
};
