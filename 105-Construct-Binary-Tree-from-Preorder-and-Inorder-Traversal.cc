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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, int pi, vector<int>& inorder, int ii, int cnt) {
        if (pi == preorder.size() || ii == inorder.size() || cnt == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pi]);
        int j, left_cnt;
        for (j = ii; j < inorder.size() && j < ii + cnt; j++)
            if (inorder[j] == preorder[pi])
                break;
        left_cnt = j - ii;
        root->left = buildTree(preorder, pi+1, inorder, ii, left_cnt);
        root->right = buildTree(preorder, pi+1+left_cnt, inorder, ii+left_cnt+1, cnt-1-left_cnt);
        return root;
    }
};
