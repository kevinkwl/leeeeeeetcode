// 4ms 100%

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int trap(int* height, int heightSize) {
    int water = 0, level;
    int lmax, rmax, l = 0, r = heightSize - 1;
    lmax = rmax = 0;
    while (l < r) {
        level = min(lmax, rmax);
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);
        if (height[l] < height[r]) {
            water += max(0, (level - height[l]));
            l++;
        } else {
            water += max(0, (level - height[r]));
            r--;
        }
    }
    return water;
}
