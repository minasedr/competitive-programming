class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        x, tot, n, leng = 0, 0, len(nums), math.inf
        
        for i in range(n):
            tot += nums[i]
            while tot >= target:
                leng = min(leng, i-x+1)
                tot, x = tot-nums[x], x+1
                
        leng = min(leng, i-x+1) if tot >= target else leng
        
        return leng if leng != math.inf else 0