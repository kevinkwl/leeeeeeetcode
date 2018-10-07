class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>{0};
        vector<int> codes{0, 1};
        for (int i = 2; i <= n; i++) {
            int base = 1 << (i - 1);
            for (int j = codes.size() - 1; j >= 0; j--)
                codes.push_back(base | codes[j]);       // generating codes based on prev codes
        }
        return codes;
    }
};

// in fact, gray(i) = i ^ (i >> 1)
// wonderful proof on gray code https://math.stackexchange.com/a/426001
