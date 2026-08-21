class Solution {
public:
    struct Node{
        int val;
        Node(){
            val=INT_MAX; 
        }
    };
    Node merge(Node left,Node right)
    {
        Node res;
        res.val=(left.val & right.val);
        return res;
    }
    
    static const int MAXX=100005; 
    Node tree[4*MAXX]; 
    
    void build(int node,int start,int end, vector<int>& arr)
    {
        if(start==end)
        {
            tree[node].val=arr[start]; 
            return; 
        }
        int mid=(start+end)/2;
        build(2*node,start,mid, arr);
        build(2*node+1,mid+1,end, arr);

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
    Node query(int node,int start,int end,int l,int r)
    {
        if(start>r || end<l) return Node();
        if(start>=l && end<=r) return tree[node];

        int mid=(start+end)/2;
        Node left_ans=query(2*node,start,mid,l,r);
        Node right_ans=query(2*node+1,mid+1,end,l,r);

        return merge(left_ans,right_ans);
    }
    int closestToTarget(vector<int>& arr, int target) {
        int n=arr.size();
        build(1, 0, n-1, arr); 
        
        int ans=INT_MAX; 
        
        for(int l=0;l<n;l++)
        {
            int lo=l,hi=n-1; 
            while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                Node x=query(1,0,n-1,l,mid); 
                
                ans=min(ans, abs(x.val - target)); 
                
                if(x.val >= target)
                {
                    lo=mid+1; 
                }
                else hi=mid-1; 
            }
        }
        return ans; 
    }
};