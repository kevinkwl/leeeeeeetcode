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
    TreeNode* wrong1, *wrong2;
    void recoverTree(TreeNode* root) {
        inorder(root, NULL);
        int tmp = wrong1->val;
        wrong1->val = wrong2->val;
        wrong2->val = tmp;
    }

    TreeNode* inorder(TreeNode* node, TreeNode* prev) {
        if (node == NULL)   return prev;
        TreeNode* curPrev = inorder(node->left, prev);
        if (curPrev != NULL) {
            if (node->val < curPrev->val) {
                if (wrong1 == NULL) {
                    wrong1 = curPrev;
                    wrong2 = node;
                } else {
                    wrong2 = node;
                }
            }
        }
        return inorder(node->right, node);
    }
};
