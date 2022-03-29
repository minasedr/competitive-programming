class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        def arithmetic(x,y,z):
            dx = nums[y] - nums[x]
            dy = nums[z] - nums[y]
            if dx == dy: return True
            return False
        
        arith = 0
        for i in range(1, len(nums)-1):
            x, y, z = i-1,i,i+1
            while x > -1 and arithmetic(x,y,z):
                arith += 1
                x,y,z = x-1,y-1,z-1
                
        return arith