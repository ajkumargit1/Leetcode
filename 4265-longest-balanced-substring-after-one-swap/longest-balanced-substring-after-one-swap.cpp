class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), t0 = 0, t1 = 0, o = n + 2, cp = 0, ml = 0;
        
        for (char c : s) c == '0' ? t0++ : t1++;
        
        vector<vector<int>> p(2 * n + 5);
        p[o].push_back(0);
        
        for (int j = 1; j <= n; ++j) {
            s[j - 1] == '1' ? cp++ : cp--;
            
            int t = cp;
            if (t + o >= 0 && t + o < p.size() && !p[t + o].empty()) {
                ml = max(ml, j - p[t + o][0]);
            }
            
            t = cp - 2;
            if (t + o >= 0 && t + o < p.size()) {
                int l = j - 2 * t0;
                auto& v = p[t + o];
                auto it = lower_bound(v.begin(), v.end(), l);
                if (it != v.end()) ml = max(ml, j - *it);
            }
            
            t = cp + 2;
            if (t + o >= 0 && t + o < p.size()) {
                int l = j - 2 * t1;
                auto& v = p[t + o];
                auto it = lower_bound(v.begin(), v.end(), l);
                if (it != v.end()) ml = max(ml, j - *it);
            }
            
            p[cp + o].push_back(j);
        }
        
        return ml;
    }
};