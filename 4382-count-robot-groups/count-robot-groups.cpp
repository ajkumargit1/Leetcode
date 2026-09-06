class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<double> T(n, 1e18);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                int j = st.top();
                double t;
                
                if (position[j] - position[i] <= distance) {
                    t = 0.0;
                } else if (speed[i] <= speed[j]) {
                    t = 1e18;
                } else {
                    t = (double)(position[j] - position[i] - distance) / (speed[i] - speed[j]);
                }
                
                if (t <= T[j]) {
                    T[i] = t;
                    st.push(i);
                    break;
                } else {
                    st.pop();
                }
            }
            if (st.empty()) {
                T[i] = 1e18;
                st.push(i);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (T[i] >= 1e18) {
                ans++;
            }
        }
        
        return ans;
    }
};