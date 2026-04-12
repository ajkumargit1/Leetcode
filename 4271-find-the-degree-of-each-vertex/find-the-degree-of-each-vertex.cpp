class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>degree;
        for(int i=0;i<n;i++)
        {
            int deg=0;
            for(int j=0;j<n;j++)
            {
                deg+=matrix[i][j]==1?1:0;
            }
                degree.push_back(deg);
        }

        return degree;
    }
};