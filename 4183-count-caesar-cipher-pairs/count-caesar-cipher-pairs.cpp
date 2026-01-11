class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map <string,long long>mp;

        for(string &s:words)
        {
            int m=s.size();
            string temp="";
            for(int i=0;i<m;i++)
            {
                int diff=(s[i]-s[0]+26)%26;
                temp+=to_string(diff)+"*";//because [0,1,11] and [0,11,1] will form same temp but both are diff in reality
            }
            mp[temp]++;
        } 
        long long ans=0;
        for(auto it:mp)
        {
            long long val=it.second;
            ans+=(val*(val-1))/2;
        }
        return ans;
    }
};