class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        int max_val=1<<n;
        vector<string>ans;
        for (int mask = 0; mask < max_val; ++mask) {
            if ((mask & (mask >> 1)) != 0) {
                continue; 
            }
            
            int cost = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << (n - 1 - i))) {
                    cost += i;
                }
            }
            
            if (cost <= k) {
                string s = "";
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << (n - 1 - i))) {
                        s += '1';
                    } else {
                        s += '0';
                    }
                }
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};