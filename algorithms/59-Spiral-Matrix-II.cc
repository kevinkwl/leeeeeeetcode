class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0)
            return vector<vector<int>>{};
        int maxNum = n * n;
        vector<vector<int>> spiral(n, vector<int>(n));
        int bound[] = {n, n}; // col, row
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // >, v, <, ^
        int d = 0, pos[] = {0, -1};
        int i = 1;
        while (i <= maxNum) {
            for (int k = 0; k < bound[d%2]; k++) {
                pos[0] += dir[d][0];
                pos[1] += dir[d][1];
                spiral[pos[0]][pos[1]] = i++;
            }
            bound[1-d%2]--;
            d = (d+1) % 4;
        }
        return spiral;
    }
};
