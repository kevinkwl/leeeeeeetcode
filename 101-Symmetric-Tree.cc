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
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) return true;
        if (l == NULL || r == NULL) return false;
        return l->val == r->val && isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};
