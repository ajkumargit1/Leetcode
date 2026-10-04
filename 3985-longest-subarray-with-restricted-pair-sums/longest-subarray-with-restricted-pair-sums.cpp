class Solution {
public:
    bool checker(int v,vector<int>&freq){
        
        for(int a=1;a<=(v/2);a++)
        {
            int b=v-a;
            if(a==b){
                if (freq[a] >= 2) return true;
            }
           
            else 
            {
                if(freq[a]>=1 and freq[b]>=1) return true;
            }
        }
        for(int a=1;a<=500-v;a++)
        {
            int b=a+v;
            if(a==b){
                if (freq[a] >= 2) return true;
            }
           
            else 
            {
                if(freq[a]>=1 and freq[b]>=1) return true;
            }
        }
        return false;
    }
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int max_len=0;
        vector<int>freq(501,0);
        for(int right=0;right<n;right++)
        {
            int v=nums[right];
            while(checker(v,freq))
            {
                freq[nums[left]]--;
                left++;
            }
            freq[nums[right]]++;
            max_len=max(right-left+1,max_len);
        }
        return max_len;
    }
};