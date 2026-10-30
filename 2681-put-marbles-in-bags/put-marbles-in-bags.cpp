#define ll long long
class Solution {
public:
    ll putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>temp;
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(weights[i]+weights[i+1]);
        }
        if(k==1 || n==k) return 0LL; 
        sort(temp.begin(),temp.end());
        ll mini=accumulate(temp.begin(),temp.begin()+k-1,0LL);
        reverse(temp.begin(),temp.end());
        ll maxi=accumulate(temp.begin(),temp.begin()+k-1,0LL);

        return (maxi-mini);
        
    }
};