class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> sols;
        vector<int> sol;
        genPermutations(sols, sol, used, nums);
        return sols;
    }
    void genPermutations(vector<vector<int>>& sols, vector<int>& sol, vector<bool>& used, vector<int>& nums) {
        if (sol.size() == nums.size()) {
            sols.push_back(sol);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i])
                    continue;
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                    continue;
                used[i] = true;
                sol.push_back(nums[i]);
                genPermutations(sols, sol, used, nums);
                sol.pop_back();
                used[i] = false;
            }
        }
    }

};
