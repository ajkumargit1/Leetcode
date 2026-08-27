class Solution {
public:
    unordered_map<string,vector<string>>memo;
    vector<string>solve(string s,unordered_set<string>&word_set)
    {
        if(s.empty()) return {""};
        if(memo.find(s)!=memo.end()) return memo[s];

        vector<string>results;
        for(int i=1;i<=s.size();i++)
        {
            string pre=s.substr(0,i);
            if(word_set.find(pre)!=word_set.end())
            {
                string suff=s.substr(i);//means chop initial i length and return the remaining
                vector<string>suff_result=solve(suff,word_set);

                for(auto sub:suff_result)
                {
                    if(sub.empty()) results.push_back(pre);
                    else{
                        results.push_back(pre+" "+sub);
                    }
                }
            }
        }
        return memo[s]=results;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word_set(wordDict.begin(),wordDict.end());
        
        return solve(s,word_set);
    }
};