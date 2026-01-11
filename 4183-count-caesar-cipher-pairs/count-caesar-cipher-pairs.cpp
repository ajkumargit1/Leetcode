class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<vector<int>, long long> mp;

        for (string &s : words) {
            vector<int> key;
            for (char c : s) {
                key.push_back((c - s[0] + 26) % 26);
            }
            mp[key]++;
        }

        long long ans = 0;
        for (auto &x : mp) {
            long long k = x.second;
            ans += k * (k - 1) / 2;
        }
        return ans;
    }
};
