class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        // 1 candy for everyone initially
        vector<int> cds(ratings.size(), 1);
        for (int i = 0; i < N; i++) {
            // might need to give more candies to i's neighbors if i's rating is lowest at at least one side
            bool needCheck = (i == 0 || i == N - 1 || 
                              (ratings[i-1] >= ratings[i] && ratings[i] <= ratings[i+1]
                                && !(ratings[i-1] == ratings[i] && ratings[i] == ratings[i+1])));
            if (needCheck) {
                for (int j = i - 1; j >= 0 && ratings[j] > ratings[j+1]; j--) {
                    if (cds[j] <= cds[j+1])
                        cds[j] = cds[j+1] + 1;
                }
                for (int j = i + 1; j < N && ratings[j] > ratings[j-1]; j++) {
                    if (cds[j] <= cds[j-1])
                        cds[j] = cds[j-1] + 1;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < N; i++)
            total += cds[i];
        return total;
    }
};
