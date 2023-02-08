class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<pair<int, double>> rep;
        vector<int> sz;
        
        function<pair<int, double>(int)>find;
        find = [&] (int u) {
            auto [p, f] = rep[u];
            if (p != u) {
                auto [n, r] = find(p);
                rep[u] = {n, r * f};
            }
            return rep[u];
        };
        
        function<double(int, int, double)> unite;
        unite = [&] (int u, int v, double ratio) {
            pair<int, double> a = find(u), b = find(v);
            
            if (a.first == b.first)
                return a.second / b.second;
            if (ratio == 0)
                return -1.0;
            
            if (sz[a.first] < sz[b.first]) {
                swap(a, b);
                ratio = 1.0 / ratio;
            }
            rep[a.first] = {b.first, b.second / a.second * ratio};
            return -1.0;
        };
        
        map<string, int> store;
        int n = 0;
        for (auto &eq: equations) {
            if (!store.count(eq[0]))
                store[eq[0]] = n++;
            if (!store.count(eq[1]))
                store[eq[1]] = n++;
        }
        
        for (int i = 0; i < n; i++) {
            rep.push_back({i, 1.0});
            sz.push_back(1);
        }
        
        for (int i = 0; i < equations.size(); i++) {
            string eq0 = equations[i][0], eq1 = equations[i][1];
            unite(store[eq0], store[eq1], values[i]);
        }
        
        vector<double> ans;
        for (auto &q: queries) {
            if (!store.count(q[0]) or !store.count(q[1]))
                ans.push_back(-1.0);
            else
                ans.push_back(unite(store[q[0]], store[q[1]], 0));
        }
        return ans;
    }
};