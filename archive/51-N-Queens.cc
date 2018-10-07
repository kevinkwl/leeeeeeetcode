class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        if (n == 0)
            return sols;
        vector<string> sol(n, string(n, '.'));
        vector<bool> used_col(n, false);
        vector<bool> used_ldg(2*n-1, false);
        vector<bool> used_rdg(2*n-1, false);
        solve(0, n, sol, sols, used_col, used_ldg, used_rdg);
        return sols;
    }
    
    void solve(int i, int n, vector<string>& sol, vector<vector<string>>& sols, vector<bool>& used_col,
              vector<bool>& used_ldg, vector<bool>& used_rdg) {
        if (i == n) {
            sols.push_back(sol);
            return;
        }
        for (int j = 0; j< n; j++) {
            if (used_col[j] || used_ldg[i+j] || used_rdg[n-1+i-j])
                continue;
            used_col[j] = used_ldg[i+j] = used_rdg[n-1+i-j] = true;
            sol[i][j] = 'Q';
            solve(i+1, n, sol, sols, used_col, used_ldg, used_rdg);
            sol[i][j] = '.';
            used_col[j] = used_ldg[i+j] = used_rdg[n-1+i-j] = false;
        }
    }
};
