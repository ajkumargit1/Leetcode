class Solution {
public:
    int vowelConsonantScore(string s) {
        int n=s.size();
        int v=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||
                s[i]=='o' || s[i]=='u') v++;
                else c++;
            }
        }
        if(c>0)
        return floor(v/c);
        return 0;
    }
};