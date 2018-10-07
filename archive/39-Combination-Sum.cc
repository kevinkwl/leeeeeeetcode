class Solution {
public:
    void dfs(vector<int>& candidates, int i, vector<int>& curVec, int cur, vector<vector<int>> &results) {
        if (cur == 0) {
            results.push_back(curVec);
            return;
        }
        if (i == candidates.size())
            return;
        for (int k = i; k < candidates.size(); k++) {
            if (candidates[k] > cur)
                return;
            curVec.push_back(candidates[k]);
            dfs(candidates, k, curVec, cur - candidates[k], results);
            curVec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> curVec;
        int cur = target;
        dfs(candidates, 0, curVec, cur, results);
        return results;
    }
};
