class Solution:
    def rob(self, nums: List[int]) -> int:
        dp, inc = [0] * len(nums), 0
        
        for i in range(len(nums)):
            inc = max(dp[i-2] if i>1 else 0, dp[i-3] if i>2 else 0)
            dp[i] = nums[i] + inc
            
        return max(dp)