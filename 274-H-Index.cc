// O(NlogN)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        if (N == 0) return 0;
        sort(citations.begin(), citations.end());
        for (int i = N; i >= 0; i--) {
            if (citations[N-i] >= i && (N-i == 0 || citations[N-i-1] <= i))
                return i;
        }
        return 0;
    }
};


// O(N)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int buckets[N+1] = {0};
        for (int c : citations) {
            if (c >= N)
                buckets[N]++;
            else
                buckets[c]++;
        }
        int cnt = 0;
        for (int i = N; i >= 0; i--) {
            cnt += buckets[i];
            if (cnt >= i)
                return i;
        }
        return cnt;
    }
};
