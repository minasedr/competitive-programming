class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maxCount, elem = 0, 0
        
        for n in nums:
            if maxCount == 0: elem = n
            maxCount += 1 if elem == n else -1
                
        return elem