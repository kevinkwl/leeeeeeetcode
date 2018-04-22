class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> dot(3);
        solve(s, 1, 0, dot, res);
        return res;
    }
    
    void solve(string& s, int i, int k, vector<int>& dot, vector<string> &res) {
        if (k == 3) {
            if (dot[2] < s.size() - 3)  return;
            string sn = s.substr(dot[2]);
            if (sn.size() > 1 && sn[0] == '0')
                return;
            int end = stoi(sn);
            if (end > 255)  return;
            string ans = "";
            int prev = 0;
            for (int j = 0; j < 4; j++) {
                if (j < 3) {
                    ans += s.substr(prev, dot[j] - prev) + '.';
                    prev = dot[j];
                }
                else
                    ans += s.substr(prev);
            }
            res.push_back(ans);
        } else {
            int stop = s.size() - 1 - (2 - k);
            for (int j = i; j <= stop && j <= i+3; j++) {
                dot[k] = j;
                string sn = s.substr(dot[k-1], j - dot[k-1]);
                int n = stoi(sn);
                if (sn.size() > 1 && sn[0] == '0')
                    return;
                if (n < 256)
                    solve(s, j+1, k+1, dot, res);
            }
        }
    }

};
