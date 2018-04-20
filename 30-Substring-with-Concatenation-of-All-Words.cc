class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int sl = s.length(), n_words = words.size();
        if (sl <= 0 || n_words <= 0)
            return res;
        int wl = words[0].length();
        if (sl < wl * n_words)
            return res;
        
        unordered_map<string, int> wcnt;
        for (string& word : words)  
            wcnt[word]++;
        
        unordered_map<string, int> appeared;        
        string token, skip;
        int start, found;
        for (int i = 0; i < wl; i++) {
            if (sl - i < wl * n_words)
                break;
            start = i;
            found = 0;
            appeared.clear();
            for (int j = i; j <= sl - wl; j += wl) {
                token = s.substr(j, wl);
                if (wcnt.count(token) > 0) {           // valid substring
                    appeared[token]++;                      
                    if (appeared[token] > wcnt[token]) {
                        do {
                            skip = s.substr(start, wl);
                            start += wl;
                            appeared[skip]--;
                            found--;
                        } while (skip != token);        // skip until the first appearance of token is dropped.
                    }
                    found++;
                } else {                // invalid substring, skip over
                    found = 0;
                    start = j + wl;
                    appeared.clear();
                }
                if (found == n_words) {
                    res.push_back(start);
                    skip = s.substr(start, wl);
                    appeared[skip]--;
                    found--;
                    start += wl;
                }
            }
        }
        return res;
    }
};
