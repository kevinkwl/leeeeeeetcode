// max sub array sum !
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0, tsum = 0;
        for (int i = 1; i < prices.size(); i++) {
            tsum += prices[i] - prices[i-1];
            if (tsum < 0)
                tsum = 0;
            if (tsum > best)
                best = tsum;
        }
        return best;
    }
};
