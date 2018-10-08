class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return "";
        string t = "^#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += "$";
        vector<int> p(t.size(), 0);
        int center = 1, right_bound = 1;
        int best_start = 0, best_len = 1;
        for (int i = 1; i < t.size(); i++) {
            p[i] = i < right_bound ? min(p[2*center-i], right_bound - i) : 0;
            if (i + p[i] >= right_bound) {
                while (t[i+p[i]+1] == t[i-p[i]-1])
                    p[i]++;
            }
            
            if (i + p[i] > right_bound) {
                center = i;
                right_bound = i + p[i];
            }
            
            if (p[i] > best_len) {
                //  here, p[i] is the radius of longest parlindrome centered at i
                //  ele in () is the center
                //  case 1: t[i] = '#', #y#x(#)x#y#, p[i] = 4
                //  case 2: t[i] = 'x', #y#(x)#y#, p[i] = 3
                //  in both cases, p[i] == len of longest parlindrome in original string
                //
                //  for the starting index, note that 'abc' -> '^#a#b#c#$', idx(a): 0 -> 2, idx(b): 1 -> 4 ...
                //  (i-p[i]+1) is the start index of char in the extended string
                best_len = p[i];
                best_start = (i - p[i] + 1) / 2 - 1;
            }
        }
        return s.substr(best_start, best_len);
    }
};
