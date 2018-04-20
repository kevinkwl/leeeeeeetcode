class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, b = nums.size() - 1, i = r; // r: the next place to put 0, b: the next place to put 2
        while (i <= b) {
            if (nums[i] < 1)
                swap(nums[i++], nums[r++]);
            else if (nums[i] > 1)
                swap(nums[i], nums[b--]);
            else
                i++;
        }
    }
};
