class Solution {
public:
    void updateNb(vector<vector<int>>& b, int i, int j) {
        int M = b.size(), N = b[0].size();
        static int dirs[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        int ii, jj;
        for (int dir = 0; dir < 8; dir++) {
            ii = i + dirs[dir][0];
            jj = j + dirs[dir][1];
            if (ii == M) ii = -1;
            if (jj == N) jj = -1;
            if (ii < 0 || jj < 0)
                continue;
            // mark up neighbors while preserve history alive-dead status
            b[ii][jj] += (b[ii][jj] > 0 ? 1 : -1);
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size(), N = board[0].size();
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (board[i][j] > 0)
                        updateNb(board, i, j);
            }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (board[i][j] > 1 && board[i][j] < 3)
                    board[i][j] = 0;
                else if (board[i][j] == 3 || board[i][j] == 4)
                    board[i][j] = 1;
                else if (board[i][j] > 4)
                    board[i][j] = 0;
                else if (board[i][j] == -3)
                    board[i][j] = 1;
                else
                    board[i][j] = (board[i][j] > 1 ? 1 : 0);
            }
    }
};
