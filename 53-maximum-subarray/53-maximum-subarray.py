class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * len(nums) 
        
        for i in range(len(nums)):
            dp[i] = max(nums[i], dp[i-1] + nums[i])
        
        return max(dp)
        
        max_sum = cur_sum = -math.inf
        
        for n in nums:
            cur_sum = n if cur_sum + n < n else cur_sum + n
            max_sum = max(max_sum, cur_sum)
                
        return max_sum