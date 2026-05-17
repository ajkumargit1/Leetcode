class Solution {
    long long safe_pow(long long x, int k, long long limit) {
        if (x == 0) return 0;
        long long res = 1;
        for (int i = 0; i < k; ++i) {
            if (res > limit / x) {
                return limit + 1; //signifying a massive val 
            }
            res *= x;
        }
        return res;
    }

    long long get_floor(long long r, int k) {
        long long low = 0, high = r, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = safe_pow(mid, k, r);
            if (val <= r) {
                ans = mid;       
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }
        return ans;
    }

    long long get_ceil(long long l, int k) {
        long long low = 0, high = l, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = safe_pow(mid, k, l);
            if (val >= l) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }

public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) return r - l + 1;
        
        long long right = get_floor(r, k);
        long long left = get_ceil(l, k);
        
        long long ans = right - left + 1;
        return ans > 0 ? ans : 0;
    }
};