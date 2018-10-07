class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int len = 0, maxlen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (lis.empty() || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
                len = lis.size();
            }
            else {
                len = binSearch(lis, nums[i]);
            }
            maxlen = max(maxlen, len);
        }
        
        return maxlen;
    }
    int binSearch(vector<int>& lis, int target) {
        int lo = 0, hi = lis.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (lis[mid] < target)
                lo = mid + 1;
            else if (lis[mid] >= target)
                hi = mid - 1;
        }
        lis[lo] = target;
        return lo + 1;
    }
};
