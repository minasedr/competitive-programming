class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        long long n = nums.size();
        
        vector<array<long long, 2>> pos(n + 1, {1, 0}), neg(n + 1, {1, 0});
        if (nums[0] < 0)
            neg[0] = {-1, 1};
        else if (nums[0] > 0)
            pos[0] = {1, 1};
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = {pos[i - 1][0], pos[i - 1][1] + 1};
                if (neg[i - 1][1])
                    neg[i] = {neg[i - 1][0], neg[i - 1][1] + 1};
            } else if (nums[i] < 0) {
                if (neg[i - 1][1])
                    pos[i] = {-neg[i - 1][0], neg[i - 1][1] + 1};
                neg[i] = {-pos[i - 1][0], pos[i - 1][1] + 1};
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            if (pos[i][0] > 0)
                ans = max(ans, pos[i][1]);

        return ans;
    }
};
/*

*/