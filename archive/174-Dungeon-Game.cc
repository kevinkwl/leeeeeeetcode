class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<int> minHP(dungeon[0].size(), 0);
        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = minHP.size() - 1; j >= 0; j--) {
                if (i == dungeon.size() - 1 && j == minHP.size() - 1)   {
                    minHP[j] = max(1, 1 - dungeon[i][j]);
                }
                else if (i == dungeon.size() - 1) {
                    minHP[j] = max(1, minHP[j+1] - dungeon[i][j]);
                }
                else if (j == minHP.size() - 1) {
                    minHP[j] = max(1, minHP[j] - dungeon[i][j]);
                }
                else {
                    minHP[j] = max(1, min(minHP[j], minHP[j+1]) - dungeon[i][j]);
                }
            }
        }
        return minHP[0];
    }
};
