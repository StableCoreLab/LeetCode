#include <gtest/gtest.h>
#include "LinkedList/ReverseKGroup/ReverseKGroup.h"

TEST(ReverseKGroupTest, Test1)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ReverseKGroup solver;
    int K = 2;
    ListNode* result = solver.Solve(head, K);

    // Verify the result
    std::vector<int> expectedValues = {2, 1, 4, 3, 5};
    for (int val : expectedValues)
    {
        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->val, val);
        result = result->next;
    }
    EXPECT_EQ(result, nullptr); // Ensure the list ends correctly
}