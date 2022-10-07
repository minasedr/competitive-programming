class Solution {
public:
    vector<vector<int>> res;
    void f(int i, int k, int n, vector<int> cur) {
        if (i > n) return;
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int j = i + 1; j <= n; j++) {
            cur.push_back(j);
            f(j, k, n, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        f(0, k, n, cur);
        return res;
    }
};