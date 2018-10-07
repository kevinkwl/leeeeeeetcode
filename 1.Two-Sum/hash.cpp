class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> has;
        for (int i = 0; i < nums.size(); i++) {
            if (has.find(target - nums[i]) != has.end())
                return {has[target-nums[i]], i};
            has[nums[i]] = i;
        }
        return {};
    }
};
