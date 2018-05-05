// Moore's Voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majority;
        for (int n : nums) {
            if (count == 0)
                majority = n;
            if (n == majority)
                count++;
            else
                count--;
        }
        return majority;
    }
};
