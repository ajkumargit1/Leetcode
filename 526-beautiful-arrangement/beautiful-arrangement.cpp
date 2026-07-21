class Solution {
public:
    int f(int mask,int n,vector<int>&dp)
    {
        if(mask+1==(1<<n)) return 1;
        if(dp[mask]!=-1) return dp[mask];

        int curr_pos=__builtin_popcount(mask)+1;
        int ways=0;
        for(int i=1;i<=n;i++)
        {
            int bit=i-1;
            if((mask & (1<<bit))==0)
            {
                if(i%curr_pos ==0 || curr_pos%i==0)
                ways+=f(mask | (1<<bit),n,dp);
            }
        }
        return dp[mask]=ways;
    }

    int countArrangement(int n) {
        vector<int>dp(1<<n,-1);
        int ans=f(0,n,dp);
        return ans;
    }
};