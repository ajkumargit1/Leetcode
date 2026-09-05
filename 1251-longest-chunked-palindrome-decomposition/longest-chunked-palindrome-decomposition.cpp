class Solution {
public:
    int longestDecomposition(string text) {
        deque<char>dq1,dq2;
        int n=text.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j)
        {
            dq1.push_back(text[i]);
            dq2.push_front(text[j]);
            if(dq1==dq2)
            {
                if(i==j) ans+=1;
                else ans+=2;
                dq1.clear();
                dq2.clear();
            }
            i++;j--;
        }
        if(!dq1.empty() || !dq2.empty()) ans++;
        return ans;
    }
};