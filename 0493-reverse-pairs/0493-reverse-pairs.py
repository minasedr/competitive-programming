from sortedcontainers import SortedList

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        ans = 0
        arr = SortedList()
        
        for num in reversed(nums):
            ans += arr.bisect_left(num / 2)
            arr.add(num)
            
        return ans