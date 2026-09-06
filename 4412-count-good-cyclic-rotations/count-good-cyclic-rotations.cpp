class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int k = n / 2;

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int ans = 0;
        for (int start = 0; start < n; start++) {
            if (2 * windowSum > total) {
                ans++;
            }
            windowSum -= nums[start];
            windowSum += nums[(start + k) % n];
        }

        return ans;
    }
};