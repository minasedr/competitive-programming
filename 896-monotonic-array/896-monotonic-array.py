class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        inc, dec, n = [], [], len(nums)
        for i in nums:
            if inc and inc[-1] <= i:
                inc.append(i)
            if dec and dec[-1] >= i:
                dec.append(i)
            if not inc: inc.append(i)
            if not dec: dec.append(i)
                
        return True if len(inc) == n or len(dec) == n else False