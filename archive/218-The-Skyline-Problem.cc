class Solution {
public:
    using Skyline = vector<pair<int, int>>;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0) return Skyline{};
        return skyline(buildings, 0, buildings.size()-1);
    }
    
    Skyline skyline(vector<vector<int>>& bds, int b, int e) {
        if (b == e) {
            Skyline skl{make_pair(bds[b][0], bds[b][2]), 
                                       make_pair(bds[b][1], 0)};
            return skl;
        }
        int mid = b + (e - b) / 2;
        Skyline left = skyline(bds, b, mid);
        Skyline right = skyline(bds, mid+1, e);
        
        // merge
        Skyline skl;
        int l = 0, r = 0;
        int hl = 0, hr = 0, cur;
        while (l < left.size() || r < right.size()) {
            if (l < left.size() && r < right.size()) {
                if (left[l].first < right[r].first) {
                    cur = left[l].first;
                    hl = left[l].second;
                    l++;
                } else {
                    cur = right[r].first;
                    hr = right[r].second;
                    r++;
                }
            } else if (l < left.size()) {
                cur = left[l].first;
                hl = left[l].second;
                l++;
            } else {
                cur = right[r].first;
                hr = right[r].second;
                r++;
            }
            int h = max(hl, hr); // higher building shadows lower ones
            if (!skl.empty()) { 
                if (skl.back().second == h)  // same height as before, skipping
                    continue;
                if (skl.back().first == cur) {      // same starting pos, might need to update the last point's height
                    skl.back().second = max(skl.back().second, h);
                    if (hl == 0 && hr == 0)     // if all drops to 0, set to 0 ( case [[1,2,1], [1,2,2]])
                        skl.back().second = 0;
                    continue;
                }
            }
            skl.push_back(make_pair(cur, h));
        }
        return skl;
    }
};
