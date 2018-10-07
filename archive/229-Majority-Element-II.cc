class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int K = 2;
        int maj[K] = {}, cnt[K] = {0, 0};
        for (int n : nums) {
            int mi;
            for (mi = 0; mi < K; mi++) {
                if (cnt[mi] != 0 && maj[mi] == n) {
                    ++cnt[mi];
                    break;
                }
            }
            // not found
            if (mi == K) {
                for (mi = 0; mi < K; mi++)
                    if (cnt[mi] == 0)
                        break;
                // no slot left
                if (mi == K) {
                    for (mi = 0; mi < K; mi++)
                        --cnt[mi];
                } else {
                    maj[mi] = n;
                    cnt[mi] = 1;
                }
            }
        }
        for (int i = 0; i < K; i++)
            cnt[i] = 0;
        for (int n : nums) {
            for (int i = 0; i < K; i++)
                if (n == maj[i]) {
                    cnt[i]++;
                    break;
                }
        }
        int thresh = nums.size() / 3;
        vector<int> ans;
        for (int i = 0; i < K; i++)
            if (cnt[i] > thresh)
                ans.push_back(maj[i]);
        return ans;
    }
};
