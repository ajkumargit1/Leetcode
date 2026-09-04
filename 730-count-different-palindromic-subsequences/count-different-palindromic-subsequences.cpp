class Solution {
public:
    long long mod = 1e9 + 7;

    int f(int x, int i, int j, const string& s,
          vector<vector<vector<int>>>& dp) {
        if (i > j)
            return 0;
        char ch = 'a' + x;
        if (i == j)
            return s[i] == ch ? 1 : 0;
        if (dp[x][i][j] != -1)
            return dp[x][i][j];

        long long ans = 0;

        if (s[i] != ch) {
            ans = f(x, i + 1, j, s, dp);
        } else if (s[j] != ch) {
            ans = f(x, i, j - 1, s, dp);
        } else {
            ans = 2;
            for (int y = 0; y < 4; y++) {
                ans = (ans + f(y, i + 1, j - 1, s, dp)) % mod;
            }
        }

        return dp[x][i][j] = ans;
    }

public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(
            4, vector<vector<int>>(n, vector<int>(n, -1)));
        long long res = 0;

        for (int x = 0; x < 4; x++) {
            res = (res + f(x, 0, n - 1, s, dp)) % mod;
        }

        return res;
    }
};