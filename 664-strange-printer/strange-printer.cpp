class Solution {
public:
    vector<vector<int>> dp;

    int solve(const string& s, int l, int r) {
        if (l > r) return 0;
        if (l == r) return 1;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 1e9;

        if (s[l] == s[r]) {
            ans = solve(s, l, r - 1);
        } 
        else {
            for (int k = l; k < r; k++) {
                ans = min(ans, solve(s, l, k) + solve(s, k + 1, r));
            }
        }

        return dp[l][r] = ans;
    }
    int strangePrinter(string s) {
        string str = "";
        for (char c : s) {
            if (str.empty() || str.back() != c) {
                str += c;
            }
        }

        int n = str.length();
        dp.assign(n, vector<int>(n, -1));
        
        return solve(str, 0, n - 1);
    }
};