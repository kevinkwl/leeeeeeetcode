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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            int size = level.size();
            vector<int> thisLvl;
            for(; size > 0; size--) {
                TreeNode* n = level.front();
                level.pop();
                thisLvl.push_back(n->val);
                if (n->left)    level.push(n->left);
                if (n->right)   level.push(n->right);
            }
            res.push_back(thisLvl);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
