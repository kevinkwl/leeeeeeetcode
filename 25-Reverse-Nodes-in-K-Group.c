// 4ms 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head)  return head;
    struct ListNode* newTail = head->next;
    struct ListNode* newHead = head;
    for (int i = 0; i < k-1; i++) {
        if (!newTail)  return head;
        newTail = newTail->next;
    }
    newTail = reverseKGroup(newTail, k);
    for (int i = 0; i < k; i++) {
        head = newHead;
        newHead = head->next;
        head->next = newTail;
        newTail = head;
    }
    return head;
}
