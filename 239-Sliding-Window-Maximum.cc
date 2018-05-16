class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> winMax;
        deque<int> maxV;
        for (int i = 0; i < nums.size(); i++) {
            // pop numbers which can't be max
            while (!maxV.empty() && maxV.back() < nums[i])
                maxV.pop_back();
            maxV.push_back(nums[i]);
            if (i >= k - 1) {
                winMax.push_back(maxV.front());
                // pop out-of-range max
                if (!maxV.empty() && maxV.front() == nums[i-(k-1)])
                    maxV.pop_front();
            }
        }
        return winMax;
    }
};
