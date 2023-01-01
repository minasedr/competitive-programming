class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> dfs;
        dfs = [&](int i) {
            cur.push_back(i);
            if (i >= n - 1) {
                ans.push_back(cur);
                cur.pop_back();
                return;
            }
            for (auto u: graph[i])
                dfs(u);
            cur.pop_back();
        };
        dfs(0);
        return ans;
    }
};