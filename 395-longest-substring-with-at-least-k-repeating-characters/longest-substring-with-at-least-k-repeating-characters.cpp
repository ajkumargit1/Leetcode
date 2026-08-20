class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n<k) return 0;

        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }

        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]<k)
            {
                string left=s.substr(0,i);
                string right=s.substr(i+1);

                return max(longestSubstring(left,k),
                longestSubstring(right,k));
            }
        }

        return n;
    }
};