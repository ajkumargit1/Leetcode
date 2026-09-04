class Solution {
public:
    struct DSU{
        vector<int>parent;
        vector<int>sz;
        DSU(int n){
            parent.resize(n+1);
            sz.resize(n+1);
            for(int i=1;i<=n;i++) make_set(i);
        }
        void make_set(int node)
        {
            parent[node]=node;
            sz[node]=1;
        }
        int find(int node)
        {
            if(node==parent[node]) return node;
            return parent[node]=find(parent[node]);
        }
        void set_union(int u,int v)
        {
            int root_a=find(u);
            int root_b=find(v);
            if(root_a==root_b) return;
            if(sz[root_a]<sz[root_b]) swap(root_a,root_b);
            sz[root_a]+=sz[root_b];
            parent[root_b]=root_a;
        }
    };
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<bool>ans;
        
        for(int i=threshold+1;i<=n;i++)
        {
            for(int z=2*i;z<=n;z+=i)
            {
                dsu.set_union(i,z);
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            if(dsu.find(u)==dsu.find(v))
            ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};