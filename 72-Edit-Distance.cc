class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 == 0)  return len2;
        if (len2 == 0)  return len1;
        vector<vector<int>> dist(len2 + 1, vector<int>(len1 + 1));
        dist[0][0] = 0;
        for (int i = 1; i <= len2; i++)
            dist[i][0] = i;
        for (int i = 1; i <= len1; i++)
            dist[0][i] = i;
        for (int i = 1; i <= len2; i++)
            for (int j = 1; j <= len1; j++) {
                if (word2[i-1] == word1[j-1])
                    dist[i][j] = dist[i-1][j-1];
                else
                    dist[i][j] = 1 + min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]));
            }
        return dist[len2][len1];
    }
};
