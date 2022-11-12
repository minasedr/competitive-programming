class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), cur = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            cur += (blocks[i] == 'W');
            if (i <= k - 1)
                ans = cur;
            else if (i >= k) {
                cur -= (blocks[i - k] == 'W');
                ans = min(ans, cur);
            }
        }
        return ans;
    }
};