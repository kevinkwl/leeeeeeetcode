class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int K = 2;
        vector<vector<int>> dp(K+1, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            int tmpMax = dp[k-1][0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[k][i] = max(dp[k][i-1], tmpMax + prices[i]);
                tmpMax = max(tmpMax, dp[k-1][i] - prices[i]);
            }
        }
        return dp[2][prices.size()-1];
    }
};
