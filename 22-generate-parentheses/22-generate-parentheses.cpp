class Solution {
public:
    vector<string> res;
    vector<char> cur;
    void dfs(int left, int right, int n) {
        if (left == right && right == n) {
            string s(cur.begin(), cur.end());
            res.push_back(s);
            return;
        }
        if (left < n) {
            cur.push_back('(');
            dfs(left + 1, right, n);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            dfs(left, right + 1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return res;
    }
};