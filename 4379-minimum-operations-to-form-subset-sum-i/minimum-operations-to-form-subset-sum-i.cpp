class Solution {
public:
    int dp[105][5005];
    int f(int i,int rem,vector<vector<pair<int,int>>>&options)
    {
        if(rem==0) return 0;
        if(rem<0 || i==options.size()) return 1e9;
        if(dp[i][rem]!=-1) return dp[i][rem];
        //not_pick...
        int ans=f(i+1,rem,options);
        for(auto x:options[i])
        {
            int val=x.first;
            int cost=x.second;
            if(rem>=val) 
                ans=min(ans,cost + f(i+1,rem-val,options));
        }
        return dp[i][rem]=ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<pair<int,int>>>options(n);
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int temp=x;
            int ops=0;
            while(temp>0)
            {
                options[i].push_back({temp,ops});
                ops++;
                temp/=2;
            }
            temp=2*x;ops=1;
            while(temp<=sum)
            {
                options[i].push_back({temp,ops});
                ops++;
                temp*=2;
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(0,sum,options);
        return ans>=1e9 ? -1 : ans;
    }
};