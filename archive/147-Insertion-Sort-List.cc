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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ph = new ListNode(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            ListNode* prev = ph;
            while (prev->next && prev->next->val < cur->val)
                prev = prev->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        return ph->next;
    }
};
