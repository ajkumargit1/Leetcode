class Solution {
public:
    vector<vector<int>>res;
    void helper(int &k,int &n,int len,int sum,int x,vector<int>path)
    {
        if(len==k && sum==n) {
            res.push_back(path);
            return;
        }
        for(int i=x;i<=9;i++)
        {
            if(sum>n || len>k) break;
            path.push_back(i);
            helper(k,n,len+1,sum+i,i+1,path);
            path.pop_back();
        }
        

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        helper(k,n,0,0,1,path);

        return res;
    }
};