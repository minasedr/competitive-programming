class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x):
            return False
        
        res = 0
        while res < x:
            res = (res * 10) + (x % 10)
            x //= 10
       
        return res == x or res//10 == x