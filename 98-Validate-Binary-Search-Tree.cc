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
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        return isValidBST(root->left, 0, root->val, false, true) 
            && isValidBST(root->right, root->val, 0, true, false);
    }
    
    bool isValidBST(TreeNode* node, int min_val, int max_val, bool checkmin, bool checkmax) {
        if (!node) return true;
        if (checkmin && node->val <= min_val) return false;
        if (checkmax && node->val >= max_val) return false;
        return isValidBST(node->left, min_val, node->val, checkmin, true)
            && isValidBST(node->right, node->val, max_val, true, checkmax);
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
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        int prev;
        bool init = false;
        stack<TreeNode*> inorder;
        TreeNode* cur = root;
        while (!inorder.empty() || cur != NULL) {
            while (cur != NULL) {
                inorder.push(cur);
                cur = cur->left;
            }
            TreeNode* node = inorder.top();
            inorder.pop();
            if (!init)
                init = true;
            else if (node->val <= prev)
                return false;
            prev = node->val;
            cur = node->right;
        }
        return true;
    }

};
