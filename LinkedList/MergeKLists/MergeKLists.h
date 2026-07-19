#pragma once
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* pNext) : val(x), next(pNext)
    {
    }
};

class MergeKLists
{
public:
    ListNode* Solve(std::vector<ListNode*>& lists);

    ListNode* Solve2(std::vector<ListNode*>& lists);
    ListNode* Solve3(std::vector<ListNode*>& lists);

private:
    ListNode* MergeTwo(ListNode* listA, ListNode* listB);
    ListNode* MergeRange(std::vector<ListNode*>& lists, int left, int right);
};
