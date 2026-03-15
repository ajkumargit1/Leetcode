class Solution {
public:
    int countCommas(int n) {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            string dig=to_string(i);
            int sz=dig.size();
            res+=(sz-1)/3;
        }
    return res;
    }
};