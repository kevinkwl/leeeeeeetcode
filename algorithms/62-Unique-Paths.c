int uniquePaths(int m, int n) {
    int ways[101] = {1, 0};
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (c > 0)
                ways[c] += ways[c-1];
        }
    }
    return ways[n-1];
}
