using piv = pair<int, vector<int>>;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int sum = 0;

        priority_queue<piv, vector<piv>, greater<>> pq;
        set<vector<int>> vis;
        vector<int> cur(n);
        
        
        for (int i = 0; i < n; i++)
            sum += mat[i][0];
        pq.push({sum, cur});
        
        k--;
        while (!pq.empty() && k--) {
            auto [sum, now] = pq.top();
            pq.pop();
            for (int i = 0; i < n; i++) {
                if (now[i] < m - 1) {
                    now[i]++;
                    if (!vis.count(now)) {
                        pq.push({sum + mat[i][now[i]] - mat[i][now[i] - 1], now});
                        vis.insert(now);
                    }
                    now[i]--;
                }
            }
        }
        return pq.top().first;
    }
};