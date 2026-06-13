class Solution {
public:
    int f(int row,int col1,int col2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        if(col1<0 || col1>=m || col2<0 || col2>=m) return -1e9;
        if(row==n) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];

        int cur=0;
        if(col1!=col2) cur=grid[row][col1]+grid[row][col2];
        else cur=grid[row][col1];

        int next_max=0;
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                next_max=max(next_max,f(row+1,col1+x,col2+y,n,m,grid,dp));
            }
        }
        return dp[row][col1][col2]=cur+next_max;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        int ans=f(0,0,m-1,n,m,grid,dp);
        return ans;
    }
};