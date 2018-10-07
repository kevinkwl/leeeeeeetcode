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
    int countNodes(TreeNode* root) {
        if (!root)  return 0;
        int count = 0;
        countNodes(root, count);
        return count;
    }
    
    void countNodes(TreeNode* node, int& count) {
        if (!node) return;
        count++;
        int hl = height(node->left), hr = height(node->right);
        if (hl == hr) {
            count += ((1 << hl) - 1);
            countNodes(node->right, count);
        } else {
            count += ((1 << hr) - 1);
            countNodes(node->left, count);
        }
    }
    // calculate height of the complete binary tree rooted at root. 
    int height(TreeNode* root) {
        TreeNode* cur = root;
        int d = 0;
        while (cur) {
            d++;
            cur = cur->left;
        }
        return d;
    }
};

// if the height of left subtree (hl) == (hr) of right subtree, then the left subtree must be a perfect binary tree
// , and the right subtree is itself a smaller complete binary tree
// if hl > hr, then right subtree is a perfect binary tree of height (hr), and left subtree is a smaller complete binary tree.
