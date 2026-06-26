class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(auto x:nums) st.insert(x);
        vector<int>temp(st.begin(),st.end());
        int m=temp.size();
        int right=0;
        int ans=n-1;
        for(int left=0;left<m;left++)
        {
            int tar_mx=temp[left]+n-1;
            while(right<m && temp[right]<=tar_mx) right++;
            int kept=right-left;

            ans=min(ans,n-kept);
        }

        return ans;
    }
};