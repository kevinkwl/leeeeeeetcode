class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int p = 0, l, h, target;
        while (p <= nums.size() - 3) {
            target = -nums[p];
            l = p + 1, h = nums.size() - 1;
            while (l < h) {
                int sum = nums[l] + nums[h];
                if (sum < target)
                    l++;
                else if (sum > target)
                    h--;
                else {
                    res.push_back(vector<int>{nums[p], nums[l], nums[h]});
                    while (l < h && nums[l] == nums[l+1])
                        l++;
                    while (l < h && nums[h] == nums[h-1])
                        h--;
                    l++, h--;
                }
            }
            p++;
            while (nums[p] == nums[p-1])
                p++;
        }
        return res;
    }
};
