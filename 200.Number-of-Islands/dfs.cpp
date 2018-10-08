class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        if (r > 0 && grid[r-1][c] == '1')   dfs(grid, r-1, c);
        if (r < grid.size()-1 && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if (c > 0 && grid[r][c-1] == '1')   dfs(grid, r, c-1);
        if (c < grid[r].size() - 1 && grid[r][c+1] == '1') dfs(grid, r, c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] =='1') {
                    ++n;
                    dfs(grid, i, j);
                }
            }
        }
        return n;
    }
};
