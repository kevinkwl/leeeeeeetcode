class Solution {
public:
    void divide_and_conquer(vector<int>& nums, int i, int N, int &lmax, int &mmax, int &rmax, vector<int> &sum) {
        if (N == 1) {
            lmax = mmax = rmax = nums[i];
            return;
        } else if (N == 2) {
            int tsum = nums[i] + nums[i+1];
            lmax = max(nums[i], tsum);
            mmax = max(nums[i], max(nums[i+1], tsum));
            rmax = max(tsum, nums[i+1]);
            return;
        }
        int n = N / 2;
        int llmax, lmmax, lrmax;
        int rlmax, rmmax, rrmax;
        divide_and_conquer(nums, i, n, llmax, lmmax, lrmax, sum);
        divide_and_conquer(nums, i+n, N-n, rlmax, rmmax, rrmax, sum);
        lmax = max(llmax, sum[i+n]-sum[i] + max(0, rlmax));
        rmax = max(rrmax, sum[i+N]-sum[i+n] + max(0, lrmax));
        mmax = max(lrmax + rlmax, max(lmmax, rmmax));
    }
    
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++)
            sum[i+1] = sum[i] + nums[i];
        int maxsum = INT_MIN;
        int cursum = 0;
        int lmax, mmax, rmax;
        divide_and_conquer(nums, 0, nums.size(), lmax, mmax, rmax, sum);
        return max(lmax, max(mmax, rmax));
    }
};
