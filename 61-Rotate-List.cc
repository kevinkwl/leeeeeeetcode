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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)  return head;
        ListNode *aheadK = head;
        int i = 0;
        // fast pointer
        while (i < k) {
            aheadK = aheadK->next;
            if (!aheadK) {
                k %= (i+1);
                i = 0;
                aheadK = head;
                continue;
            }
            i++;
        }
        ListNode *behindK = head;
        while (aheadK->next) {
            behindK = behindK->next;
            aheadK = aheadK->next;
        }
        aheadK->next = head;
        head = behindK->next;
        behindK->next = NULL;
        return head;
    }
};
