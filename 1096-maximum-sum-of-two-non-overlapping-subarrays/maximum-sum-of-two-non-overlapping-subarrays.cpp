class Solution {
public:

    int solve(vector<int>&pre,int firstLen,int secondLen){
        int max_lsum=0;
        int n=pre.size();
        int ans=0;
        for(int i=firstLen+secondLen;i<n;i++)
        {
            int cur_lsum=pre[i-secondLen]-pre[i-secondLen-firstLen];
            max_lsum=max(max_lsum,cur_lsum);
            int cur_rsum=pre[i]-pre[i-secondLen];

            ans=max(ans,cur_rsum+max_lsum);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++)
        pre[i+1]=pre[i]+nums[i];
        return max(solve(pre,firstLen,secondLen),
        solve(pre,secondLen,firstLen));
    } 
};