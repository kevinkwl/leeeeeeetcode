/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        root->next = NULL;
        TreeLinkNode *head = root, *cur;
        while (head) {
            cur = head;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            head = head->left;
        }
    }
};
