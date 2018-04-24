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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, sum, path, paths);
        return paths;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths) {
        if (!root)  return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val)
                paths.push_back(path);
        } else {
            int remain = sum - root->val;
            dfs(root->left, remain, path, paths);
            dfs(root->right, remain, path, paths);
        }
        path.pop_back();
    }
};
