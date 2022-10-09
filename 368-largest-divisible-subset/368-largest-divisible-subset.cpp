class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), par(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
        }
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        
        vector<int> ans;
        while (idx != -1) {
            ans.push_back(nums[idx]);
            idx = par[idx];
        }
        return ans;
        
    }
};