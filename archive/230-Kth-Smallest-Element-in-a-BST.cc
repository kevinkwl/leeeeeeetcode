/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root) {
            stk.push(root);
            root = root->left;
        }
        TreeNode* kth;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            k--;
            if (k == 0)
                kth = cur;
            cur = cur->right;
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
        }
        return kth->val;
    }
};
