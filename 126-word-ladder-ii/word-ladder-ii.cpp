class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> ans;
    string bWord;

    void dfs(string word,vector<string>&seq){
        if(word==bWord){
            vector<string>temp=seq;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        for(auto &parent:adj[word]){
            seq.push_back(parent);
            dfs(parent,seq);
            seq.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        bWord=beginWord;
        if(st.find(endWord)==st.end()) return {};

        unordered_map<string,int>steps;
        steps[beginWord]=1;
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front();
            int step=steps[word];
            q.pop();

            if(word==endWord) break;
            string original = word;
            for(int i=0;i<word.size();i++)
            {
                char org=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;

                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        steps[word]=step+1;
                        adj[word].push_back(original);
                    }else if(steps.find(word) != steps.end() && steps[word] == step + 1){
                        adj[word].push_back(original);
                    }
                }
                word[i]=org;
            }
        }
        if (adj.find(endWord) != adj.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
        
    }
};