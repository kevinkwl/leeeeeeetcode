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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {        // similar to morris traversal
                TreeNode* pre = cur->left;
                while (pre->right)          // find the rightmost child of cur->left
                    pre = pre->right;
                pre->right = cur->right;    // attach cur->right to it
                cur->right = cur->left;     // flatten
                cur->left = NULL;           // set NULL
            }
            cur = cur->right;
        }
    }
};
