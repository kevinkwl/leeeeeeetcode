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
    void reorderList(ListNode* head) {
        if (!head || !head->next)  return;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secHalf = slow->next;
        slow->next = NULL;

        // reverse secHalf
        ListNode* cur = secHalf->next, *tail;
        secHalf->next = NULL;
        while (cur) {
            tail = cur->next;
            cur->next = secHalf;
            secHalf = cur;
            cur = tail;
        }
        
        // merge
        cur = head;
        while (cur && secHalf) {
            ListNode* insert = secHalf;
            secHalf = secHalf->next;
            insert->next = cur->next;
            cur->next = insert;
            cur = insert->next;
        }
    }
};
