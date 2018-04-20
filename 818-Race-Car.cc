class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= target; i++) {
            int n = log2(i) + 1;
            if (i + 1 == (1 << n))
                dp[i] = n;
            else {
                dp[i] = n + 1 + dp[(1 << n) - 1 -i];
                for (int j = 0; j < n - 1; j++) {
                    dp[i] = min(dp[i], n + dp[i - (1 << (n-1)) + (1 << j)] + j + 1);
                }
            }
        }
        return dp[target];
    }
};
