class Solution {
public:
    string minWindow(string s, string t) {
        int sl = s.length(), tl = t.length();
        if (sl <= 0 || tl <= 0)
            return "";
        int charcnt[128] = {0};
        int curcnt[128] = {0};
        for (char c : t)
            charcnt[c]++;
        
        int best = -1, min_len = sl + 1, begin = 0, len = 0, meet = 0;
        for (int i = 0; i < sl; i++) {
            char ch = s[i];
            len++;
            if (charcnt[ch] > 0) {
                curcnt[ch]++;
                if (curcnt[ch] <= charcnt[ch])
                    meet++;
            }
            if (meet == tl) {
                // skip beginning non-template char and overly counted char
                while (charcnt[s[begin]] == 0 || curcnt[s[begin]] > charcnt[s[begin]]) {
                    curcnt[s[begin]]--; // doesn't care about non-t char, leave it be
                    len--;
                    begin++;
                }
                if (len < min_len) {
                    best = begin;
                    min_len = len;
                }
                // update window
                len--;          
                meet--;
                curcnt[s[begin]]--;
                begin++;
            }
        }
        return best >= 0 ? s.substr(best, min_len) : "";
    }
};
