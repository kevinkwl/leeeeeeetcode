class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        if (nums.size() == 1)   return nums[0];
        int N = nums.size();
        // either skip N-1 and try rob [0, N-2] ,or skip 0 and try rob [1, N-1] 
        return max(rob(nums, 0, N-2), rob(nums, 1, N-1));
    }
    
    int rob(vector<int>& nums, int b, int e) {
        int robMax = 0, skipMax = 0;
        for (int i = b; i <= e; i++) {
            int tmp = robMax;
            robMax = skipMax + nums[i];
            skipMax = max(tmp, skipMax);
        }
        return max(robMax, skipMax);
    }
};
