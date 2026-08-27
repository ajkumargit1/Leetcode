class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int global_max = 1;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slopeMap; 
            for (int j = i + 1; j < n; j++) {
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(abs(dx), abs(dy));
                
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } 
                else if (dx == 0) {
                    dy = abs(dy); 
                }
                
                slopeMap[{dy, dx}]++;
                global_max = max(global_max, slopeMap[{dy, dx}] + 1);
            }
        }
        
        return global_max;
    }

};