class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //int sz=ranges.size();
        vector<pair<int,int>>inter(n+1);
        for(int i=0;i<=n;i++)
        {
            inter[i]={max(0,i-ranges[i]),i+ranges[i]};
        }
        sort(inter.begin(),inter.end(),[&](pair<int,int> a,pair<int,int> b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        });

        int end = inter[0].second;
        int start = inter[0].first;
        if(start > 0) return -1;
        if(end >= n) return 1;
        int ans = 1;
        int next_end = end; 
        
        for(int i=1;i<=n;i++)
        {
            if(inter[i].first > next_end) return -1;
            
            if(inter[i].first > end) {
                ans++;
                end = next_end;
            }
            
            next_end = max(next_end, inter[i].second);
            if(end >= n) return ans;
        }
   
        return next_end >= n ? ans + 1 : -1;
    }
};