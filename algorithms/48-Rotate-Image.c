/*
 *     goal: (i, j) -> (j, n - 1 - i)  in place
 *
 *     by swap:      symmetric           left-right
 *           (i, j) -----------> (j, i) ------------> (j, n - 1 - i)
 */
void swap(int **matrix, int i, int j, int m, int n){
    int tmp = matrix[i][j];
    matrix[i][j] = matrix[m][n];
    matrix[m][n] = tmp;
}
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    for (int r = 0; r < matrixRowSize; r++)
        for (int c = 0; c < r; c++)
            swap(matrix, r, c, c, r);
    for (int r = 0; r < matrixRowSize; r++)
        for (int c = 0; c < matrixColSizes[r] - 1 - c; c++)
            swap(matrix, r, c, r, matrixColSizes[r] - 1 - c);
}

/* pure inplace rotate: 
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int tmp, r, c, nr, nc;
    int n = matrixRowSize;
    for (int ul = 0; ul < n - 1 - ul; ul++) {
        for (int i = 0; ul + i < n - 1 - ul; i++) {
            c = ul + i;
            r = ul;
            tmp = matrix[r][c];
            for (int k = 0; k < 3; k++) {
                nr = n - 1 - c;
                nc = r;
                matrix[r][c] = matrix[nr][nc];
                r = nr;
                c = nc;
            }
            matrix[r][c] = tmp;
        }
    }
}
*/
