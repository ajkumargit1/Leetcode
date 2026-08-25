class Solution {
public:
    struct Node{
        long long sum; 
        Node(){
            sum = 0;
        }
    };
    
    Node merge(Node left, Node right)
    {
        Node res;
        res.sum = left.sum + right.sum;
        return res;
    }
    

    vector<Node> tree;
    
    void update(int node, int start, int end, int ind, int val)
    {
        if(start == end)
        {
            tree[node].sum += val;
            return;
        }
        int mid = (start + end) / 2;
        if(ind <= mid)
        {
            update(2 * node, start, mid, ind, val);
        }
        else 
        {
            update(2 * node + 1, mid + 1, end, ind, val);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    Node query(int node, int start, int end, int l, int r)
    {
        if(start > r || end < l) return Node();
        if(start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        Node left_ans = query(2 * node, start, mid, l, r);
        Node right_ans = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left_ans, right_ans);
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Dynamically assign the tree size and clear it perfectly
        tree.assign(4 * n + 1, Node());
        
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
        {
            pos[nums1[i]] = i;
        }
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            arr[i] = pos[nums2[i]];
        }
        
        long long ans = 0; 
        
        for(int i = 0; i < n; i++)
        {
            int val = arr[i];
            long long left_smaller = 0;
            
            if(val > 0)
            {
                left_smaller = query(1, 0, n - 1, 0, val - 1).sum;
            }
            
            long long left_larger = i - left_smaller;
            long long total_larger = (n - 1) - val;
            long long right_larger = total_larger - left_larger;

            ans += (left_smaller * right_larger);
            update(1, 0, n - 1, val, 1);
        }

        return ans;
    }
};