class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        pal, n, ans = palindrome, len(palindrome), ""
        if n == 1: return ""
        
        for i in range(n):
            if pal[i] != 'a':
                ans = pal[:i] + 'a' + pal[i+1:]
                break
        isPal = lambda x: x == x[::-1]
        
        return pal[:-1] + 'b' if (not ans or isPal(ans)) else ans