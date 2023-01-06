class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int cur = points[0][1], arrows = 1;
        for (int i = 0; i < n; i++) {
            if (cur < points[i][0]) {
                cur = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};