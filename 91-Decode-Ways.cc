class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            dp[i] = s[i-1] != '0' ? dp[i-1] : 0;
            if (i > 1) {
                int n = stoi(s.substr(i-2, 2));
                if (n >= 10 && n <= 26)
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
