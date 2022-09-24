struct edge {
    int p1, p2, wt;
    int operator <(const edge& e) {
        return wt < e.wt;
    }
};

struct DSU {
    vector<int>rep, sz;
    
    DSU(int n): rep(n + 1), sz(n + 1) {
        iota(rep.begin(), rep.end(), 0);
        fill(sz.begin(), sz.end(), 1);
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
    int dist(vector<int>a, vector<int> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ds = dist(points[i], points[j]);
                edges.push_back({i, j, ds});
            }
        }
        sort(edges.begin(), edges.end());
        int cost = 0;
        DSU dsu(n);
        for (auto e: edges) {
            int ds = e.wt;
            if (dsu.unite(e.p1, e.p2))
                cost += ds;
        }
        return cost;
    }
};