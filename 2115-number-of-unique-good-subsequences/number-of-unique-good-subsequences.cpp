class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const long long mod=1e9+7;
        long long end1=0;//number of subsequnces ending at 1
        long long end0=0;//number of subsequnces ending at 0

        int cnt0=0;
        for(int i=0;i<binary.size();i++)
        {
            if(binary[i]=='1')
            {
                end1=(end1+end0+1)%mod;
            }
            else
            {
                cnt0=1;
                end0=(end1+end0)%mod;
            }
        }

        return (end0+end1+cnt0)%mod;
    }
};