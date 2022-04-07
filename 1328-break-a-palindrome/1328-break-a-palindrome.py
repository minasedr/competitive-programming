class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        pal, n, ans = palindrome, len(palindrome), ""
        
        if n == 1: return "" 
        for i in range(n//2):
            if pal[i] != 'a':
                return pal[:i] + 'a' + pal[i+1:]
            
        return pal[:-1] + 'b'