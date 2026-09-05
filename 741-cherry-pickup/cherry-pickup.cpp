class Solution {
public:
    static const int inf=1e9+7;
    int f(int r1,int c1,int r2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        int c2=r1+c1-r2;
        int n=grid.size();
        if(r1>=n || c1>=n ||r2>=n ||c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -inf;
        if(r1==n-1 && c1==n-1) return grid[n-1][n-1];
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];

        int cherries = 0;
        if (r1 == r2) {
            cherries = grid[r1][c1]; 
        } else {
            cherries = grid[r1][c1] + grid[r2][c2]; 
        }
        
        int right_right = f(r1, c1 + 1, r2, grid,dp);
        int down_right  = f(r1 + 1, c1, r2, grid,dp);
        int right_down  = f(r1, c1 + 1, r2 + 1, grid,dp);
        int down_down   = f(r1 + 1, c1, r2 + 1, grid,dp);

        return dp[r1][c1][r2]=cherries+max({right_right,down_right , right_down,down_down}) ;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        
        int res = f(0,0,0,grid,dp);

        return max(0 , res) ;
    }
};