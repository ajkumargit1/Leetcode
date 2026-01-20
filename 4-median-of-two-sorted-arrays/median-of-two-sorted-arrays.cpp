class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0, high = n;

        while (low <= high) {
            int takeA = (low + high) / 2;
            int takeB = (n + m + 1) / 2 - takeA;

            int leftA  = (takeA == 0) ? INT_MIN : nums1[takeA - 1];
            int rightA = (takeA == n) ? INT_MAX : nums1[takeA];

            int leftB  = (takeB == 0) ? INT_MIN : nums2[takeB - 1];
            int rightB = (takeB == m) ? INT_MAX : nums2[takeB];

            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2 == 1)
                    return max(leftA, leftB);
                else
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            else if (leftA > rightB) {
                high = takeA - 1;
            }
            else {
                low = takeA + 1;
            }
        }

        return 0.0;
    }
};