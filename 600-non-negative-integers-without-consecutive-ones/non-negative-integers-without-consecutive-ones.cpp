class Solution {
public:
    int dp[32][2][2];
    string s;
    int f(int i,int tight,int prev)
    {
        if(i==s.size()) return 1;
        if(dp[i][tight][prev]!=-1) return dp[i][tight][prev];

        int bound=tight ? (s[i]-'0') : 1;
        int ways=0;
        for(int d=0;d<=bound;d++)
        {
            if(prev==1 && d==1) continue;
            int new_tight=(tight && (d==(s[i]-'0')));
            ways+=f(i+1,new_tight,d);
        }
        return dp[i][tight][prev]=ways;
    }
    int findIntegers(int n) {
        s="";
        int temp=n;
        while(temp>0){
            s+=to_string(temp%2);
            temp/=2;
        }
        reverse(s.begin(),s.end());

        for(int i=0;i<32;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                dp[i][j][k]=-1;
            }
        }

        int ans=f(0,1,0);
        return ans;
    }
};