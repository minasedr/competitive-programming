class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            auto p = points[i];
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.push({-dist, i});
        }
        
        while (k--) {
            auto p = pq.top();
            ans.push_back(points[p.second]);
            pq.pop();
        }
        return ans;
    }
};