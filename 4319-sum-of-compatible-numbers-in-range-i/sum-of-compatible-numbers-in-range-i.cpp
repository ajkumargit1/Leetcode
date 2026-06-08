class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int lo = max(1, n - k);
        int hi = n + k;

        int ans = 0;

        for (int i = lo; i <= hi; i++) {
            if (abs(n - i) <= k && ((n & i) == 0))
                ans+=i;
        }

        return ans;
    }
};