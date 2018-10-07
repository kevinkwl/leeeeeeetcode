class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        int ugly[1700];
        ugly[1] = 1;
        int p2, p3, p5;
        p2 = p3 = p5 = 1;
        for (int i = 2; i <= n; i++) {
            int next = min(ugly[p2] * 2, min (ugly[p3] * 3, ugly[p5] * 5));
            ugly[i] = next;
            if (next == ugly[p2] * 2)   p2++;
            if (next == ugly[p3] * 3)   p3++;
            if (next == ugly[p5] * 5)   p5++;
        }
        return ugly[n];
    }
};
