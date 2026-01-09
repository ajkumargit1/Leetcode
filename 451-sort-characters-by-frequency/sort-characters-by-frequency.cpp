class Solution {
public:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), cmp);

        string result = "";
        for (auto &p : v) {
            result.append(p.second, p.first);
        }
        return result;
    }
};
