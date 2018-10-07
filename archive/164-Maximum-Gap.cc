class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)    return 0;   
        int minVal = INT_MAX, maxVal = INT_MIN, gap;
        for (int n : nums) {
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        if (minVal == maxVal)   return 0;
        gap = (maxVal - minVal) / (nums.size() - 1) + 1;
        // at least one bucket will be empty
        vector<pair<int, int>> buckets(nums.size()-1, make_pair(INT_MAX, INT_MIN));
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal || nums[i] == minVal)
                continue;
            int bi = (nums[i] - minVal) / gap;
            buckets[bi].first = min(nums[i], buckets[bi].first);
            buckets[bi].second = max(nums[i], buckets[bi].second);
        }
        int prev = minVal, maxGap = 0;
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i].first > buckets[i].second)
                continue;
            maxGap = max(maxGap, buckets[i].first - prev);
            maxGap = max(maxGap, buckets[i].second - buckets[i].first);
            prev = buckets[i].second;
        }
        return max(maxGap, maxVal - prev);
    }
};
