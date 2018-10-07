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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumPaths(root, sum, 0);
        return sum;
    }
    
    void sumPaths(TreeNode* root, int& sum, int cur) {
        if (!root)  return;
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            sum += cur;
        } else {
            sumPaths(root->left, sum, cur);
            sumPaths(root->right, sum, cur);
        }
    }
};
