class Solution {
public:    
    void genCombinations(string digits, vector<string> &combs, vector<string> &d2c, string comb) {
        if (comb.size() == digits.size()) {
            combs.push_back(comb);
            return;
        } else {
            for (char c : d2c[digits[comb.size()]-'0']) {
                comb.push_back(c);
                genCombinations(digits, combs, d2c, comb);
                comb.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> d2c = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combs;
        if (digits.empty()) return combs;
        string comb = "";
        genCombinations(digits, combs, d2c, comb);
        return combs;
    }
};
