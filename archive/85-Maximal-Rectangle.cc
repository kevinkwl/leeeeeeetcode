class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int R = matrix.size(), C = matrix[0].size();
        vector<int> h(C, 0), left(C, 0), right(C, C);
        int maxArea = 0;
        for (int r = 0; r < R; r++) {
            int curLeft = 0, curRight = C;
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == '0') {
                    curLeft = c+1;
                    left[c] = 0;
                } else {
                    left[c] = max(left[c], curLeft);    // we can extend current height to left[c]
                }
            }
            for (int c = C-1; c >= 0; c--) {
                if (matrix[r][c] == '0') {
                    curRight = c;
                    right[c] = C;
                } else {
                    right[c] = min(right[c], curRight); // we can extend current height to right[c]
                }
            }
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == '1') {
                    h[c]++;
                    int area = (right[c] - left[c]) * h[c];
                    maxArea = max(area, maxArea);
                } else {
                    h[c] = 0;
                }
            }
        }
        return maxArea;
    }
};
