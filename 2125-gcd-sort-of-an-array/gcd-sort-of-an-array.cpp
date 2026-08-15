class Solution {
public:
    struct DSU {
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.resize(n);

            for(int i=0;i<n;i++) {
                parent[i]=i;
                sz[i]=1;
            }
        }

        int find_set(int v) {
            if(parent[v]==v) return v;
            return parent[v]=find_set(parent[v]);
        }

        void set_union(int a,int b) {
            int root_a=find_set(a);
            int root_b=find_set(b);

            if(root_a==root_b) return;

            if(sz[root_a]<sz[root_b])
                swap(root_a,root_b);

            sz[root_a]+=sz[root_b];
            parent[root_b]=root_a;
        }
    };

    bool gcdSort(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int> spf(maxi+1);

        for(int i=0;i<=maxi;i++)
            spf[i]=i;

        for(int i=2;i*i<=maxi;i++) {
            if(spf[i]==i) {
                for(int j=i*i;j<=maxi;j+=i) {
                    if(spf[j]==j)
                        spf[j]=i;
                }
            }
        }

        DSU dsu(maxi+1);

        for(int num:nums) {
            int temp=num;

            while(temp>1) {
                int p=spf[temp];

                dsu.set_union(num,p);

                while(temp%p==0)
                    temp/=p;
            }
        }

        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());

        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=sorted[i] &&
               dsu.find_set(nums[i])!=dsu.find_set(sorted[i]))
                return false;
        }

        return true;
    }
};