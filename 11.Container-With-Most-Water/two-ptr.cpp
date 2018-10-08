class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int maxarea = 0;
        while (lo < hi) {
            int cur = (hi - lo) * min(height[lo], height[hi]);
            maxarea = max(maxarea, cur);
            if (height[lo] < height[hi])
                lo++;
            else if (height[lo] > height[hi])
                hi--;
            else
                lo++, hi--;
        }
        return maxarea;
    }
};
