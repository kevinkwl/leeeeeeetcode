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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)   return NULL;
        // create a cycle
        ListNode *nb = headB;
        while (nb->next)
            nb = nb->next;
        nb->next = headB;
        
        ListNode *slow = headA, *fast = headA;
        ListNode *joint = NULL;
        bool intersect = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                intersect = true;
                break;
            }
        }
        if (intersect) {
            fast = headA;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            joint = slow;
        }
        nb->next = NULL;
        return joint;
    }
};

// brilliant idea by others
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)   return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = (a == NULL ? headB : a->next);
            b = (b == NULL ? headA : b->next);
        }
        return a;
    }
};
