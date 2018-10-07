// 4ms 12.79%

int searchInsert(int* nums, int numsSize, int target) {
    int mid, low = 0, high = numsSize;
    while (low < high) {
        mid = (high + low) / 2;
        if (nums[mid] < target)  low = mid + 1;
        else high = mid;
    }
    return low;
}
