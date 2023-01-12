class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size(), ans = 0;
        vector<bool> vis(n + 1);
        
        for (int i = 2; i < n; i += 2) {
            ans = max(ans, stones[i] - stones[i - 2]);
            vis[i] = vis[i - 2] = true;
        }
        
        int last = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (vis[i]) continue;
            ans = max(ans, stones[last] - stones[i]);
            last = i;
        }
        return ans;
    }
};