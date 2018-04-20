class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(n+2, 0);
        ways[0] = 1;
        for (int i = 0; i < n; i++) {
            if (ways[i] != 0) {
                ways[i+1] += ways[i];
                ways[i+2] += ways[i];
            }
        }
        return ways[n];
    }
};
