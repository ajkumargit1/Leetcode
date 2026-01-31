class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        long long count=0;
        int mod=1e9+7;

        for(int i=0;i<n-2;i++)
        {
            /*
            // Condition 1: Sum(Mid) >= Sum(Left)
            // pre[j] - pre[i] >= pre[i]
            // pre[j] >= 2 * pre[i]
            // Find the smallest index j (where j > i)

            // Condition 2: Sum(Mid) <= Sum(Right)
            // pre[j] - pre[i] <= pre[n-1] - pre[j]
            // 2 * prefix[j] <= prefix[n-1] + prefix[i]
            // pre[j] <= (pre[n-1] + pre[i]) / 2
            // Find the largest index j (where j < n - 1)
            // upper_bound finds the first element > value, so we subtract 1 later to get <= value
            */
            auto left=lower_bound(pre.begin()+i+1,pre.begin()+n-1,2*pre[i])-pre.begin();

            int target=(pre[n-1]+pre[i])/2;
            auto right=upper_bound(pre.begin()+i+1,pre.begin()+n-1,target) -pre.begin();



            if(right > left) 
            {
                count=(count + right - left) % mod;
            }
        }

        return count;
    }
};