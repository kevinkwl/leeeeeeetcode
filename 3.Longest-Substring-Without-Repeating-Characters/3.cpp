class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, -1);
        int len = 0, prev = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (cnt[c] != -1)
                prev = max(cnt[c] + 1, prev); 
            cnt[c] = i;
            len = max(len, i+1-prev);
        }
        return len;
    }
};
