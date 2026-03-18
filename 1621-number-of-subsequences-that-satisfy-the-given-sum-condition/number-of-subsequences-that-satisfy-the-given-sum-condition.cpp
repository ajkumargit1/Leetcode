#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> p(n);
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            p[i] = (p[i - 1] * 2) % MOD;
        }
        
        int l = 0, r = n - 1;
        int ans = 0;
        
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + p[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        
        return ans;
    }
};