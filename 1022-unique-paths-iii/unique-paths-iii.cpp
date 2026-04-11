class Solution {
    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& grid, int r, int c, int cells_left) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) {
            return 0;
        }

        if (grid[r][c] == 2) {
            return cells_left == 0 ? 1 : 0;
        }

        int original_val = grid[r][c];
        grid[r][c] = -1;

        int paths = 0;

        for (int i = 0; i < 4; i++) {
            paths += dfs(grid, r + dr[i], c + dc[i], cells_left - 1);
        }

        grid[r][c] = original_val;

        return paths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int start_r = -1, start_c = -1;
        int empty_c = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    empty_c++;
                } else if (grid[i][j] == 1) {
                    start_r = i;
                    start_c = j;
                }
            }
        }

        return dfs(grid, start_r, start_c, empty_c);
    }
};