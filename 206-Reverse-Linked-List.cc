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
    ListNode* reverseList(ListNode* head) {
        if (!head)  return head;
        ListNode* prev = head->next;
        if (!prev)
            return head;
        ListNode* rhead = reverseList(head->next);
        prev->next = head;
        head->next = NULL;
        return rhead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode psd(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* nextCur = cur->next;
            cur->next = psd.next;
            psd.next = cur;
            cur = nextCur;
        }
        return psd.next;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
