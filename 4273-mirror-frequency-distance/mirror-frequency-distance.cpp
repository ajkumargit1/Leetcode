class Solution {
public:
    int mirrorFrequency(string s) {
        map<int,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        int ans=0;
        for(char c='a' ;c<='z' ; c++)
        {
            char mirror='z'-(c-'a');
            if(c<=mirror)
            ans+=abs(mp[mirror]-mp[c]);
        }
        for(char dig='0';dig<='9';dig++)
        {
            char mirror='9'-(dig-'0');
            if(dig<=mirror)
            ans+=abs(mp[mirror]-mp[dig]);
        }


        return ans;
    }
};