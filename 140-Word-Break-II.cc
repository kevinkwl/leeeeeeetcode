class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<int> cur;
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
        if (dp[s.size()])
            breakWords(0, s, cur, res, wordDict);
        return res;
    }
    
    void breakWords(int i, string& s, vector<int>& cur, vector<string>& res, vector<string>& dict) {
        cout << i <<  ' ';
        if (i == s.size()) {
            string ans = "";
            for (int k = 0; k < cur.size(); k++)
                ans += ( k == 0 ? "" : " ") + dict[cur[k]];
            res.push_back(ans);
            return;
        } else {
            for (int j = 0; j < dict.size(); j++) {
                int len = dict[j].size();
                if (i + len <= s.size() && s.compare(i, len, dict[j]) == 0) {
                    cur.push_back(j);
                    breakWords(i + len, s, cur, res, dict);
                    cur.pop_back();
                }
            }
        }
    }
};
