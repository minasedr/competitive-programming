class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> cnt;
        for (auto m: matches) {
            if (!cnt.count(m[0]))
                cnt[m[0]] = 0;
            cnt[m[1]]--;
        }
        for (auto [k, v]: cnt) {
            if (v == 0)
                ans[0].push_back(k);
            else if (v == -1)
                ans[1].push_back(k);
        }
        return ans;
    }
};