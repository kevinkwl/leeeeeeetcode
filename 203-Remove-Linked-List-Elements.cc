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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *current = head;
        ListNode *previous = nullptr;
        while (current != nullptr)
        {
            if (current->val != val)
            {
                previous = current;
                current = current->next;
                continue;
            }
            if (current == head)
            {
                head = current->next;
                delete current;
                current = head;
            }
            else
            {
                ListNode *n = current->next;
                previous->next = n;
                delete current;
                current = n;
            }
        }
        return head;
    }
};
