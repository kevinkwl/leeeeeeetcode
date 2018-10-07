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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool fp = false, fq = false;
        return findLCA(root, p, q, fp, fq);
    }
    
    // return the Node if it is LCA, otherwise return NULL
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q, bool &fp, bool &fq) {
        if (!root || !p || !q) return NULL;
        if (p == q) return p;
        
        bool lfp = false, lfq = false;
        TreeNode* LCA = findLCA(root->left, p, q, lfp, lfq);
        if (LCA != NULL)
            return LCA;
        bool rfp = false, rfq = false;
        LCA = findLCA(root->right, p, q, rfp, rfq);
        if (LCA != NULL)
            return LCA;
        
        if (root == p)
            fp = true;
        if (root == q)
            fq = true;
        fp = fp || lfp || rfp;
        fq = fq || lfq || rfq;
        
        if (fp && fq)
            return root;
        return NULL;
    }
};


// simpler !
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // one was found in left subtree
        if (left != NULL) {
            // one was found in right subtree
            if (right != NULL)
                return root;
            // another one must be descendent of left
            else
                return left;
        } else {
            return right;
        }
    }
};
