class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        long long current_ans = 0;
        
        // CHANGED: Start from bit 30 instead of 29 to handle values up to 2*10^9
        for (int bit = 30; bit >= 0; --bit) {
            long long target = current_ans | (1LL << bit);
            vector<long long> costs;
            costs.reserve(n);
            
            for (int val : nums) {
                long long x = val;
                
                if ((x & target) == target) {
                    costs.push_back(0);
                    continue;
                }
                
                long long missing_bits = target & ~x;
                int msb_pos = 0;
                // CHANGED: Inner loop must also scan up to 30
                for (int i = 30; i >= 0; --i) {
                    if ((missing_bits >> i) & 1) {
                        msb_pos = i;
                        break;
                    }
                }
                
                long long mask_lower = (1LL << (msb_pos + 1)) - 1;
                long long next_val = (x & ~mask_lower); 
                next_val = next_val | (1LL << msb_pos);
                
                long long target_lower = target & ((1LL << msb_pos) - 1);
                next_val |= target_lower;
                
                costs.push_back(next_val - x);
            }
            
            nth_element(costs.begin(), costs.begin() + m, costs.end());
            
            long long total_cost = 0;
            for (int i = 0; i < m; ++i) {
                total_cost += costs[i];
            }
            
            if (total_cost <= k) {
                current_ans = target;
            }
        }
        
        return (int)current_ans;
    }
};