class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        // not intersect
        if (!(E >= C || G <= A || F >= D || H <= B)) {
            int l, h;
            l = (C - A) - max(E - A, 0) - max(C - G, 0); // intersect region length
            h = (D - B) - max(F - B, 0) - max(D - H, 0); // intersect region height
            area -= l * h;
        }
        return area;
    }
};
