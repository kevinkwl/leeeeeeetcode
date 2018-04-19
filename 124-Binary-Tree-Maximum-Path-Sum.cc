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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxSum = root->val;
        findMaxPathSum(root, maxSum);
        return maxSum;
    }
    
    int findMaxPathSum(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        int leftMax = max(0, findMaxPathSum(node->left, maxSum));
        int rightMax = max(0, findMaxPathSum(node->right, maxSum));
        maxSum = max(maxSum, leftMax + rightMax + node->val);
        return node->val + max(leftMax, rightMax);
    }
};
