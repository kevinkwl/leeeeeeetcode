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
        TreeLinkNode pseudo(0);
        TreeLinkNode* prev, * cur = root;
        bool hasMore = true;
        while(cur) {
            pseudo.next = NULL;
            prev = &pseudo;
            while (cur) {
                if (cur->left) {
                    prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = pseudo.next;
        }
    }
};
