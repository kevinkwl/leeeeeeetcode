int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int ways[101] = {1, 0};
    for (int r = 0; r < obstacleGridRowSize; r++) {
        for (int c = 0; c < obstacleGridColSize; c++) {
            if (c > 0)
                ways[c] += ways[c-1];
            if (obstacleGrid[r][c] == 1)
                ways[c] = 0;
        }
    }
    return ways[obstacleGridColSize-1];
}
