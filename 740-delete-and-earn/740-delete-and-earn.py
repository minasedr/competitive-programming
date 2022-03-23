class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        count = Counter(nums)
        keys = list(count.keys())
        dp = [0] * len(keys)
        
        for i in range(len(keys)):
            if keys[i-1] + 1 == keys[i]:
                dp[i] = max(dp[i-1], (keys[i] * count[keys[i]]) + dp[i-2])
            else:
                dp[i] = max(dp[i-1], (keys[i] * count[keys[i]]) + dp[i-1])
                
        return dp[-1]