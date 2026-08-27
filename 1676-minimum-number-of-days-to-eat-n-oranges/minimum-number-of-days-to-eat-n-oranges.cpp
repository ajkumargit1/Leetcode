class Solution {
    unordered_map<int, int> dp;
public:
    int f(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        
        int div2 = (n % 2) + 1 + f(n / 2);
        int div3 = (n % 3) + 1 + f(n / 3);
        
        return dp[n] = min(div2, div3);
    }
    
    int minDays(int n) {
        return f(n);
    }
};