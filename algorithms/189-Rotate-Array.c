void swap(int* nums, int i, int j) {
    int tmp;
    tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}
void reverse(int* nums, int s, int e) {
    while (s < e) {
        swap(nums, s++, e--);
    }
}
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

