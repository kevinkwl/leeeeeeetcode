class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return "";
        int best = -1, cur = 0, besti, bes;
        for (int i = 0; i < s.size(); i++) {
            cur = 1;
            int j;
            // expand with center i
            for (j = 1; j <= i && i+j < s.size(); j++, cur+=2) {
                if (s[i-j] != s[i+j])
                    break;
            }
            if (cur > best) {
                besti = i-j+1;
                best = cur;
            }
            cur = 0;
            //expand with [i, i+1]
            for (j = 1; i+1-j>=0 && i+j < s.size(); j++, cur+=2) {
                if (s[i+1-j] != s[i+j])
                    break;
            }
            if (cur > best) {
                besti = i+1-j+1;
                best = cur;
            }
        }
        return s.substr(besti, best);
    }
};
