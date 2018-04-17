// iterative
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int prev_size, start;
        for (int i = 0; i < nums.size(); i++) {
            // if duplicate, only append number to sets that already contain the previous same number
            start = (i > 0 && nums[i] == nums[i-1]) ? prev_size : 0;
            prev_size = res.size();
            for (int j = start; j < prev_size; j++) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        return res;
    }
};


// recursive
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> used(nums.size(), false);
        genSubsets(0, nums, used, subset, res);
        return res;
    }
    
    void genSubsets(int i, vector<int>& nums, vector<bool>& used, vector<int>& subset, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        } else {
            genSubsets(i+1, nums, used, subset, res);
            if (i == 0 || nums[i] != nums[i-1] || used[i-1]) {
                used[i] = true;
                subset.push_back(nums[i]);
                genSubsets(i+1, nums, used, subset, res);
                subset.pop_back();
                used[i] = false;
            }
        }
    }
};
