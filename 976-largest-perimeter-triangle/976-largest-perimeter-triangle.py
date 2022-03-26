class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        per, nums = 0, sorted(nums, reverse=True)
        
        def perimeter(n,x,y,z):
            if n[x]+n[y]>n[z] and n[x]+n[z]>n[y] and n[y]+n[z]>n[x]:
                return n[x]+n[y]+n[z]
            return 0
        
        for i in range(len(nums)-2):
            per = max(per, perimeter(nums,i,i+1,i+2))
                    
        return per