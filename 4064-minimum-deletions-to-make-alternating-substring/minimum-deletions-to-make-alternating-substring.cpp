class Solution {
public:
    struct Node{
        int block;
        int first_char;
        int last_char;
        Node(){
            block=0;
            first_char='#';
            last_char='#';
        }
    };
    Node merge(Node left,Node right)
    {
        Node res;
        if(left.block == 0) return right;
        if(right.block == 0) return left;
        res.first_char=left.first_char;
        res.last_char=right.last_char;
        if(left.last_char==right.first_char)
        {
            res.block=left.block + right.block - 1;
        }
        else res.block=left.block + right.block;

        return res;
    }
    static const int MAXX=1e5+5;
    Node tree[4*MAXX];
    void build(int node,int start,int end,string &s)
    {
        if(start==end){
            tree[node].block=1;
            tree[node].first_char=s[start];
            tree[node].last_char=s[start];
            return;
        }
        int mid=(start+end)/2;
        build(2*node,start,mid,s);
        build(2*node+1,mid+1,end,s);
        tree[node]=merge(tree[2*node],tree[2*node + 1]);
    }
    void update(int node, int start, int end, int ind) {
        if (start == end) {
            if (tree[node].first_char == 'A') {
                tree[node].first_char = 'B';
                tree[node].last_char = 'B';
            } else {
                tree[node].first_char = 'A';
                tree[node].last_char = 'A';
            }
            return;
        }
        int mid = (start + end) / 2;
        if (ind <= mid) {
            update(2 * node, start, mid, ind);
        } else {
            update(2 * node + 1, mid + 1, end, ind);
        }
        
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    Node query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return Node();
        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        Node left_ans = query(2 * node, start, mid, l, r);
        Node right_ans = query(2 * node + 1, mid + 1, end, l, r);
        
        return merge(left_ans, right_ans);
    }
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.size();
        build(1,0,n-1,s);
        vector<int>ans;
        for (auto it : queries) {
            if (it[0] == 1) {
                int j = it[1];
                update(1, 0, n - 1, j);
            } else if (it[0] == 2) {
                int l = it[1];
                int r = it[2];
                Node res = query(1, 0, n - 1, l, r);
                int range_size = r - l + 1;
                ans.push_back(range_size - res.block);
            }
        }
        
        return ans;
    }
};