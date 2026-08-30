class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({(aliceValues[i]+bobValues[i]),i});


        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int alice=0;
        int bob=0;
        for(int i=0;i<n;i +=2){
            alice +=aliceValues[v[i].second];
            if(i+1<n){
                bob +=bobValues[v[i+1].second];
            }

        }
        if(alice>bob) return 1;
        else if(alice==bob) return 0;
        else return -1;
        
    }
};