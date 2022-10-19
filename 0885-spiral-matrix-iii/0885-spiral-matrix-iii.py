class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        unordered_map<char, array<int, 4>> dir {
            {'R', {1, 0, 0, 1}},
            {'D', {0, -1, 1, 0}},
            {'L', {-1, 0, 0, -1}},
            {'U', {0, 1, -1, 0}},
        };
        
        function<pair<int,int>(int, int, char)> move;
        function<bool(int, int)> inbound = [&](int r, int c) {
            return (r >= 0 and r < rows and c >= 0 and c < cols);
        };
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        set<pair<int,int>> vis;
        vis.insert({rStart, cStart});
        cStart++;
        
        move = [&](int row, int col, char direc) {
            auto [r, c, dr, dc] = dir[direc];
            while (vis.count({row + r, col + c})) {
                if (inbound(row, col))
                    ans.push_back({row, col});
                vis.insert({row, col});
                row += dr;
                col += dc;
            }
            if (vis.count({row + r, col + c}))
                if (inbound(row, col))
                    ans.push_back({row, col});
            vis.insert({row, col});
            pair<int,int> cur = {row, col};
            return cur;
        };
        int r = rStart, c = cStart;
        while (ans.size() < rows * cols) {
            tie(r, c) = move(r, c, 'R');
            tie(r, c) = move(r, c, 'D');
            tie(r, c) = move(r, c, 'L');
            tie(r, c) = move(r, c, 'U');
        }
        return ans;
    }
};