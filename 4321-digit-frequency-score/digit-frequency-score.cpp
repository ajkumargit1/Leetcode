class Solution {
public:
    int digitFrequencyScore(int n) {
        string s=to_string(n);
        int ans=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto x:mp)
        {
            ans+=(x.first-'0') * (x.second);
        }
        return ans;
    }
};