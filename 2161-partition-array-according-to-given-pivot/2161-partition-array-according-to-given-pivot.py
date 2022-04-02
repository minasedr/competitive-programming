class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        left = [n for n in nums if n < pivot]
        right = [n for n in nums if n > pivot]
        middle = [n for n in nums if n == pivot]
        
        return left + middle + right