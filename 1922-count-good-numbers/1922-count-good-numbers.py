class Solution:
    def countGoodNumbers(self, n: int) -> int:
        counter = 1
        denom = 10 ** 9 + 7
        if n % 2 == 0:
            counter *= pow(5, n//2,denom) * pow(4,n//2, denom)
        else:
            counter *= pow(4,n//2,denom) * pow(5, (n//2) + 1, denom)
        
        return counter % denom