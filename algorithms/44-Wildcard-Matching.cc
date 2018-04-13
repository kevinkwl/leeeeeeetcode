class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        int S = s.size(), P = p.size();
        vector<vector<bool>> match(S+1, vector<bool>(P+1, false));
        match[0][0] = true;
        for (int i = 1; i <= P; i++)
            match[0][i] = (match[0][i-1] && p[i-1] == '*');
        
        for (int i = 1; i <= S; i++) {
            for (int j = 1; j <= P; j++) {
                if (p[j-1] == '*') {
                    // 1. '*' matches empty char
                    // 2. '*' matches one or more char(s)
                    match[i][j] = match[i][j-1] || match[i-1][j];
                } else {
                    match[i][j] = match[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '?');
                }
            }
        }
        return match[S][P];
    }
};

// another way
bool isMatch(char* s, char* p) {
    char* lastStar = NULL,* lastStarMatch = NULL;
    while (*s) {
        // we only need to track the last * matching
        // if pattern = ... ,*1, c1, c2, ..., ck, *2,...
        // c1, c2, ..., ck have been matched in s with s1,s2,...,sk,
        // and found the next *2, we never need to backtrack on the previous *1 again
        // if a successful match is: *1 also matches s1, ..., si, then c1, c2, ..., ck must be matched in (si, sm), m > k
        // following this, it must be true that, c1, c2, ..., ck have been matched in s with s1,s2,...,sk, and *2 matches till sm
        // is also a successful match
        if (*p == '*') {
            lastStar = p++;
            lastStarMatch = s;
            continue;
        }
        if (*s == *p || *p == '?') {
            p++;
            s++;
            continue;
        }
        if (lastStar) {
            p = lastStar + 1;
            s = lastStarMatch;
            lastStarMatch++;
            continue;
        }
        return false;
    }
    while (*p)
        if (*(p++) != '*')
            return false;
    return true;
}
