class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;int r=0;
        int curr=0;
        int ans=INT_MAX;
        for(r=0;r<n;r++)
        {
            curr+=nums[r];
            while(l<=r && curr>=target){
                ans=min(ans,r-l+1);
                curr-=nums[l];
                l++;
            }

        }
         return ans==INT_MAX?0:ans;
    }
};