// 4ms 100%

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int trap(int* height, int heightSize) {
    int water = 0;
    int lmax, rmax, l = 0, r = heightSize - 1;
    lmax = rmax = 0;
    while (l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);
        if (height[l] < height[r]) {
            water += max(0, min(lmax, rmax) - height[l]);
            l++;
        } else {
            water += max(0, min(lmax, rmax) - height[r]);
            r--;
        }
    }
    return water;
}
