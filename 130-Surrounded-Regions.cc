class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (i == 0 || i == board.size()-1 || j == 0 || j == board[i].size()-1)
                    if (board[i][j] == 'O')
                        dfs(board, i, j);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
    }
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        int R = board.size(), C = board[r].size();
        if (board[r][c] == 'O') {
            board[r][c] = 'P';
            if (r > 1)
                dfs(board, r-1, c);
            if (r < R-2)
                dfs(board, r+1, c);
            if (c > 1)
                dfs(board, r, c-1);
            if (c < C-2)
                dfs(board, r, c+1);
        }
    }
};
