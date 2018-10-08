class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int M = nums1.size(), N = nums2.size();
        int m = (M+N+1)/2;
        int lo = 0, hi = M, i, j;
        while (lo <= hi) {
            i = (lo+hi) / 2;
            j = m - i;
            int go = 0;
            if (i > 0 && j < N) {
                if (nums1[i-1] > nums2[j])
                    go = -1;
            }
            if (i < M && j > 0) {
                if (nums1[i] < nums2[j-1])
                    go = 1;
            }
            if (go == 0)
                break;
            else if (go == -1)
                hi = i-1;
            else
                lo = i+1;
        }
        int n1l, n1r, n2l, n2r;
        if (i == 0) {
            n1l = n2l = nums2[j-1];
        } else if (j == 0) {
            n1l = n2l = nums1[i-1];
        } else {
            n1l = nums1[i-1];
            n2l = nums2[j-1];
        }
        if (i == M) {
            n1r = n2r = nums2[j];
        } else if (j == N) {
            n1r = n2r = nums1[i];
        } else {
            n1r = nums1[i];
            n2r = nums2[j];
        }
        return ((M+N) % 2 == 0) ? (max(n1l, n2l) + min(n1r, n2r)) * 1.0 / 2 : max(n1l, n2l);
    }
};
