/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int res=0;
    int solve(TreeNode *papa)
    {
        if(!papa) return 0;
        int l=solve(papa->left);
        int r=solve(papa->right);
        if(papa->val >=max(r,l)) res++;

        return max(papa->val,max(l,r));
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return res;
    }
};