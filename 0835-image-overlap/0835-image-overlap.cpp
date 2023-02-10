class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        
        vector<pair<int, int>> a, b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j])
                    a.push_back({i, j});
                if (img2[i][j])
                    b.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> cnt;
        for (auto [xa, ya] : a) {
            for (auto [xb, yb]: b) {
                ans = max(ans, ++cnt[{xa - xb, ya - yb}]);
            }
        }
        
        return ans;
    }
};