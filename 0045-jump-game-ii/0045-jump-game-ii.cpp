class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur = 0, jumps = 0;
        int farthest = 0, ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = jumps;
            farthest = max(farthest, i + nums[i]);
            if (i == cur) {
                cur = farthest;
                jumps++;
            }
        }
        return ans;
    }
};