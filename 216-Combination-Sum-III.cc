class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> curVec;
        dfs(k, 0, curVec, n, results);
        return results;
    }
    void dfs(int k, int i, vector<int>& curVec, int cur, vector<vector<int>> &results) {
        if (i == k) {
            if (cur == 0)
                results.push_back(curVec);
            return;
        }
        if (cur == 0) // early mature
            return;
        // pruning
        if ((cur - (k - i) < 0 || (cur - 9 * (k - i) > 0)))
            return;
        int last = (curVec.size() ? curVec.back() : 0);
        for (int d = last + 1; d <= 9 ; d++) {
            if (d > cur)
                return;
            curVec.push_back(d);
            dfs(k, i + 1, curVec, cur - d, results);
            curVec.pop_back();
        }
    }
};
