class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        arr = [0] * (10**5 + 1)
        for num in nums:
            arr[num] += 1
        for a in range(len(arr)):
            if arr[a] > 1:
                return a