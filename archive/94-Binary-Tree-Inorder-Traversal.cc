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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traverse;
        if (!root)  return traverse;
        stack<TreeNode*> inorder;
        TreeNode* cur = root;
        while (!inorder.empty() || cur != NULL) {
            while (cur != NULL) {
                inorder.push(cur);
                cur = cur->left;
            }
            TreeNode* node = inorder.top();
            inorder.pop();
            traverse.push_back(node->val);
            cur = node->right;
        }
        return traverse;
    }
};
