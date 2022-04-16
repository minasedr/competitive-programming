class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        beg, N = 0, len(nums)
        total, leng = 0, math.inf
        
        for end in range(N):
            total += nums[end]
            while total >= target:
                leng = min(leng, end-beg+1)
                total -= nums[beg]
                beg += 1
                        
        return leng if leng != math.inf else 0