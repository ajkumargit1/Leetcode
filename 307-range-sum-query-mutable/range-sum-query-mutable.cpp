class NumArray {
private:
    vector<int> nums;
    vector<int> block;
    int n;
    int S;

public:
    NumArray(vector<int>& input_nums) {
        nums = input_nums;     
        n = nums.size();       
        S = sqrt(n);           
        
        block.assign(S + 2, 0); 
        
        for(int i = 0; i < n; i++) {
            block[i / S] += nums[i]; 
        }
    }
    
    void update(int index, int val) {
        int block_id = index / S;
        block[block_id] = block[block_id] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int start = left / S;
        int end = right / S;
        int ans = 0;
        
        if(start == end)
        {
            for(int i = left; i <= right; i++) ans += nums[i];
        }
        else
        {
            int ind1 = (start + 1) * S - 1;
            for(int i = left; i <= ind1; i++) ans += nums[i];
            
            for(int i = start + 1; i <= end - 1; i++) ans += block[i];
            
            int ind2 = end * S;
            for(int i = ind2; i <= right; i++) ans += nums[i];
        }

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */