class Solution {
public:
    //dp(ind,even_cnt,od_cnt,rem,tight,is_leading0)
    int dp[11][11][11][20][2][2];
    int f(int ind,string &s,int evn_cnt,int od_cnt,int rem,int tight,int is_leading0,int k)
    {
        if(ind==(int)s.size()) 
        {
            if(is_leading0) return 0;
            return (evn_cnt==od_cnt && rem==0);
        }
        if(dp[ind][evn_cnt][od_cnt][rem][tight][is_leading0]!=-1)
        return dp[ind][evn_cnt][od_cnt][rem][tight][is_leading0];

        int bound=tight ? s[ind]-'0' : 9;
        int ans=0;
        for(int dig=0;dig<=bound;dig++)
        {
            int new_tight=tight && (dig==(s[ind]-'0'));

            if(is_leading0 && dig==0)
            {
                ans+=f(ind+1,s,0,0,0,new_tight,1,k);
            }
            else
            {
                int nevn_cnt=evn_cnt+(dig%2==0);
                int nod_cnt=od_cnt+(dig%2 != 0);
                int nrem=(rem*10 + dig)%k;
                ans+=f(ind+1,s,nevn_cnt,nod_cnt,nrem,new_tight,0,k);
            }
        }

        return dp[ind][evn_cnt][od_cnt][rem][tight][is_leading0]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
         int low_ans=0;
        if(low>=1)
        {
            low--;
            string s1=to_string(low);
            memset(dp,-1,sizeof(dp));
            low_ans=f(0,s1,0,0,0,1,1,k);
        }
        string s2=to_string(high);
        memset(dp,-1,sizeof(dp));
        int high_ans=f(0,s2,0,0,0,1,1,k);


        return high_ans-low_ans;
        
    }
};