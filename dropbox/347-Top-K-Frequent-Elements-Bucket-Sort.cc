class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            ++freq[n];
        }
        vector<int> res;
        vector<vector<int>> bucket(nums.size()+1, vector<int>{});
        for (auto it = freq.begin(); it != freq.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        int i = bucket.size() - 1;
        while (k > 0) {
            int cnt = min(int(bucket[i].size()), k);
            res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + cnt);
            k -= bucket[i].size();
            i--;
        }
        return res;
    }
};
