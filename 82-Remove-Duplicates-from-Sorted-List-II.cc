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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)  return NULL;
        ListNode vHead(0);
        ListNode* cur = head, *tail = &vHead;
        int cur_val = cur->val;
        while (cur->next) {
            if (cur->next->val != cur_val) {  // cur is a unique node
                tail->next = cur;
                tail = cur;
                cur = cur->next;
                cur_val = cur->val;
            } else {
                // jump over the repeated nodes
                while (cur && cur->val == cur_val)
                    cur = cur->next;
                if (cur)
                    cur_val = cur->val;
                else
                    break;
            }
        }
        tail->next = cur;   // remaining nodes
        return vHead.next;
    }
};
