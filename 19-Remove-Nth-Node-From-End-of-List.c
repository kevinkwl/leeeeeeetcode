// 4ms 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head)  return NULL;
    struct ListNode* prevNth = head, *NthNext = head;
    while (n-- && NthNext)
        NthNext = NthNext->next;
    if (NthNext == NULL) {  // need to delete head
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    while (NthNext->next != NULL)   {
        prevNth = prevNth->next;
        NthNext = NthNext->next;
    }
    struct ListNode* toDelete = prevNth->next;
    prevNth->next = toDelete->next;
    free(toDelete);
    return head;
}
