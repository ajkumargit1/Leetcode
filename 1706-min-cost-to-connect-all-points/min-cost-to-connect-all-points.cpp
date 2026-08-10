class Solution {
public:
    
    struct DSU{
        vector<int>par;
        vector<int>sz;

        DSU (int n){
            par.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++) make_set(i);
        }
        void make_set(int node)
        {
            par[node]=node;
            sz[node]=1;
        }
        int find_set(int node)
        {
            if(par[node]==node) return node;
            return par[node]=find_set(par[node]);
        }
        void set_union(int a,int b)
        {
            int root_a=find_set(a);
            int root_b=find_set(b);

            if(root_a==root_b) return;
            if(sz[root_a]<sz[root_b]) swap(root_a,root_b);

            par[root_b]=root_a;
            sz[root_a]+=sz[root_b];
        }
    };

    int kruskal(int n,vector<vector<int>>&adj)
    {
        DSU dsu(n);
        int ans=0;
        sort(adj.begin(),adj.end(),[](auto &l, auto &r){
            return l[2]<r[2];
        });

        for(auto edge:adj)
        {
            int u =edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(dsu.find_set(u)==dsu.find_set(v)) continue;
            dsu.set_union(u,v);
            ans+=wt;
        }

        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({i,j,wt});
            }
        }
        int res=kruskal(n,adj);

        return res;

    }
};