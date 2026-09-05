class Solution {
public:
    int dp[51][1024];
    int group_sum[1024];

    bool f(int ind,int mask,int target_mask,vector<int>&counts)
    {
        if(mask==target_mask) return true;
        if(ind==counts.size()) return false;
        if(dp[ind][mask]!=-1) return dp[ind][mask];

        for(int group=0;group<=target_mask;group++)
        {
            if((mask & group) == 0)
            {
                if(group_sum[group]<=counts[ind])
                {
                    if(f(ind+1,mask | group,target_mask,counts))
                    return dp[ind][mask]=true;
                }
            }
        }
        return dp[ind][mask]=false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;
        for(int num:nums) mp[num]++;
        vector<int>counts;
        for(auto it:mp) counts.push_back(it.second);
        int m=quantity.size();
        int target_mask=((1<<m) - 1);
        for(int i=0;i<=target_mask;i++)
        {
            group_sum[i]=0;
            for(int j=0;j<m;j++)
            {
                if(i&(1<<j)) group_sum[i]+=quantity[j];
            }
        }
        memset(dp,-1,sizeof(dp));
        return f(0,0,target_mask,counts);
    }
};