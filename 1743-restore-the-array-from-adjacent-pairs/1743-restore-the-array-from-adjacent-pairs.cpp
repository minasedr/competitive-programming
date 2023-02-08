class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        map<int, vector<int>> store;
        vector<int> ans;
        
        for (auto pair: adjacentPairs) {
            store[pair[0]].push_back(pair[1]);
            store[pair[1]].push_back(pair[0]);
        }
        
        for (auto &[pt, pts]: store) {
            if (pts.size() == 1) {
                ans.push_back(pt);
                ans.push_back(pts[0]);
                break;
            }
        }
        
        for (int i = 0; i <= n - 2; i++) {
            auto last = ans.back(), prev = ans[ans.size() - 2];
            auto next = store[last];
            ans.push_back((next[0] != prev) ? next[0] : next[1]);
        }
        
        return ans;
    }
};