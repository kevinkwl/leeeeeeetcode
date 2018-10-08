class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return "";
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        dp[s.size()-1][s.size()-1] = true;
        int pstart = 0, plen = 1;
        for (int i = 0; i < s.size()-1; i++) {
            dp[i][i] = true;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                pstart = i;
                plen = 2;
            }
        }
        
        for (int l = 3; l <= N; l++)
            for (int i = 0; i <= N-l; i++) {
                if (dp[i+1][i+l-2] && s[i] == s[i+l-1]) {
                    dp[i][i+l-1] = true;
                    if (l > plen) {
                        pstart = i;
                        plen = l;
                    }
                }
            }
        return s.substr(pstart, plen);
    }
};
