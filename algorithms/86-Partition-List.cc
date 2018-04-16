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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0), * larger = new ListNode(0);
        ListNode* scur = smaller, * lcur = larger;
        while (head) {
            if (head->val < x) {
                scur->next = head;
                scur = head;
            } else {
                lcur->next = head;
                lcur = head;
            }
            head = head->next;
        }
        scur->next = larger->next;
        lcur->next = NULL;
        return smaller->next;
    }
};
