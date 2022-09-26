class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>dp(2, vector<int>(n + 1, 1e9));
        
        dp[0][0] = 0;
        dp[1][0] = 1;
        
        for (int i = 1; i < n ; i++) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1] + 1;
            } 
            
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                dp[0][i] = min(dp[0][i], dp[1][i - 1]);
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
            }
        }
        
        return min(dp[0][n - 1], dp[1][n - 1]);
    }
};