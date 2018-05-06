/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        current = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != NULL;
    }
    // morris traversal
    /** @return the next smallest number */
    int next() {
        int ret;
        while (current) {
            if (current->left == NULL) {
                break;
            } else {
                TreeNode* pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }
                else if (pre->right == current) {
                    pre->right = NULL;
                    break;
                }
            }
        }
        ret = current->val;
        current = current->right;
        return ret;
    }
private:
    TreeNode *current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
