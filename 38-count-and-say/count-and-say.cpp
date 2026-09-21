class Solution {
public:
    string countAndSay(int n) {
       string s="1";
       for(int i=2;i<=n;i++)
       {
        string next="";
        int j=0;

        while(j<s.size()){
            int cnt=0;
            char dig=s[j];

            while(j<s.size() && s[j]==dig){
                cnt++;j++;
            }
            next+=to_string(cnt);
            next+=dig;
        }
        s=next;
       }
       return s;

       
    }
};