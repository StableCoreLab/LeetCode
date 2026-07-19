#include <gtest/gtest.h>
#include "LinkedList/MergeKLists/MergeKLists.h"

TEST(MergeKListsTest, Solve)
{
    // Create test cases for the MergeKLists::Solve function
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));
    
    std::vector<ListNode*> lists = {list1, list2, list3};
    
    MergeKLists merger;
    ListNode* mergedList = merger.Solve(lists);
    
    // Verify the merged list is sorted
    std::vector<int> expectedValues = {1, 1, 2, 3, 4, 4, 5, 6};
    for (int val : expectedValues) {
        ASSERT_NE(mergedList, nullptr);
        EXPECT_EQ(mergedList->val, val);
        mergedList = mergedList->next;
    }
    
    // Clean up memory
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }
}