// 8ms 65.79%
void swap(int* nums, int i, int j)
{
    nums[i] ^= nums[j];
    nums[j] ^= nums[i];
    nums[i] ^= nums[j];
}
int binSearch(int *nums, int start, int n, int target)
{
    if (n == 1)   return start;
    int mid = start + n/2;
    if (nums[mid] <= target)    return binSearch(nums, start, n/2, target);
    else    return binSearch(nums, mid, (n-n/2), target);
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1)  return;
    int lhi, rli; // left high index, right low index, left low index
    lhi = rli = numsSize - 1;
    while (lhi > 0 && nums[lhi] <= nums[lhi-1])
        lhi--;
    if (lhi > 0) {
        int pos = binSearch(nums, lhi, numsSize-lhi, nums[lhi-1]);
        swap(nums, pos, lhi-1);
    }
    // reverse
    while(lhi < rli)    swap(nums, lhi++, rli--);
    return;
}


//
//                    lhi
//                    |
//                    _
//                      _
//                  _   | _ _ _ _
//            ....  |   |         _
//                  |  pos        |
//                lhi-1          rli
//
//    1. find the first descending position lhi-1 starting from the end of the
//       sequence, from rli to lhi, numbers are ascending (starting from the
//       end).
//    2. find the first position in [lhi, rli] where nums[pos-1] < nums[lhi-1] <=
//       nums[pos], swap nums pos with lhi-1
//    3. reverse the sequence [lhi, rli] into an ascending order (starting from
//       lhi).
