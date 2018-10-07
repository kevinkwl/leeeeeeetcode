class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0)  return false;
        set<long> occur;
        for (int i = 0; i < nums.size(); i++) {
            set<long>::iterator it = occur.lower_bound(long(nums[i])-t);
            if (it != occur.end() && *it <= long(nums[i]) + t)
                return true;
            if (occur.count(nums[i]) == 0)
                occur.insert(nums[i]);
            if (i >= k) { // remove number out of bound
                int n = nums[i-k];
                occur.erase(n); // we can safely erase it because if duplicate exists, we would return true before
            }
        }
        return false;
    }
};

// numbers within abs diff t will be in same bucket or neighboring buckets.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0)  return false;
        unordered_map<long, int> buckets;
        long m = (long) t + 1;
        for (int i = 0; i < nums.size(); i++) {
            long b = ((long) nums[i] - INT_MIN) / m;
            if (buckets.count(b) > 0 ||
                (buckets.count(b-1) > 0 && nums[buckets[b-1]] >= (long) nums[i] - t ||
                (buckets.count(b+1) > 0 && nums[buckets[b+1]] <= (long) nums[i] + t)))
                return true;
            buckets[b] = i;
            if (i >= k) { // remove number out of bound
                long bn = ((long) nums[i-k] - INT_MIN) / m;
                buckets.erase(bn); // no two number will be in same bucket, because if it does, we would return true at an early time.
            }
        }
        return false;
    }
};
