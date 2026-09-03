class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m=requests.size();
        int ans=0;
        int combi=(1<<m);
        for(int i=0;i<combi;i++)
        {
            vector<int>degree(n,0);
            for(int j=0;j<m;j++)
            {
                if(i & (1<<j)){
                    int x=requests[j][0];
                    int y=requests[j][1];
                    degree[x]--;
                    degree[y]++;
                }  
            }

            bool valid=true;
            for(int j=0;j<n;j++)
            {
                if(degree[j]!=0)
                {
                    valid=false;
                    break;
                }
            }
            if(valid){
                int curr=__builtin_popcount(i);
                ans=max(ans,curr);
            }
        }

        return ans;
    }
};