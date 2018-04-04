class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n;
        if (m == 0 || (n = matrix[0].size()) == 0)
            return vector<int>{};
        int size = m * n;
        vector<int> spiral(size);
        int bound[] = {n, m}; // col, row
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // >, v, <, ^
        int d = 0, pos[] = {0, -1};
        int i = 0;
        while (i < size) {
            for (int k = 0; k < bound[d%2]; k++) {
                pos[0] += dir[d][0];
                pos[1] += dir[d][1];
                spiral[i++] = matrix[pos[0]][pos[1]];
            }
            bound[1-d%2]--;
            d = (d+1) % 4;
        }
        return spiral;
    }
};
