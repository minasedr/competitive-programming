class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        for i in range(n):
            left = dp[i-2] if i -2 >= 0 else 0
            right = dp[i-1] if i -1 >= 0 else 0
            dp[i] = max(left+ nums[i], right)
        return dp[n-1]