class Solution {
public:
    int partition(vector<int>& nums, int i, int n, int piv=0) {
        swap(nums[i], nums[i+piv]);
        int pivot = nums[i];
        int lo = i, hi = i + n - 1;
        while (lo < hi) {
            while (lo < hi && nums[hi] > pivot) hi--;
            if (lo < hi)    swap(nums[lo++], nums[hi]);
            while (lo < hi && nums[lo] < pivot) lo++;
            if (lo < hi)    swap(nums[lo], nums[hi--]);
        }
        return lo;
    }
    int findKth(vector<int>& nums, int i, int n, int k) {
        int pos = partition(nums, i, n) - i;
        if (pos == k - 1)
            return nums[pos + i];
        if (pos > k - 1)
            return findKth(nums, i, pos, k);
        else
            return findKth(nums, i + pos + 1, n - pos - 1, k - pos - 1);
    }
    
    int vid(int i, int n) {
        return (1 + 2*i) % (n | 1);
    }
    void wiggleSort(vector<int>& nums) {
        int N = nums.size();
        int med = findKth(nums, 0, N, N/2 + 1);
        int i = 0, j = 0, k = N - 1;
        // advanced partition!!!! 
        while (j <= k) {
            if (nums[vid(j, N)] > med)
                swap(nums[vid(i++, N)], nums[vid(j++, N)]);
            else if (nums[vid(j, N)] < med)
                swap(nums[vid(j, N)], nums[vid(k--, N)]);
            else
                j++;
        }
    }
};
