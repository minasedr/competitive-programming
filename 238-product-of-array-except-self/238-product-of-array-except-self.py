class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        rev, res, suff, pref = [None] * n, [], 1, 1
        
        for idx in range(n-1,-1,-1):
            rev[idx] =  suff
            suff *= nums[idx]
            
        for i in range(n):
            res.append(rev[i] * pref)
            pref *= nums[i]
            
        return res
            