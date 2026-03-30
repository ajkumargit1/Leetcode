#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool checkSortable(int k, int n, const vector<int>& nums, const vector<int>& S) {
        for (int i = 0; i < n; i += k) {
            int drops = 0;
            int dropIndex = -1;
            
            for (int j = 0; j < k - 1; j++) {
                if (nums[i + j] > nums[i + j + 1]) {
                    drops++;
                    dropIndex = j;
                }
            }
            
            if (drops > 1) return false;
            
            if (drops == 0) {
                for (int j = 0; j < k; j++) {
                    if (nums[i + j] != S[i + j]) return false;
                }
            } 
            else if (drops == 1) {
                if (nums[i + k - 1] > nums[i]) return false;
                
                int s_idx = 0; 
                
                for (int j = dropIndex + 1; j < k; j++) {
                    if (nums[i + j] != S[i + s_idx]) return false;
                    s_idx++;
                }
                
                for (int j = 0; j <= dropIndex; j++) {
                    if (nums[i + j] != S[i + s_idx]) return false;
                    s_idx++;
                }
            }
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> S = nums;
        sort(S.begin(), S.end());
        
        int ans = 0;
        
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                if (checkSortable(d, n, nums, S)) {
                    ans += d;
                }
                
                int pairedDivisor = n / d;
                if (pairedDivisor != d) {
                    if (checkSortable(pairedDivisor, n, nums, S)) {
                        ans += pairedDivisor;
                    }
                }
            }
        }
        
        return ans;
    }
};