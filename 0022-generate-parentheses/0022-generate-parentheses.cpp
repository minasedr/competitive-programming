class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        function<void(int, int, string)> dfs;
        dfs = [&](int i, int j, string cur) {
            if (i == j && j == n)
                ans.push_back(cur);
            if (i < n)
                dfs(i + 1, j, cur + '(');
            if (j < i)
                dfs(i, j + 1, cur + ')');
        };
        dfs(0, 0, "");
        return ans;
    }
};