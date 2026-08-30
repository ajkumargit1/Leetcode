class Solution {
public:
    int dp[505][505];
    int f(int i,int j,vector<int>&stoneValue,vector<int>&pre)
    {
        if(i==j) return 0;
        if(i+1==j) return min(stoneValue[i],stoneValue[j]);
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MIN;
        for(int k=i;k<j;k++)
        {
            int left_sum=pre[k] - (i > 0 ? pre[i-1] : 0);
            int right_sum= (pre[j]-pre[k]);
            if(left_sum<right_sum)
            {
                ans=max(ans,left_sum+f(i,k,stoneValue,pre));
            }
            else if(left_sum==right_sum)
            {
                ans=max(left_sum+f(i,k,stoneValue,pre),right_sum+f(k+1,j,stoneValue,pre));
            }
            else
            {
                ans=max(ans,right_sum+f(k+1,j,stoneValue,pre));
            }
        }

        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>pre(n);
        pre[0]=stoneValue[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+stoneValue[i];
        memset(dp,-1,sizeof(dp));
        //dp[i][j] shows the maximum score that we can make choosing the segment from i to j
        int ans=f(0,n-1,stoneValue,pre);
        return ans;
    }
};