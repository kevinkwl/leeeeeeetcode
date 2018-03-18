// 28ms 67.24%

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    int arg1 = *(const int *)a, arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (numsSize < 4) { *returnSize = 0; return NULL; }
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 2;
    int **qdps = (int **)malloc(cap * sizeof(int*));
    int qSize = 0;
    int fSum, pvt1 = 0, pvt2, lo, hi;
    while (pvt1 < numsSize) {
        pvt2 = pvt1 + 1;
        while (pvt2 < numsSize) {
            lo = pvt2 + 1;
            hi = numsSize - 1;
            while (lo < hi) {
                fSum = nums[pvt1] + nums[pvt2] + nums[lo] + nums[hi];
                if (fSum == target) {
                    int *qdp = (int*)malloc(4 * sizeof(int));
                    qdp[0] = nums[pvt1], qdp[1] = nums[pvt2], qdp[2] = nums[lo], qdp[3] = nums[hi];
                    if (qSize == cap) {
                        cap *= 2;
                        qdps = realloc(qdps, cap * sizeof(int *));
                    }
                    qdps[qSize++] = qdp;
                    do { lo++; } while (lo < hi && nums[lo] == nums[lo-1]);
                    do { hi--; } while (lo < hi && nums[hi] == nums[hi+1]);
                } else if (fSum < target) {
                    do { lo++; } while (lo < hi && nums[lo] == nums[lo-1]);
                } else {
                    do { hi--; } while (lo < hi && nums[hi] == nums[hi+1]);
                }
            }
            do { pvt2++; } while (pvt2 < numsSize && nums[pvt2] == nums[pvt2-1]);
        }
        do { pvt1++; } while (pvt1 < numsSize && nums[pvt1] == nums[pvt1-1]);
    }
    *returnSize = qSize;
    return qdps;
}
