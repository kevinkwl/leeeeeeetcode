class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        int b = 0, e = 0;
        int sum = 0, minlen = INT_MAX;
        while (b < nums.size() && e <= nums.size()) {
            while (sum >= s && b < nums.size()) {
                int len = e - b;
                minlen = min(minlen, len);
                sum -= nums[b];
                b++;
            }
            while (sum < s && e < nums.size())
                sum += nums[e++];
            if (e == nums.size()) {
                if (b == 0 && sum < s)
                    return 0;
                else if (sum < s)
                    break;
            }
        }
        return minlen;
    }
};

// cleaner
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        int b = 0, e = 0;
        int sum = 0, minlen = INT_MAX;
        while (e < nums.size()) {
            sum += nums[e++];
            while (sum >= s && b < nums.size()) {
                int len = e - b;
                minlen = min(minlen, len);
                sum -= nums[b];
                b++;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
