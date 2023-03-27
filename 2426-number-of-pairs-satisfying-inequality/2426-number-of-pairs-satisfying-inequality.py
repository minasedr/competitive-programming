from sortedcontainers import SortedList

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        ans = 0
        dif = SortedList()
        
        for a, b in zip(nums1, nums2):
            ans += dif.bisect_right(a - b + diff)
            dif.add(a - b)
            
        return ans