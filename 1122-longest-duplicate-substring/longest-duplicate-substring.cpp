class Solution {
    typedef long long ll;
public:
    const static int primes = 2;
    vector<ll> mod = {1000000009, 1000000007};
    const ll base = 31;
    vector<ll> p_pow[primes];
    vector<ll> inv_pow[primes];

    ll bin_exp(ll b, ll e, ll m) {
        ll res = 1;
        b = b % m;
        while (e > 0) {
            if (e % 2 == 1) res = (res * b) % m;
            b = (b * b) % m;
            e /= 2;
        }
        return res;
    }
    
    ll mod_inv(ll n, ll m) { 
        return bin_exp(n, m - 2, m); 
    }

    void precompute(int n) {
        for (int i = 0; i < primes; i++) {
            p_pow[i].assign(n + 1, 0);
            inv_pow[i].assign(n + 1, 0);
            
            p_pow[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                p_pow[i][j] = (base * p_pow[i][j - 1]) % mod[i];
            }
            
            inv_pow[i][n] = mod_inv(p_pow[i][n], mod[i]);
            
            for (int j = n - 1; j >= 0; j--) {
                inv_pow[i][j] = (inv_pow[i][j + 1] * base) % mod[i];
            }
        }
    }

    vector<vector<ll>> build_hash(string &s) {
        int n = s.size();
        vector<vector<ll>> pre(primes, vector<ll>(n, 0));

        for (int i = 0; i < primes; i++) {
            for (int j = 0; j < n; j++) {
                ll val = (s[j] - 'a' + 1);
                ll term = (val * p_pow[i][j]) % mod[i];
                if (j == 0)
                    pre[i][j] = term;
                else
                    pre[i][j] = (pre[i][j - 1] + term) % mod[i];
            }
        }
        return pre;
    }

    vector<ll> get_sub_hash(const vector<vector<ll>>& pre, int l, int r) {
        vector<ll> res(primes);
        for (int i = 0; i < primes; i++) {
            ll hash_r = pre[i][r];
            ll hash_l = (l > 0) ? pre[i][l - 1] : 0;
            ll raw = ((hash_r - hash_l) % mod[i] + mod[i]) % mod[i];
            res[i] = (raw * inv_pow[i][l]) % mod[i];
        }
        return res;
    }
    
    int check(int len, int n, vector<vector<ll>>& pref) {
    
        vector<pair<pair<ll, ll>, int>> hashes;
        for (int i = 0; i <= n - len; i++) {
            vector<ll> h = get_sub_hash(pref, i, i + len - 1);
            hashes.push_back({{h[0], h[1]}, i});
        }
        sort(hashes.begin(), hashes.end());
        for (int i = 1; i < hashes.size(); i++) {
            if (hashes[i].first == hashes[i - 1].first) {
                return hashes[i].second;
            }
        }
        return -1;
    }
    
    string longestDupSubstring(string s) {
        int n = s.size();
        precompute(n);

        vector<vector<ll>> pre_s = build_hash(s);
        int lo = 1;
        int hi = n - 1;
        int best_len = 0;
        int best_start = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int start_ind = check(mid, n, pre_s);

            if (start_ind != -1) {
                best_len = mid;
                best_start = start_ind;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (best_start == -1)
            return "";
        return s.substr(best_start, best_len);
    }
};