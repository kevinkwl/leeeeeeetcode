class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())   return 0;
        int maxp, minp, res;
        maxp = minp = res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxp, minp);
            
            maxp = max(nums[i], nums[i] * maxp);
            minp = min(nums[i], nums[i] * minp);
            
            res = max(res, maxp);
        }
        return res;
    }
};
