class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [&](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int cur = -2e3, ans = 0;
        for (auto pair: pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }
        return ans;
    }
};