// 68ms 78.95%
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    int arg1 = *(const int *)a, arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int cap = 2;
    int **triplets = (int **)malloc(cap * sizeof(int*));
    int tripSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int pvt = 0, lo, hi;
    int pv, twoSum;
    while (pvt < numsSize) {
        pv = nums[pvt];
        lo = pvt + 1;
        hi = numsSize - 1;
        while (lo < hi) {
            twoSum = nums[lo] + nums[hi];
            if (twoSum == -pv) {
                int *trp = (int *)malloc(3 * sizeof(int));
                trp[0] = pv, trp[1] = nums[lo], trp[2] = nums[hi];
                if (tripSize == cap) {
                    cap *= 2;
                    triplets = realloc(triplets, cap * sizeof(int *));
                }
                triplets[tripSize++] = trp;
                do { lo++; } while (lo < hi && nums[lo] == nums[lo-1]);
                do { hi--; } while (lo < hi && nums[hi] == nums[hi+1]);
            } else if (twoSum < -pv) {
                do { lo++; } while (lo < hi && nums[lo] == nums[lo-1]);
            } else {
                do { hi--; } while (lo < hi && nums[hi] == nums[hi+1]);
            }
        }        
        do { pvt++; } while (pvt < numsSize && nums[pvt] == nums[pvt-1]);
    }
    *returnSize = tripSize;
    return triplets;
}
