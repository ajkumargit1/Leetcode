class Solution {
public:
    int f(int i,int mask,vector<vector<int>>&cost,vector<int>&mini_cost2,vector<vector<int>>&dp)
    {
        int n=cost.size();
        int m=cost[0].size();

        if(i==n){
            int xtra=0;
            for(int j=0;j<m;j++)
            {
                if((mask & (1<<j)) == 0)
                {
                    xtra+=mini_cost2[j];
                }
            }
            return xtra;
        }
        if(dp[i][mask]!=-1) return dp[i][mask];

        int mini=INT_MAX;
        for(int j=0;j<m;j++)
        {
            int curr=cost[i][j] + f(i+1,mask|(1<<j),cost,mini_cost2,dp);
            mini=min(mini,curr);
        }
        return dp[i][mask]=mini;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size();
        int m=cost[0].size();
        vector<int>mini_cost2(m,INT_MAX);
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                mini_cost2[j] = min(mini_cost2[j], cost[i][j]);
            }
        }
        int num_mask=(1<<m);
        vector<vector<int>>dp(n,vector<int>(num_mask,-1));

        int ans=f(0,0,cost,mini_cost2,dp);
        return ans;
    }
};