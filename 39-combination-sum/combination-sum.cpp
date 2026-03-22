class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& vec) {

        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(vec);
            }
            return;
        }

        if (target >= candidates[ind]) {
            vec.push_back(candidates[ind]);
            solve(ind, candidates, target - candidates[ind], ans, vec);
            vec.pop_back();
        }

        solve(ind + 1, candidates, target, ans, vec);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(0, candidates, target, ans, vec);
        return ans;
    }
};