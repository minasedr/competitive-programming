class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maxCount, elem = 0, 0
        
        for n in nums:
            if maxCount == 0: elem = n
            if elem == n: maxCount += 1
            else: maxCount -= 1
                
        return elem