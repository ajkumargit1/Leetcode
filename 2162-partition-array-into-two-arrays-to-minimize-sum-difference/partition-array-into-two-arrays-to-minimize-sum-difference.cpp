class Solution {
public:  
    //quite engaging problem...
    int minimumDifference(vector<int>& nums) {
       int n=nums.size()/2;
       int total_sum=accumulate(nums.begin(),nums.end(),0);
       vector<int>left(nums.begin(),nums.begin()+n);
       vector<int>right(nums.begin()+n,nums.end());
       
       vector<vector<int>>left_sum(n+1);
       vector<vector<int>>right_sum(n+1);

       for(int mask=0;mask<(1<<n);mask++)
       {
            int sz=0,sm=0;
            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                {
                    sz++;
                    sm+=left[i];
                }
            }
                left_sum[sz].push_back(sm);
        }

        for(int mask=0;mask<(1<<n);mask++)
        {
            int sz=0,sm=0;
            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                {
                    sz++;
                    sm+=right[i];
                }
            }
                right_sum[sz].push_back(sm);
        }

        for(int i=0;i<=n;i++)
        {
            sort(right_sum[i].begin(),right_sum[i].end());
        }

        int ans=2e9;
        for(int k=0;k<=n;k++)
        {
            for(auto x:left_sum[k])
            {
                int right_sz=n-k;
                int req=total_sum/2 - x;
                auto it=lower_bound(right_sum[right_sz].begin(),right_sum[right_sz].end(),req);

                if(it!=right_sum[right_sz].end())
                {
                    int y=(*it);
                    ans=min(ans,abs(total_sum-2*(x+y)));
                }
                if(it!=right_sum[right_sz].begin())
                {
                    int y=*(--it);
                    ans=min(ans,abs(total_sum-2*(x+y)));
                }
            }
        }

        return ans;
    }
};