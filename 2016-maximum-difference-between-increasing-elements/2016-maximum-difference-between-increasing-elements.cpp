class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = 0, mn = nums[0];
        
        for (int i = 1; i < n; i++) {
            ans = max(ans, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return (ans ? ans: -1);
    }
};