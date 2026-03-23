class Solution {
public:
    bool is_safe(int ro,int col,vector<string>&board,int n)
    {
        int dupl_r=ro;
        int dupl_c=col;

        while(ro>=0 && col>=0)
        {
            if(board[ro][col]=='Q') return false;
            ro--;col--;
        }

        col=dupl_c;
        ro=dupl_r;

        while(col>=0)
        {
            if(board[ro][col]=='Q') return false;
            col--;
        }

        ro=dupl_r;
        col=dupl_c;

        while(ro<n && col>=0){
            if(board[ro][col]=='Q') return false;
            col--;ro++;
        }
        return true;
    }
    void fun(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int ro=0;ro<n;ro++)
        {
            if(is_safe(ro,col,board,n)){
                board[ro][col]='Q';
                fun(col+1,board,ans,n);
                board[ro][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        fun(0,board,ans,n);
        return ans;
    }
};