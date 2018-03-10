// 12ms 14.69%

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int maxArea(int* height, int heightSize) {
    int maxA = 0, curA, l = 0, h = heightSize - 1;
    while (l < h) {
        curA = min(height[l], height[h]) * (h - l);
        maxA = max(curA, maxA);
        if (height[l] < height[h])
            l++;
        else
            h--;
    }
    return maxA;
}
