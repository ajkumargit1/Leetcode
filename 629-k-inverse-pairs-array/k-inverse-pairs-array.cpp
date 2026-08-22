class Solution {
public:
    static const int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        //dp[i][j] represents the number of ways of making an array of length i having j number of inverse pairs in it...
        for(int j=0;j<=k;j++)
            dp[0][j]=0;
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int val=(dp[i][j-1]+dp[i-1][j])%mod;

                if(j>=i)
                val=(val-dp[i-1][j-i]+mod)%mod;
                dp[i][j]=val;
            }
        }

        return dp[n][k];
    }
};