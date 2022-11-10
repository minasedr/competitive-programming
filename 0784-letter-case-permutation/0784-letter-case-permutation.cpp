class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        function<void(int, string)> dfs;
        dfs = [&](int i, string cur) {
            if (i == s.size()) {
                ans.push_back(cur);
                return;
            }
            dfs(i + 1, cur + s[i]);
            if (isalpha(s[i]))
                dfs(i + 1, cur + char(s[i] ^ (1 << 5)));
        };
        dfs(0, "");
        return ans;
    }
};