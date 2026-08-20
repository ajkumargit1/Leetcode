class Solution {
public:
    const int inf=1e8;
    int f(int i,int j,int prev_col,vector<int>&houses,vector<vector<int>>&cost,vector<vector<vector<int>>>&dp,int m,int n,int target)
    {
        if(j>target) return inf;
        if(i==m){
            if(target==j) return 0;
            else return inf;
        }
        if(dp[i][j][prev_col]!=-1) return dp[i][j][prev_col];

        int ans=inf;
        if(houses[i]!=0)
        {
            ans=f(i+1,j+((prev_col==houses[i])?0:1),houses[i],houses,cost,dp,m,n,target);
        }
        else
        {
            for(int col=1;col<=n;col++)
            {
                int curr_cost=cost[i][col-1]+f(i+1,j+( (prev_col==col) ? 0 : 1),col,houses,cost,dp,m,n,target);
                ans=min(ans,curr_cost);
            }
        }

        return dp[i][j][prev_col]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        //dp[i][j][prev_col]-->>shows the minimum cost to paint the all houses from i to m-1 when last house was painted with color preev_col and we have already formed j neighbourhoods...//
        int ans=f(0,0,0,houses,cost,dp,m,n,target);

        return (ans==inf)?-1:ans;
    }
};