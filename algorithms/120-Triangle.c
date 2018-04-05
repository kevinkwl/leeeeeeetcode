#define min(x, y) ((x) > (y) ? (y) : (x))
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int R = triangleRowSize;
    int minval[R];
    memcpy(minval, triangle[R-1], sizeof(int) * R);
    for (int r = R - 2; r >= 0; r--)
        for (int c = 0; c <= r; c++)
            minval[c] = triangle[r][c] + min(minval[c], minval[c+1]);
    return minval[0];
}

/* zig-zag bottom-up
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int R = triangleRowSize;
    int curAtRow[R], cands[R], tmp;
    curAtRow[R-1] = INT_MAX;
    for (int k = R - 1; k >= 0; k--) {
        cands[R-1] = triangle[R-1][k];
        for (int r = R - 2; r >= k; r--) {
            tmp = curAtRow[r];
            curAtRow[r] = triangle[r][k] + min(cands[r+1], curAtRow[r+1]);
            if (r > k) {
                cands[r] = tmp;     // if there are still rows above need to be update, save the prev val
            }
        }
        curAtRow[R-1] = cands[R-1];
    }
    return curAtRow[0];
}
*/
