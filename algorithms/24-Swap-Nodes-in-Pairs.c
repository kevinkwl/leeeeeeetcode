// 0ms 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)   return head;
    struct ListNode* swapped = swapPairs(head->next->next);
    struct ListNode* newHead = head->next;
    newHead->next = head;
    head->next = swapped;
    return newHead;
}
