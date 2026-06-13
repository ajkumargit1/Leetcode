class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n=nums.size();
        vector<int>pre(1e5+5,0);
        for(auto x:nums)
        {
            if(x<0 || x>1e5) continue;
            pre[x]=1;
        }
        int ans=0;
        for(int i=1;i<=pre.size();i++)
        {
            if(pre[i]!=1) {ans=i;break;}
        }
        return ans;
    }
};