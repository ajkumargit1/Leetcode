class Solution {
public:
    const int mod=1e9+7;
    bool is_valid(int state,int m)
    {
        int prev_col=-1;
       for(int i=0;i<m;i++)
        {
            int curr_col=(state%3);
            if(curr_col==prev_col) return false;
            prev_col=curr_col;
            state=(state/3);
        }

        return true;
    }
    bool is_compatible(int state1,int state2,int m)
    {
        for(int i=0;i<m;i++)
        {
            int curr1=(state1%3);
            int curr2=(state2%3);
            if(curr1==curr2) return false;
            state1/=3;
            state2/=3;
        }

        return true;
    }
    int colorTheGrid(int m, int n) {
        int num_states=pow(3,m);
        vector<int>valid_states;
        for(int i=0;i<num_states;i++)
        {
            if(is_valid(i,m))
            {
                valid_states.push_back(i);
            }
        }
        vector<vector<long long>>dp(n,vector<long long>(num_states,0));

        for(auto state:valid_states)
        {
            dp[0][state]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int curr=0;curr<valid_states.size();curr++)
            {
                for(int prev=0;prev<valid_states.size();prev++)
                {
                    if(is_compatible(valid_states[curr],valid_states[prev],m))
                    {
                        dp[i][valid_states[curr]]=(dp[i][valid_states[curr]]+dp[i-1][valid_states[prev]])%mod;
                    }
                }
            }
        }
        long long ways=0;
        for(int j=0;j<num_states;j++)
        {
            ways=(ways+dp[n-1][j])%mod;
        }

        return ways;
    }
};