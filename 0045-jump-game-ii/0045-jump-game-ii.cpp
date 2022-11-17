class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int max_reached = 0, jumps = 0, cur = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = jumps;
            max_reached = max(max_reached, i + nums[i]);
            if (i == cur) {
                cur = max_reached;
                jumps++;
            }
        }
        return ans;
    }
};