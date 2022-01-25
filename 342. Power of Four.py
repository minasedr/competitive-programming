class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        while n > 0:
            if n == 1:
                return True
            return self.isPowerOfFour(n/4)
