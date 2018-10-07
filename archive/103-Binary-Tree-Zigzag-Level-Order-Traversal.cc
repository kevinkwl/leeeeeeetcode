// recursive
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelTraverse(root, 0, res);
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            int size = level.size();
            vector<int> thisLevel(size);
            bool zag = res.size() & 1;
            for (int i = 0; i < size; i++) {
                TreeNode* node = level.front();
                level.pop();
                int idx = zag ? size - 1 - i : i;
                thisLevel[idx] = node->val;
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }
            res.push_back(thisLevel);
        }
        return res;
    }
};
