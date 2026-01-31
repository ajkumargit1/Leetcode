class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int k = 0; k <= 30; k++) {
            vector<int> sub;
            for (int x : nums) {
                if ((x >> k) & 1)
                    sub.push_back(x);
            }

            if (sub.empty() || sub.size() <= ans)
                continue;

            vector<int> tails;
            for (int x : sub) {
                auto it = lower_bound(tails.begin(), tails.end(), x);
                if (it == tails.end()) {
                    tails.push_back(x);
                } else {
                    *it = x;
                }
            }
            if (tails.size() > ans)
                ans = tails.size();
        }

        return ans;
    }
};