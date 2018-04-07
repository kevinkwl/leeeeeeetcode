#define min(a, b) ((a < b) ? (a) : (b))
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0 || gridColSize == 0)   return 0;
    int path[gridColSize];
    memset(path, 0, sizeof(int) * gridColSize);
    path[0] = grid[0][0];
    for (int c = 1; c < gridColSize; c++) {
        path[c] = path[c-1] + grid[0][c];
    }
    for (int r = 1; r < gridRowSize; r++) {
        for (int c = 0; c < gridColSize; c++) {
            if (c > 0)
                path[c] = min(path[c], path[c-1]);
            path[c] += grid[r][c];
        }
    }
    return path[gridColSize-1];    
}
