class Solution {
public:
    int residuePrefixes(string s) {
        int ans=0;
        int n=s.size();
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp.size()==(i+1)%3) ans++;
        }

        return ans;
    }
};