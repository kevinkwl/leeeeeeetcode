/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode h(0);
        RandomListNode *ph = &h, *cur = head;
        
        // copy nodes and insert immediately after the original node
        while (cur) {
            RandomListNode *copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
            cur = cur->next->next;
        }
        // copy random ptr
        cur = head;
        while (cur) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        // split duplicate list from original list
        cur = head;
        while (cur) {
            ph->next = cur->next;
            cur->next = cur->next->next;
            ph = ph->next;
            cur = cur->next;
        }
        return h.next;
    }
};
