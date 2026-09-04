class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        long long fh = 0;
        long long bh = 0;
        long long pwr = 1;
        long long mod = 1e9 + 7;
        
        int base = 29;
        int max_len = 0;
        
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            
            fh = (fh * base + val) % mod;
            bh = (bh + val * pwr) % mod;
            pwr = (pwr * base) % mod;
            
            if (fh == bh) {
                max_len = i + 1;
            }
        }
        
        string rem = s.substr(max_len);
        reverse(rem.begin(), rem.end());
        return rem + s;
    }
};