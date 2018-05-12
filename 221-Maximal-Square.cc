class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int C = matrix[0].size();
        vector<int> maxs(C, 0);
        int prev = 0, maxSide = 0;
        for (int r = 0; r < matrix.size(); r++) {
            prev = 0;
            for (int c = 0; c < C; c++) {
                int tmp = maxs[c];
                if (matrix[r][c] == '0') {
                    maxs[c] = 0;
                } else {
                    maxs[c] = min(maxs[c] + 1, prev + 1);
                    if (c > 0)
                        maxs[c] = min(maxs[c], maxs[c-1] + 1);
                    maxSide = max(maxSide, maxs[c]);
                }
                prev = tmp;
            }
        }
        return maxSide * maxSide;
    }
};
