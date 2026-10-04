class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int ans=0;
        int last=0;
        for(auto ch:s){
            ans+=min(10-abs((ch-'0')-last),abs((ch-'0')-last));
            last=ch-'0';
        }
        return ans;
    }
};