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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> firstStk, secStk;
        if(root)    firstStk.push(root);
        while (!firstStk.empty()) {
            TreeNode* n = firstStk.top();
            firstStk.pop();
            if (n->left)
                firstStk.push(n->left);
            if (n->right)
                firstStk.push(n->right);
            secStk.push(n);
        }
        while (!secStk.empty()) {
            res.push_back(secStk.top()->val);
            secStk.pop();
        }
        return res;
    }
};
