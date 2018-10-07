class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(0, nums.size()-1, k, nums);
    }
    
    int findKthLargest(int i, int j, int k, vector<int>& nums) {
        if (i == j) return nums[i];
        int r = rand() % (j - i + 1) + i;
        swap(nums[i], nums[r]);
        int pivot = nums[i];
        int lo = i, hi = j;
        while (lo < hi) {
            while (lo < hi && nums[hi] <= pivot)
                hi--;
            if (lo < hi)
                swap(nums[lo++], nums[hi]);
            while (lo < hi && nums[lo] >= pivot)
                lo++;
            if (lo < hi)
                swap(nums[hi--], nums[lo]);
        }
        nums[lo] = pivot;
        int kth = lo - i + 1;
        if (kth == k)
            return pivot;
        else if (kth < k)
            return findKthLargest(lo+1, j, k-kth, nums);
        else
            return findKthLargest(i, lo-1, k, nums);
    }
};
