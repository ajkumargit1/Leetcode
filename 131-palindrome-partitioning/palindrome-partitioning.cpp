class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

private:
    void dfs(const string& s, int i, vector<string>& path, vector<vector<string>>& res) {
        if (i == s.length()) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < s.length(); ++j) {
            if (isPal(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, path, res);              
                path.pop_back();                       
            }
        }
    }

    bool isPal(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};