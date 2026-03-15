class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> L(n,1), R(n,1);
        
        for(int i=1;i<n;i++){
            if(i>=2 && nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                L[i] = L[i-1] + 1;
            else
                L[i] = 2;
        }
      
        for(int i=n-2;i>=0;i--){
            if(i+2<n && nums[i+1]-nums[i]==nums[i+2]-nums[i+1])
                R[i] = R[i+1] + 1;
            else
                R[i] = 2;
        }
        
        int ans = 2;
        
        for(int i=0;i<n;i++){
            
            ans = max(ans, L[i]);
            ans = max(ans, R[i]);
            
            if(i>0) ans = max(ans, L[i-1] + 1);
            if(i<n-1) ans = max(ans, R[i+1] + 1);
            
            if(i>0 && i<n-1){
                
                int diff = nums[i+1] - nums[i-1];
                
                if(diff % 2 == 0){
                    
                    int d = diff/2;
                    
                    int left = 1;
                    if(i>=2 && nums[i-1]-nums[i-2]==d)
                        left = L[i-1];
                    
                    int right = 1;
                    if(i+2<n && nums[i+2]-nums[i+1]==d)
                        right = R[i+1];
                    
                    ans = max(ans, left + 1 + right);
                }
            }
        }
        
        return ans;
    }
};