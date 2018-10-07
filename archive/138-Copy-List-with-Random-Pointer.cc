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
        if (!head)  return NULL;
        
        // copy each node and insert new node immediately after original node
        RandomListNode* cur = head;
        while (cur) {
            RandomListNode* dup = new RandomListNode(cur->label);
            dup->next = cur->next;
            cur->next = dup;
            cur = dup->next;
        }
        // copy random pointer
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        RandomListNode* dupHead = head->next;
        RandomListNode* dupCur = dupHead;
        // split into two list
        while (dupCur->next) {
            cur->next = dupCur->next;
            cur = cur->next;
            dupCur->next = dupCur->next->next;
            dupCur = dupCur->next;
        }
        cur->next = NULL;
        return dupHead;
    }
};
