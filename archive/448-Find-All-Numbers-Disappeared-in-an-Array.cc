class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i >= 0) {
            if (nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]); // move number to its corresponding idx
            } else {
                i--;
            }
        }
        vector<int> ans;
        for (i = 1; i <= nums.size(); i++) {
            if (nums[i-1] != i)
                ans.push_back(i);
        }
        return ans;
    }
};

// another way from leetcode discussion: set nums[num[i]-1] to negative to mark
// that idx number have showed up.
