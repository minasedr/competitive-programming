class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product, total, n = 1, 0, str(n)
        
        for i in n:
            product *= int(i)
            total += int(i)
            
        return product - total