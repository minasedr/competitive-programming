class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int n = 1e5 + 1;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        for (auto x: nums) {
            if (vis[x])
                return x;
            vis[x]++;
        }
        return -1;
    }
};