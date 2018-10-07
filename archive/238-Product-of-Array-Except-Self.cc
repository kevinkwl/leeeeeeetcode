class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int cur = 1, rcur = 1, N = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= cur;
            cur *= nums[i];  
            output[N-1-i] *= rcur;
            rcur *= nums[N-1-i];
        }
        return output;
    }
};
