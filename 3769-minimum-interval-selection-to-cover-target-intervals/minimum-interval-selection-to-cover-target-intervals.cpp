
class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        int n = availableIntervals.size();
        int m = targetIntervals.size();

        sort(targetIntervals.begin(), targetIntervals.end());

        vector<pair<int,int>> target;

        for (int i = 0; i < m; i++) {
            if (target.empty() || target.back().second < targetIntervals[i][0]) {
                target.push_back({targetIntervals[i][0], targetIntervals[i][1]});
            }
            else {
                target.back().second = max(target.back().second, targetIntervals[i][1]);
            }
        }

        sort(availableIntervals.begin(), availableIntervals.end());

        int ans = 0;
        int curr_reach = -1;
        int i = 0;

        for (auto t : target) {
            if (curr_reach >= t.second) continue;
            int start = max(curr_reach, t.first);
            
            while (curr_reach < t.second) {
                int max_reach = start;
                bool found_cover = false;

                while (i < n && availableIntervals[i][0] <= start) {
                    if (availableIntervals[i][1] >= start) {
                        max_reach = max(max_reach, availableIntervals[i][1]);
                        found_cover = true;
                    }
                    i++;
                }

                if (!found_cover || (max_reach == start && start < t.second)) {
                    return -1;
                }

                ans++;
                start = max_reach;
                curr_reach = max_reach;
            }
        }

        return ans;
    }
};
