class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&vec,vector<vector<int>>&ans){
        
        if(i==nums.size()) 
        {
            ans.push_back(vec);
            return;
        }
        //pick cond.
        vec.push_back(nums[i]);
        solve(i+1,nums,vec,ans);
        vec.pop_back();

        int next=i+1;
        while(next<nums.size() && nums[next]==nums[i]) next++;

        solve(next,nums,vec,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>vec;
        sort(nums.begin(),nums.end());
        solve(0,nums,vec,ans);
        return ans;
    }
};