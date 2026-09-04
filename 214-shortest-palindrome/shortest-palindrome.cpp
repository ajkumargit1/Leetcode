class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        long long fh1 = 0, bh1 = 0, pwr1 = 1;
        long long mod1 = 1e9 + 7;
        int base1 = 29;
        
        long long fh2 = 0, bh2 = 0, pwr2 = 1;
        long long mod2 = 1e9 + 9; 
        int base2 = 31;
        
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            
            fh1 = (fh1 * base1 + val) % mod1;
            bh1 = (bh1 + val * pwr1) % mod1;
            pwr1 = (pwr1 * base1) % mod1;
            
            fh2 = (fh2 * base2 + val) % mod2;
            bh2 = (bh2 + val * pwr2) % mod2;
            pwr2 = (pwr2 * base2) % mod2;
            
            if (fh1 == bh1 && fh2 == bh2) {
                max_len = i + 1;
            }
        }
        
        string rem = s.substr(max_len);
        reverse(rem.begin(), rem.end());
        return rem + s;
    }
};