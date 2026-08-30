class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;)
        {
            int val=nums[i];
            temp.push_back(val);
            while(i<n && val==nums[i]) i++;
        }
       unordered_map<int, int> freq;
        for(int num : temp) {
            freq[num]++;
        }
        
        int ans = 0;
        for(auto it : freq) {
            if(it.second == 1) {
                ans++;
            }
        }
        return ans;
    }
};