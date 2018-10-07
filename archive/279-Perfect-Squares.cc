// recursive
class Solution {
public:
    unordered_map<long, int> least;
    vector<long> squares;
    int numSquares(int n) {
        least[0] = 0;
        for (long i = 1; i * i <= n; i++) {
            least[i*i] = 1;
            squares.push_back(i*i);
        }
        return getLeast(n);
    }
    
    int getLeast(int n) {
        if (least.count(n) > 0)
            return least[n];
        int mLeast = n;
        for (long ls : squares)
            if (n >= ls)
                mLeast = min(mLeast, getLeast(n - ls));
        return least[n] = mLeast + 1;
    }
};

// iterative dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; i + j*j <= n; j++) {
                dp[i+j*j] = min(dp[i+j*j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
