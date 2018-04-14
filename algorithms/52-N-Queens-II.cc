class Solution {
public:
    int totalNQueens(int n) {
        int sols = 0;
        vector<bool> used_col(n, false);
        vector<bool> used_ldg(2*n-1, false);
        vector<bool> used_rdg(2*n-1, false);
        solve(0, n, sols, used_col, used_ldg, used_rdg);
        return sols;
    }
    void solve(int i, int n, int& sols, vector<bool>& used_col,
              vector<bool>& used_ldg, vector<bool>& used_rdg) {
        if (i == n) {
            sols++;
            return;
        }
        for (int j = 0; j< n; j++) {
            if (used_col[j] || used_ldg[i+j] || used_rdg[n-1+i-j])
                continue;
            used_col[j] = used_ldg[i+j] = used_rdg[n-1+i-j] = true;            
            solve(i+1, n, sols, used_col, used_ldg, used_rdg);
            used_col[j] = used_ldg[i+j] = used_rdg[n-1+i-j] = false;
        }
    }
};
