class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        result, N = nums[-1] - nums[0], len(nums)
        M, m = nums[-1] - k, nums[0] + k

        for i in range(N-1):
            left = min(m, nums[i+1]-k)
            right = max(M, nums[i]+k)

            result = min(result, right-left)

        return result