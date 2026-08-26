class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        vector<int>pre(n);
        int mask=0;
        for(int i=0;i<n;i++)
        {
            int dig=(s[i]-'0');
            if(i==0)
            {
                pre[0]=(mask ^ (1<<dig));
            }
            else pre[i]=pre[i-1] ^  (1<<dig);
        }

        vector<int>seen(1024,n);//this stores the index of seen[pre[i]]...
        seen[0]=-1;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(seen[pre[i]]!=n)
            {
                ans=max(ans,i-seen[pre[i]]);
            }
            for(int j=0;j<10;j++)
            {
                int flipped_mask=pre[i] ^ (1<<j);
                if(seen[flipped_mask]!=n) ans=max(ans,i-seen[flipped_mask]);
            }
            if(seen[pre[i]]==n)
            {
                seen[pre[i]]=i;
            }
        }

        return ans;
    }
};