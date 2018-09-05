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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) 
            return head;
        ListNode* eHead = head, * oHead = head->next;
        ListNode* eTail = head, * oTail = head->next;
        ListNode* cur = oHead->next;
        bool isEven = true;
        while (cur) {
            ListNode* &curTail = isEven ? eTail : oTail;
            curTail->next = cur;
            curTail = curTail->next;
            isEven = !isEven;
            cur = cur->next;
        }
        eTail->next = oHead;
        oTail->next = NULL;
        return eHead;
    }
};
