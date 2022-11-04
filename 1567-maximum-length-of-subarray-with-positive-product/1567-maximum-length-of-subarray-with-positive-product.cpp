class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pos(n + 1), neg(n + 1);
        neg[0] = (nums[0] < 0 ? 1 : 0);
        pos[0] = (nums[0] > 0 ? 1 : 0);
        int ans = pos[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = pos[i - 1] + 1;
                neg[i] = (neg[i - 1] ? neg[i - 1] + 1 : 0);
            } else if (nums[i] < 0) {
                neg[i] = pos[i - 1] + 1;
                pos[i] = (neg[i - 1] ? neg[i - 1] + 1 : 0);
            }
            ans = max(ans, pos[i]);
        }
        return ans;
    }
};