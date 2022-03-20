class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp, res = [0] * len(nums), -math.inf
        
        for i in range(len(nums)):
            dp[i] = max(nums[i], dp[i-1] + nums[i])
            res = max(res, dp[i])
        
        return res
        
        max_sum = cur_sum = -math.inf
        
        for n in nums:
            cur_sum = n if cur_sum + n < n else cur_sum + n
            max_sum = max(max_sum, cur_sum)
                
        return max_sum