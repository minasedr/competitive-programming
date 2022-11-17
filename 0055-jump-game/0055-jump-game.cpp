class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ok = true;
        int cur = 0, max_reached = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            cur = i + nums[i];
            max_reached = max(max_reached, cur);
            if (i < n - 1 && max_reached == i)
                return false;
        }
        return true;
    }
};