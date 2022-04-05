class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right, ans = 0, len(nums) - 1, 0
        if target < nums[0]: return 0
        if target > nums[-1]: return right + 1
      
        while left <= right:
            mid = (left + right)// 2
            if nums[mid] < target: left = mid + 1
            else: ans, right = mid, mid - 1
        return ans