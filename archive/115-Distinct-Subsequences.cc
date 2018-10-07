class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= s.size(); i++)
            dp[i][0] = 1;
        
        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= t.size(); j++) {
                // two possibilities
                // 1. s[i-1] is not used as the ending char of t[0], t[1], ..., t[j-1]
                // 2. s[i-1] is used
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
            }
        return dp[s.size()][t.size()];
    }
};
