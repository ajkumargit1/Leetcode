class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+f(i-2,nums,dp);
        int not_take=f(i-1,nums,dp);

        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // dp[0]=nums[0];
        // if(n>=2)
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     int take=nums[i]+dp[i-2];
        //     int not_take=dp[i-1];
        //     dp[i]=max(take,not_take);
        // }
        // return dp[n-1];
        int ans=f(n-1,nums,dp);
        return ans;
    }
};