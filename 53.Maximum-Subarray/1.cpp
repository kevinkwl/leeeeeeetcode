class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cursum = 0;
        for (int n : nums) {
            cursum = n + max(cursum, 0);
            maxsum = max(cursum, maxsum);
        }
        return maxsum;
    }
};
