class Solution {
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wd.find(s.substr(j, i-j)) != wd.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
