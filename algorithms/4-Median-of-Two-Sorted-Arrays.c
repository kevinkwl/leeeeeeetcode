#define min(a, b) ((a) < (b) ? (a) : (b))
int findKth(int *nums1, int n1, int *nums2, int n2, int k) {
    if (n1 > n2)
        return findKth(nums2, n2, nums1, n1, k);
    if (n1 == 0)
        return nums2[k-1];
    if (k == 1)
        return min(nums1[0], nums2[0]);
    int i1 = min(n1, k/2), i2 = k/2;
    if (nums1[i1-1] <= nums2[i2-1])
        return findKth(nums1 + i1, n1 - i1, nums2, n2, k - i1);
    else
        return findKth(nums1, n1, nums2 + i2, n2 - i2, k - i2);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k1 = (nums1Size + nums2Size + 1) / 2, k2 = (nums1Size + nums2Size + 2) / 2;
    int m1 = findKth(nums1, nums1Size, nums2, nums2Size, k1);
    if (k2 == k1)
        return m1;
    return (m1 + findKth(nums1, nums1Size, nums2, nums2Size, k2)) / 2.0;
}
