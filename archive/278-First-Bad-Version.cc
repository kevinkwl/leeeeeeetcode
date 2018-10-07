// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int bl = 1, bh = n;
        while (bl < bh) {
            int mid = bl + (bh - bl) / 2;
            if (isBadVersion(mid))
                bh = mid;
            else
                bl = mid + 1;
        }
        return bl;
    }
};
