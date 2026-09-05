class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
        const unsigned long long base = 31;
        unsigned long long left_hash=0;
        unsigned long long right_hash=0;
        unsigned long long power=1;
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            int left_char=text[i]-'a'+1;
            left_hash=left_hash*base + left_char;
            int right_char=text[n-1-i]-'a'+1;
            right_hash=right_char*power + right_hash;
            power*=base;

            if(left_hash==right_hash){
                ans+=2;
                left_hash=0;
                right_hash=0;
                power=1;
            }
        }
        if(n&1 || left_hash!=0) ans++;

        return ans;
    }
};