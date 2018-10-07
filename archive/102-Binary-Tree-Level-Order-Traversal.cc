// recursive
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelTraverse(root, 0, res);
        return res;
    }
    
    void levelTraverse(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node)  return;
        if (res.size() <= level)    res.push_back(vector<int>{});
        res[level].push_back(node->val);
        levelTraverse(node->left, level+1, res);
        levelTraverse(node->right, level+1, res);
    }
};

// iterative
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            int size = level.size();
            vector<int> thisLevel;
            for (int i = 0; i < size; i++) {
                TreeNode* node = level.front();
                level.pop();
                thisLevel.push_back(node->val);
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }
            res.push_back(thisLevel);
        }
        return res;
    }
};
