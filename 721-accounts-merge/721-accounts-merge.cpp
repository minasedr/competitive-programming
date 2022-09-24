struct DSU {
    vector<int> rep, sz;
    DSU(int n): rep(n), sz(n) {
        for (int i = 0; i < n; i++) {
            rep[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int a) {
        if (rep[a] != a)
            rep[a] = find(rep[a]);
        return rep[a];
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        rep[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> groups;
        DSU dsu(n);
        
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++) {
                string email = accounts[i][j];
                
                if (groups.count(email))
                    dsu.unite(i, groups[email]);
                else
                    groups[email] = i;
            }
        }
        unordered_map<int, vector<string>> comps;
        for (auto [em, gp]: groups) {
            comps[dsu.find(gp)].push_back(em);
        }
        vector<vector<string>> ans;
        for (auto [k, v]: comps) {
            string name = accounts[k][0];
            vector<string> ems = {name};
            ems.insert(ems.end(), v.begin(), v.end());
            sort(ems.begin() + 1, ems.end());
            ans.push_back(ems);
        }
        return ans;
        
    }
};