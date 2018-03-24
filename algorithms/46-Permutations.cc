class Solution {
public:
    void genPermutations(vector<vector<int>>& sols, vector<int>& nums, int d) {
        if (d == nums.size() - 1) {
            sols.push_back(nums);
        } else {
            for (int i = d; i < nums.size(); i++) {
                swap(nums[d], nums[i]);
                genPermutations(sols, nums, d+1);
                swap(nums[d], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sols;
        genPermutations(sols, nums, 0);
        return sols;
    }
};
