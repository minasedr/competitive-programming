class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            if nums[left] < nums[mid]:
                if not (nums[left] <= target < nums[mid]):
                    left = mid + 1
                else:
                    right = mid - 1
            elif nums[left] == nums[mid]  and nums[mid] > target:
                left = mid + 1
                    
            else:
                if not (nums[mid] < target <= nums[right]):
                    right = mid - 1
                else:
                    left = mid + 1
        return -1