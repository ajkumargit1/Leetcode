#define ll long long
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        long long inf=1e17;
        vector<long long>l_add(n,-inf);
        vector<long long>l_sub(n,-inf);
        vector<long long>r_add(n,-inf);
        vector<long long>r_sub(n,-inf);

        long long max_ans=-inf;
        l_add[0]=nums[0];
        max_ans=max(max_ans,l_add[0]);
        for(int i=1;i<n;i++)
        {
            l_add[i]=max(l_sub[i-1]+nums[i],(long long)nums[i]);
            l_sub[i]=l_add[i-1]-(long long)nums[i];
            max_ans=max(max_ans,max(l_sub[i],l_add[i]));
        }

        r_add[n-1]=nums[n-1];
        r_sub[n-1]=-nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r_add[i]=nums[i]+max(0LL,r_sub[i+1]);
            r_sub[i]=-nums[i]+max(0LL,r_add[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            long long A=l_add[i-1]+r_sub[i+1];
            long long B=l_sub[i-1]+r_add[i+1];
            max_ans=max({A,B,max_ans});
        }

        return max_ans;
    }
};