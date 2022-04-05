class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans, cur = [], []
        
        def backtrack(i):
            if i < len(nums):
                cur.append(nums[i])
                backtrack(i+1); cur.pop(); backtrack(i+1)
            else:
                ans.append(cur[:])
            return ans
        
        return backtrack(0)