class Solution {
public:
    struct DSU{
        vector<int>sz;
        vector<int>parent;
        int components;

        DSU(int n){
            sz.resize(n+1);
            parent.resize(n+1);
            components=n;
            for(int i=1;i<n;i++){
                make_set(i);
            }
        }
        void make_set(int x)
        {
            parent[x]=x;
            sz[x]=1;
        }
        int find_set(int v)
        {
            if(v==parent[v]) return v;
            return parent[v]=find_set(parent[v]);
        }
        void set_union(int u,int v)
        {
            int root_a=find_set(u);
            int root_b=find_set(v);
            if(root_a==root_b) return;
            if(sz[root_a]<sz[root_b]) swap(root_a,root_b);

            sz[root_a]+=sz[root_b];
            parent[root_b]=root_a;
            components--;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        int kept=0;
        for(auto edge:edges)
        {
            int type=edge[0],u=edge[1],v=edge[2];

            if (type == 3) {
                if (alice.find_set(u) != alice.find_set(v)) {
                    alice.set_union(u, v);
                    bob.set_union(u, v);
                    kept++;
                }
            }
        }
        for(auto edge:edges)
        {
            int type=edge[0],u=edge[1],v=edge[2];
            if(type==1){
                if(alice.find_set(u)!=alice.find_set(v)){
                    alice.set_union(u,v);
                    kept++;
                }
            }
        }
        for(auto edge:edges)
        {
             int type=edge[0],u=edge[1],v=edge[2];
            if(type==2){
                if(bob.find_set(u)!=bob.find_set(v)){
                    bob.set_union(u,v);
                    kept++;
                }
            }
        }

        if(alice.components==1 && bob.components==1)
            return edges.size() - kept;
        return -1;

    }
};