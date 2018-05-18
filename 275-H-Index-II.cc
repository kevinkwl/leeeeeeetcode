// binary search on H-index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int lo = 0, hi = N;
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid == 0 || citations[N-mid] >= mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo - 1;
    }
};

// binary search on len - H-index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int lo = 0, hi = N - 1;
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (citations[mid] >= N-mid)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return N - lo;
    }
};
