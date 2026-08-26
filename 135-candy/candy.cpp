class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i < n; i++) {
            v[i] = {ratings[i], i};
        }
        
        sort(v.begin(), v.end());
        
        vector<int> ans(n, 1);
        int sm = 0;
        
        for(auto it : v) {
            int val = it.first;
            int ind = it.second;
            
            if(ind > 0 && ratings[ind] > ratings[ind-1]) {
                ans[ind] = max(ans[ind], ans[ind-1] + 1);
            }
            
            if(ind < n - 1 && ratings[ind] > ratings[ind+1]) {
                ans[ind] = max(ans[ind], ans[ind+1] + 1);
            }
            
            sm += ans[ind];
        }

        return sm;
    }
};