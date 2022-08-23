class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxIdx = 0;
        vector<int> dp(n), par(n, -1), res;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i ; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
            maxIdx = (dp[i] > dp[maxIdx] ? i : maxIdx);
        }
        while (maxIdx >= 0) {
            res.push_back(nums[maxIdx]);
            maxIdx = par[maxIdx];
        }
        return res;
    }
};