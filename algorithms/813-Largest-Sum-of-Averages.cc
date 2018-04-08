class Solution {
public:
    vector<int> sum;
    double largestSumOfAverages(vector<int>& A, int K) {
        sum.resize(A.size()+1);
        sum[0] = 0;
        for (int i = 0; i < A.size(); i++)
            sum[i+1] = sum[i] + A[i];
        vector<vector<double>> ans(A.size(), vector<double>(A.size()+1, -1));
        return maxSumOfAvg(0, A.size(), K, ans);
    }
    
    double maxSumOfAvg(int start, int N, int K, vector<vector<double>> &ans) {
        if (ans[start][K] != -1) {
            return ans[start][K];
        }
        if (start + K == N) {
            ans[start][K] = sum[N] - sum[start];
            return ans[start][K];
        }
        if (K == 1) {
            ans[start][K] = (sum[N] - sum[start]) * 1.0 / (N - start);
            return ans[start][K];
        }
        double cur;
        double maxAvg = 0;
        for (int i = start + 1; i <= N - (K - 1); i++) {
            cur = (sum[i] - sum[start]) * 1.0 / (i - start);
            maxAvg = max(maxAvg, cur + maxSumOfAvg(i, N, K-1, ans));
        }
        return (ans[start][K] = maxAvg);
    }
};
