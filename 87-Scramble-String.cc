class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty()) return s2.empty();
        vector<vector<vector<bool>>> dp(s1.size(), vector<vector<bool>>(s2.size(), vector<bool>(s1.size()+1, false)));
        for (int i = 0; i < s1.size(); i++)
            for (int j = 0; j < s2.size(); j++)
                dp[i][j][1] = (s1[i] == s2[j]);
        for (int l = 2; l <= s1.size(); l++) {
            int I = s1.size() - l;
            int J = s2.size() - l;
            for (int i = 0; i <= I; i++) {
                for (int j = 0; j <= J; j++) {
                    for (int lh = 1; lh < l; lh++)
                        if ((dp[i][j][lh] && dp[i+lh][j+lh][l-lh]) ||
                            (dp[i][j+l-lh][lh] && dp[i+lh][j][l-lh])) {
                            dp[i][j][l] = true;
                            break;
                        }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};

// dp[i][j][k]: s1[i:i+k] and s2[j:j+k] are scrambled string of each other
