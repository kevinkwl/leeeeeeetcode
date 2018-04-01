int findMin(int* nums, int numsSize) {
    int lo = 0, hi = numsSize - 1, mid;
    while (lo < hi) {
        if (nums[lo] <= nums[hi])
            break;
        mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    return nums[lo];
}
