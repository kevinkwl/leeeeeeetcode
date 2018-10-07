class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        genSubsets(0, nums, sub, subs);
        return subs;
    }
    
    void genSubsets(int i, vector<int> &nums, vector<int>& sub, vector<vector<int>>& subs) {
        if (i == nums.size()) {
            subs.push_back(sub);
            return;
        }
        genSubsets(i + 1, nums, sub, subs);
        sub.push_back(nums[i]);
        genSubsets(i + 1, nums, sub, subs);
        sub.pop_back();
    }
};

// smart way: the number of power set is 2^n, each number from 0...2^n-1
// represents a subset
