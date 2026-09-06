class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) cnt++;
        }
        if(s[0]==s[n-1]) cnt++;
        if(k==cnt) return n-cnt;
        if(k==cnt-1) return cnt;
        return 0;
    }
};