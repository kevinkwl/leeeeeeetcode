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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e) {
        if (s == e)
            return NULL;
        int r = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[r]);
        root->left = sortedArrayToBST(nums, s, r);
        root->right = sortedArrayToBST(nums, r+1, e);
        return root;
    }
};
