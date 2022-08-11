class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), cnt = n;
        vector<int>link(n), size(n, 1);
        iota(link.begin(), link.end(), 0);
        
        function<int(int)> find = [&](int x) {
            while (x != link[x])
                x = link[x];
            return x;
        };
        
        function<void(int, int)> unite = [&](int a, int b) {
            int roota = find(a), rootb = find(b);
            if (roota == rootb)
                return;
            if (size[a] < size[b])
                swap(a,b);
            link[rootb] = roota;
            size[roota] += size[rootb];
            cnt--;
        };
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j])
                    unite(i, j);
                
        return cnt;
    }
};