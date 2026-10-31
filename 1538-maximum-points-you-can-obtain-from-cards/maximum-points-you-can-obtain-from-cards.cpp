class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>pre1(cardPoints);
        vector<int>pre2(cardPoints);
        reverse(pre2.begin(),pre2.end());
        for(int i=1;i<n;i++){
            pre1[i]+=pre1[i-1];
            pre2[i]+=pre2[i-1];
        }

        int maxi=0;
        for(int i=0;i<=k;i++){
            maxi=max(maxi,(i==0?0:pre1[i-1])+(i==k?0:pre2[k-i-1]));
        }

        return maxi;
    }
};