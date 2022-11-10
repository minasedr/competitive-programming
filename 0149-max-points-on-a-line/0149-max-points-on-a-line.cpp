class Solution {
public:
    double slope(vector<int>& p1, vector<int>& p2) {
        if (p1[0] == p2[0]) return INT_MAX;
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        return double(dy) / dx;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<vector<double>, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double sp = slope(points[i], points[j]);
                cnt[{(double)points[i][0],(double)points[i][1], sp}]++;
            }
        }
        int ans = 0;
        for (auto [k, v]: cnt)
            ans = max(ans, v);
        return ans + 1;
    }
};