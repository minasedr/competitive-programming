class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        function<double(vector<int>&)> dist;
        dist = [&](vector<int>&a) {
            return sqrt(pow(a[0],2) + pow(a[1],2));
        };
        function<int(vector<int>&, vector<int>&)> cmp;
        cmp = [&](vector<int>&a, vector<int>&b) {
            return dist(a) < dist(b);
        };
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};