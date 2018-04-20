class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (string &word : wordDict) {
                if (i >= word.size() && s.compare(i-word.size(), word.size(), word) == 0 && dp[i-word.size()]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
