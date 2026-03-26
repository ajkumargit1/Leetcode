class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX, min_even = INT_MAX;
        int odd = 0, even = 0;

        for (auto x : nums1) {
            if (x % 2) {
                odd++;
                min_odd = min(min_odd, x);
            } else {
                even++;
                min_even = min(min_even, x);
            }
        }
        if (odd == 0 || even == 0) return true;
        if (min_odd < min_even) return true;

        return false;
    }
};