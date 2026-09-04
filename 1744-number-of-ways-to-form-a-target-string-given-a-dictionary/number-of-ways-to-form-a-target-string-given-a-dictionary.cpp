class Solution {
public:
    static const long long mod=1e9+7;
    int f(int i,int k,vector<string>&words,string &target,vector<vector<int>>&freq,vector<vector<int>>&dp)
    {
        int p=target.size();
        int m=words[0].size();
        if(i==p) return 1;
        if(k==m) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        //pick case...
        long long ans=(1LL * freq[target[i]-'a'][k] * f(i+1,k+1,words,target,freq,dp) ) % mod;
        //not pick case...
        ans=(ans+f(i,k+1,words,target,freq,dp)) % mod;
        
        return dp[i][k]=ans;
    }
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
        int p=target.size();
        vector<vector<int>>freq(26,vector<int>(m));
        for(int row=0;row<n;row++)
        {
            string temp=words[row];
            for(int col=0;col<m;col++)
            {
                char ch=temp[col];
                freq[ch-'a'][col]++;
            }
        }
        vector<vector<int>>dp(p,vector<int>(m,-1));
        return f(0,0,words,target,freq,dp);
    }
};