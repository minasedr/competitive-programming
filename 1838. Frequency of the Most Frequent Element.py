class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        start, end = 0, 0
        maxfreq = 1
        
        while end < len(nums):
            if nums[start] - nums[end] > k:
                maxfreq = max(maxfreq, end - start)
                k += (end - start - 1) * (nums[start] - nums[start + 1])
                start += 1
            else:
                k -= nums[start] - nums[end]
                end += 1
            maxfreq = max(maxfreq, end - start)
        return maxfreq
