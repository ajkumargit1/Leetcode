class Solution {
public:
    const int mod = 1e9 + 7;
    int interleaveCharacters(string word1, string word2, string target) {
        
        int n = word1.size();
        int m = word2.size();
        int p = target.size();
        
        string valmorinth = target; 

        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(p + 1, 0)));
        // dp shows number of ways to make target string upto ind k when we are allowed to pick characters from word1 upto ind i and from word2 upto j
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j][0] = 1;
            }
        }

        for(int k = 1; k <= p; k++) {
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= m; j++) {
                    long long d = 0, e = 0, c = 0;
                    
                    if(i > 0) d = dp[i-1][j][k];
                    if(j > 0) e = dp[i][j-1][k];
                    if(i > 0 && j > 0) c = dp[i-1][j-1][k];
                    
                    long long ways = (d + e - c) % mod;

                    if(i > 0 && word1[i-1] == target[k-1]) {
                        long long a = dp[i-1][j][k-1];
                        long long a_sub = (j > 0) ? dp[i-1][j-1][k-1] : 0;
                        ways = (ways + a - a_sub) % mod;
                    }
                    if(j > 0 && word2[j-1] == target[k-1]) {
                        long long b = dp[i][j-1][k-1];
                        long long b_sub = (i > 0) ? dp[i-1][j-1][k-1] : 0;
                        ways = (ways + b - b_sub) % mod;
                    }
                    
                    dp[i][j][k] = (ways % mod + mod) % mod;
                }
            }
        }

        return ((dp[n][m][p] - dp[n][0][p] - dp[0][m][p]) % mod + mod) % mod;
    }
};