void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    bool col0Has0 = false;
    for (int r = 0; r < matrixRowSize; r++) {
        if (matrix[r][0] == 0)  col0Has0 = true;
        for (int c = 1; c < matrixColSize; c++)
            if (matrix[r][c] == 0)
                matrix[r][0] = matrix[0][c] = 0;
    }
    for (int r = matrixRowSize-1; r >= 0; r--) {
        for (int c = 1; c < matrixColSize; c++)
            if (matrix[r][0] == 0 || matrix[0][c] == 0)
                matrix[r][c] = 0;
        if (col0Has0)
            matrix[r][0] = 0;
    }
}

/*  Note:
 *  use the 0th row and col to store information about that col and row !!
 */
