class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        counter, unique = 0, []
        
        for num in nums:
            if unique and unique[-1] >= num:
                diff = unique[-1] - num + 1
                unique.append(num + diff)
                counter += diff
            else:
                unique.append(num)
                
        return counter