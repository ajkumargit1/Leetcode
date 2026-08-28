class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int helper(int i, int j, vector<vector<int>>& grid, int cnt) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
            return 0;

        if (grid[i][j] == 2) {
            return  cnt == -1;
        }

        int org = grid[i][j];
        grid[i][j] = -1;

        int ans = 0;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            ans += helper(nr, nc, grid, cnt - 1);
        }

        grid[i][j] = org;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int row, col;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }

                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return helper(row, col, grid, cnt);
    }
};