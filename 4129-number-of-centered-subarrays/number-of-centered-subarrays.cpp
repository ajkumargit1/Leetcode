class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();int ans=0;
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            set<long long>hai;
            for(long long j=i;j<n;j++)
            {
                sum+=nums[j];
                hai.insert(nums[j]);
                if(hai.count(sum)) ans++;
            }

        }
        return ans;
    }
};