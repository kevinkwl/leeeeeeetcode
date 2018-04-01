int search(int* nums, int numsSize, int target) {
    int pvt;
    int lo = 0, hi = numsSize - 1, mid;
    while (lo < hi) {
        if (nums[lo] < nums[hi])
            break;
        mid = lo + (hi - lo) / 2;
        if (nums[mid] >= nums[lo])
            lo = mid + 1;
        else
            hi = mid;
    }
    pvt = lo;
    lo = 0; 
    hi = numsSize - 1;
    int midv;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        midv = nums[(mid+pvt) % numsSize];
        if (midv < target)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (lo >= numsSize || nums[(lo+pvt) % numsSize] != target)
        return -1;
    return (lo + pvt) % numsSize;
}
