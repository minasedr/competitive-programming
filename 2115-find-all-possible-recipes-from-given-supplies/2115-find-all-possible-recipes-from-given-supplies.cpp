class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> mp;
        vector<int>deg(n);
        for (int i = 0; i < n; i++) {
            mp[recipes[i]] = i;
            for (auto gd: ingredients[i]) {
                adj[gd].push_back(recipes[i]);
                deg[i]++;
            }
        }
        queue<string> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
                q.push(recipes[i]);
        for (auto x: supplies)
            q.push(x);
        set<string> ans;
        while (!q.empty()) {
            string node = q.front();
            ans.insert(node);
            q.pop();
            for (auto u: adj[node]) {
                if (--deg[mp[u]] == 0)
                    q.push(u);
            }
        }
        vector<string> res;
        for (auto x: recipes)
            if (ans.count(x))
                res.push_back(x);
        return res;
    }
};