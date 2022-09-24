struct DSU {
    vector<int> rep, sz;
    DSU(int n): rep(n + 1), sz(n + 1) {
       for (int i = 1; i <= n; i++) {
           rep[i] = i;
           sz[i] = 1;
       }
    }
    
    int find(int a) {
        if (rep[a] != a)
            rep[a] = find(rep[a]);
        return rep[a];
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];
        rep[b] = a;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        
        for (auto e: edges) {
            if (!dsu.unite(e[0], e[1]))
                return {e[0], e[1]};
        }
        return {0, 0};
    }
};