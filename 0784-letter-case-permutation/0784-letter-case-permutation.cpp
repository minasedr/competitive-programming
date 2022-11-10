class Solution {
public:
    vector<string> ans;
    void dfs(int i, string s, string cur) {
        if (i >= s.size()) {
            ans.push_back(cur);
            return;
        }
        if (isalpha(s[i])) {
            char c = char(tolower(s[i]));
            dfs(i + 1, s, cur + c);
            c = char(toupper(s[i]));
            dfs(i + 1, s, cur + c);
        } else
            dfs(i + 1, s, cur + s[i]);
  
    }
    vector<string> letterCasePermutation(string s) {
        dfs(0, s, "");
        return ans;
    }
};