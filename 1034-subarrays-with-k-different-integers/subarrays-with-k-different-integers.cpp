class Solution {
public:
    int at_most(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int left = 0;
        int dist_el = 0;
        int tot_sub = 0;
        for (int right = 0; right < n; right++) {
            if (freq[nums[right]] == 0) {
                dist_el++;
            }
            freq[nums[right]]++;

            while (dist_el > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    dist_el--;
                left++;
            }

            tot_sub += (right - left + 1);
        }

        return tot_sub;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most(nums, k) - at_most(nums, k - 1);
    }
};