class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, nxt = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = nxt;
            nxt = prev + nxt;
            prev = tmp;
        }
        return nxt;
    }
};