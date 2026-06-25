class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l_mx(n);
        vector<int>r_mx(n);
        int cur_lmx=height[0];
        for(int i=1;i<n;i++)
        {
            l_mx[i]=cur_lmx;
            cur_lmx=max(cur_lmx,height[i]);
        }
        int cur_rmx=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r_mx[i]=cur_rmx;
            cur_rmx=max(cur_rmx,height[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=max(min(l_mx[i],r_mx[i])-height[i],0);
        }

        return ans;
    }
};