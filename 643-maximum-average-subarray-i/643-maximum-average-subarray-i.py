class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        total = sum(nums[:k])
        avg = total/k

        for i in range(k, len(nums)):
            avg = max(avg, total/k)
            total += nums[i]
            total -= nums[i-k]
            
        return max(avg, total/k)