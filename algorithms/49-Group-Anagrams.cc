class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> group;
        for (int i = 0; i < strs.size(); i++) {
            string si = strs[i];
            sort(si.begin(), si.end());
            if (group.count(si) > 0)
                ans[group[si]].push_back(strs[i]);
            else {
                ans.push_back(vector<string>{strs[i]});
                group[si] = ans.size() - 1;
            }
        }
        return ans;
    }
};
