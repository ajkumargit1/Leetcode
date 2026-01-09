class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();int khula=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
                khula++;
                ans=max(ans,khula);
            }
            else if(s[i]==')') khula--;
        }

        return ans;
    }
};