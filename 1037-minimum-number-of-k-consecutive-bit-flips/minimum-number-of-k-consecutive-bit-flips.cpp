class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> activeFlips;
        int totalFlips = 0;

        for (int i = 0; i < n; ++i) {
            if (!activeFlips.empty() && activeFlips.front() == i) {
                activeFlips.pop();
            }

            if ((nums[i] + activeFlips.size()) % 2 == 0) {
                if (i + k > n) {
                    return -1; 
                }
                activeFlips.push(i + k);
                totalFlips++;
            }
        }

        return totalFlips;
    }
};