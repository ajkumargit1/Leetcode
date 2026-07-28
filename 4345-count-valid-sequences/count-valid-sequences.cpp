class Solution {
public:
    long long mod=1e9+7;
    long long bin_exp(long long a,long long b)
    {
        long long res=1;
        while(b>0)
        {
            if(b&1) res=(res*a) % mod;
            a=(a*a) % mod;
            b/=2;
        }
        return res;
    }

    int countValidSequences(int n, int k) {
        if(n<k) return 0;
        vector<long long>fact(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++)
        fact[i]=(i*fact[i-1]) % mod;
        vector<long long>inv_fact(n+1);
        inv_fact[n]=bin_exp(fact[n],mod-2);
        for(int i=n-1;i>=0;i--)
        {
            inv_fact[i]=((i+1)*inv_fact[i+1])%mod;
        }

        auto nCr=[&](long long n,long long r)->long long{
            if(n<r || r<0) return 0LL;
            return (((fact[n]*inv_fact[n-r])%mod)*inv_fact[r])%mod; 
        };

        long long tot_seq=nCr(n-1,k-1);
        long long x=(n-k)/2;
        if((n-k)%2) return tot_seq;
        long long odd_seq=nCr(x+k-1,k-1);

        return (tot_seq-odd_seq+mod)%mod;
    }
};