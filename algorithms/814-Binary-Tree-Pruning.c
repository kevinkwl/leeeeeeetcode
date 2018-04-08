/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* pruneTree(struct TreeNode* root) {
        if (root == NULL)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
}
