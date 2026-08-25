class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++)
        {
            bool hmm=true;
            for(int i=0;i<n;i++)
            {
                if((mask & (1<<i)) == 0) continue;
                for(int j=0;j<n;j++)
                {
                    int thik=(mask & (1<<j)) ? 1 : 0;
                    if((statements[i][j]==1 && thik==0) || (statements[i][j]==0 && thik==1))
                    {
                        hmm=false;break;
                    }
                }
                if(!hmm) break;
            }
                if(hmm){
                int curr=__builtin_popcount(mask);
                ans=max(ans,curr);
            }
        }

        return ans;
    }
};