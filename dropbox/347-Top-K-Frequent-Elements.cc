class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int n : nums) {
            ++freq[n];
        }
        vector<pair<int, int>> flip;
        for (auto i = freq.begin(); i != freq.end(); i++)
            flip.push_back(make_pair(i->second, i->first));
        
        priority_queue<pair<int, int>> pqueue(flip.begin(), flip.end());
        vector<int> res;
        while (k--) {
            res.push_back(pqueue.top().second);
            pqueue.pop();
        }
        return res;
    }
};
