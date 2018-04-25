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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // morris traversal
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right != NULL && pre->right != cur)
                    pre = pre->right;
                
                if (pre->right == NULL) {
                    res.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else if (pre->right == cur) {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
