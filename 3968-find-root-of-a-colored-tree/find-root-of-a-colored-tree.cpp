class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int>indegree(n,0);
        vector<int>outdegree(n,0);
        auto get_col=[](char ch){
            if(ch=='R') return 0;
            if(ch=='B') return 1;
            return 2;
        };

        for(auto x:edges){
            int u=x[0];
            int v=x[1];

            int col_u=get_col(colors[u]);
            int col_v=get_col(colors[v]);

            if((col_u+1)%3==col_v){
                indegree[v]++;
                outdegree[u]++;
            }
            else if((col_v+1)%3==col_u){
                indegree[u]++;
                outdegree[v]++;
            }
            else return -1;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) {
                    return -1; 
                }
                root = i;
            }
        }
        if (root == -1 || outdegree[root] > 2) {
            return -1;
        }
        
        return root;
    }
};