class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int mx = 0, year = 0;
        
        for (int i = 1950; i <= 2050; i++) {
            int alive = 0;
            for (auto x: logs)
                alive += (x[0] <= i and i < x[1]);
            if (mx < alive) {
                mx = alive;
                year = i;
            }
        }
        
        return year;
    }
};