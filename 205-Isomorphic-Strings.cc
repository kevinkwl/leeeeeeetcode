class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> trans;
        unordered_set<char> mapped;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            if (trans.count(s[i]) == 0) {
                if (mapped.count(t[i]) > 0)
                    return false;
                trans[s[i]] = t[i];
                mapped.insert(t[i]);
            }
            else {
                if (trans[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
