class Solution {
public:

    bool checker(string s,string sub,int k)
    {
        int i=0;
        int cnt=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==sub[i]) i++;

            if(i==sub.size()) {
                i=0;cnt++;
            }
            if(cnt==k) return true;;

        }

        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        
        int n=s.size();
        vector<int>freq(26,0);
        for(auto c:s)
        {
            freq[c-'a']++;
        }
        string cand="";
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=k) cand+=(i+'a');
        }

        string ans="";
        queue<string>q;
        q.push("");

        while(!q.empty())
        {
            string curr=q.front();
            q.pop();

            for(auto c:cand)
            {
                string next_s=curr+c;
                if(checker(s,next_s,k))
                {
                    ans=next_s;
                    q.push(next_s);
                }
            }
        }

        return ans;
    }
};