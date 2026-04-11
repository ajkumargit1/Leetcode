class Solution {
public:
    static const int MOD = 1e9+7;
    
    static bool cmp(const pair<int,int>& A, const pair<int,int>& B) {
        if (A.second == 0 || B.second == 0) {
            return A.second < B.second;
        }
        if (A.first != B.first) {
            return A.first > B.first;
        }
        return A.second < B.second;
    }
    
    long long power(long long base, int exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int,int>> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back({nums1[i], nums0[i]});
        }
        sort(temp.begin(), temp.end(), cmp);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int ones = temp[i].first;
            int zeros = temp[i].second;

            if(ones > 0) {
                long long p = power(2, ones);
                ans = (ans * p % MOD + (p - 1 + MOD) % MOD) % MOD; 
            }
            if (zeros > 0) {
                long long p = power(2, zeros);
                ans = (ans * p) % MOD;
            }
        }

        return ans;
    }
};