class Solution {
public:
    long long calc(vector<int>&nums,int i)
    {
        long long tar = max(nums[i - 1], nums[i + 1]) + 1LL;
        return max(0LL, tar - nums[i]);
    }   
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        if (n % 2 == 1) {
            for (int i = 1; i < n - 1; i += 2) {
                ans += calc(nums, i);
            }
        } 
        else {
            int k = (n - 2) / 2;
            long long cur_sm = 0;
            
            for (int i = 1; i <= k; ++i) {
                cur_sm += calc(nums, i * 2);
            }
            ans = cur_sm;
            
            for (int i = 1; i <= k; ++i) {
                cur_sm += calc(nums, i * 2 - 1) - calc(nums, i * 2); 
                ans = min(ans, cur_sm);
            }
        }
        
        return ans;
    }
};