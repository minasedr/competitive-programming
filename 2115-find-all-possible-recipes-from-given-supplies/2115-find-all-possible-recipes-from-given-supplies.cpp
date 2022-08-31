class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = ingredients.size();
        map<string, set<int>> adj;
        vector<int> indeg(n);
        set<string> cur;
        vector<string> res;
        
        for (int i = 0; i < n; i++) {
            for (auto u: ingredients[i]) {
                adj[u].insert(i);
                indeg[i]++;
            }
        }
        
        queue<string> q;
        
        for (auto x: supplies)
            q.push(x);
        
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            cur.insert(u);
            for (auto v: adj[u]) {
                if (--indeg[v] == 0)
                    q.push(recipes[v]);
            }
        }
        
        for (auto x: recipes) {
            if (cur.count(x))
                res.push_back(x);
        }
        return res;
    }
};