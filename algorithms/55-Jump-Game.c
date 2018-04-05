bool canJump(int* nums, int numsSize) {
    int farthest = 0;
    for (int i = 0; i <= farthest && i < numsSize; i++) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;
    }
    return farthest >= numsSize - 1;
}
