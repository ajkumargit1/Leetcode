class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 100005;

    long long fact[100005], invFact[100005];

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b = b >> 1;
        }
        return res;
    }

    void solve() {
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        solve();

        int left = pos;
        int right = n - pos - 1;

        long long ans = 0;

        for (int x = 0; x <= k; x++) {
            int y = k - x;

            if (x <= left && y <= right) {
                ans = (ans + nCr(left, x) * nCr(right, y) % MOD) % MOD;
            }
        }

        return (ans * 2) % MOD;
    }
};