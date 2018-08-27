/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return "[" + serializeHelper(root) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() <= 2)
            return NULL;
        return deserializeHelper(data.substr(1, data.size()-2));
    }
private:
    string serializeHelper(TreeNode* root) {
        if (root == NULL)
            return "";
        string serial = to_string(root->val);
        int last_not_null = serial.length();
        queue<TreeNode*> nqueue;
        nqueue.push(root);
        while (!nqueue.empty()) {
            TreeNode* cur = nqueue.front();
            nqueue.pop();
            serial += ',' + (cur->left == NULL ? "null" : to_string(cur->left->val));
            serial += ',' + (cur->right == NULL ? "null" : to_string(cur->right->val));
            if (cur->left != NULL) {
                nqueue.push(cur->left);
                last_not_null = serial.length();
            }
            if (cur->right != NULL) {
                nqueue.push(cur->right);
                last_not_null = serial.length();
            }
        }
        serial = serial.substr(0, last_not_null);
        //cout << serial << endl;
        return serial;
    }
    
    TreeNode* deserializeHelper(string data) {
        int pos = data.find_first_of(',', 1);
        pos = (pos < 0 ? data.length() : pos);
        TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
        queue<TreeNode*> nqueue;
        nqueue.push(root);
        pos++;
        int pos1, pos2;
        string s1, s2;
        while (!nqueue.empty() && pos < data.length()) {
            TreeNode* cur = nqueue.front();
            nqueue.pop();
            //cout << nqueue.size() << "@" << endl;
            pos1 = data.find_first_of(',', pos+1);
            pos2 = data.find_first_of(',', pos1+1);
            pos2 = (pos2 < 0 ? data.length() : pos2);
            s1 = data.substr(pos, pos1-pos);
            s2 = data.substr(pos1+1, pos2-pos1-1);
            //cout << s1 <<' ' << s2 << endl;
            if (s1 != "null") {
                TreeNode* left = new TreeNode(stoi(s1));
                cur->left = left;
                nqueue.push(left);
            }
            if (s2 != "null") {
                TreeNode* right = new TreeNode(stoi(s2));
                cur->right = right;
                nqueue.push(right);
            }
            pos = pos2 + 1;
            //cout << nqueue.size() << '#' << pos1 << ' ' << pos2 << endl;
        }
        return root;
    }
};
