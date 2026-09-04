class Solution {
public:
    int check(vector<int>&temp,int mid,int n)
    {
        int r=0;int pairs=0;
        for(int l=0;l<n;l++)
        {
            while(r<temp.size() && temp[r]-temp[l]<=mid)
            r++;
            pairs+=(r-l-1);
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        int lo=0,hi=temp[n-1]-temp[0];int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(temp,mid,n)<k)
            {
                lo=mid+1;
            }
            else 
            {
                ans=mid;
                hi=mid-1;
            }
        }

        return ans;
    }
};