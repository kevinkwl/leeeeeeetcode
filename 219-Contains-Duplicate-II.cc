class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        unordered_map<int, int> prev;
        for (int i = 0; i < nums.size(); i++) {
            if (prev.count(nums[i]) > 0) {
                int prev_pos = prev[nums[i]];
                if (i - prev_pos <= k)
                    return true;
                prev[nums[i]] = i;
            } else
                prev[nums[i]] = i;
        }
        return false;
    }
};
