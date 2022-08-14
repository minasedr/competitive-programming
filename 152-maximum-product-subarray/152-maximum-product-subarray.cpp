class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp (n);
        dp[0] = {nums[0], nums[0]};
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                dp[i].first = min(dp[i-1].second * nums[i], nums[i]);
                dp[i].second = max(dp[i-1].first * nums[i], nums[i]);
            } else {
                dp[i].first = min(dp[i-1].first * nums[i], nums[i]);
                dp[i].second = max(dp[i-1].second * nums[i], nums[i]);
            }
        }
        int ans = nums[0];
        for (auto x: dp) {
            ans = max({ans, x.first, x.second});
        }
        return ans;
    }
};