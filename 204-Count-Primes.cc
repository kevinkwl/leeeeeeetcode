class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> np(n, false);
        int cnt = n / 2;
        for (int i = 3; i * i < n; i += 2) {
            if (np[i])
                continue;
            for (long j = (long)i * i; j < n; j += i * 2) {
                if (!np[j]) cnt--;
                np[j] = true;
            }
        }
        return cnt;
    }
};
