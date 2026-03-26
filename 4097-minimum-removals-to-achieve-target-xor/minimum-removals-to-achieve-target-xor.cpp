class Solution {
public:
    int f(int i, int curr_xor, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            if(curr_xor == target) return 0; 
            return -1e5;
        }
        if(dp[i][curr_xor] != -1) return dp[i][curr_xor];
        int take = -1e5, notTake = -1e5;

        notTake = f(i + 1, curr_xor, target, nums, dp);
        take = 1 + f(i + 1, curr_xor ^ nums[i], target, nums, dp);

        return dp[i][curr_xor] = max(take, notTake);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int val=1<<14; //because max possible value of xor is (2^14 -1)    ,means when all bits are set...that's why...

        vector<vector<int>> dp(n, vector<int>(val, -1)); 
        int ans = f(0, 0, target, nums, dp);
        if(ans < 0) return -1;
        return n - ans;
    }
};