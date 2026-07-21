#define ll long long
class Solution {
public:
    int f(int mask,int n,vector<int>&nums1,vector<int>&nums2,vector<int>&dp)
    {
        if(mask==(1<<n)-1) 
        return 0;
        if(dp[mask]!=-1) return dp[mask];
        int min_xorsm=INT_MAX;
        int i=__builtin_popcount(mask);
        for(int j=0;j<n;j++)
        {
            if((mask & (1<<j)) == 0)
            {
                int curr=nums1[i]^nums2[j];
                int new_mask=mask | (1<<j);
                min_xorsm=min(min_xorsm,curr+f(new_mask,n,nums1,nums2,dp));
            }
        }

        return dp[mask]=min_xorsm;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>dp(1<<n,-1);
        /*dp(mask) the minimum XOR sum to match the remaining elements of nums1, given that the elements of nums2 represented by the 1s in mask are already taken.*/

        int ans=f(0,n,nums1,nums2,dp);
        return ans;
    }
};