class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack, stack2 = [], []
        ans = [-1] * len(nums)
        
        for i, num in enumerate(nums):
            while stack and stack[-1][1] < num:
                idx, cur = stack.pop()
                ans[idx] = num
            stack.append((i,num))
        
        while stack and nums:
            idx, cur = stack.pop()
            while nums and cur >= nums[0]:
                nums.pop(0)
            ans[idx] = nums[0] if nums and ans[idx] == -1 else ans[idx]
            
        return ans