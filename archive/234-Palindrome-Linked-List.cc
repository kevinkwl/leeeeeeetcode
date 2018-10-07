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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        bool isPal = true;
        ListNode* midHead = slow;
        ListNode* palStart = head;
        ListNode* revHead = reverse(midHead);
        ListNode* revStart = revHead;
        // compare first half and reversed second half
        while (palStart != midHead) {
            if (!revStart || revStart->val != palStart->val) {
                isPal = false;
                break;
            }
            palStart = palStart->next;
            revStart = revStart->next;
        }
        reverse(revHead);
        return isPal;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode ph(0);
        ListNode* cur = head, * tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = ph.next;
            ph.next = cur;
            cur = tmp;
        }
        return ph.next;
    }
};
