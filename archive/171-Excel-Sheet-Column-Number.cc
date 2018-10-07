class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        for (char cc : s)
            col = col * 26 + (cc - 'A' + 1);
        return col;
    }
};
