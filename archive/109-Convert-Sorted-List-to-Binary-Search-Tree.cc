// slow fast pointer !!!
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
    
    TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
        if (start == end)
            return NULL;
        ListNode* slow = start, * fast = start->next;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(start, slow);
        root->right = sortedListToBST(slow->next, end);
        return root;
    }
};


// convert to array
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        return sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBST(vector<int> &nums, int i, int n) {
        if (n == 0)
            return NULL;
        int m = i + n / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = sortedArrayToBST(nums, i, m - i);
        root->right = sortedArrayToBST(nums, m + 1, n - 1 - (m - i));
        return root;
    }
};
