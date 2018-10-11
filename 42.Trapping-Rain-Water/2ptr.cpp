class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0;
        int l = 0, r = 0;
        int lcur = 0, rcur = height.size() - 1;
        while (lcur <= rcur) {
            // left
            l = max(l, height[lcur]);
            r = max(r, height[rcur]);
            if (l < r) {
                trapped += max(0, l - height[lcur]);
                lcur++;
            } else if (l > r) {
                trapped += max(0, r - height[rcur]);
                rcur--;
            } else {
                trapped += max(0, l - height[lcur]);
                if (lcur != rcur)
                    trapped += max(0, r - height[rcur]);
                lcur++;
                rcur--;
            }
        }
        return trapped;
    }
};
