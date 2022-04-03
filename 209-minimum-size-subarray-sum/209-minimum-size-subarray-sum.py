class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, tot, n, leng = 0, 0, len(nums), math.inf
        
        for r in range(n):
            tot += nums[r]
            while tot >= target:
                leng = min(leng, r-l+1)
                tot, l = tot-nums[l], l+1
                        
        return leng if leng != math.inf else 0