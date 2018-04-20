// NFA simulation
class Solution {
public:
    bool isMatch(string s, string p) {
        set<int> prev_pos, next_pos;
        next_pos.insert(0);
        int accept = p.size();
        // get all possible starting states
        for (int i = 1; i < p.size(); i+=2) {
            if (p[i] == '*')
                next_pos.insert(i+1);
            else
                break;
        }
        for (char ch : s) {
            swap(next_pos, prev_pos);
            next_pos.clear();
            for (int pos : prev_pos) {
                // at accepting pos
                if (pos >= accept)
                    continue;
                // no out transition
                if (p[pos] != '.' && p[pos] != ch)
                    continue;
                else {
                    int start = pos + 1;
                    if (pos < accept - 1 && p[pos+1] == '*') {
                        next_pos.insert(pos);
                        next_pos.insert(pos + 2);
                        start = pos + 2;
                    } else
                        next_pos.insert(pos+1);
                    // step further if the following pattern can be skipped --- 'x*'
                    while (start < accept - 1 && p[start+1] == '*') {
                        if (next_pos.count(start+2) > 0)  // already added
                            break;
                        next_pos.insert(start+2);
                        start += 2;
                    }
                }
            }
        }
        return next_pos.count(accept) > 0;    
    }
};


// dynamic programming
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())  return s.empty();
        int S = s.size(), P = p.size();
        // match[i][j]: s[0]...s[i-1] matches with p[0]...p[j-1]
        vector<vector<bool>> match(S + 1, vector<bool>(P + 1, false));
        match[0][0] = true;
        // non-empty string never matches with empty pattern
        for (int i = 1; i <= S; i++)
            match[i][0] = false;
        // empty string only matches with pattern accepting empty
        for (int i = 1; i <= P; i++)
            match[0][i] = (p[i-1] == '*' ? match[0][i-2] : false);
        
        for (int i = 1; i <= S; i++) {
            for (int j = 1; j <= P; j++) {
                // in this case, match[i][j] is true iff p[j-1] matches with s[i-1]
                if (p[j-1] != '*')
                    match[i][j] = match[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                
                // '_*' can be 0 or more _ characters.
                //      1. if match[i][j-2] is true, then p[j-2],p[j-1] forms a '_*'
                // pattern, which can be mapped to empty string
                //      2. otherwise, if match[i-1][j] is true, match[i][j] is
                //         true iff s[i-1] matches with p[j-2] ( _ )
                //
                //  note:   match[i][j] also holds when match[i][j-1] = true, 
                //          in this case, p[j-2] can only be '.' or a specific char, which
                //          means p[j-2] matches with s[i-1], and match[i-1][j] = true because 
                //          the pattern '_*' (p[j-2], p[j-1]) can be matched to
                //          empty string s[i-1 : i-1]. This is covered in
                //          situation 2
                else
                    match[i][j] = match[i][j-2] || (match[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            }
        }
        return match[S][P];
    }
}; 
