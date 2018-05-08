class Solution {
public:
    using Map = vector<vector<char>>;
    void explore(Map & m,int r, int c) {
        m[r][c] = 0;
        if (r > 0 && m[r-1][c] == '1')
            explore(m, r-1, c);
        if (c < m[0].size()-1 && m[r][c+1] == '1')
            explore(m, r, c+1);
        if (r < m.size()-1 && m[r+1][c] == '1')
            explore(m, r+1, c);
        if (c > 0 && m[r][c-1] == '1')
            explore(m, r, c-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1')
                {
                    ++cnt;
                    explore(grid, i, j);
                }
        return cnt;
    }
};
