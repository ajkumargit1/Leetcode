class Solution {
public:
    int f(int i, int j, int val, vector<vector<int>>& grid,               vector<vector<vector<int>>>& dp) {
        val ^= grid[i][j];
        
        if(i == 0 && j == 0) return val;
        
        if(dp[i][j][val] != -1) return dp[i][j][val];
        
        int up = 1e9, left = 1e9;
        
        if(i > 0)  up = f(i - 1, j, val, grid, dp);
        
        if(j > 0)  left = f(i, j - 1, val, grid, dp);

        return dp[i][j][val] = min(up, left);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>
        (n,vector<int>(1024, -1)));
        
        int ans = f(m - 1, n - 1, 0, grid, dp);

        return ans;
    }
};