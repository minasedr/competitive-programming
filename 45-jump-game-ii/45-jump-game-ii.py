class Solution:
    def jump(self, nums: List[int]) -> int:
        farthest, curr, jumps, n = 0, 0, 0, len(nums)
        
        for i in range(n-1):
            farthest = max(farthest, i + nums[i])
            if curr == i:
                jumps, curr = jumps + 1, farthest
                
        return jumps
        
        
        
        n, dp = len(nums), [0] * len(nums)
        
        for i in range(1, n):
            jump = math.inf
            for j in range(i-1, -1, -1):
                yes = min(jump, dp[j] + 1)
                jump = yes if j + nums[j] >= i else jump
            dp[i] = jump
            
        return dp[-1]