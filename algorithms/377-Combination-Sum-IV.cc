class Solution {
public:
    unordered_map<int, int> combs;
    int combinationSum4(vector<int>& nums, int target) {
        if (target < 0) return 0;
        if (target == 0) return 1;
        if (combs.count(target))
            return combs[target];
        int ways = 0;
        for (int n : nums)
            ways += combinationSum4(nums, target - n);
        return (combs[target] = ways);
    }
};
