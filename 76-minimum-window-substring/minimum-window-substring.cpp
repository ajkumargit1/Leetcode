class Solution {
public:
    bool valid(unordered_map<char, int>& mp1, unordered_map<char, int>& mp2) {
        for (auto it : mp1) {
            int c = it.first;
            int needed = it.second;
            if (mp2[c] < needed)
                return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp1;
        for (auto x : t)
            mp1[x]++;
        unordered_map<char, int> mp2;
        int left = 0;
        int right = 0;
        int min_len = 2e9;
        int min_start = -1;
        for (right = 0; right < n; right++) {
            mp2[s[right]]++;
            while (valid(mp1, mp2)) {
                int cur_len = right - left + 1;
                if (cur_len < min_len) {
                    min_len=cur_len;
                    min_start = left;
                }
                mp2[s[left]]--;
                left++;
            }
        }

        if (min_len == 2e9)
            return "";
        return s.substr(min_start, min_len);
    }
};