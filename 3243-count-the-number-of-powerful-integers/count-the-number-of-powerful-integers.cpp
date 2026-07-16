class Solution {
    long long dp[20][2];
    string lim;
    string suff;
    int max_lim;

    long long f(int ind, bool tight) {
        if (ind == lim.length()) return 1;
        if (dp[ind][tight] != -1) return dp[ind][tight];

        long long ways = 0;
        int s_start = lim.length() - suff.length();

        if (ind < s_start) {
            int lim_dig = tight ? (lim[ind] - '0') : 9;
            lim_dig = min(lim_dig, max_lim);
            
            for (int d = 0; d <= lim_dig; d++) {
                ways += f(ind + 1, tight && (d == (lim[ind] - '0')));
            }
        } 
        else {
            int f_dig = suff[ind - s_start] - '0';
            int lim_dig = tight ? (lim[ind] - '0') : 9;
            
            if (f_dig <= lim_dig) {
                ways += f(ind + 1, tight && (f_dig == (lim[ind] - '0')));
            }
        }
        
        return dp[ind][tight] = ways;
    }

    long long calc(long long x) {
        lim = to_string(x);
        
        if (lim.length() < suff.length()) return 0;
        
        for (int i = 0; i < 20; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        
        return f(0, true);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        suff = s;
        max_lim = limit;
        return calc(finish) - calc(start - 1);
    }
};