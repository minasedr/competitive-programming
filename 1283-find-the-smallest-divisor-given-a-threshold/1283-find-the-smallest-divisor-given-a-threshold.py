class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums.sort()
        left, right, ans = 1, nums[len(nums) - 1], 0
        
        while left <= right:
            mid = (left + right) // 2
            total = 0
            for num in nums:
                total += math.ceil(num/mid)
            if total <= threshold:
                ans, right = mid, mid - 1
            else:
                left = mid + 1
        return ans