class Solution {
public:
    int minDeletions(vector<int>& nums) {
       int cnt=0;
       for(int i=0;i<nums.size();i++)
       {
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        cnt++;
       }
       return nums.size()-cnt;
    }
};