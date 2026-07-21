#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int value): val(value), next(nullptr){}
	ListNode(int value, ListNode* pNext): val(value), next(pNext){}
};

class ReverseKGroup
{
public:
	ListNode* Solve(ListNode* head, int K);
private:
	ListNode* ReverseList(ListNode* list);
};
	