class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums.insert(0, 1)
        nums.append(1)
        
        memo = {}
        def dfs(left, right):
            if left > right:
                return 0
            
            if (left, right) in memo:
                return memo[(left, right)]
            ans = 0
            for k in range(left, right + 1):
                ans = max(ans, dfs(left, k - 1) + (nums[left - 1] * nums[k] * nums[right + 1]) + dfs(k + 1, right))
            
            memo[(left, right)] = ans
            return ans
        
        return dfs(1, len(nums) - 2)