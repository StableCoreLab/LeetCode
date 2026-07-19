#include "MergeKLists.h"
#include <vector>
#include <queue>

ListNode* MergeKLists::Solve(std::vector<ListNode*>& lists)
{
    ListNode* result{};
    if (lists.empty())
        return result;

    result = lists[0];
    for (size_t i = 1; i < lists.size(); ++i)
    {
        result = MergeTwo(result, lists[i]);
    }

    return result;
}

ListNode* MergeKLists::MergeTwo(ListNode* listA, ListNode* listB)
{
    if (!listA)
        return listB;
    if (!listB)
        return listA;

    ListNode dummy(0);
    ListNode* pNextA = listA;
    ListNode* pNextB = listB;
    ListNode* pNext = &dummy;

    while (pNextA && pNextB)
    {
        if (pNextA->val > pNextB->val)
        {
            pNext->next = pNextB;
            pNextB = pNextB->next;
        } else
        {
            pNext->next = pNextA;
            pNextA = pNextA->next;
        }
        pNext = pNext->next;
    }
    pNext->next = pNextA ? pNextA : pNextB;

    return dummy.next;
}

ListNode* MergeKLists::MergeRange(std::vector<ListNode*>& lists, int left, int right)
{
    if (left == right)
        return lists[left];
    int mid = left + (right - left) / 2;
    auto* leftList = MergeRange(lists, left, mid);
    auto* rightList = MergeRange(lists, mid + 1, right);
    return MergeTwo(leftList, rightList);
}

ListNode* MergeKLists::Solve2(std::vector<ListNode*>& lists)
{
    if (lists.empty())
        return nullptr;
    return MergeRange(lists, 0, static_cast<int>(lists.size()) - 1);
}

ListNode* MergeKLists::Solve3(std::vector<ListNode*>& lists)
{
    if (lists.empty())
        return nullptr;
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> mainQueue(cmp);
    for (auto* list : lists)
    {
        if (list)
            mainQueue.push(list);
    }
    ListNode head(0);
    ListNode* pCurrent = &head;
    while (!mainQueue.empty())
    {
        ListNode* pNode = mainQueue.top();
        mainQueue.pop();

        pCurrent->next = pNode;
        pCurrent = pCurrent->next;
        if (pNode->next)
            mainQueue.push(pNode->next);
    }
    return head.next;
}
