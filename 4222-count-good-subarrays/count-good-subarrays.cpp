class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> R(n, n - 1);
        vector<int> L(n, 0);
        
        vector<int> next_bit(30, n); 
        for (int i = n - 1; i >= 0; --i) {
            int r_bound = n;
            for (int b = 0; b < 30; ++b) {
                if ((nums[i] & (1 << b)) == 0) {
                    r_bound = min(r_bound, next_bit[b]);
                }
            }
            R[i] = r_bound - 1;
            
            for (int b = 0; b < 30; ++b) {
                if ((nums[i] & (1 << b)) != 0) {
                    next_bit[b] = i;
                }
            }
        }
        
        vector<int> prev_bit(30, -1); 
        unordered_map<int, int> last_seen;
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int l_bound = -1;
            for (int b = 0; b < 30; ++b) {
                if ((nums[i] & (1 << b)) == 0) {
                    l_bound = max(l_bound, prev_bit[b]);
                }
            }
            if (last_seen.count(nums[i])) {
                l_bound = max(l_bound, last_seen[nums[i]]);
            }
            L[i] = l_bound + 1;
            
            ans += 1LL * (i - L[i] + 1) * (R[i] - i + 1);
            
            for (int b = 0; b < 30; ++b) {
                if ((nums[i] & (1 << b)) != 0) {
                    prev_bit[b] = i;
                }
            }
            last_seen[nums[i]] = i;
        }
        
        return ans;
    }
};