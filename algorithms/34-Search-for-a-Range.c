/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1, ans[1] = -1;
    int mid, low = 0, high = numsSize;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[mid] < target)  low = mid + 1;
        else high = mid;
    }
    if (low == high && high < numsSize && nums[low] == target) {
        ans[0] = low;
        low = 0, high = numsSize;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > target) high = mid;
            else low = mid;
            if (low + 1 == high) {
                if (nums[low] == target)
                    ans[1] = low;
                break;
            }
        }
    }
    return ans;
}
