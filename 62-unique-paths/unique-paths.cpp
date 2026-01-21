class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0,left=0;
        if(i>0)  up=f(i-1,j,dp);
        if(j>0)  left=f(i,j-1,dp);

        return dp[i][j]=up+left;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=f(m-1,n-1,dp);

        return ans;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0) dp[i][j]=1;
        //         else
        //         {
        //             int left=0;
        //             int up=0;
        //             if(i>0) up=dp[i-1][j];
        //             if(j>0) left=dp[i][j-1];
        //             dp[i][j]=up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        
    }
};