// 8ms 72.59%

#define abs(x) ((x >= 0? (x) : (-(x))))
int cmp(const void *a, const void *b)
{
    int arg1 = *(const int *)a, arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int pvt = 0, lo, hi;
    int pv, threeSum, dist, best_dist=INT_MAX;
    while (pvt < numsSize) {
        pv = nums[pvt];
        lo = pvt + 1;
        hi = numsSize - 1;
        while (lo < hi) {
            threeSum = nums[lo] + nums[hi] + pv;
            dist = threeSum - target;
            if (abs(dist) < abs(best_dist))
                best_dist = dist;
            if (dist == 0)  break;
            if (dist < 0) {
                do { lo++; } while (lo < hi && nums[lo] == nums[lo-1]);
            } else {
                do { hi--; } while (lo < hi && nums[hi] == nums[hi+1]);
            }
        }
        do { pvt++; } while (pvt < numsSize && nums[pvt] == nums[pvt-1]);
    }
    return target + best_dist;
}
