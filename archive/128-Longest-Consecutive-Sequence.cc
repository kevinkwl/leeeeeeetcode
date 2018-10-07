// union find
class Solution {
public:
    unordered_map<int, int> ds;
    unordered_map<int, int> rank;
    int longestConsecutive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (ds.count(n) == 0) {
                ds[n] = n;
                rank[n] = 1;
            }
            if (ds.count(n-1) > 0)
                unionByRank(n-1, n);
            if (ds.count(n+1) > 0)
                unionByRank(n+1, n);
        }
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int length = rank[ds[nums[i]]];
            longest = max(length, longest);
        }
        return longest;
    }
    
    void unionByRank(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2)
            return;
        int rk1 = rank[p1], rk2 = rank[p2];
        if (rk1 > rk2) {
            ds[p2] = p1;
            rank[p1] += rk2;
        } else {
            ds[p1] = p2;
            rank[p2] += rk1;
        }
    }
    
    int find(int n) {
        return ds[n] == n ? n : (ds[n] = find(ds[n]));
    }
};


// faster
class Solution {
public:
    unordered_map<int, int> seq_length;
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        for (int n : nums) {
            if (seq_length.count(n) > 0)
                continue;
            // longest sequence of n-1 ends at n-1
            int left = seq_length.count(n-1) > 0 ? seq_length[n-1] : 0;
            // longest sequence of n+1 starts at n+1
            int right = seq_length.count(n+1) > 0 ? seq_length[n+1] : 0;
            seq_length[n] = left + right + 1;
            if (seq_length[n] > longest)
                longest = seq_length[n];
            seq_length[n-left] = seq_length[n];
            seq_length[n+right] = seq_length[n];
        }
        return longest;
    }
};
