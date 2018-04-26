class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> parts;
        pp(0, 1, s, parts, res);
        return res;
    }
    
    void pp(int prev, int cur, string&s, vector<string>& parts, vector<vector<string>>& res) {
        if (cur == s.size()) {
            string last = s.substr(prev, cur - prev);
            if (last == string(last.rbegin(), last.rend())) {
                parts.push_back(last);
                res.push_back(parts);
                parts.pop_back();
            }
            return;
        }
        pp(prev, cur+1, s, parts, res);
        string curP = s.substr(prev, cur - prev);
        if (curP == string(curP.rbegin(), curP.rend())) {
            parts.push_back(curP);
            pp(cur, cur+1, s, parts, res);
            parts.pop_back();
        }
    }
};
