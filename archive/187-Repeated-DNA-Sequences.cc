class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> reps;
        unordered_map<string, int> occur;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string cur = s.substr(i, 10);
            if (occur.count(cur) == 0)
                occur[cur] = 0;
            else if (occur[cur] == 1)
                reps.push_back(cur);
            occur[cur]++;
        }
        return reps;
    }
};


// use bit manipulation !!
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> reps;
        unordered_map<int, int> occur;
        unordered_map<char, int> cmap;
        cmap['A'] = 0;
        cmap['C'] = 1;
        cmap['G'] = 2;
        cmap['T'] = 3;
        bool first = true;
        int cur = 0;
        for (int i = 0; i + 10 <= s.size(); i++) {
            if (first) {
                for (int j = 0; j < 10; j++) {
                    cur = (cur << 2) | cmap[s[i+j]];
                }
                first = false;
            } else
                cur = ((cur << 2) | cmap[s[i+9]]) & 0xfffff; // 20-bit
            if (occur.count(cur) == 0)
                occur[cur] = 0;
            else if (occur[cur] == 1)
                reps.push_back(s.substr(i, 10));
            occur[cur]++;
        }
        return reps;
    }
};

