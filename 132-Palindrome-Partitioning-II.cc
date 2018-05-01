// first try
class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1) return 0;
        vector<vector<bool>> ispal(s.size(), vector<bool>(s.size(), false));
        vector<int> mc(s.size(), INT_MAX);
        mc[0] = 0;
        // fill ispal
        for (int i = s.size() - 1; i >= 0; i--) {
            ispal[i][i] = true;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (i == j - 1)
                        ispal[i][j] = true;
                    else
                        ispal[i][j] = ispal[i+1][j-1];
                }
            }
        }
        
        for (int i = 1; i < s.size(); i++) {
            if (ispal[0][i])
                mc[i] = 0;
            else {
                for (int j = 1; j <= i; j++)
                    if (ispal[j][i])
                        mc[i] = min(mc[i], mc[j-1] + 1);
            }
        }
        
        return mc[s.size()-1];
    }
};

// optimized, calculate ispal and mincut simutaneously
class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1) return 0;
        vector<vector<bool>> ispal(s.size(), vector<bool>(s.size(), false));
        vector<int> mc(s.size()+1);
        mc[0] = -1;
        for (int i = 1; i <= s.size(); i++)
            mc[i] = i;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--)
                if (s[j] == s[i] && (i - j < 2 || ispal[j+1][i-1])) {
                    ispal[j][i] = true;
                    mc[i+1] = min(mc[i+1], mc[j] + 1);
                }
        }
        
        return mc[s.size()];
    }
};
