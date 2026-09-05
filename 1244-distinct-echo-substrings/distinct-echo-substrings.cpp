class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        const unsigned long long base=31;
        vector<unsigned long long>hash(n,0);
        vector<unsigned long long>p(n,1);

        p[0]=1;
        hash[0]=text[0]-'a'+1;
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1]*base;
            int ch=text[i]-'a'+1;
            hash[i]=hash[i-1]+ch*p[i];
        }

        auto gethash=[&](int l,int r){
            unsigned long long raw_hash;
            if(l==0)
            {
                raw_hash=hash[r];
            }else{
                raw_hash=hash[r]-hash[l-1];
            }

            return raw_hash * p[n-l-1];
        };
        unordered_set<unsigned long long>st;

        for(int len=1;len<=n/2;len++)
        {
            for(int i=0;i<=n-2*len;i++)
            {
                unsigned long long hash1=gethash(i,i+len-1);
                unsigned long long hash2=gethash(i+len,i+2*len-1);

                if(hash1==hash2) st.insert(hash1);
            }
        }
        return st.size();
    }
};