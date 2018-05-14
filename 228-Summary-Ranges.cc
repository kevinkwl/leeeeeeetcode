class Solution {
public:
    string getRange(int s, int e) {
        return to_string(s) + (e == s ? "" : "->" + to_string(e));
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() == 0)  return ranges;
        int range_start = nums[0], range_end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                range_end = nums[i];
            } else {
                ranges.push_back(getRange(range_start, range_end));
                range_start = range_end = nums[i];
            }
        }
        ranges.push_back(getRange(range_start, range_end));
        return ranges;
    }
};
