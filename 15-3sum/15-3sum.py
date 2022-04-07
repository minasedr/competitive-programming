class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums, ans, n = sorted(nums), set(), len(nums)
        
        for i in range(n):
            fir, l, r = nums[i], i+1, n-1
            while l < r:
                if nums[l]+nums[r] < -fir: l += 1
                elif nums[l]+nums[r] > -fir: r -= 1
                else: 
                    ans.add((fir,nums[l], nums[r]))
                    l, r = l+1, r-1
                    
        return ans