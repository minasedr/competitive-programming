class DetectSquares {
public:
    map<int, map<int, int>> points;
    DetectSquares() {}
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int p0 = point[0], p1 = point[1];
        int ans = 0;
        
        for (auto [p, k]: points[p0]) {
            if (p1 == p) continue;
            int d = abs(p - p1);
            ans += k * points[p0 + d][p1] * points[p0 + d][p];
            ans += k * points[p0 - d][p1] * points[p0 - d][p];
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */