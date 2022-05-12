class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack, stack2, j, N = [], [], 0, len(nums)
        ans = [-1] * len(nums)
        
        for i, num in enumerate(nums):
            while stack and stack[-1][1] < num:
                idx, cur = stack.pop()
                ans[idx] = num
            stack.append((i,num))
            
        while stack and nums:
            idx, cur = stack.pop()
            while j < N and cur >= nums[j]:
                j += 1
            ans[idx] = nums[j] if j < N and ans[idx] == -1 else ans[idx]
            
        return ans