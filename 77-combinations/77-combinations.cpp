class Solution {
public:
    vector<vector<int>> res;
    vector<int>cur;
    set<set<int>> vis;
    void dfs(int idx, int n, int k) {
        if (cur.size() >= k) {
            set<int> x(cur.begin(), cur.end());
            if (cur.size() == k && !vis.count(x))
                res.push_back(cur);
            return;
        }
        for (int j = idx + 1; j <= n; j++) {
            cur.push_back(j);
            dfs(j, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(0, n, k);
        return res;
    }
};