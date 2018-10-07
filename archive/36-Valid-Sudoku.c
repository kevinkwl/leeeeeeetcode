bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    bool rowNums[9][9] = {false};
    bool colNums[9][9] = {false};
    bool gridNums[3][3][9] = {false};
    for (int i = 0; i < boardRowSize; i++)
        for (int j = 0; j < boardColSize; j++) {
            int n = board[i][j] - '1';
            if (board[i][j] != '.')
                if (rowNums[i][n]++ || colNums[j][n]++ || gridNums[i/3][j/3][n]++)
                    return false;
        }
    return true;
}
