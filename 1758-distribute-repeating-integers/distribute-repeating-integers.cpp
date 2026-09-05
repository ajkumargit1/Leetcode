class Solution {
public:
    bool helper(int ind,vector<int>&counts,vector<int>&quantity)
    {
        if(ind==quantity.size()) return true;

        for(int i=0;i<counts.size();i++)
        {
            if(counts[i]>=quantity[ind])
            {
                counts[i]-=quantity[ind];
                if(helper(ind+1,counts,quantity)) return true;
                counts[i]+=quantity[ind];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n=nums.size();
        int m=quantity.size();
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>counts;
        for(auto it:mp)
        {
            counts.push_back(it.second);
        }
        sort(counts.begin(),counts.end());
        sort(quantity.rbegin(),quantity.rend());
        return helper(0,counts,quantity);
    }
};