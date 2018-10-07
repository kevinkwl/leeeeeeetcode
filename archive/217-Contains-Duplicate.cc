class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> appeared;
        for (int n : nums) {
            if (appeared.count(n) > 0)
                return true;
            else
                appeared.insert(n);
        }
        return false;
    }
};
