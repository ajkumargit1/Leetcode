class Solution {
public:
    int dp[105][5005];
    
    int f(int i, int rem, const vector<vector<pair<int,int>>>& options)
    {
        if(rem == 0) return 0;
        if(rem < 0 || i == options.size()) return 1e9;
        if(dp[i][rem] != -1) return dp[i][rem];
        
        // not_pick...
        int ans = f(i+1, rem, options);
        
        // pick...
        for(auto x : options[i])
        {
            int val = x.first;
            int cost = x.second;
            if(rem >= val) 
                ans = min(ans, cost + f(i+1, rem-val, options));
        }
        return dp[i][rem] = ans;
    }
    
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int,int>>> options(n);
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            
            queue<pair<int, int>> q;
            unordered_map<int, int> visited; 
            
            q.push({x, 0});
            visited[x] = 0;
            
            while(!q.empty()) {
                auto [curr, ops] = q.front();
                q.pop();
                
                int mult = curr * 2;
                if (mult <= sum && !visited.count(mult)) {
                    visited[mult] = ops + 1;
                    q.push({mult, ops + 1});
                }
                
                int div = curr / 2;
                if (curr > 0 && !visited.count(div)) {
                    visited[div] = ops + 1;
                    q.push({div, ops + 1});
                }
            }
            

            for(auto& pair : visited) {
                if(pair.first <= sum) {
                    options[i].push_back({pair.first, pair.second});
                }
            }
        }
        
        memset(dp, -1, sizeof(dp));
        int ans = f(0, sum, options);
        
        return ans >= 1e9 ? -1 : ans;
    }
};