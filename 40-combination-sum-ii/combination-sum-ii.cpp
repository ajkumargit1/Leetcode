class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& vec) {
        if(target==0)
        {
            ans.push_back(vec);
            return;
        }
        if (ind == candidates.size()) {
            
            return;
        }

        if (target >= candidates[ind]) {
            vec.push_back(candidates[ind]);
            solve(ind + 1 , candidates, target - candidates[ind], ans, vec);
            vec.pop_back();
        }

         int next = ind + 1;
        while (next < candidates.size() && candidates[next] == candidates  [ind]) {
            next++;
        }

        solve(next, candidates, target, ans, vec);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, target, ans, vec);
        return ans;
    }
};