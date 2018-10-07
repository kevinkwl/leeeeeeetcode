class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int pad = 1;
        while (m != n) {
            m /= 2;
            n /= 2;
            pad *= 2;
        }
        return m * pad;
    }
};
