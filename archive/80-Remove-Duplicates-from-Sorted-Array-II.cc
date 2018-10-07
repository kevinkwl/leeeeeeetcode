class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] > nums[len-2])
                swap(nums[i], nums[len++]);
        }
        return len;
    }
};
