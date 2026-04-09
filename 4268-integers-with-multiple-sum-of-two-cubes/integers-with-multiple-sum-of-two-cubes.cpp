class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<long long,long long>mp;
        vector<int>res;
        long long last_n=cbrt(n);
        for(long long i=1;i<=last_n;i++)
        {
            long long a_cube=i*i*i;
            for(int j=i;j<=n;j++)
            {
                long long sm=a_cube + j*j*j;
                if(sm>n) break;
                mp[sm]++;
            }
        }

        for(auto it:mp)
        {
            if(it.second>=2)
            res.push_back(it.first);
        }
        sort(res.begin(),res.end());

        return res;
    }
};