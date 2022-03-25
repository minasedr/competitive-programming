class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product, total = 1, 0
        
        while n:
            x, n = n % 10, n//10
            product *= x
            total += x
            
        return product - total