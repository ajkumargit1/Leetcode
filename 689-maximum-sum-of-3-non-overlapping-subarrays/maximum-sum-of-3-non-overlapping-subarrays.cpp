class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>w(n-k+1);//this stores the sum of subarray of length k stating at index i
        int curr=0;
        for(int i=0;i<k;i++)
        {
            curr+=nums[i];
        }
        w[0]=curr;
        for(int i=1;i<n-k+1;i++)
        {
            w[i]=w[i-1]-nums[i-1]+nums[i+k-1];
        }
        vector<int>left(n-k+1,0);
        int maxi=0;
        int best_ind=-1;
        for(int i=0;i<left.size();i++)
        {
            if(w[i]>maxi)
            {
                maxi=max(maxi,w[i]);
                best_ind=i;
            }
            left[i]=best_ind;
        }
        vector<int>right(n-k+1,0);
        maxi=0;
        best_ind=-1;
        for(int i=right.size()-1;i>=0;i--)
        {
            if(w[i]>=maxi)
            {
                maxi=max(maxi,w[i]);
                best_ind=i;
            }
            right[i]=best_ind;
        }

        int l=-1,j=-1,r=-1;
        int max_sum=0;
        for(int i=k;i<w.size()-k;i++)
        {
            int a=left[i-k];
            int c=right[i+k];

            if(w[a]+w[i]+w[c]>max_sum)
            {
                max_sum=w[a]+w[i]+w[c];
                l=a;
                j=i;
                r=c;
            }
        }

        return {l,j,r};

    }
};