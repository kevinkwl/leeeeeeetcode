class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty() || s.size() == 1) return s;
        string r(s.rbegin(), s.rend());
        vector<int> p(s.size()+1, 0);
        p[1] = 0;
        int k = 0;
        // build p with pattern s
        for (int i = 2; i <= s.size(); i++) {
            while (k > 0 && s[k] != s[i-1])
                k = p[k];
            if (s[k] == s[i-1])
                k++;
            p[i] = k;
        }
        k = 0;
        int i = 0;
        // match reverse with pattern s
        for (; i < r.size(); i++) {
            while (k > 0 && s[k] != r[i])
                k = p[k];
            if (r[i] == s[k])
                k++;
        }
        if (k == r.size())
            return s;
        else
            return r.substr(0, r.size()-k) + s;
    }
};
