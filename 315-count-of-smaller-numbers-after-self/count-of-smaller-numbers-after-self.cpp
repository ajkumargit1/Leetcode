class Solution {
public:
    static const int MAXX=20005;
    int tree[4*MAXX];
    void update(int node,int start,int end,int idx)
    {
        if(start==end)
        {
            tree[node]++;return;
        }
        int mid=(start+end)/2;
        if(mid>=idx)
        {
            update(2*node,start,mid,idx);
        }
        else 
        {
            update(2*node+1,mid+1,end,idx);
        }

        tree[node]=tree[2*node]+tree[2*node+1];

    }

    int query(int node,int start,int end,int l,int r)
    {
        if(start>r || end<l) return 0;
        if(start>=l && end<=r) return tree[node];

        int mid=(start+end)/2;
        int left_ans=query(2*node,start,mid,l,r);
        int right_ans=query(2*node+1,mid+1,end,l,r);

        return left_ans+right_ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n);
        memset(tree,0,sizeof(tree));
        for(int i=n-1;i>=0;i--)
        {
            int val=nums[i]+10001;
            count[i]=query(1,1,MAXX,1,val-1);
            update(1,1,MAXX,val);
        }

        return count;
    }
};