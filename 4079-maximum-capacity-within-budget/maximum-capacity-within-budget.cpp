class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({costs[i], capacity[i]});

        sort(a.begin(), a.end());

        vector<int> pref(n);
        pref[0] = a[0].second;
        for (int i = 1; i < n; i++)
            pref[i] = max(pref[i - 1], a[i].second);

        int ans = 0;

        // One machine
        for (int i = 0; i < n; i++) {
            if (a[i].first < budget)
                ans = max(ans, a[i].second);
        }

        // Two machines
        for (int i = 0; i < n; i++) {
            int rem = budget - a[i].first - 1;
            if (rem < 0) continue;

            int j = upper_bound(
                a.begin(), a.begin() + i,
                make_pair(rem, INT_MAX)
            ) - a.begin() - 1;

            if (j >= 0) {
                ans = max(ans, a[i].second + pref[j]);
            }
        }

        return ans;
    }
};