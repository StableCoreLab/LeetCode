#include "FindSubString.h"
#include <unordered_set>
#include <unordered_map>

vector<int> FindSubString::Solve(const string& s, vector<string>& words)
{
    vector<int> res{};
    unordered_set wordsSet(words.begin(), words.end());
    if (words.empty())
        return res;
    int wordLength = words[0].size();
    for (int i = 0; i + wordLength * words.size() < s.size(); i++)
    {
        bool bFind = false;
        for (auto j = 0; j < words.size(); j++)
        {
            string sTmp = s.substr(i + j * wordLength, wordLength);
            bFind = wordsSet.count(sTmp);
            if (!bFind)
                break;
        }
        if (bFind)
            res.push_back(i);
    }
    return res;
}

vector<int> FindSubString::Solve2(const string& s, vector<string>& words)
{
    vector<int> res{};
    unordered_set wordsSet(words.begin(), words.end());
    if (words.empty())
        return res;
    int wordLength = words[0].size();
    int wordCount = words.size();

    int totalLength = wordCount * wordLength;

    if (totalLength > s.size())
        return res;

    unordered_map<string, int> need;

    for (auto& word : words)
    {
        need[word]++;
    }

    for (int offset = 0; offset < wordLength; ++offset)
    {
        int left = offset;
        int right = offset;

        int count = 0;

        unordered_map<string, int> window;

        while (right + wordLength <= s.size())
        {
            string word = s.substr(right, wordLength);
            right += wordLength;

            if (need.count(word))
            {
                window[word]++;
                count++;
                while (window[word] > need[word])
                {
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }

                if (count == wordCount)
                {
                    res.push_back(left);
                    //这里允许后面单词重复使用
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }
            } else
            {
                window.clear();
                count = 0;
                left = right;
            }
        }
    }
    return res;
}
