class Solution:
    def rob(self, nums: List[int]) -> int:
        dp, n = [0] * len(nums), len(nums)
        
        for i in range(n):
            dp[i] = nums[i] + max(dp[i-2] if i-2 >= 0 else 0, dp[i-3] if i-3 >= 0 else 0)
            
        return max(dp)