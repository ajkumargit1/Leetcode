class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans = {0};
        for (int i = 0; i < mat.size(); i++) {
            priority_queue<int> pq;
            
            for (int x : ans) {
                for (int y : mat[i]) {
                    pq.push(x + y);
                    if (pq.size() > k) pq.pop();
                }
            }
            
            ans.clear();
            while (!pq.empty()) {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        
        return ans[0];
    }
};