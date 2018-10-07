class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> change(amount+1, INT_MAX);
        change[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0 && change[i-c] != INT_MAX)
                        change[i] = min(change[i], 1 + change[i-c]);
            }
        }
        return change[amount] == INT_MAX ? -1 : change[amount];
    }
};
