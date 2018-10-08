class Solution {
public:
    int findKth(vector<int> &nums1, int i1, int n1, vector<int> &nums2, int i2, int n2, int K) {
        if (n1 > n2)
            return findKth(nums2, i2, n2, nums1, i1, n1, K);
        if (n1 == 0)
            return nums2[i2+K-1];
        if (K == 1)
            return min(nums1[i1], nums2[i2]);
        int j1 = min(n1, K/2), j2 = K/2;
        int num1 = nums1[i1+j1-1], num2 = nums2[i2+j2-1];
        if (num1 <= num2)
            return findKth(nums1, i1+j1, n1-j1, nums2, i2, n2, K-j1);
        else if (num1 > num2)
            return findKth(nums1, i1, n1, nums2, i2+j2, n2-j2, K-j2);
        
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int M = N1 + N2;
        double median = findKth(nums1, 0, N1, nums2, 0, N2, M/2+1);
        if (M % 2 == 0)
            median = (median + findKth(nums1, 0, N1, nums2, 0, N2, M/2)) * 1.0 / 2;
        return median;
    }
};
