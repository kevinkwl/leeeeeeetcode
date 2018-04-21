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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)  return head;
        ListNode* pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        ListNode* revBegin = pseudoHead;
        int revSize = n - m;
        for (int i = 0; i < m - 1; i++)
            revBegin = revBegin->next;
        
        ListNode* revEnd = revBegin->next;
        for (int i = 0; i < revSize; i++) {
            ListNode* revNode = revEnd->next;
            revEnd->next = revNode->next;
            revNode->next = revBegin->next;
            revBegin->next = revNode;
        }
        return pseudoHead->next;
    }
};
