class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        if (k >= prices.size() / 2) { // make profit as much as possible, k seperate transactions
            int profit = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            return profit;
        }
        vector<int> mp(prices.size(), 0);
        k = min(k, int(prices.size()) - 1); // we can complete at most this amount of transactions
        for (int kk = 1; kk <= k; kk++) {
            int tmpMax = mp[0] - prices[0];
            mp[0] = 0;
            for (int i = 1; i < prices.size(); i++) {
                int nextTmpMax = max(tmpMax, mp[i] - prices[i]);
                mp[i] = max(mp[i-1], tmpMax + prices[i]);
                tmpMax = nextTmpMax;
            }
        }
        return mp[prices.size()-1];
    }
};
