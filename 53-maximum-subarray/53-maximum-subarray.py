class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = cur_sum = -math.inf
        
        for n in nums:
            cur_sum = n if cur_sum + n < n else cur_sum + n
            max_sum = max(max_sum, cur_sum)
                
        return max_sum