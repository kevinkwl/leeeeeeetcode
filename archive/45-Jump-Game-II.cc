class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, next_reach = 0, steps = 0;
        // bfs
        for (int i = 0; i < nums.size() - 1; i++) {
            next_reach = max(next_reach, i + nums[i]);
            if (i == reach) {
                steps++;
                reach = next_reach;
            }
        }
        return steps;
    }
};
