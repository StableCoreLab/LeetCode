#include "ReverseKGroup.h"

ListNode* ReverseKGroup::Solve(ListNode* pHead, int K)
{
    if (!pHead || K <= 1)
    {
        return pHead;
    }
	ListNode dummy(0);
    dummy.next = pHead;	
	ListNode* pPreGroupEnd = &dummy;

	while(true)
	{
		//找到当前处理分组的末尾节点即k个节点
		ListNode* pCurrentGroupEnd = pPreGroupEnd;
        for (int i = 0; i < K; ++i)
        {
            pCurrentGroupEnd = pCurrentGroupEnd->next;
            if (!pCurrentGroupEnd)
            {
                return dummy.next;
            }
        }
        // 当前头在翻转后会变成尾节点，尾节点的next指向下一组的头节点
        ListNode* pGroupTail = pPreGroupEnd->next;
        // 记录下一组开始位置用于后续链接
        ListNode* pNextGroupHead = pCurrentGroupEnd->next;

		//因要翻转，先断开旧链接
        pCurrentGroupEnd->next = nullptr;		
		//调整当前分组
        pPreGroupEnd->next = ReverseList(pGroupTail);

        // 链接下一组
        pGroupTail->next = pNextGroupHead;
        pPreGroupEnd = pGroupTail;		
	}
}

ListNode* ReverseKGroup::ReverseList(ListNode* list)
{
	ListNode* pPre = nullptr;
	ListNode* pNext = nullptr;
	ListNode* pCurrent = list;
	
	while(pCurrent)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}
	return pPre;
}
