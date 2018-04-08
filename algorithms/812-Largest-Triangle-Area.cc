class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double largest = 0;
        double cur;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                for (int k = j + 1; k < N; k++) {
                    cur = areaOf(points[i], points[j], points[k]);
                    if (cur > largest)
                        largest = cur;
                }
        return largest;
    }
    double areaOf(vector<int> &A, vector<int> &B, vector<int> &C) {
        int x1 = B[0] - A[0];
        int y1 = B[1] - A[1];
        int x2 = C[0] - A[0];
        int y2 = C[1] - A[1];
        double area = 0.5 * (x1 * y2 - x2 * y1);
        return area >= 0 ? area : -area;
    }
};
