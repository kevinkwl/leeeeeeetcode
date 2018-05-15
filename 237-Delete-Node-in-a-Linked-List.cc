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
    void deleteNode(ListNode* node) {
        if (!node) return;
        node->val = node->next->val;
        ListNode* n = node->next;
        node->next = n->next;
        delete n;

        /*
        auto n = node->next;
        *node = *node->next;
        delete n;
         */
    }
};
