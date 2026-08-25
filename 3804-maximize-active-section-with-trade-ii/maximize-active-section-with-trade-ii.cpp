#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long max_z;
        long long min_o;
        long long max_zz;
        
        Node() {
            max_z = 0;
            min_o = 1e9; 
            max_zz = 0;
        }
    };
    
    Node merge(Node left, Node right) {
        Node res;
        res.max_z = max(left.max_z, right.max_z);
        res.min_o = min(left.min_o, right.min_o);
        res.max_zz = max(left.max_zz, right.max_zz);
        return res;
    }
    
    vector<Node> tree; 
    
    void build(int node, int start, int end, const vector<int>& Z, const vector<int>& O, const vector<int>& ZZ) {
        if(start == end) {
            tree[node].max_z = Z[start];
            tree[node].min_o = O[start];
            tree[node].max_zz = ZZ[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, Z, O, ZZ);
        build(2 * node + 1, mid + 1, end, Z, O, ZZ);
        
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    Node query(int node, int start, int end, int l, int r) {
        if(start > r || end < l) return Node();
        if(start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        Node left_ans = query(2 * node, start, mid, l, r);
        Node right_ans = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left_ans, right_ans);
    }

    struct Block {
        int type;
        int len;
        int start_idx;
        int end_idx;
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_1s = 0;
        for (char c : s) if (c == '1') total_1s++;
        
        vector<Block> blocks;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            blocks.push_back({s[i] - '0', j - i, i, j - 1});
            i = j;
        }
        
        int M = blocks.size();
        tree.assign(4 * M + 1, Node()); 
        
        vector<int> Z(M, 0), O(M, 1e9), ZZ(M, 0);
        for(int k = 0; k < M; k++) {
            if (blocks[k].type == 0) {
                Z[k] = blocks[k].len;
                if (k + 2 < M && blocks[k+2].type == 0) {
                    ZZ[k] = blocks[k].len + blocks[k+2].len;
                }
            } else {
                O[k] = blocks[k].len;
            }
        }
        
        if (M > 0) build(1, 0, M - 1, Z, O, ZZ);
        
        auto get_block_idx = [&](int idx) {
            int l = 0, r = M - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (idx >= blocks[mid].start_idx && idx <= blocks[mid].end_idx) return mid;
                if (idx < blocks[mid].start_idx) r = mid - 1;
                else l = mid + 1;
            }
            return 0;
        };
        
        vector<int> ans;
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            
            int sb = get_block_idx(l); 
            int eb = get_block_idx(r); 
            
            if (sb == eb) {
                ans.push_back(total_1s);
                continue;
            }
            
            int b_sb_len = blocks[sb].end_idx - l + 1;
            int b_eb_len = r - blocks[eb].start_idx + 1;
            
            Node mid_res = query(1, 0, M - 1, sb + 1, eb - 1);
            
            int max_z = mid_res.max_z;
            if (blocks[sb].type == 0) max_z = max(max_z, b_sb_len);
            if (blocks[eb].type == 0) max_z = max(max_z, b_eb_len);
            
            int min_o = mid_res.min_o; 
            
            int max_zz = query(1, 0, M - 1, sb + 1, eb - 3).max_zz; 
            
            if (blocks[sb].type == 0) {
                int right_len = (sb + 2 == eb) ? b_eb_len : (sb + 2 < eb ? blocks[sb+2].len : 0);
                if (sb + 2 <= eb) max_zz = max(max_zz, b_sb_len + right_len);
            }
            if (eb - 2 >= sb && blocks[eb-2].type == 0) {
                int left_len = (eb - 2 == sb) ? b_sb_len : blocks[eb-2].len;
                max_zz = max(max_zz, left_len + b_eb_len);
            }
            
            int max_gain = max(0, max_zz);
            if (min_o != 1e9) {
                max_gain = max(max_gain, max_z - min_o);
            }
            
            ans.push_back(total_1s + max_gain);
        }
        
        return ans;
    }
};