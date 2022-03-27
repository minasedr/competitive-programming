class Solution:
    def arraySign(self, nums: List[int]) -> int:
        if 0 in nums: return 0
        else:
            x = len(list(filter(lambda x: x<0, nums)))
            if not x % 2: return 1
            else: return -1

        def signFunc(x):
            if x < 0: return -1
            elif x > 0: return 1
            return 0
       
        return signFunc(prod(nums))