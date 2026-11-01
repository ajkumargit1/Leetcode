#define ll long long 
class Solution {
    vector<ll>pre;
public:
    ll f(int i,int j,int a,int b)
    {
        ll x=(pre[j+1]-pre[i]);
        int len=j-i+1;

        ll no_split=(x>0)?len*x*a:b;
        if((j-i) % 2 != 0){
            ll split_cost=f(i,(i+j)/2,a,b)+f((i+j)/2+1,j,a,b);
            return min(split_cost,no_split);
        }
        return no_split;
    }
    ll minCost(string s, int encCost, int flatCost) {
        int n=s.size();
        pre.assign(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+s[i]-'0';
        }
        ll ans=f(0,n-1,encCost,flatCost);//shows the maximum cost using the whole segment

        return ans;
    }
};