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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, bool> exists;
        for (int i : G)
            exists[i] = true;
        int cnt = 0;
        bool conn = false;
        while (head) {
            if (exists.count(head->val)) {
                if (!conn) {
                    conn = true;
                    cnt++;
                }
            } else {
                conn = false;
            }
            head = head->next;
        }
        return cnt;
    }

};
