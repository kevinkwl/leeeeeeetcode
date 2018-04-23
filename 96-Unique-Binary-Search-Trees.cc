class Solution {
public:
    int numTrees(int n) {
        vector<int> nTrees(n+1, 0);
        nTrees[0] = 1;
        nTrees[1] = 1;
        nTrees[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                nTrees[i] += nTrees[j-1] * nTrees[i-j];
        }
        return nTrees[n];
    }
};
