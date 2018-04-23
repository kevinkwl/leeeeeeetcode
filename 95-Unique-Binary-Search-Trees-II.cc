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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int i, int cnt) {
        vector<TreeNode*> roots;
        if (cnt == 0) {
            roots.push_back(NULL);
            return roots;
        }
        
        for (int j = 0; j < cnt; j++) {
            int rootVal = i + j;
            vector<TreeNode*> leftTrees = generateTrees(i, j);
            vector<TreeNode*> rightTrees = generateTrees(rootVal+1, cnt - j - 1);
            for (TreeNode* lt : leftTrees)
                for (TreeNode* rt : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = lt;
                    root->right = rt;
                    roots.push_back(root);
                }
        }
        return roots;
    }
};
