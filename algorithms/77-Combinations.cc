class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k);
        genCombs(1, n, 0, comb, res);
        return res;
    }
    
    void genCombs(int i, int n, int k, vector<int> &comb, vector<vector<int>> &res) {
        if (k == comb.size()) {
            res.push_back(comb);
            return;
        }
        for (; i <= n; i++) {
            comb[k] = i;
            genCombs(i + 1, n, k + 1, comb, res);
        }
    }
};
