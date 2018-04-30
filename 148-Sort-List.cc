/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)  return head;
        ListNode* slow = head, * fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = sortList(slow->next);
        slow->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode ph(0);
        ListNode* cur = &ph;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        
        if (h1)
            cur->next = h1;
        if (h2)
            cur->next = h2;

        return ph.next;
    }
};
